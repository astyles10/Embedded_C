#include "./Includes/stm32f4xx.h"

int main (void) {
  RCC->CR |= 1 << 16; // Turn HSE on
  RCC->CFGR = 0x0000001;
  RCC->AHB1ENR |= 1 << 3; // Turn on GPIO D
  GPIOD->MODER |= 0x01000000; // Set pin 12 to output
  GPIOD->MODER |= 0x04000000; // Set pin 13 to output
  GPIOD->MODER |= 0x10000000; // Set pin 14 to output
  GPIOD->MODER |= 0x40000000; // Set pin 15 to output
}