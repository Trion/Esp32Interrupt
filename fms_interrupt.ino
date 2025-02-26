void UART_RX_IRQ(){
    uint16_t size = Serial.available();
    Serial.printf("Got %d bytes on Serial to read\n", size);
    while(Serial.available()) {
      Serial.write(Serial.read());
    }
    Serial.printf("\nSerial data processed!\n");
  }

void UART1_RX_IRQ(){
    uint16_t size = Serial1.available();
    Serial.printf("Got %d bytes on Serial1 to read\n", size);
    while(Serial1.available()) {
      Serial.write(Serial1.read());
    }
    Serial.printf("\nSerial1 data processed!\n");
  }
  
  void setup() {
    Serial.begin(115200);
    Serial1.begin(9600, SERIAL_8N1, 16, 17);
    Serial1.onReceive(UART1_RX_IRQ);
    Serial.onReceive(UART_RX_IRQ);
    Serial.println("Send data to UART0 in order to activate the RX callback");
  }
  
  void loop() {
    Serial.println("Sleeping for 10 seconds...");
    delay(10000);
  }