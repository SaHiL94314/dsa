//tc-o(v^3) 
//,sc-o(v^2)
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(mat[r][c]==-1) mat[r][c]=1e9;
                if(r==c) mat[r][c]=0;
            }
        }
        for(int via=0;via<n;via++){
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    mat[r][c]=min(mat[r][c],mat[r][via]+mat[via][c]);
                }
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(mat[r][c]==1e9) mat[r][c]=-1;
                if(r==c) mat[r][c]=0;
            }
        }
        
    }
};
