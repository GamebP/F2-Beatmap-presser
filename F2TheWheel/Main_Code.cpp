#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <random>
#include <ctime> // For std::time
#include <Windows.h> // For Windows API functions

void pressF2(int n, int& count) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    // Press F2 key
    input.ki.wVk = VK_F2;
    input.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &input, sizeof(INPUT));

    // Simulate pressing F2 key 'n' times
    for (int i = 0; i < n; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Sleep for 300 milliseconds before each F2 press
        input.ki.dwFlags = KEYEVENTF_KEYUP; // Key release
        SendInput(1, &input, sizeof(INPUT));
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Sleep for a brief duration before pressing again
        input.ki.dwFlags = 0; // Key press
        SendInput(1, &input, sizeof(INPUT));
        ++count;
        std::cout << "F2 Press #" << count << std::endl; // Print the count
    }

    // Release F2 key
    input.ki.wVk = VK_F2;
    input.ki.dwFlags = KEYEVENTF_KEYUP; // Key release
    SendInput(1, &input, sizeof(INPUT));
}

bool isOsuFocused() {
    // Get the handle of the foreground window
    HWND foregroundWindow = GetForegroundWindow();

    // Get the length of the window title
    int length = GetWindowTextLength(foregroundWindow);

    // Create a buffer to hold the window title
    std::string title;
    title.resize(length + 1);

    // Get the window title
    GetWindowTextA(foregroundWindow, &title[0], length + 1);

    // Check if the window title contains "osu!" or "osu!.exe"
    return (title.find("osu!") != std::string::npos) || (title.find("osu!.exe") != std::string::npos);
}

int main() {
    // Prompt the user for the number of F2 presses
    int n;
    std::cout << "How many times do you want to press F2? ";
    std::cin >> n;

    // Check for invalid input
    if (std::cin.fail() || n <= 0) {
        std::cerr << "\nInvalid input. Please enter a positive integer." << std::endl;
        return 1;
    }

    // Loop until the osu! window is focused again
    while (!isOsuFocused()) {
        std::cout << "\nPlease focus on the osu!.exe window." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Check every second
    }

    int count = 0; // Initialize the count
    // Simulate pressing F2 key
    pressF2(n, count);

    std::cout << "\n\nIn 5 seconds I will close..." << std::endl;
    // Wait for 5 seconds before exiting
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
