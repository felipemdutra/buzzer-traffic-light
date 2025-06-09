enum TrafficLightState {
        RED,
        YELLOW,
        GREEN
};

enum Pins {
        RED_PIN = 8,
        YELLOW_PIN,
        GREEN_PIN,
        BUZZER_PIN
};

uint8_t curr_state = RED;

unsigned long last_changed_state_time = 0;

constexpr int red_duration = 1000 * 9;
constexpr int yellow_duration = 1000 * 2;
constexpr int green_duration = 1000 * 6;

constexpr int beep_interval = 500; /* buzzer should beep every 500ms */

bool buzzer_on = false;

void setup()
{
        /* setup pins */
}

void loop()
{
        /* do some kool shit */ 
        unsigned long curr_time = millis();

        if (curr_state == RED && curr_time - last_changed_state_time >= red_duration) {
                curr_state = GREEN;
                last_changed_state_time = curr_time;
                buzzer_on = true;
                digitalWrite(BUZZER_PIN, HIGH);
        }
}

