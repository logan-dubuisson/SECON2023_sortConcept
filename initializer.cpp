#include <cmath>
#include <random>
#include <board.h>
#include <item.h>
#include <sensor.h>
#include <bot.h>

// Top-line declarations for simplicity sake
void  place(const int& i, float pos[2], Item items[23], Board board[14]);
void buildBoard(Board board[14]);
void addItems(int const& seedNum, Item items[23]);
Bot buildBot(const float size[3], const Sensor sensors[]);

// Seed number for random item distribution
int seedNum = 0;
// Random number generator for item distribution
std::minstd_rand0 gen;

// Bot dimensions for collision mesh
float size[3] = {8,8,8};
// Sensors on bot
Sensor sensors[1] = {Sensor()};

// Main initialization method - creates board, places items, and generates bot from given parameters (i.e. dimensions, sensors, speed, etc.)
void initialize(Board board[14], Item items[23], Bot& bot){
    buildBoard(board);
    addItems(seedNum, items);
    bot = buildBot(size, sensors);
}



void buildBoard(Board board[14]){
    float t_posA[2], t_posB[2];

    board[0] = Board(); // Creates main board background (with walls space handled)

    t_posA[0] = 1; t_posA[1] = 1; t_posB[0] = 10; t_posB[1] = 13;
    board[1] = Board("alligatorAquarium", t_posA, t_posB, "ff0000");

    t_posA[0] = 1; t_posA[1] = 35; t_posB[0] = 10; t_posB[1] = 47;
    board[2] = Board("manateeAquarium", t_posA, t_posB, "00ff00");

    t_posA[0] = 11.5; t_posA[1] = 3; t_posB[0] = 12.5; t_posB[1] = 11;
    board[3] = Board("whiteCrossBottomVert", t_posA, t_posB, "ffffff");

    t_posA[0] = 10; t_posA[1] = 6.5; t_posB[0] = 14; t_posB[1] = 7.5;
    board[4] = Board("whiteCrossBottomHoriz", t_posA, t_posB, "ffffff");

    t_posA[0] = 11.5; t_posA[1] = 37; t_posB[0] = 12.5; t_posB[1] = 45;
    board[5] = Board("whiteCrossTopVert", t_posA, t_posB, "ffffff");

    t_posA[0] = 10; t_posA[1] = 40.5; t_posB[0] = 14; t_posB[1] = 41.5;
    board[6] = Board("whiteCrossTopHoriz", t_posA, t_posB, "ffffff");

    t_posA[0] = 33; t_posA[1] = 7; t_posB[0] = 2.5; t_posB[1] = 2;
    board[7] = Board(true, "leftCircle", t_posA, t_posB, "ffffff");

    t_posA[0] = 42; t_posA[1] = 1; t_posB[0] = 54; t_posB[1] = 13;
    board[8] = Board("startZone", t_posA, t_posB, "ffffff");

    t_posA[0] = 48; t_posA[1] = 35; t_posB[0] = 7; t_posB[1] = 2.5;
    board[9] = Board(true, "pond", t_posA, t_posB, "000099");

    t_posA[0] = 48; t_posA[1] = 35; t_posB[0] = 2.5; t_posB[1] = 2;
    board[10] = Board(true, "pondInnerCircle", t_posA, t_posB, "ffffff");

    t_posA[0] = 63; t_posA[1] = 7; t_posB[0] = 2.5; t_posB[1] = 2;
    board[11] = Board(true, "rightCircle", t_posA, t_posB, "ffffff");

    t_posA[0] = 72; t_posA[1] = 1; t_posB[0] = 88; t_posB[1] = 10;
    board[12] = Board("recycleLower", t_posA, t_posB, "777777");

    t_posA[0] = 72; t_posA[1] = 38; t_posB[0] = 88; t_posB[1] = 47;
    board[13] = Board("recycleUpper", t_posA, t_posB, "777777");
}

void addItems(int const& seedNum, Item items[23], Board board[14]){
    float t_pos[2] = {0,0};
    gen.seed(seedNum);
    for(int i=0; i<23; i++){
        if(i<=8){ // Creates yellow duck item objects
            items[i] = Item("duck", "ffe629"); // RGB "ffe629" is roughly the yellow duck color
        }else if(i==9){
            items[i] = Item("duck","ff0080"); // RGB "ff0080" approximates pink duck (solid pink version)
        }else if(i>9 && i<=12){
            items[i] = Item("pedestal","ffffff"); // RGB "" approximates
        }else if(i>12 && i<=15){
            items[i] = Item("pedestal","00bb00"); // RGB "" approximates
        }else if(i==16){
            items[i] = Item("pedestal","990000"); // RGB "" approximates
        }else if(i>16 && i<=19){
            items[i] = Item("chip","bb0000"); // RGB "" approximates
        }else if(i>19 && i<=22){
            items[i] = Item("chip","00bb00"); // RGB "" approximates
        }
        place(i, t_pos, items, board);
    }
}

Bot buildBot(const float size[3], const Sensor sensors[]){
    ;
}

void  place(const int& i, float pos[2], Item items[23], Board board[14]){
    bool valid = false;
    // While loops until new item doesn't overlap existing items and is within valid starting space
    while(!valid){
        valid = true;

        pos[0] = (gen()%960)*0.1; // Generates random X position
        pos[1] = (gen()%480)*0.1; // Generates random Y position

        // For cycles through existing, placed items to check for overlap
        for(int j=0; j<i; j++){
            float t_pos[2], size[3], t_size[3];
            items[j].getPos(t_pos);
            items[i].getSize(size);
            items[j].getSize(t_size);
            // If checks for items within 0.1 in of each other (fixes item space overlap)
            if((fabs(pos[0]-t_pos[0]) < (size[0]/2)+(t_size[0]/2)+0.1) /* Checks item X overlap */
                    &&(fabs(pos[1]-t_pos[1]) < (size[0]/2)+(t_size[0]/2)+0.1) /* Checks item Y overlap */)
            {
                valid = false;
                break;
            }
        }

        if(!valid){continue;}

        // For cycles through board regions and prevents items in invalid space (<2" from wall or <14" from entrance, in a zone, etc.)
        for(int j=0; j<15; j++){
            float t_pos[2], size[3], t_size[3];
            items[i].getSize(size);
            if(j<14){
                items[j].getPos(t_pos);
                items[j].getSize(t_size);
                if(board[j].round()){
                    if(hypot(fabs(pos[0]-t_pos[0]),fabs(pos[1]-t_pos[1])) < (size[0]/2)+(t_size[0]/2)+0.1)
                    {
                        valid = false;
                        break;
                    }
                }else{
                    if(fabs(pos[0]-t_pos[0]) < (size[0]/2)+(t_size[0]/2)+0.1 && fabs(pos[0]-t_pos[0]) < (size[0]/2)+(t_size[1]/2)+0.1){
                        valid = false;
                        break;
                    }
                }

            }else{
                if(pos[0] < 3+(size[0]/2)+0.1 || pos[0] > 86-(size[0]/2)-0.1 || pos[1] > 45-(size[0]/2)-0.1 || pos[1] < 15+(size[0]/2)+0.1){
                    valid = false;
                    break;
                }
            }
        }
    }
}
