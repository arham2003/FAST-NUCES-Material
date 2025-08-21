%president/1
president(washington).
president(lincoln).
president(kennedy).
president(obama).

president(X) :- member(X, [adams,jefferson, fdr]).


%score.2 - not a good rule
score(dbacks, 4).
score(dodgers, 2).
score(patriots, 34).
score(falcons, 28).
won_bad(X) :- score(X, ScoreX), score(_Y, ScoreY), ScoreX > ScoreY.

%better rule

game(dbacks, 4, dodgers, 2).
game(falcons, 28, patriots, 34).
won(X) :- game(X, ScoreX, _Y, ScoreY), ScoreX > ScoreY.
won(Y) :- game(_X, ScoreX, Y, ScoreY), ScoreY > ScoreX.


%math

double(X, Y) :- Y is X*2.
less_than_square_root(X, Y) :- Y < sqrt(X).
tangent(X, Y) :- Y is tan(X).
divides(X , Y) :- 0 is X mod Y.

%third_element_in_list/2 - find third element in a list.
third_element_in_list([_,_,A | _T], A).


%first_two/3
first_two([H1, H2 | _T], H1, H2).

%first_two/2

first_two([H1, H2 | _T], [H1, H2]).


%recursion
factorial(1,1). %base case 1 != 1
factorial(N, F) :- 











