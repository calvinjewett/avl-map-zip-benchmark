[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/sWYTrMDR)


Performance Analysis and Summary: 

Note: time in this program and referred to in this summary is measured in microseconds. 
All samples were conducted on a structure (either avl tree or std::map) with "n" amount of nodes, and 10000 (ten thousand) random searches conducted on the tree, using valid zip codes. 10000 was chosen as an arbitrary number that was large enough to ensure a robust sample size, but not too large to the point where it would be largely unneccessary or make the program take too long.

t = amount of microseconds
n = amount of data input to the program

AVL trees maintain O(log(n)) performance by continuously self-balancing as more information is added to them. This ensures a balanced Binary Search Tree, with the furthest possible leaf from the root being a distance of log(base 2)(n), where "n" represents the amount of data stored in the entire tree. This means it takes log(base 2(n)) amount of time to perform any operation, from insert to search to delete, on any of its nodes. 

Performance Analysis:
My std::map had time complexity of t = 348.5 * log(base 2)(n) + 327.9, with an R-squared value of 0.974.
The R-squared value being very close to 1, with template a*log(base 2) + b, indicates that my data closely matched the trend line, supporting that this operation has a time complexity of O(log(n)). 

My custom-implemented AVL tree had time complexity of t = 311.8 * log(base 2)(n) - 73.4, with an R-squared value of 0.988. 
The R-squared value being very close to 1, with template a*log(base 2) + b, indicates that my data closely matched the trend line, supporting that this operation has a time complexity of O(log(n)). 


Given that for all possible data input sizes "n," my custom AVL tree t-value will be lower than that of the std::map, I can state that my function takes less time to compute than the essentially-identical implementation of std::map, but they still have the same big-O complexity as each other, with both having the time complexity of O(log(n)). 
The trade-off between my implementation of AVL trees and std::map, however, is that std::map can change itself to accommodate far more different types of data, as well as doing operations on all those different types. Also, std::maps are a part of a library that can be imported at any time into any program easily, whereas my AVL tree cannot. 

This program uses the same logic for inserting data into the AVL tree as it does for looking up data, both using the same type of keys (ints) and the same logic for how to traverse the tree to obtain the correct location do perform an operation. The main difference is that inserting also may cause rotations of nodes within the tree, but there will be at most 2 rotations per insertion, and every component of the rotation takes constant time to perform. Therefore, it's fair to say that inserting takes a * log(base 2)(n) + b time to complete, and therefore is also an operation with time complexity of O(log(n)). 

Summary: 
The goal of this program is to extract information from a .csv file and store the data inside of a std::map and a custom version of an AVL tree. The data will be stored according to its ZIP code in the form of an int, which the program uses as the key to store the nodes in the structures. All of the valid ZIP codes are stored in a vector so as to access them with a time complexity of O(1), constant time. 
The size of the structures, and thus the amount of data stored in them, will be carefully varied throughout the program in order to test how long it will take to run the searches on these structures when they have varying amounts of data stored within them. 
Then, the program runs 10000 (ten thousand) random searches of valid ZIP codes (collected via random indexes of the vector) on each structure created throughout the program. The amounts of time it takes to run this constant amount of searches on differing sizes of structures will be output to the terminal. These outputs will form data points, where the independent variable is the amount of data stored in each structure, and the dependent variable is the amount of time it takes to do this constant amount of searches. 
These data points will form trend lines, one for each type of structure, both of which are expected to show time complexity of the form t = a * log(base 2)(n) + b, which fits into big-O notation of O(log(n)). 
