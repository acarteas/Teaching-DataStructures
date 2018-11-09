#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include "Actor.h"
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
class Actor;
class Movie
{
private:
    unordered_map<string, Actor*> _actors;
    string _id;

public:
    void addActor(Actor* actor);
    vector<Actor*> getActors();
    void setId(string id);
    string getId() const;
};

#endif