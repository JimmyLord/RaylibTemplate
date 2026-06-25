#pragma once

#include "raylib.h"
#include "Helpers/Vector.h"

class BallGame;

class GameObject
{
public:
    GameObject(BallGame* game);
    virtual ~GameObject();

    virtual void reset();
    virtual void update(float deltaTime);
    virtual void draw();

    // Getters.
    bool isActive()       { return Active; }
    vec2 getPosition()    { return Position; }
    float getAngle()      { return Angle; }
    vec2 getScale()       { return Scale; }
    float getRadius()     { return Radius; }
    Color getColor()      { return ObjectColor; }

    // Setters.
    virtual void setActive(bool active) { Active = active; }
    void setPosition(vec2 pos)    { Position = pos; }
    void setAngle(float angle)    { Angle = angle; }
    void setScale(vec2 scale)     { Scale = scale; }
    void setRadius(float radius)  { Radius = radius; }
    void setColor(Color color)    { ObjectColor = color; }

protected:
    BallGame* Game = nullptr;

    bool Active = false;

    vec2 Position = 0;
    float Angle = 0;
    vec2 Scale = 1;
    float Radius = 0;
    Color ObjectColor = WHITE;
};
