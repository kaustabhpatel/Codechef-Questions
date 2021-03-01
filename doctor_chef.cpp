#include"bits/stdc++.h"
using namespace std;

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, x;
        cin >> n >> x;
        
        vector<long long int> A(n);
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());
        long long int low_bound = lower_bound(A.begin(), A.end(), x) - A.begin();
        long long int no_of_days = 0;

        for(int i = low_bound; i < n; i++) {
            if(x < A[i]) {
                while(x < A[i]) {
                    x = 2 * x;
                    no_of_days++;
                }
                no_of_days++;
            }
            else {
                no_of_days++; 
            }
            x = 2 * A[i];
        }

        long long int val = low_bound + no_of_days;
        if(low_bound != 0) {
            no_of_days = 0;
            low_bound--;
            for(int i = low_bound; i < n; i++) {
                if(x < A[i]) {
                    while(x < A[i]) {
                        x = 2 * x;
                        no_of_days++;
                    }
                    no_of_days++;
                }
                else {
                    no_of_days++;
                }
                x = 2 * A[i];
            }
            if(no_of_days + low_bound < val) {
                cout << no_of_days + low_bound << "\n";
            }
            else {
                cout << val << "\n";
            }
        }
        else {
            cout << val << "\n";
        }
    }
    return 0;
}