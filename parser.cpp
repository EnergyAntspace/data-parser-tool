#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Parser::loadFromFile(const std::string& filename) {
    records.clear();
    std::ifstream in(filename);
    if (!in) return false;

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string id, name;
        float value;
        if (iss >> id >> name >> value) {
            records.push_back({id, name, value});
        }
    }
    return true;
}

std::vector<Record> Parser::filterByValue(float minValue) const {
    std::vector<Record> filtered;
    for (const auto& rec : records) {
        if (rec.value >= minValue)
            filtered.push_back(rec);
    }
    return filtered;
}

void Parser::printAll() const {
    for (const auto& rec : records) {
        std::cout << rec.id << " " << rec.name << " " << rec.value << std::endl;
    }
}
