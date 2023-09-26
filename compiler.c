#include <stdio.h>
#include <string.h>
char prog[]; 
char interpreter_code[] = "int acc = 0; int main() {for (int i = 0; i < sizeof(prog); i++) {char c = prog[i];switch (c) {case 'i':acc++;break;case 'd':acc--;break;case 's':acc = acc * acc;break;case 'o':printf(\"%d \", acc);break;}}";
char file_content[];

int main(int argc, char* argv[]) {
    strcat(file_content, "#include <stdio.h>\nchar prog[] = \"");
    strcat(file_content, prog);
    strcat(file_content, "\";\n");
    strcat(file_content, interpreter_code);
    printf("%s", file_content);
    return 0;
}