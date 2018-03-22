#ifndef PYTHONIC_INCLUDE_NUMPY_RADIANS_HPP
#define PYTHONIC_INCLUDE_NUMPY_RADIANS_HPP

#include "pythonic/include/utils/functor.hpp"
#include "pythonic/include/types/ndarray.hpp"
#include "pythonic/include/utils/numpy_traits.hpp"
#include <boost/simd/function/inrad.hpp>

PYTHONIC_NS_BEGIN

namespace numpy
{
#define NUMPY_NARY_FUNC_NAME radians
#define NUMPY_NARY_FUNC_SYM boost::simd::inrad
#include "pythonic/include/types/numpy_nary_expr.hpp"
}
PYTHONIC_NS_END

#endif
