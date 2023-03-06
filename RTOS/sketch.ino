const int led1 = 15;
const int led2 = 2;
const int led3 = 4;
const int led4 = 5;

TaskHandle_t TaskLed1;
TaskHandle_t TaskLed2;
TaskHandle_t TaskLed3;
TaskHandle_t TaskLed4;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, Belajar RTOS!");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  xTaskCreatePinnedToCore(
    Task1CodeLed, //Fungsi Tugas
    "TaskLed1", //Nama Tugas
    10000, //Besar Tumpukan
    NULL, //Parameter
    1, //Prioritas Tugas
    &TaskLed1, //Handel Tugas
    0 //Core
  );

  xTaskCreatePinnedToCore(
    Task2CodeLed, //Fungsi Tugas
    "TaskLed2", //Nama Tugas
    10000, //Besar Tumpukan
    NULL, //Parameter
    1, //Prioritas Tugas
    &TaskLed2, //Handel Tugas
    0 //Core
  );

  xTaskCreatePinnedToCore(
    Task3CodeLed, //Fungsi Tugas
    "TaskLed3", //Nama Tugas
    10000, //Besar Tumpukan
    NULL, //Parameter
    1, //Prioritas Tugas
    &TaskLed3, //Handel Tugas
    1 //Core
  );

  xTaskCreatePinnedToCore(
    Task4CodeLed, //Fungsi Tugas
    "TaskLed4", //Nama Tugas
    10000, //Besar Tumpukan
    NULL, //Parameter
    1, //Prioritas Tugas
    &TaskLed4, //Handel Tugas
    1 //Core
  );
}

void Task1CodeLed(void * pvParameters){
  Serial.print("Tugas 1 Berjalan di core : ");
  Serial.println(xPortGetCoreID());

  for(;;){
    // Tugas
    leds1();
  }
}

void Task2CodeLed(void * pvParameters){
  Serial.print("Tugas 2 Berjalan di core : ");
  Serial.println(xPortGetCoreID());

  for(;;){
    // Tugas
    leds2();
  }
}

void Task3CodeLed(void * pvParameters){
  Serial.print("Tugas 3 Berjalan di core : ");
  Serial.println(xPortGetCoreID());

  for(;;){
    // Tugas
    leds3();
  }
}

void Task4CodeLed(void * pvParameters){
  Serial.print("Tugas 4 Berjalan di core : ");
  Serial.println(xPortGetCoreID());

  for(;;){
    // Tugas
    leds4();
  }
}

void leds1(){
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
}

void leds2(){
  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led2, LOW);
  delay(1000);
}

void leds3(){
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
  delay(1000);
}

void leds4(){
  digitalWrite(led4, HIGH);
  delay(1000);
  digitalWrite(led4, LOW);
  delay(1000);
}

void loop() {
  // leds1();
  // leds2();
  // leds3();
  // leds4();
}
