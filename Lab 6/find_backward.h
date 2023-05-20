#ifndef INC_6_FIND_BACKWARD_H_
#define INC_6_FIND_BACKWARD_H_

template<typename Iterator, typename T>
Iterator find_backward(Iterator first, Iterator last, T value) {
    while (last != first) {
        if (*last == value) {
            return last;
        }
        --last;
    }
    return first;
}

#endif //INC_6_FIND_BACKWARD_H_
