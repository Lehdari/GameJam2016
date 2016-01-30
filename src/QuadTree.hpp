#ifndef QUADTREE_HPP
#define QUADTREE_HPP


#include "BoundingBox.hpp"

#include <vector>


class EventQueue;


class QuadTree {
public:
    QuadTree(EventQueue& eventQueue, unsigned nBoundingBoxes);

    BoundingBox& getBoundingBoxReference(void);

    void checkCollisions(void);

private:
    EventQueue& eventQueue_;
    std::vector<std::pair<BoundingBox, bool>> boundingBoxes_;
};


#endif // QUADTREE_HPP
