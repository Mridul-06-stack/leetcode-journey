#include <climits>

class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long base = 1000;
        
        while (n >= base) {
            // Add commas for all numbers greater than or equal to the current base
            commas += (n - base + 1);
            
            // Prevent overflow if n is near the maximum value of long long (10^18)
            if (base > LLONG_MAX / 1000) {
                break;
            }
            
            base *= 1000;
        }
        
        return commas;
    }
};