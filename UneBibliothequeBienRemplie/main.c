#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void vuln() {
    const char* FILENAME = "./dodo.txt";
    puts("*** Bienvenue dans la bibliothèque du café ***");
	puts("Quel livre voulez-vous lire ?");
	printf("> ");
    fflush(stdout);
    char input[20];
    fgets(input, 100000, stdin); /// 
	puts("Vous n'avez pas accès à ce livre. Voici une berceuse à la place : ");
	FILE* file = fopen(FILENAME, "r");
    if (! file) {
        fprintf(stderr, "Failed to open file %s : ", FILENAME);
        perror("");
        exit(1);
    }
	int c;
    while ((c = getc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
    fflush(stdout);
}

int main() {
    vuln();
    return 0;
}