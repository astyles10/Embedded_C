#include "stm32f4xx_conf.h"
#define STM32F40XX

int main (void) {

  // Configure AHB/APB1/APB2 Clocks
  RCC->CR |= 1 << 16; // Turn HSE on
  while (!(RCC->CR & (1 << 17))); // Wait for HSE ready
  RCC->CFGR = 0x0000001; // Set HSE as SYSCLK

  // Enable clock to the peripheral devices
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  // Configure GPIOx registers
  GPIOD->MODER |= (1 << 26); // Set pin 13 to output

  while (1) {
    GPIOD->ODR |= (1 << 13);
  }
}