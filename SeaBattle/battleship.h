#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "ship.h"

class Battleship:public Ship
{
private:
    int width;
    int height;
public:
    Battleship(int w,int h):width(w),height(h){};
    int getSize() override;
};

#endif // BATTLESHIP_H
