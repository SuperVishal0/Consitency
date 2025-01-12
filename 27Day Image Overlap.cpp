class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n=img1.size();// find the size of img1
        
        // created two pair vector to store the indexing of 1 in img1 and img2
        vector<pair<int,int>>non_zero1; 
        vector<pair<int,int>>non_zero2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    non_zero1.push_back({i,j}); // pushed the idx of 1 in non_zero vector
                }
                if(img2[i][j]==1){
                    non_zero2.push_back({i,j}); // pushed the idx of 2 in non_zero vector
                }
            }
        }
                
        map<pair<int,int>,int>mp; // createda map to stroe the max difference b/w their axis
        int ans=0;
        
        for(auto [i1,j1]:non_zero1){
            for(auto [i2,j2]:non_zero2){
                mp[{i2-i1,j2-j1}]++; // axis difference ++
                ans=max(ans,mp[{i2-i1,j2-j1}]); // max of axis difference 
            }
        }
        
        return ans; // return our answer
        
    }
};
