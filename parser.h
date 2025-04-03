#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

struct Record {
    std::string id;
    std::string name;
    float value;
};

class Parser {
public:
    bool loadFromFile(const std::string& filename);
    std::vector<Record> filterByValue(float minValue) const;
    void printAll() const;

private:
    std::vector<Record> records;
};

#endif
