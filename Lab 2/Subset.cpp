#include "Subset.h"

Subset::Subset() {
  const int default_size = 10;
  size_ = default_size;
  array_ = new int[size_];
  i_ = 0;
}

Subset::Subset(int size) : size_(size) {
  array_ = new int[size];
  i_ = 0;
}

bool Subset::Contains(int value) const {
  for (int j = 0; j < i_; ++j) {
    if (array_[j] == value) {
      return true;
    }
  }
  return false;
}

void Subset::AddValue(int value) {
  bool contains = false;
  for (int j = 0; j < i_; ++j) {
    if (array_[j] == value) {
      contains = true;
      break;
    }
  }
  if (!contains) {
    array_[i_++] = value;
  }
}

void Subset::RemoveValue(int value) {
  for (int k = 0; k < i_; ++k) {
    if (array_[k] == value) {
      for (int l = k; l < i_ - 1; ++l) {
        array_[l] = array_[l + 1];
      }
      --i_;
      break;
    }
  }
}

Subset Subset::operator+(const Subset &rhs) const {
  auto subsets_union = Subset(this->size_ + rhs.size_);

  for (int j = 0; j < this->i_; ++j) {
    subsets_union.array_[subsets_union.i_++] = this->array_[j];
  }
  for (int j = 0; j < rhs.i_; ++j) {
    subsets_union.array_[subsets_union.i_++] = rhs.array_[j];
  }
  return subsets_union;
}

Subset Subset::operator-(const Subset &rhs) const {
  auto subtraction = Subset(this->size_ + rhs.size_);
  for (int j = 0; j < this->i_; ++j) {
    if (!rhs.Contains(this->array_[j])) {
      subtraction.array_[subtraction.i_++] = this->array_[j];
    }
  }
  return subtraction;
}

Subset Subset::operator*(const Subset &rhs) const {
  auto intersection = Subset(this->size_ + rhs.size_);

  for (int j = 0; j < this->i_; ++j) {
    if (rhs.Contains(this->array_[j])) {
      intersection.array_[intersection.i_++] = this->array_[j];
    }
  }
  return intersection;
}

std::ostream &operator<<(std::ostream &ostream, const Subset &subset) {
  ostream << "max size: " << subset.size_ << "\narray: {";
  for (int j = 0; j < subset.i_; ++j) {
    ostream << subset.array_[j];
    if (j + 1 != subset.i_) {
      ostream << ", ";
    }
  }
  ostream << "}\n";
  return ostream;
}
