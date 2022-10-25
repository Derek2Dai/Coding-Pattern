using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct endCompare {
    bool operator()(const Meeting &x, const Meeting &y) { return x.end > y.end; }
  };
  
  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {

    if(meetings.size() <= 1) return (int)meetings.size();

    sort(meetings.begin(),meetings.end(),[](const Meeting& m1, const Meeting& m2 ){ return m1.start < m2.start; });
    
    int meetingRoom = 0;
// minheap的top元素给出的一直是 最早结束的meeting的时间，smallest end time
    priority_queue<Meeting,vector<Meeting>,endCompare> minHeap;

    for(auto meeting:meetings){
// 当发现下个meeting的开始时间 晚于 minheap种最早结束的一个 => 不用安排新的meeting room
        while (!minHeap.empty() && meeting.start >= minHeap.top().end)
        {
            minHeap.pop();
        }
        minHeap.push(meeting);
        meetingRoom = max(meetingRoom,(int)minHeap.size());
    }



    return meetingRoom;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5},{1,2}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}