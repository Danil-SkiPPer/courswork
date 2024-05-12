#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

#include "gameEngine.h"

/*�������� ����������*/

// ������� ������� ��������� �������� �������� � ����� ����� �������� ������� ����
void startGame()
{
    loading();
    mainMenu();
}

// ������� ����������� �������� �������� (� ������ ������� ���������� �������� ����, ����� �������������� ����� �� �������)
void loading()
{
    char name[] = "DANGEONS AND DRAGONS";
    printText(&name);
    Sleep(1300);
}

// ������� ��������� �� ����� ������� ���� (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)
void mainMenu()
{
    system("cls");
    printf("������(C)\n");
    printf("�����(R)\n");
    printf("���������(S)\n");
    printf("�����(X)\n");
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

// ������� ��������� ���������� ������ ���� � ����� ����� �������� ������� ��������� ������ (� ������ ������ ��������� �� ������ � ���������� � ������� ����)
void gameMenu ()
{
    system("cls");
    int statistic = returnStat("����������_������_����", 0 , 0);
    gameProgress(statistic);
    Sleep(3000);
    mainMenu();
}

// ������� ��������� �� �����  ���� ������ (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(� ������ ������ ��������� ���������)
void exitGame()
{
    system("cls");
    printf("�� ����� ������ ����� �� ����\n   ��(Y)    ���(N)");
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

// ������� ��������� �� �����  ���� ������  (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(���������� �� ��������� �������� ���� � ����� statistic.txt)
void reset()
{
    system("cls");
    printf("�� ����� ������� �������� ��������\n     ��(Y)    ���(N)");
    while(1)
    {
        switch(_getch())
        {
            case 'n':
                mainMenu();
                break;
            case 'y':
                returnStat("����������_������_����", 1 , 1);
                returnStat("�������_�������", 1 , 1);
                returnStat("�����������_����" , 1 ,1);
                system("cls");
                printf("�������� �������");
                Sleep(500);
                mainMenu();
                break;
        }
    }
}

// ������� ��������� �� �����  ���� ��������  (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(������� �������� �������� � ����� statistic.txt )
void settings ()
{
    system("cls");
    printf("���������\n=====================================================\n");
    printf("�������� ����������� ����� ��������� (�)\n");
    printf("������� ���� (M)\n");
    while(1)
        {
            switch(_getch())
            {
                case 'c':
                    system("cls");
                    int gamePoints = returnStat("�����������_�����_���������", 0, 0);
                    printf("������� ����������� �����: %d\n", gamePoints);
                    printf("������� ����� ����������� �����: ");
                    scanf("%d", &gamePoints);
                    returnStat("�����������_�����_���������", 1, gamePoints);
                    settings();
                    break;
                case 'm':
                    mainMenu();
                    break;
            }
       }
}

/*�������� ���������*/

// ������� ������ ��������� �������������� (�����������) � ����� �����
void createPerson(int person)
{
    while (person <= 2)
    {
        system("cls");
        char personName[50] ="";
        printf("%d ����� \n������� ��� ������ ���������: ", person);
        scanf("%s", &personName);
        int gamePoints = returnStat("�����������_�����_���������", 0, 0);
        int force = 0;//����
        int dexterity = 0; //��������
        int bodyType = 0;// ������������
        int intelligencee = 0;//��������
        int wisdom = 0;//��������
        int charisma = 0;//�������
        gamePointsAdder(person,&personName,&gamePoints, &force, &dexterity, &bodyType, &intelligencee, &wisdom, &charisma);
    }
}

// ������� ������������ ���� ������������ ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("(F)���� ����: %d\n",force);
            printf("(D)���� ��������: %d\n",dexterity);
            printf("(B)���� ������������: %d\n",bodyType);
            printf("(I)���� ���������: %d\n",intelligencee);
            printf("(W)���� ��������: %d\n",wisdom);
            printf("(C)���� �������: %d\n",charisma);
            printf("\n(S)�����\n");
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

// ������� ������������ ���� ���� ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: (-) [%d] (+)\n",force);
            printf("���� ��������: %d\n",dexterity);
            printf("���� ������������: %d\n",bodyType);
            printf("���� ���������: %d\n",intelligencee);
            printf("���� ��������: %d\n",wisdom);
            printf("���� �������: %d\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ������������ ���� �������� ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: %d\n",force);
            printf("���� ��������: (-) [%d] (+)\n",dexterity);
            printf("���� ������������: %d\n",bodyType);
            printf("���� ���������: %d\n",intelligencee);
            printf("���� ��������: %d\n",wisdom);
            printf("���� �������: %d\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ������������ ���� ������������ ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: %d\n",force);
            printf("���� ��������: %d\n",dexterity);
            printf("���� ������������: (-) [%d] (+)\n",bodyType);
            printf("���� ���������: %d\n",intelligencee);
            printf("���� ��������: %d\n",wisdom);
            printf("���� �������: %d\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ������������ ���� ��������� ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: %d\n",force);
            printf("���� ��������: %d\n",dexterity);
            printf("���� ������������: %d\n",bodyType);
            printf("���� ���������: (-) [%d] (+)\n",intelligencee);
            printf("���� ��������: %d\n",wisdom);
            printf("���� �������: %d\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ������������ ���� �������� � ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: %d\n",force);
            printf("���� ��������: %d\n",dexterity);
            printf("���� ������������: %d\n",bodyType);
            printf("���� ���������: %d\n",intelligencee);
            printf("���� ��������: (-) [%d] (+)\n",wisdom);
            printf("���� �������: %d\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ������������ ���� ������� ���������
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
            printf("%d ����� \n", person);
            printf("��� ���������: %s\n",personName);
            printf("����� ����������� ����� ���������: %d\n", gamePoints);
            printf("���� ����: %d\n",force);
            printf("���� ��������: %d\n",dexterity);
            printf("���� ������������: %d\n",bodyType);
            printf("���� ���������: %d\n",intelligencee);
            printf("���� ��������: %d\n",wisdom);
            printf("���� �������: (-) [%d] (+)\n",charisma);
            printf("\n(R)��������� �����");
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

// ������� ��������� �������������� ���������  person � ���� ��� ������������ ������
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
    fprintf(cur_person_file_read,"���_������ %s\n", personName);
    fprintf(cur_person_file_read,"��������_������ %d\n", health );
    fprintf(cur_person_file_read,"����_������ %d\n", force);
    fprintf(cur_person_file_read,"��������_������ %d\n", dexterity);
    fprintf(cur_person_file_read,"������������_������ %d\n", bodyType);
    fprintf(cur_person_file_read,"��������_������ %d\n", intelligencee);
    fprintf(cur_person_file_read,"��������_������ %d\n", wisdom);
    fprintf(cur_person_file_read,"�������_������ %d\n", charisma);
    fclose(cur_person_file_read);
    if (person == 2) {returnStat("����������_������_����", 1 , 0);loadLevel(0);}
    else if (person == 1) createPerson(2);
}

/*���������� ����������*/

// ������� ��������� ������������� ������ ������� �� 0 �� countOfLevels (� ������ ���������� ����� ������)
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

// ������� ���������� ��������  ���� word �� ����� ���������� (� ������ ���� status ����� 1 ����� ������ �������� ����� ���� )
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

// ������� ���������� ��������  ���� word �� ����� level � ������ outputText
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

// ������� ���������� ��������  ���� word �� ����� person (� ������ ���� status ����� 1 ����� ������ �������� ����� ���� )
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

/*��������� ������*/

// ������� ������������ ���������� ������ ���� � � ������ ���� ��� ����� 1 �� ������� ����� ���� (������ ����������)
void gameProgress (int statistic)
{
    if (statistic == 1)
    {
        createPerson(1);
    }
    else if (statistic == 0 )
    {
        int currentLevel = returnStat("�������_�������" , 0,0);
        loadLevel(currentLevel);
    }
}

// ������� �������������� ����� ������� ����� ������� � ����������� �� ������
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
        int countOfLevels = returnStat("�����������_�������", 0, 0);
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
                printText("����������");printf("\n");
                printText("�� ��������!!!");printf("\n");
                printText("(M)����� � ����");printf("\n");
                printText("(N) ������ ���� ������");printf("\n");
                printText("(R) ������ ���� ������, �� � ����������� ���������� ���������");printf("\n");
                while(1)
                {
                    switch (_getch())
                    {
                    case 'r':
                        returnStat("�������_�������" , 1,1);
                        returnStat("�����������_����" , 1 ,1);
                        returnPersonStat("��������_������",1,1,10,&health1Char);
                        returnPersonStat("��������_������",2,1,10,&health1Char);
                        loadLevel(1);
                        break;
                    case 'n':
                        returnStat("����������_������_����", 1 , 1);
                        statistic = returnStat("����������_������_����", 0 , 0);
                        returnStat("�������_�������" , 1,1);
                        returnStat("�����������_����" , 1 ,1);
                        gameProgress(statistic);
                        break;
                    case 'm':
                        returnStat("����������_������_����", 1 , 1);
                        returnStat("�������_�������" , 1,1);
                        returnStat("�����������_����" , 1 ,1);
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

// ������� ��������� ��������� ������� ( ���������� �����������: ����������� ���������, ��������� � ����� ��� �� ������ ����)
void startLevelLoader ()
{
    system("cls");
    printf("�������:");
    char outputText[1000] = "";
    levelStat("�����_��������_1",0, &outputText);
    printText( &outputText );
    levelStat("�����_��������_2",0, &outputText);
    printText( &outputText );
    levelStat("�����_��������_3",0, &outputText);
    printText( &outputText );
    levelStat("�����_��������_4",0, &outputText);
    printText( &outputText );
    levelStat("�����_��������_5",0, &outputText);
    printText( &outputText );
    levelStat("�����_��������_6",0, &outputText);
    printText( &outputText );
    printf("\n\n\n\n");
    levelStat("�������_������_1",0, &outputText);
    printf("%s", outputText);
    levelStat("�������_������_2",0, &outputText);
    printf("%s", outputText);
    levelStat("�������_������_3",0, &outputText);
    printf("%s", outputText);
    levelStat("�������_������_4",0, &outputText);
    printf("%s", outputText);
    printf("\n\n\n\n");
    char personName1[40] = " ";returnPersonStat("���_������",1,0,0, &personName1);
    char health1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &health1Char);int health1 = atoi(health1Char);
    char force1Char[3] = " ";returnPersonStat("����_������",1,0,0, &force1Char);int force1 = atoi(force1Char);
    char dexterity1Char[3] =  " ";returnPersonStat("��������_������",1,0,0, &dexterity1Char);int dexterity1 = atoi(dexterity1Char);
    char bodyType1Char[3] = " ";returnPersonStat("������������_������",1,0,0, &bodyType1Char);int bodyType1 = atoi(bodyType1Char);
    char intelligencee1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &intelligencee1Char);int intelligencee1 = atoi(intelligencee1Char);
    char wisdom1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &wisdom1Char);int wisdom1 = atoi(wisdom1Char);
    char charisma1Char[3] = " ";returnPersonStat("�������_������",1,0,0,&charisma1Char);int charisma1 = atoi(charisma1Char);
    char personName2[40] = " ";returnPersonStat("���_������",2,0,0, &personName2);
    char health2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &health2Char);int health2 = atoi(health2Char);
    char force2Char[3] = " ";returnPersonStat("����_������",2,0,0, &force2Char);int force2 = atoi(force2Char);
    char dexterity2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &dexterity2Char);int dexterity2 = atoi(dexterity2Char);
    char bodyType2Char[3] = " ";returnPersonStat("������������_������",2,0,0, &bodyType2Char);int bodyType2 = atoi(bodyType2Char);
    char intelligencee2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &intelligencee2Char);int intelligencee2 = atoi(intelligencee2Char);
    char wisdom2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &wisdom2Char);int wisdom2 = atoi(wisdom2Char);
    char charisma2Char[3] = " ";returnPersonStat("�������_������",2,0,0,&charisma2Char);int charisma2 = atoi(charisma2Char);
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
            returnStat("����������_������_����", 1 , 1);
            mainMenu();
            break;
        case '4':
            returnStat("����������_������_����", 1 , 1);
            gameMenu();
            break;
        }
    }
}

