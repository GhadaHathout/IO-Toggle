## GPIO Driver for STM32F4 Series

This project involves controlling GPIO pins on an STM32 microcontroller, focusing on enabling, configuring, reading, and writing to GPIO pins. Below is an overview of the code structure, followed by an explanation of each component.

### Overview of Files:
1. **gpio.c** - Implements functions to enable/disable the GPIO peripheral clock, configure GPIO pins, and read/write data to them.
2. **gpio.h** - Contains function prototypes and defines for GPIO registers, modes, and pin configurations.
3. **main.c** - Contains the main program that uses the GPIO functions to configure and control GPIO pins on port D (PD12 to PD15).

---

### **gpio.c**

- **GPIO_ClockEnable:** Enables the clock for a specific GPIO port (A to K). It modifies the `RCC_AHB1ENR` register to activate the clock for the specified GPIO.
- **GPIO_DeInit:** Resets the specified GPIO port (A to K) by toggling the appropriate reset bit in `RCC_AHB1RSTR`.
- **GPIO_Init:** Configures a GPIO pin for a specific mode (INPUT, OUTPUT, AF, or AN) and output type (Push-Pull or Open-Drain). It uses `MODER` for mode, `OTYPER` for output type, and `PUPDR` for pull-up/pull-down configuration.
- **GPIO_ReadInputDataBit:** Reads the state of a specific pin in the GPIO input data register (`IDR`).
- **GPIO_ReadInputData:** Reads the entire input data register (`IDR`) for the GPIO.
- **GPIO_WriteBit:** Writes a value (set or clear) to a specific GPIO pin by manipulating the output data register (`ODR`).
- **GPIO_Write:** Writes a value to all 16 pins of a GPIO port by setting the entire output data register (`ODR`).

---

### **gpio.h**

Defines macros for:
- GPIO ports (A to K).
- GPIO register offsets (e.g., `MODER`, `OTYPER`, `ODR`, etc.).
- GPIO pin modes (INPUT, OUTPUT, AF, AN) and output types (Push-Pull, Open-Drain).
- Pin configurations (GPIO_PIN_0 to GPIO_PIN_15).
  
Also includes function prototypes for:
- GPIO clock enable and reset.
- GPIO pin configuration, reading, and writing functions.

---

### **main.c**

In the `main()` function:
1. **GPIO Clock Enable** - The clock for GPIO port D is enabled using `GPIO_ClockEnable(GPIO_D)`.
2. **GPIO De-Initialization** - GPIO port D is deinitialized to reset its configuration using `GPIO_DeInit(GPIO_D)`.
3. **Pin Configuration** - PD12, PD13, PD14, and PD15 are configured as output pins with Push-Pull mode using `GPIO_Init()`.
4. **Main Loop** - The LEDs connected to PD12 and PD13 (typically on STM32 Nucleo boards) are turned on and off in a loop for a specified number of iterations (`NOMBRE_BOUCLES`). A delay is added after each state change using the `Delay()` function.

The delay function (`Delay()`) is a simple busy-wait loop that slows down the program for a specified number of iterations to create a visible blink effect on the LEDs.

---

### Key Registers:
- **RCC_AHB1ENR**: Controls the clock enabling for the GPIO peripherals.
- **RCC_AHB1RSTR**: Used to reset the GPIO peripherals.
- **MODER**: Defines the mode of each GPIO pin (input/output, analog, etc.).
- **OTYPER**: Defines the output type (Push-Pull or Open-Drain).
- **PUPDR**: Configures the pull-up or pull-down resistors for the GPIO pins.
- **IDR**: Reads the input data from the GPIO pins.
- **ODR**: Controls the output data for the GPIO pins.
- **BSRR**: Used to set/reset the GPIO pins.

