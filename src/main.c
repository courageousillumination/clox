#include "common.h"
#include "chunk.h"
#include "debug.h"

int main()
{
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN, 1);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}