class Solution {
public:
    int vowelConsonantScore(string s) {
        int c=0,v=0;
        string vowel="aeiou";
        for(auto i:s)
        {
            if(vowel.find(i)!=string::npos)
            v++;
            else if(isalpha(i))
            c++;
        }
        if(c==0)
        return 0;
        return v/c;
    }
};