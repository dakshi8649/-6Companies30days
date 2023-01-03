class Solution {
public:
string rever(string t){
string ans;
for(int i=t.length()-1;i>=0;i--){
    ans+=t[i];
}
return ans;
}
    string getHint(string secret, string guess) {
        string t;
        int bulls=0;
        int cows=0;
        int h[10]={0};
        int h1[10]={0};
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                h[secret[i]-'0']++;
                h1[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(h[i],h1[i]);
        }
        t+='B';
        if(cows==0){
            t+=(0+'0');
        }
        while(cows>0){
            int rem = cows%10;
            t+=(rem+'0');
            cows/=10;
        }
        t+='A';
        if(bulls==0){
            t+=(0+'0');
        }
        while(bulls>0){
            int rem = bulls%10;
            t+=(rem+'0');
            bulls/=10;
        }
        
    return rever(t);
}
};