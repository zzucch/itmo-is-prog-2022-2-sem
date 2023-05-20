#include "IsoscelesTrapezoid.h"

IsoscelesTrapezoid::IsoscelesTrapezoid() {
  InitFromDialog();
  FigureManager::AddFigure(this);
}

double IsoscelesTrapezoid::GetArea() const {
  return (b1_ + b2_) * h_ / 2.0;
}

double IsoscelesTrapezoid::GetPerimeter() const {
  double leg = std::abs((b2_ - b1_) / 2);
  double hypotenuse = std::sqrt(leg * leg + h_ * h_);
  return 2 * hypotenuse + b1_ + b2_;
}

const char *IsoscelesTrapezoid::GetClassname() const {
  return name_;
}

unsigned int IsoscelesTrapezoid::GetSize() const {
  return sizeof(*this);
}

CVector2D IsoscelesTrapezoid::GetPosition() const {
  return center_;
}

double IsoscelesTrapezoid::GetWeight() const {
  return weight_;
}

bool IsoscelesTrapezoid::operator==(IPhysObject &object) const {
  return GetWeight() == object.GetWeight();
}

bool IsoscelesTrapezoid::operator<(IPhysObject &object) const {
  return GetWeight() < object.GetWeight();
}

void IsoscelesTrapezoid::Draw() {
  std::cout << name_ << '\n';
  std::cout << "Lengths of sides and height:\n";
  std::cout << b1_ << ' ' << b2_ << ' ' << h_ << '\n';
  std::cout << "Weight: " << weight_;
  std::cout << "Center - x: " << center_.x << ", y: " << center_.y;
}

void IsoscelesTrapezoid::InitFromDialog() {
  std::cout << "Creating isosceles trapezoid\n";
  std::cout << "Weight:\n";
  std::cin >> weight_;
  std::cout << "Length of first side: \n";
  std::cin >> b1_;
  std::cout << "Length of second side: \n";
  std::cin >> b2_;
  std::cout << "Center - x and y:\n";
  std::cin >> center_.x >> center_.y;
}
