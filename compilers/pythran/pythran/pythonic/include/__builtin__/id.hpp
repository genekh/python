#ifndef PYTHONIC_INCLUDE_BUILTIN_ID_HPP
#define PYTHONIC_INCLUDE_BUILTIN_ID_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  template <class T>
  long id(T const &t);

  long id(long const &t);
  long id(double const &t);
  long id(bool const &t);

  DECLARE_FUNCTOR(pythonic::__builtin__, id);
}
PYTHONIC_NS_END

#endif
