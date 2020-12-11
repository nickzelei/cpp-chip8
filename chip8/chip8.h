class chip8
{
public:
  chip8();
  ~chip8();

  bool drawFlag;

  void emulate();
  bool load(const char *filename);

  unsigned char gfx[64 * 32]; // 2048 pixels
  unsigned char key[16];

private:
  unsigned short pc;     // Program Counter
  unsigned short opcode; // Current opcode
  unsigned short I;      // Index register
  unsigned short sp;     // Stack Pointer

  unsigned char V[16];         // V-regs (V0-VF)
  unsigned short stack[16];    // Stack (16 levels)
  unsigned short memory[4096]; // Memory (size=4k)

  unsigned char delay_timer; // Delay timer
  unsigned char sound_timer; // Sound timer

  void init();
};
