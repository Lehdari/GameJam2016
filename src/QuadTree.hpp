#ifndef QUADTREE_HPP
#define QUADTREE_HPP


#include "BoundingBox.hpp"

#include <vector>



class EventQueue;
class GameObject;

class QuadTree {
public:
    QuadTree(EventQueue& eventQueue, unsigned nBoundingBoxes);

    BoundingBox& getBoundingBoxReference(GameObject*);

    void checkCollisions(void);

private:
    EventQueue& eventQueue_;
    std::vector<std::pair<BoundingBox, GameObject*>> boundingBoxes_;
};


#endif // QUADTREE_HPP
