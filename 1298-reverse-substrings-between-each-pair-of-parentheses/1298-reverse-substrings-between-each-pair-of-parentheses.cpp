class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
    
    for (char ch : s) {
        if (ch == ')') {
        string substr = "";
        while (!st.empty() && st.top() != '(') {
            substr += st.top();
            st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            for (char subCh : substr) {
                st.push(subCh);
            }
        } else {
            st.push(ch);
        }
    }
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
    }
};