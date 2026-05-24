# 🛠️ ATmega328P Hardware Abstraction Layer (HAL)

[![C](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c)](https://github.com/JoseManuelEnriquez/atmega328p-hal)
[![AVR](https://img.shields.io/badge/Arch-AVR-orange?style=flat-square)](https://github.com/JoseManuelEnriquez/atmega328p-hal)
[![Bare Metal](https://img.shields.io/badge/Level-Bare--Metal-red?style=flat-square)](https://github.com/JoseManuelEnriquez/atmega328p-hal)
[![Docs](https://img.shields.io/badge/Docs-Doxygen-blue?style=flat-square)](https://github.com/JoseManuelEnriquez/atmega328p-hal)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](https://opensource.org/licenses/MIT)

A lightweight, bare-metal **Hardware Abstraction Layer** for the **ATmega328P** (AVR). It provides a clean, high-level C API to drive peripherals — GPIO, ADC, Timers, USART, and interrupts — without writing a single register directly.

---

## 🤔 Why a HAL instead of direct register access?

Writing `PORTB |= (1 << PB5)` everywhere works, but it couples your application code to the hardware layout. A HAL separates the *what* from the *how*:

```c
/* Without HAL — tightly coupled, error-prone */
DDRB  |=  (1 << PB5);          // Set pin as output
PORTB |=  (1 << PB5);          // Set HIGH
PORTB &= ~(1 << PB5);          // Set LOW

/* With this HAL — readable, portable, safe */
GPIO_setPinMode(GPIO_B, PIN5, GPIO_OUTPUT);
GPIO_writePin(GPIO_B, PIN5, HIGH);
GPIO_writePin(GPIO_B, PIN5, LOW);
```

All abstractions are implemented as `static inline` functions or macros — **zero runtime overhead** compared to direct register access.

---

## ✨ Peripheral Coverage

| Module | Features |
|---|---|
| **GPIO** | Pin mode config, digital read/write, bit-banging |
| **ADC** | Single-ended conversions, reference & prescaler config |
| **TIMER** | Hardware timer setup, prescaler selection, PWM duty cycle (normal & inverted) |
| **USART** | Polling-based TX/RX, baud rate configuration |
| **EXT_INT** | Edge-triggered external interrupts (Falling / Rising / Any edge) |
| **PCINT** | Pin Change Interrupt group handling |
| **MACROS** | Shared bit-manipulation utilities used across all modules |

---

## 🚀 Quick Start

### 1. Add the HAL to your project

Clone or copy the relevant module folders into your AVR project:

```bash
git clone https://github.com/JoseManuelEnriquez/atmega328p-hal.git
```

Include the header(s) you need:

```c
#include "GPIO/GPIO.h"
#include "ADC/ADC.h"
#include "TIMER/TIMER.h"
#include "USART/USART.h"
#include "EXT_INT.h"
```

### 2. Blink an LED

```c
#include <util/delay.h>
#include "GPIO/GPIO.h"

int main(void) {
    GPIO_setPinMode(GPIO_B, PIN5, GPIO_OUTPUT);  // Arduino pin 13

    while (1) {
        GPIO_writePin(GPIO_B, PIN5, HIGH);
        _delay_ms(500);
        GPIO_writePin(GPIO_B, PIN5, LOW);
        _delay_ms(500);
    }
}
```

### 3. Read an analog sensor

```c
#include "ADC/ADC.h"

int main(void) {
    ADC_init(ADC_REF_AVCC, ADC_PRESCALER_128);

    uint16_t value = ADC_read(ADC_CH0);  // 0–1023
    // use value...
}
```

### 4. Serial output

```c
#include "USART/USART.h"

int main(void) {
    USART_init(9600);
    USART_sendString("ATmega328P HAL ready\r\n");
}
```

### 5. External interrupt

```c
#include "EXT_INT.h"

ISR(INT0_vect) {
    // handle interrupt
}

int main(void) {
    EXT_INT_enable(INT0, FALLING_EDGE);
    sei();

    while (1) { /* main loop */ }
}
```

---

## 📁 Project Structure

```
atmega328p-hal/
├── GPIO/
│   └── GPIO.h          # Digital I/O abstraction
├── ADC/
│   └── ADC.h           # Analog-to-Digital converter
├── TIMER/
│   └── TIMER.h         # Timer/PWM configuration
├── USART/
│   └── USART.h         # Serial communication
├── EXT_INT.h           # External & pin-change interrupts
├── MACROS.h            # Shared bit-manipulation macros
└── README.md
```

---

## ⚙️ Build Requirements

- **Toolchain:** `avr-gcc` + `avr-libc`
- **Flasher:** `avrdude`
- **IDE (optional):** VS Code with the AVR extension, or Microchip Studio

### Compile example

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf main.c
avr-objcopy -O ihex main.elf main.hex
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
```

---

## 📚 Documentation

All functions follow **Doxygen-style** comments. Each header includes full parameter descriptions and usage notes. To generate the HTML docs locally:

```bash
doxygen Doxyfile
```

---

## 🗺️ Roadmap

- [ ] I2C (TWI) module
- [ ] SPI module
- [ ] Watchdog timer abstraction
- [ ] Unit tests with SimAVR

---

## 📄 License

MIT License — see [LICENSE](LICENSE) for details.
