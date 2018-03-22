#ifndef PYTHONIC_OPERATOR_IS_HPP
#define PYTHONIC_OPERATOR_IS_HPP

#include "pythonic/include/operator_/is_.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{

  template <class A, class B>
  auto is_(A const &a, B const &b) -> decltype(a == b)
  {
    return a == b;
  }

  DEFINE_FUNCTOR(pythonic::operator_, is_);
}
PYTHONIC_NS_END

#endif
