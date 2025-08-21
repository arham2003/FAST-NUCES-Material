read_from_file:-
    open('info.txt', read, Stream),
    read(Stream, Data),
    write(Data), nl,
    close(Stream).


write_to_file:-
    open('output3.txt', write, Stream),
    write(Stream, 'Hello world'),
    nl(Stream),
    writeln(Stream, 'Prolog filing'),
    close(Stream).
