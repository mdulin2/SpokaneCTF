# Bypassing auth:
Stack overflows are quite common, even in todays world. The overflows found today must bypass ASLR, DEP and and a few other security mechanisms. This challenge has none of these security mechanisms turned on, allowing for a bread&butter stack overflow challenge. The goal of the challenge is to bypass the authentication check, using a stack overflow.

## Files:
auth.c - The challenge c file.
auth - T executable.
Challenge.md - The description for the user.
payload.sh - Max Dulin wrote a payload for his computer to exploit this.

## Exploit:
- First, figure out the vuln. By putting in too many characters, a seg fault is created...Or, by reading the source code, there is no check on the input size of the buffer.
- Second, figure out the offset. This can be done in GDB, by manually looking at the stack during execution or using something like patter.py. The offset should be 28 characters.
- Third, go into GDB to figure out the address of the function "do_valid_stuff". Do this by typing in `disas do_valid_stuff`. This will give you an address to jump the flow of the program to.
    - I use `disas do_valid_stuff`, then use the beginning address of the function to find this.
- Now, it is time to craft the exploit.
    - 1. Start with the offset. Print out 28 characters, because the offset was 28.
    - 2. Because the OS's Endian, we need to turn the Big Endian (i.e. 0x804848b) into little Endian (i.e. 0xbc840408).
    - 3. Since we are writing raw values to the stack, we need to use hex code to do this. In order to do this, we must write the characters prefaced with `\x`. So, in the example, turn `0xbc840408` into `\xbc\x84\x04\x08`. Add this value to the payload.
    - 4. If all is done write, you should have redirected execution of the program to where the flag is at, displaying the flag.
    - 5. My final payload is `python -c 'print "A" * 28 + "\xbc\x84\x04\x08"' | ./auth`.

## Further explanation:
- How the stack works:
    - On load of a function, the function address is pushed, followed by ebp then local variables (if needed).
    - Last on, first off style.
- Little Endian vs Big Endian:
    - https://chortle.ccsu.edu/AssemblyTutorial/Chapter-15/ass15_3.html
    - The location of the significance of the value. Most general number systems are little Endian (little end first) 1234 would be 1 x10^3+ 2x10^2 + 3x10^1 + 4x10^0 for instance. Big Endian would be 4x10^3....
- gdb:
    - This is a debugger
    - https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
