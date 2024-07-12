class Solution {
public:
    int maximumGain(string s, int x1, int y1) {
        string str1 = "ab";
        string str2 = "ba";
        if(x1<y1) {
            str1 = "ba";
            str2 = "ab";
            swap(x1,y1);
        }

        stack<char> st;
        int ans = 0;

        for(auto x: s) {
            if(x!='a' and x!='b')st.push(x);
            else {
                if(x == str1[0])st.push(x);
                else {
                    if(!st.empty()) {
                        char ch = st.top();
                        if(ch == str1[0]) {
                            ans+=x1;
                            st.pop();
                        }
                        else st.push(x);
                    } 
                    else st.push(x);
                }
            }
        }

        string tmp;
        while(!st.empty()){
            tmp+=st.top();
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        
        for(auto x: tmp) {
            if(x!='a' and x!='b')st.push(x);
            else {
                if(x == str2[0])st.push(x);
                else {
                    if(!st.empty()) {
                        char ch = st.top();
                        if(ch == str2[0]) {
                            ans+=y1;
                            st.pop();
                        }
                        else st.push(x);
                    } 
                    else st.push(x);
                }
            }
        }
        return ans;
    }
};
