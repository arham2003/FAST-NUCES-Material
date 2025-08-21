age:-
    write('How old are you?'), nl,
    read(Age), nl,
    write('You are '), write(Age), write(' years old.').

cube:-
    write('Write a number '), nl,
    read(N), nl,
    Res is N*N*N,
    write('Cube of the '), write(N), write(' is '), write(Res).

square:-
    write('Write a number '), nl,
    read(N), nl,
    Res is N*N,
    write('Square of the '), write(N), write(' is '), write(Res).

cube1:-
    write('Next item, please: '),
    read(X),
    process(X).
process(stop):- !.
process(N):-
    C is N*N*N,
    write('Cube of '), write('N '),write(' is : '),
    write(C),nl,
    cube1.
