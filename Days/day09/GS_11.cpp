/*

leetcode ID :  https://leetcode.com/vishal1029/


1169. Invalid Transactions
Medium
422
2K
Companies
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]

*/




// using class || creating userdefined dataType which holds all data in transaction

class Transaction{
    public:
    string person_name;
    int transaction_time;
    int transaction_ammount;
    string transaction_city;

    // constructor for creating object
    Transaction(string name, int time, int ammount , string city){
        this->person_name = name;
        this->transaction_time = time;
        this->transaction_ammount = ammount;
        this->transaction_city = city;
    }
};





class Solution {
public:

    // method to find invalid transactions
    vector<string> invalidTransactions(vector<string>& transactions) {
    
    vector<bool> isValid(transactions.size(),true);
    vector<Transaction> TransactionStorage;
    vector<string> ans;
     for(auto t : transactions){
            
        int count =0;
        string name,city,temp="",stime,sammount;
        int time,ammount;
            for(auto c : t){
                if(c == ','){ count++; temp =""; continue; 
                }
                if(count == 0){ name += c; 
                }
                else if(count == 1){ stime += c;
                }
                else if(count == 2){  sammount += c;
                }
                else if(count ==3){ city += c;
                } 
            }
            time = stoi(stime);  ammount = stoi(sammount);
            Transaction newTransaction(name,time,ammount,city);       // newTransaction object
            TransactionStorage.push_back(newTransaction);                             // transation added in vector after convertin it in Transaction type from string 
                                                                      //      so we can check this transaction is valid or not
     }         
     
     for(auto tr : TransactionStorage){
         cout<<tr.person_name<<" "<<tr.transaction_time<<" "<<tr.transaction_ammount<<" "<<tr.transaction_city<<endl;
     }
     // now check tranaction is valid or not 
     // condition (1) :  ammount<=1000 -> valid
     int i=0;
     for(auto tr : TransactionStorage){
         if(tr.transaction_ammount>1000){
             isValid[i] = false;
         }
          i++;
     }
    // condition (2) :  ammount<=1000 -> valid
     for(int i=0; i<TransactionStorage.size(); i++){
         for(int j=0; j<TransactionStorage.size();j++){
             if(i==j){
                 continue;
             }
             int timeDiff =  abs(TransactionStorage[i].transaction_time - TransactionStorage[j].transaction_time);
             if(timeDiff<=60){
                 if((    TransactionStorage[i].person_name == TransactionStorage[j].person_name)   and   (TransactionStorage[i].transaction_city != TransactionStorage[j].transaction_city    )){
                     isValid[i] = false;
                     isValid[j] = false;
                 }
             }
             
         }
     }
                                          
    
    for(int i=0; i<isValid.size(); i++){
        if(isValid[i] == false){
            cout<<i<<" ";
            ans.push_back(transactions[i]);
        }
    }
     
     return ans;
    }
};













































// class Transaction {
//     public:
//     // name of the person making the transaction
//     string personName;
//     // time of the transaction in minutes
//     int transactionTime; 
//     // amount of the transaction
//     int transactionAmount;
//     // city of the transaction
//     string transactionCity;
        
//     // constructor for creating transaction object
//     Transaction(string name, int time, int amount, string city)
//     {
//         this->personName = name;
//         this->transactionTime = time;
//         this->transactionAmount = amount;
//         this->transactionCity = city;
//     }
// };

// class Solution {
// public:

//     // method to find invalid transactions
//     vector<string> invalidTransactions(vector<string>& transactions) {
//         int numTransactions = transactions.size();
//         // boolean flag for each transaction indicating whether it's valid or not
//         vector<bool> isValid(numTransactions, true);
//         vector<Transaction> inputTransactions;
        
//         // Extracting information from string
//         for(int i=0; i<numTransactions; i++)
//         {
//             string currTransaction = transactions[i];
//             string name = "", time = "", amount = "", city = "";
//             int j = 0;
            
//             // Extracting name
//             while(currTransaction[j] != ',')
//             {
//                 name += currTransaction[j++];
//             }
//             j++;
//             // Extracting time
//             while(currTransaction[j] != ',')
//             {
//                 time += currTransaction[j++];
//             }
//             j++;
//             // Extracting amount
//             while(currTransaction[j] != ',')
//             {
//                 amount += currTransaction[j++];
//             }
//             j++;
//             // Extracting city
//             while((j < currTransaction.size()) && (currTransaction[j] != ','))
//             {
//                 city += currTransaction[j++];
//             }
            
//             // Creating a new transaction object with the extracted information
//             Transaction newTransaction(name, stoi(time), stoi(amount), city);
//             inputTransactions.push_back(newTransaction);
//         }
        
//         // First check: transaction amount > 1000
//         for(int i=0;i<inputTransactions.size(); i++)
//         {
//             if(inputTransactions[i].transactionAmount > 1000)
//                 isValid[i] = false;
//         }
        
//         // Second check, pair-wise
//         for(int i=0;i<(inputTransactions.size()); i++)
//         {
//             for(int j=0; j<inputTransactions.size(); j++)
//             {
//                 // We do not need to check a transaction against itself
//                 if(i == j)
//                     continue;
//                     int timeDiff = abs(inputTransactions[j].transactionTime - inputTransactions[i].transactionTime);
//             if(timeDiff <= 60)
//             {
//                 if((inputTransactions[j].personName == inputTransactions[i].personName) && (inputTransactions[j].transactionCity != inputTransactions[i].transactionCity))
//                 {
//                     // If the above conditions are met, the transaction is invalid.
//                     isValid[i] = false;
//                     isValid[j] = false;
//                 }
//             }
//         }
//     }
    
//     // Adding invalid transactions to the answer
//     vector<string> invalidTransactions;
//     for(int i=0;i<inputTransactions.size(); i++)
//     {
//         if(!isValid[i])
//             invalidTransactions.push_back(transactions[i]);
//     }
    
//     return invalidTransactions;
// }
// };


// uning map of map -- . incomplete 

// class Solution {
// public:
//     vector<string> invalidTransactions(vector<string>& transactions) {
//         unordered_map<string,int> tempp;
//         vector<string> ans;
//         unordered_map<string,unordered_map<string,int>> mpp;     // {key : val} ==> {name : {city : time}};
//         for(auto t : transactions){
//             string temp = "";
//             int count =0;
//             string name ="",time="",ammount="",city="";
//             for(auto c : t){
//                 if(c == ','){
//                     count++;
//                     temp ="";
//                     continue;
//                 }
//                 if(count == 0){
//                     name += c;
//                 }
//                 else if(count == 1){
//                     time += c;
//                 }
//                 else if(count == 2){
//                     ammount += c;
//                 }
//                 else if(count ==3){
//                     city += c;
//                 } 
//             }
//             if(stoi(ammount)>1000){
//                 ans.push_back(t);
//             }
//             else if(mpp.find(name) != mpp.end()){        // transaction with same name is found
//                 if(mpp[name].find(city)  == mpp[name].end()){  // transaction done in different city by same person -> invalid transaction
//                 tempp[city] = stoi(time);
//                 mpp[name] =  tempp[city];
//                      for(auto ct : mpp[name] ){
//                          if(ct.second <= 60){
//                             ans.push_back(name + ',' + time + ',' + ammount+',',city);
//                          }
//                      }
//                 }
//             }
//             else{
//                 tempp[city] = stoi(time);
//                 mpp[name] =  tempp[city];
//             }  
//         }
//     }
// };