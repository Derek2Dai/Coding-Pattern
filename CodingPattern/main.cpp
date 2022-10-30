#include <iostream>
#include <vector>
#include "MergeIntervals/MeetingRoomConflict.cpp"
#include "MergeIntervals/MinimumMeetingRooms.cpp"
#include "MergeIntervals/Helper.cpp"
#include "MergeIntervals/EmployeeFreeTime.cpp"

int main(int argc, char *argv[]) {
// Given a list of intervals representing the start and end time of ‘N’ meetings, 
// find the minimum number of rooms required to hold all the meetings.
// https://www.educative.io/courses/grokking-the-coding-interview/JQMAmrVPL7l
// similar problems :
// Given a list of intervals, find the point where the maximum number of intervals overlap.
// Given a list of intervals representing the arrival and departure times of trains to a train station, 
// our goal is to find the minimum number of platforms required for the train station so that no train 
// has to wait.
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



// Given a list of intervals calendar and a number of available conference rooms. 
//For each query, return true if the meeting can be added to the calendar successfully 
// without causing a conflict,  otherwise false. 
//A conference room can only hold one meeting at a time.

   input = {{1, 2}, {4, 5}, {8, 10}};
   int rooms = 1;
   vector<Meeting> queries = {{2,3},{3,4}};
   vector<bool> answer = MeetingRoomConflict::getRoomConflict(input,rooms,queries);
   Helper::prettyBooleanPrint(answer);


   input = {{1, 3}, {4, 6}, {6, 8}, {9, 11}, {6, 9}, {1, 3}, {4, 10}};
   rooms = 3;
   queries = {{1, 9}, {2, 6}, {7, 9}, {3, 5}, {3, 9}, {2, 4}, {7, 10}, {5, 9}, {3, 10}, {9, 10}};
   Helper::prettyBooleanPrint(MeetingRoomConflict::getRoomConflict(input,rooms,queries));


  vector<vector<Interval>> input_1 = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result_1 = EmployeeFreeTime::findEmployeeFreeTime(input_1);
  cout << "Free intervals: ";
  for (auto interval : result_1) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input_1 = {{{1, 3}, {9, 12}}, {{2, 4},{5,7}}, {{6, 8}}};
  result_1 = EmployeeFreeTime::findEmployeeFreeTime(input_1);
  cout << "Free intervals: ";
  for (auto interval : result_1) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input_1 = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result_1 = EmployeeFreeTime::findEmployeeFreeTime(input_1);
  cout << "Free intervals: ";
  for (auto interval : result_1) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }

}