#if 1

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>


#define MINPRESSURE 200
#define MAXPRESSURE 1000

// ALL Touch panels and wiring is DIFFERENT


const int TS_LEFT=953,TS_RT=91,TS_TOP=907,TS_BOT=133;
int brightness=50;
String brightnessStr="50";
String brSchStr="50";
String timesch, timecount;

//landscape
const int XP=8,XM=A2,YP=A3,YM=9; //320x480 ID=0x9486
//const int TS_LEFT=87,TS_RT=911,TS_TOP=954,TS_BOT=87;


////PORTRAIT  CALIBRATION     320 x 480
////x = map(p.x, LEFT=133, RT=907, 0, 320)
////y = map(p.y, TOP=953, BOT=91, 0, 480)
//
////LANDSCAPE CALIBRATION     480 x 320
//x = map(p.y, LEFT=953, RT=91, 0, 480)
//y = map(p.x, TOP=907, BOT=133, 0, 320)

bool screen=true;


TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button on_btn, off_btn, settings_btn, schedule_btn, plus_btn,minus_btn,decbr_btn,incbr_btn, dechr_btn,inchr_btn, incmin_btn, decmin_btn,schon_btn, back_btn ;


int pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.y, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.x, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}
int intschhr=0;
int intschmin=0;
String schhr="00";
String schmin="00";


#define BLACK   0x0001
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define DARKGREEN       0x03E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define OLIVE   0x7BE0
#define GREY    0xC618
#define ORANGE  0xFD20 


void Homescreen(void){
//    tft.reset();
//  uint16_t  ID = 0x9486;
//    tft.begin(ID);
//    tft.setRotation(1);
    tft.fillScreen(BLACK);
//    on_btn.initButton(&tft,  80, 220, 100, 40, WHITE, CYAN, BLACK, "ON", 2);
    settings_btn.initButton(&tft,  400, 220, 110, 40, WHITE, GREY, BLACK, "Settings", 2);
    schedule_btn.initButton(&tft,  400, 280, 110, 40, WHITE, GREY, BLACK, "Schedule", 2);
//    off_btn.initButton(&tft, 80, 280, 100, 40, WHITE, CYAN, BLACK, "PLAY", 2);
    minus_btn.initButton(&tft, 200, 280, 50, 50, WHITE, RED, WHITE, "-", 3);
    plus_btn.initButton(&tft, 285, 280, 50, 50, WHITE, DARKGREEN, WHITE, "+", 3);
    off_btn.initButton(&tft,  400, 110, 120, 80, WHITE, GREEN, BLACK, "START", 2);
    on_btn.initButton(&tft, 80, 270, 120, 60, WHITE, CYAN, BLACK, "RESET", 2);
    
    settings_btn.drawButton(false);
    schedule_btn.drawButton(false);
    on_btn.drawButton(false);
    off_btn.drawButton(false);
    minus_btn.drawButton(false);
    plus_btn.drawButton(false);
    
//    tft.fillRect(40, 20, 160, 80, MAGENTA);
//   tft.fillRect(100,100,80,100,BLACK);
//   tft.drawRect(100,100,80,100,RED);
    tft.setCursor(175,10);
    tft.setTextColor(WHITE); 
    tft.setTextSize(2);
    tft.println("04:25:30 PM");
    tft.drawCircle(240,150,81,WHITE);
    tft.drawCircle(240,150,80,WHITE);
    tft.drawCircle(240,150,79,WHITE);
    tft.drawCircle(240,150,78,WHITE);
    tft.drawCircle(240,150,77,WHITE);
    tft.drawCircle(240,150,70,CYAN);
    tft.drawRoundRect(0,0,480,320,5,WHITE);
    tft.drawRoundRect(2,2,476,316,5,YELLOW);
//    tft.setCursor(200,125);
//    tft.setTextColor(YELLOW);
//    tft.setTextSize(6);
    if (brightness<10){
      brightnessStr="0"+String(brightness);
    }
    else{
      brightnessStr=String(brightness);
    }
    if(brightness==100){
             tft.fillCircle(240,150,69,BLACK);
//              tft.drawCircle(240,150,81,WHITE);
//              tft.drawCircle(240,150,80,WHITE);
//              tft.drawCircle(240,150,79,WHITE);
//              tft.drawCircle(240,150,78,WHITE);
//              tft.drawCircle(240,150,77,WHITE);
//              tft.drawCircle(240,150,70,CYAN);
//              tft.drawRoundRect(0,0,480,320,5,WHITE);
//              tft.drawRoundRect(2,2,476,316,5,YELLOW);
              tft.setCursor(175,125);
              tft.setTextColor(YELLOW);
              tft.setTextSize(6);
              
              tft.print(brightnessStr);
              tft.setCursor(285,135);
              tft.setTextColor(YELLOW);
              tft.setTextSize(3);
              tft.print("%");
            
          }
          else{
             tft.fillCircle(240,150,69,BLACK);
//              tft.drawCircle(240,150,81,WHITE);
//              tft.drawCircle(240,150,80,WHITE);
//              tft.drawCircle(240,150,79,WHITE);
//              tft.drawCircle(240,150,78,WHITE);
//              tft.drawCircle(240,150,77,WHITE);
//              tft.drawCircle(240,150,70,CYAN);
//              tft.drawRoundRect(0,0,480,320,5,WHITE);
//              tft.drawRoundRect(2,2,476,316,5,YELLOW);
              tft.setCursor(200,125);
              tft.setTextColor(YELLOW);
              tft.setTextSize(6);
              
              tft.print(brightnessStr);
              tft.setCursor(273,135);
              tft.setTextColor(YELLOW);
              tft.setTextSize(3);
              tft.print("%");
          }
 

    tft.drawFastHLine(0,30,480,CYAN);

    tft.drawRoundRect(10,45,140,170,5,WHITE);
    tft.setTextColor(YELLOW);
    tft.setCursor(25,65);
    tft.setTextColor(GREY);
    tft.setTextSize(2);
    tft.print("Elapsed");
    tft.setCursor(25,85);
    tft.print("Time");
    tft.setCursor(25,140);
        tft.setTextColor(GREY);
        tft.setTextSize(2);
        tft.print("Scheduled");
        tft.setCursor(25,160);
        tft.print("Duration");

        tft.setTextSize(2);
        tft.setCursor(30,110);
        tft.setTextColor(GREEN);
        tft.print("--:--:--");
      
        tft.setCursor(30,185);
        tft.setTextColor(ORANGE);
        tft.print("--:--:--");
  
}

