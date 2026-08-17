#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool customCompare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}
void bfs(int r, int c, int H, int W, vector<string> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    char target = grid[r][c];

    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc] && grid[nr][nc] == target)
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int world = 1; world <= n; world++)
    {
        int H, W;
        cin >> H >> W;

        vector<string> grid(H);
        for (int i = 0; i < H; i++)
            cin >> grid[i];

        vector<vector<bool>> visited(H, vector<bool>(W, false));
        vector<int> counts(26, 0);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!visited[i][j])
                {
                    counts[grid[i][j] - 'a']++;
                    bfs(i, j, H, W, grid, visited);
                }
            }
        }

        vector<pair<int, char>> results;
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] > 0)
            {
                results.push_back({counts[i], (char)i + 'a'});
            }
        }

        sort(results.begin(), results.end(), customCompare);

        cout << "World #" << world << endl;
        for (auto &p : results)
        {
            cout << p.second << ": " << p.first << endl;
        }
    }
    return 0;
}