// ������� ��������� ������� ������� (����� ��������, ������ �������, �� �������������� ), ���� ��� ���� ������� ����� ������� ����� , ������������ ��� � ������ ���������
void currentLevelLoader (int level)
{
    char levelLink[40];
    linkCreator(&levelLink,level);
    char personName1[40] = " ";returnPersonStat("���_������",1,0,0, &personName1);
    char health1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &health1Char);int health1 = atoi(health1Char);
    char force1Char[3] = " ";returnPersonStat("����_������",1,0,0, &force1Char);int force1 = atoi(force1Char);
    char dexterity1Char[3] =  " ";returnPersonStat("��������_������",1,0,0, &dexterity1Char);int dexterity1 = atoi(dexterity1Char);
    char bodyType1Char[3] = " ";returnPersonStat("������������_������",1,0,0, &bodyType1Char);int bodyType1 = atoi(bodyType1Char);
    char intelligencee1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &intelligencee1Char);int intelligencee1 = atoi(intelligencee1Char);
    char wisdom1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &wisdom1Char);int wisdom1 = atoi(wisdom1Char);
    char charisma1Char[3] = " ";returnPersonStat("�������_������",1,0,0,&charisma1Char);int charisma1 = atoi(charisma1Char);
    char personName2[40] = " ";returnPersonStat("���_������",2,0,0, &personName2);
    char health2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &health2Char);int health2 = atoi(health2Char);
    char force2Char[3] = " ";returnPersonStat("����_������",2,0,0, &force2Char);int force2 = atoi(force2Char);
    char dexterity2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &dexterity2Char);int dexterity2 = atoi(dexterity2Char);
    char bodyType2Char[3] = " ";returnPersonStat("������������_������",2,0,0, &bodyType2Char);int bodyType2 = atoi(bodyType2Char);
    char intelligencee2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &intelligencee2Char);int intelligencee2 = atoi(intelligencee2Char);
    char wisdom2Char[3] = " ";returnPersonStat("��������_������",2,0,0, &wisdom2Char);int wisdom2 = atoi(wisdom2Char);
    char charisma2Char[3] = " ";returnPersonStat("�������_������",2,0,0,&charisma2Char);int charisma2 = atoi(charisma2Char);
    int curHealth;int curForce;int curDexterity;int curBodyType;int curIntelligencee;int curWisdom;int curCharisma;
    for (int person = 1 ; person <= 2 ; person++)
    {
        system("cls");
        printf("(M) ��������� � ����� � ������� ���� \n");
        printf("������� �������: %d\n",level);
        srand(time(0));
        char outputText[1000] = " ";
        char outputVariant1[1000] = " ";
        char outputVariant2[1000] = " ";
        char outputVariant3[1000] = " ";
        char outputVariant4[1000] = " ";
        if (person == 1)
        {
            levelStat("1_��������_�������_������_1",level,&outputVariant1);
            levelStat("1_��������_�������_������_2",level,&outputVariant2);
            levelStat("1_��������_�������_������_3",level,&outputVariant3);
            levelStat("1_��������_�������_������_4",level,&outputVariant4);
            printf("\n�������:");
            levelStat("�����_��������_1",level, &outputText);
            printText( &outputText );
            levelStat("�����_��������_2",level, &outputText);
            printText( &outputText );
            levelStat("�����_��������_3",level, &outputText);
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
            levelStat("2_��������_�������_������_1",level,&outputVariant1);
            levelStat("2_��������_�������_������_2",level,&outputVariant2);
            levelStat("2_��������_�������_������_3",level,&outputVariant3);
            levelStat("2_��������_�������_������_4",level,&outputVariant4);
            printf("\n�������:");
            char outputText[1000] = "";
            levelStat("�����_��������_1",level, &outputText);
            printf("%s", outputText);
            levelStat("�����_��������_2",level, &outputText);
            printf("%s", outputText);
            levelStat("�����_��������_3",level, &outputText);
            printf("%s", outputText);
            curHealth = health2;
            curForce = force2;
            curDexterity = dexterity2;
            curBodyType = bodyType2;
            curIntelligencee = intelligencee2;
            curWisdom = wisdom2;
            curCharisma = charisma2;
        }
        printf("\n\n��������: %d\n",person);
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
                printf("\n��� ���������\n");
                Sleep(100);
                printf("������ �����:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("���������� ������������� %d-�� ��������� �����: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("����������, �������� ���������\n");}
                else if (combinationCharacteristicPerson < cube){printf("�������� �� ��������� :( \n"); curHealth -= 1;}
                returnPersonStat("��������_������",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '2':
                cube = 1 +rand()%19;
                printf("\n��� ���������\n");
                Sleep(100);
                printf("������ �����:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("���������� ������������� %d-�� ��������� �����: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("����������, �������� ���������\n");}
                else if (combinationCharacteristicPerson < cube){printf("�������� �� ��������� :( \n"); curHealth -= 1;}
                returnPersonStat("��������_������",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '3':
                cube = 1 +rand()%19;
                printf("\n��� ���������\n");
                Sleep(100);
                printf("������ �����:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("���������� ������������� %d-�� ��������� �����: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("����������, �������� ���������\n");}
                else if (combinationCharacteristicPerson < cube){printf("�������� �� ��������� :( \n"); curHealth -= 1;}
                returnPersonStat("��������_������",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case '4':
                cube = 1 +rand()%19;
                printf("\n��� ���������\n");
                Sleep(100);
                printf("������ �����:%d\n",cube);
                Sleep(100);
                combinationCharacteristicPerson = combinationCharacteristic(curForce ,curDexterity ,curBodyType ,curIntelligencee ,curWisdom ,curCharisma);
                printf("���������� ������������� %d-�� ��������� �����: %d\n", person,combinationCharacteristicPerson);
                Sleep(100);
                if (combinationCharacteristicPerson >= cube){printf("����������, �������� ���������\n");}
                else if (combinationCharacteristicPerson < cube){printf("�������� �� ��������� :( \n"); curHealth -= 1;}
                returnPersonStat("��������_������",person,1,curHealth,&tempHealth);
                gameOver(curHealth,level);
                Sleep(1800);
                status = 0;
                break;
            case 'm':
                returnStat("�������_�������" , 1, level);
                system("cls");
                printf("������� ������� � �� ������ �����");
                mainMenu();
                break;
            }
        }
    }
    level +=1;
    returnStat("�������_�������" , 1, level);
    loadLevel(level);
}

