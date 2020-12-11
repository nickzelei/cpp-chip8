#include "chip8.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char chip8_fontset[80] =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, //0
        0x20, 0x60, 0x20, 0x20, 0x70, //1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
        0x90, 0x90, 0xF0, 0x10, 0x10, //4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
        0xF0, 0x10, 0x20, 0x40, 0x40, //7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
        0xF0, 0x90, 0xF0, 0x90, 0x90, //A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
        0xF0, 0x80, 0x80, 0x80, 0xF0, //C
        0xE0, 0x90, 0x90, 0x90, 0xE0, //D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
        0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

chip8::chip8()
{
  // empty
}

chip8::~chip8()
{
  // empty
}

void chip8::init()
{
  pc = 0x200; // Program counter starts at 0x200
  opcode = 0; // Reset current opcode
  I = 0;      // Reset current register
  sp = 0;     // Reset stack pointer

  // Clear display
  for (int i = 0; i < 64 * 32; ++i)
  {
    gfx[i] = 0;
  }

  // Clear stack
  for (int i = 0; i < 16; ++i)
  {
    stack[i] = 0;
  }

  for (int i = 0; i < 16; ++i)
  {
    key[i] = 0;
  }

  // Clear registers V0-VF
  for (int i = 0; i < 16; ++i)
  {
    V[i] = 0;
  }

  // Clear memory
  for (int i = 0; i < 4096; ++i)
  {
    memory[i] = 0;
  }

  // Load fontset
  for (int i = 0; i < 80; ++i)
  {
    memory[i] = chip8_fontset[i];
  }

  delay_timer = 0;
  sound_timer = 0;

  drawFlag = true;

  srand(time(NULL));
}

bool chip8::load(const char *filename)
{
  init();
  return true;
}

void chip8::emulate()
{
  //
}
