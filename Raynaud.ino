/* 
   Developers: Tilden Chima and Wilson Randle
   Temperature sensor connections:
   [Sensor] to [Arduino]
   S tab to A3
   + tab to A5
   - tab to A2

   Relay Connections
   [Arduino] to [Relay]
   A4 to Signal
   + to +
   - to -

   Using an Arduino LilyPad, LilyPad Temperature Sensor, and Songle SRD-05VDC-SL-C Relay or similar simple relay.
*/ 

int sensorPin = A3;        //data pin from temperature sensor
int sensorPositive= A5;    //positive voltage to temperature sensor
int sensorNegative = A2;   //negative (ground) to temperature sensor

int relayControl=A4;       //Controls relay - HIGH for on, LOW for off.

int threshold= 80; // Set temperature threshold variable to check against. If the temperature is below this threshold, the heating pad will turn on.
                   // For demo purposes, we might want to set this to slightly lower than room temperature (65-ish), so when exposed to a cold source,
                   // the relay will be triggered and heating pad turned on.

void setup()
{
  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);

  // Set the heating pad connections as OUTPUTS and Set pin A5 to use as a power pin for the sensor
  pinMode(sensorPositive, OUTPUT);
  pinMode(sensorNegative, OUTPUT); 
  digitalWrite(sensorNegative, LOW); //Set to ground
  digitalWrite(sensorPositive, HIGH);//Set to 3.3 to 5V

  pinMode(relayControl, OUTPUT);    //Set relay control on Arduino as output.


//Temperature Sensor:
//S to A3
//+ to A5
//- to A2

//output control pin from Arduino to relay is A4.


/*

  Relay wiring reference:
               ---------
    Signal ---|         |(x) (Unused; I think it's the latching "sticky" output that retains switch state when removed from power)
       (+) ---|  Relay  |(x) (Positive terminal of external power supply)
       (-) ---|_________|(x) (Controlled non-latching output, positive terminal)

            **Common ground**
   
 */

  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
}

void loop()
{
   long rawTemp;     // Variable to store raw temperature
   float voltage;    // Variable to store voltage calculation
   float fahrenheit; // Variable to store Fahrenheit value
   float celsius;    // Variable to store Celsius value
  
  // Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);

  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (3.3V) and divide by maximum ADC value (1023).
  voltage = rawTemp * (3.3 / 1023.0);
  Serial.print("Voltage: "); // Print voltage reading to serial monitor
  Serial.println(voltage);

  // Calculate the celsius temperature, based on that voltage.
  celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: "); // Print celcius to serial monitor
  Serial.println(celsius);

  // Use a common equation to convert celsius to Fahrenheit. F = C*9/5 + 32.
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print("Fahrenheit: "); // Print Fahrenheit to serial monitor
  Serial.println(fahrenheit); 

  //Check the temperature, and turn on the Heating Pad if it passes the threshold
  if (fahrenheit <= threshold) // If the temperature falls below the threshold:
  {
    digitalWrite(relayControl, HIGH);          //Switch relay on, turn the heating pad on
    Serial.println("Bring the heat!"); //Confirm the heating pad is on
  } 
  
  else 
  {
    digitalWrite(relayControl, LOW);  //Switch relay off, turn the heating pad off
    Serial.println("Powered off");    //Confirm the heating pad is on
  }
 
  // Print a blank line
  Serial.println();       

  // Wait 1.5 seconds between readings
  delay(1500);  
}
