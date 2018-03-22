#ifndef PYTHONIC_BUILTIN_STR_STARTSWITH_HPP
#define PYTHONIC_BUILTIN_STR_STARTSWITH_HPP

#include "pythonic/include/__builtin__/str/startswith.hpp"

#include "pythonic/types/str.hpp"
#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace str
  {

    bool startswith(types::str const &s, types::str const &prefix, long start,
                    long end)
    {
      if (end < 0)
        end = s.size();
      return (end - start) >= prefix.size() &&
             s.compare(start, prefix.size(), prefix) == 0;
    }

    DEFINE_FUNCTOR(pythonic::__builtin__::str, startswith);
  }
}
PYTHONIC_NS_END
#endif
