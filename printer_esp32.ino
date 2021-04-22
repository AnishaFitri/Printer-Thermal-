#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"

#include "SoftwareSerial.h"
#define TX_PIN 16  // Pin 11 Arduino ke RX Printer
#define RX_PIN 17  // Pin 10 Arduino ke TX Printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);  

void setup() {

  mySerial.begin(9600);  // Initialize Baudrate SoftwareSerial
  printer.begin();        
  printer.setSize('S');  
  printer.justify('C');
  printer.println(F("Alex Tampan dan Berani"));
  printer.setSize('S');  
  printer.justify('C');
  printer.println(F("Ikan Asin"));
  printer.setSize('M');  
  printer.justify('C');
  printer.println(F("Perkedel Bubuk"));

// Barcode examples:
  // CODE39 is the most common alphanumeric barcode:
  printer.printBarcode("ADAFRUIT", CODE39);
  printer.setBarcodeHeight(100);
  // Print UPC line on product barcodes:
  printer.printBarcode("123456789123", UPC_A);

  // Print the 75x75 pixel logo in adalogo.h:
 
  printer.printBitmap(adalogo_width, adalogo_height, adalogo_data);


  // Print the 135x135 pixel QR code in adaqrcode.h:
  printer.printBitmap(adaqrcode_width, adaqrcode_height, adaqrcode_data);
  printer.println(F("Adafruit!"));
  printer.feed(2);

  printer.sleep();      // printer to sleep
  delay(500);         // Sleep for 3 seconds
  printer.wake();       
  printer.setDefault();
  
}

void loop() {
  
}
