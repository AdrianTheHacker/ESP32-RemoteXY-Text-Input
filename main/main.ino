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


//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_WIFI_POINT
#include <WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = { 
  255,18,0,0,0,28,0,16,31,1,7,36,9,25,47,6,24,31,37,17,
  1,1,33,34,23,7,176,31,83,117,98,109,105,116,0 
};
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  char textInput[16];  // string UTF8 end zero  
  uint8_t submitButton; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
  if(RemoteXY.submitButton != 0) {
    Serial.println("Button Clicked");
  }

  delay(200);
}