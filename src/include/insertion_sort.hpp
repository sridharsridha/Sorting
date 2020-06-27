//
// Created by Sridhar N on 28/06/20.
//

#ifndef SORTING_INSERTION_SORT_HPP
#define SORTING_INSERTION_SORT_HPP

#include <algorithm>

namespace sri {

// Insertion sort
// In each pass, finds insertion point (first element greater(ascending) or
// lesser(descending) than current in range first to current and if found,
// shift range start to current - 1 right by one and insert the current to
// insertion point.
// Optimization: Uses binary search to find insertion point
template <class ForwardIterator, class Comparator = std::less<>>
void insertion_sort(ForwardIterator first, ForwardIterator last,
                    Comparator comp = Comparator{}) {
  for (ForwardIterator current = first; current != last; ++current) {
    std::rotate(std::upper_bound(first, current, *current, comp), current,
                std::next(current));
  }
}

}  // namespace sri

#endif  // SORTING_INSERTION_SORT_HPP
