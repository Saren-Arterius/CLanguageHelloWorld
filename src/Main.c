#include <stdio.h> // printf, fprintf, stdout
#include <iostream> // cout, endl
#include <stdlib.h> // puts(iirc), system

using namespace std;

// Macro
#define cmd "echo Hello World!"

// Function pointer
void (*fnHelloWorld)();

// (static) class
class Hello
{
public:
     static const char* get();
     static const char* World;
};

const char* Hello::World = "Hello World!\r\n";
const char* Hello::get() { return Hello::World; };

// Detour somehow?
void original()
{
    printf("Hi.");
}

void hacked()
{
    printf("Hello World!\r\n");
}

int main() {
    // All of those motherfuckers could generate an output of "Hello World".
    extern void disfuncplacedaftermain();
    ::puts("Hello World!");
    ::printf("%s\n","Hello World!");
    ::printf(Hello::World);
    ::printf(Hello::get());
    ::fprintf(stdout, "%s\n", "Hello World!");
    ::cout << "Hello World!" << ::endl;
    fnHelloWorld = hacked;
    fnHelloWorld();
    void (*original)() = hacked;
    original();
    disfuncplacedaftermain();
    ::system(cmd);
    return 0;
}

void disfuncplacedaftermain()
{
      printf("Hello World!");
}


