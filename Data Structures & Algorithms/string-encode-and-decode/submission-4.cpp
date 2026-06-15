class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (auto& s : strs) {
            encoded += to_string(s.size()) + '#' + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> decoded;

        while (i < s.size()) {
            
            int j = i;

            while(s[j] != '#') j++; //at this time j is on #

            int len = stoi(s.substr(i, j - i));
            j++;
            i = j + len;

            decoded.push_back(s.substr(j, len));
        }

        return decoded;
    }
};
