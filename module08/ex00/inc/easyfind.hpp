#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

template <typename Container>
typename Container::const_iterator easyfind(const Container& container, int num) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (*it == num)
			return it;
    }
    throw std::out_of_range("Element not found in container");
}

#endif