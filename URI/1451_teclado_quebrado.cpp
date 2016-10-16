#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        list<char> textInput;
        // we're going to do a 'smart' trick and use iterator to simulate the
        // behaviour of the 'Home' and 'End' keys.
        list<char>::iterator iter( textInput.begin() );
        for (auto i = 0; i < line.size(); ++i) {
            // Case when we press the 'Home' key
            if (line[i] == '[') {
                iter = textInput.begin();
            }
            // case when we press the 'End' key
            else if (line[i] == ']') {
                iter = textInput.end();
            }
            // for the rest of the possible chars we simply add them to the output.
            else {
                textInput.insert(iter, line[i]);
            } 
        }

        // we can't use cout to print a list, so we use the ostream_iterator.
        ostream_iterator<char> out_it (cout, ""); // iterator for cout
        copy(textInput.begin(), textInput.end(), out_it); // copy list to out_it
        cout << "\n"; // Add newline after text.
    }

    return 0;
}
