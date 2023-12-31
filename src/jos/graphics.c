#include <rp6502.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>

void clear()
{
    unsigned i;
    RIA.addr0 = 0;
    RIA.step0 = 1;
    for (i = 0; i < 57600u; i++)
        RIA.rw0 = 0;        
}

void box(unsigned qty)
{
    srand(6);
    while (qty--)
    {
        int color, x1, y1, x2, y2, x, y;
        color = rand();
        x1 = ((uint32_t)rand() * 320) >> 15;
        y1 = ((uint32_t)rand() * 180) >> 15;
        x2 = ((uint32_t)rand() * 320) >> 15;
        y2 = ((uint32_t)rand() * 180) >> 15;
        if (x1 > x2)
        {
            x = x1;
            x1 = x2;
            x2 = x;
        }
        if (y1 > y2)
        {
            y = y1;
            y1 = y2;
            y2 = y;
        }
        RIA.step1 = 0;
        for (y = y1; y < y2; y++)
        {
            RIA.addr0 = 320 * y + x1;
            for (x = x1; x < x2; x++)
            {
                RIA.rw0 = color;
            }
        }
    }
}

void scroll(bool x_scroll, bool y_scroll)
{
    int x = 0, y = 0;
    uint8_t v = RIA.vsync;
    while (1)
    {
        if (RIA.vsync == v)
            continue;
        v = RIA.vsync;           

        if (x_scroll)
        {
            xram0_struct_set(0xFF00, vga_mode3_config_t, x_pos_px, x);
            if (++x >= 320)
                x = -320;
        }
        if (y_scroll)
        {
            xram0_struct_set(0xFF00, vga_mode3_config_t, y_pos_px, y);
            if (++y >= 180)
                y = -180;
        }

    }
}

void main()
{
    puts("Hello, World.");

    xreg(1, 0, 0, 2); // Canvas

    clear();

    xram0_struct_set(0xFF00, vga_mode3_config_t, x_wrap, true);
    xram0_struct_set(0xFF00, vga_mode3_config_t, y_wrap, true);
    xram0_struct_set(0xFF00, vga_mode3_config_t, x_pos_px, 100);
    xram0_struct_set(0xFF00, vga_mode3_config_t, y_pos_px, -100);
    xram0_struct_set(0xFF00, vga_mode3_config_t, width_px, 320);
    xram0_struct_set(0xFF00, vga_mode3_config_t, height_px, 180);
    xram0_struct_set(0xFF00, vga_mode3_config_t, xram_data_ptr, 0x0000);
    xram0_struct_set(0xFF00, vga_mode3_config_t, xram_palette_ptr, 0xFFFF);

    xreg(1, 0, 1, 3, 2, 0xFF00); // Mode 3

    box(10);
    scroll(true, true);
}
