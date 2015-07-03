maisons([
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _),
maison(_, _, _, _, _)
]).

afficher([]).
afficher([A|B]) :-  write(A), nl, afficher(B).

avec(A, [A|_]).
avec(A, [_|B]) :- avec(A, B).

gauche(A, B, [A, B|_]).
gauche(A, B, [_|C]) :- gauche(A, B, C).

voisin(A, B, [A, B|_]).
voisin(A, B, [B, A|_]).
voisin(A, B, [_|C]) :- voisin(A, B, C).

resoudre :-
maisons(MAISONS),
avec(maison(rouge, anglais, _, _, _), MAISONS),
avec(maison(_, suedois, _, _, chiens), MAISONS),
avec(maison(_, danois, the, _, _), MAISONS),
gauche(maison(verte, _, _, _, _), maison(blanche, _, _, _, _), MAISONS),
avec(maison(verte, _, cafe, _, _), MAISONS),
avec(maison(_, _, _, pall_mall, oiseaux), MAISONS),
avec(maison(jaune, _, _, dunhill, _), MAISONS),
MAISONS = [_, _, maison(_, _, lait, _, _), _, _],
MAISONS = [maison(_, norvegien, _, _, _), _, _, _, _],
voisin(maison(_, _, _, blend, _), maison(_, _, _, _, chats), MAISONS),
voisin(maison(_, _, _, _, cheval), maison(_, _, _, dunhill, _), MAISONS),
avec(maison(_, _, biere, bluemaster, _), MAISONS),
avec(maison(_, allemand, _, prince, _), MAISONS),
voisin(maison(_, norvegien, _, _, _), maison(bleue, _, _, _, _), MAISONS),
voisin(maison(_, _, _, blend, _), maison(_, _, eau, _, _), MAISONS),
avec(maison(_, _, _, _, poisson), MAISONS),
afficher(MAISONS).
