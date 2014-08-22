"""Robot Framework test library example that calls C code.

This example uses Python's standard `ctypes` module, which requires
that the C code is compiled into a shared library.

It is also possible to execute this file from the command line 
to test the C code manually.
"""

from ctypes import CDLL, c_char_p

#LIBRARY = CDLL('./coverage.so')  # On Windows we'd use '.dll'


def check_percentage(val):
    """Validates user name and password using imported shared C library."""
    
    val=int(val)

    if val>100:
        raise AssertionError('Value > 100 (given %d)'%(val))


if __name__ == '__main__':
    import sys
    try:
        check_percentage(*sys.argv[1:])
    except TypeError:
        print 'Usage:  %s decimal_value' % sys.argv[0]
    except AssertionError, err:
        print err
    else:
        print 'Good percentage'
