#include "ContactListener.h"
#include "GameObject.h"

void ContactListener::BeginContact(b2Contact* contact)
{
	GameObject *a, *b;
	a = (GameObject*) contact->GetFixtureA()->GetBody()->GetUserData();
	b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();

	if(a && b)
	{
		a->ContactBegin(contact, b);
		b->ContactBegin(contact, a);
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
	GameObject *a, *b;
	a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
	b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();

	if (a && b)
	{
		a->ContactEnd(contact, b);
		b->ContactEnd(contact, a);
	}
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	GameObject *a, *b;
	a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
	b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();

	if (a && b)
	{
		a->PreSolve(contact, oldManifold, b);
		b->PreSolve(contact, oldManifold, a);
	}
}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	GameObject *a, *b;
	a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
	b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();

	if (a && b)
	{
		a->PostSolve(contact, impulse, b);
		b->PostSolve(contact, impulse, a);
	}
}
