/*

leetcode ID :  https://leetcode.com/vishal1029/


150. Evaluate Reverse Polish Notation
Medium
5.3K
841
Companies
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9



*/


// solution:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> st;
        long long int  a , b;
    
        for(string x : tokens){
                
                
            if(st.size()<2){
                st.push(stoi(x));
            }
            else{
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                
                if(x == "+")
                    st.push(a+b);
                else if(x == "-")
                    st.push(b-a);
                else if(x == "*")    
                    st.push(a*b);
                else if(x == "/")
                    st.push(b/a);
                else {
                    st.push(b);
                    st.push(a);
                    st.push(stoi(x)); 
                 }
            }
        }
        return st.top();
    }
};