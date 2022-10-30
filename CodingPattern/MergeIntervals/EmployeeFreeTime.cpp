#include <iostream>
#include <queue>
#include <vector>
#include "Interval.h"

using namespace std;

class EmployeeFreeTime{
    public:
      struct startComapre{
        bool operator()(const pair<Interval,pair<int,int>>&x,
                        const pair<Interval,pair<int,int>>&y){
                            return x.first.start > y.first.start;
                        }
      };

       static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule){
        vector<Interval> result;
        if(schedule.empty()) return result;
        
  // PriorityQueue to store one interval from each employe
        priority_queue<pair<Interval,pair<int,int>>,vector<pair<Interval,pair<int,int>>>,startComapre>

                minHeap;
        
    // insert the first interval of each employee to the queue
    // 每个员工的第一个interval 工作时间，
    for(int i= 0;i<(int)schedule.size();i++){
        minHeap.push(make_pair(schedule[i][0],make_pair(i,0)));
    }

    // minHeap 的top元素给出的是 最早开始的 working hour
    Interval previousInterval = minHeap.top().first; 

    while(!minHeap.empty()){
        // 在第一循环 queueTop.first 和 previousInterval 是相等的，目的是为了把第一个 员工的下一个interval加到heap里。
        auto queueTop = minHeap.top();
        minHeap.pop();
        // 因为每次从minheap取出的都是那个时间第二早开始的员工的interval，（代表着其他员工都是晚于这个员工开始的，他们在这个start time点上是有freetime的）
        // previousInterval 有着第一早的开始的interval，要看第一早结束的时间是否 早于第二早 开始的时间
        // previousInterval 是在检查当前员工working hour 有着最晚 end的时间，如果start 时间晚于 previousInterval.end
        if(previousInterval.end < queueTop.first.start){
            result.push_back({previousInterval.end,queueTop.first.start});
            previousInterval = queueTop.first;
        }else{  // overlapping intervals, update the previousInterval if needed
                //谁更晚结束working 以他为基准。
             if(previousInterval.end <  queueTop.first.end){
                previousInterval = queueTop.first;
             }
        }
        //  second是pair<int,int> 
        //  second.first 代表 员工时间 在 schedule里的index
        vector<Interval> employeeSchedule = schedule[queueTop.second.first];
        // second.second 代表 每个员工 working hour 里 interval的idnex
        if(queueTop.second.second+1 < (int)employeeSchedule.size()) // 当该员工上一个interval被pop out掉后， 看一下还有没有下一个interval
        {
            minHeap.push(make_pair(employeeSchedule[queueTop.second.second+1],make_pair(
                    queueTop.second.first,queueTop.second.second+1
            )));
        }

    }
    return result;

   };

};