#ifndef PYTHONIC_CMATH_SQRT_HPP
#define PYTHONIC_CMATH_SQRT_HPP

#include "pythonic/include/cmath/sqrt.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/complex.hpp"

#include <cmath>

PYTHONIC_NS_BEGIN

namespace cmath
{
  DEFINE_FUNCTOR_2(sqrt, std::sqrt);
}
PYTHONIC_NS_END

#endif
