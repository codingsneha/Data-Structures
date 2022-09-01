/*       MENU DRIVEN PROGRAM TO IMPLEMENT LINKED LIST          */


/*Operations possible on a single linked list are listed below:
* 1. TRAVERSING the list
* 2. INSERTING a node into the list
* 3. DELETING a node from the list
* 4. COPYING the list to make a duplicate of it
* 5. SEARCHING for an element in the list
* 6. REVERSING the list
* 7. SORTING the list   */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Creating Linked-List
struct node{
    int data;
    struct node *next;
};

static struct node *head=NULL;         //Head points to first element



/*_________________________________________________________________________*/


//~~~is list empty
bool isEmpty() {
   return head == NULL;
}


//~~~calculate size
int calcSize(struct node *node){
   int size=0;

   while(node){
      node=node->next;
      size++;
   }

   return size;
}



//~~~find length of the list
int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}


/*_________________________________________________________________________*/



/* 1. TRAVERSING
   Printing the list  */
void display() {

   if(isEmpty){
      printf("\n\nCurrently list is empty");
      return;
   }

    struct node *ptr=head;                        //ptr is to store the pointer to a current node
    printf("\nList - \n\n[ ");
    while(ptr){                                   //continue till the last node
        printf("%d, ", ptr->data);       
        ptr=ptr->next;                             //move to the next node
    }
    printf(" ]");
}




/* 2. INSERTION
   2.1. Insertion at front
   2.2. Insertion at end
   2.3. Insertion at any other position */


//2.1 Insertion at front
void insertFirst(int data) {
   struct node *new = (struct node*) malloc(sizeof(struct node));         // create new node
	/* malloc returns void* type, we are type casting it to the user 
      defined type struct node and then storing its value to node named new */

   new->data = data;             //store data in new node
	
   new->next = head;            //point it to old first node
	
   head = new;                  //point head to new first node
}




//2.2 Insertion at end
void insertEnd(int data) {

   struct node *new = (struct node*) malloc(sizeof(struct node));      //create new node

   new->data = data;
   new->next = NULL;


   //If linked list is empty
   if(!isEmpty()){
      head=new;
      return;
   }


   struct node *temp = head;           //temporary node

   while(temp->next)                   // go till the very end
      temp=temp->next;                 // point temp to ending node

   temp->next=new;                     //store value in end node

}





//2.3 Insertion at any other position
void insertPosition(int pos, int data) {
   int size= calcSize(head);

   //If pos is 0 then should use insertStart method
    //If pos is less than 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if(pos < 1 || size < pos) { 
        printf("\n\nCan't insert, %d is not a valid position\n",pos); 
    } 
    else{
      struct node *temp = head;                       //temporary variable pointing to head
      struct node *new = (struct node*) malloc(sizeof(struct node));      //create new node

      new->data = data;
      new->next = NULL;

      while(--pos){
         temp=temp->next;
      }

      new->next = temp->next;
      temp->next = new;
    }

 
 }











/* 3. DELETING
      1. Deletion at beginning
      2. Deletion at end
      3. Deletion at any other node */




// 3.1 Deletion at beginning
void deleteFirst() {

   //if linked list is empty
   if(isEmpty()){
      printf("\n\nWait, list is already empty!\n");
      return;
   }

   struct node *temp = head;              //save reference to first link in temporary variable


   //if there is only one node in linked list
   if(temp->next==NULL){
      head = NULL;
      printf("\n\nValue %d, deleted \n",temp);
      free(temp);
      return;
   }
	
   head = head->next;                     //mark next to first link as first 
	
   //return the deleted link
   printf("\n\nDeleted value %d\n", temp);
}





// 3.2 Deletion at end
void deleteEnd() {

   //if linked list is empty
   if(isEmpty()){
      printf("\n\nWait, list is already empty!");
      return;
   }

   struct node *temp = head;              //save reference to first link in temporary variable


   //if there is only one node in linked list
   if(temp->next==NULL){
      head = NULL;
      printf("\n\nValue %d, deleted \n",temp);
      free(temp);
      return;
   }

   struct node *ptr = NULL;
   while(ptr->next){
      ptr = temp;
      temp = temp->next;
   }

   ptr->next=NULL;
      free(ptr);

}




// 3.3 Deletion at any other position
void deletePos(int pos) {
   struct node *temp = head;
   struct node *previous;


    int size = calcSize(head);

    if(pos<1 || pos>size) {
        printf("\n\nEnter valid position!\n");

        return;
    }


    if(pos==1){
        head = temp->next;          //changing head to next in the list
        printf("\n\nValue %d, deleted \n",temp->data);
        free(temp);
        return;
    }


   while (--pos) {             //Until value to be deleted is found
   
        //store previous link node as we need to change its next val
        previous = temp; 
        temp = temp->next; 
    }

    previous->next = temp->next;
    printf("\n\nValue %d, deleted \n",temp->data);

    free(temp);

}









