class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1 = [0] * 26
        freq2 = [0] * 26
        for i in range(max(len(s), len(t))):
            if i < len(s):
                freq1[ord(s[i]) - ord("a")] += 1
            if i < len(t):
                freq2[ord(t[i]) - ord("a")] += 1
        for i in range(26):
            if freq1[i] != freq2[i]:
                return False
        return True
