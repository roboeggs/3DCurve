#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include "Curve.h"
#include <cmath>

class Circle : public Curve {
public:
    explicit Circle(double radius);

    std::array<double, 3> getPoint(double t) const override;
    std::array<double, 3> getDerivative(double t) const override;
    double getRadius() const;

private:
    double radius;
};

#endif // CIRCLE_H
