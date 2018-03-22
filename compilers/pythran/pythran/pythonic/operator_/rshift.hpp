#ifndef PYTHONIC_OPERATOR_RSHIFT_HPP
#define PYTHONIC_OPERATOR_RSHIFT_HPP

#include "pythonic/include/operator_/rshift.hpp"
#include "pythonic/operator_/overloads.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{
  template <class A, class B>
  auto rshift(A const &a, B const &b) -> decltype(a >> b)
  {
    return a >> b;
  }

  DEFINE_ALL_OPERATOR_OVERLOADS_IMPL(rshift, >> )

  DEFINE_FUNCTOR(pythonic::operator_, rshift);
}
PYTHONIC_NS_END

#endif
