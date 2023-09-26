#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char interpreter_code[] = "int acc = 0; int main() {for (int i = 0; i < strlen(prog); i++) {char c = prog[i];switch (c) {case 'i':acc++;break;case 'd':acc--;break;case 's':acc = acc * acc;break;case 'o':printf(\"%d \", acc);break;}if (acc >= 256 || acc < 0) {acc = 0;}}return 0;}";
char file_content[];
char ch[];

char* read_file(const char* filename) { // Definitely didn't copy this from stackoverflow
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening source file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    size_t result = fread(buffer, 1, file_size, file);
    if (result != file_size) {
        perror("Error reading source file");
        fclose(file);
        free(buffer);
        return NULL;
    }

    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}


int main(int argc, char* argv[]) {


    char* prog = read_file(argv[2]);

    for (int i = 0; i < strlen(prog); i++) {
        if (prog[i] == '\n') {
            prog[i] = ' ';
        }    
    }

    strcat(file_content, "#include <stdio.h>\nchar prog[] = \"");
    strcat(file_content, prog);
    strcat(file_content, "\";\n");
    strcat(file_content, interpreter_code);
    printf("%s", file_content);
    return 0;
}