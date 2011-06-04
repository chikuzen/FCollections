LoadPlugin("FCollections.dll")
BlankClip()
timestr = "-0:12:34.567"
array1 = "(12, 34, 56, 78, 90)"
n = 38
clamp = "Clamp(10, 16, 235)"
val1 = TimeStringToMilliSecond(timestr)
val2 = TS2MS(timestr) # same as TimeStringToMilliSecond(string "time string")
val3 = Eval("GCD" + array1)
val4 = Eval("LCM" + array1)
val5 = IsEven(last.width())
val6 = Fibo(n)
val7 = Eval(clamp)
y = 32
Subtitle("TimeStringToMilliSecond() converts " + timestr + " to " + string(val1) + ".", y = y * 1)
Subtitle("TS2MS() converts " + timestr + " to " + string(val2) + ".", y = y * 2)
Subtitle("GCD of " + array1 + " is "+ string(val3) + ".", y = y * 3)
Subtitle("LCM of " + array1 + " is " + string(val4) + ".", y = y * 4)
Subtitle("Width of this clip is " + (val5 ? "even" : "odd") + ".", y = y * 5)
Subtitle("Fibonacci number of " + string(n) + " is " + string(val6) + ".", y = y * 6)
Subtitle(clamp + " returns " + string(val7) + ".", y = y * 7)
return last
