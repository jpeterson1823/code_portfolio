import sys, pathlib

DEBUG = False

# check for file command line argument
if len(sys.argv) < 2:
    print("Error: Invalid number of arguments. Path to file not provided.")
    exit()

# create pathlib object
path = pathlib.Path(sys.argv[1]);

# check to make sure path exists
if not path.exists():
    print("Error: Path provided does not exist:\n\t%s" % sys.argv[1])
    exit()

# check to make sure path leads to a file
if not path.is_file():
    print("Error: Path provided does not lead to a file:\n\t%s" % sys.argv[1])
    exit()

# check to make sure file is a brainfuck file
if path.suffix != ".bf":
    print("Error: Path points to file of non-brainfuck filetype:\n\t%s", sys.argv[1])
    exit()




# if everything checks out, read the file into a string of commands
bf = ""
with open(path.absolute(), "r") as f:
    bf = f.read()

# remove every character that is not a bf command
bf = "".join([c for c in bf if c in ["+", "-", "<", ">", "[", "]", ".", ","]])


# create memory simulation (100 bits long) and its pointer
size = 99
mem = [ 0 for _ in range(size + 1) ]
p = 0;
allocd = []
loop_index_stack = []

# display output header
print("==========[  PROGRAM OUTPUT  ]==========", end="\n\n")

# read every command and perform an action
index = 0
while index < len(bf):
    c = bf[index]
    
    # "allocate memory" of new byte if needed
    if p not in allocd: 
        allocd.append(p)

    # print byte value at p
    if   c == ".":
        if DEBUG: print("%s: %i" % (hex(p), mem[p]))
        else: print("%c" % chr(mem[p]), end="")
    
    # take one byte of input
    elif c == ",":
        # get and sanitize input
        byte = int(input("INPUT REQUIRED: "))
        while byte > 255:
            byte = int(input("Size of input limited to 1 byte.\nInput: "))

        # store input in memory at p
        mem[p] = byte

    # increment value at p
    elif c == '+': 
        mem[p] += 1
    
    # decrement value at p
    elif c == '-':
        mem[p] -= 1

    # move pointer right if not at end
    elif c == '>':
        if p != size: p += 1
    
    # move pointer left (if not at beginning)
    elif c == '<':
        if p != 0: p -= 1

    # add loop to stack
    elif c == "[":
        loop_index_stack.append(index)
    
    # if memory at p is equal to 0, end loop
    elif c == "]":
        if len(loop_index_stack) != 0:
            if mem[p] == 0:     # end loop
                # remove [ index from stack
                loop_index_stack.pop()
            else:               # continue loop
                # set i to the index of last [ encountered
                index = loop_index_stack[-1]

    # increment index counter
    index += 1

# if not in debug mode, add return character
print()
# display program termination message
print("==========[    TERMINATED    ]==========", end="\n\n")

# display parsed code if in debug mode
if DEBUG: print("***** Raw brainfuck Code\n%s\n*****" % bf)

# display memory array up to last alloc'd byte and current pointer
print("Final Memory Array    : \t %s" % str(mem[:max(allocd)+1]))
print("Final Pointer Address : \t %s" % hex(p))
print("Final Allocated Memory: \t %i bytes" % len(allocd))