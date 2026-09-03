class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> nums2(n);
        int min_ele=INT_MAX;

        for(int i=0;i<nums1.size();i++){
            min_ele=min(min_ele,nums1[i]);
        }
        
        if(min_ele%2!=0){
            return true;
        }
        else{
            for(int i=0;i<n;i++){
                if(nums1[i]%2!=0){
                    return false;
                }
            }
        }

        // if(min_ele%2==0){
        //     for(int i=0;i<nums1.size();i++){
        //         if(nums1[i]%2==0){
        //             nums2[i]=nums1[i];
        //         }
        //         else{
        //             nums2[i]=nums1[i]-min_ele;
        //         }
        //     }
        // }  

        return true; 
    }
};