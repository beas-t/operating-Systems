#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

int findPage(int page, int *frames, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return i; 
        }
    }
    return -1;
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
        int index = findPage(page_reference[i], frames, NUM_FRAMES);
        if (index == -1) {
            
            int lru_index = 0;
            for (int j = 1; j < NUM_FRAMES; j++) {
                if (frames[j] < frames[lru_index]) {
                    lru_index = j;
                }
            }
            frames[lru_index] = page_reference[i];
            page_faults++;
        } else {
            
            int temp = frames[index];
            for (int j = index; j > 0; j--) {
                frames[j] = frames[j - 1];
            }
            frames[0] = temp;
        }
        printFrames(frames, NUM_FRAMES);
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
