mari_de(marc, anne).
mari_de(luc, betty).
mari_de(jules, lisa).
mari_de(leon, sylvie).
mari_de(loic, eve).
mari_de(paul, julie).

femme_de(A, B) :- mari_de(B, A).

homme(jean).
homme(jacques).
homme(herve).
homme(gerard).
homme(A) :- mari_de(A, _).

femme(valerie).
femme(A) :- femme_de(A, _).

couple(A, B) :- mari_de(A, B); femme_de(A, B).

enfant_de(jean, marc).
enfant_de(jules, marc).
enfant_de(leon, marc).
enfant_de(lisa, luc).
enfant_de(loic, luc).
enfant_de(gerard, luc).
enfant_de(jacques, jules).
enfant_de(herve, leon).
enfant_de(julie, leon).
enfant_de(paul, loic).
enfant_de(valerie, loic).
enfant_de(A, B) :- femme_de(B, C), enfant_de(A, C).

beaupere_de(A, B) :- enfant_de(C, A), couple(B, C), homme(A).

bellemere_de(A, B) :- enfant_de(C, A), couple(B, C), femme(A).

ancetre_de(A, B) :- enfant_de(B, A).
ancetre_de(A, C) :- enfant_de(C, B), ancetre_de(A, B).
