#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isValid(string s) {

    string part1 = "ab*";


    string part2 = "((a*(b+)*|ab)+)";


    regex fullExpr("^(" + part1 + "|" + part2 + ")$");

    return regex_match(s, fullExpr);
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (isValid(input)) {
        cout << "Result: ACCEPT" << endl;
    } else {
        cout << "Result: REJECT" << endl;
    }

    return 0;
}
