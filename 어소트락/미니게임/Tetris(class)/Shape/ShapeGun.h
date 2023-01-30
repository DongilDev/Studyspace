#pragma once

#include "Shape.h"

class CShapeGun :
    public CShape
{
public:
    CShapeGun();
    virtual ~CShapeGun();

public:
    virtual bool Init();
    virtual void Rotation();
};

