#define loop(i,n) for(int i=0;i<n;i++)
class Solution {
public:
bool is_operator(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/'){
        return true;
    }
    return false;
}

long solve(long a,long b,char ch){
    if(ch=='+'){return a+b;}
    else if(ch=='-'){return a-b;}
    else if(ch=='*'){return a*b;}
    else{
        return a/b;
    }
}
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long> st;
    loop(i,n){
       if(tokens[i].size()==1 && tokens[i][0]<48){
           
           long x1 = st.top(); 
           st.pop();
           long x2 = st.top(); 
           st.pop();
           long ans = solve(x2,x1,tokens[i][0]);
           st.push(ans);
        }
           else{
               st.push(stol(tokens[i]));
           }
       } 
       return st.top();
    }
};