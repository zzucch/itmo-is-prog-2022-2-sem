#include "LineSegment.h"
#include "IsoscelesTrapezoid.h"
#include "FigureManager.h"

int main() {
  // 15:
  // B - line segment
  LineSegment line_segment;
  // G - isosceles trapezoid
  IsoscelesTrapezoid isosceles_trapezoid;

  line_segment.Draw();
  isosceles_trapezoid.Draw();

  FigureManager::PrintAll();

  return 0;
}

