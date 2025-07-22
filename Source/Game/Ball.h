#pragma once

#include "raylib.h"

#include "GameObject.h"
#include "Helpers/InputTypes.h"

class Sprite;

class Ball : public GameObject
{
private:
public:
    Ball(Game* pGame);
    virtual ~Ball();

    virtual void update(float deltaTime) override;
    virtual void draw() override;

    // Input event methods.
    void onKey(int keyCode, KeyState keyState);

private:
    Sprite* m_pSprite;
    vec2 m_controls = 0;
    vec2 m_velocity = 0;
};
