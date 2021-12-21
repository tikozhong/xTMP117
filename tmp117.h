/**********************************************************
filename: tmp117.h
**********************************************************/
#ifndef _TMP117_H_
#define _TMP117_H_

#include "misc.h"
#include "IIC_IO.h"

/*****************************************************************************
 @ typedefs
****************************************************************************/
typedef struct{
	char name[DEV_NAME_LEN];
	/* config	*/
	IIC_IO_Dev_T DevIIC;
	IIC_IO_Dev_T *pIIC;
	u8 slvWrtAddr;	//slave write addr
	u16 tick;
	u16 tmr;
	s32 tempSerial[2];
	void (*cbNewData)(char* name, s32 temp_in_micro);	//in 10e-3 DegreeC
}TMP117_Rsrc_T;

typedef struct{
	TMP117_Rsrc_T rsrc;
	//basic
	void (*polling)(TMP117_Rsrc_T* pRsrc, u8 tick);
	s32 (*temperature)(TMP117_Rsrc_T* pRsrc);	//in 10e-3 DegreeC
	u16 (*getID)(TMP117_Rsrc_T* pRsrc);
	u16 (*regRead)(TMP117_Rsrc_T* pRsrc, u8 addr);
	s8 (*regWrite)(TMP117_Rsrc_T* pRsrc, u8 addr, u16 val);
	s8 (*offset)(TMP117_Rsrc_T* pRsrc, s16 offset);
	s16 (*offget)(TMP117_Rsrc_T* pRsrc);
}TMP117_Dev_T;

void TMP117_Setup(
	TMP117_Dev_T *pDev, 
	const PIN_T SCL, 
	const PIN_T SDA, 
	const u8 cfgAddr,	//A0, 0..3
	const char* NAME
);
	
void TMP117_Setup1(
	TMP117_Dev_T *pDev,
	IIC_IO_Dev_T *pIIC,
	const u8 cfgAddr,	//A0, 0..3
	const char* NAME
);

#endif
