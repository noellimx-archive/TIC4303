


# Exercise 1

Linux memory model

## Why are the addresses printed in hex rather than decimal?

A hexidecimal digit represents 4 binary digits. i.e 0x7ffef87cc6fc == 0b011111111111111011111000011111001100011011111100. It is much more human-readable to display in hex. Also, address bus sizes are usually in shifts of 8 bits which can be represented by 2 hexes.

## What is “rostr”, and the difference with “&rostr”?

```rostr``` is the pointer to the char array. Also the address stores the first element in the array.

```&rostr``` is of type **char; the address which stores the pointer to the char array.

## Which direction does the runtime stack grow?

the runtime stack 


# some other notes

- heap and stack addresses start from different address space






DECREASING STACK ADDRESS (HIGH ABOVE LOW BELOW)

***callee stack***

[local_variable]
[arg1]
[arg2]
[arg3]
[arg4]
[arg5]
[arg6]


***caller stack***

[local_variable]
[arg1]
[arg2]
[arg3]

