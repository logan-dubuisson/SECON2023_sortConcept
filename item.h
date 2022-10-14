#include <string>

#ifndef ITEM_H
#define ITEM_H


class Item
{
private:
    float length, width, height;
    std::string color, type;
    bool isSorted, isScored;
public:
    Item(); // Default item - empty values
    Item(const std::string& type, const std::string& color); // Intake typename and color of item

    std::string getColor();
    std::string getType();
    void getSize(float size[3]);
    bool getIsSorted();
    bool getScored();
};

#endif // ITEM_H
