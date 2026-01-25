/*
Sort characters by frequency



Problem Statement: You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
If two or more characters have same frequency then arrange them in alphabetic order.
*/

#include <bits/stdc++.h>
using namespace std;

string sortByFrequency(string s){
    unordered_map<char, int> freq;
    for(char c : s){
        freq[c]++;
    }
    vector<pair<char, int>> v;
    for(auto it : freq){
        v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(), [](pair<char,int>& a, pair<char,int>& b){
        if(a.second != b.second)
            return a.second > b.second;  
        return a.first < b.first;       
    });
    string result = "";
    for(auto p : v){
        result += p.first;
    }

    return result;
}

int main(){
    string s = "programming";
    cout<< sortByFrequency(s) << endl;

    return 0;
}
