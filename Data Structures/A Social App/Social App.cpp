#include <iostream>
#include<cstring>
using namespace std;

class profile
{
    public:
        char name[50];
        char email[30];
        char city[30];
        profile *prev ;
        profile *next;
        bool isFriend;
        profile(char nm[] , char em[] , char ct[])
        {
            strcpy( name ,nm);
            strcpy(email , em);
            strcpy(city , ct);
            prev = NULL;
            next = NULL;
            isFriend = false;

        }
    friend class socialApp;

};

class socialApp
{
    profile *head;
    profile *fhead;
    profile *temp;
    profile *ptr;
    profile *fptr;

    profile *ptr1, *ptr2, *dup;

    public:
    profile *prevn;
   

    void addAccount();
    void showSuggestions();
    void showFriends();
    void removeFriend(char p[20]);
    void searchFriend(char p[20]);
    void searchByEmail(char p[20]);
    void DeleteFromSuggestion(char p[20]);
    void addFriend(profile *a);

    socialApp()
    {
        head=NULL;
        temp=NULL;
        ptr=NULL;
        fptr=NULL;
        ptr1=NULL;
        ptr2=NULL;
        dup=NULL;
        fhead = NULL;
    }

};

void socialApp::addAccount()
{
    char name[50];
    char email[30];
    char city[30];
    int age;
    char ans;
    do
    {
        cout<<"ENTER NAME      :";
        cin>>name;
        cout<<"ENTER Email   :";
        cin>>email;
        cout<<"ENTER CITY   :";
        cin>>city;
         temp = new profile(name , email , city);
         if(head == NULL)
         {
            head = temp;
         }
         else
        {
            ptr=head;
		    while(ptr->next!=NULL)
		    {
                ptr=ptr->next;
		    }
		    ptr->next=temp;
		    temp->prev=ptr;
        }
        cout<<"DO YOU WANT TO CONTINUE?????????";
        cin>>ans;
    }while (ans=='y');

  
}

void socialApp::showSuggestions()
{
    ptr = head;
    char ans;
    char selec;
    while(ans!= 'N' && ptr != NULL)
    { 
       
        ptr1 = head;
        while(ptr1 != NULL)
        {   
            if(ptr1==ptr){
            cout<<"\n";
            cout<<"\n\nNAME::\t"<<ptr1->name;
			cout<<"\nEMAIL::\t"<<ptr1->email;
			cout<<"\nCITY::\t"<<ptr1->city;
            cout<<"\n";

            }

			ptr1=ptr1->next;
        
        }
         cout<<"DO YOU WANT TO ADD THIS PERSON AS A FRIEND??      :";
            cin>>selec;
            if(selec == 'y' && ptr->isFriend == false)
            {
                profile *ftemp;
                ftemp = new profile(ptr->name , ptr->email , ptr->city);
                ptr->isFriend = true;
                addFriend(ftemp);
                DeleteFromSuggestion(ptr->name);
            }
            else if(selec == 'n')
            {
                cout<<"CONTINUE";
            }
            
        cout<<"\nPRESS\n R TO GO TO NEXT\n L TO GO TO PREVIOUS\n N TO EXIT\n";
        cin>>ans;
        if(ans == 'R')
        {
            ptr = ptr->next;
        }
        else if(ans == 'L')
        {
            ptr = ptr->prev;
        }
    }
    

    
   
}
void socialApp::addFriend(profile *pf)
{
    if(fhead == NULL)
    {
        fhead = pf;
    }
    else
    {
        fptr = fhead;
        while(fptr->next!=NULL)
        {
            fptr = fptr->next;
        }
        fptr->next=pf;
		pf->prev=fptr;
    }

    cout<<"\n\nFRIEND HAS BEEN ADDED\n";

}

void socialApp::showFriends()
{
    fptr = fhead;
    cout<<"\n\nYOUR FRIENDS\n";
    while(fptr!=NULL)
    {
       
        cout<<"\n\nNAME::\t"<<fptr->name;
		cout<<"\nEMAIL::\t"<<fptr->email;
		cout<<"\nCITY::\t"<<fptr->city;

        fptr = fptr->next;
           
    }
}

