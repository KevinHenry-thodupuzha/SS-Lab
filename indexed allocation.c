#include <stdio.h>

#define MAX_BLOCKS 100

// Structure for index block of a file
struct FileIndex {
    int blocks[MAX_BLOCKS];
};

// Initialize all blocks to -1 (empty)
void initialize(struct FileIndex* file) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file->blocks[i] = -1;
    }
}

// Add a block to the file
int addBlock(struct FileIndex* file, int blockNumber) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file->blocks[i] == -1) {  // Find first empty slot
            file->blocks[i] = blockNumber;
            return 1;  // Success
        }
    }
    return 0;  // No space
}

// Read a block from the file
void readBlock(struct FileIndex* file, int blockNumber) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (file->blocks[i] == blockNumber) {
            printf("Reading from block %d\n", blockNumber);
            return;
        }
    }
    printf("Block %d is not allocated.\n", blockNumber);
}

int main() {
    struct FileIndex myFile;

    initialize(&myFile);  // Start with all blocks empty

    // Allocate 3 blocks
    addBlock(&myFile, 5);
    addBlock(&myFile, 8);
    addBlock(&myFile, 12);

    // Read from blocks
    readBlock(&myFile, 5);   // Allocated
    readBlock(&myFile, 8);   // Allocated
    readBlock(&myFile, 10);  // Not allocated

    return 0;
} 
