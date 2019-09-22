//https://leetcode.com/problems/powx-n/

//playground не доступен

class Solution {
public:
    double myPow(double x, int &n) {
        if (abs(x)==1) {return x;}
        else
        {
            if (n==0) {return 1;}
            else
            {
                if (n==-2147483648) {n++; return (1/x)*myPow(x,n);}
                else
                {
                    bool negative=false;
                    if (n<0) {negative=true; n=-n;}
                    if (n==1) {if (negative) {return 1/x;} else {return x;};}
                    else
                    {
                        double ans=x;
                        while (n>1)
                        {
                            if (n%2 == 0)
                            {
                                ans*=ans;
                                n/=2;
                            }
                            else
                            {
                                n--;
                                ans*=myPow(ans, n); 
                            };
                        };
                        if (negative) {return 1/ans;} else {return ans;};
                    }
                }
            }
        }
    }
};
