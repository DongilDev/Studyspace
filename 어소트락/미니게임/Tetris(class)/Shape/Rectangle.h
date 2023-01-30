#pragma once

#include "Shape.h"

class CRectangle :
    public CShape
{
public:
    CRectangle();
    virtual ~CRectangle();

public:
    virtual bool Init();
};