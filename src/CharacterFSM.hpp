#ifndef CHARACTER_FSM_HPP

enum CharacterState {
    STATE_STALL,
    STATE_RUNNING,
    STATE_JUMPING,
    STATE_DUCKING,
    STATE_CRAWLING,
    STATE_ATTACKING,
    STATE_DEATH
};

class CharacterFSM {
    public:

        CharacterFSM();
        CharacterFSM(const CharacterFSM& other);
        ~CharacterFSM();

        void                    SetState(CharacterState state);
        const CharacterState    PresentState()  const;

    private:

        CharacterState          mActiveState;
};

#endif // CHARACTER_FSM_HPP
