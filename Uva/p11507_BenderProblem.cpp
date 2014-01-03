# include <iostream>
# include <cstdio>
# include <map>

using namespace std;

string actualPos, bendDir;
long l;

int main(){
    
    // create and populate map with bend directions
    map<string, map<string,string> > bend;
    bend["+x"]["+y"] = "+y";
    bend["+x"]["-y"] = "-y";
    bend["+x"]["+z"] = "+z";
    bend["+x"]["-z"] = "-z";
    bend["-x"]["+y"] = "-y";
    bend["-x"]["-y"] = "+y";
    bend["-x"]["+z"] = "-z";
    bend["-x"]["-z"] = "+z";
    bend["+y"]["+y"] = "-x";
    bend["+y"]["-y"] = "+x";
    bend["+y"]["+z"] = "+y";
    bend["+y"]["-z"] = "+y";
    bend["-y"]["+y"] = "+x";
    bend["-y"]["-y"] = "-x";
    bend["-y"]["+z"] = "-y";
    bend["-y"]["-z"] = "-y";
    bend["+z"]["+y"] = "+z";
    bend["+z"]["-y"] = "+z";
    bend["+z"]["+z"] = "-x";
    bend["+z"]["-z"] = "+x";
    bend["-z"]["+y"] = "-z";
    bend["-z"]["-y"] = "-z";
    bend["-z"]["+z"] = "+x";
    bend["-z"]["-z"] = "-x";

    // while l != 0 (false)
    while(scanf("%d", &l), l){
        actualPos = "+x"; // initial pos
        l--; // stard bending at l-1

        // calculate next pos based on actualPos
        // and bendDir
        for(int i = 0; i < l; i++){
            cin >> bendDir;
            if (bendDir != "No"){
                actualPos = bend[actualPos][bendDir];
            }
        }
        // print actualPos (the last pos)
        cout << actualPos << '\n';
    }
}
