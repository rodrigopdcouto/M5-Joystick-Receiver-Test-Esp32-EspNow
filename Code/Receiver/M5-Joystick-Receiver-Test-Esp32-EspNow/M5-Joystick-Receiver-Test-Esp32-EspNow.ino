#include <esp_now.h>
#include <WiFi.h>

typedef struct RxStruct {
  byte Joystick = 0;
} RxStruct;

RxStruct ReceiverData;

void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  if (len == 0) {
    return;
  }
  memcpy(&ReceiverData, incomingData, sizeof(ReceiverData));
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  if (ReceiverData.Joystick == 1) {
    Serial.println(" Joystick UP ");
  } else if (ReceiverData.Joystick == 2) {
    Serial.println(" Joystick DOWN ");
  } else if (ReceiverData.Joystick == 3) {
    Serial.println(" Joystick LEFT ");
  } else if (ReceiverData.Joystick == 4) {
    Serial.println(" Joystick RIGHT ");
  } else if (ReceiverData.Joystick == 5) {
    Serial.println(" Joystick PRESSED ");
  } else if (ReceiverData.Joystick == 6) {
    Serial.println(" Joystick STOP ");
  }
  delay(200);
}
