int pumps[] = { 2,3,4,5 };

int moistureSensors[] = { 2,3,4,5 };

void setup() {
	// Serial Begin so we can see the data from the moisture sensor in our serial input window.
	Serial.begin(9600);

	// setting the led pins to outputs
	pinMode(pumps[0], OUTPUT);
	pinMode(pumps[1], OUTPUT);
	pinMode(pumps[2], OUTPUT);
	pinMode(pumps[3], OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

	int sensorValue;
	//int i = 0; // test purpose, replace by for-loop for prod
	int potarValue;
	int pumpValue;

	for (int i = 0; i < 4; i++)
	{
		// read the input on analog pin

		sensorValue = map(analogRead(moistureSensors[i]), 350, 1010, 0, 100);

		if ((i % 2) == 0)
			potarValue = map(analogRead(0), 24, 1014, 0, 100);
		else
			potarValue = map(analogRead(1), 24, 1014, 0, 100);

		// print out the value you read: Serial.println(sensorValue);
		/*Serial.println("POTAR");
		Serial.println(potarValue);
		Serial.println("SENSOR");
		Serial.println(sensorValue);*/

		if (potarValue < sensorValue)
		{
			digitalWrite(pumps[i], LOW);
			Serial.println("AFTER LOW");
			//activate the pump for 2 minutes
			for (int j = 0; j < 120; j++)
			{
				delay(1000);
			}
			Serial.println("BEFORE HIGH");
			digitalWrite(pumps[i], HIGH);
			do {
				pumpValue = digitalRead(pumps[i]);
			} while (pumpValue != HIGH);
		}

		delay(1000);        // delay 1 second between reads
	}

	for (int x = 0; x < 1800; x++) // sleep for 30 minutes between two check of sensors
	{
		delay(1000);
	}


}