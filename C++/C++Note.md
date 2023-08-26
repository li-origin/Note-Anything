# C++
________

### ***variable arguments***
---
`va_list`, `va_start`, and `va_arg` are macros defined in the C standard library header file `stdarg.h`. They are used to implement functions that can accept a variable number of arguments.

`va_list` is a type that represents a list of arguments. It is used to declare a variable that will hold the arguments passed to a function.

`va_start` is a macro that initializes a `va_list` variable to point to the first argument in the list. It takes two arguments: the `va_list` variable and the name of the last fixed argument in the function's argument list.

`va_arg` is a macro that retrieves the next argument from the `va_list`. It takes two arguments: the `va_list` variable and the type of the argument to retrieve.

`va_end` is another macro defined in `stdarg.h` that is used to clean up the `va_list` variable after it has been used. It takes one argument, which is the `va_list` variable.

It's also worth noting that the behavior of `va_arg` is undefined if there are no more arguments in the `va_list`. It's the responsibility of the programmer to ensure that the correct number and types of arguments are passed to the function.

Finally, it's important to mention that variadic functions can be error-prone and difficult to debug, so they should be used with caution. It's generally a good idea to provide a non-variadic alternative to a function if possible.

Here's an example of how these macros can be used:

```
#include <stdarg.h>
#include <stdio.h>

void print_ints(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int arg = va_arg(args, int);
        printf("%d ", arg);
    }
    va_end(args);
}

int main() {
    print_ints(3, 1, 2, 3); // prints "1 2 3 "
    return 0;
}
```

In this example, the `print_ints` function takes a variable number of arguments. It uses `va_list`, `va_start`, and `va_arg` to retrieve the arguments and print them to the console.

---

### ***vsnprintf***

---
`vsnprintf` is a function in the C standard library that is used to format a string with a variable number of arguments. It is similar to the `sprintf` function, but takes a `va_list` argument instead of a variable number of arguments. This makes it useful when you want to format a string with a variable number of arguments, but you don't know how many arguments there will be at compile time.

The `vsnprintf` function takes a buffer to write the formatted string to, the maximum number of characters to write to the buffer, a format string, and a `va_list` argument that contains the variable arguments to be formatted. The function returns the number of characters that would have been written to the buffer if it were large enough, not including the terminating null character. If the buffer is not large enough to hold the entire formatted string, the function will write as much as it can and return the number of characters that would have been written if the buffer were large enough.

Here's an example usage of `vsnprintf`:

```
#include <stdio.h>
#include <stdarg.h>

int main() {
    char buffer[100];
    int n = 42;
    const char* s = "hello";
    double d = 3.14159;
    int result = vsnprintf(buffer, sizeof(buffer), "n=%d s=%s d=%f", n, s, d);
    printf("result=%d buffer=%s\n", result, buffer);
    return 0;
}
```

In this example, `vsnprintf` is used to format a string with three variables: an integer `n`, a string `s`, and a double `d`. The formatted string is written to a buffer of size 100. The `printf` function is then used to print the result of `vsnprintf`.
--- -

### ***dlopen***
---
`RTLD_NOW` and `RTLD_LOCAL` are flags used with the `dlopen()` function in C and C++ to specify how a shared library should be loaded.

`RTLD_NOW` specifies that all undefined symbols in the library should be resolved immediately, at the time the library is loaded. This means that if any of the symbols cannot be resolved, the `dlopen()` call will fail. This flag is typically used when you want to ensure that all symbols are available before the program starts running.

`RTLD_LOCAL` specifies that the symbols in the library should not be made available for symbol resolution of subsequently loaded libraries. This means that any symbols defined in the library will not be available for use by other libraries that are loaded later. This flag is typically used when you want to avoid symbol conflicts between different libraries.

Together, these flags ensure that a shared library is loaded with all its symbols resolved immediately, and that the symbols in the library are not made available for use by other libraries.

--- -

### ***strtok_r***

---
`strtok_r` is a function in the C programming language that is used to tokenize a string. It is similar to the `strtok` function, but it is thread-safe and reentrant. The function takes three arguments:

1. `str` - a pointer to the string to be tokenized
2. `delim` - a string containing the delimiter characters
3. `saveptr` - a pointer to a `char *` variable that is used to maintain context between calls to `strtok_r`

