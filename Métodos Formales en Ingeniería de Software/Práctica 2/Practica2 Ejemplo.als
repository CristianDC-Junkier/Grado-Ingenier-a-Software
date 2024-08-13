module Prision

sig Banda {miembros : some Preso}

sig Preso {celda : Celda}//por defecto uno

sig Celda { }

fact Ejercicio1{
	all B: Banda | some B.miembros
	no disj B,B1: Banda | some B.miembros & B1.miembros
	asigSegura implies asigFeliz

	some c1 : Celda |  #(c1->Preso) <= 2 and #(c1->Preso) >= 1

	all b: Banda | #(b.miembros) >= 2
	all p: Preso | one b: Banda | p in b.miembros
}


pred asigSegura(){

	no B1,B2 : Banda | (B1 != B2) and some (B1.miembros.celda & B2.miembros.celda)
}

pred asigFeliz(){
	all P1,P2 : Preso | P1.celda = P2.celda implies ~miembros[P1]  = ~miembros[P2]//~ No contiene 
}

pred show(){

//#Banda = 2
//#Celda = 2
//#Preso = 4
asigFeliz
asigSegura
}

run show
