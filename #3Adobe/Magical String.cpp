class Solution {
public:
    int magicalString(int n) {
        int ans=0;
        if(n<=3){
            return 1;
        }
        string s = "122";
        int end=2;
        int j = 2;
        while(s.length()<n){
            if(s[j]=='2' && s[end]=='2'){
                s+='1';s+='1';
                j++;
            }
            else if(s[j]=='1' && s[end]=='2'){
                s+='1';
                j++;
            }
            else if(s[j]=='2' && s[end]=='1'){
                s+='2';s+='2';
                j++;
            }
            else{
                s+='2';
                j++;
            }
            end = s.length()-1;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans++;
            }
        }
        return ans;
    }
};