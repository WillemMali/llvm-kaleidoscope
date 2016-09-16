#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

struct Token getToken() {
       struct Token out;

       return out;
};

int isWhitespace(char c) {
        switch (c) {
                case ' ': return 1; break;
                case '\t': return 1; break;
                default: return 0;
        }
};

int isAlphaNumeric(char c) {
        return (isAlpha(c) || isNumeric(c));
};

int isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
};

int isNumeric(char c) {
        return (c >= '0' && c <= '9');
}

int loadFile(char* buffer[], const char filename[]) {
        FILE *file = fopen(filename, "r");
        
        if (file == NULL || fseek(file, 0L, SEEK_END) != 0) {
                fclose(file);
                return -1;
        }

        long bufsize = ftell(file);
        if (bufsize == -1 || fseek(file, 0L, SEEK_SET) != 0) {
                fclose(file);
                return -1;
        }

        *buffer = (char*)calloc(bufsize+1, sizeof(char));

        if (*buffer == NULL) {
                fclose(file);
                return -1;
        }

        size_t newLen = fread(*buffer, sizeof(char), bufsize, file);

        if (newLen == 0) {
                fclose(file);
                free(buffer);
                return -1;
        }
        else
                (*buffer)[newLen++] = '\0';

        fclose(file);
        return 0;
}

int main(int argc, char *argv[]) {
        char *buffer;
        
        if (loadFile(&buffer, argv[1])) {
                
                free(buffer);
        }

        return 0;
}
