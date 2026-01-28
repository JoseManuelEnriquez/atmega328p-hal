/** 
 * @file MACROS.h 
 * @brief Funciones Macro para trabajar con los registros I/O
 * @author Jose Manuel Enriquez Baena
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1 << BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &=~(1 << BIT))
#define READ_PIN(ADDRESS,BIT) (ADDRESS & (1 << BIT))

#endif /* MACROS_H_ */