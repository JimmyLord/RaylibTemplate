#pragma once

#include "raylib.h"

#include "GameObject.h"
#include "Helpers/InputTypes.h"

class Sprite2D;

class BallObject : public GameObject
{
private:
public:
    BallObject(BallGame* game);
    virtual ~BallObject();

    virtual void update(float deltaTime) override;
    virtual void draw() override;

    // Input event methods.
    void onKey(int keyCode, KeyState keyState);

private:
    Sprite2D* Sprite;
    vec2 Controls = 0;
    vec2 Velocity = 0;
};
