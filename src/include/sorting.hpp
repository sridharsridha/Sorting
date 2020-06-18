#ifndef __SORTING_HPP
#define __SORTING_HPP

#include <algorithm>
#include <forward_list>
#include <iterator>
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

// Merge Sort
// Finds the middle of the unsorted elements and recusrively calls itself with
// left and right sub elements, recursive calls terminate when the sub elements
// count reaches less than 2. These two sub elements are then merged
// together using inplace_merge and as stack unwinds we merge bigger sub elements
// until all the sub elements are merged into final sorted elements.
// Optimization: using inplace merge rather than normal merge using temporary.
// Further optimization of switching sorting algorithm depends on case to case basis
// is done in std::stable_sort so we are not going to look into that.
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
// Iterative merge sort is implemented similar way as recursion. In recursion, we
// recursively spilt the unsorted data in to two groups and once we reach a point
// where we have less than two elements we stop splitting and start merging.
// In iterative approach, we start merging from bottom up. In first pass, we start
// by taking 2 elements and then inplace_merge them then next two elements and merge
// and do the same until we reach end. Similarly, next pass take 4 elements and do
// the same as first pass and next 8, 16 etc. untill the value is less then data
// size.
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

// 3 way merge sort

// Quick Sort
// Iterative quick sort
// 3 way quick sort

// Heap Sort
// Counting Sort
// Radix Sort
// Bucket Sort
// Shell Sort
// Tim Sort
// Comb Sort
// Pigeonhole Sort
// Cycle Sort
// Coctail Sort
// Strand Sort
// Bitonic Sort
// Pancake Sort
// Permutation Sort
// Gnome Sort
// Sleep Sort
// Structure Sorting
// Tag Sort
// Tree Sort
// Stooge Sort
// Odd Even Sort
// Cartesian Tree Sort

}  // namespace sri

#endif
