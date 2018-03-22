#ifndef PYTHONIC_OPERATOR_POS_HPP
#define PYTHONIC_OPERATOR_POS_HPP

#include "pythonic/include/operator_/pos.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{

  template <class A>
  auto pos(A const &a) -> decltype(+a)
  {
    return +a;
  }

  DEFINE_FUNCTOR(pythonic::operator_, pos);
}
PYTHONIC_NS_END

#endif
