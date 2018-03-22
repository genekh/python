#ifndef PYTHONIC_OPERATOR_NOT_HPP
#define PYTHONIC_OPERATOR_NOT_HPP

#include "pythonic/include/operator_/not_.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{
  template <class T>
  decltype(!std::declval<T const &>()) not_(T const &a)
  {
    return !a;
  }
  template <class T>
  bool not_(std::complex<T> const &a)
  {
    return !a.real() && !a.imag();
  }

  DEFINE_FUNCTOR(pythonic::operator_, not_);
}
PYTHONIC_NS_END

#endif
