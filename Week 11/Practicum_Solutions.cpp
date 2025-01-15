#include <iostream>

const size_t SIZE = 100;

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

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
} // ne ni trqbwa

// 1
int* reverseArr(int* arr, size_t n)
{
    int* result = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        result[i] = arr[n - i - 1];
    }

    return result;
}

// 2
int* filterDivisible(const int* arr1, const int* arr2, size_t size1, size_t size2, int k, size_t& size)
{
    size_t counter1 = 0;
    for (size_t i = 0; i < size1; i++)
    {
        if (arr1[i] % k == 0)
        {
            counter1++;
        }
    }

    size_t counter2 = 0;
    for (size_t i = 0; i < size2; i++)
    {
        if (arr2[i] % k == 0)
        {
            counter2++;
        }
    }

    size = counter1 + counter2;
    int* result = new int[size];

    size_t ind = 0;
    for (size_t i = 0; i < size1; i++)
    {
        if (arr1[i] % k == 0)
        {
            result[ind] = arr1[i];
            ind++;
        }
    }

    for (size_t i = 0; i < size2; i++)
    {
        if (arr2[i] % k == 0)
        {
            result[ind] = arr2[i];
            ind++;
        }
    }

    return result;
}

// 3
// raboti ama ne kakto trqbwa
// int* moveKToRight(const int* arr, size_t size, int k, size_t& resultSize)
// {
//     if (!arr || size == 0) {
//         resultSize = 0;
//         return nullptr;
//     }
 
//     size_t resultIndex = 0;
//     size_t arrIndex = 0;
//     const int* arrPtr = arr;
//     int temp = k;
//     resultSize = size;
//     int* result = new int[resultSize];
   
//     for (size_t i = 0; i < k; i++)
//     {
//         result[resultIndex++] = arr[++temp];
//     } 
//     for (size_t i = k; i < size; i++)
//     {
//         result[resultIndex++] = arr[arrIndex++];
//     }

//     return result;
// }

// 3
int* moveKToRight(const int* arr, size_t size, int k, size_t& resultSize) {
    if (!arr || size == 0) {
        resultSize = 0;
        return nullptr;
    }

    k = k % size;

    resultSize = size;
    int* result = new int[resultSize];

    for (size_t i = 0; i < size; i++) {
        size_t newIndex = (i + k) % size;
        result[newIndex] = arr[i];
    }

    return result;
}

// 4
int* filterDivisibleByNeighbor(const int* arr, size_t size, size_t& resultSize)
{
    if (!arr) return nullptr;

    size_t count = 0;
    if (size > 1 && arr[0] % arr[1] == 0)
    {
        count++;
    }
        
    for (size_t i = 1; i < (size - 1); i++)
    {
        if (!(arr[i] % arr[i - 1]) || !(arr[i] % arr[i + 1]))
        {
            count++;
        }
    }

    if (size > 1 && arr[size - 1] % arr[size - 2] == 0)
    {
        count++;
    }

    int* result = new int[count];
    resultSize = 0;

    if (size > 1 && arr[0] % arr[1] == 0)
    {
        result[resultSize++] = arr[0];
    }
    
    for (size_t i = 1; i < size - 1; i++)
    {
        if (arr[i] % arr[i - 1] == 0 || arr[i] % arr[i + 1] == 0)
        {
            result[resultSize++] = arr[i];
        }
    }

    if (size > 1 && arr[size - 1] % arr[size - 2] == 0)
    {
        result[resultSize++] = arr[size - 1];
    }
        
    return result;
}

// 5
bool isLower(const char c)
{
    return c >= 'a' && c <= 'z';
}

bool isUpper(const char c)
{
    return c >= 'A' && c <= 'Z';
}

