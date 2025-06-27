#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
    STARTUPINFOW si;

    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    //Pfad zum Programm der gestartet werden soll
    LPCWSTR appPath = L"C:\\Windows\\System32\\calc.exe"; // ersetzen durch programm das geöffnet werden soll

    //Prozess erstellen

    if (CreateProcessW(
        appPath,            //Anwendungspfad
        NULL,               //Befehlszeile kann auch Parameter enthalten
        NULL,               //Prozess Sicherheitsatributte 
        NULL,               //Thread Sicherheitsattribute
        FALSE,              //HANDLE Vererbung
        0,                  //Erstellungflags
        NULL,               //Umgebungsvariablen
        NULL,               //Arbeitsverzeichniss
        &si,                //Startupinfo
        &pi                 //prozessinfo
    )){
        Wprintf(L"Prozess erfolgreich erstellt PID: %lu\n", pi.dwProcessId);

        //optional
        WaitForSingleObject(pi.hProcess, INFINITE);

        //handles Schließen
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

    } else {
        wprintf("fehler beim erstellen des prozesses Fehler: %lu", GetLastError());
    }

    return 0;
}
