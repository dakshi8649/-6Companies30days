class Solution {
public:
long long int dis_btw(vector<int> p1,vector<int> p2){
long long int x1 = pow(abs(p1[0]-p2[0]),2) + pow(abs(p1[1]-p2[1]),2);
return x1;
}
int fact(int n){
    if(n<=1){
        return 1;
    }
    return n*fact(n-1);
}
int perm(int n,int r){
    int x1=fact(n);
    int x2=fact(n-r);
    return x1/x2;
}
 map<int,int> m;
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<points.size();i++){
            vector<int> v;
            for(int j=0;j<points.size();j++){
                if(i!=j){
                v.push_back(dis_btw(points[i],points[j]));
            }}
            for(int i=0;i<v.size();i++){
                m[v[i]]++;
            }
            for(auto it:m){
                if(it.second>=2){
                    ans+=(perm(it.second,2));
                }
            }
            m.clear();
        }
        return ans;
    }
};