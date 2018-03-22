#ifndef PYTHONIC_INCLUDE_OPERATOR_POS_HPP
#define PYTHONIC_INCLUDE_OPERATOR_POS_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{

  template <class A>
  auto pos(A const &a) -> decltype(+a);

  DECLARE_FUNCTOR(pythonic::operator_, pos);
}
PYTHONIC_NS_END

#endif
