#include <stdio.h>

void binary_search(int data[], int low, int high, int value, int *position)
{
	int mid = (low+high)/2;

	printf("Mid created - %d\n", mid);

	if(data[mid] == value){
		*position = mid;
		return;
	}
	else{
		if(value < data[mid]) binary_search(data, low, mid-1, value, position);
		else binary_search(data, mid+1, high, value, position);
		return;
	}
}

void interpolation_search(int data[], int low, int high, int value, int *position)
{
	int mid = low + (((high-low)*(value-data[low])) /(data[high]-data[low]));

	printf("Mid created - %d\n", mid);

	if(data[mid] == value){
		*position = mid;
		return;
	}
	else{
		if(value < data[mid]) interpolation_search(data, low, mid-1, value, position);
		else interpolation_search(data, mid+1, high, value, position);
		return;
	}
}

int main(void) {
 	int n, i;
 	char temp;

 	printf("Enter the size of the array - ");
 	scanf("%d", &n);

	int data[n], low = 0, high = n-1, value, position;

	printf("Enter the array - ");
	for(i=0; i<n; i++) scanf("%d", &data[i]);

	do
	{
        printf("Enter the value to search - ");
        scanf("%d", &value);

        position = -1;
        binary_search(data, low, high, value, &position);

        if(position < 0){
            printf("Value not found in the array.\n");
        }else{
            printf("Value found in postion %d\n", position);
        }

        position = -1;
        interpolation_search(data, low, high, value, &position);

        if(position < 0){
            printf("Value not found in the array.\n");
        }else{
            printf("Value found in postion %d\n", position);
        }
        scanf("%c", &temp);
        printf("More values? (Y/N) - ");
        scanf("%c", &temp);
	}while(temp != 'N' && temp != 'n');

	return 0;
}
