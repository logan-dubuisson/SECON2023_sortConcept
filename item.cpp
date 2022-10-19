#include "item.h"

Item::Item()
{
    isSorted = false; isScored = false;
    type = "null"; color = "null";
    length = 0; width = 0; height = 0;
    pos[0] = 0; pos[1] = 0;
}

Item::Item(const std::string& type, const std::string& color)
{
    isScored = false;
    this->type = type;
    this->color = color;
    pos[0] = 0; pos[1] = 0;

    if(type=="duck"){
        length = 3.5;
        width = 3.0;
        height = 3.0;
        isSorted = false;
    }else if(type=="pedestal"){
        length = 1.5;
        width = 1.5;
        height = 3.0;
        isSorted = false;
    }else if(type=="chip"){
        length = 1.5;
        width = 1.5;
        height = 0.24;
        isSorted = true;
    }
}

std::string Item::getColor(){
    return color;
}

std::string Item::getType(){
    return type;
}

void Item::getPos(float pos[2]){
    pos[0] = this->pos[0];
    pos[1] = this->pos[0];
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

void Item::setPos(const float pos[2]){
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
}

void Item::sort(const bool& sorted){
    isSorted = sorted;
}

void Item::score(const bool& scored){
    isScored = scored;
}
