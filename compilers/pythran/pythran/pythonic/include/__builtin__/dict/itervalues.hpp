#ifndef PYTHONIC_INCLUDE_BUILTIN_DICT_ITERVALUES_HPP
#define PYTHONIC_INCLUDE_BUILTIN_DICT_ITERVALUES_HPP

#include "pythonic/types/dict.hpp"
#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace dict
  {

    template <class K, class V>
    auto itervalues(types::dict<K, V> d) -> decltype(d.itervalues());

    DECLARE_FUNCTOR(pythonic::__builtin__::dict, itervalues);
  }
}
PYTHONIC_NS_END

#endif
