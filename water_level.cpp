#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;

int GetWaterLevel(int input1,int input2,int input3_size, int* input3)
{



    vector<vector<int> > heightMap(input1,vector<int>(input2, 0));
    int /*m = heightMap.size(), input2 = heightMap[0].size(),*/ res = 0, mx = INT_MIN;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<vector<bool> > visited(input1, vector<bool>(input2, false));
    int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    for (int i = 0; i < input1; ++i) {
        for (int j = 0; j < input2; ++j) {
            heightMap[i][j] = input3[i*input2+j];
            if (i == 0 || i == input1 - 1 || j == 0 || j == input2 - 1) {
                q.push(make_pair(heightMap[i][j], i * input2 + j));
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();
        int h = t.first, r = t.second / input2, c = t.second % input2;
        mx = max(mx, h);
        for (int i = 0; i < 4; ++i) {
            int x = r + dir[i][0], y = c + dir[i][1];
            if (x < 0 || x >= input1 || y < 0 || y >= input2 || visited[x][y]) continue;
            visited[x][y] = true;
            if (heightMap[x][y] < mx) res += mx - heightMap[x][y];
            q.push(make_pair(heightMap[x][y], x * input2 + y));
        }
    }
    return res;

}