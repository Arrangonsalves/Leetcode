class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map <int,int> m2;
        for(int i=0;i<nums2.size();i++)
            m2[nums2[i]]++;
        for(int i=0;i<nums1.size();i++){
            if(m2[nums1[i]]){
                v.push_back(nums1[i]);
                m2[nums1[i]]--;
            }
        }
        return v;
    }
};