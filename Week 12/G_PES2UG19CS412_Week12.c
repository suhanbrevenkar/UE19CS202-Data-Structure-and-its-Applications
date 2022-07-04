#include "hash.h"
HashTable *create_table(int size)
{
	// printf("Started construction...\n");
	HashTable * hash_structure;
	hash_structure->size=size;
	for(int i=0; i<size; i++){
		hash_structure->table[i]=-1;
	}
	// printf("Finished construction\n");
	return hash_structure;
}

void insert(HashTable *htable, int element)
{
	HashTable * hash_structure = htable;
	int check_full(){
		int tracker;
		for(int i=0;i<hash_structure->size;i++){
			if(hash_structure->table[i]!=-1){
				tracker++;
			}
		}
		if(tracker==hash_structure->size){
			return 0;
		}
		else{
			return 1;
		}
	}
	int hashing_function(int x, int n){
		return (x%n);
	}
	int index = hashing_function(element,hash_structure->size);
	// printf("Index = %d\n",index);
	if(check_full()!=0){
		if(hash_structure->table[index]==-1 && index<hash_structure->size){
			hash_structure->table[index]=element;
			// printf("Inserted from if\n");
		}
		else{
			while(hash_structure->table[index]!=-1 && index<=(hash_structure->size)-1){
				index++;
			}
			if(index>=(hash_structure->size)){
				// printf("Wrapping around 2\n");
				index=0;
				while(hash_structure->table[index]!=-1){
					index++;
				}
			}
			// printf("Looped index = %d\n",index);
			hash_structure->table[index]=element;
			// printf("Inserted from else\n");
		}
		// for(int i=0;i<hash_structure->size;i++){
			// printf("%d|",hash_structure->table[i]);
		// }
		// printf("\n");
	}
}

int search(HashTable *htable, int element)
{
    HashTable * hash_structure = htable;
	int hashing_function(int x, int n){
		return (x%n);
	}
	int index = hashing_function(element,hash_structure->size);
	// printf("Index for search = %d\n",index);
	if(hash_structure->table[index]==element){
		// for(int i=0;i<hash_structure->size;i++){
			// printf("%d|",hash_structure->table[i]);
		// }
		// printf("\n");
		return 1;
	}
	else{
		while(hash_structure->table[index]!=element && index<=(hash_structure->size)-1){
			// printf("In search loop\n");
			index++;
		}
		if(index>=(hash_structure->size)){
			// printf("Wrapping around 3\n");
			index=0;
			while(hash_structure->table[index]!=element && index<=(hash_structure->size)-1){
				index++;
			}
		}
		if(hash_structure->table[index]==element){
			// for(int i=0;i<hash_structure->size;i++){
				// printf("%d|",hash_structure->table[i]);
			// }
			// printf("\n");
			return 1;
		}
		else{
			// for(int i=0;i<hash_structure->size;i++){
				// printf("%d|",hash_structure->table[i]);
			// }
			// printf("\n");
			return 0;
		}
	}
}

void delete (HashTable *htable, int element)
{
	HashTable * hash_structure = htable;
	int hashing_function(int x, int n){
		return (x%n);
	}
	int index = hashing_function(element,hash_structure->size);
	// printf("Index for delete = %d\n",index);
	if(hash_structure->table[index]==element){
		hash_structure->table[index]=-1;
		return;
	}
	else{
		while(hash_structure->table[index]!=element && index<=(hash_structure->size)-1){
			// printf("In delete loop\n");
			index++;
		}
		if(index>=(hash_structure->size)){
			// printf("Wrapping around 4\n");
			index=0;
			while(hash_structure->table[index]!=element && index<=(hash_structure->size)-1){
				index++;
			}
		}
		if(hash_structure->table[index]==element){
			// printf("Element deleted - Part 2\n");
			hash_structure->table[index]=-1;
			return;
		}
		else{
			return;
		}
	}
}


void destroy_table(HashTable *htable)
{
	    free(htable);

}
