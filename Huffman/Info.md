# Huffman Decoding data
Huffman encoding is a very common compression algorithm, that is used with zip files. In this challenge, the hackers are given the huffman table and the output string of the text, ran through the compression algorithm.
Written by Maxwell Dulin   

- answer.py: The solution to the problem in Python.
- cipher.txt: The output of the huffman encoding
- huffman: The huffman table associated with the cipher.txt compression.
- bible.txt: The wordset that the huffman algorithm was used to get character frequencies.
- Huff.py is the implementation of the huffman encoding algorithm (don't need to do this for the challenge)
- Challenge.md has the challenge that will be given to the hackers. The files given to the hackers will be the challenge file, huffman and cipher.txt.

# Answer:
Use the huffman decoding algorithm to get the original string from cipher.txt
- Step 1: Understand the huffman compression algorithm.
- Step 2: Import the huffman table using a key-value pair (replacing the \s and \n with space and newline characters)
- Step 3: Import the cipher.txt into a string.
- Step 4: Write the decoding algorithm:
    - Huffman has an interesting property about it: no individual complete table key (011010) is a substring of another key. So, once you see a value that is a key, then YOU KNOW this is the correct entry in the table.
    - Search character by character in the string. If the character is not a valid entry, then append the next character to the string and check again.
    - Once a valid entry is found, remove the characters that made up the valid entry from the string. Place the 'valid entry' from the key-value pair (letter 'a') into the flag value.
    - Repeat the process until the entire string of 0's and 1's is gone.
- The flag is the decoded string, which is below:
```
A guilty conscience needs no accuser.
 Why doesn't DOS ever say 'EXCELLENT command or filename'
 - Anonymous
```
