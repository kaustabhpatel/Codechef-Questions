#include"bits/stdc++.h"
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    string s, p;

    while(t--) {
        cin >> s;
        cin >> p;

        vector<int> alphabets(26);
        for(int i = 0; i < s.size(); i++) {
            alphabets[(int)(s[i] - 'a')]++;
        }

        for(int i = 0; i < p.size(); i++) {
            alphabets[(int)(p[i] - 'a')]--;
        }

        vector<int> temp(alphabets);

        string lexico_out, lexico_out_less;
        int val = (int)(p[0] - 'a');
        for(int i = 0; i < val; i++) {
            while(alphabets[i] != 0) {
                lexico_out = lexico_out + (char)((int)'a' + i);
                alphabets[i]--;
            }
        }

        int flag = 0;
        for(int i = 0; i <= p[val]; i++) {
            if(val > (int)(p[i] - 'a')) {
                flag = 1;
                break;
            }
            else if(val < (int)(p[i] - 'a')) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            lexico_out = lexico_out + p;
            while(alphabets[val] != 0) {
                lexico_out = lexico_out + (char)((int)'a' + val);
                alphabets[val]--;
            }
        }
        else {
            while(alphabets[val] != 0) {
                lexico_out = lexico_out + (char)((int)'a' + val);
                alphabets[val]--;
            }
            lexico_out = lexico_out + p;
        }

        for(int i = val+1; i < 26; i++) {
            while(alphabets[i] != 0) {
                lexico_out = lexico_out + (char)((int)'a' + i);
                alphabets[i]--;
            }
        }

        cout << lexico_out << "\n";
        
    }
    return 0;
}