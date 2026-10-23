class Solution {
public:
    void f(int sr,int sc,int m,int n,int c,int color,vector<vector<int>>& vis,vector<vector<int>>& image){

        if(sr<0 || sr>=m || sc<0 || sc>=n || vis[sr][sc] || image[sr][sc]!=c) return ;

        vis[sr][sc]=1;
        image[sr][sc]=color;

        vector<int> x={0,1,0,-1};
        vector<int> y={1,0,-1,0};

        for(int d=0;d<x.size();d++){
            f(sr+x[d],sc+y[d],m,n,c,color,vis,image);
        }

        return ;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m=image.size();
        int n=image[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int c=image[sr][sc];

        f(sr,sc,m,n,c,color,vis,image);


        return image;
        
    }
};