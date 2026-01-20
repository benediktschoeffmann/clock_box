#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Button2.h>
#include <Rotary.h>

// OLED _
#define OLED_WIDTH    128
#define OLED_HEIGHT   64
#define OLED_ADDRESS  0x3D
#define OLED_RESET      -1

// ENCODER 
#define ENCODER_A    3
#define ENCODER_B    2
#define ENCODER_PSH  6

// BUTTONS
#define CONFIRM      4
#define BACK         5

// I2C 
#define SCL          (A5) 
#define SDA          (A4)

// PORTS
#define PORTA        8
#define PORTB        9
#define PORTC        10
#define PORDD        11 

const int CLICKS_PER_STEP = 5;

Rotary encoder;
Button2 encoderButton;
Button2 confirmButton, backButton;

Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(9600);
    delay(500);    

    // setup encoder with pushbutton
    encoder.begin(ENCODER_A, ENCODER_B, CLICKS_PER_STEP);
    encoder.setChangedHandler(rotate);
    encoder.setLeftRotationHandler(showDirection);
    encoder.setRightRotationHandler(showDirection);

    encoderButton.begin(ENCODER_PSH);
    encoderButton.setTapHandler(encoderClick);
    encoderButton.setLongClickHandler(encoderLong);

    // setup buttons
    backButton.begin(BACK);
    backButton.setTapHandler(backClick);
    backButton.setLongClickHandler(backLong);

    confirmButton.begin(CONFIRM);
    confirmButton.setTapHandler(confirmClick);
    confirmButton.setLongClickHandler(confirmLong);

    if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
      Serial.println("Failed to allocate SSD1306");
      for (;;);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}

////////////////////////////////////////////////// event handlers
// -------------------------------------------------------encoder 
// on change
void rotate(Rotary& r) {
   Serial.println(r.getPosition());
}

// on left or right rotation
void showDirection(Rotary& r) {
  Serial.println(r.directionToString(r.getDirection()));
}

// -------------------------------------------------------encoder Button

void encoderClick(Button2& btn) {
  Serial.println("Click!");
}

void encoderLong(Button2& btn) {
  encoder.resetPosition();
  Serial.println("Reset!");
}

// -------------------------------------------------------back Button
void backClick(Button2& btn) {
  Serial.println("Click!");
}

void backLong(Button2& btn) {
  Serial.println("Back Long!");
}

// -------------------------------------------------------confirm Button
void confirmClick(Button2& btn) {
  Serial.println("Confirm!");
}

void confirmLong(Button2& btn) {
  Serial.println("Confirm Long!");
}