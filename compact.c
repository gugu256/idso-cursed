#include <stdio.h>
char prog[] = "";
int acc = 0; int main() {for (int i = 0; i < sizeof(prog); i++) {char c = prog[i];switch (c) {case 'i':acc++;break;case 'd':acc--;break;case 's':acc = acc * acc;break;case 'o':printf("%d ", acc);break;}}return 0;}