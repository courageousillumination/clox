#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum
{
    OP_RETURN,
    OP_CONSTANT,
    // Challenge exercise to support > 255 local variables.
    // NOTE: This stores as 32 bits instead of 24 (couldn't get
    // my pointer arithmatic up and running with 24).
    OP_CONSTANT_LONG,

    // Numeric operators
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,

    // Other constants
    OP_NIL,
    OP_TRUE,
    OP_FALSE,

    // Boolean operators
    OP_NOT,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,

    // Builtins
    OP_PRINT,
    OP_POP,
    OP_DEFINE_GLOBAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL,

    // Jump
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_LOOP,

    // Functions
    OP_CALL,
} OpCode;

typedef struct
{
    int count;
    int capacity;
    int *lines;
    uint8_t *code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);

int addConstant(Chunk *chunk, Value value);

/** Write a new constant, adding to the table as necessary */
void writeConstant(Chunk *chunk, Value value, int line);

#endif