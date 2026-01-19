#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

HANDLE emptySlots;  // Semaphore counting empty slots
HANDLE fullSlots;   // Semaphore counting full slots
HANDLE mutex;       // Mutex to protect buffer

DWORD WINAPI Producer(LPVOID param) {
    int item;
    for (int i = 0; i < 10; i++) { // Produce 10 items
        item = i + 1; // Simple item

        WaitForSingleObject(emptySlots, INFINITE); // Wait if buffer is full
        WaitForSingleObject(mutex, INFINITE);      // Enter critical section

        buffer[in] = item;
        printf("Produced: %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        ReleaseSemaphore(mutex, 1, NULL);          // Leave critical section
        ReleaseSemaphore(fullSlots, 1, NULL);      // Signal a full slot

        Sleep(100); // simulate time to produce
    }
    return 0;
}

DWORD WINAPI Consumer(LPVOID param) {
    int item;
    for (int i = 0; i < 10; i++) { // Consume 10 items
        WaitForSingleObject(fullSlots, INFINITE); // Wait if buffer is empty
        WaitForSingleObject(mutex, INFINITE);     // Enter critical section

        item = buffer[out];
        printf("Consumed: %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        ReleaseSemaphore(mutex, 1, NULL);         // Leave critical section
        ReleaseSemaphore(emptySlots, 1, NULL);    // Signal an empty slot

        Sleep(150); // simulate time to consume
    }
    return 0;
}

int main() {
    HANDLE hProducer, hConsumer;

    // Initialize semaphores
    emptySlots = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL); // all slots empty initially
    fullSlots  = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);           // no full slots initially
    mutex      = CreateSemaphore(NULL, 1, 1, NULL);                     // mutex for critical section

    // Create threads
    hProducer = CreateThread(NULL, 0, Producer, NULL, 0, NULL);
    hConsumer = CreateThread(NULL, 0, Consumer, NULL, 0, NULL);

    // Wait for threads to finish
    WaitForSingleObject(hProducer, INFINITE);
    WaitForSingleObject(hConsumer, INFINITE);

    // Close handles
    CloseHandle(hProducer);
    CloseHandle(hConsumer);
    CloseHandle(emptySlots);
    CloseHandle(fullSlots);
    CloseHandle(mutex);

    printf("Producer-Consumer simulation completed.\n");
    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
