% knight's jump
jump(X/Y, X1/Y1) :- 
    (   DX is 2, DY is 1; DX is 1, DY is 2;
        DX is -2, DY is 1; DX is -1, DY is 2;
        DX is 2, DY is -1; DX is 1, DY is -2;
        DX is -2, DY is -1; DX is -1, DY is -2
    ),
    X1 is X + DX,
    Y1 is Y + DY,
    between(1, 8, X1),
    between(1, 8, Y1).

% knightpath/1
knightpath([Start, End]) :- 
    jump(Start, End).

knightpath([Start, Next | Rest]) :-
    jump(Start, Next),
    knightpath([Next | Rest]).

% Find a knight's path of length 4 that goes through specific squares
find_knight_path(Path) :-
    write('Possible Paths: '), nl,
    length(Path, 5),
    Path = [2/1, _, 4/5, _, End],
    End = _/8,
    knightpath(Path).

% To see all possible jumps from a square
find_jumps(Square) :-
    findall(NewSquare, jump(Square, NewSquare), Jumps),
    write('Possible jumps from '), write(Square), write(': '), write(Jumps), nl.
