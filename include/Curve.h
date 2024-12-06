#ifndef CURVE_H
#define CURVE_H

#include <array>

// Abstract base class for all curves
class Curve {
public:
    virtual ~Curve() = default;

    virtual std::array<double, 3> getPoint(double t) const = 0;
    virtual std::array<double, 3> getDerivative(double t) const = 0;
};

#endif // CURVE_H
