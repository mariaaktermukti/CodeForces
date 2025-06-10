#include<bits/stdc++.h>

using namespace std;

string tanuAndHeadBob(string s);

int main() {
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << tanuAndHeadBob(s) << endl;
    }

    return 0;
}

string tanuAndHeadBob(string s){
    int countOfY = 0, countOfI = 0;

    for (int i = 0; i < s.length(); ++i){
        if(s[i] == 'Y')
            countOfY++;
        else if(s[i] == 'I')
            countOfI++;
    }

    if(countOfI != 0)
        return "INDIAN";
    else if(countOfY != 0)
        return "NOT INDIAN";
    else
        return "NOT SURE";
}