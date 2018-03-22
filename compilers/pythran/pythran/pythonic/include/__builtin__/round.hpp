#ifndef PYTHONIC_INCLUDE_BUILTIN_ROUND_HPP
#define PYTHONIC_INCLUDE_BUILTIN_ROUND_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{
  template <class T>
  double round(T const &v, size_t n);

  template <class T>
  double round(T const &v);

  DECLARE_FUNCTOR(pythonic::__builtin__, round);
}
PYTHONIC_NS_END

#endif
