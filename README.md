# data_structures_project2


• When the program opens, it looks for the Numbers.txt file in the folder. It reads the lines written in the file line by line and sends them to the Add Line function, this function simultaneously takes the AVL tree as a parameter,<br>
• After the numbers in the row are assigned to the array, they are sorted with the Radix Sort sorting algorithm and then added to the AVL tree.
LevelUp or LevelDown functions are called in the balancing process after each node is added in the AVL Tree,<br>
• These functions start to be called on the child nodes of the node that are called as recursive functions, and the last or first number of the sequence in the node is deleted according to the conditions given in the assignment.<br>


### Prerequisites

What things you need to install the software and how to install them

```javascript
#include "AVL.hpp"
#include "Radix.hpp"
#include <fstream>
#include <sstream>

```

### Installing






