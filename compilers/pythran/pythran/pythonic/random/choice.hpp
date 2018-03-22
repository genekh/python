#ifndef PYTHONIC_RANDOM_CHOICE_HPP
#define PYTHONIC_RANDOM_CHOICE_HPP

#include "pythonic/include/random/choice.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/random/random.hpp"

PYTHONIC_NS_BEGIN

namespace random
{

  template <class Seq>
  typename Seq::value_type choice(Seq const &seq)
  {
    return seq[long(random() * seq.size())];
  }

  DEFINE_FUNCTOR(pythonic::random, choice);
}
PYTHONIC_NS_END

#endif
