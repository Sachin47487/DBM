#include <stdio.h>
#include "header_01.h"
int main()
{

    int op, c;
    SLL *headptr = 0;
    while (1)
    {
        printf("\n1)Add begin\n2)Add Middle\n3)Add End\n4)Print_data\n5)Count Nodes\n6)Save File\n7)Read File\n8)printing using rec\n9)printing rev using rec\n10)print_using_loops\n11)print_using_array of pointer\n12)Delete All Nodes\n13)Delete Node\n14)Reverse Linking\n15)Reverse Link Printing\n16)Sorting Data\n17)Find node\n");
        printf("Enter the option...\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add_begin(&headptr);
            break;
        case 2:
            add_middle(&headptr);
            break;
        case 3:
            add_end(&headptr);
            break;
        case 4:
            print_data(headptr);
            break;
        case 5:
            c = count_nodes(headptr);
            printf("Count=%d\n", c);
            break;
        case 6:
            save_file(headptr);
            break;
        case 7:
            read_file(&headptr);
            break;
        case 8:
            print_rec(headptr);
            break;
        case 9:
            print_rev_rec(headptr);
            break;
        case 10:
            print_rev_U_loop(headptr);
            break;
        case 11:
            print_rev_U_AP(headptr);
            break;
        case 12:
            delete_all_nodes(&headptr);
            break;
        case 13:
            delete_node(&headptr);
            break;
        case 14:
            rev_link(headptr);
            break;
        case 15:
            rev_link_printing(&headptr);
            break;
        
        case 16:
            sort_data(headptr);
            break;

        case 17:
        find_node(headptr);
        break;
        default:
            "Invalid option!";
            break;
        }
    }
}
void add_begin(SLL **ptr)
{
    SLL *new;
    new = malloc(sizeof(SLL));
    printf("\n Enter data:");
    scanf("%d %s", &new->rollnum, new->name);
    new->next = *ptr;
    *ptr = new;
}
void print_data(SLL *ptr)
{
    if (ptr == 0)
    {
        printf("There is no nodes are present\n");
        return;
    }
    while (ptr)
    {
        printf("%d %s\n", ptr->rollnum, ptr->name);
        ptr = ptr->next;
    }
}
void add_middle(SLL **ptr)
{
    SLL *new, *temp;
    new = malloc(sizeof(SLL));
    printf("\n Enter roll number and name of student to be added:\n ");
    scanf("%d%s", &new->rollnum, &new->name);
    if ((*ptr == 0) || (new->rollnum < (*ptr)->rollnum))
    {
        new->next = *ptr;
        *ptr = new;
    }
    else
    {
        temp = *ptr;
        while (temp)
        {
            if ((temp->next == 0) || (temp->next->rollnum > new->rollnum))
            {
                new->next = temp->next;
                temp->next = new;
                break;
            }
            temp = temp->next; 
        }
    }
}
void add_end(SLL **ptr)
{
    SLL *new, *temp;
    new = malloc(sizeof(SLL));
    printf("\nEnter the rollnum and name: ");
    scanf("%d %s", &new->rollnum, new->name);
    if (*ptr == 0)
    {
        new->next = *ptr;
        *ptr = new;
    }
    else
    {
        temp = *ptr;
        while (temp->next)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}
int count_nodes(SLL *ptr)
{
    SLL *temp;
    int c = 0;
    temp = ptr;
    if (ptr == 0)
    {
        printf("There is no nodes are present\n");
        return 0;
    }
    while (temp)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
void save_file(SLL *ptr)
{
    FILE *fp;
    fp = fopen("data_01", "w");
    while (ptr)
    {
        fprintf(fp, "%d %s\n", ptr->rollnum, ptr->name);
        ptr = ptr->next;
    }
    fclose(fp);
}
void read_file(SLL **ptr)
{
    FILE *fp;
    SLL v, *new, *temp;
    fp = fopen("data_01", "r");
    if (fp == 0)
    {
        printf("File is not present\n");
        return;
    }
    while (fscanf(fp, "%d %s", &v.rollnum, v.name) != EOF)
    {
        new = malloc(sizeof(SLL));
        *new = v;
        if (*ptr == 0)
        {
            new->next = (*ptr);
            *ptr = new;
            temp = new;
        }
        else
        {
            new->next = temp->next;
            temp->next = new;
            temp = new;
        }
    }
}
void print_rec(SLL *ptr)
{
    if (ptr)
    {
        printf("%d %s\n", ptr->rollnum, ptr->name);
        print_rec(ptr->next);
    }
}
void print_rev_rec(SLL *ptr)
{
    if (ptr)
    {
        print_rev_rec(ptr->next);
        printf("%d %s\n", ptr->rollnum, ptr->name);
    }
}
void print_rev_U_loop(SLL *ptr)
{
    int c, i, j;
    SLL *temp;
    c = count_nodes(ptr);
    for (i = 0; i < c; i++)
    {
        temp = ptr;
        for (j = 0;j<c-1-i;j++)
        {
            temp = temp->next;
        }
        printf("%d %s\n", temp->rollnum, temp->name);
    }
}
void print_rev_U_AP(SLL *ptr)
{
    SLL **q, *temp;
    temp = ptr;
    int c, i = 0, j;
    c = count_nodes(ptr);
    q = malloc(sizeof(SLL *) * c);
    while (temp)
    {
        q[i++] = temp;
        temp = temp->next;
    }
    for (j = c - 1; j >= 0; j--)
    {
        printf("%d %s\n", q[j]->rollnum, q[j]->name);
    }
}
void delete_all_nodes(SLL **ptr)
{
    SLL *p;
    p = *ptr;
    if (p->next == 0)
    {
        free(p);
        *ptr = 0;
    }
    else
    {
        while (*ptr)
        {
            p = p->next;
            *ptr = (*ptr)->next;
            free(*ptr);
            *ptr = p;
        }
    }
}
void delete_node(SLL **ptr)
{
    SLL *p, *q;
    p = *ptr;
    int num;
    printf("Enter the roll number\n");
    scanf("%d", &num);
    while (p)
    {
        if (p->rollnum == num)
        {
            if (p == (*ptr))
            {
                *ptr = (*ptr)->next;
                free(p);
            }
            else
            {
                q->next = p->next;
                free(p);
            }
        }
        q = p;
        p = p->next;
    }
}
void rev_link(SLL *ptr)
{
    SLL *p, *q, v;
    p = ptr;
    int c, i, j;
    c = count_nodes(ptr);
    for (i = 0; i < c / 2; i++)
    {
        q = ptr;
        for (j = 0; j < c - i - 1; j++)
            q = q->next;

        v.rollnum = p->rollnum;
        strcpy(v.name, p->name);

        p->rollnum = q->rollnum;
        strcpy(p->name, q->name);

        q->rollnum = v.rollnum;
        strcpy(q->name, v.name);

        p = p->next;
    }
}
void rev_link_printing(SLL **ptr)
{
    SLL *temp, **p;
    temp = *ptr;
    int c, i = 0;
    c = count_nodes(*ptr);
    p = malloc(sizeof(SLL *) * c);

    while (temp)
    {
        p[i++] = temp;
        temp = temp->next;
    }
    p[0]->next = 0;
    for (i = 1; i < c; i++)
    {
        p[i]->next = p[i - 1];
    }
    *ptr = p[c - 1];
}

void sort_data(SLL *ptr)
{
    if(ptr==0)
    {
        printf("no records\n");
        return;
    
    }

    SLL *p1,*p2,temp;
    p1=ptr;
    int i,j,c=count_nodes(ptr);
    for(i=0;i<c-1;i++)
    {
        
        for(p2=p1->next,j=i+1;j<c;j++)
        {
            if(p1->rollnum  < p2->rollnum)
            {
                temp.rollnum=p1->rollnum;
                strcpy(temp.name,p1->name);

                p1->rollnum=p2->rollnum;
                strcpy(p1->name,p2->name);

                p2->rollnum=temp.rollnum;
                strcpy(p2->name,temp.name);
            }
        p2=p2->next;
        }
       p1=p1->next;
    }

}
void find_node(SLL *ptr)
{
    SLL *temp;
    int c=0;
    
    temp=ptr;
    int num;
    if(ptr==0)
    {
        printf("There is no nodes are present\n");
        return;
    }
    printf("Enter the rollnum you want to search\n");
    scanf("%d",&num);

    while(ptr)
    {
        c++;
        if(ptr->rollnum==num)
        {
            printf("The rollnum is present in %d node\n",c);
            return;
        }
        ptr=ptr->next;
    }   
    printf("The roll number you entered is not present in any node\n");
}

