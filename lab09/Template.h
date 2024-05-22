#pragma once

template<typename K, typename V>
class Map {
	struct Pair {
		K key;
		V value;
		int index;
	};
	Pair* pairs;
	int indexcurent;
	int maxelemente;
public:
	Map()
	{
		this->maxelemente = 10;
		this->pairs = new Pair[this->maxelemente];
		this->indexcurent = 0;
	}
	~Map()
	{
		if (pairs != nullptr)delete[] pairs;
		this->maxelemente = 0;
		this->indexcurent = 0;
	}

	V& operator[](K cheie)
	{
		int i;
		for (i = 0; i < this->indexcurent; i++)
			if (this->pairs[i].key == cheie)
				return this->pairs[i].value;

		//in caz ca nu avem deja acea cheie:
		Pair* elnou = new Pair[this->maxelemente];
		for (i = 0; i < this->indexcurent; i++)
		{
			elnou[i].key = this->pairs[i].key;
			elnou[i].value = this->pairs[i].value;
			elnou[i].index = this->pairs[i].index;
		}
		elnou[this->indexcurent].key = cheie;
		elnou[this->indexcurent].value = 0;
		elnou[this->indexcurent].index = this->indexcurent;

		this->indexcurent++;

		if (this->pairs != nullptr)delete[] pairs;

		pairs = new Pair[this->indexcurent];

		for (i = 0; i < this->indexcurent; i++)
		{
			this->pairs[i].key = elnou[i].key;
			this->pairs[i].value = elnou[i].value;
			this->pairs[i].index = elnou[i].index;
		}
		if (elnou != nullptr)delete[] elnou;
		return this->pairs[this->indexcurent - 1].value;
	}

	//pt iterator:
	class Iterator
	{
		Pair* p;

		Iterator operator!=(Iterator& a)
		{
			return p != a.p;
		}

		Iterator operator++()
		{
			p++;
			return *this;
		}

		int operator*()
		{
			return *p;
		}
	};

	Pair* begin()
	{
		return &pairs[0];
	}

	Pair* end()
	{
		return &pairs[this->indexcurent];
	}

	//Functii:
	void Set(V val, K cheie)
	{
		int i, ok = 0;
		for (i = 0; i < indexcurent; i++)
			if (pairs[i].key == cheie)
			{
				ok = 1;
				pairs[i].value = val;
			}
		if (ok == 0)
		{
			pairs[indexcurent].key = cheie;
			pairs[indexcurent].value = val;
			pairs[indexcurent].index = this->indexcurent;
			this->indexcurent++;
		}
	}

	//Get
	bool Get(const K& key, V& value)
	{
		int i, ok = 0;
		for (i = 0; i <= indexcurent; i++)
			if (pairs[i].key == key)
			{
				ok = 1;
				value = pairs[i].value;
			}
		if (ok == 1)return true;
		else return false;
	}

	//Count
	int Count()
	{
		return this->indexcurent;
	}

	//Clear
	void Clear()
	{
		this->indexcurent = 0;
		pairs = nullptr;
		delete pairs;
	}

	//Delete
	bool Delete(const K& key)
	{
		int i, j;
		for (i = 0; i <= indexcurent; i++)
			if (pairs[i].key == key)
			{
				for (j = i + 1; j < indexcurent; j++)
				{
					pairs[j].index--;
					pairs[j - 1] = pairs[j];
				}
				indexcurent--;
				return true;
			}
		return false;
	}

	//Includes
	bool Includes(const Map<K, V>& map)
	{
		K cheie;
		int i, j, ok;
		for (i = 0; i < map.indexcurent; i++)
		{
			ok = 0;
			cheie = map[i].key;
			for (j = 0; j < indexcurent; j++)
				if (pairs[i].key == cheie)ok = 1;
			if (ok == 0)return false;
		}
		return true;
	}
};