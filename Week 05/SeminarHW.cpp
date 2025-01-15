#include <iostream>

int main(){

	size_t n = 0;

	std::cout << "Please enter the size of the first array: ";
	std::cin >> n;
	int arr1[n];

	std::cout << "Please enter the elements of the first sorted array: ";
	for(size_t i = 0; i < n; i++)
	{
		std::cin >> arr1[i];
	}

	size_t m = 0;

	std::cout << "Please enter the size of the second array: ";
	std::cin >> m;
	int arr2[m];

	std::cout << "Please enter the elements of the second sorted array: ";
	for(size_t i = 0; i < m; i++)
	{
		std::cin >> arr2[i];
	}

	int finalArr[n + m];
	size_t i = 0, j = 0, k = 0;

	while(i < n && j < m)
	{
		if(arr1[i] <= arr2[j])
		{
			finalArr[k] = arr1[i];
			i++;
		}
		else
		{
			finalArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	 while (i < n) 
	{
        finalArr[k] = arr1[i];
        i++;
        k++;
    }

	 while (j < m) 
	{
        finalArr[k] = arr2[j];
        j++;
        k++;
    }

	
	std::cout << "This is the final array: ";
	for(size_t i = 0; i < n + m; i++)
	{
		std::cout << finalArr[i];
	}


    return 0;
}