The `strtok_r` function returns a pointer to the next token in the string, or `NULL` if there are no more tokens. It modifies the original string by replacing the delimiter characters with null characters (`'\0'`) to terminate each token.

Here is an example usage of `strtok_r`:

```
char str[] = "The quick brown fox jumps over the lazy dog";
char *token, *saveptr;

token = strtok_r(str, " ", &saveptr);
while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
}
```

This code will tokenize the string `str` using the space character as the delimiter, and print each token on a new line. The `saveptr` variable is used to maintain context between calls to `strtok_r`, allowing the function to be called multiple times on the same string.
```
/* 
 * strtok_r.c: 
 * Implementation of strtok_r for systems which don't have it. 
 * 
 * This is taken from the GNU C library and is distributed under the terms of 
 * the LGPL. See copyright notice below. 
 * 
 */  
  
#ifdef HAVE_CONFIG_H   
#include "configuration.h"   
#endif /* HAVE_CONFIG_H */   
  
#ifndef HAVE_STRTOK_R   
  
static const char rcsid[] = "$Id: strtok_r.c,v 1.1 2001/04/24 14:25:34 chris Exp $";  
  
#include <string.h>   
  
#undef strtok_r   
  
/* Parse S into tokens separated by characters in DELIM. 
   If S is NULL, the saved pointer in SAVE_PTR is used as 
   the next starting point.  For example: 
        char s[] = "-abc-=-def"; 
        char *sp; 
        x = strtok_r(s, "-", &sp);      // x = "abc", sp = "=-def" 
        x = strtok_r(NULL, "-=", &sp);  // x = "def", sp = NULL 
        x = strtok_r(NULL, "=", &sp);   // x = NULL 
                // s = "abc/0-def/0" 
*/  
char *strtok_r(char *s, const char *delim, char **save_ptr) {  
    char *token;  
  
    if (s == NULL) s = *save_ptr;  
  
    /* Scan leading delimiters.  */  
    s += strspn(s, delim);  
    if (*s == '/0')   
        return NULL;  
  
    /* Find the end of the token.  */  
    token = s;  
    s = strpbrk(token, delim);  
    if (s == NULL)  
        /* This token finishes the string.  */  
        *save_ptr = strchr(token, '/0');  
    else {  
        /* Terminate the token and make *SAVE_PTR point past it.  */  
        *s = '/0';  
        *save_ptr = s + 1;  
    }  
  
    return token;  
}   
```
---

### ***opendir***
---
`opendir` is a function in the C programming language that is used to open a directory stream. It takes a string argument representing the name of the directory to be opened and returns a pointer to a `DIR` structure, which is used to read the contents of the directory. Once a directory stream is opened, you can use other functions like `readdir` to read the directory entries. 

Here's an example of how to use `opendir`:

```
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
```

This program opens the current directory using `opendir`, reads each directory entry using `readdir`, and prints the name of each entry to the console. Finally, it closes the directory stream using `closedir`.
--- -

### ***fdopendir***
---
`fdopendir` is a C library function that is used to open a directory stream corresponding to the file descriptor `fd`. It takes an integer file descriptor `fd` as its argument and returns a pointer to a `DIR` structure that can be used to read the contents of the directory.

Here's the syntax of the `fdopendir` function:

```c
#include <dirent.h>

DIR *fdopendir(int fd);
```

The `fd` argument is the file descriptor of the directory to be opened. The function returns a pointer to a `DIR` structure on success, or `NULL` on failure. Once the directory stream is no longer needed, it should be closed using the `closedir` function.
--- -

### ***dirent***

---
`dirent` is a header file in the C standard library that provides functions and data structures for working with directories and directory entries in a file system. It is typically used in Unix-like operating systems, such as Linux and macOS.

The `dirent.h` header file defines the `DIR` data type, which represents a directory stream, and the `struct dirent` data type, which represents a directory entry. The `opendir()`, `readdir()`, and `closedir()` functions are used to open, read, and close directory streams, respectively. The `struct dirent` data type contains information about a directory entry, such as its name and type.

Here's an example of how to use `dirent.h` to list the contents of a directory:

```c
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
```

This program opens the current directory using `opendir()`, reads each directory entry using `readdir()`, and prints the name of each entry using `printf()`. Finally, it closes the directory stream using `closedir()`.
--- -

### ***readdir()***

