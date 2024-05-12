#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

#include "gameEngine.h"

/*Элементы управления*/

// функция которая загружает экранную заставку и после этого включает главное меню
void startGame()
{
    loading();
    mainMenu();
}

// функция загружающая экранную заставку (в данной функции печатается название игры, после осуществляется выход из функции)
void loading()
{
    char name[] = "DANGEONS AND DRAGONS";
    printText(&name);
    Sleep(1300);
}

// функция выводящая на экран главное меню (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)
void mainMenu()
{
    system("cls");
    printf("Играть(C)\n");
    printf("Сброс(R)\n");
    printf("Настройки(S)\n");
    printf("Выход(X)\n");
    while(1)
    {
        switch (_getch())
        {
        case 'c':
            gameMenu();
            break;
        case 'r':
            reset();
            break;
        case 's':
            settings();
            break;
        case 'x':
            exitGame();
            break;
        }
    }
}

// функция проверяет статистику начала игры и после этого вызывает вункцию загрузски уровня (в случае ошибки указывает на ошибку и возвращает в главное меню)
void gameMenu ()
{
    system("cls");
    int statistic = returnStat("статистика_начала_игры", 0 , 0);
    gameProgress(statistic);
    Sleep(3000);
    mainMenu();
}

// функция выводящая на экран  меню выхода (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(в случае выхода закрывает программу)
void exitGame()
{
    system("cls");
    printf("Вы точно хотите выйти из игры\n   ДА(Y)    НЕТ(N)");
    while(1)
    {
        switch(_getch())
        {
            case 'n':
                mainMenu();
                break;
            case 'y':
                system("cls");
                exit(0);
                break;
        }
    }
}

// функция выводящая на экран  меню сброса  (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(сбрасывает до начальных значений теги в файле statistic.txt)
void reset()
{
    system("cls");
    printf("Вы точно желаете сбросить прогресс\n     ДА(Y)    НЕТ(N)");
    while(1)
    {
        switch(_getch())
        {
            case 'n':
                mainMenu();
                break;
            case 'y':
                returnStat("статистика_начала_игры", 1 , 1);
                returnStat("текущий_уровень", 1 , 1);
                returnStat("возможность_хила" , 1 ,1);
                system("cls");
                printf("Прогресс сброшен");
                Sleep(500);
                mainMenu();
                break;
        }
    }
}

// функция выводящая на экран  меню настроек  (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(имеется изменить значения в файле statistic.txt )
void settings ()
{
    system("cls");
    printf("Настройки\n=====================================================\n");
    printf("Поменять колличество очков персонажа (С)\n");
    printf("Главное меню (M)\n");
    while(1)
        {
            switch(_getch())
            {
                case 'c':
                    system("cls");
                    int gamePoints = returnStat("колличество_очков_персонажа", 0, 0);
                    printf("Текущее колличество очков: %d\n", gamePoints);
                    printf("Введите новое колличество очков: ");
                    scanf("%d", &gamePoints);
                    returnStat("колличество_очков_персонажа", 1, gamePoints);
                    settings();
                    break;
                case 'm':
                    mainMenu();
                    break;
            }
       }
}

/*Создание персонажа*/

