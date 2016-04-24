#ifndef COORDINATEGEOMETRY_LINE_H
#define COORDINATEGEOMETRY_LINE_H


class Line {
private:
    // Distance from origin
    double rho;
    // Slope
    double theta;
public:
    Line(double rho_, double theta);
};


#endif
