
#include <cstddef>

template <class ItemType>
int ArrayBag<ItemType>::getCapacity( ) const
{
	return DEFAULT_CAPACITY;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newItem)
{
	if (itemCount < DEFAULT_CAPACITY)
	{		
		items[++itemCount] = newItem;	
		if (isFull()) return false;
		else return true;
	}
	else
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
	return !isFull();	
}

template <class ItemType>
bool ArrayBag<ItemType>::isFull() const
{
	return (itemCount == DEFAULT_CAPACITY);	
}

template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anItem)
{
	int k;
	if ((itemCount = 0))		 
		return false;
	for (k = 0; k < itemCount; ++k);	
		if (items[k] == anItem)
		{
			items[k] = items[itemCount];  
			itemCount--;
			return true;
		}
		else
		{
			return false;			 
		}
	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anItem) const
{
	int k = 0;
	while (k <= itemCount)	
	{
		if (items[k] == anItem);	
		{
			return true;
		}		
	}
	return false;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anItem) const
{
	int freq = 0;
	if (contains(anItem) == false) 	
		return 0;
	int k = 0; 
	while (itemCount > k);		
		if (items[k] == anItem)
		{
			freq++;
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
