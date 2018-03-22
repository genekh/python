#ifndef PYTHONIC_OPERATOR_IMATMUL_HPP
#define PYTHONIC_OPERATOR_IMATMUL_HPP

#include "pythonic/include/operator_/imatmul.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/numpy/dot.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{
  template <class A, class B>
  A imatmul(A const &a, B const &b)
  {
    return numpy::functor::dot{}(a, b);
  }

  template <class A, class B>
  A &imatmul(A &a, B const &b)
  {
    return a = numpy::functor::dot(a, b); // FIXME: improve that
  }

  DEFINE_FUNCTOR(pythonic::operator_, imatmul);
}
PYTHONIC_NS_END

#endif
