#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "Meeting.h"

using namespace std;

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
// 把meeting加到minheap里。
        minHeap.push(meeting);
// The heap will always have all the overlapping meetings, 
// so we will need rooms for all of them. Keep a 
// counter to remember the maximum size of the heap at any
// time which will be the minimum number of rooms needed.
        meetingRoom = max(meetingRoom,(int)minHeap.size());
    }
    return meetingRoom;
  }
};
