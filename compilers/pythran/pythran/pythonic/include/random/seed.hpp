#ifndef PYTHONIC_INCLUDE_RANDOM_SEED_HPP
#define PYTHONIC_INCLUDE_RANDOM_SEED_HPP

#include "pythonic/include/utils/functor.hpp"
#include "pythonic/include/__builtin__/None.hpp"
#include "pythonic/include/random/random.hpp"

PYTHONIC_NS_BEGIN

namespace random
{
  types::none_type seed(long s);
  types::none_type seed();

  DECLARE_FUNCTOR(pythonic::random, seed);
}

PYTHONIC_NS_END

#endif
