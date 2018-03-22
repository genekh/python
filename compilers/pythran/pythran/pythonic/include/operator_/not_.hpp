#ifndef PYTHONIC_INCLUDE_OPERATOR_NOT_HPP
#define PYTHONIC_INCLUDE_OPERATOR_NOT_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{
  template <class T>
  decltype(!std::declval<T const &>()) not_(T const &a);

  template <class T>
  bool not_(std::complex<T> const &a);

  DECLARE_FUNCTOR(pythonic::operator_, not_);
}
PYTHONIC_NS_END

#endif