void Schedulescreen(void){
//    tftTIM.reset();
//   uint16_t ID = 0x9486;
//    tft.begin(ID);
//    tft.setRotation(1);
    tft.fillScreen(BLACK);
    
    decbr_btn.initButton(&tft, 60, 240, 70, 50, WHITE, RED, WHITE, "-", 3);
    incbr_btn.initButton(&tft, 60, 100, 70, 50, WHITE, DARKGREEN, WHITE, "+", 3);
    dechr_btn.initButton(&tft, 200, 240, 50, 50, WHITE, RED, WHITE, "-", 3);
    inchr_btn.initButton(&tft, 200, 100, 50, 50, WHITE, DARKGREEN, WHITE, "+", 3);
    decmin_btn.initButton(&tft, 320, 240, 50, 50, WHITE, RED, WHITE, "-", 3);
    incmin_btn.initButton(&tft, 320, 100, 50, 50, WHITE, DARKGREEN, WHITE, "+", 3);
    schon_btn.initButton(&tft,  420, 240, 90, 60, WHITE, YELLOW, BLACK, "Set", 3);
    back_btn.initButton(&tft,  420, 130, 90, 60, WHITE, GREY, BLACK, "Back", 3);
    
    
    decbr_btn.drawButton(false);
    incbr_btn.drawButton(false);
    dechr_btn.drawButton(false);
    inchr_btn.drawButton(false);
    decmin_btn.drawButton(false);
    incmin_btn.drawButton(false);
    schon_btn.drawButton(false);
    back_btn.drawButton(false);
    
    tft.drawRoundRect(0,0,480,320,5,WHITE);
    tft.drawRoundRect(2,2,476,316,5,YELLOW);    
    tft.drawFastHLine(0,30,480,CYAN);


    tft.setCursor(10,40);
    tft.setTextSize(2);
    tft.setTextColor(YELLOW);
    tft.println("Set the brightness and time");

    if (brightness<10){
      brSchStr="0"+String(brightness);
    }
    else{
      brSchStr=String(brightness);
    }
    if(brightness==100){
            tft.fillRoundRect(26,146,68,48,15,BLACK);
             tft.setCursor(35,160);
              tft.setTextSize(3);
              tft.setTextColor(WHITE);
              tft.println(brSchStr);
            
          }
          else{
            tft.fillRoundRect(26,146,68,48,15,BLACK);
             tft.setCursor(45,160);
              tft.setTextSize(3);
              tft.setTextColor(WHITE);
              tft.println(brSchStr);
          }
    tft.drawRoundRect(25,145,70,50,15,WHITE);
    tft.drawRoundRect(175,145,50,50,15,WHITE);
    tft.drawRoundRect(295,145,50,50,15,WHITE);
    
    tft.setCursor(105,160);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.println("%");
    
    tft.setCursor(7,280);
    tft.setTextSize(2);
    tft.setTextColor(CYAN);
    tft.println("Brightness");

    intschhr=0;
    intschmin=0;
    
    tft.setCursor(185,160);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.println(schhr);

    tft.setCursor(169,280);
    tft.setTextSize(2);
    tft.setTextColor(CYAN);
    tft.println("Hours");
    
    tft.setCursor(305,160);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.println(schmin);

    tft.setCursor(280,280);
    tft.setTextSize(2);
    tft.setTextColor(CYAN);
    tft.println("Minutes");
    


    
  
}

