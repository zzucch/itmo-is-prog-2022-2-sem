#ifndef INC_4_FIGUREMANAGER_H_
#define INC_4_FIGUREMANAGER_H_

#include <algorithm>
#include <vector>
#include "IFigure.h"

class FigureManager {
 public:
  static void AddFigure(IFigure *figure);
  static void RemoveFigure(int index);
  static void PrintAll();
  static double GetArea();
  static double GetPerimeter();
  static CVector2D GetCenterOfMass();
  static unsigned int GetMemoryUsage();
  static void SortByWeight();

 private:
  static std::vector<IFigure *> all_figures_;
};

#endif //INC_4_FIGUREMANAGER_H_
