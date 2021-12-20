#include"LinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* element = new Monster();

	strcpy_s(element->Name, NAME_LENGTH, name);	//strcpy 문자열을 복사한다
	element->HP = hp;

	if (list.tail == nullptr)
	{
		list.head = element;
		list.tail = element;
	}
	else
	{
		list.tail->next = element;
		list.tail = element;
	}

	return element;
}


//travers
int GetCountMonsterList(MonsterList& list)
{
	Monster* element = list.head;
	int count{ 0 };

	while (element != nullptr)
	{
		count++;
		element = element->next;
	}

	return count;
}

void PrintMonsterList(MonsterList& list)
{
	Monster* element = list.head;

	while (element != nullptr)
	{
		std::cout << element->Name << " : " << element->HP << std::endl;
		element = element->next;
	}
}

void PrintListRecursive(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}
	else
	{
		std::cout << monster->Name << " : " << monster->HP << std::endl;
		PrintListRecursive(monster->next);
	}
}

Monster* FindMonster(MonsterList& list, const char* name)
{
	Monster* result = nullptr;
	Monster* element = list.head;

	while (element != nullptr)
	{
		if (strcmp(element->Name, name) == 0)	//strcmp 문자열 비교
			return element;

		element = element->next;
	}

	return nullptr;
}

void DeleteList(MonsterList& list)
{
	Monster* element = list.head;
	Monster* next;

	while (element != nullptr)
	{
		next = element->next;
		delete element;

		element = next;
	}

	list.head = nullptr;
	list.tail = nullptr;
}

bool Delete(MonsterList& list, const char* name)
{
	Monster* element = list.head;
	Monster* previous = nullptr;

	while (element != nullptr)
	{
		if (strcmp(element->Name, name) == 0)
		{
			break;
		}

		previous = element;
		element = element->next;
	}

	if (element == nullptr)
	{
		return false;
	}

	if (list.head == list.tail)
	{
		list.head = list.tail = nullptr;
	}
	else if (previous == nullptr)
	{
		list.head = element->next;
	}
	else
	{
		previous->next = element->next;
	}

	delete element;

	return true;

}