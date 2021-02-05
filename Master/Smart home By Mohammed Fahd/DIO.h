/*
 * DIO.h
 *
 * Created: 12/5/2020 6:35:37 PM
 *  Author: DELL
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_HW.h"
#include "DIO_Types.h"
#include "STD_Types.h"
#include "BitMath.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId, STD_LevelTypes level);
STD_LevelTypes DIO_readChn(DIO_ChannelTypes ChannelId);

#endif /* DIO_H_ */