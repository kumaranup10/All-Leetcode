class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>m;

        for(auto c:s)
        m[c]++;


        int req=m[s[0]];
        for(auto & i : m)
        if(i.second!=req)
        return false;


        return true;

    }
};