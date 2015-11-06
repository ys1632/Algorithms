#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

bool ifValid(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') count++;
            if (s[i] == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
}
    
vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> res;
        if (s.length() < 1) {
            res.push_back(s);
            return res;
        }
        
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            
            if (ifValid(str)) {
                res.push_back(str);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != '(' && str[i] != ')') continue;
                string str2 = str.substr(0, i) + str.substr(i+1);
                if (!visited.count(str2)) {
                    q.push(str2);
                    visited.insert(str2);
                }
                
            }
        }
        return res;
}

int main() {
    vector<string> res = removeInvalidParentheses("()())()");
    for (auto &a : res)
        cout << a << " ";
    return 0;
}

