#include <iostream>
using namespace std;

int Chechevcoin(int N, int* array) {
    int toReturn = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (array[i] > array[i + 1]) {
            continue;
        }
        else {
            toReturn += (-array[i] + array[i+1]);
        } 
    }
    return toReturn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << Chechevcoin(n, array);
}

