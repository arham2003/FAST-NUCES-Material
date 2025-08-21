% Read routes from a file and assert them into the knowledge base
read_route :-
    seeing(S),             
    see('route2.txt'),     
    read_data,            
    write('Data read'), nl,
    seen,                  
    see(S).                

read_data :-
    read(A),               
    process(A).            

process(end).              
process(A) :-
    read(B),
    read(C),
    assertz(route(A, B, C)), 
    read_data.             

% Write the routes from the knowledge base to a file
output_data :-
    telling(T),            
    tell('route.txt'),     
    write_data,            
    told,                  
    tell(T),               
    write('Data written'), nl.

write_data :-
    route(A, B, C),       
    write(A), write('. '), 
    write(B), write('. '), 
    write(C), write('. '), 
    nl,
    fail.                 
write_data :-
    write('end.'), nl.    
