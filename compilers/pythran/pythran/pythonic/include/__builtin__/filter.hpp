#ifndef PYTHONIC_INCLUDE_BUILTIN_FILTER_HPP
#define PYTHONIC_INCLUDE_BUILTIN_FILTER_HPP

#include "pythonic/include/types/list.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  template <class F, class Iterable>
  types::list<typename Iterable::iterator::value_type>
  filter(F const &f, Iterable const &iterable);

  DECLARE_FUNCTOR(pythonic::__builtin__, filter);
}
PYTHONIC_NS_END

#endif
