#include <iostream>
#include <queue>
using namespace std;
const int N = 350;

struct Node
{
    int x;
    int y;
    int t;
};

char a[309][309];
bool vis[309][309];
int n, m, sx, sy;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void portal(int &nx, int &ny, int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == a[nx][ny] && (i != nx || j != ny))
            {
                nx = i, ny = j;
                return;
            }
        }
    }
}

queue<Node> q;

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '@')
                sx = i, sy = j;
        }
    }

    q.push((Node){sx, sy, 0});
    while (!q.empty())
    {
        Node f = q.front();
        q.pop();
        // cout << f.x << "," << f.y << "," << f.t << endl;
        // cout<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         cout<<vis[i][j];
        //     }
        //     cout<<endl;
        // }
        if (a[f.x][f.y] == '=')
        {
            cout << f.t;
            return 0;
        }
        if (a[f.x][f.y] >= 'A' && a[f.x][f.y] <= 'Z')
        {
            portal(f.x, f.y, f.t);
        }
        for (int i = 0; i <= 3; i++)
        {
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                q.push((Node){nx, ny, f.t + 1});
            }
        }
    }
    return 0;
}