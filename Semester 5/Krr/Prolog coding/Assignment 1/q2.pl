:- write('Welcome to Q2: '), nl.
route(a, b, 5).
route(b, c, 3).
route(a, d, 7).
route(d, c, 4).
route(c, e, 2).
route(e, f, 6).
route(b, e, 10).

% Direct route
path(X, Y, [X, Y], D) :- route(X, Y, D).

% Indirect route
path(X, Y, [X | Path], D) :-
    route(X, Z, D1),
    path(Z, Y, Path, D2),
    D is D1 + D2.

format_route_with_distance([X], D) :- 
    write(X), write(' : '), write(D), nl.
format_route_with_distance([X, Y | Rest], D) :-
    write(X), write(' -> '), format_route_with_distance([Y | Rest], D).

find_all_routes :-
    write('All possible routes (direct and indirect) with distances:'), nl,
    findall((Path, D), path(_, _, Path, D), AllPaths),
    display_routes_with_distances(AllPaths).

display_routes_with_distances([]).
display_routes_with_distances([(Route, D) | Rest]) :-
    format_route_with_distance(Route, D),
    display_routes_with_distances(Rest).

% 2: Multi-hop routes
multi_hop_path(X, Y, K, [X, Y], D) :- 
    K =:= 1, route(X, Y, D).
multi_hop_path(X, Y, K, [X | Path], D) :-
    K > 1,
    route(X, Z, D1),
    K1 is K - 1,
    multi_hop_path(Z, Y, K1, Path, D2),
    D is D1 + D2.

% 3: Longest route
longest_route(X, Y, LongestPath, LongestDistance) :-
    findall((Path, D), path(X, Y, Path, D), AllRoutes),
    find_longest(AllRoutes, LongestPath, LongestDistance).

find_longest([(Path, D)], Path, D).
find_longest([(Path, D) | Rest], LongestPath, LongestDistance) :-
    find_longest(Rest, P, D2),
    (D > D2 -> (LongestPath = Path, LongestDistance = D); (LongestPath = P, LongestDistance = D2)).

% 4: Routes with fixed distance
routes_with_distance(X, MaxD, Y, Path, D) :-
    path(X, Y, Path, D),
    D =< MaxD.

% 5: Multi-destination route
multi_destination_route([X, Y], [X, Y], D) :-
    route(X, Y, D).
multi_destination_route([X, Y | Rest], [X | Path], D) :-
    route(X, Y, D1),
    multi_destination_route([Y | Rest], Path, D2),
    D is D1 + D2.

% 6: Shortest paths between all points
shortest_path(X, Y, ShortestPath, D) :-
    findall((Path, D1), path(X, Y, Path, D1), Distances),
    find_shortest(Distances, ShortestPath, D).

% Find the shortest route in a list of paths
find_shortest([(Path, D)], Path, D).
find_shortest([(Path, D1) | Rest], ShortestPath, D) :-
    find_shortest(Rest, P, D2),
    (D1 < D2 -> (ShortestPath = Path, D = D1); (ShortestPath = P, D = D2)).

all_shortest_paths :-
    findall((X, Y, ShortestPath, D), (route(X, _, _), route(Y, _, _), shortest_path(X, Y, ShortestPath, D)), ShortestPaths),
    display_shortest_paths(ShortestPaths).

display_shortest_paths([]).
display_shortest_paths([(X, Y, ShortestPath, D) | Rest]) :-
    write(X), write(' -> '), write(Y), write(' : '), 
    format_route_with_distance(ShortestPath, D),
    display_shortest_paths(Rest).
