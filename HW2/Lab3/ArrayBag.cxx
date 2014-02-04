
#include <cstddef>

template <class ItemType>
int ArrayBag<ItemType>::getCapacity( ) const
{
	return DEFAULT_CAPACITY;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newItem)
{
	if (!isFull())
	{		
		items[itemCount] = newItem;
		++itemCount;
		return true;
	}
	return false;
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return (itemCount == 0);	
}

template <class ItemType>
bool ArrayBag<ItemType>::isFull() const
{
	return (itemCount == DEFAULT_CAPACITY);	
}

template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	itemCount = 0;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anItem)
{
	for (int k = 0; k < itemCount; ++k)	
	{
		if (items[k] == anItem)
		{
			items[k] = items[itemCount-1];  
			itemCount--;
			return true;
		}
	}
	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anItem) const
{
	int k = 0;
	while (k < itemCount)	
	{
		if (items[k] == anItem)	
		{
			return true;
		}		
		k++;
	}
	return false;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anItem) const
{
	int freq = 0;
	int k = 0; 
	while (k < itemCount)		
	{
		if (items[k] == anItem)
		{
			freq++;
		}
		k++;
	}
	return freq;
}

template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int k = 0; k < itemCount; ++k)
		bagContents.push_back(items[k]);
	return bagContents;
}
