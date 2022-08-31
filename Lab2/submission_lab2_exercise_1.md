


# Exercise 1

Linux memory model

## Why are the addresses printed in hex rather than decimal?

A hexidecimal digit represents 4 binary digits. i.e 0x7ffef87cc6fc == 0b011111111111111011111000011111001100011011111100. It is much more human-readable to display in hex. Also, address bus sizes are usually in shifts of 8 bits which can be represented by 2 hexes.

## What is “rostr”, and the difference with “&rostr”?

```rostr``` is the pointer to the char array. Also the address stores the first element in the array.

```&rostr``` is of type **char; the address which stores the pointer to the char array.

## Which direction does the runtime stack grow?

the runtime stack 


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


## Explain which memory regions correspond to: code (text), globals, stack and heap. Note that the answer can vary depending on the program.

```
code (text), globals, stack and heap.

addr of func addr      : 0x401216
addr of func main      : 0x4012c8
addr of char array rostr : 0x402008
addr of pointer to char array rostr : 0x404078
global                 : 0x404090
initglobal             : 0x404068
local                  : 0x7ffe2e65f1c0
heap from malloc(16)   : 0x13752b0
f(arg1)                : 0x7ffe2e65f13c
f(arg6)                : 0x7ffe2e65f128
f():local              : 0x7ffe2e65f140
argv[0], which is a char array : 0x7ffe2e660711
envp[0], which is a char array : 0x7ffe2e66072b
errno                  : 0x7fe104e3b4c0
stdout                 : 0x7fe104e356a0




[CODE] 		00400000-00401000 r--p 00000000 ca:01 518602                             /home/ubuntu/repos/TIC4303/Lab2/L2-mem-region-nopie.out
[CODE] 		00401000-00402000 r-xp 00001000 ca:01 518602                             /home/ubuntu/repos/TIC4303/Lab2/L2-mem-region-nopie.out
[CODE] 		00402000-00403000 r--p 00002000 ca:01 518602                             /home/ubuntu/repos/TIC4303/Lab2/L2-mem-region-nopie.out
[CODE] 		00403000-00404000 r--p 00002000 ca:01 518602                             /home/ubuntu/repos/TIC4303/Lab2/L2-mem-region-nopie.out
[STACK] 	00404000-00405000 rw-p 00003000 ca:01 518602                             /home/ubuntu/repos/TIC4303/Lab2/L2-mem-region-nopie.out
[HEAP] 		01374000-01395000 rw-p 00000000 00:00 0                                  [heap]
[CODE] 		7fe104c48000-7fe104c6a000 r--p 00000000 ca:01 3463                       /usr/lib/x86_64-linux-gnu/libc-2.31.so
[CODE] 		7fe104c6a000-7fe104de2000 r-xp 00022000 ca:01 3463                       /usr/lib/x86_64-linux-gnu/libc-2.31.so
[CODE] 		7fe104de2000-7fe104e30000 r--p 0019a000 ca:01 3463                       /usr/lib/x86_64-linux-gnu/libc-2.31.so
[CODE] 		7fe104e30000-7fe104e34000 r--p 001e7000 ca:01 3463                       /usr/lib/x86_64-linux-gnu/libc-2.31.so
[CODE] 		7fe104e34000-7fe104e36000 rw-p 001eb000 ca:01 3463                       /usr/lib/x86_64-linux-gnu/libc-2.31.so
7fe104e36000-7fe104e3c000 rw-p 00000000 00:00 0 
[CODE] 		7fe104e43000-7fe104e44000 r--p 00000000 ca:01 3457                       /usr/lib/x86_64-linux-gnu/ld-2.31.so
[CODE] 		7fe104e44000-7fe104e67000 r-xp 00001000 ca:01 3457                       /usr/lib/x86_64-linux-gnu/ld-2.31.so
[CODE] 		7fe104e67000-7fe104e6f000 r--p 00024000 ca:01 3457                       /usr/lib/x86_64-linux-gnu/ld-2.31.so
[CODE] 		7fe104e70000-7fe104e71000 r--p 0002c000 ca:01 3457                       /usr/lib/x86_64-linux-gnu/ld-2.31.so
[CODE] 		7fe104e71000-7fe104e72000 rw-p 0002d000 ca:01 3457                       /usr/lib/x86_64-linux-gnu/ld-2.31.so
[CODE] 		7fe104e72000-7fe104e73000 rw-p 00000000 00:00 0 
[STACK] 	7ffe2e640000-7ffe2e661000 rw-p 00000000 00:00 0                          [stack]
7ffe2e798000-7ffe2e79c000 r--p 00000000 00:00 0                          [vvar]
[CODE] 		7ffe2e79c000-7ffe2e79e000 r-xp 00000000 00:00 0                          [vdso]
[GLOBAL] 	ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]


Memory Map from /proc/25528/maps
```

## Each region has permissions (rwx, can ignore p) – what is the rationale for a region having a particular set of permissions.

w : writable if variable is mutable
x : executable code
r : access allowed

## Some regions are associated with files and some are not? Can you explain the distinction?

These are usually created by mmap but are not attached to any file. They are used for a lot of miscellaneous things like shared memory or buffers not allocated on the heap. For instance, I think the pthread library uses anonymous mapped regions as stacks for new threads.

see [https://stackoverflow.com/questions/1401359/understanding-linux-proc-pid-maps-or-proc-self-maps](https://stackoverflow.com/questions/1401359/understanding-linux-proc-pid-maps-or-proc-self-maps)

# some other notes

- heap and stack addresses start from different address space





