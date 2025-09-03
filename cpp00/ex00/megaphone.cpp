#include <iostream>
int main(int ac, char **av){
    if (ac == 1) return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 1;
    int upper;
    for (int i = 1; av[i]; i++){
        for (int j = 0; av[i][j]; j++){
            upper = toupper(av[i][j]);
            std::cout << (char)upper;}}
    std::cout << "\n"; return 0;
}