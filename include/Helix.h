#ifndef HELIX_H
#define HELIX_H

#pragma once

#include "Curve.h"
#include <cmath>

class Helix : public Curve {
public:
    Helix(double radius, double step);

    std::array<double, 3> getPoint(double t) const override;
    std::array<double, 3> getDerivative(double t) const override;

private:
    double radius, step;
};

#endif // HELIX_H
