//
// Created by Sridhar N on 28/06/20.
//

#ifndef SORTING_BUBBLE_SORT_HPP
#define SORTING_BUBBLE_SORT_HPP

#include <type_traits>

namespace sri {

// Bubble Sort
// Bubbles (compare and swap) the current element with the previous
// element until last element has the greatest(ascending)/least(descending)
// element. Optimization: After each pass, store the last swapped index and use
// it as last for next pass. Reasoning is all elements after the last swap is
// already sorted.
template <class ForwardIterator, typename Comparator = std::less<>>
void bubble_sort(ForwardIterator first, ForwardIterator last,
                 Comparator comp = Comparator{}) {
  for (ForwardIterator sorted = first; first != last; last = sorted) {
    sorted = first;
    for (ForwardIterator current = first, prev = first; ++current != last;
         ++prev) {
      if (comp(*current, *prev)) {
        std::iter_swap(current, prev);
        sorted = current;
      }
    }
  }
}

}  // namespace sri

#endif  // SORTING_BUBBLE_SORT_HPP
