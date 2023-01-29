/*

166. Fraction to Recurring Decimal
Medium
1.8K
3.3K
Companies
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
*/

class Solution {
public:
    string tostring(long long n){
        if (n==0)return "0";
        string ans;
        while (n>0){
            string dem;
            dem+= ((n%10)+'0');
            ans= dem+ans;
            n/=10;
        }
        return ans;
    }
    string fractionToDecimal(int num, int denom) {
        if (num==0)return "0";
        string ans;
        if ((num<0 && denom>0) || (num>0 && denom<0))ans.push_back('-');
        num= abs(num); denom= abs(denom);
        long long quotient= num/denom;
        long long remainder= num%denom;
        ans= ans+tostring(quotient);
        if (remainder==0)return ans;
        ans+='.';
        map<long long, int> mp;
        while (remainder != 0){
            if (mp.find(remainder)!= mp.end()){
                int pos= mp[remainder];
                ans.insert(pos,"(");
                ans+=')';
                break;
            }
            else {
                mp[remainder]= ans.length();
                remainder*= 10;
                quotient= remainder/denom;
                remainder= remainder%denom;
                ans+= tostring(quotient);
            }
        }
        return ans;
    }
};