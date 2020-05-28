#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned int n;
    scanf("%u", &n); //how many string will be entered

    char** s; // pointer marks like a array
    s = (char**)malloc(n * sizeof(char*)); //allocates the requested memory for s

    for (unsigned int i = 0; i < n; ++i)
    {
        *(s + i) = malloc(1024 * sizeof(char)); //allocates the requested memory s[i]
        if (1 != scanf(" %[^\n]", *(s + i)))//read a sentence
        {
            **(s + i) = '\0';
        }
        else
        {
            *(s + i) = realloc(*(s + i), strlen(*(s + i)) + 1);//allocates the enough memory s[i]
        }

    }

    char* name; //pointer for looking for the number
    name = (char*)malloc(1024 * sizeof(char)); //allocates the requested memory name
    for (unsigned int i = 0; i < n; ++i)
    {
        if (1 != scanf("%s", name))//read a name
        {
            *name = '\0';
        }
        else
        {
            name = (char*)realloc(name, strlen(name) + 1);//allocates the enough memory name

        }
        int counter = 0;
        for (unsigned int j = 0; j < n; ++j)
        {
            if (0 == strncmp(*(s + j), name, strlen(name))) //is it equal name and s[j]
            {
                counter = 1; //it is a counter for output sentence
                printf("%s=%s%c", name, *(s + j) + strlen(name) + 1, '\n');
                break;
            }
            else
            {
                counter = 0;
                continue;
            }
        }
        if (counter == 0) { printf("%s", "Not found\n"); }
    }


}