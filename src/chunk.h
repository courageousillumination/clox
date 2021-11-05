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