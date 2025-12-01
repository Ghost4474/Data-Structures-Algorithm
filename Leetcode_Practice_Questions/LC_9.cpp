class Solution {
public:
    bool isPalindrome(int x) {
        long k =0;
        int num=x;
        while(num>0){
            int rem;
            rem=num%10;
            k=(k*10)+rem;
            num=num/10;
        }
        if(k==x){
            return bool(1);
        }else{
            return bool(0);
        }
    }
};