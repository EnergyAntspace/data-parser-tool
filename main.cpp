#include "parser.h"
#include <iostream>

int main() {
    Parser parser;
    std::string filename;
    float minValue;

    std::cout << "Enter file name: ";
    std::cin >> filename;

    if (!parser.loadFromFile(filename)) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::cout << "Enter minimum value to filter: ";
    std::cin >> minValue;

    auto filtered = parser.filterByValue(minValue);
    std::cout << "Filtered records:" << std::endl;
    for (const auto& rec : filtered) {
        std::cout << rec.id << " " << rec.name << " " << rec.value << std::endl;
    }

    return 0;
}
