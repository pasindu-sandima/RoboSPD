Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void OLEDsetup(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void testdrawRED() {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print(F("RED"));
  display.display();
}
void OLEDprint(const char word){
  display.clearDisplay();
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print(word); 
  display.display();

}

void testdrawGREEN() {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print(F("GREEN")); 
  display.display();
}

void testdrawBLUE() {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print(F("BLUE")); 
  display.display();
}
void testdrawWelcome() {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(20,20);             // Start at top-left corner
  display.print(F("Welcome")); 
  display.display();
}