char* concatLowerAndUpper( const char* str1, const char* str2)
{
    size_t counter = 0;
    const char* str1Ptr = str1;
    const char* str2Ptr = str2;

    while (*str1Ptr)
    {
        if (isLower(*str1Ptr))
            counter++;
        str1Ptr++;
    }
    while (*str2Ptr)
    {
        if (isUpper(*str2Ptr))
            counter++;
        str2Ptr++;
    }

    char* result = new char[counter + 1];
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

// 6
// char* remainOnlyEdgeWords(const char* str)
// {
//     if (!str) return nullptr;

//     while (*str == ' ') 
//     {
//         str++;
//     }

//     size_t counter = 0;
//     const char* startFirstWord = str;
//     const char* endFirstWord = nullptr;
//     const char* startLastWord = nullptr;
//     const char* endLastWord = nullptr;
//     const char* startWord = nullptr;
//     const char* endWord = nullptr;
//     const char* tempStr = str;
    
//     while (*tempStr != ' ')
//     {
//         if (*tempStr != ' ' && (*(tempStr + 1) == ' ' || *(tempStr + 1) == '\0'))
//         {
//             endFirstWord = tempStr;
//         }

//         counter++;
//         tempStr++;
//     }

//     while (*tempStr)
//     {
//         if (*tempStr != ' ' && *(tempStr - 1) == ' ')
//         {
//             startWord = tempStr;
//         }
//         if (*tempStr != ' ' && *(tempStr + 1) == ' ' || *(tempStr + 1) == '\0')
//         {
//             endWord = tempStr;

//             startLastWord = startWord;
//             endLastWord = endWord;
//         }
//         tempStr++;
//     }

//     while (startWord <= endWord)
//     {
//         counter++;
//         startWord++;
//     }

//     size_t resultSize = counter + 1 + 1;     // Adding space for '\0' and ' '
//     char* result = new char[resultSize];

//     while (startFirstWord <= endFirstWord)
//     {
//         *result = *startFirstWord;
//         result++;
//         startFirstWord++;
//     }
//     *result = ' ';
//     result++;

//     while (startLastWord <= endLastWord)
//     {
//         *result = *startLastWord;
//         result++;
//         startLastWord++;
//     }
//     *result = '\0';

//     return result;
// }

int strLen(const char* str)
{
    if (!str) return 0;

    size_t size = 0;
    while (*str)
    {
        size++;
        str++;
    }

    return size;
}

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

char* reverseStr(char* str, size_t size)
{
    char* reversed = new char[size];
    for (size_t i = 0; i < size; i++)
    {
        reversed[i] = str[size - 1 - i];
    }
    reversed[size] = '\0';
    return reversed;
}

char* remainOnlyEdgeWords(char* str)
{
    if (!str) return nullptr;

    const char* strPtr = str;

    char firstWord[SIZE];
    size_t firstWordSize = 0;

    while (*strPtr != ' ' && *strPtr )
    {
        firstWord[firstWordSize++] = *strPtr;
        strPtr++;
    }
    firstWord[firstWordSize] = '\0';

    char lastWord[SIZE];
    size_t lastWordSize = 0;

    char* reversed = reverseStr(str, strLen(str));
    while (*reversed != ' ' && *reversed)
    {
        lastWord[lastWordSize++] = *reversed;
        reversed++;
    }
    lastWord[lastWordSize] = '\0';

    char* reversedLastWord = reverseStr(lastWord, lastWordSize);
    char* result = new char[firstWordSize + 1 + lastWordSize + 1];

    for (size_t i = 0; i < firstWordSize; i++)
    {
        result[i] = firstWord[i];
    }
    result[firstWordSize] = ' ';

    for (size_t i = 0; i < lastWordSize; i++)
    {
        result[firstWordSize + 1 + i] = reversedLastWord[i];
    }
    result[firstWordSize + 1 + lastWordSize] = '\0';

    return result;
}

// 7
char* insertCharAt(const char* str, const int* indexes, size_t len, const char s)
{
    size_t size = strLen(str) + len + 1;
    char* result = new char[size];
    char* resultPtr = result;

    size_t i = 0;
    size_t j = 0;
   
    while (i < strLen(str))
    {
        if (j < len && i == indexes[j]) 
        {
            *resultPtr = s;
            resultPtr++;
            j++;
        }
        else
        {
            *resultPtr = str[i];
            resultPtr++;
            i++;
        }
    }
    *resultPtr = '\0';  

    return result;
}

int main()
{
    // 1
    // const size_t n = 5;
    // int arr[n] = { 1, 2, 3, 4, 5 };
    // int* dynamicArr = reverseArr(arr, n);
    // printArray(dynamicArr, n);
    // delete[] dynamicArr;

    // 2
    // int arr1[] = {2, 4, 5, 8};
    // size_t size1 = 4;
    // int arr2[] = {3, 16, 7, 9, 10};
    // size_t size2 = 5;
    // int k = 2;
    // size_t resultSize = 0;
    // int* result = filterDivisible(arr1, arr2, size1, size2, k, resultSize);
    // std::cout << "Filtered elements divisible by " << k << ": ";
    // printArray(result, resultSize);
    // std::cout << std::endl;
    // delete[] result;

    // 3
    // int arr[] = {1, 2, 3, 4, 5};
    // size_t size = 5;
    // int k = 2;
    // size_t resultSize = 0;
    // int* result = moveKToRight(arr, size, k, resultSize);
    // printArray(result, resultSize);
    // std::cout << std::endl;
    // delete[] result;

    // 4
    // int arr[] = {5, 10, 20, 4, 2, 7};
    // size_t size = 6;
    // size_t resultSize = 0;
    // int* result = filterDivisibleByNeighbor(arr, size, resultSize);
    // printArray(result, resultSize);
    // std::cout << std::endl;
    // delete[] result;

    // 5
    // char str1[SIZE], str2[SIZE];
    // std::cin.getline(str1, SIZE);
    // std::cin.getline(str2, SIZE);
    // char* result = concatLowerAndUpper(str1, str2);
    // std::cout << result << std::endl;
    // delete[] result;

    // 6
    // char str[SIZE];
    // std::cin.getline(str, SIZE);
    // char* result = remainOnlyEdgeWords(str);
    // std::cout << result << std::endl;
    // delete[] result;

    // 7
    // char str[SIZE];
    // size_t len = 3;
    // int arr[] = {3, 13, 18};
    // char s = 't';
    // std::cin.getline(str, SIZE);
    // char* result = insertCharAt(str, arr, len, s);
    // std::cout << result << std::endl;
    // delete[] result;

    return 0;
}
