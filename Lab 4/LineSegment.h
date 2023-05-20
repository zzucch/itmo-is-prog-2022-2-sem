#ifndef INC_4_LINESEGMENT_H_
#define INC_4_LINESEGMENT_H_

#include "IFigure.h"
#include "FigureManager.h"
#include <cmath>
#include <iostream>

class LineSegment : public IFigure {
 public:
  class Point {
   public:
    double y;
    double x;
  };

  LineSegment();
  ~LineSegment() = default;

  double GetArea() const override;
  double GetPerimeter() const override;
  const char *GetClassname() const override;
  unsigned int GetSize() const override;
  CVector2D GetPosition() const override;
  double GetWeight() const override;
  bool operator==(IPhysObject &object) const override;
  bool operator<(IPhysObject &object) const override;
  void Draw() override;

 private:
  const char *name_ = "line segment";
  CVector2D center_{};
  Point a_{};
  Point b_{};
  int weight_{};

  double GetDistance(Point a, Point b) const;
  void InitFromDialog() override;
};

#endif //INC_4_LINESEGMENT_H_
