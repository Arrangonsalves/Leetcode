class Solution {
public:
    int bestClosingTime(string customers) {
        int max_score=0,ind=-1,n=customers.size(),score=0;
        for(int i=0;i<n;i++)
        {
           if(customers[i]=='Y')
                score++;
           else
                score--;
            if(score>max_score)
            {
                max_score=score;
                ind=i;
            }
        }
        return ind+1;
    }
};