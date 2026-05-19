#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> keywords = {
 "int", "float", "double", "char", "string", "if", "else", "for", "while",
 "return", "void", "class", "public", "private", "protected", "include",
 "using", "namespace", "main", "switch", "case", "break", "continue"
};

bool isKeyword(const string& token) {
 return find(keywords.begin(), keywords.end(), token) != keywords.end();
}

bool isNumber(const string& token) {
 for (char c : token) {
 if (!isdigit(c)) return false;
 }
 return !token.empty();
}

bool isIdentifier(const string& token) {
 if (token.empty()) return false;
 if (!(isalpha(token[0]) || token[0] == '_')) return false;
 for (char c : token) {
 if (!(isalnum(c) || c == '_')) return false;
 }
 return true;
}

bool isSymbol(const string& token) {
 string symbols = ";{}()[]=+-*/<>,.";
 return token.size() == 1 && symbols.find(token[0]) != string::npos;
}

int main() {
 ifstream file("compile.txt");
 if (!file) {
 cout << "Error: File not found!" << endl;
 return 1;
 }

 string line;

 cout << "=== File Content ===\n";
 while (getline(file, line)) {
 cout << line << endl;
 }

 file.clear();
 file.seekg(0, ios::beg);

 cout << "\n=== Tokens & Classification ===\n";
 while (getline(file, line)) {
 stringstream ss(line);
 string token;
 while (ss >> token) {
 if (isKeyword(token)) {
 cout << token << " --> Keyword\n";
 } else if (isNumber(token)) {
 cout << token << " --> Number\n";
 } else if (isIdentifier(token)) {
 cout << token << " --> Identifier\n";
 } else if (isSymbol(token)) {
 cout << token << " --> Symbol\n";
 } else {
 cout << token << " --> Unknown\n";
 }
 }
 }

 file.close();
 return 0;
}
