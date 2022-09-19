#include <stdio.h>
#include <stdlib.h>

struct student
{
    int ID;
    int sem;
    struct student * next;
};

struct course
{
    int Courseno;
    struct student * Startt;
    struct Course * nextt;
};

struct course * start = NULL;
int addcourse = 0;


int Cinsert()
{
    addcourse = 1;
    printf("\n\nInserting A course\n\n");
    struct course * temp = (struct course*)malloc(sizeof(struct course));
    int cNO;
    printf("Enter the course ID\n");
    scanf("%d" , &cNO);

    temp -> Courseno = cNO;
    temp -> Startt = NULL;
    temp -> nextt = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct course *current = start;
        while(current->nextt!=NULL)
        {
            current = current->nextt;
        }
        current->nextt = temp;
    }
}

int Cdisplay()
{
    if(addcourse == 0)
    {
        printf("No Courses in the list\n");
        main();
    }
    struct course * current = start;
    while(current!=NULL)
    {
        printf("%d\n" , current->Courseno);
        current = current->nextt;
    }
}

int Sinsert()
{
    int flag1 = 0;
    
    int wcourse;
    printf("Enter the Course number you want to add a student in\n");
    scanf("%d" , &wcourse);


    struct course * current = start;
    while(current != NULL)
    {
        if(current->Courseno == wcourse)
        {
            struct student * temp = (struct student*)malloc(sizeof(struct student));
            int sID,semester;
            printf("Enter the ID of the student that you want to add\n");
            scanf("%d" , &sID);
            printf("Enter the semester the student is in\n");
            scanf("%d" , &semester);
            temp->ID = sID;
            temp->sem = semester;
            temp->next = NULL;
            if(current->Startt == NULL)
            {
                current->Startt = temp;
            }
            else
            {
                struct student * curr = current->Startt;
                while(curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = temp;
            }
            flag1 = 1;         

        }
        current = current->nextt;
    }
    if(flag1 == 0)
    {
        printf("Not found\n");
    }

}

int sDisplay()
{
    if(addcourse == 0)
    {
        printf("No courses in the list\n");
        main();
    }
    
    int flag2 = 0;
    int Wcourse;
    printf("Enter The Course you want to display the students of\n");
    scanf("%d" , &Wcourse);

    struct course * current = start;
    while(current != NULL)
    {
        if(current->Courseno == Wcourse)
        {
            flag2 = 1;
            if(current->Startt==NULL)
            {
                printf("No Students in this course\n");
                break;
            }

            
            struct student * curr = current->Startt;
            while(curr != NULL)
            {
                printf("The course is %d\n" , current->Courseno);
                printf("Student ID is %d\n" , curr->ID);
                printf("Semester is %d\n\n" , curr->sem);
                curr = curr->next;
            }
           
        }
        
        current = current->nextt;
    }
    if(flag2==0)
    {
        printf("Not Found\n");

    }
}

int csearch()
{
    if(addcourse == 0)
    {
        printf("No courses in the list\n");
        main();
    }
    int wcourse;
    int flag3 = 0;
    printf("Enter the course number that you want to search\n");
    scanf("%d" , &wcourse);
    struct course * current = start;
    while(current!=NULL)
    {
        if(current->Courseno == wcourse)
        {
            printf("Course Found\n");
            flag3 = 1;
            break;
        }
        current = current->nextt;
    }
    if(flag3 == 0)
    {
        printf("Course Not present\n");
    }
}

int Ssearch()
{
    if(addcourse == 0)
    {
        printf("No courses in the List\n");
        main();
    }
    int flag4 = 0;
    int flag5 = 0;
    int wcourse;
    printf("Enter the Course that you want to search the students in\n");
    scanf("%d" , &wcourse);
    struct course * current = start;
    while(current!=NULL)
    {
        if(current->Courseno == wcourse)
        {
            flag4 = 1;
            if(current->Startt==NULL)
            {
                printf("No Students in this course\n");
                break;
            }
            
            struct student * curr = current->Startt;
            int wstud;
            printf("Enter the student id of the student that you want to search\n");
            scanf("%d" , &wstud);
            while(curr!=NULL)
            {
                if(curr->ID == wstud)
                {
                    printf("Student found\n");
                    flag5 = 1;
                    break;
                }
                curr = curr->next;
            }
            if(flag5 == 0)
            {
                printf("Student not present\n");
            }

        }
        current = current->nextt;
    }
    if(flag4 == 0)
    {
        printf("Course Not present\n");
    }
}
int Cdel()
{
    if(addcourse == 0)
    {
        printf("No course in the list\n");
         main();
    }
    int wcourse;
    int flag6 = 0;
    printf("Enter the course that you want to delete\n");
    scanf("%d" , &wcourse);
    struct course * current = start;
    struct course * prev = start;
    
    if(current->Courseno == wcourse)
    {
        if(current->nextt == NULL)
        {
            if(current->Startt != NULL)
            {
                while(current->Startt != NULL)
                {
                    struct student * curr = current->Startt;
                    struct student * prev = current->Startt;
                    if(curr->next == NULL)
                    {
                        free(curr);
                        current->Startt = NULL;
                    }
                    else
                    {
                        curr = curr->next;
                        prev = prev;
                        // struct course * curr = current->Startt;
                        while(curr->next!=NULL)
                        {
                            curr = curr->next;
                            prev = prev->next;
                        }
                        
                        free(curr);
                        prev->next = NULL;
                        
                    }
                }
            }
            addcourse = 0;
            free(start);
            start = NULL;
            flag6 = 1;
        }
        else
        {
            if(current->Startt != NULL)
            {
                while(current->Startt != NULL)
                {
                    struct student * curr = current->Startt;
                    struct student * prev = current->Startt;
                    if(curr->next == NULL)
                    {
                        free(curr);
                        current->Startt = NULL;
                    }
                    else
                    {
                        curr = curr->next;
                        prev = prev;
                        // struct course * curr = current->Startt;
                        while(curr->next!=NULL)
                        {
                            curr = curr->next;
                            prev = prev->next;
                        }
                        
                        free(curr);
                        prev->next = NULL;
                        
                    }
                }
            }
            start = start->nextt;
            free(current);
            flag6 = 1;
        }
    }
    else
    {

        current = current->nextt;
        prev = prev;
        
        while(current!=NULL)
        {
            if(current->Courseno == wcourse)
            {
                if(current->Startt != NULL)
                {
                    while(current->Startt != NULL)
                    {
                        struct student * curr = current->Startt;
                        struct student * prev = current->Startt;
                        if(curr->next == NULL)
                        {
                            free(curr);
                            current->Startt = NULL;
                        }
                        else
                        {
                            curr = curr->next;
                            prev = prev;
                            // struct course * curr = current->Startt;
                            while(curr->next!=NULL)
                            {
                                curr = curr->next;
                                prev = prev->next;
                            }
                            
                            free(curr);
                            prev->next = NULL;
                            
                        }
                    }
                }
                prev->nextt = current->nextt;
                free(current);
                flag6 = 1;
            }
            current = current->nextt;
            prev = prev->nextt;
        }
    }
    if (flag6 == 0)
    {
        printf("Course Not Found\n");
    }
}
int Sdel()
{
    if (addcourse == 0)
    {
        printf("No courses in this list\n");
        main();
    }
    int wcourse;
    int flag7 = 0;
    int flag8 = 0;
    printf("Enter The course you want to delete the student from\n");
    scanf("%d" , &wcourse);
    struct course * current = start;
    while(current!= NULL)
    {
        if(current->Courseno == wcourse)
        {
            flag7 = 1;
            if(current->Startt == NULL)
            {
                printf("No Students in this course\n");
                break;
            }
            struct student * curr = current->Startt;
            struct student * prev = current ->Startt;
            int wstud;
            printf("Enter the ID of the student that you want to remove\n");
            scanf("%d" , &wstud);
            if(curr->ID == wstud)
            {
                if(curr->next == NULL)
                {
                    flag8 = 1;
                    free(curr);
                    current->Startt = NULL;
                    main();
                }
                else
                {
                    flag8 = 1;
                    current->Startt = current->Startt->next;
                    free(curr);
                }
            }
            else
            {
                curr = curr->next;
                prev = prev;
                while(curr!=NULL)
                {
                    if(curr->ID == wstud)
                    {
                        prev->next = curr->next;
                        free(curr);
                        flag8 = 1;
                    }
                    curr = curr->next;
                    prev = prev->next;
                }
                if(flag8 == 0)
                {
                    printf("Not Found\n");
                }
            }
        }
        current = current->nextt;
    } 
    if(flag7 == 0)
    {
        printf("Course not found\n");
    }  
    main();
}

int main()
{
    printf("\n\nMulti Linked List\n\n");
    int choice;
    
    while(choice!=0)
    {
        printf("Enter\n 1.Add A Course\n 2.Display Courses\n 3.Add A student\n 4.Display Students\n 5.Search Course\n 6.Student Search\n 7.Delete Course\n 8.Remove Student\n");
        scanf("%d" , &choice);
        if (choice == 1)
        {
            Cinsert();
        }
        if (choice == 2)
        {
            Cdisplay();
        }
        if (choice == 3)
        {
            Sinsert();
        }
        if (choice == 4)
        {
            sDisplay();
        }
        if (choice == 5)
        {
            csearch();
        }
        if (choice == 6)
        {
            Ssearch();
        }
        if (choice == 7)
        {
            Cdel();
        }
        if(choice == 8)
        {
            Sdel();
        }
    }
}