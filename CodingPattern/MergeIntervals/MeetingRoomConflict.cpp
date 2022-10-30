#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "Meeting.h"
#include "Helper.cpp"

using namespace std;

class MeetingRoomConflict {
 public:
// Google | Onsite | Meeting Rooms 3
  static vector<bool> getRoomConflict(vector<Meeting> &meetings,
                                      const int& k,
                                      vector<Meeting>& meetingqueries) {
        int maxHour = INT_MIN;
        // 找出所有meeting里结束最晚的时间。
        for(int i=0;i < (int)meetings.size(); i++) maxHour = max(maxHour,meetings[i].end);
        //  初始化 maxHour+1 个时间节点，每个时间节点初始化为 0 -> 代表每个时间节点上room的变化多少
        vector<int> rooms(maxHour+1,0);
        for(int i= 0; i < (int)meetings.size();i++){
            rooms[meetings[i].start]++;
            rooms[meetings[i].end]--;
        }

        vector<int> maxRoomOccupTimes;
        if(rooms[0] == k ) maxRoomOccupTimes.push_back(0);
        for(int i = 1;i <= maxHour;i++ ){
            rooms[i] += rooms[i-1];
            if(rooms[i] == k ) maxRoomOccupTimes.push_back(i);
        }
        Helper::prettyIntVecPrint(maxRoomOccupTimes);

        vector<bool> ans(meetingqueries.size(),true);  
        int start, end;
        for(int i=0;i<(int)meetingqueries.size();i++){
           start = meetingqueries[i].start;
           end = meetingqueries[i].end;
           auto itr = lower_bound(maxRoomOccupTimes.begin(),maxRoomOccupTimes.end(),start);
           if(itr != maxRoomOccupTimes.end() && *(itr) < end ) ans[i] = false;     
        }

        return ans;

  }
};
