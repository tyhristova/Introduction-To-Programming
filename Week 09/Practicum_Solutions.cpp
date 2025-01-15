#include <iostream>

const size_t SIZE = 50;
const size_t ARRAY_SIZE = 10;

int myStrLen(const char* str)
{
    if(str == nullptr) return -1;

    size_t counter = 0;
    while(*str)
    {
        counter++;
        str++;
    }
    return counter;
}

int myStrCmp(const char* str1, const char* str2) {
    if (!str1 || !str2) {
        return 128;
    }
    while ((*str1) == (*str2) && (*str1)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

// 1
void removeSymbol(char* text, const char symbol)
{
    char* writePtr = text;
    char* readPtr = text;

    while(*readPtr != '\0')
    {
        if(*readPtr != symbol)
        {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }
    *writePtr = '\0';
}

// 2
char* replaceWord(char* text, const char* where, const char* what)
{
    size_t whereLen = myStrLen(where);
    size_t whatLen = myStrLen(what);
    size_t textLen = myStrLen(text);

    size_t startIndex = 0;
    size_t endIndex = 0;
    bool isMatch = false;

    for (size_t i = 0; i < textLen; i++)
    {
        if (text[i] == where[0])
        {
            startIndex = i;
            size_t t = i;
            for (size_t j = 0; j < whereLen; j++, t++)
            {
                if (t < textLen && text[t] != where[j]) 
                {
                    isMatch = false;
                    break;
                }

                if (j == whereLen - 1) 
                {
                    isMatch = true;
                    endIndex = t;
                }
            }

            if (isMatch) 
            {
                // check the size

                if (whatLen == whereLen) 
                {
                    size_t counter = 0;
                    for (size_t k = startIndex; k <= endIndex; k++) 
                    {
                        text[k] = what[counter++];
                    }
                }

                // else if (whatLen - whereLen < 0) -> increse ??? the length(move characters with that many symbols)
                // Shrink the length
                else if (whatLen < whereLen)
                {
                    size_t counter = 0;
                    for (size_t k = startIndex; k < startIndex + whatLen; k++) 
                    {
                        text[k] = what[counter++];
                    }
                    
                    size_t diff = whereLen - whatLen;
                    for (size_t k = endIndex + 1; k <= textLen; k++) 
                    {
                        text[k - diff] = text[k];
                    }
                }

                // else if (whatLen - whereLen > 0) -> decrease ??? the length(move characters with that less symbols)
                // Expand the length
                else if (whatLen > whereLen) 
                {
                    size_t diff = whatLen - whereLen;
                    for (size_t k = textLen; k >= endIndex + 1; k--) 
                    {
                        text[k + diff] = text[k];
                    }

                    size_t counter = 0;
                    for (size_t k = startIndex; k < startIndex + whatLen; k++) 
                    {
                        text[k] = what[counter++];
                    }

                isMatch = false; // always set to false because it will change the symbol every time
                }

            i = t; // Move the index forward
            }
        }
    }
    return text;
}

char* replaceWord2(char* text, const char* where, const char* what)
{   
    char* writePtr = text;
    char* readPtr = text;
    size_t whereLen = myStrLen(where);
    size_t whatLen = myStrLen(what);

    while (*readPtr)
    {
        const char* searchPtr = where;
        char* tempPtr = readPtr;

        while (*searchPtr && *tempPtr == *searchPtr)
        {
            searchPtr++;
            tempPtr++;
        }

        if (*searchPtr == '\0') { // Match found
            // Write `what` in place of `where`
            const char* whatPtr = what;
            for (size_t i = 0; i < whatLen; i++) {
                *writePtr = *whatPtr;
                writePtr++;
                whatPtr++;
            }
            readPtr += whereLen; // Skip over `where`
        } else {
            // Copy current character if no match
            *writePtr = *readPtr;
            writePtr++;
            readPtr++;
        }
    }
    *writePtr = '\0';

    return text;
}

// 3
char* convertCase (char* text)
{
    char* originalText = text;

    while (*text)
    {
        if (*text >= 'a' && *text <= 'z')
        {
            *text = *text - 'a' + 'A';
        }
        else if (*text >= 'A' && *text <= 'Z')
        {
            *text = *text - 'A' + 'a';
        }
        text++;
    }
    return originalText;
}

// 4
char* countRepetitions(const char* text, char* res)
{
    int digitsCount[ARRAY_SIZE] = {0};

    while (*text)
    {
        if (*text >= '0' && *text <= '9')
        {
            digitsCount[*text - '0']++;
        }
        text++;
    }

    char* resPtr = res;
    bool first = true;

    for (int i = 0; i < 10; i++)
    {
        if (digitsCount[i] > 0)
        {
            if (!first)
            {
                *resPtr = ',';
                resPtr++;
            }
            first = false; 

            *resPtr = digitsCount[i] + '0';
            resPtr++;

            *resPtr = 'x';
            resPtr++;

            *resPtr = i + '0';
            resPtr++;
        }
    }
    *resPtr = '\0';

    return res;
}

// 5
char* capitalizeWords(char* text)
{
    char* originalText = text;
    bool newWord = true;

    while (*text)
    {
        if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z'))
        {
            if (newWord)
            {
                if (*text >= 'a' && *text <= 'z')
                {
                    *text -= 'a' - 'A';
                }
                newWord = false;
            }  
        }
        else
        {
            newWord = true;
        }
        text++; 
    }
   
    return originalText;
}

// 6
char* getLastWord(const char* input, char* res)
{
    const char* wordStart = nullptr;
    const char* wordEnd = nullptr;
    const char* inputStart = input;
    const char* lastWordStart = nullptr;
    const char* lastWordEnd = nullptr;

    while (*input)
    {
        if (*input != ' ' && (input == inputStart || *(input - 1) == ' '))
        {
            wordStart = input;
        }

        if (*input != ' ' && (*(input + 1) == ' ' || *(input + 1) == '\0'))
        {
            wordEnd = input;

            lastWordStart = wordStart;
            lastWordEnd = wordEnd;
        }

        input++;
    }

    if (lastWordStart && lastWordEnd) {
        while (lastWordStart <= lastWordEnd) {
            *res = *lastWordStart;
            res++;
            lastWordStart++;
        }
    }

    *res = '\0';
    return res - (lastWordEnd - lastWordStart + 1);
}

// 7

int countWords(const char* text) {
    bool inWord = false; 
    int wordCount = 0;

    while (*text) {
        if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z')) {
            if (!inWord) {
                inWord = true;
                wordCount++;  
            }
        } else {
            inWord = false;
        }
        text++;
    }

    return wordCount;
}

void shiftLeft (char* str)
{
    if (!str) return;

    while (*str)
    {
        *str = *(str + 1);
        str++;
    }
}

void shiftRight (char* str)
{
    if (!str) return;

    char* end = str + myStrLen(str) + 1;
    while (end != str)
    {
        *end = *(end - 1);
        end--;
    }
}

int main()
{
    // 1
    // char text[SIZE] = "Hello, my friend!";
    // const char symbol = 'e';

    // removeSymbol(text, symbol);

    // 2
    // char text[SIZE] = "I am the worst of the worst.";

    // std::cout << text << std::endl;
    // std::cout << replaceWord(text, "worst", "best") << std::endl;

    // char text[SIZE] = "I am the worst of the worst.";

    // std::cout << text << std::endl;
    // std::cout << replaceWord2(text, "worst", "best") << std::endl;

    // 3
    // char text[SIZE] = "Hello World!";

    // std::cout << text << std::endl;
    // std::cout << convertCase(text) << std::endl;

    // 4
    // const char* text = "4231148";
    // char res[SIZE];

    // std::cout << text << std::endl;
    // std::cout << countRepetitions(text, res) << std::endl;

    // 5
    // char text[SIZE] = "hello, my friend!";

    // std::cout << text << std::endl;
    // std::cout << capitalizeWords(text) << std::endl;

    // 6
    // char input[SIZE] = "What is your name";
    // char result[SIZE];

    // std::cout << input << std::endl;
    // std::cout << getLastWord(input, result) << std::endl;

    return 0;
}
