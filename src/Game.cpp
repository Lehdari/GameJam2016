#include "game.hpp"


Game::Game() {
    mShouldExit = false;
    mWindow.create(sf::VideoMode(800, 600), "Game Jam");
}

Game::Game(const Game& other) {

}

Game::~Game() {

}

void Game::Run() {
    float delta;

    while(!mShouldExit) {
        ProcessEvents();
        Update(delta);
        Render(delta);
    }
}

void Game::ProcessEvents() {
    sf::Event event;

    while(mWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed : {
                mWindow.close();
                break;
            }

            case sf::Event::KeyPressed : {
                mKeyStates[(int)event.key.code] = true;
                break;
            }

            case sf::Event::KeyReleased : {
                mKeyStates[(int)event.key.code] = false;
                break;
            }

            default:
                break;
        }
    }
}

void Game::ProcessInput() {
    switch(mGameState) {
        case STATE_MENU : {

        }

        case STATE_ACTIVE : {

        }

        case STATE_PAUSE : {

        }

        default:
            break;
    }
}

void Game::Update(float dt) {
    switch(mGameState) {
        case STATE_MENU : {

        }

        case STATE_ACTIVE : {

        }

        case STATE_PAUSE : {

        }

        case STATE_CUTSCENE : {

        }

        case STATE_EXITING : {

        }

        default:
            break;
    }
}

void Game::Render(float dt) {

}
