#ifndef PYTHONIC_INCLUDE_OPERATOR_INDEXOF_HPP
#define PYTHONIC_INCLUDE_OPERATOR_INDEXOF_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{

  template <class A, class B>
  long indexOf(A const &a, B const &b);

  DECLARE_FUNCTOR(pythonic::operator_, indexOf);
}
PYTHONIC_NS_END

#endif
