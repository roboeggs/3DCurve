#include "Circle.h"

Circle::Circle(double radius) : radius(radius) {}

std::array<double, 3> Circle::getPoint(double t) const {
    return {radius * cos(t), radius * sin(t), 0.0};
}

std::array<double, 3> Circle::getDerivative(double t) const {
    return {-radius * sin(t), radius * cos(t), 0.0};
}

double Circle::getRadius() const {
    return radius;
}
