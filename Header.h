#pragma once
#include <ctime>
#include<random>
#include<fstream>
#include<string>

using namespace std;

//struct player
//{
//	int Xor0;
//};
//
//class Points
//{
//	vector<int> points;
//public:
//	Points() {}
//	void operator() (int point)
//	{
//		points.push_back(point);
//	}
//	int GetLastPoint() { return points[points.size() - 1]; }
//	bool isEmpty()
//	{
//		if (points.empty())
//			return 1;
//		else if (!points.empty())
//			return 0;
//	}
//
//	int size()
//	{
//		return points.size();
//	}
//
//	int operator ++()
//	{
//		return points[points.size() - 1]++;
//	}
//
//	int operator[] (int idx)
//	{
//		if (idx > points.size())
//			return 0;
//		return points[idx];
//	}
//
//	virtual bool CheckIsFree() { return 0; }
//};
//
//
//class Field
//{
//protected:
//	vector<int> field;
//	Points points;
//	bool end=false;
//	vector <int> Positions3{ 3,6 };
//	player human{ 1 };
//	player machine{ 2 };
//	int wins[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7},{2,5,8}, {0,4,8}, {2,4,6} };
//
//public:
//
//	Field(const Field& orig)
//	{
//		field = orig.field;
//		human.Xor0 = orig.human.Xor0;
//	}
//
//	Field()
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			field.push_back(0);
//		}
//	}
//
//	Field(bool IsFirst)
//	{
//		if (IsFirst)
//		{
//			for (int i = 0; i < 9; i++)
//			{
//				field.push_back(0);
//			}
//		}
//		else if (!IsFirst)
//		{
//			ifstream source("CloudServer.txt", ofstream::app);
//			for (int i = 0; i < 9; i++)
//			{
//				string buff;
//				getline(source, buff);
//				field.push_back( stoi(buff));
//			}
//			source.close();
//		}
//	}
//
//	size_t GetSz()
//	{
//		return field.size();
//	}
//
//	int check()
//	{
//
//		for (int i = 0; i < 8; i++)
//		{
//			int count = 0, count1 = 0;
//			for (int j = 0; j < 3; j++)
//			{
//				if (field[wins[i][j]] == human.Xor0)
//				{
//					count++;
//					end = true;
//					if (count == 3)
//						return 2;
//				}
//				if (field[wins[i][j]] == machine.Xor0)
//				{
//					count1++;
//					end = true;
//					if (count1 == 3)
//						return 1;
//				}
//				if (count == 3 || count1 == 3)
//					return 1;
//			}
//		}
//		int ifAllFill = 0;
//		for (int i = 0; i < field.size(); i++)
//		{
//			if (field[i] != 0)
//			{
//				ifAllFill++;
//			}
//		}
//		if (ifAllFill == field.size())
//		{
//			end = true;
//			return -1;
//		}
//		
//		return 0;
//	}
//
//	int operator[](int idx)
//	{
//		if (!field.empty() && idx < 9)
//			return field[idx];
//		else
//		{
//			return 0;
//		}
//	}
//
//	bool Set(int pos, bool HorM)
//	{
//		if (!HorM)
//		{
//			if (field[pos] == 1)
//			{
//				return 0;
//			}
//			field[pos] = machine.Xor0;
//			return 1;
//		}
//
//	}
//
//	int SetHuman(int pos)
//	{
//		if (field[pos] == 2)
//		{
//			return 0;
//		}
//		field[pos] = 1;
//		return pos;
//	}
//
//	~Field()
//	{
//		ofstream wrote("CloudServer.txt");
//		if (end)
//			wrote << "" << endl;
//		else if (!end)
//		{
//			for (int i = 0; i < field.size(); i++)
//			{
//				wrote << field[i] << endl;
//			}
//		}
//		wrote.close();
//	}
//};
//
//class bot : public Field, Points
//{
//	player Bot{ 2 };
//	Points p;
//	bool IsEnd=false;
//
//	int FindHuman()
//	{
//		int iterator = 0;
//
//		for (int i = 0; i < field.size(); i++)
//		{
//			if (field[i] == 1)
//			{
//				iterator = i;
//				break;
//			}
//		}
//		return iterator;
//	}
//
//public:
//	bot(const Field& f) : Field(f) {}
//	bot(bool IsFirst, const Field& f) : Field(f)
//	{
//		if (!IsFirst)
//		{
//			ifstream source("BotsCloudServer.txt", ofstream::app);
//			while (!source.eof())
//			{
//				string buff;
//				getline(source, buff);
//				p(stoi(buff));
//			}
//		}
//	}
//	int atack(Field& ToSave, Field orig)
//	{
//		if (!p.isEmpty())
//		{
//			//��������� ���//
//			if (orig[++p] != 1)
//			{
//				
//				field[++p] = 2;
//				ToSave.Set(++p, false);
//				p(++p);
//				return ++p;
//			}
//			else if (orig[++p] == 1)
//			{
//				
//				int npos = 0;
//				while (true)
//				{
//					npos = rand() % 8;
//					if (ToSave[npos] != 1)
//					{
//						field[npos] = 2;
//						ToSave.Set(npos, false);
//						p(npos);
//						return npos;
//						break;
//					}
//				}
//			}
//			0
//	
//		}
//		else if (p.isEmpty())
//		{
//			int pos = FindHuman();
//			field[pos++] == Bot.Xor0;
//			ToSave.Set(pos, false);
//			p(pos);
//			return pos;
//		}
//	}
//	~bot()
//	{
//		ofstream wrote("BotsCloudServer.txt");
//		if (IsEnd)
//			wrote << "" << endl;
//		else if (!IsEnd)
//		{
//			for (int i = 0; i < p.size(); i++)
//			{
//				wrote << p[i] << endl;
//			}
//		}
//		wrote.close();
//	}
//};
//
//void KillAll()
//{
//	ofstream wrote("CloudServer.txt", ios::trunc);
//	wrote << "" << endl;
//	wrote.close();
//}


