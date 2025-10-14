#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word; vector<string> words;
    while (ss >> word) words.push_back(word);
    reverse(words.begin(), words.end());
    string res;
    for (int i = 0; i < words.size(); i++) {
        if (i) res += " ";
        res += words[i];
    }
    return res;
}
