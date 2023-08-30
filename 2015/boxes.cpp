#include<bits/stdc++.h>
#include "boxes.h"
#define LL long long
#define N 10000010

using namespace std;

LL pref[N], suf[N];

LL delivery(int n, int k, int L, int p[]){
    pref[0] = 2*p[0];

    for(int i = 1;i < n;i++){
        pref[i] = 2*p[i] + (i >= k ? pref[i-k]:0); 
    }

    // for(int i = 0;i < n;i++) cout << pref[i] << " ";

    // cout << "\n";

    for(int i = n-1;i >= 0;i--){
        suf[i] = 2*(L - p[i]) + (n-1 - i >= k ? suf[i+k]:0);
    }

    // for(int i = 0;i < n;i++) cout << suf[i] << "\n";

    LL res = 1e16;

    for(int i = 0;i < n;i++){
        // cout << i << " " << pref[i] + suf[i+1] << "\n";    
        res = min(res, pref[i] + suf[i+1]);
    }

    res = min(res, suf[0]);

    for(int i = 0;i < n;i++){
        // cout << i << " " << (i > 0 ? pref[i-1] : 0) + (i+k < n+5 ? suf[i+k] : 0) + L << "\n";
        res = min(res, (i > 0 ? pref[i-1] : 0) + (i+k < n+5 ? suf[i+k] : 0) + L);
    }

    return res;
}
