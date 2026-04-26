
#include <stdio.h>
#include <string.h>

#define SIZE 5

char buffer[SIZE];
int start = -1;
int end = -1;

// insilaisation (Initialization)
void insilaisation() {
    start = -1;
    end = -1;
}

// فحص الامتلاء
int it_isfull() {
    return (end + 1) % SIZE == start;
}

// فحص الفراغ
int it_isempty() {
    return start == -1;
}

// إدخال
void enqueue(char value) {
    if (it_isfull()) {
        printf("Overflow! Buffer is full\n");
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

// إزالة
char dequeue() {
    if (it_isempty()) {
        printf("Underflow! Buffer is empty\n");
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

// عرض
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

    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    char text[] = "CE-ESY";

    for (int i = 0; i < strlen(text); i++) {
        enqueue(text[i]);
    }

    display();

    printf("Removed: %c\n", dequeue());
    printf("Removed: %c\n", dequeue());

    display();

    enqueue('X');
    enqueue('Y');

    display();

    return 0;
}
