# USER MANUAL

## Use of input.txt

Input.txt must store the data for 3 graphs:  
- Graph 1 from the exam  
- Graph 1.7 from Question 5 from the exam  
- Graph 2 from the exam  

The format for this data is as follows:  

                <number of nodes on Graph 1 := n\\>

                <id of node 1\\> <adj1 of node 1\\> <adj2 of node 1\\> ...

                <id of node 2\\> <adj1 of node 2\\> <adj2 of node 2\\> ...

                ...

                <id of node n\\> <adj1 of node n\\> <adj2 of node n\\> ...

                <number of nodes on Graph 1.7 := m\\>

                <id of node 1\> <adj1 of node 1\> <adj2 of node 1\> ...

                <id of node 2\> <adj1 of node 2\> <adj2 of node 2\> ...

                ...

                <id of node m\> <adj1 of node m\> <adj2 of node m\> ...

                <number of nodes on Graph 2 := x\>

                <id of node 1\> <adj1 of node 1\> <adj2 of node 1\> ...

                <id of node 2\> <adj1 of node 2\> <adj2 of node 2\> ...

                ...

                <id of node x\> <adj1 of node x\> <adj2 of node x\> ...


**Special Cases:**  
- If a node does not have adjacencies, then that line only has its id. e.g., if node 3 on a graph does not have adjacencies, then its line will look like:  
  `3`

- If the student did not construct one or more of the required graphs, store it as a generic graph with 1 node and no edges:

        1

        1

---

## Use of application `e`

The program is meant to be run on **Ubuntu** (or a similar Linux distro) and must be run from the command line using the following syntax:  

        ./e <index basis\> <start node for Question 1 in the exam\> <start node for Question 8 in the exam\>


Where:  
- *index_basis*: this is either `0` or `1`, and indicates the starting point for the node enumeration used by the student for their graphs.  
- The other two parameters are self-explanatory.  

> ⚠️ **WARNING:** There is an exam-key in which all graphs except Graph 2 use 1-indexation, so even if Question 8 on this key says `0` for the start node, use `1` when running the program.

---

## Use of application `n`

`n` is a program meant to be run on **Ubuntu** (or a similar Linux distro) and must be run from the command line using the following syntax:  

        ./n <grade out of 80\>


The idea is that the exam has **8 questions**, and each question must be graded from **1 to 10**, so the total obtained is a **grade out of 80 maximum points**. This program converts this result to a **normal grade from 1 to 10** for the exam and the student.