/*������� �������*/

// ������� �� ����� � ���� ������� ������� �������������� ���� �������
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
    printf("��������: %d                                                       ��������: %d\n",person1,person2);
    printf("���: %s                                                            ���: %s\n",personName1,personName2);
    printf("��������������                                                     ��������������\n");
    printf("��������: %d                                                       ��������: %d\n",health1,health2);
    printf("����: %d                                                           ����: %d\n",force1,force2);
    printf("��������: %d                                                       ��������: %d\n",dexterity1,dexterity2);
    printf("������������: %d                                                   ������������: %d\n",bodyType1,bodyType2);
    printf("��������: %d                                                       ��������: %d\n",intelligencee1,intelligencee2);
    printf("��������: %d                                                       ��������: %d\n",wisdom1,wisdom2);
    printf("�������: %d                                                        �������: %d\n",charisma1,charisma2);
}

// ������� ������� ��������� �������������� �������� ������ � ��������� ������� (�� ����� �� ������ ����) ���������� ���������� ���� �������������
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

// �������� ������� ����������� ������� ������� ���� � � ������ ������ ������ �� ������� ����������� ���� (�� ���� ����������� �������������)
void gameOver (int health, int level)
{
    if (health <= 0)
    {
        system("cls");
        printf("\n\n\n �� ��������� :(\n");
        printf("������� (M) ��� �� ��������� � ����\n");
        printf("������� (N) ���� ������ ������ �������\n");
        printf("������� (C) ����  ������ �������� 5 �� (�������� 1 ���)\n");
        int statistic;
        int reHeal;
        while(1)
        {
            switch (_getch())
            {
            case 'c':
                reHeal = returnStat("�����������_����" , 1 ,0);
                if (reHeal == 1)
                {
                    char health1Char[3] = " ";returnPersonStat("��������_������",1,0,0, &health1Char);int health1 = atoi(health1Char);
                    health1 +=5;
                    returnPersonStat("��������_������",1,1,health1,&health1Char);
                    returnPersonStat("��������_������",2,1,5,&health1Char);
                    printf("\n�������� �������������\n");
                    Sleep(2000);
                    loadLevel(level+1);
                }
                else if (reHeal == 0)
                {
                    printf("\n�� ��� ������������ �������\n");
                    Sleep(2000);
                    gameOver(0,level);
                }
                break;
            case 'n':
                returnStat("����������_������_����", 1 , 1);
                statistic = returnStat("����������_������_����", 0 , 0);
                returnStat("�������_�������" , 1,1);
                returnStat("�����������_����" , 1 ,1);
                gameProgress(statistic);
                break;
            case 'm':
                returnStat("����������_������_����", 1 , 1);
                returnStat("�������_�������" , 1,1);
                returnStat("�����������_����" , 1 ,1);
                mainMenu();
                break;
            }
        }
    }
}

/*������ �������*/

// ������ ������� ������� �������� � �� ������ �� ��������� � ����������� ���������
void printText (char* outputText)
{
    for (int i = 0 ; i < strlen(outputText); i++)
    {
        if (outputText[i] == "\0"){break;}
        else {printf("%c", outputText[i]); Sleep(12);}
    }
}

// ������ ������� ����������� int � char ��� ������������ ������������� � ������  �������� (��� ������ � �������� linkCreator � personLinkCreator)
void intToChar (char* char_int , int level)
{
    itoa(level,char_int, 10);
}

// ������ ������� ������ ������ �� ����������� ������� ��� ���� �����  � ������� levelStat ������� ���� �� ���� ������ (������: ./levels/level_1.txt)
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

// ������ ������� ������ ������ �� ������������ ���������  ��� ���� �����  � ������� returnPersonStat ������� ���� �� ���� ������ (������: ./person/person_1.txt)
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
