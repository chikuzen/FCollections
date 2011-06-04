FCollections.dll

    Copyright (C) 2011 Oka Motofumi (chikuzen.mo at gmail dot com)

    *Clamp() function was written by James D. Lin (http://avisynth.org/stickboy/)

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


WHAT'S THIS:
    This is an AviSynth plugin to add some functions.

REQUIREMENT:
    msvcr100.dll
    AviSynth2.5x or later
    SSE capable CPU

USAGE:

TimeStringToMilliSecond(string "time string")
TS2MS(string "time string")
    This function convert time string("xx:xx:xx.xxx") to millisecond.
    Acceptable range of time string is "-99:59:59.999" to "99:59:59.999".
    TS2MS() is a shortcut version of TimeStringToMilliSecond().
    TimeStringToMilliSecond("0:12:34.567") (or TS2MS("0:12:34.567")) will return 754567.


GCD(int val1, int val2, int val3, ...)
    Returns GCD(Greatest Common Divisor) of its arguments.
    GCD(125, 75, -50, 175) will return 25.


LCM(int val1, int val2, int val3, ...)
    Returns LCM(Lowest Common Multiple) of its arguments.
    LCM(125, 75, -50, 175) will return 5250.


Fibo(int n)
    Returns Fibonacci number(http://en.wikipedia.org/wiki/Fibonacci_number) of n.
    The value of acceptable n is an integer from 0 to 46(AviSynth script can't process over 2147483647).
    Fibo(10) will return 55.


IsEven(int n)
    Returns whether n is an even number. (type: bool)
    IsEven(12345) will return false.


Clamp(val, low, high)
    This is the same as the one of MinMax.dll by Stickboy.
    (see also http://avisynth.org/stickboy/ )
    Returns the value of val when constrained to the range [low, high].
    Clamp(4, 1.0, 9) will return 4
    Clamp(13, 1.0, 9) will return 9
    Clamp(0, 1.0, 9) will return 1.0


Sourcecode:
    https://github.com/chikuzen/FCollections
