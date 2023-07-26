#include <Arduino.h>

#define LED_PIN 2  // The pin the LED is connected to.

// Define the task - Tasks must have an infinite loop.
void TaskBlink(void *pvParameters) {
  (void) pvParameters;

  // Initialize the GPIO pin for the LED.
  pinMode(LED_PIN, OUTPUT);

  // An infinite loop.
  for (;;) {
    digitalWrite(LED_PIN, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED_PIN, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


void setup() {
  // Create the task.
  xTaskCreate(TaskBlink, "Blink", 1000, NULL, 2, NULL);
}

void loop() {
  // Nothing to do here.
}
