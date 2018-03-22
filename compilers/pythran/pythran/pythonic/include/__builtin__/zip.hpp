#ifndef PYTHONIC_INCLUDE_BUILTIN_ZIP_HPP
#define PYTHONIC_INCLUDE_BUILTIN_ZIP_HPP

#include "pythonic/include/types/list.hpp"
#include "pythonic/include/types/tuple.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  template <class... Lists>
  auto zip(Lists &&... lists)
      -> types::list<decltype(types::make_tuple(*lists.begin()...))>;

  types::empty_list zip();

  DECLARE_FUNCTOR(pythonic::__builtin__, zip);
}
PYTHONIC_NS_END

#endif
