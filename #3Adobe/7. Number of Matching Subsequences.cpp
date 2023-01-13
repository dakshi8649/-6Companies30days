class Solution {
public:
bool check(string s1,string s2){
    int f=0,se=0;
    while(se<s1.length() && f<s2.length()){
                if(s1[se]==s2[f]){
                    se++;f++;
                }
                else{
                    se++;
                }
}
return f==s2.length();
}
unordered_map<string,int> m;
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])!=m.end() ){
            if( m.find(words[i])->second != 0){
                m[words[i]]++;
            }
            else continue;
            }
            else{
               if(check(s,words[i])){
                    m[words[i]]++;
                }
                 else {
                    m[words[i]] = 0; 
                 } 
            }
        }
        for(auto it:m){
            ans+=(it.second);
        }
        return ans;
    }
};