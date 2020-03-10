
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>


#define RELAY_NUMBERS_GROUP 11

//Группа макросов, задающих время
/*_____________________________________________________________ПЕРВЫЙ_СТЕНД_РАСПИНОВКА___________________________________*/
//значение регулирующих пинов для насосов
#define PUMP_1_IN_PIN 22
#define PUMP_1_OUT_PIN 23
//значение регулирующих пинов для кранов
#define STEND_1_YAR_1_IN_PIN 24    //первый ярус
#define STEND_1_YAR_2_IN_PIN 25    //второй ярус
#define STEND_1_YAR_3_IN_PIN 26    //третий ярус
#define STEND_1_YAR_4_IN_PIN 27    //четвертый ярус
#define STEND_1_YAR_5_IN_PIN 28    //пятый ярус



/*____________________________________________________________Группа макровос включения япусов первого стенда____________*/
//
#define STEND_1_YAR_1_ENABLED 1
#define STEND_1_YAR_2_ENABLED 0
#define STEND_1_YAR_3_ENABLED 0
#define STEND_1_YAR_4_ENABLED 0
#define STEND_1_YAR_5_ENABLED 0

/*_____________________________________________________________ПЕРВЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/



//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_1_IN_HOUR_ON 18   //значения ЧАСА ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_ON 5 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_HOUR_OFF 18   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_OFF 7   //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_1_OUT_HOUR_ON 18   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_MINUTE_ON 14 //значения МИНУТЫ ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_HOUR_OFF 18   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_1_OUT_MINUTE_OFF 15 //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ВТОРОЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_2_IN_HOUR_ON 17   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_ON 35 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_OFF 26   //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_2_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_MINUTE_ON 27 //значения МИНУТЫ ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_2_OUT_MINUTE_OFF 28 //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ТРЕТИЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_3_IN_HOUR_ON 17  //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_ON 29 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_OFF 30   //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_3_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_MINUTE_ON 31 //значения МИНУТЫ ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_3_OUT_MINUTE_OFF 32 //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*______________________________________________________________ЧЕТВЕРТЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_4_IN_HOUR_ON 17   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_MINUTE_ON 33 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_MINUTE_OFF 34   //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_4_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_4_OUT_MINUTE_ON 35 //значения МИНУТЫ ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_4_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_4_OUT_MINUTE_OFF 36 //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ПЯТЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_5_IN_HOUR_ON 17  //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_MINUTE_ON 37 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_MINUTE_OFF 38   //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_5_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_5_OUT_MINUTE_ON 39 //значения МИНУТЫ ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_5_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_5_OUT_MINUTE_OFF 40 //значения МИНУТЫ ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


//Функции, используемые в проекте
void InitializePins();
void led_tester();
void led_tester_off();
void stage1(int crane,int pump);
void stage2(int crane,int pump);
void stage3(int pump);
void stage4(int pump);

void setup() {

     Serial.begin(9600);

  // put your setup code here, to run once:
     pinMode(13,OUTPUT);//Отладка мигалкой

    // pinMode(2,OUTPUT);

    InitializePins();


}

void loop() {
  // put your main code here, to run repeatedly:

      tmElements_t tm;
      
      
      if (RTC.read(tm)) 
      {
        
        //___________________________________________________Первый ярус___________________
        if(STEND_1_YAR_1_ENABLED){
        if((tm.Hour==PUMP_ST1_1_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_1_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_1_IN_PIN);


          //тестовый код
          led_tester_on();
          
        }

        
        if((tm.Hour==PUMP_ST1_1_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_1_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_1_IN_PIN);

          //тестовый код
          led_tester_off();       
        }

        
        if((tm.Hour==PUMP_ST1_1_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_1_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_on();        
        }

        
        if((tm.Hour==PUMP_ST1_1_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_1_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);

          //тестовый код
          led_tester_off();
        }
        }   

        //_________________________________________________ВТОРОЙ ЯРУС_____________________________

        if(STEND_1_YAR_2_ENABLED){
         if((tm.Hour==PUMP_ST1_2_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_2_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_2_IN_PIN);

          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_2_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_2_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_2_IN_PIN);


          //тестовый код
          led_tester_off();
        }

        
        if((tm.Hour==PUMP_ST1_2_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_2_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_2_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_2_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_off();
        }

      }
      
        //________________________________________Третий ярус__________________________________________________

        if(STEND_1_YAR_3_ENABLED){

         if((tm.Hour==PUMP_ST1_3_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_3_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_3_IN_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_3_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_3_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_3_IN_PIN);


          //тестовый код
          led_tester_off();
        }

        
        if((tm.Hour==PUMP_ST1_3_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_3_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_3_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_3_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_off();
        }
        }

        //________________________________________Четвертый ярус__________________________________________________
        
        if(STEND_1_YAR_4_ENABLED){

         if((tm.Hour==PUMP_ST1_4_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_4_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_4_IN_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_4_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_4_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_4_IN_PIN);


          //тестовый код
          led_tester_off();
        }

        
        if((tm.Hour==PUMP_ST1_4_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_4_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_4_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_4_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_off();
        }

        }
      //________________________________________Пятый ярус__________________________________________________

      if(STEND_1_YAR_5_ENABLED){

         if((tm.Hour==PUMP_ST1_5_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_5_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_5_IN_PIN);


          //тестовый код
          led_tester_on();
        }

        
        if((tm.Hour==PUMP_ST1_5_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_5_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_5_IN_PIN);


          //тестовый код
          led_tester_off();
        }

        
        if((tm.Hour==PUMP_ST1_5_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_5_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_on(); 
        }

        
        if((tm.Hour==PUMP_ST1_5_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_5_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          led_tester_off();
        }
      }      
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
}


void InitializePins()//ПЕРЕПИСАТЬ ДЛЯ МАКРОСОВ!!!
{
  int i=0;
  for(i=22;i<=28;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
    }

}

void led_tester_on()
{
    digitalWrite(13,HIGH);
  }

void led_tester_off()
{
    digitalWrite(13,LOW);
  }


void stage1(int pump,int crane)
{
  digitalWrite(crane,LOW);
  digitalWrite(pump,LOW);
  }

  void stage2(int pump,int crane)
{
  digitalWrite(crane,HIGH);
  digitalWrite(pump,HIGH);
  }

 void stage3(int pump)
 {
    digitalWrite(pump,LOW);
  }

    void stage4(int pump)
 {
    digitalWrite(pump,HIGH);
  } 
