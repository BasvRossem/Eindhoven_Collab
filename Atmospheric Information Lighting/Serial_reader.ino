#include <Adafruit_SSD1306.h>

//=====Variables=====
int led = 13;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//=====Functions=====
void setup() {
  pinMode(led, OUTPUT);
  Serial.println("Program started");
  Serial.begin(9600);
  
  //Display setup
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)  // init done  
  display.clearDisplay();  // text display tests  
  display.setTextSize(1.5);  
  display.setTextColor(WHITE);  
  display.setCursor(0,0);  
  display.println("Start typing");  
  display.display();  
  display.clearDisplay();
}

void loop() {
  // send data only when you receive data:
  //println (Serial.read);
  
  if (Serial.available() > 0) {
    //  read the incoming byte:
    display.setCursor(0,0); 
    display.println(Serial.readString());
    display.display();  
    display.clearDisplay();

    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay (500);
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
