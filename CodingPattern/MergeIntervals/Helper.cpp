#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

class Helper{
 public:
// Google | Onsite | Meeting Rooms 3
  static void prettyBooleanPrint(const vector<bool> v){
    cout << endl;
    for(auto ele:v)
      cout << (ele? "true":"false") << ", ";
    cout << endl;
  }

  static void prettyIntVecPrint(const vector<int> v){
     cout << endl;
    for(auto ele:v)
      cout << ele << ", ";
    cout << endl;
  }
};
