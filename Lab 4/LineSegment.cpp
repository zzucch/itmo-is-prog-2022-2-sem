#include "LineSegment.h"

LineSegment::LineSegment() {
  InitFromDialog();
  FigureManager::AddFigure(this);
}

double LineSegment::GetArea() const {
  return 0;
}

double LineSegment::GetPerimeter() const {
  return 2 * GetDistance(a_, b_);
}

double LineSegment::GetDistance(LineSegment::Point a, const LineSegment::Point b) const {
  return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const char *LineSegment::GetClassname() const {
  return name_;
}

unsigned int LineSegment::GetSize() const {
  return sizeof(*this);
}

CVector2D LineSegment::GetPosition() const {
  return center_;
}

double LineSegment::GetWeight() const {
  return weight_;
}

bool LineSegment::operator==(IPhysObject &object) const {
  return (weight_ == object.GetWeight()) && (center_ == object.GetPosition());
}

bool LineSegment::operator<(IPhysObject &object) const {
  return (weight_ < object.GetWeight());
}

void LineSegment::Draw() {
  std::cout << "Name: " << name_ << '\n';
  std::cout << "Weight: " << weight_ << '\n';
  std::cout << "Point a:\nx: " << a_.x << ", y: " << a_.y << '\n';
  std::cout << "Point b:\nx: " << b_.x << ", y: " << b_.y << '\n';
}

void LineSegment::InitFromDialog() {
  std::cout << "Creating line segment\n";
  std::cout << "Weight:\n";
  std::cin >> weight_;
  std::cout << "Point a; x and y:\n";
  std::cin >> a_.x >> a_.y;
  std::cout << "Point b; x and y:\n";
  std::cin >> b_.x >> b_.y;
  std::cout << "Center; x and y:\n";
  std::cin >> center_.x >> center_.y;
}
