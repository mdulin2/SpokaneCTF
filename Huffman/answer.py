# Everything that is needed in order to solve the challenge.

# Gets the huffman table from the file.
# Returns a dictionary of letter to bits mapping
def import_key(filename):
    key = {}
    file_content = open(filename, "r")
    for line in file_content.readlines():
        line = line.strip("\n")
        line = line.split(" ")
        if(line[0] == '\\n'):
            line = ['\n', line[1]]
        elif(line[0] == '\s'):
            line = [' ', line[1]]
        key[line[0]] = line[1]

    return key

# Helper function for import key
# Gets next character found in the binit stream.
def get_substring(string, encode_dict):
    substring = ""

    for i in range(len(string)):
        substring += string[i]
        if(substring in encode_dict.values()):
            return substring, i

# For decoding the huffman encoding
# encode_dict is the huffman table, compressed_text is the string of 1s and 0s.
def decode(encode_dict, compressed_text):
    message = ""

    while compressed_text != "":

        substring, amount = get_substring(compressed_text, encode_dict)
        message += encode_dict.keys()[encode_dict.values().index(substring)]
        compressed_text = compressed_text[amount+1:]
    return message

# Gets the cipher text message from a file
def get_message(filename):
    message = ""
    file_content = open(filename, "r")
    for line in file_content.readlines():
        message += line
    message = message.replace('\n','')
    return message

bit_dict = import_key("huffman")
cipher = get_message("cipher.txt")
flag = decode(bit_dict, cipher)
print flag
