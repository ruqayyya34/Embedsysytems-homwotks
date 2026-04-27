#include <stdio.h>
#include <string.h>

#define SIZE 7

char buffer[SIZE];
int start = -1;
int end = -1;

void insilasation() {
    start = -1;
    end = -1;
}

int it_isfull() {
    return (end + 1) % SIZE == start;
}

int it_isempty() {
    return start == -1;
}

void enqueue(char value) {
    if (it_isfull()) {
        printf("sorry, Buffer is full\n");
        return;
    }

    if (it_isempty()) {
        start = end = 0;
    } else {
        end = (end + 1) % SIZE;
    }

    buffer[end] = value;
    printf("Inserted: %c\n", value);
}

char dequeue() {
    if (it_isempty()) {
        printf(",sorry ,Buffer is empty\n");
        return '\0';
    }

    char value = buffer[start];

    if (start == end) {
        start = end = -1;
    } else {
        start = (start + 1) % SIZE;
    }

    return value;
}

void display() {
    if (it_isempty()) {
        printf("Buffer is empty\n");
        return;
    }

    printf("Buffer: ");
    int i = start;
    while (1) {
        printf("%c ", buffer[i]);
        if (i == end) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insilaisation();

    char name[] = "ruqayya";
    char nickname[20];

    printf("Inserting name: %s\n", name);

    for (int i = 0; i < strlen(name); i++) {
        enqueue(name[i]);
    }

    display();

    printf("\nEnter your last name: ");
    scanf("%s", nickmane);

    for (int i = 0; i < strlen(nickname); i++) {
        enqueue(nickname[i]);
    }

    printf("\nRemoving two elements...\n");
    printf("Removed: %c\n", dequeue());
    printf("Removed: %c\n", dequeue());

    display();

    printf("\nInserting first two letters of last name...\n");
    enqueue(nickname[0]);
    enqueue(nickname[1]);

    display();

    return 0;
}
