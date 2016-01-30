#ifndef GAME_HPP

#include <vector>

#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum GameState {
    STATE_MENU,
    STATE_ACTIVE,
    STATE_PAUSE,
    STATE_CUTSCENE,
    STATE_EXITING
};

enum Options {
    OPTION_START,
    OPTION_HIGH_SCORE,
    OPTION_QUIT
};

enum PlayerState {
    STATE_STALL,
    STATE_RUNNING,
    STATE_FALLING,
    STATE_JUMPING,
    STATE_INTERACTING,
    STATE_DEAD
};

class Game {
    public:

        Game();
        Game(const Game& other);
        ~Game();

        void                        Run();

    private:

        void                        ProcessEvents();
        void                        ProcessInput();
        void                        Update(float dt);
        void                        Render(float dt);

        sf::Window                  mWindow;
        bool                        mShouldExit;
        bool                        mKeyStates[256];

        GameState                   mGameState;
        PlayerState                 mPlayerState;
        Options                     mOptionState;
};

#endif // GAME_HPP
