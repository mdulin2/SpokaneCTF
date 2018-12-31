# Breaking RSA
RSA is a very well known asymmetric encryption algorithm. RSA is secure because of the difficulty of getting the factors out of a very large number. However, what if the keys are not large? The purpose of this challenge is to break the RSA key.

## Files:
- Challenge.md - The info to give to the user of the challenge.
- RSA.py - The implemented creation and solution to the challenge.
- Key_info.txt - The key information for the RSA key to decrypt.

## Exploit:

### RSA
Breaking RSA encryption requires an understanding of RSA. In RSA, there are a standard values that are used:  
- p and q: Prime numbers  
- n: p * q  
- tot(n): (p-1) * (q-1)
- e: A number that is relatively prime to tot(n)  
- d: The multiplicative inverse of e and tot(n)
- m: The message being sent  
- c: The encrypted message  

To encrypt:
- c = m^e mod n  

To decrypt:
- m = c^d mod n

Values are either known or unknown to the world:
- p and q: unknown
- n: known
- e: known
- d: unknown
- m: unknown
Better known as public key(e,n), private key(d)

### Breaking the protocol 
So, the main goal is to get d, in order to decrypt the message.   
Here are the steps to do this:   
1. Factor n for its primes. Because n is not very large, this should not be very difficult to do.
2. Now that we know p and q, we can derive tot(n) with (p-1) * (q-1).  
3. With the tot(n) and e, calculate the multiplicative inverse of these two numbers, which is d!
    - Calculating this is considered a very difficult problem. So, I suggest googling until you find out how to calculate this. There is an implementation in `RSA.py` with the function name `inverseMod`.  
4. Take c^d mod n, to get the flag.
