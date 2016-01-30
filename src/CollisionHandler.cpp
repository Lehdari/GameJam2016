#include "CollisionHandler.hpp"

CollisionHander::CollisionHander() {

}

CollisionHander::CollisionHander(const CollisionHander& other) {

}

CollisionHander::~CollisionHander() {

}

const int CollisionHander::GetShape(bool is_ball) {
    if(is_ball) {
        if(mFreeBall < mBalls.size())
            return mFreeBall++;
        else {
            Ball ball;
            mBalls.push_back(ball);
            return mFreeBall++;
        }
    }

    else {
        if(mFreeBox < mBoxes.size())
            return mFreeBox++;
        else {
            Box box;
            mBoxes.push_back(box);
            return mFreeBox++;
        }
    }
}

void CollisionHander::MoveShape(int id, float deltaX, float deltaY) {

}

void CollisionHander::Update() {

}
