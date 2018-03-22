#ifndef PYTHONIC_NUMPY_DIAG_HPP
#define PYTHONIC_NUMPY_DIAG_HPP

#include "pythonic/include/numpy/diag.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/ndarray.hpp"
#include "pythonic/utils/numpy_conversion.hpp"
#include "pythonic/numpy/asarray.hpp"

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class T>
  types::ndarray<T, 1> diag(types::ndarray<T, 2> const &a, long k)
  {
    auto &&a_shape = a.shape();
    utils::shared_ref<types::raw_array<T>> buffer(
        std::max(a_shape[0], a_shape[1]));
    types::array<long, 1> shape = {0};
    auto iter = buffer->data;
    if (k >= 0)
      for (int i = 0, j = k; i < a_shape[0] && j < a_shape[1];
           ++i, ++j, ++shape[0])
        *iter++ = a[i][j];
    else
      for (int i = -k, j = 0; i < a_shape[0] && j < a_shape[1];
           ++i, ++j, ++shape[0])
        *iter++ = a[i][j];
    return types::ndarray<T, 1>(buffer, shape);
  }

  template <class T>
  types::ndarray<T, 2> diag(types::ndarray<T, 1> const &a, long k)
  {
    long n = a.flat_size() + std::abs(k);
    types::ndarray<T, 2> out(types::make_tuple(n, n), 0);
    if (k >= 0)
      for (long i = 0, j = k; i < n && j < n; ++i, ++j)
        out[i][j] = a[i];
    else
      for (long i = -k, j = 0; i < n && j < n; ++i, ++j)
        out[i][j] = a[j];
    return out;
  }

  template <class T>
  auto diag(types::list<T> const &a, long k) -> decltype(diag(asarray(a), k))
  {
    return diag(asarray(a), k);
  }

  NUMPY_EXPR_TO_NDARRAY0_IMPL(diag);
  DEFINE_FUNCTOR(pythonic::numpy, diag);
}
PYTHONIC_NS_END

#endif
