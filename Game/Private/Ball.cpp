


#include "Game/Private/GameObject.h"
#include "Engine/Public/EngineInterface.h"
#include "Ball.h"


Ball::Ball(exVector2 Center, exColor color, float speed, Paddle* p1, Paddle* p2, exEngineInterface* engine)
{
	this->mBallCenter = Center;
	this->mBallColor = color;
	this->engine = engine;
	mSpeedX = speed;
	mSpeedY = speed * -1;

	paddle1 = p1;
	paddle2 = p2;

	p1Score = 0;
	p2Score = 0;
}

void Ball::Render()
{
	engine->DrawCircle(mBallCenter, radius, mBallColor, 1);
}

void Ball::Update(float fDeltaT)
{
	//Check if wall hit
	if (mBallCenter.y < radius)
	{
		mSpeedY *= -1;
		
	}
	else if (mBallCenter.y > kViewportHeight)
	{
		mSpeedY *= -1;
		
	}
	//Score right
	if (mBallCenter.x < radius)
	{
		mSpeedX *= -1;
		p2Score++;
		this->Reset();
	}
	//Score left
	else if (mBallCenter.x > kViewportWidth)
	{
		mSpeedX *= -1;
		p1Score++;
		this->Reset();
	}

	if (mBallCenter.x < paddle1->getmPaddleRightVecX())
	{
		if (mBallCenter.y > paddle1->getmPaddleLeftVecY() && mBallCenter.y < paddle1->getmPaddleRightVecY())
		{
			mSpeedX += .5;
			mSpeedX *= -1;
		}
	}

	if (mBallCenter.x > paddle2->getmPaddleRightVecX())
	{
		if (mBallCenter.y > paddle2->getmPaddleLeftVecY() && mBallCenter.y < paddle2->getmPaddleRightVecY())
		{
			mSpeedX += .5;
			mSpeedX *= -1;
		}
	}


	//Calc the speed
	mBallCenter.x +=  mSpeedX * fDeltaT;
	mBallCenter.y += mSpeedY * fDeltaT;
	
}

void Ball::Reset()
{
	mBallCenter.x = kViewportWidth / 2;
	mBallCenter.y = kViewportHeight / 2;
}