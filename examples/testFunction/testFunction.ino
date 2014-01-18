/*
 * Test sketch for Xadow LED 5x7 Matrix. 
 * http://www.seeedstudio.com/depot/xadow-led-p-1518.html
 * Part of the Xadow line of miature and wearable electronics.
 * http://www.seeedstudio.com/wiki/Xadow
 *
 * This sketch presents a menu when you open the Serial Console
 * for you to select and view the various modes of the 5x7 Matrix
 *
 * Theres a 'datasheet' decribing functions and more at: 
 * https://docs.google.com/document/d/1a5goyVOdg7LhKmaBIOASU9KGieQbUIGRv5aqFcrxuwE/edit
 * 
 * Check out the wiki page for more info
 * http://www.seeedstudio.com/wiki/Xadow_LED_5X7
 * (note theres 2 version of the firmware out there, so either the
 * current wiki code will work or this library will work
 * if this library doesnt work and youd like it to, see the datasheet
 * for info on how to upgrade firmware
 * 
 * Seeed Studios is an Open Hardware company. Support our contributions by buying
 * our products! http://www.seeedstudio.com/
 */

#include <Wire.h>
#include <LEDMatrix.h>

#define ADDRESS 0x04

unsigned char data[5] = {
  0b1010101,
  0b0101010,
  0b1010101,
  0b0101010,
  0b1010101,
};

unsigned char data2[5] = {
  0b0101010,
  0b1010101,
  0b0101010,
  0b1010101,
  0b0101010,
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
    Serial.println("1: set direction: DIR_DOWN");
    Serial.println("2: set direction: DIR_NORMAL");
    Serial.println("3: string once");
    Serial.println("4: string loop");
    Serial.println("5: display char");
    Serial.println("A: animate");
    Serial.println("***********************************");
    Serial.println("6: set direction: DIR_RIGHT");
    Serial.println("7: set direction: DIR_LEFT");
    Serial.println("8: display matrix");
    Serial.println("9: display different matrix");
    Serial.println("***********************************");
    Serial.println("S: goto sleep");
    Serial.println("W: wake up");
    Serial.println("***********************************");
}

void dtaProc(unsigned char cmd)
{
    switch(cmd)
    {      
        case '1':
        Serial.println("set direction: DIR DOWN");
        fiveBySeven.setDir(DIR_DOWN);
        break;
        
        case '2':
        Serial.println("set direction: DIR NORMAL");
        fiveBySeven.setDir(DIR_NORMAL);
        break;
        
        case '3':
        Serial.println("string once");
        fiveBySeven.sendString(STR_ONCE, 400, "once");
        break;
        
        case '4':
        Serial.println("string loop");
        fiveBySeven.sendString(STR_LOOP, 400, "loop");
        break;
        
        case '5':
        Serial.println("disp char");
        fiveBySeven.sendChar('A');
        break;
        
        case 'A':
        Serial.println("animate");
        fiveBySeven.setPoint(0, 0, 1);
        delay(1000); //give some time to animate
        fiveBySeven.setPoint(1, 1, 1);
        delay(1000);
        fiveBySeven.setPoint(2, 2, 1);
        delay(1000);
        fiveBySeven.setPoint(3, 3, 1);
        delay(1000);
        fiveBySeven.setPoint(4, 4, 1);
        break;
        
        case '6':
        Serial.println("set direction: DIR RIGHT");
        fiveBySeven.setDir(DIR_RIGHT);
        break;
        
        case '7':
        Serial.println("set direction: DIR LEFT");
        fiveBySeven.setDir(DIR_LEFT);
        break;
        
        case '8':
        Serial.println("display matrix");
        fiveBySeven.setPoints(data, 5);
        break;
        
        case '9':
        Serial.println("display different matrix");
        fiveBySeven.setPoints(data2, 5);
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
