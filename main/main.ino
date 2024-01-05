// #include <LiquidCrystal.h>


// LiquidCrystal lcd(13, 12, 14, 27, 26, 25);


// void setup() {
//   // set up the LCD's number of columns and rows:
//   lcd.begin(16, 2);
//   // Print a message to the LCD.
//   lcd.print("Hello, world!");
// }

// void loop() {
//   // set the cursor to column 0, line 1
//   // (note: line 1 is the second row, since counting begins with 0):
//   lcd.setCursor(0, 1);
//   // print the number of seconds since reset:
//   lcd.print(millis() / 1000);
// }

/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.11 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.4 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_WIFI_POINT
#include <WiFi.h>
#include <RemoteXY.h>
#include <LiquidCrystal.h>


bool submitButtonReleased = true;
LiquidCrystal lcd(13, 12, 14, 27, 26, 25);

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = { 
  255,17,0,0,0,28,0,16,31,1,7,36,9,25,47,6,24,31,37,16,
  1,1,33,34,23,7,176,31,83,117,98,109,105,116,0 
};
  
// this structure defines all the variables and events of your control interface 
struct {
  // input variables
  char textInput[16];     // string UTF8 end zero  
  uint8_t submitButton;   // =1 if button pressed, else =0 

  // other variable
  uint8_t connect_flag;   // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


void setup() 
{
  RemoteXY_Init (); 
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() 
{ 
  RemoteXY_Handler ();
  lcd.setCursor(0, 0);

  if(RemoteXY.submitButton == 1 && submitButtonReleased) {
    submitButtonReleased = false;
    Serial.println(RemoteXY.textInput);
    lcd.println(RemoteXY.textInput);
  }
  
  if(RemoteXY.submitButton == 0) {
    submitButtonReleased = true;
  }

  delay(50);
}
















