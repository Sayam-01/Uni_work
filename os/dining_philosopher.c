#include <stdio.h>
#include <windows.h>

#define N 3         // number of philosophers
#define EAT_COUNT 2 // number of times each philosopher eats
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
int eatTimes[N] = {0};

HANDLE mutex;
HANDLE sem[N];

int left(int i) { return (i + N - 1) % N; }
int right(int i) { return (i + 1) % N; }

void test(int i) {
    if (state[i] == HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING) {
        state[i] = EATING;
        ReleaseSemaphore(sem[i], 1, NULL);
    }
}

void take_forks(int i) {
    WaitForSingleObject(mutex, INFINITE);
    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i);
    test(i);
    ReleaseSemaphore(mutex, 1, NULL);
    WaitForSingleObject(sem[i], INFINITE);
}

void put_forks(int i) {
    WaitForSingleObject(mutex, INFINITE);
    state[i] = THINKING;
    eatTimes[i]++;
    printf("Philosopher %d finished EATING (%d/%d)\n", i, eatTimes[i], EAT_COUNT);
    test(left(i));
    test(right(i));
    ReleaseSemaphore(mutex, 1, NULL);
}

DWORD WINAPI philosopher(LPVOID num) {
    int i = *(int*)num;
    while (eatTimes[i] < EAT_COUNT) {
        printf("Philosopher %d is THINKING\n", i);
        Sleep(rand() % 500 + 300); // shorter thinking time
        take_forks(i);
        printf("Philosopher %d is EATING\n", i);
        Sleep(rand() % 500 + 300); // shorter eating time
        put_forks(i);
    }
    return 0;
}

int main() {
    HANDLE threads[N];
    int phil[N];

    mutex = CreateSemaphore(NULL, 1, 1, NULL);
    for (int i = 0; i < N; i++) {
        sem[i] = CreateSemaphore(NULL, 0, 1, NULL);
        phil[i] = i;
    }

    for (int i = 0; i < N; i++)
        threads[i] = CreateThread(NULL, 0, philosopher, &phil[i], 0, NULL);

    WaitForMultipleObjects(N, threads, TRUE, INFINITE);

    for (int i = 0; i < N; i++) {
        CloseHandle(threads[i]);
        CloseHandle(sem[i]);
    }
    CloseHandle(mutex);

    printf("All philosophers have finished eating %d times.\n", EAT_COUNT);
    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
