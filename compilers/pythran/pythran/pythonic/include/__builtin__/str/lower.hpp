#ifndef PYTHONIC_INCLUDE_BUILTIN_STR_LOWER_HPP
#define PYTHONIC_INCLUDE_BUILTIN_STR_LOWER_HPP

#include "pythonic/include/types/str.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace str
  {

    types::str lower(types::str const &s);

    DECLARE_FUNCTOR(pythonic::__builtin__::str, lower);
  }
}
PYTHONIC_NS_END
#endif
