class Solution {
public:
    vector<int> sp;
    string s;

    string encode(vector<string>& strs) {
        sp.clear();
        s.clear();

        for (auto &st: strs) {

            sp.push_back(st.size());

            for (char c: st) {
                s += c;
            }
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int idx = 0;

        for (auto &len: sp) {
            // string temp = s.substr(0, it);
            decoded.push_back(s.substr(idx, len));
            idx += len;
            // s.erase(0, it);
        }

        return decoded;
    }
};
