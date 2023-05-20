#ifndef INC_5_ARRAY_H
#define INC_5_ARRAY_H

// Array with N elements of type T;
// template params: (int N, class T)
// Exception: accessing at non-existent index

#include <string>
#include <utility>

class Exception {
public:
    virtual std::string getMessage() = 0;

protected:
    std::string messageText;
};

class ArrayException : public Exception {
public:
    explicit ArrayException(std::string _text = "Error. Exception") {
        messageText = std::move(_text);
    }

    std::string getMessage() override;
};

class nonExistentIndex final : public ArrayException {
public:
    explicit nonExistentIndex(std::string _text = "Error. Trying to access non-existent index") {
        messageText = std::move(_text);
    }

    std::string getMessage() override;
};

template<int N, class T>
class Array {
public:
    void setElement(int i, T value);

    T getElement(int i);

private:
    T array[N];
};

template<int N, class T>
T Array<N, T>::getElement(int i) {
    if (i < 0 || i >= N) {
        throw nonExistentIndex();
    }
    return this->array[i];
}

template<int N, class T>
void Array<N, T>::setElement(int i, T value) {
    if (i < 0 || i >= N) {
        throw nonExistentIndex();
    }
    this->array[i] = value;
}


#endif //INC_5_ARRAY_H
