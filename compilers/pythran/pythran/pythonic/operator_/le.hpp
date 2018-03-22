#ifndef PYTHONIC_OPERATOR_LE_HPP
#define PYTHONIC_OPERATOR_LE_HPP

#include "pythonic/include/operator_/le.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{
  template <class A, class B>
  auto le(A const &a, B const &b) -> decltype(a <= b)
  {
    return a <= b;
  }

  DEFINE_FUNCTOR(pythonic::operator_, le);
}
PYTHONIC_NS_END

#endif
