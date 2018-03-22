#  f90wrap: F90 to Python interface generator with derived type support
#
#  Copyright James Kermode 2011-2018
#
#  This file is part of f90wrap
#  For the latest version see github.com/jameskermode/f90wrap
#
#  f90wrap is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  f90wrap is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with f90wrap. If not, see <http://www.gnu.org/licenses/>.
# 
#  If you would like to license the source code under different terms,
#  please contact James Kermode, james.kermode@gmail.com
from __future__ import print_function

#=======================================================================
#           simple test for f90wrap 
#=======================================================================


import numpy as np

#=======================================================================
#the first import is a subroutine, the second is a module)
#=======================================================================

from mockdt import *

#=======================================================================
# call a "top-level" subroutine. This refers to subroutines that are 
# present outside of modules, and do not operate on derived types AFAIK
#=======================================================================

#This particular routine sets some numeric constants 
assign_constants()

#=======================================================================
#Check if the subroutine worked : it modifies the "precision" module 
#variables
#=======================================================================

assert(precision.zero   == 0.0)
assert(precision.one    == 1.0)
assert(precision.two    == 2.0)
assert(precision.three  == 3.0)
assert(precision.four   == 4.0)

assert(precision.half   == 0.5)

#"acid" test for trailing digits, double precision: nonterminating, nonrepeating
assert(precision.pi     == np.pi)
print('1,2,3,4 as done by subroutine are ')
print(precision.one,precision.two, precision.three,precision.four)

#=======================================================================
#           Declare the SolverOptions derived type
#=======================================================================

Options =  Defineallproperties.SolverOptionsDef()

print(type(Options.airframevib))
Options.airframevib = 0
Options.fet_qddot   = 1

#=======================================================================
#           Set default values for this derived type
#=======================================================================

set_defaults(Options)
assert(Options.airframevib           == 1)
assert(Options.fet_qddot             == 0)
assert(Options.fusharm               == 0)
assert(Options.fet_response          == 0)
assert(Options.store_fet_responsejac == 0)

print('all tests passed, OK!')

