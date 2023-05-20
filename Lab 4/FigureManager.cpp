#include "FigureManager.h"

std::vector<IFigure *> FigureManager::all_figures_;

void FigureManager::AddFigure(IFigure *figure) {
  all_figures_.push_back(figure);
}

void FigureManager::RemoveFigure(int index) {
  all_figures_.erase(all_figures_.begin() + index);
}

void FigureManager::PrintAll() {
  for (IFigure *i : all_figures_) {
    i->Draw();
  }
}

double FigureManager::GetArea() {
  double result = 0;
  for (const IFigure *i : all_figures_) {
    result += i->GetWeight();
  }
  return result;
}

double FigureManager::GetPerimeter() {
  double result = 0;
  for (const IFigure *i : all_figures_) {
    result += i->GetPerimeter();
  }
  return result;
}

CVector2D FigureManager::GetCenterOfMass() {
  double total_mass = 0;
  CVector2D weighted_sum{};

  for (IFigure *i : all_figures_) {
    double mass = i->GetWeight();
    total_mass += mass;
    weighted_sum.x += i->GetPosition().x * mass;
    weighted_sum.y += i->GetPosition().y * mass;
  }

  weighted_sum.x /= total_mass;
  weighted_sum.y /= total_mass;

  return weighted_sum;
}

unsigned int FigureManager::GetMemoryUsage() {
  unsigned int result = 0;
  for (IFigure *i : all_figures_) {
    result += i->GetSize();
  }
  return result;
}

void FigureManager::SortByWeight() {
  std::sort(all_figures_.begin(), all_figures_.end(),
            [](IFigure *a, IFigure *b) { return a->GetWeight() < b->GetWeight(); });
}
