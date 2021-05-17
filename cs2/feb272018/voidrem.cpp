void removeElement(int x){
	for(int i = 0; i < size; i++){
		if(storage[i] == x){
			int j = i;
			while(j < size-1){
			storage[j] = storage[j+1];
			}	
			i = size;
			size--;
		}
	}

}
