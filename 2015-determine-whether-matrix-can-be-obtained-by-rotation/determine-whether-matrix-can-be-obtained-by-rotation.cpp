class Solution {
public:
    void rotate90(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        if(mat.size()!=target.size())
        return false;

        if(mat==target)
        return true;

        int mat_count1=0,tar_count1=0;
        for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat.size();j++)
        if(mat[i][j]==1)
        mat_count1++;


        for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat.size();j++)
        if(mat[i][j]==1)
        tar_count1++;

        if(tar_count1!=mat_count1)
        return false;

        int n=4;
        while(n--)
        {
            rotate90(mat);
            if(mat==target)
                return true;
        }
return false;
    }
};