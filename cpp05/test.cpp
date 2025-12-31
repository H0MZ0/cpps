#include <iostream>
#include <cctype>
#include <fstream>

int main(int ac, char **av){
    {
        for (int j = 1; j < ac; j++){
            std::string hamza = av[j];
            for (int i = 0; hamza[i]; i++){
                if (hamza[i] == '.')
                    break;
                std::cout << (char)toupper(hamza[i]);
            }
            std::cout << "\n";
        }
    }
    
    {
        std::ofstream outfile("_shrubbery");
        if (!outfile)
            std::cerr << "Problem to create shrubbery" << std::endl;
        outfile << "         ox\n";
        outfile << "        oo oxoo\n";
        outfile << "      xoo   ooxoo\n";
        outfile << "    oxoxoo   ooxoo\n";
        outfile << "  ooxoxo oo  oxoxooo\n";
        outfile << " oooo xxoxoo ooo ooox\n";
        outfile << " oxo o oxoxo  xoxxoxo\n";
        outfile << "  oxo xooxoooo o ooo\n";
        outfile << "    ooo\\oo\\  /o/o\n";
        outfile << "        \\  \\/ /\n";
        outfile << "         |   /\n";
        outfile << "         |  |\n";
        outfile << "         | D|\n";
        outfile << "         |  |\n";
        outfile << "         |  |\n";
        outfile << "  ______/____\\____\n";
    }
}