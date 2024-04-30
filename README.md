# osu! F2 Presser

This simple C++ program simulates pressing the F2 key multiple times for the game osu!. It prompts the user to enter the number of times they want to press F2, then waits for the osu!.exe window to be focused before performing the key presses. Each F2 press has a pause of 300 milliseconds between them.

## Compilation

You can compile the program using `g++` on the command line:

```
g++ main_code.cpp -o osu_presser.exe
```

Alternatively, you can use Visual Studio Code and compile from there.

## Usage

1. Run the compiled `osu_presser.exe`.
2. Enter the number of times you want to press F2 when prompted.
3. Make sure the osu!.exe window is focused.
4. The program will then simulate pressing F2 the specified number of times.

## Requirements

- Windows OS
- osu! installed

## Disclaimer

This program is intended for educational purposes only. Use it responsibly and do not use it to violate the rules of any game.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
