#pragma once
#include "stdafx.h"
class Screen
{
public:
	Screen();
	~Screen();

	void Initialize();
	void Prograss();
	void Render(HDC hdc);
	void handleArgs(vector<int> args); // args[0] = mode, args[1] = mapType
};