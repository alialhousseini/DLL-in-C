# DLL-in-C

### In this project you need to put in practice your knowledge in structures, files and doubly linked list material. You don’t need to use global variables or any other advanced material.

### I am providing you with the same file you used in the first project but this time you need to use a doubly linked list rather than an array to store the file data!

### You are asked to provide the user with the following menu
1. Create a doubly linked list for the file data
2. Update the revenues of a company
3. Get ranking information about a company
4. Remove a company from ranking
5. Add a new company to the list
6. Quit

- Every menu choice should be implemented using a user defined function
where you need to correctly use the appropriate input/output arguments,
if any the menu should also be printed using a function
- You need to make sure that you cannot execute choices 2 to 6 unless
choice 1 was already picked by the user
- For the first choice, you need to design a function that will have access to
your input file and generate an ordered doubly linked list (you construct a
doubly linked list sorted by revenues in a descending order).
- Define a function called add_company_node() a function that will
add an already created node to a doubly linked list. Make sure that
the node is inserted in the appropriate place. Remember we need to
create an ordered doubly LL
- For choice 2, we want to define a function to update the revenues of a
company X. Remember, the doubly linked list should maintain being
ordered. So if the new update will change the ranking of the company do it. You don’t need to sort the whole LL!!
- For choice number 3, we need to define a function that will return the
name of the predecessor(if exist) and the name of the successor (if exist) of
a particular company X
- For choice 4, we need to define a function that will delete a company from
the ranking; ie from the doubly LL
- For choice 5, you need to simply define a function needed to create/fill a
node (this time you are filling the node from data input by the user rather
than from a file) and then call add_company_node()
- For the last choice, quit, you simply need to define a function that will
update your input file with the new data in the linked list then end the
whole program.
