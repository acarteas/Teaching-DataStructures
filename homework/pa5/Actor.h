#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include "Movie.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Movie;
class Actor
{
private:
    unordered_map<string, Movie*> _movies;
    string _name;
    string _id;

public:

    void addMovie(Movie* movie);
    vector<Movie*> getMovies();
    void setName(string name);
    string getName() const;
    void setId(string id);
    string getId() const;
};

#endif