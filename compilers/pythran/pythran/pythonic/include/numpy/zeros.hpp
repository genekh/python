#ifndef PYTHONIC_INCLUDE_NUMPY_ZEROS_HPP
#define PYTHONIC_INCLUDE_NUMPY_ZEROS_HPP

#include "pythonic/include/numpy/float64.hpp"
#include "pythonic/include/utils/functor.hpp"
#include "pythonic/include/types/ndarray.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class IntTy, size_t N, class dtype = functor::float64>
  types::ndarray<typename dtype::type, N>
  zeros(types::array<IntTy, N> const &shape, dtype d = dtype());

  template <class dtype = functor::float64>
  types::ndarray<typename dtype::type, 1> zeros(long size, dtype d = dtype());

  DECLARE_FUNCTOR(pythonic::numpy, zeros);
}
PYTHONIC_NS_END

#endif
