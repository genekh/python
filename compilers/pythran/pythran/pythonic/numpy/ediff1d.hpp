#ifndef PYTHONIC_NUMPY_EDIFF1D_HPP
#define PYTHONIC_NUMPY_EDIFF1D_HPP

#include "pythonic/include/numpy/ediff1d.hpp"

#include "pythonic/numpy/asarray.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class E>
  types::ndarray<typename E::dtype, 1> ediff1d(E const &expr)
  {
    auto arr = asarray(expr);
    long n = arr.flat_size() - 1;
    types::ndarray<typename E::dtype, 1> out(types::make_tuple(n),
                                             __builtin__::None);
    // Compute adjacent difference except for the first element
    std::adjacent_difference(arr.fbegin() + 1, arr.fend(), out.fbegin());
    // First element can be done now
    (*out.fbegin()) = *(arr.fbegin() + 1) - *(arr.fbegin());
    return out;
  }

  template <class E>
  auto ediff1d(types::list<E> const &expr) -> decltype(ediff1d(asarray(expr)))
  {
    return ediff1d(asarray(expr));
  }

  DEFINE_FUNCTOR(pythonic::numpy, ediff1d);
}
PYTHONIC_NS_END

#endif
