/*=======================================================================
	プロジェクト名	：	RX63N-eMoBee 組込みプログラミング演習５
	ファイル名		：	ad.h
	機能			：	A/D変換関連プロトタイプ宣言
	修正履歴		：	1.00	2013/08/30　研修太郎	新規作成
	Copyright(c) 2017 emBex Education inc. All Rights Reserved.
=======================================================================*/

#ifndef AD_H
#define AD_H

void waitTimeMS(int mSec);
int getVR1(void);
int getVR2(void);
void initAD(void);

#endif /* AD_H */
