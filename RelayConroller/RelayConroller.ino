
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>


#define RELAY_NUMBERS_GROUP 11

//Группа макросов, задающих время
/*_____________________________________________________________ПЕРВЫЙ_СТЕНД_РАСПИНОВКА___________________________________*/
//значение регулирующих пинов для насосов
#define PUMP_1_IN_PIN 2
#define PUMP_1_OUT_PIN 3
//значение регулирующих пинов для кранов
#define STEND_1_YAR_1_IN_PIN 4    //первый ярус
#define STEND_1_YAR_2_IN_PIN 5    //второй ярус
#define STEND_1_YAR_3_IN_PIN 6    //третий ярус
#define STEND_1_YAR_4_IN_PIN 7    //четвертый ярус
#define STEND_1_YAR_5_IN_PIN 8    //пятый ярус


/*_____________________________________________________________ПЕРВЫЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/



//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_1_IN_HOUR_ON 4   //значения ЧАСА ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_ON 48 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_HOUR_OFF 4   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса
#define PUMP_ST1_1_IN_MINUTE_OFF 49   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для первого яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_1_OUT_HOUR_ON 4   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_MINUTE_ON 50 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_1_OUT_HOUR_OFF 4   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_1_OUT_MINUTE_OFF 51 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ВТОРОЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_2_IN_HOUR_ON 7   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_ON 13 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_HOUR_OFF 7   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_2_IN_MINUTE_OFF 18   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_2_OUT_HOUR_ON 7   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_MINUTE_ON 23 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_2_OUT_HOUR_OFF 7   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_2_OUT_MINUTE_OFF 26 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!


/*_____________________________________________________________ТРЕТИЙ_ЯРУС_ПЕРВОГО СТЕНДА________________________________*/
//Первый стенд первый ярус_ПОДАЧА ВОДЫ
#define PUMP_ST1_3_IN_HOUR_ON 7   //значения ЧАСА ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_ON 26 //значение МИНУТЫ ВКЛ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_HOUR_OFF 7   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса
#define PUMP_ST1_3_IN_MINUTE_OFF 31   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса ПОДАЧИ для второго яруса 
//первый ярус первый стенд_СЛИВ ВОДЫ
#define PUMP_ST1_3_OUT_HOUR_ON 7   //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_MINUTE_ON 36 //значения ЧАСА ВКЛ насоса СЛИВА для первого яруса
#define PUMP_ST1_3_OUT_HOUR_OFF 7   //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!
#define PUMP_ST1_3_OUT_MINUTE_OFF 39 //значения ЧАСА ВЫКЛЮЧЕНИЯ насоса СЛИВА для первого яруса и активация второго яруса !!!




   bool start=1;
   bool sheduler_1_started=0;
   bool sheduler_1_finished=0;


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
//pinMode(2,OUTPUT);
//pinMode(3,OUTPUT);

//pinMode(3,OUTPUT);
    pinMode(13,OUTPUT);//Отладка мигалкой

void InitializePins();


}

void loop() {
  // put your main code here, to run repeatedly:

      tmElements_t tm;

     // if((sheduler_1_started==0)&&(sheduler_1_finished!=1))
     // {
      if (RTC.read(tm)) 
      {
        //___________________________________________________Первый ярус___________________
        if((tm.Hour==PUMP_ST1_1_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_1_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_1_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
          //led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_1_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_1_IN_MINUTE_OFF))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_1_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          //led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_1_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_1_OUT_MINUTE_ON))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
          //led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_1_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_1_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
          //led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }   

        //_________________________________________________ВТОРОЙ ЯРУС_____________________________
         if((tm.Hour==PUMP_ST1_2_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_2_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_2_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
          //led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_2_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_2_OUT_MINUTE_ON))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_2_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          //led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_2_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_2_IN_MINUTE_OFF))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
          //led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_2_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_2_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
          //led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }

        //________________________________________Третий ярус__________________________________________________

         if((tm.Hour==PUMP_ST1_3_IN_HOUR_ON)&&(tm.Minute==PUMP_ST1_3_IN_MINUTE_ON))

        {
          stage1(PUMP_1_IN_PIN,STEND_1_YAR_3_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
          //led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_3_IN_HOUR_OFF)&&(tm.Minute==PUMP_ST1_3_OUT_MINUTE_ON))

        {
          stage2(PUMP_1_IN_PIN,STEND_1_YAR_3_IN_PIN);


          //тестовый код
          //sheduler_1_started=1;
          //led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_3_OUT_HOUR_ON)&&(tm.Minute==PUMP_ST1_3_IN_MINUTE_OFF))

        {
          stage3(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
          led_tester_on();
         // led_tester_off();
          //sheduler_1_finished=1;
          
        }

        
        if((tm.Hour==PUMP_ST1_3_OUT_HOUR_OFF)&&(tm.Minute==PUMP_ST1_3_OUT_MINUTE_OFF))

        {
          stage4(PUMP_1_OUT_PIN);


          //тестовый код
          //sheduler_1_started=1;
         // led_tester_on();
          led_tester_off();
          //sheduler_1_finished=1;
          
        }





        
//    Serial.print("Ok, Time = ");
//    print2digits(tm.Hour);
//    Serial.write(':');
//    print2digits(tm.Minute);
//    Serial.write(':');
//    print2digits(tm.Second);
//    Serial.print(", Date (D/M/Y) = ");
//    Serial.print(tm.Day);
//    Serial.write('/');
//    Serial.print(tm.Month);
//    Serial.write('/');
//    Serial.print(tmYearToCalendar(tm.Year));
//    Serial.println();
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
  //}
  //delay(1000);


    //led_tester_on();

    if (start==1)
    {
    InitializePins();
    start=0;
    }
    
    //digitalWrite(2,HIGH);

    

    //led_tester_off();

    //delay(7500);
    //digitalWrite(2,LOW);
    //delay(7500);
    

}


void InitializePins()//ПЕРЕПИСАТЬ ДЛЯ МАКРОСОВ!!!
{
  int i=0;
  for(i=2;i<RELAY_NUMBERS_GROUP+2;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
    }

}

void led_tester_on()
{
    digitalWrite(13,HIGH);
    //delay(7500);
  }

void led_tester_off()
{
    digitalWrite(13,LOW);
    //delay(7500);
  }


void stage1(int crane,int pump)
{
  digitalWrite(crane,LOW);
  digitalWrite(pump,LOW);
  }

  void stage2(int crane,int pump)
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
