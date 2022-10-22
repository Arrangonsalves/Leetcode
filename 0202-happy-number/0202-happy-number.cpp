class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s; 
        int m,b=0;
        if(n==1 || n==10)
            return true;
        while(1)
        {
            m=n;
            while(m>0)
            {
                int a=m%10;
                //cout<<"a:"<<a<<endl;
                a=pow(a,2);
                b=b+a;
                m=m/10;
                //cout<<"b:"<<b<<" "<<"m:"<<m<<endl;
            }
            if(b==1)
                return true;
            if(s.find(b)!=s.end())
                return false;
            s.insert(b);
            n=b;
            b=0;
       }
       return false;
        
    }
};