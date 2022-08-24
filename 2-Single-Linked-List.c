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
        printf("Can't insert, %d is not a valid position\n",pos); 
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
      printf("\nList is already empty!\n");
      return;
   }

   struct node *temp = head;              //save reference to first link in temporary variable


   //if there is only one node in linked list
   if(temp->next==NULL){
      head = NULL;
      printf("Value %d, deleted \n",temp);
      free(temp);
      return;
   }
	
   head = head->next;                     //mark next to first link as first 
	
   //return the deleted link
   printf("\nDeleted value %d\n", temp);
}





// 3.2 Deletion at end
void deleteEnd() {

   //if linked list is empty
   if(isEmpty()){
      printf("\nList is already empty!\n");
      return;
   }

   struct node *temp = head;              //save reference to first link in temporary variable


   //if there is only one node in linked list
   if(temp->next==NULL){
      head = NULL;
      printf("Value %d, deleted \n",temp);
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


    int size = calcSize(*head);

    if(pos<1 || pos>size) {
        printf("\nEnter valid position!\n");

        return;
    }


    if(pos==1){
        head = temp->next;          //changing head to next in the list
        printf("Value %d, deleted \n",temp->data);
        free(temp);
        return;
    }


   while (--pos) {             //Until value to be deleted is found
   
        //store previous link node as we need to change its next val
        previous = temp; 
        temp = temp->next; 
    }

    previous->next = temp->next;
    printf("Value %d, deleted \n",temp->data);

    free(temp);

}









//4. COPYING
struct node *copy(struct node *head) {
   display();

   if (head==NULL){
      printf("\nList empty\n");
      return;
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
      printf("\nEmpty List!\n");
      return;
   }


   struct node *ptr = head;

   int flag=0, i=0;
   while(ptr){
      if(ptr->data==item)
         printf("\nItem found at location %d\n", i+1);
      else
        flag=1;

      i++;
      ptr=ptr->next;
   }

   if(flag==1)
      printf("\nElement not found\n");


}








//6. REVERSING
void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
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







void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   display();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   display();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   display();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   display();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
	
   printf("\n");
   sort();
	
   printf("List after sorting the data: ");
   display();
	
   reverse(&head);
   printf("\nList after reversing the data: ");
   display();
}