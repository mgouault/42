etape([X, X, Chevre, Chou], loup(X), [Y, Y, Chevre, Chou]).
etape([X, Loup, X, Chou], chevre(X), [Y, Loup, Y, Chou]).
etape([X, Loup, Chevre, X], chou(X), [Y, Loup, Chevre, Y]).
etape([X, Loup, Chevre, Chou], seul(X), [Y, Loup, Chevre, Chou]).

egal(X,X).

survis([Peon, Loup, Chevre, Chou]) :-
	egal(Peon, Chevre);
	(egal(Peon, Loup), egal(Peon, Chou)).

but([<=, <=, <=, <=], []).
but(Precedent, [H|T]) :-
	etape(Precedent, H, Nouveau),
	survis(Nouveau),
	but(Nouveau, T).

afficher([]).
afficher([H|T]) :- write(H), nl, afficher(T).

resoudre :- length(X, 7), but([=>, =>, =>, =>], X), afficher(X).
