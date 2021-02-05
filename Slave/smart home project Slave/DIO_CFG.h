/*
 * DIO_CFG.h
 *
 * Created: 12/5/2020 6:36:01 PM
 *  Author: DELL
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"
/*
#include "DIO_HW.h"
#include "STD_Types.h"
#include "DIO_Types.h"
#include "BitMath.h"   */

#define PINCOUNT 32

typedef struct {
	DIO_DirTypes PinDir;
	STD_LevelTypes level ;
	}DIO_PinCFGType;

void DIO_Init(void);

#endif /* DIO_CFG_H_ */