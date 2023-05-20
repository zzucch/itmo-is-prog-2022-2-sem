#ifndef INC_5_SWAP_H
#define INC_5_SWAP_H

template<typename T>
void Swap(T &first, T &second);

template<typename T>
void Swap(T &first, T &second) {
    T tmp = first;
    first = second;
    second = tmp;
}

#endif //INC_5_SWAP_H
