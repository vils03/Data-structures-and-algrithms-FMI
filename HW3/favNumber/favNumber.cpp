#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long candy(long long index,long long start,long long end, long long counter) {

    long long middle1 = (2 * start + end) / 3;
    long long middle2 = (start + 2 * end) / 3;

    if (middle1 < index && index <= middle2) {
        return 1;
    }
   
    else {
        if (index < middle1) {
            return candy(index, start, middle1, counter);
        }
        else {
            return candy(index, middle2, end, counter);
        }
    }
   
}


int main()
{
    long long pow3, numInvited;
    cin >> pow3 >> numInvited;
    vector<long long> invited;
    for (int i = 0; i < numInvited; ++i) {
        long long el;
        cin >> el;
        invited.push_back(el);
    }
    long long allFriends = pow(3, pow3);
    for (int i = 0; i < invited.size(); ++i) {
       cout << candy(invited[i], 0, allFriends - 1, 1);
    }

    
    
}

