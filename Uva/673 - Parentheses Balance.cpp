# include <iostream>
# include <cstdio>
# include <stack>
# include <string>

using namespace std;


int main() {
//  freopen ("in.txt", "r", stdin);
//  freopen ("out.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        stack<char> s;
        string word;
        getline(cin, word);

        // validity of word logic
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ' ');  // ignore empty spaces
            else if (word[i] == '(' || word[i] == '[') {
                s.push(word[i]);
            } else if (word[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    s.push('$');  // when word == ')'
                    break;
                } else {
                    s.pop();
                }
            } else if (word[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    s.push('$');  // when word == ']'
                    break;
                } else {
                    s.pop();
                }
            }
        }

        // print logic
        if (s.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
