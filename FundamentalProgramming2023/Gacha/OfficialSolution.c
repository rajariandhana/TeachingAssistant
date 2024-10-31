#include <stdio.h>
#include <string.h>

struct contact
{
    int ID;
    char name[30];
    // char affiliation[30];
    int relations[21];
    int numOfRelations;
    int exist;
};
struct contact contactList[21]; 

int found = 0;
int visited[21];

void FindSetup()
{
    found = 0;
    for (int i=0; i<21; i++) visited[i] = 0;
}

void FindContact(int ID_start, int ID_target)
{
    // printf("st %d tar %d\n",ID_start,ID_target);
    if(ID_start == ID_target){found=1; return;}
    if(visited[ID_start] == 1) return;
    visited[ID_start] = 1;
    for(int i=0; i<=contactList[ID_start].numOfRelations; i++)
    {
        int nextID = contactList[ID_start].relations[i];
        FindContact(nextID, ID_target);
        if(found == 1) return;
    }
    return;
}

void InsertContact()
{
    int in_ID;
    char in_name[30];
    // char in_affiliation[30];
    // scanf("%d %s %s", &in_ID, in_name, in_affiliation);
    scanf("%d %s", &in_ID, in_name);
    contactList[in_ID].ID = in_ID;
    strcpy(contactList[in_ID].name, in_name);
    // strcpy(contactList[in_ID].affiliation, in_affiliation);
    contactList[in_ID].numOfRelations = -1;
    contactList[in_ID].exist = 1;
}

void SetRelation(int ID_A, int ID_B)
{
    int atob=0;
    for(int i=0; i<contactList[ID_A].numOfRelations; i++)
    {
        if(contactList[ID_A].relations[i] == ID_B) atob = 1;
    }
    if(atob == 0)
    {
        contactList[ID_A].numOfRelations++;
        int numOfRelationA = contactList[ID_A].numOfRelations;
        contactList[ID_A].relations[numOfRelationA] = ID_B;
    }

    int btoa=0;
    for(int i=0; i<contactList[ID_B].numOfRelations; i++)
    {
        if(contactList[ID_B].relations[i] == ID_A) btoa = 1;
    }
    if(btoa == 0)
    {
        contactList[ID_B].numOfRelations++;
        int numOfRelationA = contactList[ID_B].numOfRelations;
        contactList[ID_B].relations[numOfRelationA] = ID_A;
    }
}



int main()
{
    for(int i=0; i<21; i++)
    {
        contactList[i].exist = 0;
    }
    int vertices;
    scanf("%d", &vertices);
    while(vertices--)
    {
        InsertContact();
    }

    int edges;
    scanf("%d", &edges);
    while(edges--)
    {
        int ID_A, ID_B;
        scanf("%d %d", &ID_A, &ID_B);
        SetRelation(ID_A, ID_B);
    }

    //print all contact list
    // for(int i=0; i<21; i++)
    // {
    //     if(contactList[i].exist == 1)
    //     {
    //         printf("C: %d %s\n",i, contactList[i].name);
    //         for(int j=0; j<=contactList[i].numOfRelations; j++)
    //         {
    //             int rel = contactList[i].relations[j];
    //             printf("R: %d %s\n",rel, contactList[rel].name);
    //         }
    //         printf("\n");
    //     }
    // }

    int testcases;
    scanf("%d", &testcases);
    while(testcases--)
    {
        FindSetup();
        int ID_A, ID_B;
        scanf("%d %d", &ID_A, &ID_B);
        FindContact(ID_A, ID_B);
        if(found == 1)
        {printf("%s can reach %s\n", contactList[ID_A].name, contactList[ID_B].name);}
        else printf("We need more transponder snail\n");
    }
}

/*
1 AJ
2 CJ
3 DJ
4 JJ
5 KJ
6 MJ
7 OJ
8 RJ
9 TJ
*/