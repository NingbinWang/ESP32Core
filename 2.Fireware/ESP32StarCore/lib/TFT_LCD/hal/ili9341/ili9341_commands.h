#ifndef _ILI9341_COMMANDS_H_
#define _ILI9341_COMMANDS_H_

#include "../../include/config.h"

#ifdef SETUP_ILI9341
 /** ili9341 LCD driver commands */
enum ili9341_command_tabel{
   ILI9341_NOP              = 0x00,
   ILI9341_SWRESET          = 0x01,
   ILI9341_RDDIDIF          = 0x04,
   ILI9341_RDDST            = 0x09,
   ILI9341_RDDPM            = 0x0A,
   ILI9341_RDDMADCTL        = 0x0B,
   ILI9341_RDDCOLMOD        = 0x0C,
   ILI9341_RDDIM            = 0x0D,
   ILI9341_RDDSM            = 0x0E,
   ILI9341_RDDSDR           = 0x0F,
   ILI9341_SLPIN            = 0x10,
   ILI9341_SLPOUT           = 0x11,
   ILI9341_PTLON            = 0x12,
   ILI9341_NORON            = 0x13,
   ILI9341_INVOFF           = 0x20,
   ILI9341_INVON            = 0x21,
   ILI9341_GAMSET           = 0x26,
   ILI9341_DISPOFF          = 0x28,
   ILI9341_DISPON           = 0x29,
   ILI9341_CASET            = 0x2A,
   ILI9341_RASET            = 0x2B,
   ILI9341_RAMWR            = 0x2C,
   ILI9341_RGBSET           = 0x2D,
   ILI9341_RAMRD            = 0x2E,
   ILI9341_PTLAR            = 0x30,
   ILI9341_VSCRDEF          = 0x33,
   ILI9341_TEOFF            = 0x34,
   ILI9341_TEON             = 0x35,
   ILI9341_MADCTL           = 0x36,
   ILI9341_VSCRSADD         = 0x37,
   ILI9341_IDMOFF           = 0x38,
   ILI9341_IDMON            = 0x39,
   ILI9341_PIXSET           = 0x3A,
   ILI9341_RAMWRC           = 0x3C,
   ILI9341_RAMRDC           = 0x3E,
   ILI9341_TESCAN           = 0x44,
   ILI9341_RDTESCAN         = 0x45,
   ILI9341_WRDISBV          = 0x51,
   ILI9341_RDDISBV          = 0x52,
   ILI9341_WRCTRLD          = 0x53,
   ILI9341_RDCTRLD          = 0x54,
   ILI9341_WRCACE           = 0x55,
   ILI9341_RDCABC           = 0x56,
   ILI9341_WRCABCMB         = 0x5E,
   ILI9341_RDCABCMB         = 0x5F,
   ILI9341_RDID1            = 0xDA,
   ILI9341_RDID2            = 0xDB,
   ILI9341_RDID3            = 0xDC,
};

enum ili9341_Extended_Commands_Table
{
  ILI9341_IFMODE            = 0xB0,
  ILI9341_FRMCTR1           = 0xB1,
  ILI9341_FRMCTR2           = 0xB2,
  ILI9341_FRMCTR3           = 0xB3,
  ILI9341_INVTR             = 0xB4,
  ILI9341_PRCTR             = 0xB5,
  ILI9341_DISCTRL           = 0xB6,
  ILI9341_ETMOD             = 0xB7,
  ILI9341_BACTRL1           = 0xB8,
  ILI9341_BACTRL2           = 0xB9,
  ILI9341_BACTRL3           = 0xBA,
  ILI9341_BACTRL4           = 0xBB,
  ILI9341_BACTRL5           = 0xBC,
  ILI9341_BACTRL6           = 0xBD,
  ILI9341_BACTRL7           = 0xBE,
  ILI9341_BACTRL8           = 0xBF,
  ILI9341_PWCTRL1           = 0xC0,
  ILI9341_PWCTRL2           = 0xC1,
  ILI9341_VMCTRL1           = 0xC5,
  ILI9341_VMCTRL2           = 0xC7,
  ILI9341_NVMWR             = 0xD0,
  ILI9341_NVMPKEY           = 0xD1,
  ILI9341_RDNVM             = 0xD2,
  ILI9341_RDID4             = 0xD3,
  ILI9341_PGAMCTRL          = 0xE0,
  ILI9341_NGAMCTRL          = 0xE1,
  ILI9341_DGAMCTRL          = 0xE2,
  ILI9341_DGAMCTRL2         = 0xE3,
  ILI9341_IFCTL             = 0xF6,
};

enum ili9341_Extended_Commands_Table2
{
  ILI9341_PWCTLA            = 0xCB,
  ILI9341_PWCTLB            = 0xCF,
  ILI9341_DRTMCTLA          = 0xE8,
  ILI9341_DRTMCTLB          = 0xEA,
  ILI9341_POSECTL           = 0xED,
  ILI9341_EN3G              = 0xF2,
  ILI9341_PURATCTL          = 0xF7,
};

#endif

#endif
