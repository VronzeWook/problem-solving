#include<bits/stdc++.h>
using namespace std;
int ap[26] ;
string s;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ap[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++) cout << ap[i] << " ";
    return 0;
}