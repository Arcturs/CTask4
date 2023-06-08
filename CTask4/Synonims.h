#pragma once
#include <vector>
#include <cstring>
#include <random>

class Synonims
{
private:
	std::random_device rnd;
	CStringArray words;
	std::vector<int> positions;

public:
	Synonims();
	~Synonims();

	CString getSynonim(CString word);
	void addSynonim(CString word);
	void addWord(CString word);
	int findWordIndex(CString word);
	bool isEmpty();
};

