#include <stdio.h>
#include <windows.h>

DWORD WINAPI MyThread(LPVOID param) {
    printf("Hello from thread!\n");
    return 0;
}

int main() {
    // Thread example
    HANDLE hThread = CreateThread(NULL, 0, MyThread, NULL, 0, NULL);
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    // Process example (simpler version)
    printf("Launching Notepad...\n");
    int result = system("notepad");

    if (result == -1) {
        printf("Error: system() failed to run the command processor.\n");
    } else if (result != 0) {
        printf("Command ran, but returned non-zero exit code: %d\n", result);
    } else {
        printf("Command ran successfully.\n");
    }


    printf("Program finished.\n");

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
