
enum error_t {
    OK = 0,
    READING_FROM_EMPTY = -1,
    WRITING_TO_FULL = -2
};
typedef enum error_t error_t;

void init();

error_t write(uint16_t e);

error_t read(uint16_t *e);

int is_full();

int is_empty();

void clear();