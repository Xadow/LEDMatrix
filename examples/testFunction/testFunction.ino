/*
 * Test sketch for Xadow LED 5x7 Matrix. 
 * http://www.seeedstudio.com/depot/xadow-led-p-1518.html
 * Part of the Xadow line of miature and wearable electronics.
 * http://www.seeedstudio.com/wiki/Xadow
 *
 * This sketch presents a menu when you open the Serial Console
 * for you to select and view the various modes of the 5x7 Matrix
 *
 * Check out the wiki page for more info
 * http://www.seeedstudio.com/wiki/Xadow_LED_5X7
 * 
 * Seeed Studios is an Open Hardware company. Support our contributions by buying
 * our products! http://www.seeedstudio.com/
 */

#include <Wire.h>
#include <LEDMatrix.h>

#define ADDRESS 0x04

unsigned char dta[50] = {
    0x03, 
    0b10000,
    0b01000,
    0b10000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
};

unsigned char dta2[5] = {
    0b1000000,
    0b0100000,
    0b1000000,
    0b0000000,
    0b0000001,
};

LEDMatrix fiveBySeven = LEDMatrix(ADDRESS);

void setup()
{
    Serial.begin(115200);
    while(!Serial);
    Serial.println("hello world");
    
    dispCmd();

}

void loop()
{

    while(Serial.available())
    {
        unsigned char c = Serial.read();
        Serial.write(c);
        dtaProc(c);
    }
    delay(1);
}

void dispCmd()
{
    Serial.println("***********************************");
    Serial.println("1: display matrix");
    Serial.println("2: string once");
    Serial.println("3: string loop");
    Serial.println("4: display char");
    Serial.println("5: set direction: DIR_DOWN");
    Serial.println("6: set direction: DIR_NORMAL");
    Serial.println("7: set direction: DIR_RIGHT");
    Serial.println("8: set direction: DIR_LEFT");
    Serial.println("9: display matrix: DIRRIGHT");
    Serial.println("A: set point test");
    Serial.println("S: goto sleed");
    Serial.println("W: wake up");
    Serial.println("***********************************");
}

void dtaProc(unsigned char cmd)
{
    switch(cmd)
    {
        case '1':
        Serial.println("dispoint");
        fiveBySeven.sendPoint(dta, 5);
        break;

        case '2':
        Serial.println("string once");
        fiveBySeven.sendString(STR_ONCE, 400, "hello world");   // once
        break;
        
        case '3':
        Serial.println("string loop");
        fiveBySeven.sendString(STR_LOOP, 400, "hello world");   // once
        break;
        
        case '4':
        Serial.println("disp char");
        fiveBySeven.sendChar('A');
        break;
        
        case '5':
        Serial.println("set direction: DIR DOWN");
        fiveBySeven.setDir(DIR_DOWN);
        break;
        
        case '6':
        Serial.println("set direction: DIR NORMAL");
        fiveBySeven.setDir(DIR_NORMAL);
        break;
        
        case '7':
        Serial.println("set direction: DIR RIGHT");
        fiveBySeven.setDir(DIR_RIGHT);
        break;
        
        case '8':
        Serial.println("set direction: DIR LEFT");
        fiveBySeven.setDir(DIR_LEFT);
        break;
        
        case '9':
        Serial.println("matrix - dir right");
        fiveBySeven.sendPoint(dta2, 8);
        break;
        
        case 'A':
        Serial.println("set point");
        fiveBySeven.disPoint();
        break;
        
        case 'S':
        Serial.println("goto sleep");
        fiveBySeven.gotoSleep();
        break;
        
        case 'W':
        Serial.println("wake up");
        fiveBySeven.wakeUp();
        break;
        
        default:
        ;
    }
    dispCmd();
}