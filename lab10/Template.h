#pragma once
#include <exception>

using namespace std;

class exceptie2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}
};
template<typename T>
int compare(T x, T y)
{
	return (x > y);
}
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class Comparatie : public Compare {
public:
	int CompareElements(void* e1, void* e2)
	{
		int* x = static_cast<int*>(e1);
		int* y = static_cast<int*>(e2);
		if (*x < *y) {
			return 1;
		}
		else if (*x > *y) {
			return -1;
		}
		else {
			return 0;
		}
	}
};

template<class T>


class Array
{
private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array() {
		Capacity = 0;
		Size = 0;
		List = new T * [Capacity];

	}
	~Array()
	{
		/*for (int i = 0;i < Size;i++)
			delete[] List;*/
		List = nullptr;
		delete[] List;
		this->Capacity = 0;
		this->Size = 0;
	}

	Array(int capacity) {
		int i;
		Capacity = capacity;
		Size = 0;
		List = new T * [Capacity];

	}

	class ArrayIterator
	{
	private:

		int Current; // mai adaugati si alte date si functii necesare pentru iterator
		T** newList;
		int elemente;
	public:

		ArrayIterator() {}
		ArrayIterator(T** newList, int Current) : newList(newList), Current(Current) {}


		ArrayIterator& operator ++ () {
			Current++;
			return *this;
		}

		ArrayIterator& operator -- () {
			Current--;
			return *this;
		}

		bool operator== (ArrayIterator& array2) {
			return Current == array2.Current;
		}

		bool operator!=(ArrayIterator& array2) {
			return Current != array2.Current;
		}
		auto operator* () const {
			return newList[Current];
		}
		T* GetElement() {
			return newList[Current];
		}

	};

	ArrayIterator GetBeginIterator() {
		return ArrayIterator(List, 0);
	}

	ArrayIterator& GetEndIterator() {
		return (ArrayIterator&)ArrayIterator(List, Size);
	}

	ArrayIterator begin() {
		return ArrayIterator(List, 0);
	}

	ArrayIterator end() {
		return ArrayIterator(List, Size);
	}

	T& operator[] (int index) {
		exceptie2 index_out_of_bounds;
		try {
			if (index<0 || index > Size - 1)
				throw index_out_of_bounds;
			else
				return *List[index];
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	Array(const Array<T>& otherArray) {
		List = new T * [otherArray.Capacity];
		for (int i = 0; i < otherArray.Capacity; i++) {
			List[i] = otherArray.List[i];
		}
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
	}


	const Array<T>& operator+=(const T& newElem) {
		if (Size == Capacity)
			Capacity = Capacity * 2;
		List[Size] = new T(newElem);
		Size++;

		return *this;

	}

	const Array<T>& Insert(int index, const T& newElem) {

		exceptie2 index_out_of_bounds;
		try {
			if (index<0 || index > Size)
				throw index_out_of_bounds;
			else
			{
				Capacity = Capacity * 2;
				Size++;
				for (int i = Size; i >= index; i--)
					List[i] = List[i - 1];
				List[index] = new T(newElem);
			}
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}

	}
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		exceptie2 index_out_of_bounds; int i, j;
		try {
			if (index<0 || index > Size)
				throw index_out_of_bounds;
			else
			{
				Capacity *= otherArray.Capacity;
				T** newList;
				newList = new T * [Capacity];

				for (i = 0; i <= index; i++)
					newList[i] = List[i];

				for (i = index + 1, j = 0; i <= index + otherArray.Size; i++, j++)
					newList[i] = otherArray.List[j];

				int Size2 = otherArray.Size + Size;
				for (i = index + otherArray.Size + 1, j = index; i <= Size2, j < Size; i++, j++)
					newList[i] = List[j];

				List = nullptr;
				delete[] List;

				List = new T * [Capacity];

				Size = Size2;
				for (i = 0; i < Size; i++)
					List[i] = newList[i];

				Size += otherArray.Size;
			}
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Delete(int index)
	{
		exceptie2 index_out_of_bounds;
		try {
			if (index<0 || index > Size - 1)
				throw index_out_of_bounds;
			else
			{
				for (int i = index; i < Size; i++)
					List[i] = List[i + 1];
				Size--;
				return *this;
			}
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}


	bool operator=(const Array<T>& otherArray) {
		if (this == &otherArray) {
			return true;
		}
		Capacity = otherArray.Capacity;
		for (int i = 0; i < otherArray.Size; i++) {
			List[i] = otherArray.List[i];
		}

		return true;
	}



	void Sort()
	{
		int i, j; T* aux;
		for (i = 0; i < Size - 1; i++)
			for (j = i + 1; j < Size; j++)
				if (List[i] > List[j])
				{
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}

	void Sort(int(*compare)(const T&, const T&)) {
		int i, j; T* aux;
		for (i = 0; i < Size - 1; i++)
			for (j = i + 1; j < Size; j++)
				if (compare(*List[i], *List[j]) > 0)
				{
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}

	void Sort(Compare* comparator)
	{
		int i, j; T* aux;
		for (i = 0; i < Size - 1; i++)
			for (j = i + 1; j < Size; j++)
				if (comparator->CompareElements(&List[i], &List[j]) > 0)
				{
					aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}




	int BinarySearch(const T& elem)
	{
		int l = 0, r = Size - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (*List[m] == elem)
				return m;
			if (*List[m] < elem)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int l = 0, r = Size - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int cmp = compare(*List[m], elem);
			if (cmp == 0)
				return m;
			if (cmp < 0)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator) {

		int l = 0, r = Size - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int cmp = comparator->CompareElements(&List[m], &elem);
			if (cmp == 0)
				return m;
			if (cmp < 0)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}



	int Find(const T& elem) {
		int i;
		for (i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		int i;
		for (i = 0; i < Size; i++)
		{
			int cmp = compare(*List[i], elem);
			if (cmp == 0)
				return i;
		}
		return -1;
	}

	int Find(const T& elem, Compare* comparator)
	{
		int i;
		for (i = 0; i < Size; i++)
		{
			int cmp = comparator->CompareElements(&List[i], &elem);
			if (cmp == 0)
				return i;
		}
		return -1;
	}



	int GetSize() {
		return Size;
	}

	int GetCapacity() {
		return Capacity;
	}

	void Print() {
		for (int i = 0; i < Size; i++) {
			cout << *List[i] << " ";
		}
		cout << endl;
	}

};