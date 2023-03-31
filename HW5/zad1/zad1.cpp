//for(dni)
//      while(size na opashkata)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool check(int x, int y, int n, int m, vector<vector<bool>> visited) {
    return (x >= 0 && y >= 0 && x < m && y < n && !visited[y][x]);
}

void visit(queue<pair<int, int>>& rotten, int row, int col, vector<vector<bool>>& visited) {

    int curY = rotten.front().first;
    int curX = rotten.front().second;
    if (check(curX, curY + 1, row, col, visited)) {
        visited[curY + 1][curX] = true;
        rotten.push({ curY + 1, curX });
    }
    if (check(curX, curY - 1, row, col, visited)) {
        visited[curY - 1][curX] = true;
        rotten.push({ curY - 1, curX });
    }
    if (check(curX + 1, curY, row, col, visited)) {
        visited[curY][curX + 1] = true;
        rotten.push({ curY, curX + 1});
    }
    if (check(curX - 1, curY, row, col, visited)) {
        visited[curY][curX - 1] = true;
        rotten.push({ curY, curX - 1 });
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;
    int days;
    cin >> days;
    int x, y;
    vector<pair<int, int>> startApples;
    vector<vector<bool>> visited(row, vector<bool>(col));
    while (cin >> y >> x) {
        startApples.push_back({ y - 1, x - 1 });
    }
    queue<pair<int, int>> rotten;
    //day 1
    if (startApples.size() == 1)
    {
        rotten.push({ startApples[0].first, startApples[0].second });
        visited[startApples[0].first][startApples[0].second] = true;
        visit(rotten, row, col, visited);
        rotten.pop();
    }
    else if (startApples.size() == 2) {
        rotten.push({ startApples[0].first, startApples[0].second });
        visited[startApples[0].first][startApples[0].second] = true;

        rotten.push({ startApples[1].first, startApples[1].second });
        visited[startApples[1].first][startApples[1].second] = true;

        visit(rotten, row, col, visited);
        rotten.pop();
        visit(rotten, row, col, visited);
        rotten.pop();
    }
    //other days
    for (int i = 1; i < days; ++i) {
        int rottenSize = rotten.size();
        for(int i = rottenSize;i > 0;--i) {
            visit(rotten, row, col, visited);
            rotten.pop();
        }
    }
    int countGood = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; ++j) {
            if (visited[i][j] == false)
                countGood++;
        }
    }
    cout << countGood;
}