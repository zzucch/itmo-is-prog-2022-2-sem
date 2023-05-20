#ifndef INC_2_SUBSET_H
#define INC_2_SUBSET_H

#include <ostream>

class Subset {
 public:
  Subset();
  explicit Subset(int size);

  bool Contains(int) const;
  void AddValue(int value);
  void RemoveValue(int value);

  Subset operator+(const Subset &rhs) const;
  Subset operator-(const Subset &rhs) const;
  Subset operator*(const Subset &rhs) const;
  friend std::ostream &operator<<(std::ostream &ostream, const Subset &subset);

 private:
  int size_;
  int *array_;
  int i_;
};

#endif //INC_2_SUBSET_H
