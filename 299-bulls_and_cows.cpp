#include <iostream>
#include <sstream>

using namespace std;

//O(10) Space, O(n) time (scan the string once)
string getHint(string secret, string guess) {
        int len = secret.length();
        
        int cows = 0;
        int bulls = 0;
        int count[] = {0,0,0,0,0,0,0,0,0,0};
        
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                int cnt = ++count[secret[i] - '0'];
                if (cnt <= 0) cows++;
                cnt = --count[guess[i] - '0'];
                if (cnt >= 0) cows++;
            }
        }
        
        stringstream ss;
        ss << bulls;
        
        stringstream ss2;
        ss2 << cows;
        
        return ss.str() + "A" + ss2.str() + "B";   
    }

//2nd methond
//two O(n) space (map and vector), O(n) time (but need to scane the string twice)
string getHint2(string secret, string guess) {
        int len = secret.length();
        int bulls = 0;
        int cows = 0;
        map<char, int> mp;
        vector<bool> flag(len, false);
        
        for (int i = 0; i < len; i++) {
            if (guess[i] == secret[i]) {
                bulls++;
                flag[i] = true;
            } else {
                if (mp.count(secret[i])) {
                    mp[secret[i]]++;
                }
                else {
                    mp[secret[i]] = 1;
                }
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (mp.count(guess[i]) && !flag[i]) {
                cows++;
                mp[guess[i]]--;
                if (mp[guess[i]] == 0) mp.erase(guess[i]);
            }
        }
        
        stringstream ss;
        ss << bulls;
        stringstream ss2;
        ss2 << cows;
        
        return ss.str() + "A" + ss2.str() + "B";
    }    

int main() {
	cout << getHint("1807", "7810") << endl; //1A3B
	cout << getHint("1123", "0111") << endl; //1A1B

}