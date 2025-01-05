## Linux kernel list   
https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/managing-repository-settings/about-email-notifications-for-pushes-to-your-repository
   
[list.h](https://cs.android.com/android/kernel/superproject/+/common-android-mainline:test/ltp/testcases/realtime/include/list.h)

### 本文从最基本的内核链表出发，引出初始化INIT_LIST_HEAD函数，然后介绍list_add，通过改变链表位置的问题引出list_for_each函数，然后为了获取容器结构地址，引出offsetof和container_of宏，并对内核链表设计原因作出了解释，一步步引导到list_for_each_entry，然后介绍list_del函数，通过在遍历时list_del链表的不安全行为，引出list_for_each_entry_safe函数，通过本文，我希望读者可以得到如下三个技能点：

1. 能够熟练使用内核链表的相关宏和函数，并应用在项目中；
2. 明白内核链表设计者们的意图，为什么要那样去设计链表的操作和提供那样的函数接口；
3. 能够将内核链表移植到非GNU环境。

链表是学习数据结构中必不可少的一种数据结构，虽然我们也学习并且实现过各种的链表，但是在实际的工作中，还是Linux内核的链表最为常用，下面是对Linux内核链表的一些总结：
假设你已经有了链表的基本知识储备，下面是Linux内核链表的基础实现：

```
/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

struct list_head {
	struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}
```

Linux内核链表是一个双向链表结构，其只有指针域没有数据域，数据域是根域实际的实现而定的。之前有位网友针对Linux内核链表总结的很到位：既然链表不能包含万事万物，那么就让万事万物来包含链表。

根据上面Linux内核链表的基础实现我们假定一个数据结构如下：

```
struct Student
{
    struct list_head list;
    unsigned int age;
}
```

上面假定的数据结构我们将链表的声明放在结构体的第一个成员地址处（这样实现下面会解释原因）

```
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Student
{
    struct list_head list;
    unsigned int age;
}

int main(int argc, char **argv)
{
    struct Student *stuPtr;
    struct Student student;
    struct list_head *listPoint;

    INIT_LIST_HEAD(&student.list);

    for( int idx = 0, idx < 6; idx++ )
    {
        stuPtr = (struct Student *)malloc(sizeof(struct Student));
        stuPtr->
    }
}
```

this is test   