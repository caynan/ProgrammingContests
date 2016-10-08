#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isExpressionValid(string expression) {
    stack<char> mStack;

    for (char& c : expression) {
        // if it's oppening parenthesis, simply put it into stack.
        if ( c == '(' ) {
            mStack.emplace(c);
        }
        // If it's closing parenthesis, we can do two things:
        else if ( c == ')') {
            // Check if top element is oppening parenthesis
            // (we use the short circuit property of and here to check if the stack is empty first)
            if (!mStack.empty() && mStack.top() == '(' ) {
                mStack.pop();
            }
            // if not, we insert it into stack and break, cause we have an invalid expression
            else {
                mStack.emplace(c);
                break;
            }
        }
    }

    // if our stack is empty it means that every parenthesis had a match (valid expression)
    return mStack.empty();
}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string expression;
    // Receive expression
    while(cin >> expression) {
        auto ans = isExpressionValid(expression) ? "correct" : "incorrect";
        cout << ans << "\n";
    }

    return 0;
}
