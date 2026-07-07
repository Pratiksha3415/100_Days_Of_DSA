class Solution {
public:
    bool isPalindrome(int x) {
        int original=x;
        long long reverse=0;
        while(x>0){
            int d=x%10;
            reverse=(reverse*10)+d;
            x=x/10;
            
        }
        if(reverse==original){
            return true;
        }else{
            return false;
        }
        
    }
};