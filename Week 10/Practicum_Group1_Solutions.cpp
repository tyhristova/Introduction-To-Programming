#include <iostream>

void readArray(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

size_t strLen(const char* str)
{
    if (!str) return 0;

    size_t counter = 0;

    while (*str)
    {
        counter++;
        str++;
    }

    return counter;
}

// Задача 1. Напишете функция, която приема като вход два символни низа и връща втори низ,
// за който е заделено точно количество памет, представляващ конкатенация на двата входни
// масива.

char* concat(const char* str1, const char* str2, size_t& size)
{
    if (!str1 || !str2) return nullptr;

    size_t lenStr1 = strLen(str1);
    size_t lenStr2 = strLen(str2);

    size = lenStr1 + lenStr2 + 1; 
    char* result = new char[size];

    for (size_t i = 0; i < lenStr1; i++)
    {
        result[i] = str1[i];
    }

    for (size_t i = lenStr1; i < size; i++)
    {
        result[i] = *str2;
        str2++;
    }
    result[size] = '\0';

    return result;
}

// Задача 2. Напишете функция, която приема като вход два символни низа и връща втори низ,
// за който е заделено точно количество памет, които конкатенира малките букви от първия
// масив с големите букви от вторите.

bool isUpper(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

char* concatLowerAndUpper(const char* str1, const char* str2, size_t& size)
{
    if (!str1 || !str2) return nullptr;

    const char* ptr1 = str1;
    const char* ptr2 = str2;

    while (*ptr1)
    {
        if (isLower(*ptr1))
        {
            size++;
        }
        ptr1++;
    }

    while (*ptr2)
    {
        if (isUpper(*ptr2))
        {
            size++;
        }
        ptr2++;
    }

    char* result = new char[size + 1];
    char* resultPtr = result;

    while (*str1)
    {
        if (isLower(*str1))
        {
            *resultPtr = *str1;
            resultPtr++;
        }
        str1++;
    }

    while (*str2)
    {
        if (isUpper(*str2))
        {
            *resultPtr = *str2;
            resultPtr++;
        }
        str2++;
    }
    *resultPtr = '\0';

    return result;
}

// Задача 3. Напишете функция, която приема като вход символен низ и връща втори низ,
// за който е заделено точно количество памет, който представлява обърнат огледално
// подаденият низ.

char* reverseStr(const char* str, size_t& size)
{
    if (!str) return nullptr;

    size_t lenStr = strLen(str);
    size = lenStr + 1;
    char* result = new char[size];

    for (size_t i = 0; i < lenStr; i++)
    {
        result[i] = str[lenStr - i - 1];
    }
    result[size] = '\0';

    return result;
}

// Задача 4. Да се напише функция, която приема като вход 2 масива от цели числа с 
// произволна големина, както и число К. Функцията да връща нов масив, за който е заделено
// точно количество памет, който да е съставен само от числата, съдържащи се в двата масива,
// които се делят на К.

// The fun diplicates nums => incorrect
int* filterDivisibleByK(const int* arr1, const int* arr2, size_t size1, size_t size2, size_t& size, int k)
{
    if (!arr1 || !arr2 || k == 0) return nullptr;

    size = 0;
    for (size_t i = 0; i < size1; i++)
    {
        if (arr1[i] % k == 0)
        {
            size++;
        }
    }

    for (size_t i = 0; i < size2; i++)
    {
        if (arr2[i] % k == 0)
        {
            size++;
        }
    }

    int* result = new int[size];
    int* resPtr = result;
    for (size_t i = 0; i < size1; i++)
    {
        if (arr1[i] % k == 0)
        {
            *resPtr = arr1[i];
            resPtr++;
        }
    }

    for (size_t i = 0; i < size2; i++)
    {
        if (arr2[i] % k == 0)
        {
            *resPtr = arr2[i];
            resPtr++;
        }
    }

    return result;
}

bool existsInArr(const int* arr, size_t size, int value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value) return true;
    }

    return false;
}

// Second attempt
int* filterDivisible(const int* arr1, const int* arr2, size_t size1, size_t size2, size_t& size, int k)
{
    if (!arr1 || !arr2 || k == 0) return nullptr;

    size_t tempSize = size1 + size2;
    int* tempResult = new int[tempSize];

    size = 0;
    for (size_t i = 0; i < size1; i++)
    {
        if (arr1[i] % k == 0 && !existsInArr(tempResult, tempSize, arr1[i]) && existsInArr(arr2, tempSize, arr1[i]))
        {
            tempResult[size++] = arr1[i];
        }
    }

    for (size_t i = 0; i < size1; i++)
    {
        if (arr2[i] % k == 0 && !existsInArr(tempResult, tempSize, arr2[i]) && existsInArr(arr1, tempSize, arr2[i]))
        {
            tempResult[size++] = arr2[i];
        }
    }

    int* result = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = tempResult[i];
    }

    delete[] tempResult;
    return result;
}

