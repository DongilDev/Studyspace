#pragma once

#include "Shape.h"

class CShapeS :
    public CShape
{
public:
    CShapeS();
    virtual ~CShapeS();

public:
    virtual bool Init();
    virtual void Rotation();
};

