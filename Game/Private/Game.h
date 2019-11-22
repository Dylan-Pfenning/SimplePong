//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#pragma once

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game\Private\Paddle.h"
#include "Game\Private\Ball.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

private:

	exEngineInterface*			mEngine;

	int							mFontID;

	bool						mUp;
	bool						mDown;
	bool						mP2Up;
	bool						mP2Down;
	bool						mQuit;

	exVector2					mScoreP1;
	exVector2					mScoreP2;

	exVector2					mP1BoxP1;
	exVector2					mP1BoxP2;

	exVector2					mP2BoxP1;
	exVector2					mP2BoxP2;

	Paddle*						mPaddle1;
	Paddle*						mPaddle2;

	Ball*						mBall;
	exVector2					mBallCenter;

};
