Project finished (125%).

Sort a non-repeating stack of integers the most efficiently possible.

To get 100%, we need to sort 100 numbers in 700 moves MAX, and 500 numbers in 5500 moves MAX.


Algorithm is a remix of quicksort:

  -> find the median of stack A (number that has as many > than <= elements in the stack)
  
  -> push all numbers <= to the median onto stack b.
  
  -> find the median of stack B (number that has as many < than >= elements in the stack)
  
  -> push all numbers <= to the median onto stack b.
  
  -> repeat.


[!] Does not pass NORMINETTE because i am trying to make it more efficient.

CURRENT AVERAGE:

- 100 NUMBERS: 626 moves

- 500 NUMBERS: ~4800 moves
