#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#define _USE_MATH_DEFINES
#include <math.h>


int main() {
    std::vector<std::shared_ptr<Curve>> curves;

    for (int i = 0; i < 10; ++i) {
        int type = rand() % 3;
        if (type == 0)
            curves.push_back(std::make_shared<Circle>(rand() % 10 + 1));
        else if (type == 1)
            curves.push_back(std::make_shared<Ellipse>(rand() % 10 + 1, rand() % 10 + 1));
        else
            curves.push_back(std::make_shared<Helix>(rand() % 10 + 1, rand() % 10 + 1));
    }

    std::cout << "Points and Derivatives at t = PI/4:\n";
    for (const auto& curve : curves) {
        auto point = curve->getPoint(M_PI / 4);
        auto derivative = curve->getDerivative(M_PI / 4);
        std::cout << "Point: (" << point[0] << ", " << point[1] << ", " << point[2] << ") ";
        std::cout << "Derivative: (" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")\n";
    }

    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->getRadius() < b->getRadius();
    });

    double totalRadius = std::accumulate(circles.begin(), circles.end(), 0.0, [](double sum, const std::shared_ptr<Circle>& circle) {
        return sum + circle->getRadius();
    });

    std::cout << "Total radius of circles: " << totalRadius << "\n";

    return 0;
}
