#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BloodBank
{
    char Name[20];
    char Blood[4];
    char Email[20];
    char Number[12];
    struct BloodBank *next;
}*Profile=NULL;

void Add()
{
    system("cls");
    struct BloodBank *CurrNode, *NewNode;
    NewNode= (struct BloodBank*)malloc(sizeof(struct BloodBank));
    printf("Enter Name:\n");
    scanf("%s",&NewNode->Name);
    printf("Enter Blood Group:\n");
    scanf("%s",&NewNode->Blood);
    printf("Enter Email:\n");
    scanf("%s",&NewNode->Email);
    printf("Enter Number:\n");
    scanf("%s",&NewNode->Number);
    NewNode->next=NULL;
    if(Profile==NULL)
    {
        Profile=NewNode;
    }
    else
    {
        CurrNode=Profile;
        while(CurrNode->next!=NULL)
        {
            CurrNode=CurrNode->next;
        }
        CurrNode->next=NewNode;
    }
}

void Search()
{
    struct BloodBank *display=Profile;
    int Count=0;
    char NAME[20],Blood[4];

Start:
    system("cls");
    printf("\n\tSearch by What?\n");
    printf("\n\t1. by Name\n\t2. by Blood Group\n\t3. Main Menu\n");
    switch(getch())
    {
    case '1':
    {
        printf("\nEnter Name to search profile:\n");
        scanf("%s",&NAME);
        while(display!=NULL)
        {
            if(strcmp(display->Name,NAME)==0)
            {
                Count++;
                printf("%d.\n\tName: %s",Count,display->Name);
                printf("\n\tBlood Group: %s",display->Blood);
                printf("\n\tEmail: %s",display->Email);
                printf("\n\tNumber: %s\n\n",display->Number);
            }
            display=display->next;
        }
        break;
    }
    case '2':
    {
        printf("\nEnter Blood Group to search profile:\n");
        scanf("%s",&Blood);
        while(display!=NULL)
        {
            if(strcmp(display->Blood,Blood)==0)
            {
                Count++;
                printf("%d.\n\tName: %s",Count,display->Name);
                printf("\n\tBlood Group: %s",display->Blood);
                printf("\n\tEmail: %s",display->Email);
                printf("\n\tNumber: %s\n\n",display->Number);
            }
            display=display->next;
        }
        break;
    }
    case '3':
    {
        goto End;
        break;
    }
    default:
    {
        printf("Wrong Input !\n");
        goto Start;
        break;
    }
    }
End:
    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

void Delete(struct BloodBank *CurrNode)
{
    system("cls");
    char Name[20];
    struct BloodBank *Prev=NULL;
    printf("\nTo delete a profile Please enter Name:\n");
    scanf("%s",&Name);
    while(CurrNode!=NULL)
    {
        if(strcmp(CurrNode->Name,Name)==0)
        {
            break;
        }
        Prev=CurrNode;
        CurrNode=CurrNode->next;
    }
    if(CurrNode==NULL)
    {
        printf("\n\nNot Found!\n");
    }
    else if(Prev==NULL)
    {
        Profile=CurrNode->next;
        free(CurrNode);
        printf("\n%s is deleted.\n",Name);
    }
    else
    {
        Prev->next=CurrNode->next;
        free(CurrNode);
        printf("\n%s is deleted.\n",Name);
    }
    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

void ViewAll(struct BloodBank *display)
{
    system("cls");
    int Count=0;
    while(display!=NULL)
    {
        Count++;
        printf("%d.\n\tName: %s",Count,display->Name);
        printf("\n\tBlood Group: %s",display->Blood);
        printf("\n\tEmail: %s",display->Email);
        printf("\n\tNumber: %s\n\n",display->Number);
        display=display->next;
    }
    if(Profile==NULL)
    {
        printf("BloodBank is Empty!");
    }
    printf("\n\nPress any key for Main Menu.\n");
    getch();
}

int main()
{
    system("COLOR 2f");
    int load1,load2;
    char Pass[20],Hint[20];
    printf("\n\tBloodBank Application By RubeL  (press any key to start)\n\t");
    getch();
Password:
    printf("\n\tPlease wait:");
    for(load1=1; load1<=30; load1++)
    {
        for(load2=0; load2<=10000000; load2++);
        printf("%c",177);
    }
    system("cls");
    printf("\n\tBloodBank Application By RubeL \n\n\tEnter Your Choice:");
    printf("\n\t1. Create Password\t2. Forgot Password?\t3. Login\t4. Exit\n");
    switch(getch())
    {
    case '1':
    {
        printf("\nEnter New Password:\n");
        gets(Pass);
        printf("\nEnter Hints for Security:\n");
        gets(Hint);
        goto Password;
        break;
    }
    case '2':
    {
        char Reset[20];
        printf("\nEnter Hints for Reset Password:\n");
        gets(Reset);
        if(strcmp(Hint,Reset)==0)
        {
            printf("\nEnter New Password:\n");
            gets(Pass);
            printf("\nPassword has been Changed Successfully.\n");
        }
        else
        {
            printf("\nYou Need to Remember Hints For Reseting Password!\n");
            getch();
        }
        goto Password;
        break;
    }
    case '3':
    {
        char Login[20];
        printf("\nEnter Password to Login:\n");
        gets(Login);
        if(strcmp(Pass,Login)==0)
        {
            goto Menu;
        }
        else
        {
            goto Password;
        }
        break;

    }
    case '4':
    {
        goto End;
        break;
    }
    default:
    {
        goto Password;
        break;
    }

    }
Menu:

    system("cls");
    printf("\n\tBloodBank Application By RubeL \n\n\tEnter Your Choice:");
    printf("\n\t1. Create\t2. Search\n\t3. Delete\t4. View All\n\t5. Exit \t6. LogOut\n");
    switch(getch())
    {
    case '1':
    {
        Add();
        goto Menu;
        break;
    }
    case '2':
    {
        Search();
        goto Menu;
        break;
    }
    case '3':
    {
        Delete(Profile);
        goto Menu;
        break;
    }
    case '4':
    {
        ViewAll(Profile);
        goto Menu;
        break;
    }
    case '5':
    {
        goto End;
        break;
    }
    case '6':
    {
        goto Password;
        break;
    }
    default:
    {
        goto Menu;
        break;
    }
    }
End:
    system("cls");
    printf("\n\tPlease wait:");
    for(load1=1; load1<=30; load1++)
    {
        for(load2=0; load2<=10000000; load2++);
        printf("%c",177);
    }
    system("cls");
    printf("\n\Thank you for using BloodBank.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("@ Copyright March,2016 || All Rights Reserved By RubeL\n");
    return 0;
}
