#ifndef COLLISION_HANDLER_HPP

struct Box {
    float   width;
    float   height;
    float   center_x;
    float   center_y;
};

struct Ball {
    float   radius;
    float   center_x;
    float   center_y;
};

class CollisionHander {
    public:

        CollisionHander();
        CollisionHander(const CollisionHander& other);
        ~CollisionHander();

        void                MoveShape(int id, float deltaX, float deltaY);
        const int           GetShape(bool is_ball);
        void                Update();

    private:

        std::vector<Box>    mBoxes;
        std::vector<Ball>   mBalls;

        int                 mFreeBall;
        int                 mFreeBox;
};

#endif // COLLISION_HANDLER_HPP
