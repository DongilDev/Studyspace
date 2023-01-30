#pragma once

#include "Shape.h"

class CShapeRGun :
    public CShape
{
public:
    CShapeRGun();
    virtual ~CShapeRGun();

public:
    virtual bool Init();
    virtual void Rotation();
};

