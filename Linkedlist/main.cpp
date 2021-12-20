#include<iostream>
#include"Monster.h"
#include"LinkedList.h"

int main()
{
	MonsterList myList;

	Monster* newMonster = nullptr;

	CreateMonster(myList, "Demon", 100);
	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 5);

	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Delete(myList, "Wolf");
	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;
	
	Delete(myList, "Slime");
	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Delete(myList, "Demon");
	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	DeleteList(myList);

}