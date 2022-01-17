#include <IRremote.h>
#include <avr/wdt.h>

const int IR = 7;
const int Relay = 8;
unsigned long key_value = 0;
IRrecv irrecv(IR);
decode_results results;


void setup() {
  irrecv.enableIRIn();
  irrecv.blink13(true);
  digitalWrite(Relay, HIGH);
  pinMode(Relay, OUTPUT);
  wdt_enable(WDTO_500MS);
}

void loop() {
  if (irrecv.decode(&results)) {
   if (results.value == 0x9CB8F || results.value == 0x261301B5) {
      digitalWrite(Relay, LOW);
      delay(300);
      digitalWrite(Relay, HIGH);
      irrecv.resume();
    } else delay(600);
  }
  wdt_reset();
}