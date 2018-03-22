#ifndef PYTHONIC_INCLUDE_BUILTIN_DICT_HPP
#define PYTHONIC_INCLUDE_BUILTIN_DICT_HPP

#include "pythonic/include/types/dict.hpp"
#include "pythonic/include/utils/functor.hpp"

#include <tuple>
#include <utility>

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace anonymous
  {
    inline types::empty_dict dict();

    template <class Iterable>
    inline types::dict<typename std::tuple_element<
                           0, typename std::remove_reference<
                                  Iterable>::type::iterator::value_type>::type,
                       typename std::tuple_element<
                           1, typename std::remove_reference<
                                  Iterable>::type::iterator::value_type>::type>
    dict(Iterable &&iterable);
  }

  DECLARE_FUNCTOR(pythonic::__builtin__::anonymous, dict);
}
PYTHONIC_NS_END

#endif
