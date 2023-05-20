#include <iostream>
#include <algorithm>
#include "CircularBuffer.h"

int main() {
  CircularBuffer<int> first_buffer(12);
  first_buffer.push_front(3);
  first_buffer.push_back(2);
  first_buffer.push_front(4);
  first_buffer.push_back(1);

  for (auto i : first_buffer) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::sort(first_buffer.begin(), first_buffer.end());

  for (auto iterator = first_buffer.begin();
       iterator != first_buffer.end(); ++iterator) {
    std::cout << *iterator << ' ';
  }
  std::cout << '\n';

  CircularBuffer<int> second_buffer;

  try {
    second_buffer.push_back(12);
  } catch (std::out_of_range &e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "capacity/size:\t\n";
  std::cout << second_buffer.capacity() << "\t" << second_buffer.size()
            << '\n';
  second_buffer.resize(3);
  std::cout << second_buffer.capacity() << "\t" << second_buffer.size()
            << '\n';

  second_buffer = first_buffer;
  CircularBuffer third_buffer(first_buffer);

  for (int i = 0; i < second_buffer.size(); ++i) {
    std::cout << first_buffer[i] << ' ' << second_buffer[i] << ' '
              << third_buffer[i] << ' ' << '\n';
  }

  return 0;
}

