#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct Node 
{
    char name[1000];
    char num[1000];
    struct Node* next;
};

//создание в конец 1
void CreateInEnd(struct Node** head, char newName[], char newNum[])
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    strcpy_s(newNode->name,sizeof(newNode->name), newName);
    strcpy_s(newNode->num, sizeof(newNode->num), newNum);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
// создание в орпеделённой позиции 2
void CreateInPos(struct Node** head, char newName[],char newNum[], int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), newName);
    strcpy_s(newNode->num, sizeof(newNode->num), newNum);

    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node* current = *head;

        for (int i = 0; current != NULL && i < pos ; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
// создание после определённой позиции 3
void CreateAfterTarget(struct Node** head, char targetData[], char newName[],char newNum[])
{
    struct Node* current = *head;
    while (current != NULL && strcmp(current->name, targetData) != 0)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Data not founded");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), newName);
    strcpy_s(newNode->num, sizeof(newNode->num), newNum);
    newNode->next = current->next;
    current->next = newNode;

}
// создание перед определённой позицией 4
void CreateBeforeTarget(struct Node** head, char targetData[], char newName[], char newNum[])
{
    if (strcmp((*head)->name, targetData)==1)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        strcpy_s(newNode->name, sizeof(newNode->name), newName);
        strcpy_s(newNode->num, sizeof(newNode->num), newNum);
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && strcmp(current->next->name, targetData) != 0)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("Data not founded");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), newName);
    strcpy_s(newNode->num, sizeof(newNode->num), newNum);
    newNode->next = current->next;
    current->next = newNode;
}
//создание в середине 5
void CreateInMiddle(struct Node** head, char newName[],char newNum[])
{
    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(newNode->name, sizeof(newNode->name), newName);
    strcpy_s(newNode->num, sizeof(newNode->num), newNum);
    newNode->next = slow;
    if (prev != NULL)
    {
        prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }

}

//удаление из середины 6
void DeleteInMiddle(struct Node** head)
{
    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        prev->next = slow->next;
        free(slow);
    }
}

//удаление выбранного элемента 7
void DeleteInTarget(struct Node** head, char target[]) {
    struct Node* temp = *head;
    struct Node* prev = *head;

    if (temp != NULL && strcmp(temp->name, target) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, target) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Элемент с именем %s не найден в списке.\n", target);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

//удаление последнего эллемента 8
void DeleteInEnd(struct Node** head)
{
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

//удаление из заданного места 9
void DeleteInPos(struct Node** head, int pos)
{
    if (pos == 0)
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    for (int i = 0; current != NULL && i < pos - 1; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Position is greater");
        return;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

//удаление первого эллемента 10
void DeleteFirst(struct Node** head)
{
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Функция для отображения элементов списка 11
void displayList(struct Node* node)
{
    while (node != NULL) {
        printf("\n%s %s", node->name, node->num);
        node = node->next;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct Node* test = NULL;
    
    char name[100];
    char num [15];
    char target[100];
    int pos = 0;
    int choice = 15;

    while (choice != 0) 
    {
        printf("\nвыход - 0");
        printf("\nсоздание в конце - 1");
        printf("\nсоздание в орпеделённой позиции - 2");
        printf("\nсоздание после определённой позиции - 3");
        printf("\nсоздание перед определённой позицией - 4");
        printf("\nсоздание в середине - 5");
        printf("\nудаление из середины - 6");
        printf("\nудаление выбранного элемента - 7");
        printf("\nудаление последнего эллемента - 8");
        printf("\nудаление из заданного места - 9");
        printf("\nудаление первого эллемента - 10");
        printf("\nвывод списка - 11");
        printf("\n\nвыбери функцию ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1:
                printf("введите имя: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("введите номер: ");
                fgets(num, sizeof(num), stdin);

                CreateInEnd(&test, name, num);
                break;
            case 2:
                printf("введите имя: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("введите номер: ");
                fgets(num, sizeof(num), stdin);
                printf("введите позицию: ");
                scanf_s("%d", &pos);

                CreateInPos(&test,name,num,pos-1);
                break;
            case 3:

                printf("введите имя после которого вставить ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = '\0';
                printf("введите имя: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("введите номер: ");
                fgets(num, sizeof(num), stdin);

                CreateAfterTarget(&test, target, name, num);
                break;
            case 4: 
                printf("введите имя перед которым вставить ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = '\0';
                printf("введите имя: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("введите номер: ");
                fgets(num, sizeof(num), stdin);

                CreateBeforeTarget(&test, target, name, num);
                break;
            case 5:
                printf("введите имя: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("введите номер: ");
                fgets(num, sizeof(num), stdin);

                CreateInMiddle(&test, name, num);
                break;
            case 6:
                DeleteInMiddle(&test);
                break;
            case 7:
                printf("введите имя элемента, который хотите удалить ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = '\0';
                DeleteInTarget(&test, target);
                break;
            case 8:
                DeleteInEnd(&test);
                break;
            case 9:
                printf("введите позицию, которую хотите удалить: ");
                scanf_s("%d", &pos);
                DeleteInPos(&test, pos-1);
                break;
            case 10:
                DeleteFirst(&test);
            case 11:
                displayList(test);
        
        }
    }
}