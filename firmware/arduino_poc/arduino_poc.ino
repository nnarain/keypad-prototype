#define COL1 4
#define COL2 5
#define COL3 6
#define NUM_COLS 3

#define ROW1 7
#define ROW2 8
#define ROW3 9
#define NUM_ROWS 3

static const int COL_PINS[NUM_COLS] = {COL1, COL2, COL3};
static const int ROW_PINS[NUM_ROWS] = {ROW1, ROW2, ROW3};

static const int BUTTONS[NUM_COLS][NUM_ROWS] = { {7, 4, 1}, {8, 5, 2}, {9, 6, 3} };

void setup() {
  //pinMode(COL1, OUTPUT);
  //pinMode(ROW1, INPUT);

  for (int i = 0; i < NUM_COLS; ++i)
  {
    pinMode(COL_PINS[i], OUTPUT);
  }

  for (int i = 0; i < NUM_COLS; ++i)
  {
    pinMode(ROW_PINS[i], INPUT);
  }

  Serial.begin(115200);
}

void loop() {
  for (int col = 0; col < NUM_COLS; ++col)
  {
    // Select the column by pulling it LOW
    digitalWrite(COL_PINS[col], LOW);

    for (int row = 0; row < NUM_ROWS; ++row)
    {
      // Button pressed are a LOW signal
      if (digitalRead(ROW_PINS[row]) == LOW)
      {
        Serial.print("Pressed ");
        Serial.println(BUTTONS[col][row]);
      }
    }

    //De-select column
    digitalWrite(COL_PINS[col], HIGH);
  }
}
