#pragma once

#include "Shape.h"

class CShapeT :
    public CShape
{
public:
    CShapeT();
    virtual ~CShapeT();

public:
    virtual bool Init();
    virtual void Rotation();
};

