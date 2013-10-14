//You will need this so you can make a string to throw in
// remove
#include <string>

int sizeOfArrayIndex = 0;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArraySize = hashPrimes[sizeOfArrayIndex];
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;
	}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  
}




template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
   if(numItems + numRemoved >= backingArraySize/2) {
   
		grow();
		
	}
	
	
  unsigned long index = hash(k)%backingArraySize;
  std::cout << "hashed" << std::endl;
  unsigned long curIndex = index;
  if (backingArray[curIndex].isNull) {
  
    backingArray[curIndex].isNull = false;
	std::cout << "Problem is:";
	backingArray[curIndex].k = k;
	std::cout << "adslkfjahfdklajdhflakdsfhaskjfhadslkjfhskjlfhlkh" << std::endl;
	backingArray[curIndex].x = x;
	
	numItems++;
	return;
  }

  for(int i = 0; i < (int)backingArraySize; i++) {
	curIndex = (curIndex+index)%backingArraySize;
	
	 if (backingArray[curIndex].isNull) {
		backingArray[curIndex].isNull = false;
		backingArray[curIndex].k = k;
		backingArray[curIndex].x = x;
		numItems++;
		return;
	}

	if (backingArray[curIndex].isDel) {
	  backingArray[curIndex].isDel = false;
	  backingArray[curIndex].isNull = false;
	  backingArray[curIndex].k = k;
	  backingArray[curIndex].x = x;
	  numRemoved--;
	  numItems++;
	  return;
	  }
  }
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
unsigned long index = hash(k)%backingArraySize;
 while(!(backingArray[index].isNull)) {
	if (k == backingArray[index].k) {
	  backingArray[index].isDel = true;
	  numItems --;
	  numRemoved ++;
	  }
	  index = (index+index)%backingArraySize;
  }
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if (!keyExists(k))
    throw std::string("This key does not exist. Please choose a different one");

  unsigned long index = hash(k)%backingArraySize;
 while(!(backingArray[index].isNull)) {
   if (!(backingArray[index].isDel)) {
	 if(k == backingArray[index].k) {
	    return backingArray[index].x;
	  }
	  index = (index+index)%backingArraySize;
	 }
  }
return 0;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  unsigned long index = hash(k)%backingArraySize;
  while(!(backingArray[index].isNull)) {
	if ((backingArray[index].k == k)&& !(backingArray[index].isDel))
	  return true;
	
	index = (index + index) % backingArraySize;
	}


  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	
    sizeOfArrayIndex++;
	HashTable<Key,T> secondTable;
	secondTable.backingArraySize = hashPrimes[sizeOfArrayIndex];
	secondTable.backingArray = new HashRecord[backingArraySize];
	secondTable.numItems = 0;
	secondTable.numRemoved = 0;
	numItems = 0;

	for (int i = 0; i < backingArraySize; i++) {
	std::cout<<"Done";
	  secondTable.add(backingArray[i].k,backingArray[i].x);
	  std::cout << "NOt done";
	}
	std::cout << secondTable.backingArraySize;
	delete[] backingArray;
	backingArray = secondTable.backingArray;
	backingArraySize = secondTable.backingArraySize;
	numItems = secondTable.numItems;
	numRemoved = 0;






	
	numRemoved = 0;
	

  
}
