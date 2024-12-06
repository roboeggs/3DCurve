#ifndef ELLIPSE_H
#define ELLIPSE_H

#pragma once

#include "Curve.h"
#include <cmath>

class Ellipse : public Curve {
public:
    Ellipse(double radiusX, double radiusY);

    std::array<double, 3> getPoint(double t) const override;
    std::array<double, 3> getDerivative(double t) const override;

private:
    double radiusX, radiusY;
};

#endif // ELLIPSE_H
