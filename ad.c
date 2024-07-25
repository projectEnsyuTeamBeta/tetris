/*=======================================================================
	�v���W�F�N�g��	�F	RX63N-eMoBee �g���݃v���O���~���O���K�T
	�t�@�C����		�F	ad.c
	�@�\			�F	A/D�ϊ��@�����������y�ђl�擾
	�C������		�F	1.00	2013/08/30�@���C���Y	�V�K�쐬
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
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;	/* S12AD ���W���[���X�g�b�v��ԉ��� */
	S12AD.ADCSR.BIT.ADST = 0;		/* P1772  AD�ϊ���~ */
	S12AD.ADCSR.BIT.ADIE = 0;		/* P1772  �����݂Ȃ� */
	S12AD.ADCSR.BIT.ADCS = 1;		/* P1772  1:�A���X�L�������[�h */
	S12AD.ADANS0.BIT.ANS0 = 3;		/* P1778  P40 P41 = bit 0,1 */
	S12AD.ADCSR.BIT.ADST = 1;		/* P1772 AD�ϊ��J�n */
}

/*
 * �y�Q�l�ziodefine.h �ɂ���
 *  "MSTP(S12AD)" �� "MSTP_S12AD" �ƓW�J����A�����
 *  "SYSTEM.MSTPCRA.BIT.MSTPA17" �ƓW�J�����̂ŁA
 *	MSTP(S12AD) = 0;
 *  �Ə������Ƃ��ł��܂��B
 */
