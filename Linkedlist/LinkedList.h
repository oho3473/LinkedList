#pragma once

#include"Monster.h"

struct MonsterList
{
	Monster* head = nullptr;
	Monster* tail = nullptr;
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
Monster* FindMonster(MonsterList& list, const char* name);
int GetCountMonsterList(MonsterList& list);
void PrintListRecursive(Monster* monster);
void DeleteList(MonsterList& list);
bool Delete(MonsterList& list, const char* name);