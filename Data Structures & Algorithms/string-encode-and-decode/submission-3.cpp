class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (auto& st : strs) {
            s += to_string(st.size()) + '#' + st;
        }
        return s;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> msg;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i));
            j++;
            i = j + len;
            
            msg.push_back(s.substr(j, len));
        }

        return msg;
    }
};
