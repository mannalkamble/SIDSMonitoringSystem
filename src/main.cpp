// Team Members: Mannal Kamble (mk8475), Meenesh Solanki (mms9905), Shruti Garg (sg7395), Tiyas Dey (td2355)
// Date: 18-12-2022
// Real-time Embedded Systems - Final Project Submission


#include <mbed.h>
//this file has all the functions for interacting with the screen
#include "drivers/LCD_DISCO_F429ZI.h"
#define BACKGROUND 1
#define FOREGROUND 0
#define NORMALIZING_FACTOR 4095
#define THRESHOLD 60000
using namespace std::chrono;
LCD_DISCO_F429ZI lcd;
//buffer for holding displayed text strings
char display_buf[2][60];
AnalogIn  sensorPA0(PA_0); //  pin for sensor
DigitalOut ledPA6(PA_6);  //  pin for LED
//sets the background layer to be visible, transparent, and resets its colors to all black
void setup_background_layer(){
  lcd.SelectLayer(BACKGROUND);
  lcd.Clear(LCD_COLOR_BLACK);
  lcd.SetBackColor(LCD_COLOR_BLACK);
  lcd.SetTextColor(LCD_COLOR_GREEN);
  lcd.SetLayerVisible(BACKGROUND,ENABLE);
  lcd.SetTransparency(BACKGROUND,0x7Fu);
}

//resets the foreground layer to all black
void setup_foreground_layer(){
    lcd.SelectLayer(FOREGROUND);
    lcd.Clear(LCD_COLOR_BLACK);
    lcd.SetBackColor(LCD_COLOR_BLACK);
    lcd.SetTextColor(LCD_COLOR_LIGHTGREEN);
}

Timer t;
int main() {
  setup_background_layer();
  setup_foreground_layer();

  //creates c-strings in the display buffers, in preparation for displaying them on the screen

  lcd.SelectLayer(FOREGROUND);
  uint16_t sensor_in = 0;  // stores sensor readings
  t.start();

  while(1){        
        if(duration_cast<milliseconds>(t.elapsed_time()).count()/1000 == 10){
          snprintf(display_buf[1],60,"%llu",duration_cast<milliseconds>(t.elapsed_time()).count()/1000); //  displays 10 on LCD when no readings change for 10s
          lcd.DisplayStringAt(0, LINE(3), (uint8_t *)display_buf[1], LEFT_MODE);
          ledPA6 = 1; //turn LED on
          break;  // breaks out of loop when no changes in readings for 10s
        }       
        sensor_in = NORMALIZING_FACTOR*sensorPA0.read_u16(); //  normalizing sensor readings
        if(sensor_in>THRESHOLD){  //  timer reset for significant fluctuation in sensor readings
          t.reset();
        }
        snprintf(display_buf[0],60,"%d",sensor_in);
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)display_buf[0], LEFT_MODE);  // display sensor readings on LCD
        thread_sleep_for(10); //  to control change in readings being displayed on LCD too fast
    }
}