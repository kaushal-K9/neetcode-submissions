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
        vector<string> msg;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i));
            j++;

            msg.push_back(s.substr(j, len));
            i = j + len;
        }

        return msg;
    }
};
