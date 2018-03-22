#ifndef PYTHONIC_INCLUDE_TYPES_FLOAT_HPP
#define PYTHONIC_INCLUDE_TYPES_FLOAT_HPP

#include "pythonic/include/types/attr.hpp"
#include <cstddef>

PYTHONIC_NS_BEGIN
namespace __builtin__
{
  template <size_t AttributeID>
  double getattr(double self);
}
PYTHONIC_NS_END
#ifdef ENABLE_PYTHON_MODULE

#include "pythonic/python/core.hpp"

PYTHONIC_NS_BEGIN

template <>
struct to_python<double> {
  static PyObject *convert(double d);
};
template <>
struct to_python<float> {
  static PyObject *convert(float d);
};
template <>
struct from_python<double> {
  static bool is_convertible(PyObject *obj);
  static double convert(PyObject *obj);
};
template <>
struct from_python<float> {
  static bool is_convertible(PyObject *obj);
  static float convert(PyObject *obj);
};
PYTHONIC_NS_END

#endif

#endif
