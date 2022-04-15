#ifndef HEADER_H_
#define HEADER_H_



/// @fn int menu(float, float, float)
/// @brief muestra un menú en pantalla y permite al usuario elegir una opción
///
/// @param kilometros (sirve de bandera)
/// @param precioAerolineas (sirve de bandera)
/// @param precioLatam (sirve de bandera)
/// @return eleccion
int menu(float, float, float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn int subMenu(float, float)
/// @brief muestra un menú en pantalla y permite al usuario elegir una opción
///
/// @param precioAerolineas (sirve de bandera)
/// @param precioLatam (sirve de bandera)
/// @return eleccion
int subMenu(float, float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn void imprimirResultados(float, float, float, float, float, float, float, float, float , float , float , float)
/// @brief imprime en pantalla los resultados de las cuentas realizadas
///
/// @param kilometros
/// @param precioAerolineas
/// @param precioDebitoAerolineas
/// @param precioCreditoAerolineas
/// @param precioBitcoinAerolineas
/// @param precioUnitarioAerolineas
/// @param precioLatam
/// @param precioDebitoLatam
/// @param precioCreditoLatam
/// @param precioBitcoinLatam
/// @param precioUnitarioLatam
/// @param diferencia
void imprimirResultados(float, float, float, float, float, float, float, float, float , float , float , float);
//--------------------------------------------------------------------------------------------------------------------

/// @brief imprime en pantalla un mensaje que pide al usuario ingresar un número.
/// Verifica que el numero ingresado sea mayor a 0
///
/// @param mensaje
/// @return numero
float validacionNumeroPositivo(char[]);
//--------------------------------------------------------------------------------------------------------------------

/// @brief verifica que si numero ingresado tiene decimales. Si no los tiene, los imprime sin los ceros.
///
/// @param numero
void imprimirDecimales(float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn float precioDebito(float)
/// @brief averigua el precio a pagar con débito (10% de descuento)
///
/// @param precio
/// @return precio con descuento
float precioDebito(float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn float precioCredito(float)
/// @brief averigua el precio a pagar con crédito (25% de recargo)
///
/// @param precio
/// @return precio con recargo
float precioCredito(float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn float precioBitcoin(float)
/// @brief averigua el precio a pagar con bitcoins
///
/// @param precio en pesos
/// @return precio en bitcoins
float precioBitcoin(float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn float precioUnitario(float, int)
/// @brief averigua el precio a pagar por kilometro viajado
///
/// @param precio
/// @param kilometros
/// @return resultado
float precioUnitario(float, float);
//--------------------------------------------------------------------------------------------------------------------

/// @fn float diferenciaDePrecios(float, float)
/// @brief averigua la diferencia entre los dos precios ingresados
///
/// @param precio 1
/// @param precio 2
/// @return diferencia entre precios
float diferenciaDePrecios(float, float);
//--------------------------------------------------------------------------------------------------------------------

#endif /* HEADER_H_ */
