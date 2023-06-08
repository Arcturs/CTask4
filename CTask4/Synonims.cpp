#include "pch.h"
#include "Synonims.h"

using namespace std;

Synonims::Synonims()
{
}

Synonims::~Synonims()
{
}

CString Synonims::getSynonim(CString word)
{
	mt19937 gen(rnd());
	int wordIndex = findWordIndex(word);
	int firstIndex = positions[wordIndex];
	if (firstIndex == words.GetSize() - 1) {
		return word;
	}
	firstIndex++;
	int lastIndex;
	if (wordIndex == positions.size()) {
		lastIndex = words.GetSize() - 1;
	}
	else {
		lastIndex = positions[wordIndex + 1] - 1;
	}

	uniform_int_distribution<> dist(firstIndex, lastIndex);
	return words[dist(gen)];
}

void Synonims::addSynonim(CString word)
{
	words.Add(word);
}

void Synonims::addWord(CString word)
{
	positions.push_back(words.GetSize());
	addSynonim(word);
}

int Synonims::findWordIndex(CString word)
{
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		CString synonim = words.GetAt(*it);
		if (word.Compare(synonim)) {
			return distance(positions.begin(), it);
		}
	}
}

bool Synonims::isEmpty()
{
	return words.IsEmpty();
}
