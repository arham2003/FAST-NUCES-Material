% dynamic predicates
:- dynamic vertex/1.
:- dynamic edge/2.

% Load vertices and edges from a file
load_graph(File) :-
    see(File), 
    repeat,
    (   read(Term),
        (   Term == end_of_file -> !;   
            assert(Term), fail
        )
    ),
    seen.

% BFS implementation
bfs(Start, Goal) :-
    bfs([Start], Goal, []).

bfs([Goal | _], Goal, _) :- 
    write('Found: '), write(Goal), nl.
bfs([Current | Rest], Goal, Visited) :-
    \+ member(Current, Visited), % Check if current node is already visited
    write('Exploring: '), write(Current), nl,
    findall(Next, (edge(Current, Next), \+ member(Next, Visited)), NextNodes),
    write('Next nodes to explore: '), write(NextNodes), nl,
    append(Rest, NextNodes, NewQueue),
    bfs(NewQueue, Goal, [Current | Visited]).

% DFS implementation with unique output
dfs(Start, Goal) :- 
    dfs(Start, Goal, [Start], Path),
    reverse(Path, FinalPath), 	% Reverse the path for correct order
    write('Path: '), write(FinalPath), nl,
    !. % Cut to prevent backtracking after finding the first path

dfs(Goal, Goal, Visited, Visited) :- 
    !. % Cut to avoid backtracking when goal is reached.
dfs(Current, Goal, Visited, Path) :-
    edge(Current, Next),
    \+ member(Next, Visited),
    dfs(Next, Goal, [Next | Visited], Path).

% To run the search
search_graph(SearchType, Start, Goal) :-
    SearchType = bfs -> bfs(Start, Goal);   
    SearchType = dfs -> dfs(Start, Goal);
    write('Invalid search type.'), nl.
