#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Playlist
struct Song {
    char name[50];
    struct Song* next;
};

// Function to create a new song node
struct Song* createSong(char* name) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = newSong;  // circular link
    return newSong;
}

// Function to print playlist
void printPlaylist(struct Song* head) {
    if (head == NULL) {
        printf("\nPlaylist is empty\n");
        return;
    }
    struct Song* temp = head;
    printf("\nPlaylist: ");
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %s)\n", head->name);
}

// Function to play forward (circular)
void playForward(struct Song* head, int n) {
    if (head == NULL) return;
    struct Song* temp = head;
    printf("\nPlaying forward:\n");
    for (int i = 0; i < n; i++) {
        printf("Now playing: %s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    // Creating songs
    struct Song* song1 = createSong("Song A");
    struct Song* song2 = createSong("Song B");
    struct Song* song3 = createSong("Song C");

    // Linking songs (Circular Linked List)
    song1->next = song2;
    song2->next = song3;
    song3->next = song1;  // circular link

    // Head of playlist
    struct Song* head = song1;

    // Show playlist
    printPlaylist(head);

    // Play forward (loop around 5 times)
    playForward(head, 5);

    return 0;
}
