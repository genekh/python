#ifndef PYTHONIC_INCLUDE_BUILTIN_OCT_HPP
#define PYTHONIC_INCLUDE_BUILTIN_OCT_HPP

#include "pythonic/include/types/str.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{
  template <class T>
  types::str oct(T const &v);

  DECLARE_FUNCTOR(pythonic::__builtin__, oct);
}
PYTHONIC_NS_END

#endif
