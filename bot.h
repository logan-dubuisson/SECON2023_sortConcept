#ifndef BOT_H
#define BOT_H


class Bot
{
private:
    float maxSize[3], collisionMesh[3], velocity[2], speed;

public:
    Bot();

    float getSpeed();
    void getVelocityXY(float vel[2]);
    void getVelocityAngular(float velAng[2]);
    bool collision();
    float getAngle();
    void locate();
};

#endif // BOT_H
