typedef enum state {
    SEARCHING_START,
    SEARCHING_CMD,
    SEARCHING_LEN,
    SEARCHING_DATA,
    SEARCHING_END
} PARSER_STATE_T;

struct packet {
    char cmd;
    int length;
    char data[18];
};

int Parser_AddChar(char input, struct packet *packet);