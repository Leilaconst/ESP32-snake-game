# ESP32 Snake Game

A classic Snake game built from scratch for the ESP32, running on a 128x64 SSD1306 OLED display and controlled with an analog joystick. Score tracking, a start jingle, and sound effects are handled through a piezo buzzer.



| Wired Build | Display Mockup |
|:---:|:---:|
| ![Wired build of the ESP32 snake game](images/wired-build.jpg) | ![Digital mockup of the game display](images/display-mockup.png) |

## Features

- Classic grid-based Snake gameplay rendered on a 128x64 monochrome OLED
- Analog joystick directional control
- Push-button start and replay
- Score tracking and display
- Buzzer sound effects: start jingle, score tone, and game-over tone
- Collision detection for walls and self-collision

## Hardware

| Component | Notes |
|---|---|
| ESP32 dev board | Any standard ESP32 dev module |
| SSD1306 OLED display | 128x64, I2C |
| Analog joystick module | 2-axis with push-button switch |
| Push button | Used to start the game and replay after game over |
| Piezo buzzer | Passive buzzer for tones/jingle |

### Wiring

| Component | Pin | ESP32 GPIO |
|---|---|---|
| OLED | SDA | 21 |
| OLED | SCL | 22 |
| OLED | I2C Address | 0x3C |
| Joystick | X-axis (analog) | 34 |
| Joystick | Y-axis (analog) | 35 |
| Joystick | Switch (SW) | 33 |
| Start/Replay Button | Digital in (pull-up) | 4 |
| Buzzer | Output | 12 |

## Software & Libraries

Built in the Arduino IDE. Install the following libraries via the Library Manager before uploading:

- `Adafruit_GFX`
- `Adafruit_SSD1306`
- `Wire` (bundled with the ESP32 board package)

### Setup

1. Install the [ESP32 board package](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) in the Arduino IDE.
2. Install the libraries listed above.
3. Clone this repo and open `game.ino`.
4. Select your ESP32 board and port, then upload.
5. Wire up the components per the table above.

## How to Play

1. Power on the board — the OLED displays the "SNAKE" start screen.
2. Press the start button to begin (a short jingle plays first).
3. Steer the snake with the joystick; it moves continuously on a fixed interval.
4. Eat food tiles to grow and increase your score.
5. Avoid colliding with the walls or the snake's own body.
6. On game over, press the button again to replay.

## Project Structure

```
├── game.ino        # Main game loop, setup, and input handling
├── snake.cpp/.h     # Snake movement, growth, and collision logic
├── food.cpp/.h       # Food spawning logic
├── score.cpp/.h       # Score tracking and display
├── joystick.cpp/.h     # Joystick input reading
├── buzzer.cpp/.h        # Buzzer tones and start jingle
├── pitches.h              # Musical note frequency definitions
├── display.h                # Display and grid configuration constants
└── point.h                    # Shared point/coordinate struct
```

## Possible Improvements

- Adjustable difficulty / speed levels
- High score persistence (EEPROM/NVS)
- Menu screen for game options
