#ifndef __SORTING_HPP
#define __SORTING_HPP

#include <algorithm>
#include <iterator>
#include <type_traits>

namespace sri {

// Bubble Sort Implementation
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

// Selection Sort Implementation
template <class ForwardIterator, typename Comparator = std::less<>>
void selection_sort(ForwardIterator first, ForwardIterator last,
                    Comparator comp = Comparator{}) {
  for (ForwardIterator sorted = first; sorted != last; ++sorted) {
    std::iter_swap(sorted, std::min_element(sorted, last, comp));
  }
}

// Best performing insertion sort algorithm
template <class ForwardIterator, class Comparator = std::less<>>
void insertion_sort(ForwardIterator first, ForwardIterator last,
                    Comparator comp = Comparator{}) {
  for (ForwardIterator it = first; it != last; ++it) {
    std::rotate(std::upper_bound(first, it, *it, comp), it, std::next(it));
  }
}


}  // namespace sri



#endif
