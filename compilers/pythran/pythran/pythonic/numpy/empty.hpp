#ifndef PYTHONIC_NUMPY_EMPTY_HPP
#define PYTHONIC_NUMPY_EMPTY_HPP

#include "pythonic/include/numpy/empty.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/ndarray.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class IntTy, size_t N, class dtype>
  types::ndarray<typename dtype::type, N>
  empty(types::array<IntTy, N> const &shape, dtype)
  {
    static_assert(std::is_integral<IntTy>::value,
                  "expected shape of integral type");
    return {shape, __builtin__::None};
  }

  template <class dtype>
  types::ndarray<typename dtype::type, 1> empty(long size, dtype d)
  {
    return empty(types::make_tuple(size), d);
  }

  DEFINE_FUNCTOR(pythonic::numpy, empty);
}
PYTHONIC_NS_END

#endif
