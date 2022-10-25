class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
         for(int i=A.size()-1;i>=0&&K>0;i--)
        {
            A[i]+=K;
            K=A[i]/10;
            A[i]%=10;
        }
        while(K>0)
        {
             A.insert(A.begin(),K%10);
             K/=10;
        }
        return A;
   
        
        
        
        
        
        
        
        
        
      /* int n=num.size()-1;
       vector<int> v;
       int c=0,i,sum=0;
       for(i=n;i>=0 && k>0;i--)
       {
           sum=(num[i]+k%10+c)%10;
           v.insert(v.begin(),sum);
           c=(num[i]+k%10+c)/10;
           k=k/10;
       }
       n=i;
       for(int i=n;i>=0;i--){
           if(c!=0 && num[i]==9)
               v.insert(v.begin(),0);
           else{
                v.insert(v.begin(),(num[i]+c)%10);
                c=(num[i]+c)/10;
           }
       }
       while(k)
       {
           v.insert(v.begin(),(k%10+c)%10);
           c=(k%10+c)/10;
           k=k/10;
       }
       if(c!=0)
           v.insert(v.begin(),c);
       return v;*/
    }
};