/*==============================================================================
	�v���W�F�N�g��	:	LCD�\�����C�u����
	�t�@�C����	:	lcdlib.h
	�@�\		:	���C�u������`�t�@�C��
	�C������	:	1.00	2013/08/30	�V�K�쐬 ���C���Y
	Copyright(c) 2017 emBex Education inc. All Rights Reserved.
==============================================================================*/

/* �J���[��`(RGB) */
#define CLR_WHITE	0xFFFF
#define CLR_BLACK	0x0000
#define CLR_RED		0xF800
#define CLR_GREEN	0x07E0
#define CLR_BLUE	0x001F
#define CLR_YELLOW	0xFFE0
#define CLR_MAGENTA	0xF81F
#define CLR_GREY	0xF7DE
#define CLR_CYAN	0x7FFF

/* ���߃��[�h */
#define TRANS_NONE 0x00
#define TRANS_FG 0x01
#define TRANS_BG 0x02

/* �v���g�^�C�v�錾 */
void initBase(void);
void initLCD(void);
void printString(int column, int row, char *string);
void printFstr(int column, int row, char *string, ...);
void drawString(int xpos, int ypos, char *string);
void drawFstr(int xpos, int ypos, char *string, ...);
unsigned short readPoint(int xpos, int ypos);
void drawPoint(int xpos, int ypos);
void drawLine(int x1pos, int y1pos, int x2pos, int y2pos);
void drawRect(int x1pos, int y1pos, int x2pos, int y2pos);
void drawFillRect(int x1pos, int y1pos, int x2pos, int y2pos);
void drawCircle(int xpos, int ypos, int radius);
int drawBitmap(int xpos, int ypos, int width, int height, char *bitmap);
void setLineColor(unsigned short color);
int setExtChar(int code, unsigned short extFont[]);
void setTextColor(unsigned short color);
void setBackColor(unsigned short color);
void setTransparent(char tmode);
void setFontSize(char fcolumn, char frow);
void clearLCD(void);

