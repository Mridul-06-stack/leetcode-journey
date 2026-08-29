class Solution {
public:
    bool find(int n, unordered_map<int,int>& visited) {

        if (n == 1)
            return true;
        if (visited.count(n))
            return false;

        visited[n]==1;

        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return find(sum, visited);
    }

    bool isHappy(int n) {
        unordered_map<int,int> visited;
        return find(n, visited);
    }
};