// функция создаёт персонажа характеристики (перемененые) а также запис
void createPerson(int person)
{
    while (person <= 2)
    {
        system("cls");
        char personName[50] ="";
        printf("%d ИГРОК \nВведите имя вашего персонажа: ", person);
        scanf("%s", &personName);
        int gamePoints = returnStat("колличество_очков_персонажа", 0, 0);
        int force = 0;//сила
        int dexterity = 0; //ловкость
        int bodyType = 0;// телосложение
        int intelligencee = 0;//интелект
        int wisdom = 0;//мудрость
        int charisma = 0;//харизма
        gamePointsAdder(person,&personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
    }
}

// функция распределяет очки способностей персонажа
void gamePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("(F)Очки силы: %d\n",force);
            printf("(D)Очки ловкости: %d\n",dexterity);
            printf("(B)Очки телосложения: %d\n",bodyType);
            printf("(I)Очки интелекта: %d\n",intelligencee);
            printf("(W)Очки мудрости: %d\n",wisdom);
            printf("(C)Очки харизмы: %d\n",charisma);
            printf("\n(S)Далее\n");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case 'f':
                        forcePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'd':
                        dexterityPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'b':
                        bodyTypePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'i':
                        intelligenceePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'w':
                        wisdomPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'c':
                        charismaPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 's':
                        personFileSaver(person, personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки силы персонажа
void forcePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: (-) [%d] (+)\n",force);
            printf("Очки ловкости: %d\n",dexterity);
            printf("Очки телосложения: %d\n",bodyType);
            printf("Очки интелекта: %d\n",intelligencee);
            printf("Очки мудрости: %d\n",wisdom);
            printf("Очки харизмы: %d\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        printf("%d", force);
                        if(force > 0)
                        {
                            gamePoints += 1;
                            force -= 1;
                        }
                        forcePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            force += 1;
                        }
                        forcePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки ловкости персонажа
void dexterityPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: %d\n",force);
            printf("Очки ловкости: (-) [%d] (+)\n",dexterity);
            printf("Очки телосложения: %d\n",bodyType);
            printf("Очки интелекта: %d\n",intelligencee);
            printf("Очки мудрости: %d\n",wisdom);
            printf("Очки харизмы: %d\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        if(dexterity > 0)
                        {
                            gamePoints += 1;
                            dexterity -= 1;
                        }
                        dexterityPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            dexterity += 1;
                        }
                        dexterityPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки телосложения персонажа
void bodyTypePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: %d\n",force);
            printf("Очки ловкости: %d\n",dexterity);
            printf("Очки телосложения: (-) [%d] (+)\n",bodyType);
            printf("Очки интелекта: %d\n",intelligencee);
            printf("Очки мудрости: %d\n",wisdom);
            printf("Очки харизмы: %d\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        if(bodyType > 0)
                        {
                            gamePoints += 1;
                            bodyType -= 1;
                        }
                        bodyTypePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            bodyType += 1;
                        }
                        bodyTypePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки интелекта персонажа
void intelligenceePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: %d\n",force);
            printf("Очки ловкости: %d\n",dexterity);
            printf("Очки телосложения: %d\n",bodyType);
            printf("Очки интелекта: (-) [%d] (+)\n",intelligencee);
            printf("Очки мудрости: %d\n",wisdom);
            printf("Очки харизмы: %d\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        if(intelligencee > 0)
                        {
                            gamePoints += 1;
                            intelligencee -= 1;
                        }
                        intelligenceePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            intelligencee += 1;
                        }
                        intelligenceePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки мудрости с персонажа
void wisdomPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: %d\n",force);
            printf("Очки ловкости: %d\n",dexterity);
            printf("Очки телосложения: %d\n",bodyType);
            printf("Очки интелекта: %d\n",intelligencee);
            printf("Очки мудрости: (-) [%d] (+)\n",wisdom);
            printf("Очки харизмы: %d\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        if(wisdom > 0)
                        {
                            gamePoints += 1;
                            wisdom -= 1;
                        }
                        wisdomPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            wisdom += 1;
                        }
                        wisdomPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция распределяет очки харизмы персонажа
void charismaPointsAdder(int person ,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    char *personName = personNamePtr;
    int gamePoints = *gamePointsPtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    while(gamePoints >= 0)
        {
            system("cls");
            printf("%d ИГРОК \n", person);
            printf("Имя персонажа: %s\n",personName);
            printf("Общее колличество очков персонажа: %d\n", gamePoints);
            printf("Очки силы: %d\n",force);
            printf("Очки ловкости: %d\n",dexterity);
            printf("Очки телосложения: %d\n",bodyType);
            printf("Очки интелекта: %d\n",intelligencee);
            printf("Очки мудрости: %d\n",wisdom);
            printf("Очки харизмы: (-) [%d] (+)\n",charisma);
            printf("\n(R)Вернуться назад");
            while (gamePoints >= 0)
            {
                switch(_getch())
                {
                    case '-':
                        if(charisma > 0)
                        {
                            gamePoints += 1;
                            charisma -= 1;
                        }
                        charismaPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case '+':
                        if(gamePoints > 0)
                        {
                            gamePoints -= 1;
                            charisma += 1;
                        }
                        charismaPointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                    case 'r':
                        gamePointsAdder(person,personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
                        break;
                }
            }
        }
}

// функция сохраняет характеристики персонажа  person в фаил под определёнными тегами
void personFileSaver(int person, char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr)
{
    int health = 10;
    char *personName = personNamePtr;
    int force = *forcePtr;
    int dexterity = *dexterityPtr;
    int bodyType = *bodyTypePtr;
    int intelligencee = *intelligenceePtr;
    int wisdom = *wisdomPtr;
    int charisma = *charismaPtr;
    char currentPerson[20]="";
    personLinkCreator(&currentPerson, person);
    FILE* cur_person_file_read = fopen(currentPerson,"w+");
    fprintf(cur_person_file_read,"имя_игрока %s\n", personName);
    fprintf(cur_person_file_read,"здоровье_игрока %d\n", health );
    fprintf(cur_person_file_read,"сила_игрока %d\n", force);
    fprintf(cur_person_file_read,"ловкость_игрока %d\n", dexterity);
    fprintf(cur_person_file_read,"телосложение_игрока %d\n", bodyType);
    fprintf(cur_person_file_read,"интелект_игрока %d\n", intelligencee);
    fprintf(cur_person_file_read,"мудрость_игрока %d\n", wisdom);
    fprintf(cur_person_file_read,"харизма_игрока %d\n", charisma);
    fclose(cur_person_file_read);
    if (person == 2) {returnStat("статистика_начала_игры", 1 , 0);loadLevel(0);}
    else if (person == 1) createPerson(2);
}

/*Подгрузска информации*/

// функция проверяет существование файлов уровней от 0 до countOfLevels (в случае отсутствия выдаёт ошибку)
void fileChecker(bool*error , int countOfLevels)
{
    int iferror = 0;
    int cur_level;
    if (countOfLevels == 0){cur_level = 0 ;}
    else if (countOfLevels > 0){cur_level = 1 ;}
    for(cur_level; cur_level <= countOfLevels; cur_level++)
    {
        char fullLink[20] ="";
        linkCreator(&fullLink, cur_level);
        FILE* cur_level_file;
        cur_level_file = fopen(fullLink,"r+");
        if (cur_level_file == NULL){printf("ERROR FILE %d NOT FOUND\n",cur_level);iferror = 1;}
        fclose(cur_level_file);
    }
    if (iferror == 1) {*error = true;}
    else *error = false;
}

// функция возвращает значение  тега word от файла статистики (в случае если status равен 1 может менять значение этого тега )
int returnStat (char* word,int status , int index)
{
    int value = -1;
    FILE* stat_file_read = fopen(".\\statistic\\statistic.txt", "r+");
    FILE* stat_file_write = fopen(".\\statistic\\tempstatistic.txt", "w+");
    if (stat_file_read == NULL){printf("FILE NOT FOUND"); return -1;}
    else
    {
        int length = 0;
        char buffer[1000];
        char *buffer_pt = &buffer;
        while (fgets(buffer, 1000 , stat_file_read) != NULL)
        {
            char* char_stat = strstr(buffer_pt,word);
            if(char_stat != NULL)
            {
                int len = length + strlen(word);
                fseek(stat_file_read, len ,SEEK_SET);
                fscanf(stat_file_read," %d", &value);
                if (status == 1){fprintf(stat_file_write,"%s %d", word , index);}
                else if (status == 0 ){fputs(buffer,stat_file_write);}
            }
            else fputs(buffer,stat_file_write);
            length += (strlen(buffer)+1);
        }
    }
    fclose(stat_file_read);
    fclose(stat_file_write);
    const char oldName[] = ".\\statistic\\tempstatistic.txt";
    const char newName[] = ".\\statistic\\statistic.txt";
    remove(newName);
    rename(oldName,newName);
    return value;
}

// функция возвращает значение  тега word от файла level в строку outputText
int levelStat (char* word,int level, char* outputText)
{
    int value = -1;
    const char levelLink[40] = "";
    linkCreator(&levelLink,level);
    FILE* level_file_read = fopen(levelLink, "r+");
    FILE* level_file_write = fopen(".\\levels\\templevel.txt", "w+");
    if (level_file_read == NULL){printf("FILE NOT FOUND"); return -1;}
    else
    {
        int length = 0;
        char buffer[1000];
        char *buffer_pt = &buffer;
        while (fgets(buffer, 1000 , level_file_read) != NULL)
        {
            char* char_level = strstr(buffer_pt,word);
            if (char_level != NULL)
            {
                int len = length + strlen(word);
                fseek(level_file_read, len ,SEEK_SET);
                fgets(outputText,1000,level_file_read);
            }
            fputs(buffer,level_file_write);
            length += (strlen(buffer)+1);
        }
    }
    fclose(level_file_read);
    fclose(level_file_write);
    const char oldName[] = ".\\levels\\templevel.txt";
    remove(levelLink);
    rename(oldName,levelLink);
    return value;
}

// функция возвращает значение  тега word от файла person (в случае если status равен 1 может менять значение этого тега )
void returnPersonStat (char* word,int person, int status , int index, char*result)
{
    const char personLink[40] = "";
    personLinkCreator(&personLink,person);
    FILE* person_file_read = fopen( personLink, "r+");
    FILE* person_file_write = fopen(".\\person\\tempperson.txt", "w+");
    if (person_file_read == NULL){printf("FILE NOT FOUND");}
    else
    {
        int length = 0;
        char buffer[1000];
        char *buffer_pt = &buffer;
        while (fgets(buffer, 1000 , person_file_read) != NULL)
        {
            char* char_person = strstr(buffer_pt,word);
            if(char_person != NULL)
            {
                int len = length + strlen(word);
                fseek(person_file_read, len ,SEEK_SET);
                fscanf(person_file_read," %s", result);
                if (status == 1){fprintf(person_file_write,"%s %d", word , index);}
                else if (status == 0 ){fputs(buffer, person_file_write);}
            }
            else fputs(buffer,person_file_write);
            length += (strlen(buffer)+1);
        }
    }
    fclose(person_file_read);
    fclose(person_file_write);
    const char oldName[] = ".\\person\\tempperson.txt";
    remove(personLink);
    rename(oldName,personLink);
}

/*Загрузска уровня*/

// функция обрабатывает статистику начала игры и в случае если она равна 1 то создает новою игру (создаёт персонажей)
void gameProgress (int statistic)
{
    if (statistic == 1)
    {
        createPerson(1);
    }
    else if (statistic == 0 )
    {
        int currentLevel = returnStat("текущий_уровень" , 0,0);
        loadLevel(currentLevel);
    }
}

// функция распределяющая какую функцию нужно вызвать в зависимости от уровня
void loadLevel(int level)
{
    bool error = false;
    if (level == 0 )
    {
        fileChecker(&error, 0 );
        if (error == false) startLevelLoader();
        else {Sleep(1000); mainMenu();}
    }
    else if (level > 0)
    {
        int countOfLevels = returnStat("колличество_уровней", 0, 0);
        fileChecker(&error, countOfLevels);
        if (error == false )
        {
            if (level <= countOfLevels)
            {
                currentLevelLoader(level);
            }
            else if (level == (countOfLevels+1))
            {
                system("cls");
                printf("\n\n");
                int statistic;
                char health1Char[3] = " ";
                printText("Поздравляю");printf("\n");
                printText("Вы выйграли!!!");printf("\n");
                printText("(M)Выйти в меню");printf("\n");
                printText("(N) Начать игру заново");printf("\n");
                printText("(R) Начать игру заново, но с сохранением статистики персонажа");printf("\n");
                while(1)
                {
                    switch (_getch())
                    {
                    case 'r':
                        returnStat("текущий_уровень" , 1,1);
                        returnStat("возможность_хила" , 1 ,1);
                        returnPersonStat("здоровье_игрока",1,1,10,&health1Char);
                        returnPersonStat("здоровье_игрока",2,1,10,&health1Char);
                        loadLevel(1);
                        break;
                    case 'n':
                        returnStat("статистика_начала_игры", 1 , 1);
                        statistic = returnStat("статистика_начала_игры", 0 , 0);
                        returnStat("текущий_уровень" , 1,1);
                        returnStat("возможность_хила" , 1 ,1);
                        gameProgress(statistic);
                        break;
                    case 'm':
                        returnStat("статистика_начала_игры", 1 , 1);
                        returnStat("текущий_уровень" , 1,1);
                        returnStat("возможность_хила" , 1 ,1);
                        mainMenu();
                        break;
                    }
                }
            }
            else
            {
                printf(" ERROR LEVEL NOT CREATED");
                Sleep(2000);
                mainMenu();
            }
        }
        else {Sleep(2000); mainMenu();}
    }
}

// функция загружает начальный уровень ( появляется возможность: пересоздать персонажа, сохранить и выйти или же начать игру)
void startLevelLoader ()
{
    system("cls");
    printf("Ведущий:");
    char outputText[1000] = "";
    levelStat("слова_ведущего_1",0, &outputText);
    printText( &outputText );
    levelStat("слова_ведущего_2",0, &outputText);
    printText( &outputText );
    levelStat("слова_ведущего_3",0, &outputText);
    printText( &outputText );
    levelStat("слова_ведущего_4",0, &outputText);
    printText( &outputText );
    levelStat("слова_ведущего_5",0, &outputText);
    printText( &outputText );
    levelStat("слова_ведущего_6",0, &outputText);
    printText( &outputText );
    printf("\n\n\n\n");
    levelStat("вариант_ответа_1",0, &outputText);
    printf("%s", outputText);
    levelStat("вариант_ответа_2",0, &outputText);
    printf("%s", outputText);
    levelStat("вариант_ответа_3",0, &outputText);
    printf("%s", outputText);
    levelStat("вариант_ответа_4",0, &outputText);
    printf("%s", outputText);
    printf("\n\n\n\n");
    char personName1[40] = " ";returnPersonStat("имя_игрока",1,0,0, &personName1);
    char health1Char[3] = " ";returnPersonStat("здоровье_игрока",1,0,0, &health1Char);int health1 = atoi(health1Char);
    char force1Char[3] = " ";returnPersonStat("сила_игрока",1,0,0, &force1Char);int force1 = atoi(force1Char);
    char dexterity1Char[3] =  " ";returnPersonStat("ловкость_игрока",1,0,0, &dexterity1Char);int dexterity1 = atoi(dexterity1Char);
    char bodyType1Char[3] = " ";returnPersonStat("телосложение_игрока",1,0,0, &bodyType1Char);int bodyType1 = atoi(bodyType1Char);
    char intelligencee1Char[3] = " ";returnPersonStat("интелект_игрока",1,0,0, &intelligencee1Char);int intelligencee1 = atoi(intelligencee1Char);
    char wisdom1Char[3] = " ";returnPersonStat("мудрость_игрока",1,0,0, &wisdom1Char);int wisdom1 = atoi(wisdom1Char);
    char charisma1Char[3] = " ";returnPersonStat("харизма_игрока",1,0,0,&charisma1Char);int charisma1 = atoi(charisma1Char);
    char personName2[40] = " ";returnPersonStat("имя_игрока",2,0,0, &personName2);
    char health2Char[3] = " ";returnPersonStat("здоровье_игрока",2,0,0, &health2Char);int health2 = atoi(health2Char);
    char force2Char[3] = " ";returnPersonStat("сила_игрока",2,0,0, &force2Char);int force2 = atoi(force2Char);
    char dexterity2Char[3] = " ";returnPersonStat("ловкость_игрока",2,0,0, &dexterity2Char);int dexterity2 = atoi(dexterity2Char);
    char bodyType2Char[3] = " ";returnPersonStat("телосложение_игрока",2,0,0, &bodyType2Char);int bodyType2 = atoi(bodyType2Char);
    char intelligencee2Char[3] = " ";returnPersonStat("интелект_игрока",2,0,0, &intelligencee2Char);int intelligencee2 = atoi(intelligencee2Char);
    char wisdom2Char[3] = " ";returnPersonStat("мудрость_игрока",2,0,0, &wisdom2Char);int wisdom2 = atoi(wisdom2Char);
    char charisma2Char[3] = " ";returnPersonStat("харизма_игрока",2,0,0,&charisma2Char);int charisma2 = atoi(charisma2Char);
    playerStatPrint(1,&personName1,&health1,&force1,&dexterity1,&bodyType1,&intelligencee1,&wisdom1,&charisma1,2,&personName2,&health2,&force2,&dexterity2,&bodyType2,&intelligencee2,&wisdom2,&charisma2);
    while(1)
    {
        switch (_getch())
        {
        case '1':
            loadLevel(1);
            break;
        case '2':
            mainMenu();
            break;
        case '3':
            returnStat("статистика_начала_игры", 1 , 1);
            mainMenu();
            break;
        case '4':
            returnStat("статистика_начала_игры", 1 , 1);
            gameMenu();
            break;
        }
    }
}

// функция загружает текущий уровень (слова ведущего, ответы игроков, их характеристики ), поле ждёт пока текущий игрок выберет ответ , обрабатывает его и выдает результат
void currentLevelLoader (int level)
{
    char levelLink[40];
    linkCreator(&levelLink,level);
    char personName1[40] = " ";returnPersonStat("имя_игрока",1,0,0, &personName1);
    char health1Char[3] = " ";returnPersonStat("здоровье_игрока",1,0,0, &health1Char);int health1 = atoi(health1Char);
    char force1Char[3] = " ";returnPersonStat("сила_игрока",1,0,0, &force1Char);int force1 = atoi(force1Char);
    char dexterity1Char[3] =  " ";returnPersonStat("ловкость_игрока",1,0,0, &dexterity1Char);int dexterity1 = atoi(dexterity1Char);
    char bodyType1Char[3] = " ";returnPersonStat("телосложение_игрока",1,0,0, &bodyType1Char);int bodyType1 = atoi(bodyType1Char);
    char intelligencee1Char[3] = " ";returnPersonStat("интелект_игрока",1,0,0, &intelligencee1Char);int intelligencee1 = atoi(intelligencee1Char);
    char wisdom1Char[3] = " ";returnPersonStat("мудрость_игрока",1,0,0, &wisdom1Char);int wisdom1 = atoi(wisdom1Char);
    char charisma1Char[3] = " ";returnPersonStat("харизма_игрока",1,0,0,&charisma1Char);int charisma1 = atoi(charisma1Char);
    char personName2[40] = " ";returnPersonStat("имя_игрока",2,0,0, &personName2);
    char health2Char[3] = " ";returnPersonStat("здоровье_игрока",2,0,0, &health2Char);int health2 = atoi(health2Char);
    char force2Char[3] = " ";returnPersonStat("сила_игрока",2,0,0, &force2Char);int force2 = atoi(force2Char);
    char dexterity2Char[3] = " ";returnPersonStat("ловкость_игрока",2,0,0, &dexterity2Char);int dexterity2 = atoi(dexterity2Char);
    char bodyType2Char[3] = " ";returnPersonStat("телосложение_игрока",2,0,0, &bodyType2Char);int bodyType2 = atoi(bodyType2Char);
    char intelligencee2Char[3] = " ";returnPersonStat("интелект_игрока",2,0,0, &intelligencee2Char);int intelligencee2 = atoi(intelligencee2Char);
    char wisdom2Char[3] = " ";returnPersonStat("мудрость_игрока",2,0,0, &wisdom2Char);int wisdom2 = atoi(wisdom2Char);
    char charisma2Char[3] = " ";returnPersonStat("харизма_игрока",2,0,0,&charisma2Char);int charisma2 = atoi(charisma2Char);
    int curHealth;int curForce;int curDexterity;int curBodyType;int curIntelligencee;int curWisdom;int curCharisma;
    for (int person = 1 ; person <= 2 ; person++)
    {
        system("cls");
        printf("(M) Сохранить и выйти в главное меню \n");
        printf("Текущий уровень: %d\n",level);
        srand(time(0));
        char outputText[1000] = " ";
        char outputVariant1[1000] = " ";
        char outputVariant2[1000] = " ";
        char outputVariant3[1000] = " ";
        char outputVariant4[1000] = " ";
        if (person == 1)
        {
            levelStat("1_персонаж_вариант_ответа_1",level,&outputVariant1);
            levelStat("1_персонаж_вариант_ответа_2",level,&outputVariant2);
            levelStat("1_персонаж_вариант_ответа_3",level,&outputVariant3);
            levelStat("1_персонаж_вариант_ответа_4",level,&outputVariant4);
            printf("\nВедущий:");
            levelStat("слова_ведущего_1",level, &outputText);
            printText( &outputText );
            levelStat("слова_ведущего_2",level, &outputText);
            printText( &outputText );
            levelStat("слова_ведущего_3",level, &outputText);
            printText( &outputText );
            curHealth = health1;
            curForce = force1;
            curDexterity = dexterity1;
            curBodyType = bodyType1;
            curIntelligencee = intelligencee1;
            curWisdom = wisdom1;
            curCharisma = charisma1;
        }
        if (person == 2)
        {
            levelStat("2_персонаж_вариант_ответа_1",level,&outputVariant1);
            levelStat("2_персонаж_вариант_ответа_2",level,&outputVariant2);
            levelStat("2_персонаж_вариант_ответа_3",level,&outputVariant3);
            levelStat("2_персонаж_вариант_ответа_4",level,&outputVariant4);
            printf("\nВедущий:");
            char outputText[1000] = "";
            levelStat("слова_ведущего_1",level, &outputText);
            printf("%s", outputText);
            levelStat("слова_ведущего_2",level, &outputText);
            printf("%s", outputText);
            levelStat("слова_ведущего_3",level, &outputText);
            printf("%s", outputText);
            curHealth = health2;
            curForce = force2;
            curDexterity = dexterity2;
            curBodyType = bodyType2;
            curIntelligencee = intelligencee2;
            curWisdom = wisdom2;
            curCharisma = charisma2;
        }
        printf("\n\nПерсонаж: %d\n",person);
        printf("\n(1)%s", outputVariant1);
        printf("(2)%s", outputVariant2);
        printf("(3)%s", outputVariant3);
        printf("(4)%s", outputVariant4);
        playerStatPrint(1,&personName1,&health1,&force1,&dexterity1,&bodyType1,&intelligencee1,&wisdom1,&charisma1,2,&personName2,&health2,&force2,&dexterity2,&bodyType2,&intelligencee2,&wisdom2,&charisma2);
        int combinationCharacteristicPerson = 0;
        int status = 1;
        int cube = 0;
        char tempHealth[2];
        while(status == 1)
        {
            switch (_getch())
            {
            case '1':
                cube = 1 +rand()%19;
                printf("\nКуб подброшен\n");
                Sleep(100);
                printf("Выполо число:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("Комбинация характеристик %d-го персонажа равна: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("Поздравляю, действие сработало\n");}
                else if (combinationCharacteristicPerson < cube){printf("Действие не сработало :( \n"); curHealth -= 1;}
                returnPersonStat("здоровье_игрока",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '2':
                cube = 1 +rand()%19;
                printf("\nКуб подброшен\n");
                Sleep(100);
                printf("Выполо число:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("Комбинация характеристик %d-го персонажа равна: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("Поздравляю, действие сработало\n");}
                else if (combinationCharacteristicPerson < cube){printf("Действие не сработало :( \n"); curHealth -= 1;}
                returnPersonStat("здоровье_игрока",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '3':
                cube = 1 +rand()%19;
                printf("\nКуб подброшен\n");
                Sleep(100);
                printf("Выполо число:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("Комбинация характеристик %d-го персонажа равна: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("Поздравляю, действие сработало\n");}
                else if (combinationCharacteristicPerson < cube){printf("Действие не сработало :( \n"); curHealth -= 1;}
                returnPersonStat("здоровье_игрока",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '4':
                cube = 1 +rand()%19;
                printf("\nКуб подброшен\n");
                Sleep(100);
                printf("Выполо число:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("Комбинация характеристик %d-го персонажа равна: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("Поздравляю, действие сработало\n");}
                else if (combinationCharacteristicPerson < cube){printf("Действие не сработало :( \n"); curHealth -= 1;}
                returnPersonStat("здоровье_игрока",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case 'm':
                returnStat("текущий_уровень" , 1, level);
                system("cls");
                printf("Уровень сохранён и вы можете выйти");
                mainMenu();
                break;
            }
        }
    }
    level +=1;
    returnStat("текущий_уровень" , 1, level);
    loadLevel(level);
}

/*Игровой процесс*/

// выводит на экран в двух слобцах текущую характеристику двух игроков
void playerStatPrint(int person1 ,char*personNamePtr1,int*healthPtr1,int*forcePtr1, int*dexterityPtr1, int*bodyTypePtr1, int*intelligenceePtr1, int*wisdomPtr1, int*charismaPtr1, int person2,char*personNamePtr2,int*healthPtr2,int*forcePtr2, int*dexterityPtr2, int*bodyTypePtr2, int*intelligenceePtr2, int*wisdomPtr2, int*charismaPtr2)
{
    char *personName1 = personNamePtr1;
    int health1 = *healthPtr1;
    int force1 = *forcePtr1;
    int dexterity1 = *dexterityPtr1;
    int bodyType1 = *bodyTypePtr1;
    int intelligencee1 = *intelligenceePtr1;
    int wisdom1 = *wisdomPtr1;
    int charisma1 = *charismaPtr1;
    char *personName2 = personNamePtr2;
    int health2 = *healthPtr2;
    int force2 = *forcePtr2;
    int dexterity2 = *dexterityPtr2;
    int bodyType2 = *bodyTypePtr2;
    int intelligencee2 = *intelligenceePtr2;
    int wisdom2 = *wisdomPtr2;
    int charisma2 = *charismaPtr2;
    printf("\n");
    printf("Персонаж: %d                                                       Персонаж: %d\n",person1,person2);
    printf("Имя: %s                                                            Имя: %s\n",personName1,personName2);
    printf("Характеристика                                                     Характеристика\n");
    printf("Здоровье: %d                                                       Здоровье: %d\n",health1,health2);
    printf("Сила: %d                                                           Сила: %d\n",force1,force2);
    printf("Ловкость: %d                                                       Ловкость: %d\n",dexterity1,dexterity2);
    printf("Телосложение: %d                                                   Телосложение: %d\n",bodyType1,bodyType2);
    printf("Интилект: %d                                                       Интилект: %d\n",intelligencee1,intelligencee2);
    printf("Мудрость: %d                                                       Мудрость: %d\n",wisdom1,wisdom2);
    printf("Харизма: %d                                                        Харизма: %d\n",charisma1,charisma2);
}

// функция которая принемает характеристики текущего игрока и случайным образом (по одной из формул ниже) возвращает комбинацию этих характеристик
int combinationCharacteristic(int curForce ,int curDexterity ,int curBodyType ,int curIntelligencee ,int curWisdom ,int curCharisma)
{
    int combinationCharacteristic = 0;
    int random = 1 + rand()%20;
    switch(random)
    {
        case 1:
            combinationCharacteristic = (2 + (curForce + curBodyType)/2);
            break;
        case 2:
            combinationCharacteristic = (2 + (curForce + curDexterity)/2);
            break;
        case 3:
            combinationCharacteristic = (2 + (curDexterity + curIntelligencee)/2);
            break;
        case 4:
            combinationCharacteristic = (2 + (curDexterity + curCharisma)/2);
            break;
        case 5:
            combinationCharacteristic = (2 + (curIntelligencee + curWisdom)/2);
            break;
        case 6:
            combinationCharacteristic = (2 + (curIntelligencee + curCharisma)/2);
            break;
        case 7:
            combinationCharacteristic = (2 + (curBodyType + curCharisma)/2);
            break;
        case 8:
            combinationCharacteristic = (2 + (curForce + curBodyType + curDexterity)/4);
            break;
        case 9:
            combinationCharacteristic = (2 + (curIntelligencee + curDexterity + curBodyType)/4);
            break;
        case 10:
            combinationCharacteristic = (2 + (curWisdom + curDexterity + curIntelligencee)/4);
            break;
        case 11:
            combinationCharacteristic = (2 + (curCharisma + curForce + curBodyType)/4);
            break;
        case 12:
            combinationCharacteristic = (2 + curBodyType);
            break;
        case 13:
            combinationCharacteristic = (2 + curCharisma);
            break;
        case 14:
            combinationCharacteristic = (2 + curDexterity);
            break;
        case 15:
            combinationCharacteristic = (2 + curForce);
            break;
        case 16:
            combinationCharacteristic = (2 + curIntelligencee);
            break;
        case 17:
            combinationCharacteristic = (2 + curWisdom);
            break;
        case 18:
            combinationCharacteristic = (2 +(curBodyType + curForce + curIntelligencee + curDexterity)/5);
            break;
        case 19:
            combinationCharacteristic = (2 +(curForce + curDexterity + curWisdom + curIntelligencee + curCharisma)/6);
            break;
        case 20:
            combinationCharacteristic = (2 +(curBodyType + curCharisma + curDexterity + curForce + curIntelligencee + curWisdom)/7);
            break;
    }
    return combinationCharacteristic;
}

// функиция которая отслеживает игровой процесс игры и в случае смерти одного из игроком заканчивает игру (но есть возможность востановления)
void gameOver (int health, int level)
{
    if (health <= 0)
    {
        system("cls");
        printf("\n\n\n Вы проиграли :(\n");
        printf("Нажмите (M) что бы вернуться в меню\n");
        printf("Нажмине (N) если хотите начать сначала\n");
        printf("Нажмите (C) если  хотите получить 5 хп (работает 1 раз)\n");
        int statistic;
        int reHeal;
        while(1)
        {
            switch (_getch())
            {
            case 'c':
                reHeal = returnStat("возможность_хила" , 1 ,0);
                if (reHeal == 1)
                {
                    char health1Char[3] = " ";returnPersonStat("здоровье_игрока",1,0,0, &health1Char);int health1 = atoi(health1Char);
                    health1 +=5;
                    returnPersonStat("здоровье_игрока",1,1,health1,&health1Char);
                    returnPersonStat("здоровье_игрока",2,1,5,&health1Char);
                    printf("\nЗдоровье востановленно\n");
                    Sleep(2000);
                    loadLevel(level+1);
                }
                else if (reHeal == 0)
                {
                    printf("\nВы уже использовали попытку\n");
                    Sleep(2000);
                    gameOver(0,level);
                }
                break;
            case 'n':
                returnStat("статистика_начала_игры", 1 , 1);
                statistic = returnStat("статистика_начала_игры", 0 , 0);
                returnStat("текущий_уровень" , 1,1);
                returnStat("возможность_хила" , 1 ,1);
                gameProgress(statistic);
                break;
            case 'm':
                returnStat("статистика_начала_игры", 1 , 1);
                returnStat("текущий_уровень" , 1,1);
                returnStat("возможность_хила" , 1 ,1);
                mainMenu();
                break;
            }
        }
    }
}

/*Разные функции*/

// данная функция выводит входящую в неё строку по символьно с определённой задержкой
void printText (char* outputText)
{
    for (int i = 0 ; i < strlen(outputText); i++)
    {
        if (outputText[i] == "\0"){break;}
        else {printf("%c", outputText[i]); Sleep(12);}
    }
}

// данная функция преобразует int в char для последующего использования в других  функциях (как пример в функциях linkCreator и personLinkCreator)
void intToChar (char* char_int , int level)
{
    itoa(level,char_int, 10);
}

// данная функция создаёт ссылку на определённый уровень для того чтобы  в функции levelStat открыть фаил по этой ссылке (Пример: ./levels/level_1.txt)
void linkCreator (char* result, int levelNumber)
{
    const char link[] =".\\levels\\";
    const char txt[] =".txt";
    const char levels[] ="level_";
    char char_level[4];
    intToChar(&char_level,levelNumber);
    strcat(result,link);
    strcat(result,levels);
    strcat(result,char_level);
    strcat(result,txt);
}

// данная функция создаёт ссылку на определённого персонажа  для того чтобы  в функции returnPersonStat открыть фаил по этой ссылке (Пример: ./person/person_1.txt)
void personLinkCreator (char* result, int person)
{
    const char link[] =".\\person\\";
    const char txt[] =".txt";
    const char levels[] ="person_";
    char char_person[4];
    intToChar(&char_person,person);
    strcat(result,link);
    strcat(result,levels);
    strcat(result,char_person);
    strcat(result,txt);
}
