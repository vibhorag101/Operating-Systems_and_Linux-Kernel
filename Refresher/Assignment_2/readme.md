# Makefile
### It is assumed that a linux environment is used for running the makefile.
### To run the make file in the folder run command make from folder
```
make
```
### Now the individual compiled files are created as doublyLinked funcPointArr linkedList matrix rowChange sort 
``` 
now just run using:-
./swap
```



# Q1 a) matrix.c
### inputs
* To create a matrix shown in the image , I have hardcoded the values and no input is required.
  
### outputs
* Matrix as shown in the image is printed with each cell having a random value between 1-10.


### Working
* We have first created an array which contains the pointers to each row. The pointer to this array is double pointer of int ** type.
* Then using calloc we allocate the memory of required size and point to these arrays with the pointers in the arrays previously created where arrOut[i] represents the pointer to i'th row.
  
# Q1 b) rowChange.c
#### I have created the the same matrix as in Q1 a) so, the there are 6 rows only.
### inputs
* To create a matrix shown in the image , I have hardcoded the values.
* Firstly enter the row number you want to change from 0-5.
* Then enter the new number of elements in that row.
  
### outputs
* A new matrix is created with newly changed rows. The new row have a random number between 1-10.

### Working
* We have first created an array which contains the pointers to each row. The pointer to this array is double pointer of int ** type.
* Then using calloc we allocate the memory of required size and point to these arrays with the pointers in the arrays previously created where arrOut[i] represents the pointer to i'th row.
* Now to change the rows , we make use of realloc function.
* Also we maitain a size array , where size[i] denotes the number of elements in the i'th row.


# Q2 a) LinkedList.c
### inputs
* I have hardcoded the data of the three nodes in the linked list , hence no inputs need to be given
* First Node contains the record of the student with the name , Steve Rogers , second node with Tony Stark and 
  third node with name Bruce Banner

### Outputs
* The corresponding linked list is printed with academic records like Name , year of enrollment , roll and Course Name

### Working
* First we create a node with given data
* Then we link the node to next node.
* For printing the linked list we use printList function which prints the node untill it hits a null node.

# Q2 b) DoublyLinked.c
### inputs
* I have hardcoded the data of the three nodes in the linked list , hence no inputs need to be given
* First Node contains the record of the student with the name , Steve Rogers , second node with Tony Stark and 
  third node with name Bruce Banner

### Outputs
* The corresponding linked list is printed with academic records like Name , year of enrollment , roll and Course Name
  
### Working
* First we create a node with given data
* Then we link the node to next node.
* For printing the linked list we use printList function which prints the node untill it hits a null node.
* The way in which its different from a singly linked list is that it can also access the value of previous nodes.


# Q3 funcPointArr.c
#### We expect integer inputs.
### Inputs
* First enter a number between 0-4.
  * enter 0 for add.
  * enter 1 for subtract.
  * enter 2 for multiply.
  * enter 3 for divide.
  * enter 4 for exponentiation.
* Then first enter first number.
* And then enter the second number.
  
### Outputs
* The result for the chosen operation is displayed on the screen.

### Working
* We make use of Function Pointers Array.
* arr[i] represnts a pointer to the function like add, sub, div ,mul ,exponentiation.
* The function pointers take arguments just like the normal function call

```
    void (*arr[5])(int, int) = {add, sub, mul, div, exponent};
```

# Q5 sort.c
### Input
* First input the number of elements in the array
* Now input the elements of the array in the space seperated fashion.
* Now enter s for selection sort and b for bubble sort.

### Output
* First the name of chosen sorting algo is printed on the screen.
* Sorted array for the given input array is printed using chosen sorting algorithm.


