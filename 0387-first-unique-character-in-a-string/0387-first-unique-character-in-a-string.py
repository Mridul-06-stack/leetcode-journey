class Solution:
    def firstUniqChar(self, s: str) -> int:

        freq = [0] * 26

      
        for x in s:
            freq[ord(x) - ord('a')] += 1

        for i, x in enumerate(s):
            if freq[ord(x) - ord('a')] == 1:
                return i

        return -1