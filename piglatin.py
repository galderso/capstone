def translate(word):
    if word[0] in ['a','e','i','o','u']:
        pword=word+"yay"
    else:
        pword=word[1:]+word[0]+"ay"
    return pword

def read_input(file_name):
    f =open("file_name","r")
    line_list=[line.split() for line in f]
    return line_list

def parse_lines(line):
    for word in line:
        pline=pline+translate(word)
    return pline

def parse_all_lines(lines):

if __name__ == "__main__":
file_name = input()
lines = read_input(file_name)
if len(lines) == 0:
    print("Unable to open input file.")
else:
    for line in parse_lines(lines):
        print(line)