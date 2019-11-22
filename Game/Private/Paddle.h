
#pragma once


#include "Game/Private/GameObject.h"
#include "Engine/Public/SDL.h"


class Paddle : public GameObject
{
public:

	virtual void Render() override;
	virtual void Update(float fDeltaT) override;
	Paddle(exVector2 left, exVector2 right, exColor color, int playerNum, exEngineInterface* engine);
	
	float getmPaddleLeftVecY() { return this->mPaddleLeft.y; }
	float getmPaddleRightVecY() { return this->mPaddleRight.y; }

	float getmPaddleLeftVecX() { return this->mPaddleLeft.x; }
	float getmPaddleRightVecX() { return this->mPaddleRight.x; }

	void setp1Up(bool p1Up) { this->mUp = p1Up; }
	void setp1Down(bool p1Down) { this->mDown = p1Down; }
	void setp2Up(bool p2Up) { this->mP2Up = p2Up; }
	void setp2Down(bool p2Down) { this->mP2Down = p2Down; }

private:
	exEngineInterface * mEngine;

	const float paddleSpeed = 250.0f;

	exVector2 mPaddleLeft;
	exVector2 mPaddleRight;

	exColor mColor;
	
	int mPlayerId;


	bool mUp;
	bool mDown;
	bool mP2Up;
	bool mP2Down;

};