#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

/*�������� ����������*/

// ������� ������� ��������� �������� �������� � ����� ����� �������� ������� ����
void startGame();

// ������� ����������� �������� �������� (� ������ ������� ���������� �������� ����, ����� �������������� ����� �� �������)
void loading();

// ������� ��������� �� ����� ������� ���� (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)
void mainMenu();

// ������� ��������� ���������� ������ ���� � ����� ����� �������� ������� ��������� ������ (� ������ ������ ��������� �� ������ � ���������� � ������� ����)
void gameMenu ();

// ������� ��������� �� �����  ���� ������ (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(� ������ ������ ��������� ���������)
void exitGame();

// ������� ��������� �� �����  ���� ������  (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(���������� �� ��������� �������� ���� � ����� statistic.txt)
void reset();

// ������� ��������� �� �����  ���� ��������  (����� ������ ������ � ����������� ���� ���� �� ����� ������ ������ ������)(������� �������� �������� � ����� statistic.txt )
void settings ();

/*�������� ���������*/

// ������� ������ ��������� �������������� (�����������) � ����� �����
void createPerson(int person);

// ������� ������������ ���� ������������ ���������
void gamePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� ���� ���������
void forcePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� �������� ���������
void dexterityPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� ������������ ���������
void bodyTypePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� ��������� ���������
void intelligenceePointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� �������� � ���������
void wisdomPointsAdder(int person,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ������������ ���� ������� ���������
void charismaPointsAdder(int person ,char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

// ������� ��������� �������������� ���������  person � ���� ��� ������������ ������
void personFileSaver(int person, char*personNamePtr,int*gamePointsPtr, int*forcePtr, int*dexterityPtr, int*bodyTypePtr, int*intelligenceePtr, int*wisdomPtr, int*charismaPtr);

/*���������� ����������*/

// ������� ��������� ������������� ������ ������� �� 0 �� countOfLevels (� ������ ���������� ����� ������)
void fileChecker(bool*error , int countOfLevels);

// ������� ���������� ��������  ���� word �� ����� ���������� (� ������ ���� status ����� 1 ����� ������ �������� ����� ���� )
int returnStat (char* word,int status , int index);

// ������� ���������� ��������  ���� word �� ����� level � ������ outputText
int levelStat (char* word,int level, char* outputText);

// ������� ���������� ��������  ���� word �� ����� person (� ������ ���� status ����� 1 ����� ������ �������� ����� ���� )
void returnPersonStat (char* word,int person, int status , int index, char*result);

/*��������� ������*/

// ������� ������������ ���������� ������ ���� � � ������ ���� ��� ����� 1 �� ������� ����� ���� (������ ����������)
void gameProgress (int statistic);

// ������� �������������� ����� ������� ����� ������� � ����������� �� ������
void loadLevel(int level);

// ������� ��������� ��������� ������� ( ���������� �����������: ����������� ���������, ��������� � ����� ��� �� ������ ����)
void startLevelLoader ();

// ������� ��������� ������� ������� (����� ��������, ������ �������, �� �������������� ), ���� ��� ���� ������� ����� ������� ����� , ������������ ��� � ������ ���������
void currentLevelLoader (int level);

/*������� �������*/

// ������� �� ����� � ���� ������� ������� �������������� ���� �������
void playerStatPrint(int person1 ,char*personNamePtr1,int*healthPtr1,int*forcePtr1, int*dexterityPtr1, int*bodyTypePtr1, int*intelligenceePtr1, int*wisdomPtr1, int*charismaPtr1, int person2,char*personNamePtr2,int*healthPtr2,int*forcePtr2, int*dexterityPtr2, int*bodyTypePtr2, int*intelligenceePtr2, int*wisdomPtr2, int*charismaPtr2);

// ������� ������� ��������� �������������� �������� ������ � ��������� ������� (�� ����� �� ������ ����) ���������� ���������� ���� �������������
int combinationCharacteristic(int curForce ,int curDexterity ,int curBodyType ,int curIntelligencee ,int curWisdom ,int curCharisma);

// �������� ������� ����������� ������� ������� ���� � � ������ ������ ������ �� ������� ����������� ���� (�� ���� ����������� �������������)
void gameOver (int health, int level);

/*������ �������*/

// ������ ������� ������� �������� � �� ������ �� ��������� � ����������� ���������
void printText (char* outputText);

// ������ ������� ����������� int � char ��� ������������ ������������� � ������  �������� (��� ������ � �������� linkCreator � personLinkCreator)
void intToChar (char* char_int , int level);

// ������ ������� ������ ������ �� ����������� ������� ��� ���� �����  � ������� levelStat ������� ���� �� ���� ������ (������: ./levels/level_1.txt)
void linkCreator (char* result, int levelNumber);

// ������ ������� ������ ������ �� ������������ ���������  ��� ���� �����  � ������� returnPersonStat ������� ���� �� ���� ������ (������: ./person/person_1.txt)
void personLinkCreator (char* result, int person);

#endif // GAMEENGINE_H_INCLUDED
