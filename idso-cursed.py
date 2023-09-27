from sys import argv
import os

interpreter_code = "int acc = 0; int main() {for (int i = 0; i < strlen(prog); i++) {char c = prog[i];switch (c) {case 'i':acc++;break;case 'd':acc--;break;case 's':acc = acc * acc;break;case 'o':printf(\"%d \", acc);break;}if (acc >= 256 || acc < 0) {acc = 0;}}return 0;}"
file_content = "#include <stdio.h>\n#include <string.h>\nchar prog[] = \""

with open(argv[2], "r") as f:
    file_content += (f.read() + "\"; " + interpreter_code)

with open(argv[1] + ".c", "w") as f:
    f.write(file_content)

os.system("gcc -o " + argv[1] + " " + argv[1] + ".c")
os.remove(argv[1] + ".c") # Cleanup