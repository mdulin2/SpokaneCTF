'''
Huffman Encoding, table creation and decoding file.
https://en.wikipedia.org/wiki/Huffman_coding
'''


import copy

bit_dict = {}
# Huffman Encoding
def decode(encode_dict, compressed_text):
    message = ""

    while compressed_text != "":

        substring, amount = get_substring(compressed_text, encode_dict)
        message += encode_dict.keys()[encode_dict.values().index(substring)]
        compressed_text = compressed_text[amount+1:]
    return message


def get_substring(string, encode_dict):
    substring = ""

    for i in range(len(string)):
        substring += string[i]

        if(substring in encode_dict.values()):
            return substring, i

# Compresses the text based upon the huffman encoding.
def encode(text, encode_dict):
    compressed_text = ""
    for char in text:
        compressed_text += str(encode_dict[char])
    return compressed_text

# A helper function for creating the huffman algorithm tree.
# Combines the last two frequentcies into one.
def combine(freq, char_count):
    # assumes a sorted list
    length = len(freq)
    last_item = freq.pop()
    second_to_last = freq.pop()
    new_item = (char_count, last_item[1] + second_to_last[1])
    freq.append(new_item)
    return freq, last_item, second_to_last

# Creates the huffman tree.
def get_key(freq):
    tree = make_tree(sort(freq))
    return bit_dict

# Create the tree to be traversed.
# freq is a list with the setup [(a,b),(a,b)...,(a,b)] where a is the character and b is the frequentcy.
def make_tree(freq):
    tree = {}
    tree_size = len(freq)
    for elt in freq:
        tree[elt[0]] = elt[1]
    for spot in range(tree_size -1):
        freq, last_item, second_to_last = combine(copy.deepcopy(freq), spot)
        freq = sort(freq)
        if spot == 1:
            print freq
        tree[spot] = (last_item[0], second_to_last[0])

    x =  traverse_tree(tree, spot)
    return traverse_tree(tree,spot)

# The function for traversing the free.
# tree is the tree created in the make tree function.
# root is the top of the tree.
def traverse_tree(tree,root):
    bit_dict[root] = ''
    return traverse_tree_helper(tree, root)

# Helper function for traverse tree.
def traverse_tree_helper(tree, spot):
    # Characters will always be the leafs points, while the assigned integers are always the inner nodes.
    if(type(tree[spot]) == float):
        return bit_dict
    else:
        bit_dict[tree[spot][0]] = bit_dict[spot] + '0'
        traverse_tree_helper(tree, tree[spot][0])
        bit_dict[tree[spot][1]] = bit_dict[spot] + '1'
        traverse_tree_helper(tree, tree[spot][1])

# Removes the non-leaf 'numbers' from the key-value mappping.
def strip_numbers():
    bit_dict_fixed = {}
    for elt in bit_dict:
        if(type(elt) != int):
            bit_dict_fixed[elt] = bit_dict[elt]
    return bit_dict_fixed

# Sorts a list of the format [(a,b)...(a,b)] where it is sorted on b, the frequentcy.
def sort(inlist):
    for i in range(len(inlist)):
        changed = False
        for j, x in enumerate(inlist[:-i-1]):
            if x[1] <= inlist[j + 1][1]:
                inlist[j], inlist[j + 1] = inlist[j + 1], inlist[j]
                changed = True

        if not changed:
            break
    print inlist
    return inlist

# Creates a frequentcy calculation based upon each character in the file.
# Returns a dictionary of char : frequentcy, key value mapping.
def eval_file(filename):
    char_count = {}
    total = 0
    file_content = open(filename, "r")
    for line in file_content.readlines():
        line += '\n'
        for char in line:
            total +=1
            if char in char_count:
                char_count[char] = char_count[char] +1
            else:
                char_count[char] = 1

    # calculates the percentage of the time a character occurs.
    for key in char_count:
        char_count[key] = char_count[key] / float(total)

    return char_count

# Convert the dictionary into a tree traversable object.
def dict_to_tuple_list(char_count):
    freq_list = []
    for key in char_count:
        freq_list.append((key, char_count[key]))
    return freq_list

# Imports the huffman table.
# Returns a dictionary of key-value mappings from char to encoding.
def import_key(filename):
    key = {}
    file_content = open(filename, "r")
    for line in file_content.readlines():
        line = line.strip("\n")
        line = line.split(" ")
        if(line[0] == '\\n'):
            print line
            line = ['\n', line[1]]
        elif(line[0] == '\s'):
            line = [' ', line[1]]
        key[line[0]] = line[1]

    return key

char_count = eval_file("bible.txt")
freq_list = dict_to_tuple_list(char_count)

encoding = get_key(freq_list)
bit_dict = strip_numbers()

# the challenge will need the bit_dict and the ciphered 0's and 1's. But, having an easy and automated way to create the challenges is nice and fun!
for elt in bit_dict:
    print elt, bit_dict[elt]

y = encode("""A guilty conscience needs no accuser. \n Why doesn't DOS ever say 'EXCELLENT command or filename'\n - Anonymous""", bit_dict)
print y
print decode(bit_dict,y)
