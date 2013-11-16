# include <iostream>
# include <string>
# include <algorithm>
# include <cctype>

bool compare(char a, char b){
    bool aLower = std::islower(a), bLower = std::islower(b);

    // both are lowercase
    if(aLower && bLower) return a < b;
    // both are uppercase
    if(!aLower && !bLower) return a < b;
    // case a lowercase & b uppercase
    if(aLower){
        std::toupper(a);
        return a < b;
    }
    // case a uppercase & b lowercase
    else{
        std::toupper(b);
        return a <= b;
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    int counter; std::cin >> counter;
    std::string str;
    while(counter--){
        std::cin >> str;
        std::sort(str.begin(), str.end(), compare);
        do{
            std::cout << str << "\n";
        }while(std::next_permutation(str.begin(), str.end(), compare));
    }
}
