#include "raylib.h"
#include <random>
#include <float.h>

#include "Game.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite.h"
#include "Ball.h"

Game::Game()
{
    std::random_device rd;
    srand( rd() );

    m_textures["SoccerBall"] = LoadTexture( "Data/Textures/SoccerBall.png" );

    // Create a ball.
    m_pBall = new Ball( this );

    reset();
}

Game::~Game()
{
    delete m_pBall;

    for( auto texturePair : m_textures )
    {
        UnloadTexture( texturePair.second );
    }
}

void Game::reset()
{
    m_pBall->reset();
    m_pBall->setActive( true );
    m_pBall->setPosition( { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f } );
}

void Game::update(float deltaTime)
{
    m_pBall->update( deltaTime );
}

void Game::draw()
{
    ClearBackground( DARKBLUE );

    char buffer[64];
    snprintf( buffer, sizeof(buffer), "Ball Pos: %0.0f, %0.0f", m_pBall->getPosition().x, m_pBall->getPosition().y );
    DrawText( buffer, 600, 5, 20, LIGHTGRAY );

    m_pBall->draw();
}

void Game::onKey(int keyCode, KeyState keyState)
{
    if( keyCode == 'R' && keyState == KeyState::Pressed )
    {
        reset();
    }

    // Send key events to the ball.
    m_pBall->onKey( keyCode, keyState );
}

Texture2D Game::getTexture(const char* textureName) const
{
    auto it = m_textures.find( textureName );
    if( it != m_textures.end() )
    {
        return it->second;
    }

    // Return an empty texture if not found.
    assert( false );
    return Texture2D();
}
