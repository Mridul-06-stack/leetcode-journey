class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
    
        int n = 0;
        int balance = 0;
        int paid = 0;
        while (n < bills.size()) {
             
            paid = bills[n];
            n++;
            balance = paid - 5;
            if (paid == 5) {
                five++;
            } else if (paid == 10) {
                ten++;
            }
            if (balance == 0) {
                continue;
            } else {
                while (balance != 0) {
                   if (ten > 0&& balance>=10) {
                        ten--;
                        balance=balance-10; }
                    else if (five > 0) {
                        five--;
                        balance=balance-5;
                    } 
                     else {
                        return false;
                    }
                }
            }
           
        }

        return true;
    }
};