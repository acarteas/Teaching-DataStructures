#include "Actor.h"

void Actor::addMovie(Movie* movie)
{
    _movies[movie->getId()] = movie;
}

vector<Movie*> Actor::getMovies()
{
    vector<Movie*> result{};
    for (auto movie : _movies)
    {
        result.push_back(movie.second);
    }
    return result;
}

void Actor::setName(string name)
{
    _name = name;
}

string Actor::getName() const
{
    return _name;
}

void Actor::setId(string id)
{
    _id = id;
}
string Actor::getId() const
{
    return _id;
}