#ifndef GAME_FSM_HPP

enum State {
    STATE_NONE,
    STATE_MENU,
    STATE_ACTIVE,
    STATE_PAUSE,
    STATE_CUTSCENE
};

class GameFSM {
    public:

        GameFSM();
        GameFSM(const GameFSM& other);
        ~GameFSM();

        void        SetState(State state);
        const State PresentState()  const;

    private:

        State       mActiveState;
};

#endif // GAME_FSM_HPP
