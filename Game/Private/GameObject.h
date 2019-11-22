
#pragma once


#include "Engine/Public/EngineTypes.h"

class GameObject
{
public:
	GameObject();
	virtual void Render();
	virtual void Update(float fDeltaT);

private:

};