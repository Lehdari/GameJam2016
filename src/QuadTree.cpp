#include "QuadTree.hpp"


QuadTree::QuadTree(EventQueue& eventQueue, unsigned nBoundingBoxes) :
    eventQueue_(eventQueue),
    boundingBoxes_(nBoundingBoxes, std::make_pair(BoundingBox({0.0f, 0.0f}, {0.0f, 0.0f}), false))
{}

BoundingBox& QuadTree::getBoundingBoxReference(void) {
    for (auto& b : boundingBoxes_) {
        if (!b.second) {
            b.second = true;
            return b.first;
        }
    }
    throw "Not enough bounding box memory allocated in quadtree";
}

void QuadTree::checkCollisions(void) {

}
