#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Math.hpp"

// Variables
static std::vector<Entity*> entities;

static float paddleWidth, paddleHeight;
static float ballWidth, ballHeight;

static Entity ball;
static Entity rightPaddle;
static Entity leftPaddle;

Game::Game()
    : m_pWindow(NULL), m_bGameRunning(false), m_fTimePerFrame(0)
{}

void Game::Init(RenderWindow* p_pWindow)
{
    m_pWindow = p_pWindow;

    // Get the Display refresh rate
    m_fTimePerFrame = 1.0 / m_pWindow->GetRefreshRate();
}

void Game::Run()
{
    m_bGameRunning = true;

    Setup();

    float fTimeSinceLastUpdate = 0;
    float fPreviousTime = utils::HireTimeInSeconds();

    while (m_bGameRunning)
    {
        float fCurrentTime = utils::HireTimeInSeconds();
        float fFrameTime = fCurrentTime - fPreviousTime;

        fTimeSinceLastUpdate += fFrameTime;
        fPreviousTime = fCurrentTime;

        while (fTimeSinceLastUpdate > m_fTimePerFrame)
        {
            HandleEvents();
            Update(m_fTimePerFrame);

            fTimeSinceLastUpdate -= m_fTimePerFrame;
        }

        Render();
    }
}

void Game::CleanUp()
{
    m_pWindow->CleanUp();
    TTF_Quit();
    SDL_Quit();
}

void Game::Setup()
{
    // Intialize things
    ballWidth = 20;
    ballHeight = 20;
    paddleWidth = 20;
    paddleHeight = 100;

    leftPaddle = Entity(50, (g_ScreenHeight/2) - paddleHeight/2, paddleWidth,
            paddleHeight, 0.0f, 0.0f);
    rightPaddle = Entity((g_ScreenWidth - paddleWidth) - 50, (g_ScreenHeight/2) -
            paddleHeight/2, paddleWidth, paddleHeight, 0.0f, 0.0f);

    ball = Entity((g_ScreenWidth/2) - ballWidth/2, (g_ScreenHeight/2) -
            ballHeight/2, ballWidth, ballHeight, 0.0f, 0.0f);

    ball.SetVx(300);
    ball.SetVy(300);

    // add entities to entity group
    entities.push_back(&ball);
    entities.push_back(&leftPaddle);
    entities.push_back(&rightPaddle);
}

void Game::HandleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bGameRunning = false;
                break;

            case SDL_KEYDOWN:
                ProcessInput(event.key.keysym.sym, true);
                break;

            case SDL_KEYUP:
                ProcessInput(event.key.keysym.sym, false);
                break;
        }
    }
}

void Game::ProcessInput(SDL_Keycode p_KeyCode, bool p_bIsPressed)
{
    if (p_bIsPressed)
    {
        switch (p_KeyCode)
        {
            case SDLK_ESCAPE:
                m_bGameRunning = false;
                break;

            case SDLK_UP:
                rightPaddle.SetVy(-400);
                break;

            case SDLK_DOWN:
                rightPaddle.SetVy(400);
                break;

            case SDLK_w:
                leftPaddle.SetVy(-400);
                break;

            case SDLK_s:
                leftPaddle.SetVy(400);
                break;
        }
    } else {
        leftPaddle.SetVy(0);
        rightPaddle.SetVy(0);
    }
}


void Game::Update(float p_fDeltaTime)
{
    for (Entity* entity : entities)
        entity->Update(p_fDeltaTime);

    /* if ((ball.GetY() + ball.GetHeight()) >= leftPaddle.GetY() && ball.GetY() <= (leftPaddle.GetY() + leftPaddle.GetHeight()) && ; */
    // check for paddle collision
    if (utils::IsColliding(ball, rightPaddle))
        ball.SetVx(ball.GetVx() * -1);

    if (utils::IsColliding(ball, leftPaddle))
        ball.SetVx(ball.GetVx() * -1);

    // Bounce the ball when it hits the bottom or the top
    if ((ball.GetY() + ball.GetHeight()) >= g_ScreenHeight || ball.GetY() <= 0)
        ball.SetVy(ball.GetVy() * -1);
}

void Game::Render()
{
    // Clear the screen
    m_pWindow->SetColor(0, 0, 0, 255);
    m_pWindow->Clear();

    // Render with different color
    m_pWindow->SetColor(255, 255, 255, 255);

    for (Entity* entity : entities)
        m_pWindow->Render(entity);

    m_pWindow->Display();
}

bool Game::GameRunning()
{
    return m_bGameRunning;
}
