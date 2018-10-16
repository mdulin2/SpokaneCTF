import re

def hang():
    password = "happpydays"

    input_name = "Give me a username!"
    password = raw_input("Give me a password: ")
    #password = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    regex = re.compile("""^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$""")


    m = regex.match(password)
    print m.group()

def normal():
    password = "happpydays"

    input_name = "Give me a username!"
    password = raw_input("Give me a password")
    #password = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    regex = re.compile("""[a-zA-Z0-9]""")
    m = regex.match(password)

hang()
