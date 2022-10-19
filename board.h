#include <string>
#include <cmath>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    float pos[2], dim[2]; // Values for position on coordinate grid and dimensions of board object
    std::string name, color;
    bool isRound;

    // Private getter called methods
    float getArea(const bool& isRound);
    float getPerim(const bool& isRound);

    // Derived setters
    void findCenter(float pos[2], const float posA[2], const float posB[2]); // finds center for position reference, stores in pos

public:
    // Constructors
    Board(); // default
    Board(const std::string& name, const float posA[2], const float posB[2], const std::string& color); // floating-point dimensions in xy-plane, color in 24-bit RGB
    Board(const bool& isRound, const std::string& name, const float posCenter[2], const float radius[2], const std::string& color); //

    // Getter methods
    std::string getName();
    void getPos(float output[2]); // Outputs center coordinates (x,y) to output array
    float getArea(){return getArea(isRound);} // Outputs total area (compensates for hollow radius)
    float getPerim(){return getPerim(isRound);} // Outputs total perimeter
    float getX(); // Outputs length (x-dir)
    float getY(); // Outputs width (y-dir)
    bool round(){return isRound;};
};

#endif // BOARD_H
