#define pb push_back
#define bb insert
class Solution {
public:
int sto(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
vector<pair<string,int>> func(string s){
    vector<pair<string,int>> p;
    int i=0;
    string name="";
    string city="", tim="", am="";
    while(s[i]!=','){
        name+=s[i];
        i++;
    }
    i++;
    while(s[i]!=','){
        tim+=s[i++];
    }
    i++;
    int time=sto(tim);
    while(s[i]!=','){
        am+=s[i++];
    }
    i++;
    int amount=sto(am);
    while(i<s.length()){
        city+=s[i++];
    }
    p.pb({name,time});
    p.pb({city,amount});
    return p;
}
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> result;
        vector<int> time;
        vector<int> amount;
        vector<string> name;
        vector<string> city;

        for(int i=0;i<transactions.size();i++){
             vector<pair<string,int>> p= func(transactions[i]);
             time.pb(p[0].second);
             amount.pb(p[1].second);
             city.pb(p[1].first);
             name.pb(p[0].first);
        }
        set<int> st;
        for(int i=0;i<transactions.size();i++){
            cout<<name[i]<<" "<<time[i]<<" "<<amount[i]<<" "<<city[i]<<endl;
        }
        for(int i=0;i<amount.size();i++){
            if(amount[i]>1000){
                result.pb(transactions[i]);
                st.insert(i);
            }
        }
        // set<int> st;
        map<string,vector<int>> m;
        for(int i=0;i<name.size();i++){
            if(m.find(name[i])!=m.end()){
                for(int k=0;k<m[name[i]].size();k++){
                    if(city[m[name[i]][k]]!=city[i] && abs(time[m[name[i]][k]]-time[i])<=60){
                        if(st.find(i)==st.end()){
                            result.pb(transactions[i]);
                        }
                        if(st.find(m[name[i]][k])==st.end()){
                            result.pb(transactions[m[name[i]][k]]);
                        }
                        st.insert(i);
                        st.insert(m[name[i]][k]);
                    }
                }}
                m[name[i]].pb(i);
        }  
        
        // for(auto it:ans){
        //     result.pb(it);
        // }
        return result;      
    }
};