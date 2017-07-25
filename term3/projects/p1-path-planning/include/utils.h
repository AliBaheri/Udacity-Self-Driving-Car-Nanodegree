#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <cmath>

constexpr double pi() { return M_PI; }
constexpr double deg2rad(const double x) { return x * pi() / 180.0; }
constexpr double rad2deg(double x) { return x * 180.0 / pi(); }

std::string hasData(const std::string& s);

double distance(double x1, double y1, double x2, double y2);
int ClosestWaypoint(double x, double y, std::vector<double> maps_x,
                                        std::vector<double> maps_y);
int NextWaypoint(double x, double y, double theta, std::vector<double> maps_x,
                                                   std::vector<double> maps_y);
std::vector<double> getFrenet(double x, double y, double theta,
                              std::vector<double> maps_x,
                              std::vector<double> maps_y);
std::vector<double> getXY(double s, double d, std::vector<double> maps_s,
                    std::vector<double> maps_x, std::vector<double> maps_y);

/// \brief Computes the coefficients of a jerk-minimizing 5-order polynomial
///        trajectory, given the initial and final conditions, as well as
///        the time taken to go from initial to final states.
/// \param x0       initial position
/// \param x0_d     initial velocity
/// \param x0_dd    initial acceleration
/// \param xf       final position
/// \param xf_d     final velocity
/// \param xf_dd    final acceleration
/// \param t        time to go from initial to final state
/// \param trajectory_coeffs coefficients of the trajectory, in the form:
///
///        x(t) = c[0] + c[1]*t + c[2]*t^2 + c[3]*t^3 + c[4]*t^4 + c[5]*t^5
void generateJerkMinTrajectory(const double x0, const double x0_d, const double x0_dd,
                               const double xf, const double xf_d, const double xf_dd,
                               const double t,
                               std::vector<double>& trajectory_coeffs);

/// \brief Evaluates the polynomial:
///
///        f(x) = coeffs[0] + coeffs[1]*x + coeffs[2]*x^2 + ...
///
/// \param coeffs coefficients of the polynomial
/// \param x      point at which the polynomial is evaluated
/// \return f(x), the polynomial evaluated at x
double evaluatePolynomial(const std::vector<double>& coeffs, const double x);

#endif // UTILS_H