---
`readdir()` is a function in the C standard library that is used to read the contents of a directory. It is defined in the `dirent.h` header file and is typically used in Unix-like operating systems, such as Linux and macOS.

The `readdir()` function takes a pointer to a `DIR` data type, which represents a directory stream, and returns a pointer to a `struct dirent` data type, which represents a directory entry. Each call to `readdir()` returns the next directory entry in the directory stream, or `NULL` if there are no more entries.

Here's an example of how to use `readdir()` to list the contents of a directory:

```c
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
```

This program opens the current directory using `opendir()`, reads each directory entry using `readdir()`, and prints the name of each entry using `printf()`. Finally, it closes the directory stream using `closedir()`.
--- -

### ***__sync_****
---

type __sync_fetch_and_add (type *ptr, type value, ...)
// 将value加到*ptr上，结果更新到*ptr，并返回操作之前*ptr的值

type __sync_fetch_and_sub (type *ptr, type value, ...) 
// 从*ptr减去value，结果更新到*ptr，并返回操作之前*ptr的值

type __sync_fetch_and_or (type *ptr, type value, ...)
// 将*ptr与value相或，结果更新到*ptr， 并返回操作之前*ptr的值

type __sync_fetch_and_and (type *ptr, type value, ...)
// 将*ptr与value相与，结果更新到*ptr，并返回操作之前*ptr的值

type __sync_fetch_and_xor (type *ptr, type value, ...)
// 将*ptr与value异或，结果更新到*ptr，并返回操作之前*ptr的值

type __sync_fetch_and_nand (type *ptr, type value, ...)
// 将*ptr取反后，与value相与，结果更新到*ptr，并返回操作之前*ptr的值

type __sync_add_and_fetch (type *ptr, type value, ...)
// 将value加到*ptr上，结果更新到*ptr，并返回操作之后新*ptr的值

type __sync_sub_and_fetch (type *ptr, type value, ...)
// 从*ptr减去value，结果更新到*ptr，并返回操作之后新*ptr的值

type __sync_or_and_fetch (type *ptr, type value, ...)
// 将*ptr与value相或， 结果更新到*ptr，并返回操作之后新*ptr的值

type __sync_and_and_fetch (type *ptr, type value, ...)
// 将*ptr与value相与，结果更新到*ptr，并返回操作之后新*ptr的值

type __sync_xor_and_fetch (type *ptr, type value, ...)
// 将*ptr与value异或，结果更新到*ptr，并返回操作之后新*ptr的值

type __sync_nand_and_fetch (type *ptr, type value, ...)
// 将*ptr取反后，与value相与，结果更新到*ptr，并返回操作之后新*ptr的值

bool __sync_bool_compare_and_swap (type *ptr, type oldval type newval, ...)
// 比较*ptr与oldval的值，如果两者相等，则将newval更新到*ptr并返回true

type __sync_val_compare_and_swap (type *ptr, type oldval type newval, ...)
// 比较*ptr与oldval的值，如果两者相等，则将newval更新到*ptr并返回操作之前*ptr的值

__sync_synchronize (...)
// 发出完整内存栅栏

type __sync_lock_test_and_set (type *ptr, type value, ...)
// 将value写入*ptr，对*ptr加锁，并返回操作之前*ptr的值。即，try spinlock语义

void __sync_lock_release (type *ptr, ...)
// 将0写入到*ptr，并对*ptr解锁。即，unlock spinlock语义

--- -

### ***sem_init***
---
`sem_init` is a function in the C programming language that is used to initialize a semaphore. A semaphore is a synchronization object that is used to control access to a shared resource in a multi-threaded or multi-process environment. 

The `sem_init` function takes three arguments:

1. A pointer to the semaphore to be initialized
2. A flag that specifies whether the semaphore should be shared between processes or not
3. An initial value for the semaphore

The function returns 0 on success and -1 on failure. 

Here's an example of how to use `sem_init`:

```
#include <semaphore.h>

int main() {
    sem_t my_semaphore;
    int shared = 0; // 0 for a semaphore that is not shared between processes

    if (sem_init(&my_semaphore, shared, 1) == -1) {
        perror("sem_init");
        exit(1);
    }

    // Use the semaphore...

    sem_destroy(&my_semaphore);

    return 0;
}
```

