class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));


        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;

            int d=q.front().second;

            q.pop();

            dis[u][v]=d;

            vector<int> x={-1,0,1,0};
            vector<int> y={0,1,0,-1};

            for(int i=0;i<4;i++){
                int du=x[i]+u;
                int dv=y[i]+v;

                if(du>=0 && du<m && dv>=0 && dv<n && !vis[du][dv]){
                    q.push({{du,dv},d+1});
                    vis[du][dv]=1;
                }

            }
        }

        return dis;

    }
};