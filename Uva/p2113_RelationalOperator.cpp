# include <iostream>

int main(){
    // increase c++ io performance
    std::ios::sync_with_stdio(false);

    int a,b,counter,diff;
    
    while(std::cin >> counter){
        // receive input from user.
        for(int i = 0; i < counter; i++){
            std::cin >> a >> b;
            diff = a - b;
            
            // case a < b
            if(diff < 0){
                std::cout << "<" << '\n';
            }
            // case a > b
            else if(diff > 0){
                std::cout << ">" << '\n';
            }
            // case a = b
            else{
                std::cout << "=" << '\n';
            }
        }
    }
}
