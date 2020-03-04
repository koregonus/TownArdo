
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


/*_____________________________________________________________ПЕРВЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/



//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_1_IN_HOUR_ON 17   //значения ЧАСА ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_ON 01 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_OFF 02   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_1_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_MINUTE_ON 03 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_1_OUT_MINUTE_OFF 04 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ВТОРОЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_2_IN_HOUR_ON 17   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_ON 05 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_OFF 06   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_2_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_MINUTE_ON 07 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_2_OUT_MINUTE_OFF 8 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ТРЕТИЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_3_IN_HOUR_ON 17  //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_ON 9 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_OFF 10   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_3_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_MINUTE_ON 11 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_3_OUT_MINUTE_OFF 12 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*______________________________________________________________ЧЕТВЕРТЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_4_IN_HOUR_ON 17   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_MINUTE_ON 13 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_4_IN_MINUTE_OFF 14   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_4_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_4_OUT_MINUTE_ON 15 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_4_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_4_OUT_MINUTE_OFF 16 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ПЯТЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_5_IN_HOUR_ON 17  //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_MINUTE_ON 17 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_5_IN_MINUTE_OFF 18   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_5_OUT_HOUR_ON 17   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_5_OUT_MINUTE_ON 19 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_5_OUT_HOUR_OFF 17   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_5_OUT_MINUTE_OFF 20 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


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

void InitializePins();


}

void loop() {
  // put your main code here, to run repeatedly:

      tmElements_t tm;

      if (RTC.read(tm)) 
      {
        //___________________________________________________Первый ярус___________________
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

        //_________________________________________________ВТОРОЙ ЯРУС_____________________________
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

        //________________________________________Третий ярус__________________________________________________

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


        //________________________________________Четвертый ярус__________________________________________________

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


      //________________________________________Пятый ярус__________________________________________________

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
