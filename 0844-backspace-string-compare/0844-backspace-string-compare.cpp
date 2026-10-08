class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> tt;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(!tt.empty()){
                    tt.pop();
                }
            }
            else{
                tt.push(t[i]);
            }
        }

        string a = "";
        string b = "";

        while(!st.empty()){
            a += st.top();
            st.pop();
        }

        while(!tt.empty()){
            b += tt.top();
            tt.pop();
        }

        return a == b;
    }
};