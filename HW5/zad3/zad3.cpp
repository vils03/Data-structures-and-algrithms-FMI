#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void func(stack<int>& positive, int& lastIndex, vector<int>& all, int& i) {
    if (positive.empty()) {
        cout << all[i] << ' ';
        lastIndex = i;
    }
    else if (abs(all[i]) < positive.top()) {
        return;
    }
    else if (abs(all[i]) == positive.top()) {
        positive.pop();
    }
    else {
        positive.pop();
        if (positive.empty()) {
            cout << all[i] << " ";
        }
        else
            func(positive, lastIndex, all, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int people;
    cin >> people;
    vector<int> all;
    stack<int> positive;
    for (int i = 0; i < people; ++i) {
        int el;
        cin >> el;
        all.push_back(el);
    }
    int lastIndex = -1;
    for (int i = 0; i < people; ++i) {
        if (all[i] < 0) {
            func(positive, lastIndex, all, i);
        }
        else {
            positive.push(all[i]);
        }
    }
    if (lastIndex != people - 1) {
        vector<int> toPrint;
        while (!positive.empty()) {
            toPrint.push_back(positive.top());
            positive.pop();
        }
        for (int i = toPrint.size() - 1; i >= 0; --i) {
            cout << toPrint[i] << " ";
        }
    }   
}

