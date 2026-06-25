#include "raylib.h"
#include <random>
#include <float.h>

#include "Game.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"
#include "BallObject.h"

BallGame::BallGame()
{
    std::random_device rd;
    srand( rd() );

    Textures["SoccerBall"] = LoadTexture( "Data/Textures/SoccerBall.png" );

    // Create a ball.
    Ball = new BallObject(this);

    reset();
}

BallGame::~BallGame()
{
    delete Ball;

    for( auto texturePair : Textures )
    {
        UnloadTexture( texturePair.second );
    }
}

void BallGame::reset()
{
    Ball->reset();
    Ball->setActive( true );
    Ball->setPosition( { GetScreenWidth()/2.0f + rand() % 100 - 50, GetScreenHeight()/2.0f + rand() % 20 - 10 } );
}

void BallGame::update(float deltaTime)
{
    Ball->update( deltaTime );
}

void BallGame::draw()
{
    ClearBackground( DARKBLUE );

    //char buffer[64];
    //snprintf( buffer, sizeof(buffer), "Ball Pos: %0.0f, %0.0f", m_pBall->getPosition().x, m_pBall->getPosition().y );
    //DrawText( buffer, 600, 5, 20, LIGHTGRAY );

    if( Ball->isActive() )
    {
        Ball->draw();
    }
}

void BallGame::onKey(int keyCode, KeyState keyState)
{
    if( keyCode == 'R' && keyState == KeyState::Pressed )
    {
        reset();
    }

    // Send key events to the ball.
    if( Ball->isActive() )
    {
        Ball->onKey( keyCode, keyState );
    }
}

Texture2D BallGame::getTexture(const char* textureName) const
{
    auto it = Textures.find( textureName );
    if( it != Textures.end() )
    {
        return it->second;
    }

    // Return an empty texture if not found.
    assert( false );
    return Texture2D();
}
