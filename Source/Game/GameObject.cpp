#include "GameObject.h"

GameObject::GameObject(BallGame* game)
    : Game( game )
{
}

GameObject::~GameObject()
{
}

void GameObject::reset()
{
    setActive( false );
}

void GameObject::update(float deltaTime)
{
}

void GameObject::draw()
{
}
