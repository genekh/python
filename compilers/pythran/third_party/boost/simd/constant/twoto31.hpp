//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTO31_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTO31_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Twoto31 Twoto31 (function template)

  Generates the constant \f$2^{31}\f$

  @headerref{<boost/simd/constant/twoto31.hpp>}

  @par Description

  1.  @code
      template<typename T> T Twoto31();
      @endcode

  2.  @code
      template<typename T> T Twoto31( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T that evaluates to (\f$2^{31}\f$).

  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to <tt>T(2147483648)</tt>.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/twoto31.hpp>
#include <boost/simd/constant/simd/twoto31.hpp>

#endif
