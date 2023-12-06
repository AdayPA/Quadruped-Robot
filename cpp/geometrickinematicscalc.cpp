#include <iostream>
#include <vector>
#include <cmath>

const long double pi = atan(1)*4;

double radToDegree (double radians) {
  return radians * (180/pi);
}

double degToRadian (double degrees) {
  return degrees * (pi / 180);
}

std::vector<double> forward(double q1d, double q2d, double l1, double l2) {
  double q1 = degToRadian(q1d);
  double q2 = degToRadian(q2d);
  std::vector<double> result;
  result.push_back(l1 * cos(q1) + l2 * cos(q1 + q2));
  result.push_back(l1 * sin(q1) + l2 * sin(q1 + q2));
  return result;
}

std::vector<double> inverse(double x, double y, double l1, double l2) {
  std::vector<double> result;
  double r1 = sqrt(pow(x, 2) + pow(y, 2));
  double m = (pow(r1, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2);
  double b1 = atan2(y, x);
  double m2 = (pow(r1, 2) + pow(l1, 2) - pow(l2, 2)) / (2 * r1 * l1);
  double q1 = b1 - acos(m2);
  double q2 = acos(m);
  result.push_back(radToDegree(q1));
  result.push_back(radToDegree(q2));
  return result;
}

int main(void) {
  std::vector<double> temp;

  double offset_q1 = 10.0;  // Offset para q1 en grados
  double offset_q2 = -5.0;  // Offset para q2 en grados

  temp = forward(0, -200, 106, 135); // points to angles
  std::cout << "directa:\n";
  std::cout << temp.at(0) + 165<< "\n";
  std::cout << temp.at(1) - 170 << "\n";

  temp = inverse(180 + 165, 180 - 170, 106, 135); // angles to points
  std::cout << "inversa:\n";
  std::cout << temp.at(0) << "\n";
  std::cout << temp.at(1) << "\n";

  return 0;
}

