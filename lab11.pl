% Q1

% KNOWLEDGE BASE

male(james1).
male(charles1).
male(charles2).
male(james2).
male(george1).

female(catherine).
female(elizabeth).
female(sophia).

parent(james1, charles1).
parent(james1, elizabeth).
parent(charles1, charles2).
parent(charles1, catherine).
parent(charles1, james2).
parent(elizabeth, sophia).
parent(sophia, george1).

% M is the mother of X if she is a parent of X and is female
mother(M, X):- parent(M, X), female(M).

% F is the father of X if he is a parent of X and is male
father(F, X):- parent(F, X), male(F).

% X is a sibling of Y if they both have the same parent
sibling(X, Y):- parent(P, X), parent(P, Y), X\=Y.

% G is the grandparent of X if Y is parent of X and G is parent of Y.
grandparent(G, X):- parent(P, X), parent(G, P).



% QUERIES
% test the queries one by one :)
% (in the online compiler) semicolons are required for backtracking = to find other solutions.
% if there are no more solutions, search will return "false."

% Was George I the father of Charles I?
father(george1, charles1). 

% Who was Charles I's parent?
parent(X, charles1).

% Who is the mother of Sophia?
mother(X, sophia).

% Who were the children of Charles I?
parent(charles1, X).
;.
;.
;.

% Who were the siblings of James II? 
sibling(james2, X).
;.
;.

% Who was the grandparent of Catherine?
grandparent(X, catherine).

% Who were the grandchildren of James I?
grandparent(james1, X).
;.
;.
;.
;.



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



% Q2 - Size of a list

% Base condition for recursion.
% size(empty list, 0) returns 0 as the size of the empty list

size([],0).


% Recursive part.
% Explanation (not real syntax):
% size(list, N) :- size(list without head element, N1), N is N1 + 1

size([H|T],N) :- size(T,N1), N is N1+1.
%  or size([_|T],N) :- size(T,N1), N is N1+1.


% QUERIES 

size([1, 2, 3, 4, 5, 6],N).
size([jane, jack, bob, tim, alice],N).
size([11.6, hello, "here i am", ???, [1,2,3]],N).




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




% Q3 - Sum of the elements of a list

% Base condition for recursion.
% sumlist(empty list, 0) returns 0 as the sum of the empty list

sumlist([],0).


% Recursive part.
% Explanation (not real syntax):
% sumlist(list, N) :- sumlist(list without head element, N1), N is N1 + head element

sumlist([H|T],N) :- sumlist(T,N1), N is N1+H.


% QUERIES

sumlist([1, 4, 6, 66, 30, 77, 32],N).
sumlist([11.2, 82.3, 73.1, 44.5, 108],N).







