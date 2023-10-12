// Copyright [2022] <Shafaat Osmani>
#include <iostream>
#include <string>
#include "RandWriter.hpp"


int main(int argc, const char *argv[]) {
    int ord = std::stoi(argv[1]);
    int len = std::stoi(argv[2]);
    std::string text;
    char c;
    do {
        c = getchar();
        text += c;
    } while (c != EOF);
    std::cout << std::endl;
    RandWriter k1(text, ord);
    std::cout << k1 << std::endl;
    std::string output = k1.generate(text.substr(0, ord), len);
    std::cout << "New Text: " << std::endl;
    std::cout << output << std::endl;

    return 0;
}
