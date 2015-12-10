#define LIGHT_PIN  0
#define SENSOR_PIN A2
#define BUTTON_PIN A1
#define MAX_RANGE  7  // This is in feet

#define FEET_TO_INCHES(feet) (feet * 12.0f)
#define INCHES_TO_MV(inches) (inches * 10.0f) // 10 mV/in
#define MV_TO_VOLTS(millivs) (millivs * 0.001f)
#define REMAP_VOLTS(orvolts) (int(orvolts * 204.0f)) // 204 is 1024/5
#define FEET_TO_ANALOG(feet) (REMAP_VOLTS(MV_TO_VOLTS(INCHES_TO_MV(FEET_TO_INCHES(feet)))))
#define MAX_ANALOG_INPUT FEET_TO_ANALOG(MAX_RANGE)

void setup()
{
	pinMode(BUTTON_PIN, INPUT);
	pinMode(SENSOR_PIN, INPUT);
	pinMode(LIGHT_PIN, OUTPUT);
}

void loop()
{
	if (	digitalRead(BUTTON_PIN) == HIGH &&
		analogRead(SENSOR_PIN) < MAX_ANALOG_INPUT )
	{
		digitalWrite(LIGHT_PIN, HIGH);
	}
	else
	{
		digitalWrite(LIGHT_PIN, LOW);
	}
	delay(50);
}
