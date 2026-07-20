class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[] ) {  //0(1)
        for (int i=0; i<26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for (int i=0;i<s1.length();i++) {
             //for a-> 0, b->1
            freq[s1[i]-'a']++; //value of freq at i will increase
        }
        int windsize = s1.length();
        for (int i=0 ; i<s2.length(); i++) {
            int windind=0, indx=i;
            int windfreq[26]={0};
            while(windind < windsize && indx <s2.length()) {
                windfreq[s2[indx]-'a']++;
                windind++; indx++;
            }
            if (isfreqsame(freq, windfreq)) { //found
                return true;
            }
        }
        return false;
    }
};