#include "item.h"

Item::Item()
{
    isSorted = false; isScored = false;
    type = "null"; color = "null";
    length = 0; width = 0; height = 0;
}

Item::Item(const std::string& type, const std::string& color)
{
    isSorted = false; isScored = false;
    this->type = type;
    this->color = color;

    if(type=="duck"){
        length = 3.5;
        width = 3;
        height = 3;
    }else if(type=="pedestal"){
        length = 0.75;
        width = 0.75;
        height = 2.5;
    }else if(type=="chip"){
        length = 0.5;
        width = 0.5;
        height = 0.05;
    }
}

std::string Item::getColor(){
    return color;
}

std::string Item::getType(){
    return type;
}

void Item::getSize(float size[3]){
        size[0] = length;
        size[1] = width;
        size[2] = height;
}

bool Item::getIsSorted(){
    return isSorted;
}

bool Item::getScored(){
    return isScored;
}
