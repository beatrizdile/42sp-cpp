#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

template <typename Container>
typename Container::const_iterator easyFind(const Container& container, int num) {
    typename Container::const_iterator it;
    
    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw std::out_of_range("Element not found in container");
    return it;
}

#endif