#include <stdio.h>
#include <stdlib.h>
#define NUM_FRAMES 3
#define NUM_PAGES 10

int findPage(int page, int *frames, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return 1; 
        }
    }
    return 0; 
}


void printFrames(int *frames, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int frames[NUM_FRAMES] = {-1}; 
    int page_reference[] = {0, 1, 2, 3, 0, 4, 5, 1, 6, 7}; 
    int page_faults = 0;

    for (int i = 0; i < NUM_PAGES; i++) {
        printf("Reference: %d\n", page_reference[i]);
        if (!findPage(page_reference[i], frames, NUM_FRAMES)) {
            
            frames[page_faults % NUM_FRAMES] = page_reference[i];
            page_faults++;
        }
        printFrames(frames, NUM_FRAMES);
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
