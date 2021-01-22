#include <Arduino.h>
#include <xCore.h>
#include <xSL20.h>

xSL20 SL20;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Serial.println("trying to initialize SL20...");
  SL20.begin(16); // start the thermo cam with 8 frames per second
  Serial.println("sensor initialized!");
}

void loop()
{
  SL20.measure(true); //get new readings from the sensor
  for (int y = 0; y < 4; y++)
  { //go through all the rows
    //Serial.print("[");

    for (int x = 0; x < 16; x++)
    {                                                   //go through all the columns
      double tempAtXY = SL20.getTemperature(y + x * 4); // extract the temperature at position x/y
      Serial.print(tempAtXY);

      if (x < 15)
        Serial.print(",");
    }
    Serial.println("");
    //if (y<3)Serial.print("~");
  }
  Serial.print("\n");
  Serial.println("");
  delay(300);
};
