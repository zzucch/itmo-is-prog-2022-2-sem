#ifndef INC_6_IS_PARTITIONED_H_
#define INC_6_IS_PARTITIONED_H_

template<typename Iterator, typename Predicate>
bool is_partitioned(Iterator first, Iterator last, Predicate predicate) {
    while (first != last && predicate(*first)) {
        ++first;
    }
    while (first != last) {
        if (predicate(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}
#endif //INC_6_IS_PARTITIONED_H_
