
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string inputString, string delimiter) {
    vector<string> result = vector<string>();

    // check if 'delimiter' is present in 'inputString'
    int first_index = inputString.find(delimiter);
    if (first_index == -1) {
        result.push_back(inputString);
        return result;
    }
    
    // there's at least one delimiter in the string, so add the substrings
    string remaining = inputString;
    while (remaining.find(delimiter) != -1) {
        int i = remaining.find(delimiter);
        string substr = remaining.substr(0, i);
        result.push_back(substr);
        remaining = remaining.substr(i+delimiter.length());
    }

    // add the last substring if it's not empty
    if (remaining != "")
        result.push_back(remaining);

    return result;
}
