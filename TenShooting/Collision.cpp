#include "Collision.h"
#include <math.h>

//	�~�Ή~�̔���
bool Collision::CircleCollision(const GameObject* objectA, const GameObject* objectB)
{
	if (objectA == nullptr || objectB == nullptr)
		return false;
	auto x = abs((objectA->Position().x + objectA->Radius()) - (objectB->Position().x + objectB->Radius()));
	auto y = abs((objectA->Position().y + objectA->Radius()) - (objectB->Position().y + objectB->Radius()));

	return (sqrt(x * x + y * y) <= objectA->Radius() + objectB->Radius());
}

//	��`�΋�`�̔���
bool Collision::RectCollision(const GameObject* objectA, const GameObject* objectB)
{
	if (objectA == nullptr || objectB == nullptr)
		return false;
	auto dx = abs((objectA->Position().x + objectA->Size().x / 2) - (objectB->Position().x + objectB->Size().x / 2));
	auto dy = abs((objectA->Position().y + objectA->Size().y / 2) - (objectB->Position().y + objectB->Size().y / 2));

	return (dx < (objectA->Size().x + objectB->Size().x) / 2 && dy < (objectA->Size().y + objectB->Size().y) / 2);
}

bool Collision::CircleCollision2(const Vector2D & circleA, int aradius, const Vector2D & circleB, int bradius)
{
	auto x = abs((circleA.x + aradius) - (circleB.x + bradius));
	auto y = abs((circleA.y + aradius) - (circleB.y + bradius));

	return (sqrt(x*x + y * y) <= aradius + bradius);
}