In this example, we initialize a semaphore called `my_semaphore` with an initial value of 1. The semaphore is not shared between processes, so we set the `shared` flag to 0. If `sem_init` fails, we print an error message using `perror` and exit the program. Finally, we destroy the semaphore using `sem_destroy` when we're done with it.
--- -

### ***sem_open/sem_init***
---
The second parameter of `sem_init` is a flag that specifies whether the semaphore should be shared between processes or not. This flag is of type `int` and can take one of two values:

- `0`: The semaphore is local to the calling process and cannot be shared with other processes.
- `1`: The semaphore is shared between multiple processes.

If the semaphore is shared between processes, it can be used to synchronize access to a shared resource across multiple processes. For example, if two processes need to access a shared file, they can use a semaphore to ensure that only one process accesses the file at a time.

Here's an example of how to use `sem_init` to create a semaphore that is shared between processes:

```
#include <semaphore.h>
#include <fcntl.h>

int main() {
    sem_t *my_semaphore;
    int shared = 1; // 1 for a semaphore that is shared between processes

    my_semaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);
    if (my_semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    // Use the semaphore...

    sem_close(my_semaphore);
    sem_unlink("/my_semaphore");

    return 0;
}
```

In this example, we create a semaphore called `my_semaphore` that is shared between processes. We use the `sem_open` function instead of `sem_init` to create the semaphore. The first argument to `sem_open` is a name for the semaphore, which must begin with a forward slash (`/`). The second argument specifies that the semaphore should be created if it doesn't already exist. The third argument is the initial value of the semaphore. If `sem_open` fails, we print an error message using `perror` and exit the program. Finally, we close the semaphore using `sem_close` and unlink it using `sem_unlink` when we're done with it.
--- -

`sem_open` and `sem_init` are both used for creating and initializing a semaphore, but they have different use cases.

`sem_open` is used to create a named semaphore that can be shared between processes. Named semaphores are identified by a string name, and can be accessed by any process that knows the name. This makes them useful for synchronizing between processes that are not related by parent-child relationships. `sem_open` returns a semaphore descriptor that can be used by other processes to access the semaphore.

`sem_init`, on the other hand, is used to initialize an unnamed semaphore that is only accessible within the current process. Unnamed semaphores are typically used for synchronization between threads within a single process. `sem_init` initializes the semaphore and returns a pointer to the semaphore object.

In summary, use `sem_open` when you need to synchronize between processes, and use `sem_init` when you need to synchronize between threads within a single process.
--- -


### ***If the current class declaration declares a static object of the current class, will this static object allocate specific memory. For example, the myClass class declaration declares static myClass myClassInstance***

---
Yes, if the current class declaration declares a static object of the current class, it will allocate specific memory when the program is loaded into memory.

When a static object is declared within a class, it is essentially a static data member of that class. The static object is initialized before the program starts and is destroyed when the program ends, just like any other static variable.

For example, consider the following class declaration where a static object of the current class is declared:

```
class MyClass {
public:
    static MyClass myClassInstance;
    void myMethod() {
        // do something
    }
};

MyClass MyClass::myClassInstance; // initialize static object

int main() {
    MyClass::myClassInstance.myMethod(); // access static object
    return 0;
}
```

In this example, a static object myClassInstance of type MyClass is declared within the class MyClass. The static object is initialized outside of the class declaration using the syntax MyClass MyClass::myClassInstance;, which allocates memory for the static object and initializes it with the default constructor.

When the program is loaded into memory, memory is allocated for the static object myClassInstance and it is initialized with the default constructor. The static object can be accessed using the scope resolution operator ::, as shown in the main() function.

It's worth noting that when a static object is declared within a class, the class definition must be complete before the static object can be initialized. This means that the static object must be initialized outside of the class declaration, as shown in the example.

In summary, if a static object of the current class is declared within the class declaration, it will allocate specific memory when the program is loaded into memory. The static object is essentially a static data member of the class and is initialized before the program starts.
--- -

### MarkDown

---
[link](https://www.markdownguide.org/basic-syntax/)
--- -

### virtual function table

---
>[Link-1](http://www.dietmar-kuehl.de/mirror/c++-faq/virtual-functions.html)
>
>[Link-2](https://cloud.tencent.com/developer/article/1599283)
>
>[example](https://note.youdao.com/s/cg727Mu)
--- -

