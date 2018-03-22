#ifndef PYTHONIC_NUMPY_SHAPE_HPP
#define PYTHONIC_NUMPY_SHAPE_HPP

#include "pythonic/include/numpy/shape.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/ndarray.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{

  template <class E>
  auto shape(E const &e) -> decltype(e.shape())
  {
    return e.shape();
  }

  DEFINE_FUNCTOR(pythonic::numpy, shape)
}
PYTHONIC_NS_END

#endif
