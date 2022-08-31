


# Lab 2 Exercise 2 - Segmentation Fault in Linux


## Question for each part

a. What is the behavior?
b. Is there a memory error? If there is a memory error, explain the rationale for the memory error.
If there is no memory error, explain why it isn’t a memory error. You should also explain the
reason for the result and what happened. Your explanation should be clear, refer to the code
and justify the behavior observed.


### 1
#### a

Segmentation fault (core dumped)

#### b

case 1 has an instruction ```p = 0;``` which reassigns p to 0. We can add ```printf(""``` at the start of 