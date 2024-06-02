#include "push_swap.h"

void ft_bubble_sort(int *array, int len)
{
	int i;
	int j;
	int temp;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}


int *ft_fill_array(t_data *head)
{
	int i;
	int *array;
	array = malloc(sizeof(int) * ft_stacksize(head));
	if(!array)
		return NULL;
	t_data *temp;
	i = 0;
	temp = head;
	while (temp)
	{
		array[i++] = temp->value;
		temp = temp->next;
	}
	int len = ft_stacksize(head);
	i = 0;
	ft_bubble_sort(array, len);
	return array;
}
