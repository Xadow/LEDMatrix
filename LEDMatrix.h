#ifndef LEDMatrix_h
#define LEDMatrix_h

#define CMD_SETMODE     0x01
#define CMD_SLEEP       0x02
#define CMD_DISPMATRIX  0x03
#define CMD_DISPCHAR    0x04
#define CMD_DISPSTR     0x05
#define CMD_DISPOINT    0x06

#define STR_ONCE        0x01
#define STR_LOOP        0x02

#define DIR_NORMAL      0x00
#define DIR_LEFT        0x01
#define DIR_RIGHT       0x02
#define DIR_DOWN        0x03

class LEDMatrix
{
public:
	LEDMatrix(int);
	void gotoSleep();
	void wakeUp();
	void sendString(unsigned char cycle, int ts, char *str);
	void setPoints(unsigned char dta[], int);
	void sendChar(char c);
	void setDir(unsigned char dir);
	void setPoint(int x, int y, int state);
};

#endif