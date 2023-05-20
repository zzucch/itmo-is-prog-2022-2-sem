#include <iostream>
#include <vector>
#include <deque>

#include "all_of.h"
#include "is_partitioned.h"
#include "find_backward.h"
#include "user_classes/Apple.h"

void Check1() {
  std::cout << "[1] - all_of:\n";

  std::cout << "std::vector:\n";
  std::vector<int> v(12, -1);

  if (all_of(v.begin(), v.end(), [](int i) -> bool { return i > 0; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }

  std::cout << "std::deque:\n";
  std::deque<int> d = {5, 7, 9, 11};

  if (all_of(d.begin(), d.end(), [](int i) -> bool { return i % 2 == 0; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }

  std::cout << "Apple class:\n";
  Apple apple_array[3] = {{}, {12, Apple::Color::RED}, {21, Apple::Color::GREEN}};

  Apple tmp;

  if (all_of(&apple_array[0], &apple_array[2], [&tmp](Apple i) -> bool { return tmp == i; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }
}

void Check6() {
  std::cout << "\n[6] - is_partitioned:\n";

  std::cout << "std::vector:\n";
  std::vector<int> v(12, -1);

  if (is_partitioned(v.begin(), v.end(), [](int i) -> bool { return i > 0; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }

  std::cout << "std::deque:\n";
  std::deque<int> d = {5, 7, 9, 11};

  if (is_partitioned(d.begin(), d.end(), [](int i) -> bool { return i % 2 == 0; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }

  std::cout << "Apple class:\n";
  Apple apple_array[3] = {{}, {12, Apple::Color::RED}, {21, Apple::Color::GREEN}};

  Apple tmp;

  if (is_partitioned(&apple_array[0], &apple_array[2], [&tmp](Apple i) -> bool { return tmp == i; })) {
    std::cout << "true\n";
  } else {
    std::cout << "false\n";
  }
}

void Check8() {
  std::cout << "\n[8] - find_backward:\n";

  std::cout << "std::vector:\n";
  std::vector<int> v(12, -1);
  int tmp_1 = 12;

  v.begin() = find_backward(v.begin(), v.end(), tmp_1);
  std::cout << v[0] << '\n';

  std::cout << "std::deque:\n";
  std::deque<int> d = {5, 7, 9, 11};

  std::cout << *find_backward(d.begin(), d.end(), d[2]) << '\n';

  std::cout << "Apple class:\n";

  Apple apple_array[3] = {{}, {12, Apple::Color::RED}, {21, Apple::Color::GREEN}};

  Apple tmp_2;

  auto tmp_3 = find_backward(&apple_array[0], &apple_array[2], tmp_2);
  std::cout << tmp_3->GetWeight() << ((tmp_3->GetColor() == Apple::Color::GREEN) ? " green" : " red") << '\n';
}

int main() {
  Check1();
  Check6();
  Check8();

  return 0;
}

