""" Check unary functions for the numpy module. """

import numpy

from test_env import TestEnv
from pythran.tables import MODULES
from pythran.intrinsic import UFunc
from pythran.typing import NDArray


@TestEnv.module
class TestNumpyUFuncBinary(TestEnv):
    pass

#automatic generation of basic test cases for ufunc
binary_ufunc = (k for k, v in MODULES["numpy"].items() if isinstance(v, UFunc))

for f in binary_ufunc:
    if 'bitwise_' in f or 'ldexp' in f or '_shift' in f :
        setattr(TestNumpyUFuncBinary, 'test_' + f, eval("lambda self: self.run_test('def np_{0}(a): from numpy import {0} ; return {0}(a,a)', numpy.ones(10, numpy.int32), np_{0}=[NDArray[numpy.int32,:]])".format(f)))
        setattr(TestNumpyUFuncBinary, 'test_' + f + '_scalar', eval("lambda self: self.run_test('def np_{0}_scalar(a): from numpy import {0} ; return {0}(a, a-1)', 1, np_{0}_scalar=[int])".format(f)))
        setattr(TestNumpyUFuncBinary, 'test_' + f + '_matrix', eval("lambda self: self.run_test('def np_{0}_matrix(a): from numpy import {0} ; return {0}(a,a)', numpy.ones((2,5), numpy.int32), np_{0}_matrix=[NDArray[numpy.int32, :, :]])".format(f)))
        # Tests for accumulation
        if f != "ldexp":
            # accumulate doesn't work with ldexp as typing is incorrect for
            # accumulation.
            setattr(TestNumpyUFuncBinary, 'test_accumulate_' + f, eval("lambda self: self.run_test('def np_{0}_accumulate(a): from numpy import {0} ; return {0}.accumulate(a)', numpy.ones(10, numpy.int32), np_{0}_accumulate=[NDArray[numpy.int32, :]])".format(f)))
            setattr(TestNumpyUFuncBinary, 'test_accumulate_' + f + '_matrix', eval("lambda self: self.run_test('def np_{0}_matrix_accumulate(a): from numpy import {0} ; return {0}.accumulate(a)', numpy.ones((2,5), numpy.int32), np_{0}_matrix_accumulate=[NDArray[numpy.int32,:,:]])".format(f)))
    else:
        setattr(TestNumpyUFuncBinary, 'test_' + f, eval("lambda self: self.run_test('def np_{0}(a): from numpy import {0} ; return {0}(a,a)', numpy.ones(10), np_{0}=[NDArray[float, :]])".format(f)))
        setattr(TestNumpyUFuncBinary, 'test_' + f + '_scalar', eval("lambda self: self.run_test('def np_{0}_scalar(a): from numpy import {0} ; return {0}(a+0.5, a+0.5)', 0.5, np_{0}_scalar=[float])".format(f)))
        setattr(TestNumpyUFuncBinary, 'test_' + f + '_matrix', eval("lambda self: self.run_test('def np_{0}_matrix(a): from numpy import {0} ; return {0}(a,a)', numpy.ones((2,5)) - 0.2 , np_{0}_matrix=[NDArray[float,:,:]])".format(f)))
        ## Tests for  complex numbers
        try:
            eval('numpy.{}(1.j, 1.j)'.format(f))
            setattr(TestNumpyUFuncBinary, 'test_' + f + '_complex', eval("lambda self: self.run_test('def np_{0}_complex(a): from numpy import {0} ; return {0}(a,a)', numpy.ones(10)*1.j, np_{0}_complex=[NDArray[complex, :]])".format(f)))
        except TypeError:
            pass

        ## Tests for accumulation
        setattr(TestNumpyUFuncBinary, 'test_accumulate_' + f, eval("lambda self: self.run_test('def np_{0}_accumulate(a): from numpy import {0} ; return {0}.accumulate(a)', numpy.ones(10), np_{0}_accumulate=[NDArray[float,:]])".format(f)))
        setattr(TestNumpyUFuncBinary, 'test_accumulate_' + f + '_matrix', eval("lambda self: self.run_test('def np_{0}_matrix_accumulate(a): from numpy import {0} ; return {0}.accumulate(a)', numpy.ones((2,5)) - 0.2 , np_{0}_matrix_accumulate=[NDArray[float, :, :]])".format(f)))
