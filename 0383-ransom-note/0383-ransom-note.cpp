class Solution {
public:
    bool canConstruct(string str1, string str2) {
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<str1.size();i++)
            arr1[str1[i]-97]++;
        for(int i=0;i<str2.size();i++)
            arr2[str2[i]-97]++;
        for(int i=0;i<str1.size();i++)
        {
            if(arr1[str1[i]-97]>arr2[str1[i]-97])
                return false;
        }
        return true;
        
    }
};