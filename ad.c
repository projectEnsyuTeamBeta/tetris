/*=======================================================================
	プロジェクト名	：	RX63N-eMoBee 組込みプログラミング演習５
	ファイル名		：	ad.c
	機能			：	A/D変換機初期化処理及び値取得
	修正履歴		：	1.00	2013/08/30　研修太郎	新規作成
	Copyright(c) 2017 emBex Education inc. All Rights Reserved.
=======================================================================*/

#include "iodefine.h"

/* 96000000(ICLK:96MHz) / 1000(0.001sec) / 4(cycle:SUB+BNE) == 24000 */
#define WAIT_LOOP_FOR_1MSEC	24000


void waitTimeMS(int mSec)
{
	int loopCount1, loopCount2;
	
	for (loopCount1 = 0; loopCount1 < mSec; loopCount1++) {
		for (loopCount2 = 0; loopCount2 < WAIT_LOOP_FOR_1MSEC; loopCount2++) {
			;
		}
	}
}


int getVR1(void)
{
	return S12AD.ADDR0 >> 2;
}

int getVR2(void)
{
	
}


void initAD(void)
{
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;	/* S12AD モジュールストップ状態解除 */
	S12AD.ADCSR.BIT.ADST = 0;		/* P1772  AD変換停止 */
	S12AD.ADCSR.BIT.ADIE = 0;		/* P1772  割込みなし */
	S12AD.ADCSR.BIT.ADCS = 1;		/* P1772  1:連続スキャンモード */
	S12AD.ADANS0.BIT.ANS0 = 3;		/* P1778  P40 P41 = bit 0,1 */
	S12AD.ADCSR.BIT.ADST = 1;		/* P1772 AD変換開始 */
}

/*
 * 【参考】iodefine.h によれば
 *  "MSTP(S12AD)" は "MSTP_S12AD" と展開され、さらに
 *  "SYSTEM.MSTPCRA.BIT.MSTPA17" と展開されるので、
 *	MSTP(S12AD) = 0;
 *  と書くことができます。
 */
