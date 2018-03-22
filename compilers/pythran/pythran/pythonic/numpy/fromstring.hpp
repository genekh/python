#ifndef PYTHONIC_NUMPY_FROMSTRING_HPP
#define PYTHONIC_NUMPY_FROMSTRING_HPP

#include "pythonic/include/numpy/fromstring.hpp"

#include "pythonic/utils/functor.hpp"
#include "pythonic/types/ndarray.hpp"
#include "pythonic/types/list.hpp"

#include <limits>
#include <sstream>

PYTHONIC_NS_BEGIN

namespace numpy
{
  template <class dtype>
  types::ndarray<typename dtype::type, 1> fromstring(types::str const &string,
                                                     dtype d, long count,
                                                     types::str const &sep)
  {
    if (sep) {
      types::list<typename dtype::type> res(0);
      if (count < 0)
        count = std::numeric_limits<long>::max();
      else
        res.reserve(count);
      size_t current;
      size_t next = -1;
      long numsplit = 0;
      do {
        current = next + 1;
        next = string.find_first_of(sep, current);
        typename dtype::type item;
        std::istringstream iss(
            string.substr(current, next - current).get_data());
        iss >> item;
        res.push_back(item);
      } while (next != types::str::npos && ++numsplit < count);
      return {res};
    } else {
      if (count < 0)
        count = string.size();
      types::array<long, 1> shape = {count};
      utils::shared_ref<types::raw_array<typename dtype::type>> buffer(
          shape[0]);
      auto const *tstring =
          reinterpret_cast<typename dtype::type const *>(string.c_str());
      std::copy(tstring, tstring + shape[0], buffer->data);
      return {buffer, shape};
    }
  }

  DEFINE_FUNCTOR(pythonic::numpy, fromstring);
}
PYTHONIC_NS_END

#endif
