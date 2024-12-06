#pragma once

#include "Helix.h"

#define _USE_MATH_DEFINES
#include <math.h>

Helix::Helix(double radius, double step) : radius(radius), step(step) {}

std::array<double, 3> Helix::getPoint(double t) const {
    return {radius * cos(t), radius * sin(t), step * t / (2 * M_PI)};
}

std::array<double, 3> Helix::getDerivative(double t) const {
    return {-radius * sin(t), radius * cos(t), step / (2 * M_PI)};
}
