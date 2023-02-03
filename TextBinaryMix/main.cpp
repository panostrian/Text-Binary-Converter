#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> binaryToDecimal(std::string binary) {
    std::vector<int> decimal;
    int len = binary.length();
    int i = 0;
    while (i < len) {
        std::string block = "";
        int start = i;
        while (i < len && binary[i] != ' ') {
            block += binary[i];
            i++;
        }
        i++;
        if (block.length() != 8) {
            std::cout << "Error: Invalid binary string." << std::endl;
            return {};
        }
        int decimal_value = 0;
        int p = 0;
        for (int j = block.length() - 1; j >= 0; j--) {
            if (block[j] == '1') {
                decimal_value += pow(2, p);
            }
            p++;
        }
        decimal.push_back(decimal_value);
    }
    return decimal;
}

std::string decimalToText(std::vector<int> decimal) {
    std::string text;
    for (int i = 0; i < decimal.size(); i++) {
        text += char(decimal[i]);
    }
    return text;
}

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "|           Binary/Text Conversion Tool          |" << std::endl;
    std::cout << "==================================================" << std::endl;
    while (true) {
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Enter 1 for ->Binary to Text<- Translation" << std::endl;
        std::cout << "Enter 2 for ->Text to Binary<- Translation" << std::endl;
        std::cout << "Enter 3 to Exit and close the terminal" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        int option;
        std::cin >> option;

        if (option == 1) {
            std::string binary;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Enter binary to be translated: " << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, binary);

            std::vector<int> decimal = binaryToDecimal(binary);
            if (decimal.empty()) {
                continue;
            }
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "This binary converts to: " << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::string text = decimalToText(decimal);
            std::cout << text << std::endl;
        }
        else if (option == 2) {
            std::string text;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Enter text to be translated: " << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, text);

            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "This Text converts to: " << std::endl;
            std::cout << "------------------------------" << std::endl;
            for (char c : text) {
                std::bitset<8> bits(c);
                std::cout << bits << ' ';
            }
            std::cout << std::endl;
        }
        else if (option == 3) {
            break;
        }
        else {
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Error: Invalid option." << std::endl;
            std::cout << "------------------------------" << std::endl;
        }
    }

    return 0;
}