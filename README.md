**The project:**

You have two stacks, one with a set of numbers, stack A, and an empty stack B which you can use during your program. By the end of the program you must have one sorted list of numbers in stack A and an empty stack B. Your program needs to be deemed sufficiently optimal to pass the project! You can use a limited set of operations to move numbers around, these are: PA, PB (push number from top of one stack to either A or B depending on the second letter of the command), RA, RB, RR (rotate top number of the stack to the bottom, either for stack A (RA), stack B (RB) or both (RR)), SA, SB, SS (swap top two number of the stack, either for stack A (SA), stack B (SB) or both (SS)) and RRA, RRB, RRR (rotate bottom number of the stack to the top, either for stack A (RRA), stack B (RRB) or both (RRR)).
The executable ./push_swap takes a list of numbers and returns a list of commands which will sort the list.
The executable ./checker takes a list of numbers and a list of commands and confirms if the list of commands results in a sorted list.

**My program:**

I work with linked lists throughout on this project because I haven’t really had the chance to work with them in detail before so I thought this would be a good opportunity to get comfortable with them. Integer arrays another alternative which might be a bit simpler when it comes to tracking the location of certain numbers via indexing.

**My sorting algorithm:**

1) I start by splitting my list of numbers in stack A into “chunks”. I ran some tests to decipher how many chunks were optimal for certain dataset sizes.
2) Like in the quicksort algorithm, I then take a “pivot” number for this chunk and push everything above it from stack A into stack B (calculating the fastest route, i.e. is it nearer the bottom or top of list). The “pivot” number is not a random number but the median of this set of numbers. After that, I push everything above the pivot to stack B too, but this already helps to start the sorting process already!
3) I continue doing this until there are no numbers left in stack A and we have set of numbers in stack B which is not entirely sorted, but is beginning to be more in order in stack B. This is much more optimal for the use of insertion sort, which performs well with near-sorted lists.
4) I find the highest number in stack B, get it back to stack A in the fastest way possible and then repeat the process until stack B is empty and stack A has one sorted list of numbers.

**Ideas to improve results further:**

The chunks are moved from stack A to B in ascending order of numerical value. This means the last chunk is guaranteed to contain numbers with a higher value than previous numbers, so I could simply sort them in stack A, rather than moving them across to stack B and then back to A and then add the values in stack A on top of them. If I have time, I will test the results with this optimisation.