struct player
{
	int Xor0;
};

class Field
{
protected:
	vector<int> field;
	
	bool end = false;
	vector <int> Positions3{ 3,6 };
	player human{ 1 };
	player machine{ 2 };
	int wins[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7},{2,5,8}, {0,4,8}, {2,4,6} };

public:

	Field(const Field& orig)
	{
		field = orig.field;
		human.Xor0 = orig.human.Xor0;
	}

	Field()
	{
		for (int i = 0; i < 9; i++)
		{
			field.push_back(0);
		}
	}

	Field(bool IsFirst)
	{
		if (IsFirst)
		{
			for (int i = 0; i < 9; i++)
			{
				field.push_back(0);
			}
		}
		else if (!IsFirst)
		{
			ifstream source("CloudServer.txt", ofstream::app);
			for (int i = 0; i < 9; i++)
			{
				string buff;
				getline(source, buff);
				field.push_back(stoi(buff));
			}
			source.close();
		}
	}

	size_t GetSz()
	{
		return field.size();
	}

	int check()
	{

		for (int i = 0; i < 8; i++)
		{
			int count = 0, count1 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (field[wins[i][j]] == human.Xor0)
				{
					count++;
					end = true;
					if (count == 3)
						return 2;
				}
				if (field[wins[i][j]] == machine.Xor0)
				{
					count1++;
					end = true;
					if (count1 == 3)
						return 1;
				}
				if (count == 3 || count1 == 3)
					return 1;
			}
		}
		int ifAllFill = 0;
		for (int i = 0; i < field.size(); i++)
		{
			if (field[i] != 0)
			{
				ifAllFill++;
			}
		}
		if (ifAllFill == field.size())
		{
			end = true;
			return -1;
		}

		return 0;
	}

	int operator[](int idx)
	{
		if (!field.empty() && idx < 9)
			return field[idx];
		else
		{
			return 0;
		}
	}

	bool Set(int pos)
	{
		
			if (field[pos] == 1)
			{
				return 0;
			}
			field[pos] = machine.Xor0;
			return 1;

	}

	int SetHuman(int pos)
	{
		if (field[pos] == 2)
		{
			return 0;
		}
		field[pos] = 1;
		return 1;
	}

	~Field()
	{
		
		ofstream wrote("CloudServer.txt");

		for (int i = 0; i < field.size(); i++)
		{
			
			wrote << field[i] << endl;
		}

		wrote.close();
	}
};

class bot : public Field
{
	player Bot{ 2 };
	
	int Strotegy;
	bool IsEnd = false;

	int FindHuman()
	{
		int iterator = 0;

		for (int i = 0; i < field.size(); i++)
		{
			if (field[i] == 1)
			{
				iterator = i;
				break;
			}
		}
		return iterator;
	}

public:
	bot(const Field& f) : Field(f) {}
	bot(bool IsFirst, const Field& f, int st) : Field(f), Strotegy(st)
	{

	}
	//int atack(Field& ToSave, Field orig)
	//{
	//	if (!p.isEmpty())
	//	{
	//		//��������� ���//
	//		if (orig[++p] != 1)
	//		{
	//		
	//			field[++p] = 2;
	//			ToSave.Set(++p, false);
	//			p(++p);
	//			return ++p;
	//		}
	//		else if (orig[++p] == 1)
	//		{
	//			
	//			int npos = 0;
	//			while (true)
	//			{
	//				npos = rand() % 9;
	//				if (ToSave[npos] != 1)
	//				{
	//					field[npos] = 2;
	//					ToSave.Set(npos, false);
	//					p(npos);
	//					return npos;
	//					break;
	//				}
	//			}
	//		}


	//	}
	//	else if (p.isEmpty())
	//	{
	//	
	//		int pos = FindHuman();
	//		field[pos++] == Bot.Xor0;
	//		ToSave.Set(pos, false);
	//		p(pos);
	//		return pos;
	//	}
	//}

	int AttackTest(Field& ToSave, Field orig)
	{
	

		for (int j = 0; j < 3; j++)
		{
			if (orig[wins[Strotegy][j]] == 0)
			{
				int point = wins[Strotegy][j];
				
				field[wins[Strotegy][j]] == Bot.Xor0;
				ToSave.Set(wins[Strotegy][j]);
				return point;

			}
			else
			{
				int point1 = rand() % 9;
				field[point1] == Bot.Xor0;
				ToSave.Set(point1);
				return point1;
			}
		}


	}

	~bot()
	{

	}
};