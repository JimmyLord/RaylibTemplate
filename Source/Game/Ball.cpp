#include "Game.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite.h"
#include "Ball.h"

Ball::Ball(Game* pGame)
    : GameObject( pGame )
{
    m_active = true;

    m_radius = 20.0f;
    m_scale = 1.0f;

    m_velocity = { randFloat(-200, 200), randFloat(-200, 200) };

    m_pSprite = new Sprite( pGame->getTexture("SoccerBall") );
}

Ball::~Ball()
{
    delete m_pSprite;
}

void Ball::update(float deltaTime)
{
    float speed = 200.0f;
    vec2 gravity = { 0.0f, 200.0f };

    vec2 dir = m_controls.getNormalized();
    vec2 forces = gravity + dir * speed;

    m_velocity += forces * deltaTime;

    m_position.x += m_velocity.x * deltaTime;
    m_position.y += m_velocity.y * deltaTime;

    // Lock to edges.
    if( m_position.x < 32.0f )
    {
        m_position.x = 32.0f;
        m_velocity.x *= -0.95f; // Bounce off the left edge.
    }
    if( m_position.x >= GetScreenWidth()-32.0f )
    {
        m_position.x = GetScreenWidth()-32.0f;
        m_velocity.x *= -0.95f; // Bounce off the right edge.
    }
    if( m_position.y < 32.0f )
    {
        m_position.y = 32.0f;
        m_velocity.x *= 0.95f; // Slow down horizontal velocity.
        m_velocity.y *= -0.95f; // Bounce off the top.
    }
    if( m_position.y >= GetScreenHeight()-32.0f )
    {
        m_position.y = GetScreenHeight()-32.0f;
        m_velocity.x *= 0.95f; // Slow down horizontal velocity.
        m_velocity.y *= -0.95f; // Bounce off the bottom.
    }
}

void Ball::draw()
{
    m_pSprite->draw( m_position, 0.0f, m_scale );
}

void Ball::onKey(int keyCode, KeyState keyState)
{
    if( IsWindowFocused() == false )
        m_controls = 0;

    if( keyState == KeyState::Pressed )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            m_controls.y -= 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            m_controls.y += 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            m_controls.x -= 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            m_controls.x += 1;
    }

    if( keyState == KeyState::Released )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            m_controls.y += 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            m_controls.y -= 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            m_controls.x += 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            m_controls.x -= 1;
    }
}
