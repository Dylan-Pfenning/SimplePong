/*
	Paddle class. Start with paddle move to 2 paddles
*/

#include "Game/Private/GameObject.h"
#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Paddle.h"



Paddle::Paddle(exVector2 left, exVector2 right, exColor color, int PlayerNum, exEngineInterface* engine)
{
		this->mPaddleLeft = left;
		this->mPaddleRight = right;
		this->mColor = color;
		mPlayerId = PlayerNum;
		mEngine = engine;
}

void Paddle::Render()
{
	mEngine->DrawBox(mPaddleLeft, mPaddleRight, mColor, 1);
}




void Paddle::Update(float fDeltaT)
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState(&nKeys);
	//Change square position with keys
	//if key up use paddle speed -
	//if key down uyse paddle speed +

	if (mUp && getmPaddleLeftVecY() > 5 || mP2Up && getmPaddleLeftVecY() > 5)
	{
		mPaddleLeft.y -= paddleSpeed * fDeltaT;
		mPaddleRight.y -= paddleSpeed * fDeltaT;
	}
	else if (mDown && getmPaddleRightVecY() < (kViewportHeight - 5) || mP2Down && getmPaddleRightVecY() < (kViewportHeight - 5))
	{
		mPaddleLeft.y += paddleSpeed * fDeltaT;
		mPaddleRight.y += paddleSpeed * fDeltaT;
	}
}



