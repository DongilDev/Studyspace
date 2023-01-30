#pragma once

#include "Shape.h"

class CShapeZ :
    public CShape
{
public:
    CShapeZ();
    virtual ~CShapeZ();

public:
    virtual bool Init();
    virtual void Rotation();
};

