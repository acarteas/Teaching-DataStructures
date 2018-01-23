#pragma once
#ifndef  IMAGE_EFFECT_H
#define IMAGE_EFFECT_H
#include "PpmDocument.h"
class ImageEffect
{
public:
    virtual void processImage(PpmDocument &doc) = 0;
    virtual ~ImageEffect() {}
};

#endif // ! IMAGE_EFFECT_H

