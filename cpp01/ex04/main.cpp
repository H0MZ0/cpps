#include "Replace.hpp"

int main(int ac, char **av){	
	if (ac != 4) {
        std::cerr << "Invalid arguments\n";
        return 1;
    }

    std::string newNameFile = std::string(av[1]) + ".replace";
    std::ifstream inFile(av[1]);
    if (!inFile) {
        std::cerr << "Error opening input file\n";
        return 1;
    }
    std::ofstream outFile(newNameFile.c_str());
    if (!outFile) {
        std::cerr << "Error opening output file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();

    std::string s1 = av[2];
    std::string s2 = av[3];

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    outFile << content;

    return 0;
}
