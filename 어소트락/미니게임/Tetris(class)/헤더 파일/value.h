#pragma once

#include <iostream>
#include <time.h>
#include <windows.h>
#include <list>

using namespace std;

#include "Macro.h"
#include "Flags.h"

#define STAGE_WIDTH 10
#define STAGE_HEIGHT 15

typedef struct _tagPosition
{
	int x;
	int y;

	_tagPosition() :
		x(0),
		y(0)
	{
	}

	_tagPosition(const _tagPosition& pos)
	{
		*this = pos;
	}

	_tagPosition(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}

	_tagPosition operator +(const _tagPosition& pos)
	{
		_tagPosition p;
		p.x = x + pos.x;
		p.y = y + pos.y;
		return p;
	}

	_tagPosition operator +(int i)
	{
		_tagPosition p;
		p.x = x + i;
		p.y = y + i;
		return p;
	}

	void operator +=(const _tagPosition& pos)
	{
		x += pos.x;
		y += pos.y;
	}

	void operator +=(int i)
	{
		x += i;
		y += i;
	}

	_tagPosition operator -(const _tagPosition& pos)
	{
		_tagPosition p;
		p.x = x - pos.x;
		p.y = y - pos.y;
		return p;
	}

	_tagPosition operator -(int i)
	{
		_tagPosition p;
		p.x = x - i;
		p.y = y - i;
		return p;
	}

	void operator -=(const _tagPosition& pos)
	{
		x -= pos.x;
		y -= pos.y;
	}

	void operator -=(int i)
	{
		x -= i;
		y -= i;
	}

	void operator =(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}

}POSITION, *PPOSITION;