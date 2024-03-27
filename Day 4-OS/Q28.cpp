#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        
        if (strstr(line, "unix") != NULL) {
            
            printf("%s", line);
        }
    }

    fclose(file);

    return 0;
}
