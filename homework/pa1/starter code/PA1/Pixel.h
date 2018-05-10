#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <sstream>
using namespace std;

class Pixel
{
private:
    int _red;
    int _green;
    int _blue;

public:
    Pixel(int r = 0, int g = 0, int b = 0)
    {
        _red = r;
        _green = g;
        _blue = b;
    }

    int getRed()
    {
        return _red;
    }

    void setRed(int r)
    {
        _red = r;
    }

    int getGreen()
    {
        return _green;
    }

    void setGreen(int g)
    {
        _green = g;
    }

    int getBlue()
    {
        return _blue;
    }

    void setBlue(int b)
    {
        _blue = b;
    }

    string toString()
    {
        ostringstream output{};
        output << _red << " " << _green << " "
            << _blue;
        return output.str();
    }
};
#endif // !PIXEL_H

