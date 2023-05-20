#ifndef INC_7_CIRCULARBUFFER_H
#define INC_7_CIRCULARBUFFER_H

#include <iterator>
#include <cstddef>

template<typename T>
class CircularBuffer {
 public:
  class iterator {
   public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    iterator(CircularBuffer<T> *circular_buffer, size_t index)
        : m_circular_buffer(circular_buffer), m_index(index) {}

    reference operator*() const {
      return m_circular_buffer->m_buffer[m_index];
    }

    pointer operator->() const {
      return &((*m_circular_buffer)[m_index]);
    }

    reference operator[](difference_type d) const {
      return *(*this + d);
    }

    iterator &operator++() {
      m_index = (m_index + 1) % m_circular_buffer->capacity();
      return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    iterator &operator--() {
      m_index = (m_index - 1 + m_circular_buffer->capacity())
          % m_circular_buffer->capacity();
      return *this;
    }

    iterator operator--(int) {
      iterator tmp = *this;
      --(*this);
      return tmp;
    }

    iterator operator+(difference_type d) const {
      return iterator(m_circular_buffer,
                      (m_index + d) % m_circular_buffer->capacity());
    }

    iterator operator-(difference_type d) const {
      return iterator(m_circular_buffer,
                      (m_index - d + m_circular_buffer->capacity())
                          % m_circular_buffer->capacity());
    }

    iterator &operator+=(difference_type d) {
      m_index = (m_index + d) % m_circular_buffer->capacity();
      return *this;
    }

    iterator &operator-=(difference_type d) {
      m_index = (m_index - d + m_circular_buffer->capacity())
          % m_circular_buffer->capacity();
      return *this;
    }

    difference_type operator-(const iterator &other) const {
      if (m_index >= other.m_index) {
        return m_index - other.m_index;
      } else {
        return m_circular_buffer->capacity()
            - other.m_circular_buffer->capacity();
      }
    }

    bool operator==(const iterator &other) const {
      return m_index == other.m_index;
    }

    bool operator!=(const iterator &other) const {
      return m_index != other.m_index;
    }

    bool operator<(const iterator &other) const {
      if (m_circular_buffer == other.m_circular_buffer) {
        if (m_index >= other.m_index) {
          return m_index - other.m_index < m_circular_buffer->capacity() / 2;
        } else {
          return other.m_index - m_index > m_circular_buffer->capacity() / 2;
        }
      } else {
        return false;
      }
    }

    bool operator>(const iterator &other) const {
      return other < *this;
    }

    bool operator<=(const iterator &other) const {
      return !(other < *this);
    }

    bool operator>=(const iterator &other) const {
      return !(*this < other);
    }

   private:
    CircularBuffer<T> *m_circular_buffer;
    size_t m_index;
  };

  CircularBuffer() : m_buffer(new T[0]),
                     m_capacity(0),
                     m_size(0),
                     m_head(0) {}

  explicit CircularBuffer(size_t capacity)
      : m_buffer(new T[capacity]), m_capacity(capacity), m_size(0), m_head(0) {}

  ~CircularBuffer() {
    delete[] m_buffer;
  }

  CircularBuffer(const CircularBuffer &other)
      : m_buffer(new T[other.m_capacity]),
        m_capacity(other.m_capacity),
        m_size(other.m_size),
        m_head(other.m_head) {
    for (size_t i = 0; i < m_size; ++i) {
      m_buffer[(m_head + i) % m_capacity] =
          other.m_buffer[(other.m_head + i) % other.m_capacity];
    }
  }

  CircularBuffer &operator=(const CircularBuffer &other) {
    if (this == &other) {
      return *this;
    }
    T *new_buffer = new T[other.m_capacity];
    for (size_t i = 0; i < other.m_size; ++i) {
      new_buffer[(other.m_head + i) % other.m_capacity] =
          other.m_buffer[(other.m_head + i) % other.m_capacity];
    }
    delete[] m_buffer;
    m_buffer = new_buffer;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_head = other.m_head;
    return *this;
  }

  bool operator==(CircularBuffer &other) {
    if (m_size == other.m_size) {
      for (int i = 0; i < m_size; ++i) {
        if (m_buffer[(i + m_head) % m_capacity]
            != other.m_buffer[(i + other.m_head) % other.m_capacity]) {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  size_t capacity() const {
    return m_capacity;
  }

  size_t size() const {
    return m_size;
  }

  iterator begin() {
    return iterator(this, (m_head + m_capacity) % m_capacity);
  }

  iterator end() {
    return iterator(this, (m_head + m_size + m_capacity) % m_capacity);
  }

  T &operator[](size_t i) const {
    if (i >= m_size) {
      throw std::out_of_range("CircularBuffer index out of range");
    }
    return m_buffer[(m_head + i) % m_capacity];
  }

  const T &operator[](size_t i) {
    if (i >= m_size) {
      throw std::out_of_range("CircularBuffer index out of range");
    }
    return m_buffer[(m_head + i) % m_capacity];
  }

  void resize(size_t new_capacity) {
    if (new_capacity < m_size) {
      throw std::invalid_argument(
          "New capacity must be greater than or equal to the size of the buffer");
    } else if (new_capacity == m_capacity) {
      return;
    }

    T *new_buffer = new T[new_capacity];
    for (size_t i = 0; i < m_size; ++i) {
      new_buffer[i] = m_buffer[(m_head + i) % m_capacity];
    }

    delete[] m_buffer;
    m_buffer = new_buffer;
    m_capacity = new_capacity;
    m_head = 0;
  }

  void push_back(const T &value) {
    if (m_size == m_capacity) {
      throw std::out_of_range("The buffer is full");
    } else {
      m_buffer[(m_head + m_size) % m_capacity] = value;
      ++m_size;
    }
  }

  void push_front(const T &value) {
    if (m_size == m_capacity) {
      throw std::out_of_range("The buffer is full");
    } else {
      m_head = (m_head - 1) % m_capacity;
      m_buffer[m_head] = value;
      ++m_size;
    }
  }

 private:
  T *m_buffer;
  size_t m_capacity{};
  size_t m_size{};
  size_t m_head{};
};

#endif //INC_7_CIRCULARBUFFER_H
