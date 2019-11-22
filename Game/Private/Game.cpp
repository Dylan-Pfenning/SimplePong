//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"

#include "Game/Private/GameObject.h"
#include <string>
using namespace std;
//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "PressStart2P.ttf", 32 );
	
	mScoreP1.x = (kViewportWidth / 4);
	mScoreP1.y = 25;
	

	mScoreP2.x = (kViewportWidth * .75);
	mScoreP2.y = 25;

	//Player 1 box left side
	mP1BoxP1.x = 30.0f;
	mP1BoxP1.y = (kViewportHeight / 2) - 75.0f;
	mP1BoxP2.x = 50.0f;
	mP1BoxP2.y = (kViewportHeight / 2) + 75.0f;
	exColor c;
	c.mColor[0] = 0; //r
	c.mColor[1] = 255; //g
	c.mColor[2] = 255; //b
	c.mColor[3] = 255; //alpha

	//player 2 box right side
	mP2BoxP1.x = kViewportWidth - 30;
	mP2BoxP1.y = (kViewportHeight/2) -75.0f;
	mP2BoxP2.x = kViewportWidth -50;
	mP2BoxP2.y = (kViewportHeight / 2) + 75.0f;

	mBallCenter.x = kViewportWidth / 2;
	mBallCenter.y = kViewportHeight / 2;

	mPaddle1 = new Paddle(mP1BoxP1,mP1BoxP2,c,1,pEngine);
	mPaddle2 = new Paddle(mP2BoxP1, mP2BoxP2, c, 2, pEngine);
	mBall = new Ball(mBallCenter, c, 250, mPaddle1, mPaddle2, pEngine);
	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mUp = pState[SDL_SCANCODE_W];
	mDown = pState[SDL_SCANCODE_S];
	mP2Up = pState[SDL_SCANCODE_UP];
	mP2Down = pState[SDL_SCANCODE_DOWN];
	mQuit = pState[SDL_SCANCODE_ESCAPE];
	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//Runs every frame
void MyGame::Run( float fDeltaT )
{
	

	exVector2 p1, p2;
	exColor c;
	//COLOUR STYLE
	//0-r 1-g 2-b 3-a 
	c.mColor[0] = 0; //r
	c.mColor[1] = 255; //g
	c.mColor[2] = 255; //b
	c.mColor[3] = 255; //a
	//middle line
	p1.x = (kViewportWidth / 2) - 2;
	p2.x = (kViewportWidth / 2) - 2;
	p1.y = 0.0f;
	p2.y = kViewportHeight;
	mEngine->DrawLine(p1, p2, c, 0);

	mPaddle1->Render();
	mPaddle2->Render();
	mBall->Render();


	//Score

	string score1 = to_string(mBall->getP1Score());
	string score2 = to_string(mBall->getP2Score());

	mEngine->DrawText(mFontID, mScoreP1, score1.c_str(), c, 0);
	mEngine->DrawText(mFontID, mScoreP2, score2.c_str(), c, 0);

	//Paddle controllers
	mPaddle1->setp1Up(mUp);
	mPaddle1->setp1Down(mDown);
	mPaddle2->setp2Up(mP2Up);
	mPaddle2->setp2Down(mP2Down);
	
	mPaddle1->Update(fDeltaT);
	mPaddle2->Update(fDeltaT);


	//Ball shit
	mBall->Update(fDeltaT);

}

