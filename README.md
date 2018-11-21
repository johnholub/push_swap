# push_swap

Sorting algorithm between 2 stacks.  

**Main goal is 2 programs:**  
**./push_swap** - return commands for sorting the stack "a"  
	if number of digits == **3** - no more then **2-3** operations  
	if number of digits <= **5** - no more then **8** operations  
	if number of digits > 5 and number == **100** - no more then **700** operations  
	if number of digits > 5 and number == **500** - no more then **5300** operations  
**./checker** - using commands make manipulations with stacks "a" and show the result **OK**/**KO**

###How to run?
```
make
```
```
A="2 3 1"; ./push_swap $A | ./cheker $A
```
###push_swap
```
./push_swap 2 3 1
```

commands for checker:  
**sa**   swap a - swap the first 2 elements at the top of stack a  
**sb**   swap b - swap the first 2 elements at the top of stack b  
**ss**   sa and sb at the same time  
**pa**   push a - take the first element at the top of b and put it at the top of a  
**pb**   push b - take the first element at the top of a and put it at the top of b  
**ra**   rotate a - shift up all elements of stack a by 1  
**rb**   rotate b - shift up all elements of stack b by 1  
**rr**   ra and rb at the same time  
**rra**  reverse rotate a - shift down all elements of stack a by 1  
**rrb**  reverse rotate b - shift down all elements of stack b by 1  
**rrr**  rra and rrb at the same time  
