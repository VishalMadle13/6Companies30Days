/*
2327. Number of People Aware of a Secret
Medium
619
100
Companies
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
Example 2:

Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
 

*/


// method 1 not optimized approach
// class Solution {
// public:
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         vector<int> person;
//         person.push_back(1);
//         for(int i=1; i<=n; i++){
//           for(int j=0; j<person.size(); j++){
//                    person[j]++; 
//             }
//             for(int j=0; j<person.size(); j++){
//                 if(person[j] >= delay+1 and person[j] < forget+1){
//                     person.push_back(1);
//                 }
//             }
//         }
//         int c =0;
//         for(auto x : person){
//             cout<<x<<" ";
//             if(x <= forget){
//                 c++;
//             }
//         }
//         return c;  
//     } 
  
// };


 
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // vector<int> day(n,0);
        
        // day[0] = 1;
        // for(int i=0; i<n; i++){
        //     if(day[i]>0){
        //         for(int j=delay+i; j<forget+i; j++){
        //             if(j>=n){
        //                 break;
        //             }
        //             day[j] = day[i] + day[j];
        //         }
        //     }
        // }
        // for(auto x : day){
        //     cout<<x<<" ";
        // }
        // int c = 0;
        // for(int i=n-1; i>=0; i--){
        //     if(day[i]== 0){
        //         break;
        //     }
        //     c+= day[i];
        // }
        // return c;
        #define ll long long
        #define MOD 1000000007
        ll day = 2, taken = 1;
 
        vector <array <ll, 3>> persons = {{delay + 1, forget + 1, 1}};
 
        while(day<=n){
            // remove all those persons who forgets secrets
            while(!persons.empty() && persons[0][1] == day){
                persons.erase(persons.begin());
            }
 
            // find number of persons that can spread secret
            ll cnt = 0;
            for(auto& x : persons){
                if(x[0] <= day){
                    cnt += x[2];
                }
 
                cnt %= MOD;
            }
 
            persons.push_back({day + delay, day + forget, cnt});
 
            day++;
        }       
 
        ll ans = 0;
        for(auto& x : persons){
            ans += x[2];
            ans %= MOD;
        }
 
        return ans;

    } 
};