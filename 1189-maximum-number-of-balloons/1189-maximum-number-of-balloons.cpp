class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bc=0,ac=0,lc=0,oc=0,nc=0;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='b')
            bc++;
            if(text[i]=='a')
            ac++;
            if(text[i]=='l')
            lc++;
            if(text[i]=='o')
            oc++;
            if(text[i]=='n')
            nc++;
        }
        oc=oc/2;
        lc=lc/2;
        return min({bc,ac,lc,oc,nc});
    }
};