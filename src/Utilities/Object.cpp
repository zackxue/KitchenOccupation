#include "Object.hpp"

Object::Object(cv::Rect boundingBox)
{
    id = -1;
    this->boundingBox = boundingBox;
    center.x = boundingBox.x + boundingBox.width/2.0;
    center.y = boundingBox.y + boundingBox.height/2.0;

    entryPoint = cv::Point2d(-1, -1);
    exitPoint = cv::Point2d(-1, -1);

    lost = false;
}

Object::~Object()
{

}

void Object::merge(Object * previousState) {
    id = previousState->id;
    lost = previousState->lost;
    entryPoint = previousState->entryPoint;
}

void Object::enter() {
    entryPoint = center;
}

void Object::exit() {
    exitPoint = center;
    lost = true;
}



