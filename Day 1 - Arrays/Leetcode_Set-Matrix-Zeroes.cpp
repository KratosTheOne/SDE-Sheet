/* Brute T.c -> O(n * m) * O(n + m)
class Solution {
public:

    void markRow(int row, int m, vector<vector<int>>& matrix) {

        for(int j = 0; j < m; j++)
        {
            if(matrix[row][j] != 0)
            {
                matrix[row][j] = -1;
            }
        }
    }

    void markCol(int col, int n, vector<vector<int>>& matrix) {

        for(int i = 0; i < n; i++)
        {
            if(matrix[i][col] != 0)
            {
                matrix[i][col] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    markRow(i, m, matrix);
                    markCol(j, n, matrix);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
*/

// Optimized TC -> O(2 * (n * m))
//           SC -> O(1)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int col0 = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
