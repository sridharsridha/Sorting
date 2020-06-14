#ifndef __SORTING_HPP
#define __SORTING_HPP

#include <algorithm>
#include <iterator>
#include <type_traits>

namespace sri {

// Bubble Sort Implementation
template<class ForwardIterator, typename Comparator>
typename std::enable_if<
  !std::is_same<
    typename std::iterator_traits<ForwardIterator>::iterator_category,
    std::input_iterator_tag>::value
    && !std::is_same<
      typename std::iterator_traits<ForwardIterator>::iterator_category,
      std::output_iterator_tag>::value,
  void>::type
  bubble_sort(ForwardIterator first, ForwardIterator last, Comparator comp)
{
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

template<class ForwardIterator>
typename std::enable_if<
  !std::is_same<
    typename std::iterator_traits<ForwardIterator>::iterator_category,
    std::input_iterator_tag>::value
    && !std::is_same<
      typename std::iterator_traits<ForwardIterator>::iterator_category,
      std::output_iterator_tag>::value,
  void>::type
  bubble_sort(ForwardIterator first, ForwardIterator last)
{
  bubble_sort(
    first, last, std::less<typename std::iterator_traits<ForwardIterator>::value_type>());
}

// Selection Sort Implementation
template<class ForwardIterator, typename Comparator>
typename std::enable_if<
  !std::is_same<
    typename std::iterator_traits<ForwardIterator>::iterator_category,
    std::input_iterator_tag>::value
    && !std::is_same<
      typename std::iterator_traits<ForwardIterator>::iterator_category,
      std::output_iterator_tag>::value,
  void>::type
  selection_sort(ForwardIterator first, ForwardIterator last, Comparator comp)
{
  for (ForwardIterator sorted = first; sorted != last; ++sorted) {
    ForwardIterator minimum = sorted;
    for (ForwardIterator current = sorted; ++current != last;) {
      if (comp(*current, *minimum)) {
        minimum = current;
      }
    }
    std::iter_swap(sorted, minimum);
  }
}

template<class ForwardIterator>
typename std::enable_if<
  !std::is_same<
    typename std::iterator_traits<ForwardIterator>::iterator_category,
    std::input_iterator_tag>::value
    && !std::is_same<
      typename std::iterator_traits<ForwardIterator>::iterator_category,
      std::output_iterator_tag>::value,
  void>::type
  selection_sort(ForwardIterator first, ForwardIterator last)
{
  bubble_sort(
    first, last, std::less<typename std::iterator_traits<ForwardIterator>::value_type>());
}

}// namespace sri

#endif
