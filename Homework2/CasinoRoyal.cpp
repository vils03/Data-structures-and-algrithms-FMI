#include <iostream>
#include <vector>
using namespace std;

bool isEven(int number) {
    return number % 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t betsCount;
    cin >> betsCount;
    vector<int> bets;

    vector<int> even;
    vector<int> odd;
    for (size_t i = 0; i < betsCount; ++i) {
        int bet;
        cin >> bet;
        bets.push_back(bet);
    }
    for (size_t i = 0; i < bets.size(); ++i) {
        if (isEven(bets[i]))
            even.push_back(bets[i]);
        else
            odd.push_back(bets[i]);
    }
    bets.clear();
    bets.insert(bets.end(), even.begin(), even.end());
    bets.insert(bets.begin(), odd.begin(), odd.end());
    for (size_t i = 0; i < bets.size(); ++i) {
        cout << bets[i] << '\n';
    }
}
