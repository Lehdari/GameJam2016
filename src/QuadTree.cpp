#include "QuadTree.hpp"

#include "Event.hpp"
#include "EventQueue.hpp"


QuadTree::QuadTree(EventQueue& eventQueue, unsigned nBoundingBoxes) :
    eventQueue_(eventQueue),
    boundingBoxes_(nBoundingBoxes, std::make_pair(BoundingBox({0.0f, 0.0f}, {0.0f, 0.0f}), nullptr))
{}

BoundingBox& QuadTree::getBoundingBoxReference(GameObject* gameObject) {
    for (auto& b : boundingBoxes_) {
        if (!b.second) {
            b.second = gameObject;
            return b.first;
        }
    }
    throw "Not enough bounding box memory allocated in quadtree";
}

void QuadTree::checkCollisions(void) {
	for (size_t ii = 0; ii < boundingBoxes_.size() - 1; ++ii) {
		if (boundingBoxes_[ii].second) {
			for (size_t jj = ii + 1; jj < boundingBoxes_.size(); ++jj) {
				if (boundingBoxes_[jj].second) {
					auto& bb1 = boundingBoxes_[ii].first;
					auto& bb2 = boundingBoxes_[jj].first;

					bool collision = !(bb1.topRight_.x() < bb2.bottomLeft_.x() ||
					                   bb1.topRight_.y() < bb2.bottomLeft_.y() ||
					                   bb1.bottomLeft_.x() > bb2.topRight_.x() ||
					                   bb1.bottomLeft_.y() > bb2.topRight_.y());

					if (collision) {
						Event event;
						event.type = Event::Collision;
						event.collisionData.a = boundingBoxes_[ii].second;
						event.collisionData.b = boundingBoxes_[jj].second;

						eventQueue_.events_.push(std::move(event));
					}
				}
			}
		}
	}
}
