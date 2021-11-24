#ifndef _ST7789_COMMANDS_H_
#define _ST7789_COMMANDS_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "../../include/config.h"
#ifdef SETUP_ST7789V2
/** st7789 LCD driver commands */
enum st7789_System_Commands1
{
   ST7789_NOP              = 0x00, 
   ST7789_SWRESET          = 0x01, 
   ST7789_RDDID            = 0x04,
   ST7789_RDDST            = 0x09,
   ST7789_RDDPM            = 0x0A,
   ST7789_RDDMADCTL        = 0x0B,
   ST7789_RDDCOLMOD        = 0x0C,
   ST7789_RDDIM            = 0x0D,
   ST7789_RDDSM            = 0x0E,
   ST7789_RDDSDR           = 0x0F,
   ST7789_SLPIN            = 0x10,
   ST7789_SLPOUT           = 0x11,
   ST7789_PTLON            = 0x12,
   ST7789_NORON            = 0x13,
   ST7789_INVOFF           = 0x20,
   ST7789_INVON            = 0x21,
   ST7789_GAMSET           = 0x26,
   ST7789_DISPOFF          = 0x28,
   ST7789_DISPON           = 0x29,
   ST7789_CASET            = 0x2A,
   ST7789_RASET            = 0x2B,
   ST7789_RAMWR            = 0x2C,
   ST7789_RAMRD            = 0x2E,
   ST7789_PTLAR            = 0x30,
   ST7789_VSCRDEF          = 0x33,
   ST7789_TEOFF            = 0x34,
   ST7789_TEON             = 0x35,
   ST7789_MADCTL           = 0x36,
   ST7789_VSCRSADD         = 0x37,
   ST7789_IDMOFF           = 0x38,
   ST7789_IDMON            = 0x39,
   ST7789_COLMOD           = 0x3A,
   ST7789_RAMWRC           = 0x3C,
   ST7789_RAMRDC           = 0x3E,
   ST7789_TESCAN           = 0x44,
   ST7789_RDTESCAN         = 0x45,
   ST7789_WRDISBV          = 0x51,
   ST7789_RDDISBV          = 0x52,
   ST7789_WRCTRLD          = 0x53,
   ST7789_RDCTRLD          = 0x54,
   ST7789_WRCACE           = 0x55,
   ST7789_RDCABC           = 0x56,
   ST7789_WRCABCMB         = 0x5E,
   ST7789_RDCABCMB         = 0x5F,
   ST7789_RDABCSDR         = 0x68,
   ST7789_RDID1            = 0xDA,
   ST7789_RDID2            = 0xDB,
   ST7789_RDID3            = 0xDC,
};

enum st7789_System_Commands2
{
  ST7789_RAMCTRL          = 0xB0,
  ST7789_RGBCTRL          = 0xB1,
  ST7789_PORCTRL          = 0xB2,
  ST7789_FRCTRL1          = 0xB3,
  ST7789_PARCTRL          = 0xB5,
  ST7789_GCTRL            = 0xB7,
  ST7789_GTADJ            = 0xB8,
  ST7789_DGMEN            = 0xBA,
  ST7789_VCOMS            = 0xBB,
  ST7789_POWSAVE          = 0xBC,
  ST7789_DLPOFFSAVE       = 0xBD,
  ST7789_LCMCTRL          = 0xC0,
  ST7789_IDSET            = 0xC1,
  ST7789_VDVVRHEN         = 0xC2,
  ST7789_VRHS             = 0xC3,
  ST7789_VDVSET           = 0xC4,
  ST7789_VCMOFSET         = 0xC5,
  ST7789_FRCTR2           = 0xC6,
  ST7789_CABCCTRL         = 0xC7,
  ST7789_REGSEL1          = 0xC8,
  ST7789_REGSEL2          = 0xCA,
  ST7789_PWMFRSEL         = 0xCC,
  ST7789_PWCTRL1          = 0xD0,
  ST7789_VAPVANEN         = 0xD2,
  ST7789_CMD2EN1          = 0xDF,
  ST7789_CMD2EN2          = 0x5A,
  ST7789_CMD2EN3          = 0x69,
  ST7789_CMD2EN4          = 0x02,
  ST7789_PVGAMCTRL        = 0xE0,
  ST7789_NVGAMCTRL        = 0xE1,
  ST7789_DGMLUTR          = 0xE2,
  ST7789_DGMLUTB          = 0xE3,
  ST7789_GATECTRL         = 0xE4,
  ST7789_SPI2EN           = 0xE7,
  ST7789_PWCTRL2          = 0xE8,
  ST7789_EQCTRL           = 0xE9,
  ST7789_PROMCTRL         = 0xEC,
  ST7789_PROMEN           = 0xFA,
  ST7789_NVMSET           = 0xFC,
  ST7789_PROMACT          = 0xFE,
};

#endif
#ifdef __cplusplus
}
#endif

#endif
