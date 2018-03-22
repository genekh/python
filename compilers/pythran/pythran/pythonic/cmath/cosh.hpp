#ifndef PYTHONIC_CMATH_COSH_HPP
#define PYTHONIC_CMATH_COSH_HPP

#include "pythonic/include/cmath/cosh.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/complex.hpp"

#include <cmath>

PYTHONIC_NS_BEGIN

namespace cmath
{
  DEFINE_FUNCTOR_2(cosh, std::cosh);
}
PYTHONIC_NS_END

#endif
