class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0, r = rows - 1;
        int row = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target)
            {
                row = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (row == -1)
            return false;

        l = 0;
        r = cols - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[row][mid] == target)
                return true;

            if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};