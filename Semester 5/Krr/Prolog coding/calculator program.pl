calculator :- write('Operations Supported: '),nl, write('1. addition'),nl,write('2. substraction'),nl,write('3. multiplication'),nl, write('4. division'),nl,write('5. modulo'),nl, write('6. exit'),nl,nl,write('What do you want to do?'),read(Choice),nl, write('Number 1: '),read(N1),nl,write('Number 2: '),read(N2),c(Choice,N1,N2).


c(1,N1,N2):- Add is N1+N2, nl, write(Add).
c(2,N1,N2):- Sub is N1-N2, nl, write(Sub).
c(3,N1,N2):- Mul is N1*N2, nl, write(Mul).
c(4,N1,N2):- Div is N1/N2,nl, write(Div).
c(5,N1,N2):- Mod is N1 mod N2, nl, write(Mod).
c(6,_,_):- !.
c(_,_,_):- write('Invalid Input!'),nl, calculator.