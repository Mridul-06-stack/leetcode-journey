class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
     void fill(
        vector<vector<int>> & visited, int sr, int sc, int color,
        vector<vector<int>>& image) {
        int newrow;
        int newcol;
        int original = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        int row = sr;
        int col = sc;
        queue<pair<int, int>> q1;
        q1.push({row, col});
        visited[sr][sc] = 1;

        while (!q1.empty()) {
            row = q1.front().first;
            col = q1.front().second;
            q1.pop();
            for (auto it : dir) {
                newrow = row + it.first;
                newcol = col + it.second;

                if (newrow >= 0 && newrow < n && newcol>= 0 && newcol < m &&!visited[newrow][newcol] &&image[newrow][newcol] == original) {
                    image[newrow][newcol] = color;
                    visited[newrow][newcol] = 1;
                    q1.push({newrow, newcol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        fill(visited, sr, sc, color, image);
        return image;
    }
};