﻿Pythran
#######

http://pythran.readthedocs.io

What is it?
-----------

Pythran is a Python to c++ compiler for a subset of the Python language, with a
focus on scientific computing. It takes a Python module annotated with a few
interface description and turns it into a native python module with the same
interface, but (hopefully) faster.

It is meant to efficiently compile **scientific programs**, and takes advantage
of multi-cores and SIMD instruction units.

Pythran supports Python **2.7** and also has a beta Python **3** support.

Installation
------------

Pythran sources are hosted on https://github.com/serge-sans-paille/pythran.

Pythran releases are hosted on http://pypi.python.org/pypi/pythran.

Pythran is available through Conda on https://conda.anaconda.org/serge-sans-paille.

Debian/Ubuntu
=============

Using ``pip``
*************

1. Gather dependencies:

   Pythran depends on a few Python modules and several C++ libraries. On a debian-like platform, run::

        $> sudo apt-get install libgmp-dev libatlas-base-dev
        $> sudo apt-get install python-dev python-ply python-networkx python-numpy

2. Use ``easy_install`` or ``pip``::

		$> pip install pythran

Using ``conda``
***************

1. Install ``conda``, following the instruction given in
   http://conda.pydata.org/docs/install/quick.html

2. Run::

       $> conda install -c serge-sans-paille pythran

Mac OSX
=======

Using brew (http://brew.sh/)::

    $> brew install gmp
    $> brew install cmake

    $> easy_install pip

    $> pip install numpy pythran

Depending on your setup, you may need to add the following to your \\~/.pythranrc`` file::

    [compiler]
    CXX=g++-4.9
    CC=gcc-4.9

ArchLinux
=========

Using `yaourt`::

    $> yaourt -S python2-pythran-git

Windows
=======

Windows support is on going and only targets Python 3.5+ with Visual Studio 2017.

    % pip install pythran


Other Platform
==============

See MANUAL file.


Basic Usage
-----------

A simple pythran input could be ``dprod.py``::

    """
    Naive dotproduct! Pythran supports numpy.dot
    """
    #pythran export dprod(int list, int list)
    def dprod(l0,l1):
    	"""WoW, generator expression, zip and sum."""
	return sum(x * y for x, y in zip(l0, l1))

To turn it into a native module, run::

	$> pythran dprod.py

That will generate a native dprod.so that can be imported just like the former
module::

    $> python -c 'import dprod' # this imports the native module instead


Documentation
-------------

The user documentation is available in the MANUAL file from the doc directory.

The developer documentation is available in the DEVGUIDE file from the doc
directory. The also is a TUTORIAL file for those who don't like reading
documentation.

A todo list is maintained in the eponymous TODO file.

The CLI documentation is available from the pythran help command::

	$> pythran --help

Some extra developer documentation is also available using pydoc. Beware, this
is the computer science incarnation for the famous Where's Waldo? game::

	$> pydoc pythran
	$> pydoc pythran.typing


Examples
--------

See the ``pythran/tests/cases/`` directory from the sources.


Contact
-------

Praise, flame and cookies:

- pythran@freelists.org -- register at http://www.freelists.org/list/pythran first!

- #pythran on FreeNode

- serge.guelton@telecom-bretagne.eu

The mailing list archive is available at http://www.freelists.org/archive/pythran/.

Citing
------

If you need to cite a Pythran paper, feel free to use::

    @article{guelton2015pythran,
      title={Pythran: Enabling static optimization of scientific python programs},
      author={Guelton, Serge and Brunet, Pierrick and Amini, Mehdi and Merlini,
                      Adrien and Corbillon, Xavier and Raynaud, Alan},
      journal={Computational Science \& Discovery},
      volume={8},
      number={1},
      pages={014001},
      year={2015},
      publisher={IOP Publishing}
    }


Authors
-------

See AUTHORS file.

License
-------

See LICENSE file.

