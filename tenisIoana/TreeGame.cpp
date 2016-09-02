#include "TreeGame.h"

TreeGame::TreeGame(std::vector<Player*>* names)
{
	this->root = buildTree(names);
}

TreeGame::TreeGame(char* pathPlayers, char* pathsCourts)
{
	vector<Player*> players;
	vector<string> strings;
	FILE * f = fopen(pathPlayers,"r");
	char buffer[100];
	while (!feof(f))
	{
		fgets(buffer, 100, f);
		Util::split(buffer, '*', strings);
		Player*p = new Player(strings[1],0,atoi(strings[0].c_str()),strings[2]);
		players.push_back(p);
	}
	fclose(f);
	f = fopen(pathsCourts, "r");
	TenisCourt dummy;
	availableCourts.push_back(dummy.load(f));
	availableCourts.push_back(dummy.load(f));
	availableCourts.push_back(dummy.load(f));
	availableCourts.push_back(dummy.load(f));
}

TreeGame::~TreeGame()
{
}

Game* TreeGame::buildTree(std::vector<Player*>* list)
{
	if (list->size() == 1)
	{
		return new Game(list->at(0));
	}
	std::vector<Player*>*  leftList = new std::vector<Player*>();
	std::vector<Player*>*  rightList = new std::vector<Player*>();
	while (list->size() >= 2)
	{
		int rand_left = Util::randInt(0, list->size() - 1);
		Player* strLeft = list->at(rand_left);
		list->erase(list->begin() + rand_left);
		leftList->push_back(strLeft);
		int rand_right = Util::randInt(0, list->size() - 1);
		Player* strRight = list->at(rand_right);
		list->erase(list->begin() + rand_right);
		rightList->push_back(strRight);
	}
	if (list->size() > 0)
	{
		leftList->push_back(list->at(0));
	}
	return new Game(buildTree(std::move(leftList)),
		buildTree(std::move(rightList)));
}

Game* TreeGame::find(Game *start, string player)
{
	if (start == nullptr)
		return nullptr;
	Game* ret = nullptr;
	if (start->getPlayer()->getNume() == player)
		return  start;
	ret = find(start->getPlayerLeft(), player);
	if (ret)
		return ret;
	ret = find(start->getPlayerRight(), player);
	return ret;
}

Game* TreeGame::GetByName(string player)
{
	if (this->root->getPlayer()->getNume() == player)
		return this->root;
	return nullptr;
}

void TreeGame::AddGames(const char* file)
{

	FILE * f = fopen(file, "r");
	while (!feof(f))
	{
		queue<Game*> que;
		if (!root)
			return;

		Game *tmp, *l, *r;
		que.push(root);
		que.push(NULL);
		char buffer[100];
		while (!que.empty())
		{
			tmp = que.front();
			que.pop();
			if (tmp != NULL)
			{
				string text = fgets(buffer, 100, f);
				
				l = tmp->getPlayerLeft();
				r = tmp->getPlayerRight();
				if (l) que.push(l);
				if (r) que.push(r);
			}
			else
			{
				if (!que.empty())
					que.push(NULL);
			}
		}
	}
}