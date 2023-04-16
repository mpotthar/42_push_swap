# Push_Swap

"42 Push Swap" is a sorting algorithm project in C language that aims to sort a given set of integers using only two stacks and a set of predefined operations. The program must output a list of these operations that, when executed, would correctly sort the given set of integers in ascending order. The objective of the project is to minimize the number of operations needed to sort the integers. The project is part of the curriculum at 42, a coding school that promotes peer-to-peer learning and self-improvement.

## Operations
|  | **Command** | **Description** |
| --- | --- | --- |
| **Swap a** | sa | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| **Swap b** | sb | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| **Swap both stacks** | ss | sa and sb at the same time. |
| **Push a** | pa | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| **Push b** | pb | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| **Rotate a** | ra | Shift up all elements of stack a by 1. The first element becomes the last one. |
| **Rotate b** | rb | Shift up all elements of stack b by 1. The first element becomes the last one. |
| **Rotate both stacks** | rr | ra and rb at the same time. |
| **Reverse rotate a** | rra | Shift down all elements of stack a by 1. The last element becomes the first one. |
| **Reverse rotate b** | rrb | Shift down all elements of stack b by 1. The last element becomes the first one. |
| **Reverse rotate both stacks** | rrr | rra and rrb at the same time. |