void socialApp::searchFriend(char na[10])
{
    bool found = false;
    fptr = fhead;
    while(fptr!=NULL)
    {
        if(strcmp(na,fptr->name)==0)
        {
            found = true;
            cout<<"NAME FOUND";
            cout<<"DETAILS ARE BELOW:\n";
        	cout<<"\n\nNAME  ::\t"<<fptr->name;
        	cout<<"\n\nEMAIL  ::\t"<<fptr->email;
        	cout<<"\n\nCITY ::\t"<<fptr->city;

        }
        fptr=fptr->next;
    }
    if(found == false)
    {
        cout<<"FRIEND NOT PRESENT";
    }
}

void socialApp::searchByEmail(char na[10])
{
    bool found = false;
    fptr = fhead;
    while(fptr!=NULL)
    {
        if(strcmp(na,fptr->email)==0)
        {
            found = true;
            cout<<"NAME FOUND";
            cout<<"DETAILS ARE BELOW:\n";
        	cout<<"\n\nNAME  ::\t"<<fptr->name;
        	cout<<"\n\nEMAIL  ::\t"<<fptr->email;
        	cout<<"\n\nCITY ::\t"<<fptr->city;

        }
        fptr=fptr->next;
    }
    if(found == false)
    {
        cout<<"FRIEND NOT PRESENT";
    }
}


void socialApp::removeFriend(char s[20])
{
    int c=0;
    fptr=fhead;
    while(fptr!=NULL)
    {
        if(strcmp(s,fptr->name)==0)
        {
            c=1;
            break;
        }
        else
        {
            c=2;
        }
        fptr=fptr->next;
    }
    if(c==1 && ptr!=head && ptr->next!=NULL)
    {
        fptr->prev->next=fptr->next;
        fptr->next->prev=fptr->prev;
        delete(fptr);
        cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if(fptr==fhead)
    {
        fhead=fhead->next;
        fhead->prev=NULL;
        delete(fptr);
        cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if(fptr->next==NULL)
    {
        fptr->prev->next=NULL;
        fptr->prev=NULL;
        delete(ptr);
        cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if(c==2)
    {
        cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
    }
}

void socialApp::DeleteFromSuggestion(char p[20])
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(p,ptr->name)==0)
        {
            c=1;
            break;
        }
        else
        {
            c=2;
        }
        ptr=ptr->next;
    } 
    if(c==1 && ptr!=head && ptr->next!=NULL)
    {
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        delete(ptr);
    }
    if(ptr==head)
    {
        head=head->next;
        head->prev=NULL;
        delete(ptr);
    }
    if(ptr->next==NULL)
    {
        ptr->prev->next=NULL;
        ptr->prev=NULL;
        delete(ptr);
    }
}

int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char email[20];
    char city[20];
    int age;
    socialApp app;
    char ans;
    int ch,a;
    cout<<"**************                                FRIENDCIRCLE                          ********************";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin>>name;
    cout<<"\n\nWHAT IS YOUR EMAIL?\n";
    cin>>email;
    cout<<"\n\nWHERE ARE YOU FROM?\n";
    cin>>city;
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLET'S SOCIALIZE \n\n";
    do
    {
        cout<<"\n\n1)ADD ACCOUNT\n2)SHOW SUGGESTIONS\n3)SHOW FRIENDS\n4)SEARCH A FRIEND\n5)Search By Email\n6)REMOVE A FRIEND\n";
        cin>>ch;
        if(ch == 1)
        {
            app.addAccount();
        }
        else if(ch == 2)
        {
            app.showSuggestions();
        }
        else if(ch==3)
        {
            app.showFriends();
        }
        else if(ch == 4)
        {
             cout<<"ENTER THE NAME OF THE FRIEND YOU WANT TO SEARCH\n";
            cin>>name;
            app.searchFriend(name);
        }
        else if(ch == 5)
        {
             cout<<"ENTER THE EMAIL OF THE ACCOUNT YOU WANT TO SEARCH\n";
            cin>>name;
            app.searchByEmail(name);
        }
        else if(ch == 6)
        {
            cout<<"ENTER THE NAME OF THE FRIEND YOU WANT TO REMOVE\n";
            cin>>name;
            app.removeFriend(name);
        }
        cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
        cin>>ans;

    }while(ans=='y');


}