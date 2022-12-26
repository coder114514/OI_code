#include <bits/stdc++.h>
using namespace std;

int m, mp[309][309], ans[309][309];

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};

int neg_to_inf(int x)
{
    return (x < 0 ? (1 << 30) : x);
}

void bfs()
{
    queue<pair<int, int> > q;
    ans[0][0] = 0;
    q.push(make_pair(0, 0));
    int x, y, t;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        t = ans[x][y];
        q.pop();
        // cout << x << ',' << y << ',' << t << "," << mp[x][y] << endl;
        if (mp[x][y] == -1) break;
        for (int d = 1; d <= 4; d++)
            if (x + dx[d] >= 0 && y + dy[d] >= 0 && t + 1 < neg_to_inf(mp[x + dx[d]][y + dy[d]]) && ans[x + dx[d]][y + dy[d]] == -1)
            {
                ans[x + dx[d]][y + dy[d]] = ans[x][y] + 1;
                q.push(make_pair(x + dx[d], y + dy[d]));
            }
    }
    cout << (mp[x][y] == -1 ? ans[x][y] : -1) << endl;
}

int main()
{
    cin >> m;
    for (int i = 0; i < 309; i++)
        for (int j = 0; j < 309; j++)
            mp[i][j] = -1;
    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        for (int d = 0; d <= 4; d++)
            if (x + dx[d] >= 0 && y + dy[d] >= 0 && t < neg_to_inf(mp[x + dx[d]][y + dy[d]]))
                mp[x + dx[d]][y + dy[d]] = t;
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << setw(5) << mp[j][5 - i - 1] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 309; i++)
        for (int j = 0; j < 309; j++)
            ans[i][j] = -1;
    bfs();
    return 0;
}