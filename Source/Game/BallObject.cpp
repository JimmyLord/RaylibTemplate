#include "Game.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"
#include "BallObject.h"

BallObject::BallObject(BallGame* game)
    : GameObject( game )
{
    Active = true;

    Radius = 20.0f;
    Scale = 1.0f;

    Velocity = { randFloat(-200, 200), randFloat(-200, 200) };

    Sprite = new Sprite2D( Game->getTexture("SoccerBall") );
}

BallObject::~BallObject()
{
    delete Sprite;
}

void BallObject::update(float deltaTime)
{
    float speed = 200.0f;
    vec2 gravity = { 0.0f, 200.0f };

    vec2 dir = Controls.getNormalized();
    vec2 forces = gravity + dir * speed;

    Velocity += forces * deltaTime;

    Position.X += Velocity.X * deltaTime;
    Position.Y += Velocity.Y * deltaTime;

    Angle += deltaTime * 50;

    // Lock to edges.
    if( Position.X < 32.0f )
    {
        Position.X = 32.0f;
        Velocity.X *= -0.95f; // Bounce off the left edge.
    }
    if( Position.X >= GetScreenWidth()-32.0f )
    {
        Position.X = GetScreenWidth()-32.0f;
        Velocity.X *= -0.95f; // Bounce off the right edge.
    }
    if( Position.Y < 32.0f )
    {
        Position.Y = 32.0f;
        Velocity.X *= 0.95f; // Slow down horizontal velocity.
        Velocity.Y *= -0.95f; // Bounce off the top.
    }
    if( Position.Y >= GetScreenHeight()-32.0f )
    {
        Position.Y = GetScreenHeight()-32.0f;
        Velocity.X *= 0.95f; // Slow down horizontal velocity.
        Velocity.Y *= -0.95f; // Bounce off the bottom.
    }
}

void BallObject::draw()
{
    Sprite->draw( Position, Angle, Scale );
}

void BallObject::onKey(int keyCode, KeyState keyState)
{
    if( IsWindowFocused() == false )
        Controls = 0;

    if( keyState == KeyState::Pressed )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            Controls.Y -= 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            Controls.Y += 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            Controls.X -= 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            Controls.X += 1;
    }

    if( keyState == KeyState::Released )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            Controls.Y += 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            Controls.Y -= 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            Controls.X += 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            Controls.X -= 1;
    }
}
