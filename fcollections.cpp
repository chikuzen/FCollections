/********************************************************************************
    FCollections.dll
        AviSynth plugin to add some functions.

    Copyright (C) 2011 Motofumi Oka (chikuzen.mo at gmail dot com)

    authors : Motofumi Oka
              James D. Lin (Clamp() function)

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
******************************************************************************/
#include <stdio.h>
#include <math.h>
#include "windows.h"
#include "avisynth.h"

#pragma warning(disable:4996)
#define ERR_INT 2147483647


int timestring_to_millisecond(const char *tstr);
int gcd(int m, int n);
int lcm(int m, int n);
int fibonacci_number(const int n);


static AVSValue __cdecl avsTimeStrToMilliSec(AVSValue args, void*, IScriptEnvironment* env)
{
    const char *tstr = args[0].AsString("0:00:00.000");
    int msec;

    if ((msec = timestring_to_millisecond(tstr)) == ERR_INT)
        env->ThrowError("TimeStringToMilliSecond: Acceptable range is \"-99:59:59.999\" to \"99:59:59.999\".");

    return msec;
}


static AVSValue __cdecl avsGCD(AVSValue args, void*, IScriptEnvironment* env)
{
    const AVSValue& vals = args[0];
    const int n = vals.ArraySize();

    if (n < 2)
        env->ThrowError("GCD: Need two or more non-zero integers.");

    int num = vals[0].AsInt();

    for (int i = 1; i < n ; i++)
        num = gcd(num, vals[i].AsInt());

    if (!num)
        env->ThrowError("GCD: Need two or more non-zero integers.");
    return num;
}


static AVSValue __cdecl avsLCM(AVSValue args, void*, IScriptEnvironment* env)
{
    const AVSValue& vals = args[0];
    const int n = vals.ArraySize();
    int num = vals[0].AsInt();

    if (n < 2)
        env->ThrowError("LCM: Need two or more integers.");

    for (int i = 1; i < n; i++)
        num = lcm(num, vals[i].AsInt());

    if (!num)
        env->ThrowError("LCM: Need one or more non-zero integers.");

    return num;
}


static AVSValue __cdecl avsFibonacciNumber(AVSValue args, void*, IScriptEnvironment* env)
{
    const int n = args[0].AsInt(0);

    if (n < 0 || n > 46)
        env->ThrowError("Fibo: acceptable value range is an integer from 0 to 46.");

    return fibonacci_number(n);
}

static AVSValue __cdecl avsIsEven(AVSValue args, void*, IScriptEnvironment*)
{
    return !(args[0].AsInt() & 1);
}


static AVSValue __cdecl avsClamp(AVSValue args, void* , IScriptEnvironment* env)
{
    AVSValue v = args[0];
    const AVSValue& low = args[1];
    const AVSValue& high = args[2];

    if (low.AsFloat() > high.AsFloat())
        env->ThrowError("Clamp: low must be <= high");

    if (v.AsFloat() < low.AsFloat())
        v = low;
    else if (v.AsFloat() > high.AsFloat())
        v = high;

    return v;
}


extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit2(IScriptEnvironment* env)
{
    env->AddFunction("TimeStringToMilliSecond", "s", avsTimeStrToMilliSec, 0);
    env->AddFunction("TS2MS", "s", avsTimeStrToMilliSec, 0);
    env->AddFunction("GCD", "i+", avsGCD, 0);
    env->AddFunction("LCM", "i+", avsLCM, 0);
    env->AddFunction("IsEven", "i", avsIsEven, 0);
    env->AddFunction("Fibo", "i", avsFibonacciNumber, 0);
    env->AddFunction("Clamp", "fff", avsClamp, 0); //original by James D. Lin http://avisynth.org/stickboy/
    return 0;
}


int timestring_to_millisecond(const char *tstr)
{
    int sign = 1;
    unsigned int hh, mm;
    double ss;

    if (!strncmp(tstr, "-", 1)) {
        tstr++;
        sign = -1;
    }

    if (sscanf(tstr, "%u:%u:%lf", &hh, &mm, &ss) == EOF)
        return ERR_INT;
    if (hh > 99 || mm > 59 || ss > 60 || ss < 0)
        return ERR_INT;

    ss += hh * 3600 + mm * 60;

    return (int)(ss * 1000) * sign;
}


int gcd(int m, int n)
{
    if (!m || !n)
        return abs(m - n);

    int num1 = abs(m), num2 = abs(n);

    while (num1 != num2) {
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }

    return num1;
}


int lcm(int m, int n)
{
    if (!m || !n)
        return abs(m - n);

    return (abs(m) * abs(n)) / gcd(m, n);
}


int fibonacci_number(const int n)
{
    int fibonacci_siries[47] = {
                0,         1,         1,          2,          3,         5,
                8,        13,        21,         34,         55,        89,
              144,       233,       377,        610,        987,      1597,
             2584,      4181,      6765,      10946,      17711,     28657,
            46368,     75025,    121393,     196418,     317811,    514229,
           832040,   1346269,   2178309,    3524578,    5702887,   9227465,
         14930352,  24157817,  39088169,   63245986,  102334155, 165580141,
        267914296, 433494437, 701408733, 1134903170, 1836311903
    };

    return fibonacci_siries[n];
}
