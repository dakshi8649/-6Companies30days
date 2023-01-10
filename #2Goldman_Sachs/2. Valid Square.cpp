class Solution {
public:

long long int dis_btw(vector<int> p1,vector<int> p2){
long long int x1 = pow(abs(p1[0]-p2[0]),2) + pow(abs(p1[1]-p2[1]),2);
return x1;
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       set<long long int> s;
       s.insert(dis_btw(p1,p2));
       s.insert(dis_btw(p3,p4));
       s.insert(dis_btw(p4,p2));
       s.insert(dis_btw(p3,p2));
       s.insert(dis_btw(p1,p4));
       s.insert(dis_btw(p1,p3));
       if(s.find(0)==s.end() && s.size()==2){
           return true;
       }
       return false;
    }
};