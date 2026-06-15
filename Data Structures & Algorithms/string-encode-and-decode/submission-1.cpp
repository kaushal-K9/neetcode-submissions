class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (auto &s: strs) {
            encoded += to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        
        vector<string> decoded;

        int i = 0;

        while (i < s.size()) {

            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i)); //multiple digits possible
            j++;

            decoded.push_back(s.substr(j, len));
            i = j + len;
        }

        return decoded;
    }
};
