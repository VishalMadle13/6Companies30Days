/*



leetcode ID :  https://leetcode.com/vishal1029/



433. Minimum Genetic Mutation
Medium
2.4K
251
Companies
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1



*/class Solution {
public:
    
    bool able(string str, string temp){
        
        int c = 0;
        
        if(str.size() != temp.size()){
            return false;
        }
        for(int i=0; i<str.size(); i++){
            if(str[i]!=temp[i]){
                c++;
            }
        }
        
        return c==1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        
     // if end not belongs to bank return -1
      
        if((find(bank.begin(), bank.end(),end)) == bank.end()){
            return -1;
        }
  
        queue<string> q;
        unordered_map<string,bool> ma;
        ma[start]=true;
        q.push(start);
        int ans=0;
        while(!q.empty()){
            ans++;
            int m=q.size();
            for(int j=0;j<m;j++){
                string temp=q.front();
                q.pop();
                for(int i=0;i<bank.size();i++){
                    if(ma[bank[i]]!=true){
                        
                        if(able(bank[i],temp)){
                            
                            if(bank[i]==end){
                                
                                return ans;
                            }
                            ma[bank[i]]=true;
                            
                            q.push(bank[i]);
                        }
                    }
                }
             }
        }
         return -1;
        
    }
};