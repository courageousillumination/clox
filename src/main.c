#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main()
{
    initVM();
    Chunk chunk;
    initChunk(&chunk);
    // Fill up the constants array to send us to long constant.
    for (int i = 0; i < 300; i++)
    {
        addConstant(&chunk, i);
    }

    writeConstant(&chunk, 555, 1);
    writeChunk(&chunk, OP_NEGATE, 1);
    writeChunk(&chunk, OP_RETURN, 1);

    interpret(&chunk);

    freeChunk(&chunk);
    freeVM();
    return 0;
}