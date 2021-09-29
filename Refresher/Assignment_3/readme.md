# Q1) calendar.sh
### Input
* we need to supply the date in space seperated fashion to run the script
* ie . for calendar for 22/07/2022 the run command would be as follows from the directory where script is present :- 
```
./calendar.sh 22 07 2022
```
### Output
* The calendar for month and year of given date is displayed

### Working
* The bash inbuilt cal command is called with month and year as argument from given date.

# Q2) calculator.sh
### Input
* We need to supply the operation type and the integer arguments in a space seperated manner.
  * add for addition
  * sub for subtraction
  * div for division
  * exp for exponentiation
* ie. to perform exponentiation for 2^3 the command is :-
```
./calculator.sh exp 2 3
```

# Q3 a) BST_insert.c
### Input
* I have hardcoded the input for inserting nodes to a binary tree with inorder traversal as 20 30 40 50 60 70 80.
* And then I delete the 70 node from the BST and print inorder traversal of modified tree.
* No input is required.
### Output
* Firstly the binary tree with inorder traversal as 20 30 40 50 60 70 80 is printed.
* Then node 70 is deleted
* Now again the modified BST inorder traversal is printed as 20 30 40 50 60 80.

# Q3 b) Balanced_BST.c (AVL Tree)
# Input
* I have hardcoded the input for inserting nodes to a Balanced BST (AVL Tree) with preorder traversal as 30 20 10 25 40 50.
* So no input is required
### Output
* The preorder traversal of the tree given in input is printed.

# Q4 sort.c
### Input
* First input the number of elements in the array
* Now input the elements of the array in the space seperated fashion.
* Now enter s for selection sort and b for bubble sort.

### Output
* First the name of chosen sorting algo is printed on the screen.
* Sorted array for the given input array is printed using chosen sorting algorithm.