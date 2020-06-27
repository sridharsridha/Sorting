//
// Created by Sridhar N on 28/06/20.
//

#ifndef SORTING_SELECTION_SORT_HPP
#define SORTING_SELECTION_SORT_HPP

#include <type_traits>

namespace sri {

// Selection Sort
// Finds the minimum element in each pass and swap it with the current element's
// location in each pass.
// Optimization: find min element start index decreases by 1 for every pass.
// Reasoning is after each pass either greater(ascending)/lesser(desceding)
// element is swapped to the current of that pass so its already sorted.
template <class ForwardIterator, typename Comparator = std::less<>>
void selection_sort(ForwardIterator first, ForwardIterator last,
                    Comparator comp = Comparator{}) {
  for (ForwardIterator sorted = first; sorted != last; ++sorted) {
    std::iter_swap(sorted, std::min_element(sorted, last, comp));
  }
}

}  // namespace sri

#endif  // SORTING_SELECTION_SORT_HPP
