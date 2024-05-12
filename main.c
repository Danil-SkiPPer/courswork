#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

#include "gameEngine.h"

int main()
{
    setlocale (LC_ALL, "Rus");
    startGame();
    return 0;
}
