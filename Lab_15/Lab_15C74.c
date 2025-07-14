// 74. Write a program to simulate music player application using suitable data 
// structure. There is no estimation about number of music files to be managed by 
// the music player. Your program should support a/ll the basic music player 
// operations to play and manage the playlist. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char song[20];
    struct node *lptr;
    struct node *rptr;
};

// create a node for doubly liked list
struct node* createNode(char s[20]) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    strcpy(newNode->song, s);
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    return newNode;
}

void insertANodeAtLast(char s[20], struct node **first) {
    struct node *newNode = createNode(s);

    if(*first == NULL) {
        *first = newNode;
        return;
    }

    struct node *save = *first;
    while(save->rptr != NULL) {
        save = save->rptr;
    }

    newNode->lptr = save;
    save->rptr = newNode;
}

void display(struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }

    struct node *save = first;
    while(save != NULL) {
        printf("%s -> ", save->song);
        save = save->rptr;
    }

    printf("NULL \n");
}

void play(struct node *first, struct node **current) {
    printf("current play : %s \n", first->song);
    *current = first;
}

void playNext(struct node **current) {
    *current = (*current)->rptr;
    if(*current == NULL) {
        printf("song pura thya gya bhai !\n");
        return;
    }
    printf("current play : %s \n", (*current)->song);
}

void playPre(struct node **current) {
    *current = (*current)->lptr;
    if(*current == NULL) {
        printf("song pura thya gya bhai !\n");
        return;
    }
    printf("current play : %s \n", (*current)->song);
}

void deletesong(struct node **first, char s[20]) {
    if(first == NULL) {
        printf("Song is not available \n");
        return;
    }

    struct node *save = *first;
    while (save != NULL) {
        if(strcmp(strlwr(save->song), strlwr(s)) == 0) {
            if(save->lptr) {
                save->lptr->rptr = save->rptr;
            }
            else {
                *first = save->rptr;
            }

            if(save->rptr) {
                save->rptr->lptr = save->lptr;
            }

            free(save);
            break;
        }
    }
}

int main() {
    int choice;
    char songname[20];
    struct node *playlist = NULL;
    struct node *current = NULL;

    do {
        printf("\nMusic Player Menu: \n");
        printf("1. Add Song\n2. Play Playlist\n3. Next Song\n4. Previous Song \n");
        printf("5. Delete Song\n6. Display Playlist \n 7. Exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter song name: ");
                scanf("%s \n", songname);
                insertANodeAtLast(songname, &playlist);
                break;
            case 2:
                play(playlist, &current);
                break;
            case 3:
                playNext(&current);
                break;
            case 4:
                playPre(&current);
                break;
            case 5:
                printf("Enter song name to delete: ");
                scanf("%s \n", songname);
                deletesong(&playlist, songname);
                break;
            case 6:
                display(playlist);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! \n");
        }
    } while (choice != 7);

    return 0;
}