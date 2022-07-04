#include "heap.h"
heap* heap_construct(int n)
{
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}

void heap_destruct(heap* tmp)
{
    free(tmp);
}

int heap_get_capacity(heap* tmp)
{
    return tmp->capacity;
}

int heap_get_size(heap* tmp)
{
    return tmp->size;
}

int heap_insert(heap* tmp,int data)
{
    if(heap_get_size(tmp) < heap_get_capacity(tmp))
    {
        tmp->elements[tmp->size]=data;
        tmp->size++;
        return 1;
    }
    
    else
        return 0;
}

int heap_get_min(heap* tmp)
{
    int i,j,k,ele;

	for(k=1;k<heap_get_size(tmp);k++)
	{
		i=k;
		ele= tmp->elements[i];
		j=(i-1)/2;

		while((i>0)&&(ele < tmp->elements[j]))
		{
			tmp->elements[i]=tmp->elements[j];
			i=j;
			j=(i-1)/2;
		}
		tmp->elements[i]=ele;
	}
	return tmp->elements[0];
}

void heap_remove(heap* tmp)
{
    for(int i = 1; i< heap_get_size(tmp) ; i++)
        tmp->elements[i-1]=tmp->elements[i];
    tmp->size--;
}

