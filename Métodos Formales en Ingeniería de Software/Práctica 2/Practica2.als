module Practica2

//Clases
sig Proveedor{tienda : one Nave, vehiculo : some Vehiculo}
//Abstracta
abstract sig Vehiculo{TipoProductoTrasporta : one Producto}
//Subclases - Enumerado
sig Camion extends Vehiculo{}
sig Furgoneta extends Vehiculo{}
sig Turismo extends Vehiculo{}
//------
//Abstracta
abstract sig NivelCalidad{}
//Subclase - Enumerado
sig Excelente extends NivelCalidad{}
sig Buena extends NivelCalidad{}
sig Normal extends NivelCalidad{}
sig Mala extends NivelCalidad{}
sig MuyMala extends NivelCalidad{}
//------
sig Nave{CalidadTotal : one NivelCalidad ,productos : set Producto}
//Abstracta
abstract sig Producto{Calidad : one NivelCalidad}
//Subclase - Enumerado
sig Pescado extends Producto{}
sig Carne extends Producto{}
sig Fruta extends Producto{}
sig Hortalizas extends Producto{}
//------
sig LineadeCompra{Conjunto : some Compra, producto : one Producto}
sig Compra{}
//Abstracta
abstract sig Comprador{compra : some Compra}
//Subclases - Enumerados
sig Mayorista extends Comprador{}
sig Minorista extends Comprador{}
sig Restaurador extends Comprador{}

//Restricciones de Diseño
fact{
	all v: Vehiculo | v in Camion + Furgoneta + Turismo
	all p: Producto | p in Pescado + Carne + Fruta + Hortalizas
	all n: NivelCalidad | n in MuyMala + Mala + Normal + Buena + Excelente
}

fact{ //Nave
	all disj n1: Nave | //Todos los productos de una nave deben ser de un tipo
		#(n1.productos) > 0 implies
			n1.productos in Pescado or 	n1.productos in Carne or n1.productos in Fruta or n1.productos in Hortalizas

	all disj n1,n2: Nave | //los productos de una nave no estan en otra
		n1.productos not in n2.productos 

}

fact{//Producto
	all disj p1: Producto | //Un producto esta en una nave, o en un vehiculo o en los dos
		(some v1: Vehiculo | p1 in v1.TipoProductoTrasporta) or (some n1: Nave | p1 in n1.productos) or
		((some v1: Vehiculo | p1 in v1.TipoProductoTrasporta) and (some n1: Nave | p1 in n1.productos))
}

fact{//Linea de Compra

	all disj c1,c2: LineadeCompra| //Todos los productos de todas las lineas de compra deben ser del mismo tipo si es de tipo mayorista el comprador
		(one mayo: Mayorista |  mayo.compra = c1.Conjunto + c2.Conjunto) implies
		((c1.producto in Pescado and c2.producto in Pescado) or 
		(c1.producto in Carne and c2.producto in Carne) or (c1.producto in Fruta and c2.producto in Fruta) 
		or (c1.producto in Hortalizas and c2.producto in Hortalizas))

	all disj c1,c2: LineadeCompra | //Cada linea de compra si es de una misma compra no puede tener el mismo producto
		c1.Conjunto = c2.Conjunto implies c1.producto not in c2.producto

	all c1: LineadeCompra |//Cada linea de compra esta en una unica compra (Composicion)
		#c1.Conjunto = 1
	
	all c1: LineadeCompra |//Cada producto de una linea de compra debe estar en una nave
		(some n1 : Nave | c1.producto in n1.productos)

}

fact{//Comprador
	all disj comp1,comp2: Comprador | //Cada compra solo es de un comprador
		comp1.compra not in comp2.compra
	all comp1 : Comprador |	//Cada comprador que haga más de 5 compras será Mayorista.
		#(comp1.compra) > 5 implies
		comp1 in Mayorista
}

fact{//Compra
	all c1 : Compra | //Cada compra pertenece a una linea de compra
		(some lc: LineadeCompra | c1 in lc.Conjunto) 
	all c1: Compra |//Cada compra debe tener solo un unico comprador
		(one co1: Comprador | c1 in co1.compra)

}

fact{//Vehiculo
	all v1: Vehiculo |//Cada vehiculo tiene solo un unico proveedor
		(one p1: Proveedor | v1 in p1.vehiculo)
}

fact{//Proveedor
	all p1: Proveedor |//Cada vehiculos de proveedor transportan un unico tipo de producto
		p1.vehiculo.TipoProductoTrasporta in Pescado or p1.vehiculo.TipoProductoTrasporta in Carne 
		or p1.vehiculo.TipoProductoTrasporta in Fruta or p1.vehiculo.TipoProductoTrasporta in Hortalizas
	all p1: Proveedor | //Cada Proveedor tiene minimo un Camión
		(one cam: Camion | cam in p1.vehiculo)
}

//Predicados
pred show(){}

pred EliminarProductoMalo(n,n': Nave , p : Producto ){
	p in n.productos and (p.Calidad in MuyMala or p.Calidad in Mala) implies
	n'.productos = n.productos  - p
}

pred AnadirProductoNuevo(n,n': Nave, v : Vehiculo){
	v.TipoProductoTrasporta not in n.productos and (some nx : Nave | v.TipoProductoTrasporta not in nx.productos) implies
	n'.productos = n.productos + v.TipoProductoTrasporta
}

pred LineadeCompraProductoBueno(){
	all ln: LineadeCompra | 
		ln.producto.Calidad in Buena or ln.producto.Calidad in Normal or ln.producto.Calidad in Excelente
}

//Assert-Cheks
/*check MayoristaCompraDosCosasDiferentes{//Un Mayorista tiene una compra de un tipo de producto y otra de otro tipo.
		all disj c1,c2: LineadeCompra| 
		(one mayo: Mayorista |  mayo.compra = c1.Conjunto + c2.Conjunto) implies
		((c1.producto in Pescado and c2.producto not in Pescado) or (c1.producto in Carne and c2.producto not in Carne) 
		or (c1.producto in Hortalizas and c2.producto not in Hortalizas) or (c1.producto in Fruta and c2.producto not in Fruta))
}*/

/*check{//Existe un producto que no esta en una nave ni en un coche
	all disj v: Vehiculo, n: Nave |
		(one  p: Producto | p not in v.TipoProductoTrasporta and p not in n.productos)
}*/

/*check VehiculosDobles{//Un vehiculo pertenece a más de 1 persona
	all disj v1 : Vehiculo, p1,p2 : Proveedor| 
	v1 in p1.vehiculo and v1 in p2.vehiculo }
*/



//run EliminarProductoMalo for exactly 1 Proveedor, exactly 1 Vehiculo, exactly 1 NivelCalidad,exactly 1 Nave,exactly 1 Producto,exactly 1 LineadeCompra,exactly 1 Compra,exactly 1 Comprador
//run AnadirProductoNuevo for exactly 1 Proveedor, exactly 1 Vehiculo, exactly 1 NivelCalidad,exactly 1 Nave,exactly 1 Producto,exactly 1 LineadeCompra,exactly 1 Compra,exactly 1 Comprador
//run LineadeCompraProductoBueno for exactly 1 Proveedor, exactly 1 Vehiculo, exactly 1 NivelCalidad,exactly 1 Nave,exactly 1 Producto,exactly 1 LineadeCompra,exactly 1 Compra,exactly 1 Comprador

run show
//run show for exactly 1 Proveedor, exactly 1 Vehiculo, exactly 1 NivelCalidad,exactly 1 Nave,exactly 1 Producto,exactly 1 LineadeCompra,exactly 1 Compra,exactly 1 Comprador



