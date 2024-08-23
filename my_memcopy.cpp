#include <iostream>
using namespace std;

int my_memcpy(int *dest,const int *source,const int count);
//int my_strcpy(char *dest,char *source, const int dest_length=256);
int main()
{
    int count=10;
    int source[count], *dest;
    dest = source+4;
    cout << source + count << '\n';
    cout << dest - source << '\n';
    cout << dest << '\n';
    cout << ((source + count) > dest) << '\n';
    // dest[0] = 9;
    for (int i=0;i<count;i++)
        source[i]=i;
    cout << "source mem address: " << source << '\n';
    
    cout << "dest mem address:   " << dest << '\n';
    
    cout << "source \t dest \n";
    for (int i=0;i<count;i++)
    {
        cout << source[i] << '\t' << dest[i] << '\n';
    }
    int j = my_memcpy(dest, source, count);
    cout << "source mem address: " << source << '\n';
    cout << "dest mem address:   " << dest << '\n';
    
    cout << "source \t dest \n";
    for (int i=0;i<count;i++)
    {
        cout << source[i] << '\t' << dest[i] << '\n';
    }
    return 0;
}

int my_memcpy(int *dest,const int *source, const int count)
{
    int i;


    if ((source + count) >= dest)
    {
        cout << "memory overlap!\n";
        dest = dest+count;
        source = source+count;
        for (i=count;i>0;i--)
            *--dest = *--source;
        return i;
    }
    
    for (i=0;i<count;i++)
    {
        *dest++ = *source++;
    }
    
    return(i);
}
// 
// int my_strcpy(char *dest,char *source,const int dest_length)
// {
//     int i;
//     for (i=0;(i < dest_length)&&(*dest++ = *source++);i++)
//         ;
//     if (i == dest_length)
//         *(dest-1) = '\0';
//     return(i);
// }
