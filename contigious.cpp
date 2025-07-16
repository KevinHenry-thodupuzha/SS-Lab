#include <stdio.h>
#include <string.h>

// File structure
struct File {
    char name[20];
    int start;
    int blocks;
};

// Function to allocate file
void allocateFile(struct File* f, const char* name, int start, int blocks) {
    strcpy(f->name, name);
    f->start = start;
    f->blocks = blocks;
}

// Main function
int main() {
    struct File myFile;

    // Allocate file
    allocateFile(&myFile, "data.txt", 5, 4);

    // Display file info
    printf("File Name: %s\n", myFile.name);
    printf("Start Block: %d\n", myFile.start);
    printf("Number of Blocks: %d\n", myFile.blocks);

    return 0;
} 
