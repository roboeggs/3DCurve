#include "Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}

std::array<double, 3> Ellipse::getPoint(double t) const {
    return {radiusX * cos(t), radiusY * sin(t), 0.0};
}

std::array<double, 3> Ellipse::getDerivative(double t) const {
    return {-radiusX * sin(t), radiusY * cos(t), 0.0};
}
