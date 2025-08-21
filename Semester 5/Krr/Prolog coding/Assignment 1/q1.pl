initial_state([t, t, 0, f, f]).
goal_state([f, f, 0, t, t]).      % Goal state to achieve

move([t, 0 | Rest], [0, t | Rest], 'Toad Slide').       % Toad Slide to the right
move([t, f, 0 | Rest], [0, f, t | Rest], 'Toad Hop').   % Toad Hop over Frog

move([f, 0 | Rest], [0, f | Rest], 'Frog Slide').       % Frog Slide to the left
move([0, t, f | Rest], [f, t, 0 | Rest], 'Frog Hop').   % Frog Hop over Toad

% Handle move in the middle of the list
move([H | T], [H | T1], Move) :-
    move(T, T1, Move).   % Recursively apply move on the remaining part of the list

solve(State, Goal, _, []) :- 
    State = Goal.  % Base case

solve(State, Goal, Visited, [MoveDesc | Moves]) :-
    move(State, NextState, MoveDesc),        % Find a valid move
    \+ member(NextState, Visited),           % Ensure this state hasn't been visited
    solve(NextState, Goal, [NextState | Visited], Moves).  % Continue solving from the new state

moves_of_toads_and_frogs :-
    initial_state(StartState),
    goal_state(GoalState),
    solve(StartState, GoalState, [StartState], Moves),
    write('Possible Set of Moves: '), nl, write(Moves), nl.