// Задача 5. Да се напише функция, която приема символен низ, и връща нов низ,
// за който е заделено точно количество памет, в който са премахнати всички повтарящи
// се символи.

bool existsInStr(const char* str, char c)
{
    while (*str)
    {
        if (*str == c) return true;
        str++;
    }
    return false;
}

char* removeDuplicates(const char* str, size_t& size)
{
    if (!str) return nullptr;

    size_t tempSize = strLen(str) + 1;
    char* tempResult = new char[tempSize];

    size = 0;
    while (*str)
    {
        if (!existsInStr(tempResult, *str)) 
        {
            tempResult[size++] = *str;
        }
        str++;
    }
    
    char* result = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = tempResult[i];
    }
    result[size] = '\0';

    delete[] tempResult;
    return result;
}

// Задача 6. От стандартния вход се въвежда естествено число n. След това на нови редове се
// въвеждат два низа с дължина n. Да се напише функция, която връща низ, за който е заделено
// точно количество памет, представляващ най - дългия общ префикс на двата входни масива.

char* getLongestCommonPrefix(const char* str1, const char* str2, size_t& size)
{
    if (!str1 || !str2) return nullptr;

    const char* ptr1 = str1;
    const char* ptr2 = str2;

    size = 0;
    while (*ptr1 == *ptr2 && *ptr1 && *ptr2)
    {
        ptr1++;
        ptr2++;
        size++;
    }

    char* result = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = str1[i];
    }
    result[size] = '\0';

    return result;
}

// Задача 7. Да се напише функция, която приема едно число num от тип long и два числа n и m
// от тип int. Функцията да връща целочислен масив масив, за който е заделено точно
// количество памет, за който всеки елемент е цифра на num, като са разменени цифрите
// на позиции k и m. Започваме да броим от едно, от ляво на дясно.

int getNumLen(long long num)
{
    if (num == 0) return 0;

    size_t counter = 0;
    while (num)
    {
        counter++;
        num /= 10;
    }

    return counter;
}

int* itoa(long long num, size_t& size)
{
    size = getNumLen(num);

    int* numArr = new int[size];
    int ind = size - 1;
    while (ind >= 0)
    {
        numArr[ind--] = num % 10;
        num /= 10;
    }

    return numArr;
}

void swap(int* arr, int n, int m)
{
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

int* tranformToNumAndChangeInds(long long num, int n, int m, size_t& size)
{
    size = 0;
    int* result = itoa(num, size);
    swap(result, n, m);

    return result;
}


// produljenieto e ot zadachata na Desi
int atoi(const int* beg, const int* end)
{
    int res = 0;

	while (beg <= end)
	{
		res *= 10;
		res += *beg;
		beg++;
	}

	return res;
}

bool isDivByT(int num, int t)
{
	return num % t == 0;
}

int main()
{
    // 1
    // const char* str1 = "mah";
    // const char* str2 = "murluk";
    // size_t size = 0;

    // char* result = concat(str1, str2, size);
    // std::cout << result << std::endl;
    // delete[] result;
    
    // 2
    // const char* str1 = "Abc24-d";
    // const char* str2 = "AW?--12bF";
    // size_t size = 0;

    // char* result = concatLowerAndUpper(str1, str2, size);
    // std::cout << result << std::endl;
    // delete[] result;

    // 3
    // const char* str = "abcd123";
    // size_t size = 0;

    // char* result = reverseStr(str, size);
    // std::cout << result << std::endl;
    // delete[] result;

    // 4
    // const int arr1[] = {1, 3, 6, 7, 8, 2};
    // size_t size1 = 6;
    // const int arr2[] = {2, 5, 7, 3, 9, 6, 11};
    // size_t size2 = 7;
    // size_t size = 0;
    // int k = 3;
    // int* result = filterDivisible(arr1, arr2, size1, size2, size, k);
    // printArray(result, size);
    // delete[] result;

    // 5
    // const char* str = "abcdaattrewb";
    // size_t size = 0;
    // char* result = removeDuplicates(str, size);
    // std::cout << result << std::endl;
    // delete[] result;

    // 6
    // const char* str1 = "This is a lovely morning";
    // const char* str2 = "This is a beautiful morning";
    // size_t size = 0;
    // char* result = getLongestCommonPrefix(str1, str2, size);
    // std::cout << result << std::endl;
    // delete[] result;

    // 7
    long long num = 1234567;
    int n = 4, m = 3;
    size_t size = 0;
    int* result = tranformToNumAndChangeInds(num, n, m, size);
    printArray(result, size);
    delete[] result;

    return 0;
}
