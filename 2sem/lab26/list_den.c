#include "list_den.h"

void two_elem_list_reverse(List *list)
{
    ListNode *tmp = list->head;
    //ListNode *tmp_prev = list->head->prev;
    ListNode *tmp_next = list->head->next;
    sData *tmp_data = list->head->data;

    list->head = list->tail;
    list->head->next = list->tail->prev;
    list->head->prev = NULL;
    list->head->data = list->tail->data;

    list->tail = tmp;
    list->tail->next = NULL;
    list->tail->prev = tmp_next;
    list->tail->data = tmp_data;
}

List *merge(List *first, List *second, List *result)
{
    if (list_is_empty(first) && list_is_empty(second))
        return result;

    if (list_is_empty(first)) {
        if (list_is_empty(result))
            return second;

        result->tail->next = second->head;
        second->head->prev = result->tail;

        list_delete(first);
        list_delete(second);

        return result;
    }

    if (list_is_empty(second)) {
        if (list_is_empty(result))
            return first;

        result->tail->next = first->head;
        first->head->prev = result->tail;

        list_delete(first);
        list_delete(second);

        return result;
    }


    if (first->head->data->key <= second->head->data->key) {
        list_insert_last(result, first->head->data);
        list_delete_elem(first, first->head);
    }
    else {
        list_insert_last(result, second->head->data);
        list_delete_elem(second, second->head);
    }

    // list_print(result);
    return merge(first, second, result);
}

List *merge_sort(List *list)
{
    if (list->head == NULL)
        return NULL;

    if (list_lenght(list) < 2)
        return list;

    if (list_lenght(list) == 2) {
        if (list->head->data->key > list->tail->data->key)
            two_elem_list_reverse(list);

        return list;
    }

    if (list_lenght(list) > 2) {
        List *list_1 = list_create();
        List *list_2 = list_create();

        int lenght = list_lenght(list);

        for (int i = 0; i < lenght; ++i) {
            ListNode *tmp = list->head;

            if (i + 1 > lenght/ 2)
                list_insert_last(list_2, tmp->data);
            else
                list_insert_last(list_1, tmp->data);

            list_delete_elem(list, tmp);
        }

        list_1 = merge_sort(list_1);
        list_2 = merge_sort(list_2);

        list = merge(list_1, list_2, list);
    }
    return list;
}

void annotation()
{
    printf("0 - break \n");
    printf("1 - add elem\n");
    printf("2 - delete elem\n");
    printf("3 - sort by merge\n");
    printf("4 - print list\n");
    printf("9 - tips\n");
}

void annotation_2()
{
    printf("0 - break\n");
    printf("1 - add elem after node\n");
    printf("2 - add elem before node\n");
    printf("3 - add elem front\n");
    printf("4 - add elem back\n");
    printf("5 - print list\n");
    printf("9 - tips\n");
}

void interface_1(List *list)
{
    annotation();

    while (1)
    {
        int interact = 0;
        int key = 0;

        printf("Num of actinon:\n");
        scanf("%d", &interact);

        if (interact == 0)
            break;

        if (interact == 1) {
            interface_2(list);
            continue;
        }

        if (interact == 2) {
            if (list_is_empty(list)) {
                printf("Nothing to delete, enter element, just press 1\n");
                continue;
            }
            printf("Key of delete element?\n");
            scanf("%d", &key);

            list_delete_elem(list, find_elem(list, key));
            continue;
        }

        if (interact == 3) {
            list = merge_sort(list);
            continue;
        }

        if (interact == 4) {
            list_print(list);
            continue;
        }

        if (interact == 9) {
            annotation();
            continue;
        }

        printf("Wrong input try again\n");
    }
}

void interface_2(List *list)
{
    annotation_2();

    while (1) {

        int key_1 = 0;
        int value_1 = 0;
        int n = 0;

        printf("Num of actinon(2):\n");
        scanf("%d", &n);

        if (n == 0)
            break;

        if (n == 1) {
            printf("Key after each add\n");

            int find_key = 0;
            scanf("%d", &find_key);

            if (!find_elem(list, find_key)) {
                printf("Try again, press 1\n");
                continue;
            }

            printf("Key - Value\n");
            scanf("%d%d", &key_1, &value_1);

            sData *ins_data = list_node_data_create(key_1, value_1);
            if (ins_data == NULL) {
                printf("ERRROR\n");
                continue;
            }

            list_insert_after_elem(find_elem(list, find_key), ins_data);
            continue;
        }

        if (n == 2) {
            printf("Key before each add\n");

            int find_key = 0;
            scanf("%d", &find_key);

            if (!find_elem(list, find_key)) {
                printf("Try again, press 1\n");
                continue;
            }

            printf("Key - Value\n");
            scanf("%d%d", &key_1, &value_1);

            sData *ins_data = list_node_data_create(key_1, value_1);
            if (ins_data == NULL) {
                printf("ERRROR\n");
                continue;
            }

            list_insert_before_elem(find_elem(list, find_key), ins_data);
            continue;
        }

        if (n == 3) {
            printf("Key - Value\n");
            scanf("%d%d", &key_1, &value_1);

            sData *ins_data = list_node_data_create(key_1, value_1);
            if (ins_data == NULL) {
                printf("ERRROR\n");
                continue;
            }

            list_insert_front(list, ins_data);
            continue;
        }

        if (n == 4) {
            printf("Key - Value\n");
            scanf("%d%d", &key_1, &value_1);

            sData *ins_data = list_node_data_create(key_1, value_1);
            if (ins_data == NULL) {
                printf("ERRROR\n");
                continue;
            }

            list_insert_last(list, ins_data);
            continue;
        }

        if (n == 5) {
            list_print(list);
            continue;
        }

        if (n == 9) {
            annotation_2();
            continue;
        }
        printf("Wrong input try again\n");
    }
}