# Chess AI
## version 1 for now


## Introduction
A chess engine can be written in a couple of ways, you can
write a neural network that will learn from the games played
chess games that are entire databases available in
internet or it can self-learn like eg AlphaGo engine
chess game created by "google". I reject this option by
complexity. You can also write engine
chess, using the database of games played i
algorithms optimizers how e.g. StockFish.
I will use this method, but I will cut it slightly.
My chess engine will check the individual ones
combinations possible on the board and then them
optimized with the "minmax" algorithm. The problem is that
approach is a huge number of all possible combinations
value of 10 120. For the motor to run faster, you should limit w
"Minmax" the number of branches checked to achieve this
I will use an alpha-beta pruning algorithm that allows
omit some branches in the minmax. You should also
we can notice that, starting from two different points, we can
achieve the same state on the board so as not to check it
state itself, I will use the transposition table (map) a few times,
which will include the items already examined.
He will use Zobrist to distinguish a proven combination 


## Comment
To make a chess engine based on the minmax algorithm
to be effective he must search as deep as possible
movement. In my engine, the usable depth is only 4,
It can be increased with a few modifications:
To increase the alpha-beta impact of pruning you would need
the most promising moves to search first, you can this
get by searching first the traffic in which
there is an alpha-beta bundling at best
pruning thus increases the depth at the expense
twice.
Global memory allocation, in the search process
position followed by a lot of memory allocations which is very much
"Free" can be implemented to optimize it
"Mempool" functions that allow you to allocate a large area
memory, by searching, and then sharing the data
remember if necessary.
You don't have to calculate new possible every time
movements of the figure, it can be limited. 
