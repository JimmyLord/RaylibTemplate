#include "GameObject.h"

GameObject::GameObject(Game* pGame)
    : m_pGame( pGame )
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
