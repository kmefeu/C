// Matheus Corrêa - 202010270
// Leonardo Rossi Vinagre - 202010277

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct toDo
{
    int task;
    int priority;
    int timeStamp;
    struct toDo *next;
} todoList;

todoList *start(void)
{
    return NULL;
}

void printList(todoList *dailyTask)
{

    if (dailyTask != NULL)
    {
        printf("%d# Task | %d Priority | %d mim \n", dailyTask->task, dailyTask->priority, dailyTask->timeStamp);
        printList(dailyTask->next);
    }
}

void printNextTask(todoList *dailyTask)
{
    if (dailyTask == NULL)
    {
        printf("No tasks");
    }
    if (dailyTask != NULL)
    {
        while (dailyTask != NULL)
        {
            if (dailyTask->next == NULL)
            {
                printf("%d# Task | %d Priority | %d mim \n", dailyTask->task, dailyTask->priority, dailyTask->timeStamp);
            }
            dailyTask = dailyTask->next;
        }
    }
}

todoList *add(todoList *dailyTask, int p, int a, int tp)
{
    todoList *newNode = (todoList *)malloc(sizeof(todoList));
    newNode->priority = p;
    newNode->task = a;
    newNode->timeStamp = tp;
    newNode->next = NULL;

    if (dailyTask == NULL)
    {
        return newNode;
    }
    else
    {
        todoList *previous = dailyTask;
        todoList *current = dailyTask;

        for (; current != NULL && ((current->priority - 1) * 1440) + current->timeStamp >= ((newNode->priority - 1) * 1440) + newNode->timeStamp;)
        {
            previous = current;
            current = current->next;
        }

        if (current == dailyTask)
        {
            newNode->next = dailyTask;
            return newNode;
        }
        else
        {
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }
    return dailyTask;
}

todoList *removeTask(todoList *dailyTask)
{
    if (dailyTask == NULL)
    {
        printf("\nEmpty list!");
    }
    else
    {
        todoList *
            previous = dailyTask;
        todoList *current = dailyTask;

        while (current->next != NULL)
        {

            previous = current;
            current = current->next;
        }

        if (current == dailyTask)
            dailyTask = NULL;
        else

            previous->next = NULL;

        free(current);
    }

    return dailyTask;
}

void freeList(todoList *dailyTask)
{
    todoList *p = dailyTask;
    while (p != NULL)
    {
        todoList *dailyTask = p->next;
        free(p);
        p = dailyTask;
    }
}

int main()
{
    todoList *dailyTask;
    int option, task = 0, priority, time, j = 0;

    dailyTask = start();
    do
    {
        system("cls");
        printf("\nDaily Task");
        printf("\n1 -> New Task");
        printf("\n2 -> Print List");
        printf("\n3 -> Next Task");
        printf("\n4 -> Remove Task");
        printf("\n5 -> Software Test");
        printf("\n0 -> Close \n");
        printf("\nOption:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            task++;
            printf("\n%d# Task", task);
            priority = -1;

            do
            {
                printf("Task Priority (1-3):");
                scanf("%d", &priority);

                if (priority > 3 || priority < 1)
                {
                    printf("\nInvalid Input!\n");
                }

            } while (priority > 3 || priority < 1);

            do
            {
                printf("Task deadline(1-1440):");
                scanf("%d", &time);
                if (time >= 1441 || time < 1)
                {
                    printf("\nInvalid Input!\n");
                }

            } while (time >= 1441 || time < 1);

            dailyTask = add(dailyTask, priority, task, time);

            break;
        case 2:
            printf("\n\nList:\n");
            printf("\nLast Task\n");
            printList(dailyTask);
            printf("First Task\n");
            printf("\n\n");
            system("pause");
            break;
        case 3:
            printf("\nNext Task\n");
            printNextTask(dailyTask);
            printf("\n\n");
            system("pause");
            break;

        case 4:
            printf("\nRemoved Task\n");
            printNextTask(dailyTask);
            removeTask(dailyTask);
            printf("\n\n");
            system("pause");
            break;

        case 5:
            j = task + 10;
            for (; task < j; task++)
            {
                dailyTask = add(dailyTask, ((rand() % 3) + 1), task, ((rand() % 1439) + 1));
            }
            printf("\n+10 Randon Tasks\n\n");
            system("pause");
            break;
        }
        getchar();
    } while ((option != 0));

    freeList(dailyTask);
    return 0;
}
