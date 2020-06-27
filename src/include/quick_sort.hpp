//
// Created by Sridhar N on 28/06/20.
//

#ifndef SORTING_QUICK_SORT_HPP
#define SORTING_QUICK_SORT_HPP

#include <algorithm>
#include <stack>

namespace sri {

// Quick Sort
template <class ForwardIterator, class Comparator = std::less<>>
void quick_sort(ForwardIterator first, ForwardIterator last,
                Comparator comp = Comparator{}) {
  if (last == first || std::next(first) == last) {
    return;
  }
  auto pivot = *std::next(first, std::distance(first, last) / 2);
  auto middle1 = std::partition(
      first, last, [comp, pivot](const auto& elm) { return comp(elm, pivot); });
  auto middle2 = std::partition(middle1, last, [comp, pivot](const auto& elm) {
    return !comp(pivot, elm);
  });
  quick_sort(first, middle1, comp);
  quick_sort(middle2, last, comp);
}

// Iterative quick sort
template <class ForwardIterator, class Comparator = std::less<>>
void quick_sort_i(ForwardIterator first, ForwardIterator last,
                  Comparator comp = Comparator{}) {
  std::stack<std::pair<ForwardIterator, ForwardIterator>> stk;
  stk.push(std::make_pair(first, last));
  while (!stk.empty()) {
    auto [f, l] = stk.top();
    stk.pop();
    if (f == l || std::next(f) == l) {
      continue;
    }
    auto pivot = *std::next(f, std::distance(f, l) / 2);
    auto m1 = std::partition(
        f, l, [comp, pivot](const auto& elm) { return comp(elm, pivot); });
    auto m2 = std::partition(
        m1, l, [comp, pivot](const auto& elm) { return !comp(pivot, elm); });
    stk.push(std::make_pair(f, m1));
    stk.push(std::make_pair(m2, l));
  }
}

}  // namespace sri

#endif  // SORTING_QUICK_SORT_HPP
