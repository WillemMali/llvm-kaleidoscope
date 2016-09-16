/* The lexer returns tokens [0-255] if it is an unknown character,
** otherwise one of these for known things */
enum TokenID {
        TOKEN_EOF = -1,

        TOKEN_DEF = -2,
        TOKEN_EXTERN = -3,

        TOKEN_IDENTIFIER = -4,
        TOKEN_NUM = -5,
};

struct Token {
        enum TokenID tokenID;
        char* identifierString;
        double numVal;
};

int isAlphaNumeric(char c);
int isAlpha(char c);
int isNumeric(char c);
int loadFile(char* buffer[], const char filename[]);
