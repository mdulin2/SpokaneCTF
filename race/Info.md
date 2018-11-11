Currently, there are two race conditions in here: race and race_fun.

The race was a proof of concept to ensure that this was possible.
The second one, race_fun (source code is in race2.c), is pretty sick!!

It uses multithreading to check if a number is prime or not. However, because the VALUE is not locked, then the amount of time that the prime checker takes is enough to change the value of VALUE in the input section. So, this creates a race condition that can be exploited.
