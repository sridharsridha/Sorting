//
// Created by Sridhar N on 28/06/20.
//

#ifndef SORTING_MERGE_SORT_HPP
#define SORTING_MERGE_SORT_HPP

#include <algorithm>
#include <iterator>

namespace sri {

// Merge Sort
// Finds the middle of the unsorted elements and recusrively calls itself with
// left and right sub elements, recursive calls terminate when the sub elements
// count reaches less than 2. These two sub elements are then merged
// together using inplace_merge and as stack unwinds we merge bigger sub
// elements until all the sub elements are merged into final sorted elements.
// Optimization: using inplace merge rather than normal merge using temporary.
// Further optimization of switching sorting algorithm depends on case to case
// basis is done in std::stable_sort so we are not going to look into that.
template <class ForwardIterator, class Comparator = std::less<>>
void merge_sort(ForwardIterator first, ForwardIterator last,
                Comparator comp = Comparator{}) {
  auto n = std::distance(first, last);
  if (n > 1) {
    auto middle = std::next(first, n / 2);
    merge_sort(first, middle, comp);
    merge_sort(middle, last, comp);
    std::inplace_merge(first, middle, last, comp);
  }
}

// Iterative Merge Sort
// Iterative merge sort is implemented similar way as recursion. In recursion,
// we recursively spilt the unsorted data in to two groups and once we reach a
// point where we have less than two elements we stop splitting and start
// merging. In iterative approach, we start merging from bottom up. In first
// pass, we start by taking 2 elements and then inplace_merge them then next two
// elements and merge and do the same until we reach the end. Similarly, next
// pass take 4 elements and do the same as the first pass and then next 8, 16
// etc. until the value is less then data size.
template <class ForwardIterator, class Comparator = std::less<>>
void merge_sort_i(ForwardIterator first, ForwardIterator last,
                  Comparator comp = Comparator{}) {
  using diff_type =
      typename std::iterator_traits<ForwardIterator>::difference_type;
  diff_type n = std::distance(first, last);
  for (diff_type size = 1; size < n; size = 2 * size) {
    for (diff_type start = 0; start < n; start += 2 * size) {
      diff_type middle = std::min(start + size, n);
      diff_type end = std::min(start + 2 * size, n);
      std::inplace_merge(std::next(first, start), std::next(first, middle),
                         std::next(first, end), comp);
    }
  }
}

}  // namespace sri

#endif  // SORTING_MERGE_SORT_HPP
