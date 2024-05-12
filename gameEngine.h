#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

/*Элементы управления*/

// функция которая загружает экранную заставку и после этого включает главное меню
void startGame();

// функция загружающая экранную заставку (в данной функции печатается название игры, после осуществляется выход из функции)
void loading();

// функция выводящая на экран главное меню (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)
void mainMenu();

// функция проверяет статистику начала игры и после этого вызывает вункцию загрузски уровня (в случае ошибки указывает на ошибку и возвращает в главное меню)
void gameMenu ();

// функция выводящая на экран  меню выхода (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(в случае выхода закрывает программу)
void exitGame();

// функция выводящая на экран  меню сброса  (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(сбрасывает до начальных значений теги в файле statistic.txt)
void reset();

// функция выводящая на экран  меню настроек  (после вывода входит в бесконечный цикл пока не будет нажата нужная кнопка)(имеется изменить значения в файле statistic.txt )
void settings ();

/*Создание персонажа*/

// функция создаёт персонажа характеристики (перемененые) а также запис
void createPerson(int person);

// функция распределяет очки способностей персонажа
void gamePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки силы персонажа
void forcePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки ловкости персонажа
void dexterityPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки телосложения персонажа
void bodyTypePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки интелекта персонажа
void intelligenceePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки мудрости с персонажа
void wisdomPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция распределяет очки харизмы персонажа
void charismaPointsAdder(int person ,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// функция сохраняет характеристики персонажа  person в фаил под определёнными тегами
void personFileSaver(int person, char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

/*Подгрузска информации*/

// функция проверяет существование файлов уровней от 0 до countOfLevels (в случае отсутствия выдаёт ошибку)
void fileChecker(bool*error , int countOfLevels);

// функция возвращает значение  тега word от файла статистики (в случае если status равен 1 может менять значение этого тега )
int returnStat (char* word,int status , int index);

// функция возвращает значение  тега word от файла level в строку outputText
int levelStat (char* word,int level, char* outputText);

// функция возвращает значение  тега word от файла person (в случае если status равен 1 может менять значение этого тега )
void returnPersonStat (char* word,int person, int status , int index, char*result);

/*Загрузска уровня*/

// функция обрабатывает статистику начала игры и в случае если она равна 1 то создает новою игру (создаёт персонажей)
void gameProgress (int statistic);

// функция распределяющая какую функцию нужно вызвать в зависимости от уровня
void loadLevel(int level);

// функция загружает начальный уровень ( появляется возможность: пересоздать персонажа, сохранить и выйти или же начать игру)
void startLevelLoader ();

// функция загружает текущий уровень (слова ведущего, ответы игроков, их характеристики ), поле ждёт пока текущий игрок выберет ответ , обрабатывает его и выдает результат
void currentLevelLoader (int level);

/*Игровой процесс*/

// выводит на экран в двух слобцах текущую характеристику двух игроков
void playerStatPrint(int person1 ,char*personNamePtr1,int*healthPtr1,int*forcePtr1, int*dexterityPtr1, int*bodyTypePtr1, int*intelligenceePtr1, int*wisdomPtr1, int*charismaPtr1, int person2,char*personNamePtr2,int*healthPtr2,int*forcePtr2, int*dexterityPtr2, int*bodyTypePtr2, int*intelligenceePtr2, int*wisdomPtr2, int*charismaPtr2);

// функция которая принемает характеристики текущего игрока и случайным образом (по одной из формул ниже) возвращает комбинацию этих характеристик
int combinationCharacteristic(int curForce ,int curDexterity ,int curBodyType ,int curIntelligencee ,int curWisdom ,int curCharisma);

// функиция которая отслеживает игровой процесс игры и в случае смерти одного из игроком заканчивает игру (но есть возможность востановления)
void gameOver (int health, int level);

/*Разные функции*/

// данная функция выводит входящую в неё строку по символьно с определённой задержкой
void printText (char* outputText);

// данная функция преобразует int в char для последующего использования в других  функциях (как пример в функциях linkCreator и personLinkCreator)
void intToChar (char* char_int , int level);

// данная функция создаёт ссылку на определённый уровень для того чтобы  в функции levelStat открыть фаил по этой ссылке (Пример: ./levels/level_1.txt)
void linkCreator (char* result, int levelNumber);

// данная функция создаёт ссылку на определённого персонажа  для того чтобы  в функции returnPersonStat открыть фаил по этой ссылке (Пример: ./person/person_1.txt)
void personLinkCreator (char* result, int person);

#endif // GAMEENGINE_H_INCLUDED
