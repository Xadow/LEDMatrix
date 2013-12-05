#include "Arduino.h"
#include "Wire.h"   

#include "LEDMatrix.h"

int _ADDRESS;


LEDMatrix::LEDMatrix(int address)
{
    _ADDRESS = address;
    Wire.begin();
}

void LEDMatrix::gotoSleep()
{
    Wire.beginTransmission(_ADDRESS);
    Wire.write(CMD_SLEEP);
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::wakeUp()
{
    Wire.beginTransmission(_ADDRESS);
    Wire.write(0x55);
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::sendString(unsigned char cycle, int ts, char *str)
{
    int lend = strlen(str);
    
    Wire.beginTransmission(_ADDRESS);
    
    Wire.write(CMD_DISPSTR);
    
    Wire.write(cycle);
    Wire.write(ts>>8);
    Wire.write(ts);
    Wire.write(lend);
    for(int i=0; i<lend; i++)
    Wire.write(str[i]);        // sends five bytes
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::setPoints(unsigned char data[], int len)
{
    Wire.beginTransmission(_ADDRESS);
    
    Wire.write(CMD_DISPMATRIX);

    for(int i=0; i<len; i++)
    Wire.write(data[i]);        // sends five bytes
    
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::sendChar(char c)
{
    Wire.beginTransmission(_ADDRESS);
    
    Wire.write(CMD_DISPCHAR);
    Wire.write(c);        // sends five bytes
    
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::setDir(unsigned char dir)
{

    Wire.beginTransmission(_ADDRESS);

    Wire.write(CMD_SETMODE);
    Wire.write(dir);
    
    Wire.endTransmission();    // stop transmitting
}

void LEDMatrix::setPoint(int x, int y, int state)
{
    Wire.beginTransmission(_ADDRESS);

    Wire.write(CMD_DISPOINT);
    Wire.write(x);
    Wire.write(y);
    Wire.write(state);
    Wire.endTransmission();    // stop transmitting
}