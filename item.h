#include <string>

#ifndef ITEM_H
#define ITEM_H


class Item
{
private:
    float length, width, height, pos[2]; // Dimensions of item, XY position array
    std::string color, type; // Color (RGB Hex value) and type (duck, pedestal, chip)
    bool isSorted, isScored; // Memory for sorting and avoidance of scored items
public:
    Item(); // Default item - empty values
    Item(const std::string& type, const std::string& color); // Intake typename and color of item

    std::string getColor();
    std::string getType();
    void getPos(float pos[2]);
    void getSize(float size[3]);
    bool getIsSorted();
    bool getScored();

    void setPos(const float pos[2]);
    void sort(const bool& sorted);
    void score(const bool& scored);
};

#endif // ITEM_H
