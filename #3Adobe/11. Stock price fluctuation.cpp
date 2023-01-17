class StockPrice {
public:
map<int,int> m;
multiset<int> s;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       if(m.find(timestamp)!=m.end()){
           int x = m[timestamp];
           s.erase(s.find(x));
           s.insert(price);
           m[timestamp] = price;
       }
       else{
           s.insert(price);
           m[timestamp] = price;
       }
    }
    
    int current() {
        return (*m.rbegin()).second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */