class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        string ans = "";

        int left = 0;
        int right = 0;
        int temp;
        int bit;

        while (left < a.size() && right < b.size()) {
            temp = (a[left] - '0') + (b[right] - '0') + carry;

            carry = temp / 2;
            bit = temp % 2;

            ans.push_back(bit + '0');

            left++;
            right++;
        }

        while (left < a.size()) {
            temp = (a[left] - '0') + carry;

            carry = temp / 2;
            bit = temp % 2;

            ans.push_back(bit + '0');

            left++;
        }

        while (right < b.size()) {
            temp = (b[right] - '0') + carry;

            carry = temp / 2;
            bit = temp % 2;

            ans.push_back(bit + '0');

            right++;
        }

        if (carry)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};