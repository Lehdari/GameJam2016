GameFSM::GameFSM() {
    mActiveState = STATE_NONE;
}

GameFSM::GameFSM(const GameFSM& other) {

}

GameFSM::~GameFSM() {

}

void GameFSM::SetState(State state) {
    switch(mActiveState) {
        case STATE_NONE :
            mActiveState = state;

        case STATE_ACTIVE : {
            if (state == STATE_PAUSE)
                mActiveState = STATE_PAUSE;
        }

        case STATE_PAUSE : {
            if (state == STATE_ACTIVE)
                mActiveState = STATE_ACTIVE;

            else if (state = STATE_MENU)
                mActiveState = STATE_MENU;

            else if (state = STATE_CUTSCENE)
                mActiveState = STATE_CUTSCENE;
        }

        case STATE_MENU : {
            if (state == STATE_ACTIVE)
                mActiveState = STATE_ACTIVE;
        }

        case STATE_CUTSCENE : {
            if (state == STATE_ACTIVE)
                mActiveState = STATE_ACTIVE;
        }
    }
}

const State GameFSM::PresentState() const {
    return mActiveState;
}
