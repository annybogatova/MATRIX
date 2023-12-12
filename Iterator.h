//
// Created by AnnyB on 09.12.2023.
//

#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include <iterator>

template <typename T>
struct Iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }

    pointer operator->() { return m_ptr; }

    Iterator &operator++() {
        m_ptr++;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

    friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

private:
    pointer m_ptr;
};


#endif //LAB3_ITERATOR_H
