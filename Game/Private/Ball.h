#pragma once



#include "Game/Private/GameObject.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Paddle.h"

class Ball : public GameObject
{
public:
    Ball(exVector2 Center, exColor color, float speed, Paddle* p1, Paddle* p2, exEngineInterface* engine);
    virtual void Render() override;
    virtual void Update(float fDeltaT) override;
	void Reset();
	exVector2 getCenter() { return this->mBallCenter; }
	int getP1Score() { return this->p1Score; }
	int getP2Score() { return this->p2Score; }
private:

	exVector2 mBallCenter;
	float radius = 10;
	exEngineInterface* engine;
	exColor mBallColor;

	Paddle* paddle1;
	Paddle* paddle2;


	float mSpeedX;
	float mSpeedY;

	int p1Score;
	int p2Score;
};