void setup(void)
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
//    Serial.print("TFT ID = 0x");
//    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(1);            //PORTRAIT
    Homescreen();
    
           

}
bool on=true;
bool play=true;
bool sch=false;
int a=0;
int sec=0;
int minute=0,hour=0;
int test=0;
unsigned long current_time=0;
unsigned long pre_time=0;
String hr,mn,sc;
bool timer=true;

/* two buttons are quite simple
 */
void loop(void)
{
   current_time=millis();
   if(!timer && screen){
    if((current_time-pre_time)>1000){
     pre_time=current_time;
    sec++;
    if(sec<10)
    {
      sc="0"+String(sec);
    }
    else
    {
      sc=String(sec);
    }
    if(minute<10)
    {
      mn="0"+String(minute);
    }
    else
    {
      mn=String(minute);
    }
    if(hour<10)
    {
      hr="0"+String(hour);
    }
    else
    {
      hr=String(hour);
    }
    timecount= hr+ ":"+mn+":"+ sc;
    
    
    tft.fillRoundRect(30,110,100,30,5,BLACK);
    tft.setTextSize(2);
    tft.setCursor(30,110);
    tft.setTextColor(GREEN);
    tft.print(timecount);

    
      
   if(sec>=59){
         sec=-1;
         minute++;
         if(minute>59){
          hour++;
          minute=0;
          if(hour>23){hour=0;}
             } 
             }
    
    }

    
   }
  
   
   
  
    bool down = Touch_getXY();
    on_btn.press(down && on_btn.contains(pixel_x, pixel_y));
    off_btn.press(down && off_btn.contains(pixel_x, pixel_y));
    schedule_btn.press(down && schedule_btn.contains(pixel_x, pixel_y));
    plus_btn.press(down && plus_btn.contains(pixel_x, pixel_y));
    minus_btn.press(down && minus_btn.contains(pixel_x, pixel_y));
    back_btn.press(down && back_btn.contains(pixel_x, pixel_y));
    schon_btn.press(down && schon_btn.contains(pixel_x, pixel_y));
    decbr_btn.press(down && decbr_btn.contains(pixel_x, pixel_y));
    incbr_btn.press(down && incbr_btn.contains(pixel_x, pixel_y));
    dechr_btn.press(down && dechr_btn.contains(pixel_x, pixel_y));
    inchr_btn.press(down && inchr_btn.contains(pixel_x, pixel_y));
    decmin_btn.press(down && decmin_btn.contains(pixel_x, pixel_y));
    incmin_btn.press(down && incmin_btn.contains(pixel_x, pixel_y));

    
    if (on_btn.justReleased()&& screen)
        on_btn.drawButton();
    if (off_btn.justReleased()&& screen)
        off_btn.drawButton();
//    if (schedule_btn.justReleased())
//        schedule_btn.drawButton();
    if (minus_btn.justReleased()&& screen)
        minus_btn.drawButton();
    if (plus_btn.justReleased()&& screen)
        plus_btn.drawButton();
//    if (back_btn.justReleased()&& screen)
//        back_btn.drawButton();
      if (incbr_btn.justReleased()&& !screen)
          incbr_btn.drawButton();
      if (decbr_btn.justReleased()&& !screen)
         decbr_btn.drawButton();
      if (inchr_btn.justReleased()&& !screen)
         inchr_btn.drawButton();
      if (dechr_btn.justReleased()&& !screen)
         dechr_btn.drawButton();
      if (incmin_btn.justReleased()&& !screen)
         incmin_btn.drawButton();
      if (decmin_btn.justReleased()&& !screen)
         decmin_btn.drawButton();

    if(timesch==timecount && sch){
      timer=true;
      sch=false;
//      tft.fillRoundRect(30,185,100,20,5,BLACK);
//      tft.setCursor(30,185);
//        tft.setTextColor(ORANGE);
//        tft.print("--:--:--");
      tft.fillRoundRect(350,6,20,20,5,BLACK);
      
    }

    
    if (on_btn.justPressed()&& screen) {
        on_btn.drawButton(true);
        timer=true;
        sch=false;
        off_btn.initButton(&tft,  400, 110, 120, 80, WHITE, GREEN, BLACK, "START", 2);
        play=true;
        tft.fillRoundRect(30,110,100,30,5,BLACK);
        tft.setTextSize(2);
        tft.setCursor(30,110);
        tft.setTextColor(GREEN);
        tft.print("00:00:00");
        tft.fillRoundRect(30,185,100,20,5,BLACK);
        tft.setCursor(30,185);
        tft.setTextColor(ORANGE);
        tft.print("00:00:00");
        tft.fillRoundRect(350,6,20,20,5,BLACK);

        
//        off_btn.drawButton(true)
//        if(on){
//          timer=false;
//          on=false;
//          on_btn.initButton(&tft,  400, 110, 120, 80, WHITE, CYAN, BLACK, "OFF", 2);
////          play=false;
//          
//          
//           
//          off_btn.initButton(&tft, 80, 260, 120, 80, WHITE, CYAN, BLACK, "PAUSE", 2);
//          off_btn.drawButton();
//////          tft.fillRect(40, 80, 160, 80, RED);
////          play=false;
//          
//        }
//        else{
//          hour=0;
//          minute=0;
//          sec=0;
//          timer=true;
//          on=true;
//          on_btn.initButton(&tft,  400, 110, 120, 80, WHITE, CYAN, BLACK, "ON", 2);
//
////          play=true;
//          
//           
//          off_btn.initButton(&tft,  80, 260, 120, 80, WHITE, CYAN, BLACK, "START", 2);
//          off_btn.drawButton();
//////          tft.fillRect(40, 80, 160, 80, RED);
////          play=true;
//            
//        }
        
    }
    if (off_btn.justPressed()&& screen) {
      Serial.println(play);
        timer=false;
        off_btn.drawButton(true);
        if(play){
          
          off_btn.initButton(&tft,  400, 110, 120, 80, WHITE, ORANGE, BLACK, "PAUSE", 2);
//          tft.fillRect(40, 80, 160, 80, RED);
          play=false; 
          
        }
        else{
          timer=true;
          off_btn.initButton(&tft,  400, 110, 120, 80, WHITE, GREEN, BLACK, "START", 2);
//          tft.fillRect(40, 80, 160, 80, RED);
          play=true; 
          
        }
        
    }
    if (schedule_btn.justPressed()&& screen) {
        schedule_btn.drawButton(true);
        screen=false;
        
        Schedulescreen();
//        if(sch){
//          tft.drawRoundRect(350,6,20,20,5,WHITE);
//          
//           tft.setCursor(355,9);
//           tft.setTextColor(ORANGE);
//           tft.setTextSize(2);
//           tft.print("S");
//           sch=false;
//        }
//        else{
//          tft.fillRoundRect(350,6,20,20,5,BLACK);
////           tft.setTextColor(YELLOW);
////           tft.setCursor(368,115);
////           tft.setTextColor(ORANGE);
////           tft.print("S");
//           sch=true; 
//        }
        
    }
    if (plus_btn.justPressed()&& screen) {
        plus_btn.drawButton(true);
        
        if(brightness<100){
            brightness=brightness+5;
            if(brightness<10)
          {
            brightnessStr="0"+String(brightness);
          }
           else{
            brightnessStr=String(brightness);
          }
          if(brightness==100){
             tft.fillCircle(240,150,69,BLACK);
//              tft.drawCircle(240,150,81,WHITE);
//              tft.drawCircle(240,150,80,WHITE);
//              tft.drawCircle(240,150,79,WHITE);
//              tft.drawCircle(240,150,78,WHITE);
//              tft.drawCircle(240,150,77,WHITE);
//              tft.drawCircle(240,150,70,CYAN);
//              tft.drawRoundRect(0,0,480,320,5,WHITE);
//              tft.drawRoundRect(2,2,476,316,5,YELLOW);
              tft.setCursor(175,125);
              tft.setTextColor(YELLOW);
              tft.setTextSize(6);
              
              tft.print(brightnessStr);
              tft.setCursor(285,135);
              tft.setTextColor(YELLOW);
              tft.setTextSize(3);
              tft.print("%");
            
          }
          else{
             tft.fillCircle(240,150,69,BLACK);
//              tft.drawCircle(240,150,81,WHITE);
//              tft.drawCircle(240,150,80,WHITE);
//              tft.drawCircle(240,150,79,WHITE);
//              tft.drawCircle(240,150,78,WHITE);
//              tft.drawCircle(240,150,77,WHITE);
//              tft.drawCircle(240,150,70,CYAN);
//              tft.drawRoundRect(0,0,480,320,5,WHITE);
//              tft.drawRoundRect(2,2,476,316,5,YELLOW);
              tft.setCursor(200,125);
              tft.setTextColor(YELLOW);
              tft.setTextSize(6);
              
              tft.print(brightnessStr);
              tft.setCursor(273,135);
              tft.setTextColor(YELLOW);
              tft.setTextSize(3);
              tft.print("%");
          }
          
        
       
          
       
        }  
        
    }
    if (minus_btn.justPressed()&& screen) {
        minus_btn.drawButton(true);
        if(brightness>0){
          brightness=brightness-5;
          if(brightness<10)
          {
            brightnessStr="0"+String(brightness);
          }
          else{
            brightnessStr=String(brightness);
          }
          
         
        tft.fillCircle(240,150,69,BLACK);
//        tft.drawCircle(240,150,81,WHITE);
//        tft.drawCircle(240,150,80,WHITE);
//        tft.drawCircle(240,150,79,WHITE);
//        tft.drawCircle(240,150,78,WHITE);
//        tft.drawCircle(240,150,77,WHITE);
//        tft.drawCircle(240,150,70,CYAN);
//        tft.drawRoundRect(0,0,480,320,5,WHITE);
//        tft.drawRoundRect(2,2,476,316,5,YELLOW);
        tft.setCursor(200,125);
        tft.setTextColor(YELLOW);
        tft.setTextSize(6);
        
        tft.print(brightnessStr);
        tft.setCursor(273,135);
        tft.setTextColor(YELLOW);
        tft.setTextSize(3);
        tft.print("%");
          
        }

        }
        if (incbr_btn.justPressed()&& !screen) {
        incbr_btn.drawButton(true);
        
        if(brightness<100){
            brightness=brightness+5;
            if(brightness<10)
          {
            brSchStr="0"+String(brightness);
          }
           else{
            brSchStr=String(brightness);
          }
          if(brightness==100){
            tft.fillRoundRect(26,146,68,48,15,BLACK);
             tft.setCursor(35,160);
              tft.setTextSize(3);
              tft.setTextColor(WHITE);
              tft.println(brSchStr);
            
          }
          else{
            tft.fillRoundRect(26,146,68,48,15,BLACK);
             tft.setCursor(45,160);
              tft.setTextSize(3);
              tft.setTextColor(WHITE);
              tft.println(brSchStr);
          }
        }  
        
    }
    if (decbr_btn.justPressed()&& !screen) {
        decbr_btn.drawButton(true);
        if(brightness>0){
          brightness=brightness-5;
          if(brightness<10)
          {
            brSchStr="0"+String(brightness);
          }
          else{
            brSchStr=String(brightness);
          }
          
         tft.fillRoundRect(26,146,68,48,15,BLACK);
             tft.setCursor(35,160);
              tft.setTextSize(3);
              tft.setTextColor(WHITE);
              tft.println(brSchStr);
            
       
          
        }
   
    }


#endif
