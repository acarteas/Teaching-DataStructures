#include "Movie.h"
void Movie::addActor(Actor* actor)
{
    _actors[actor->getId()] = actor;
}

vector<Actor*> Movie::getActors()
{
    vector<Actor*> result{};
    for (auto item : _actors)
    {
        result.push_back(item.second);
    }
    return result;
}

void Movie::setId(string id)
{
    _id = id;
}

string Movie::getId() const
{
    return _id;
}