#ifndef INC_4_ISOSCELESTRAPEZOID_H_
#define INC_4_ISOSCELESTRAPEZOID_H_

#include "IFigure.h"
#include "FigureManager.h"
#include <iostream>
#include <cmath>

class IsoscelesTrapezoid : IFigure {
 public:
  IsoscelesTrapezoid();
  ~IsoscelesTrapezoid() = default;

  const double GetArea();
  double GetPerimeter() const override;
  const char *GetClassname() const override;
  unsigned int GetSize() const override;
  CVector2D GetPosition() const override;
  double GetWeight() const override;
  bool operator==(IPhysObject &object) const override;
  bool operator<(IPhysObject &object) const override;
  void Draw() override;

 private:
  const char *name_ = "Isosceles Trapezoid";
  CVector2D center_{};
  double weight_{};
  double b1_{};
  double b2_{};
  double h_{};
  void InitFromDialog() override;
};

#endif //INC_4_ISOSCELESTRAPEZOID_H_
