#ifndef INC_6_ALL_OF_H_
#define INC_6_ALL_OF_H_

template<typename Iterator, typename Predicate>
bool all_of(Iterator first, Iterator last, Predicate predicate) {
    while (first != last) {
        if (!predicate(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}

#endif //INC_6_ALL_OF_H_