//4. COPYING
struct node *copy(struct node *head) {
   display();

   if (head==NULL){
      printf("\n\nList is empty!\n");
      return NULL;
   }

   struct node *copyList = (struct node *) malloc(sizeof(struct node));
   copyList->data = head->data;
   copyList->next = copy(head->next);

   printf("\nCopied List - \n\n[ ");
    while(copyList){                                   //continue till the last node
        printf("%d, ", copyList->data);       
        copyList=copyList->next;                             //move to the next node
    }
    printf(" ]");

   return copyList;
}









//5. SEARCHING
void search(int item){

   if(isEmpty()){
      printf("\n\nEmpty List!\n");
      return;
   }


   struct node *ptr = head;

   int flag=0, i=0;
   while(ptr){
      if(ptr->data==item)
         printf("\n\nItem found at location %d\n", i+1);
      else
        flag=1;

      i++;
      ptr=ptr->next;
   }

   if(flag==1)
      printf("\n\nElement not found\n");


}








//6. REVERSING
void reverse(struct node *head_ref) {
   struct node* prev   = NULL;
   struct node* current = head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   head_ref = prev;
}








//7. SORTING
void sort() {

   int i, j, k, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

         }
			
         current = current->next;
         next = next->next;
      }
   }   
}




//    MENU
void menu(){

   printf("\n\n____________________________________________________________");
   printf("\n\nChoose one - ");
   printf("\n\n\n\t1. DISPLAY the list");
   printf("\n\n\t2. INSERTING a node into the list");
   printf("\n\n\t3. DELETING a node from the list");
   printf("\n\n\t4. COPYING the list to make a duplicate of it");
   printf("\n\n\t5. SEARCHING for an element in the list");
   printf("\n\n\t6. REVERSING the list");
   printf("\n\n\t7. SORTING the list");
   printf("\n\n\t8. EXIT");

   printf("\n\nEnter the operation you'd like to perform [1-8] : ");
}



void main() {

   printf("\n\n\n\t\tHey human!");
   printf("\n\n\t\t Welcome");
   printf("\n\nAs you already may be aware, ");
   printf("\nfollowing operations are possible on a single linked list - ");

   int choice=1, i=0, d=0, data, pos;

   while(choice){
      menu();

      scanf("%d", &choice);


      switch (choice) {

         case 1:

            display();

            break;
      
         case 2:
         //INSERTION

            printf("\nChoose one option - \n\n\t1. Insert at first\n\t2. Insert at end\n\t3. Insert at any other position\n\nEnter[1-3]: ");
            scanf("%d", &i);

            switch (i){
               case 1:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at beginning . . .\n\nDone!", data);
                  insertFirst(data);
                  display();
                  break;

               case 2:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at end . . .\n\nDone!", data);
                  insertEnd(data);
                  display();
                  break;

               case 3:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nEnter position: ");
                  scanf("%d", &pos);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at position %d . . .\n\nDone!", data, pos);
                  insertFirst(data);
                  display();
                  break;
            }


            break;
      
         case 3:
         // DELETION

            printf("\nChoose one option - \n\n\t1. Delete element at front\n\t2. Delete element at end\n\t3. Delete at any other position\n\nEnter[1-3]: ");
            scanf("%d", &d);

            switch (d){
               case 1:
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting first element . . .\n\nDone!");
                  deleteFirst();
                  break;

               case 2:
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting last element . . .\n\nDone!", data);
                  deleteEnd();
                  break;

               case 3:
                  printf("\nEnter position: ");
                  scanf("%d", &pos);
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting at position %d...\n\nDone!", pos);
                  deletePos(pos);
                  break;
            }

            break;



         case 4:
         //COPY

            copy(head);

            break;
      
         case 5:
         //SEARCH

            printf("\n\nEnter element to be searched: ");
            scanf("%d", &data);

            search(data);

            break;
      
         case 6:
         //REVERSE

            display();
            reverse(head);
            printf("\n\nReversing list . . .\n\nDone!");
            display();

            break;
      
         case 7:
         //SORTING

            display();
            sort();
            printf("\n\nSorting list . . .\n\nDone!");
            display();

            break;
      
         case 8:
            choice=0;
            break;
      
         default:
            printf("\n\nEnter valid choice!");
      }
   }
   

}