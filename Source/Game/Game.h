#pragma once

#include <assert.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "raylib.h"
#include "Helpers/InputTypes.h"
#include "Helpers/Vector.h"

class Ball;

class Game
{
public:
    Game();
    virtual ~Game();

    void reset();
    void update(float deltaTime);
    void draw();

    // Input event methods.
    void onKey(int keyCode, KeyState keyState);

    // Getters.
    Ball* getBall() { return m_pBall; }

    Texture2D getTexture(const char* textureName) const;

private:
    std::unordered_map<std::string, Texture2D> m_textures;

    Ball* m_pBall = nullptr;
};
