#ifndef PYTHONIC_NUMPY_RAVEL_HPP
#define PYTHONIC_NUMPY_RAVEL_HPP

#include "pythonic/include/numpy/ravel.hpp"

#include "pythonic/numpy/ndarray/reshape.hpp"
#include "pythonic/utils/numpy_conversion.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class T, size_t N>
  types::ndarray<T, 1> ravel(types::ndarray<T, N> const &expr)
  {
    return expr.reshape(types::array<long, 1>{{expr.flat_size()}});
  }

  NUMPY_EXPR_TO_NDARRAY0_IMPL(ravel);
  DEFINE_FUNCTOR(pythonic::numpy, ravel);
}
PYTHONIC_NS_END

#endif
