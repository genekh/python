#ifndef PYTHONIC_INCLUDE_BUILTIN_FILE_XREADLINES_HPP
#define PYTHONIC_INCLUDE_BUILTIN_FILE_XREADLINES_HPP

#include "pythonic/include/types/file.hpp"
#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace file
  {

    types::file &xreadlines(types::file &f);
    types::file &&xreadlines(types::file &&f);

    DECLARE_FUNCTOR(pythonic::__builtin__::file, xreadlines);
  }
}
PYTHONIC_NS_END
#endif
