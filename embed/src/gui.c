#include "gui.h"
#include <stdio.h>

void _lcd_pset(UG_S16 x, UG_S16 y, UG_COLOR c) { draw_pixel(x, y, c); }

void gui_init() {
  init_lcd();
  UG_Init(&gui, _lcd_pset, 240, 320);
  UG_FontSelect(&FONT_6X8);

  // console setup
  UG_ConsoleSetArea(0, 200, 240, 320);
  UG_ConsoleSetForecolor(C_GREEN_YELLOW);
  UG_ConsoleSetBackcolor(C_BLACK);
}

uint16_t strwidth(char *str) {
  char ch, chwidth;
  uint16_t width = 0;
  while (*str != 0) {
    ch = *str;
    chwidth = gui.font.widths ? gui.font.widths[ch - gui.font.start_char]
                              : gui.font.char_width;
    width += chwidth + gui.char_h_space;
    str++;
  }

  return width;
}

void console_put_ch(char ch) {
  char str[2] = "\0";
  str[0] = ch;
  UG_ConsolePutString(str);
}

void console_put_number(uint16_t number) {
  char buffer[8];
  snprintf(buffer, 8, "%u; ", number);
  UG_ConsolePutString(buffer);
}

void console_put_float(float number) {
  char buffer[8];
  snprintf(buffer, 8, "%5.2f; ", number);
  UG_ConsolePutString(buffer);
}