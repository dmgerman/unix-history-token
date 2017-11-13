begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_define
define|#
directive|define
name|PINMUX_PIN
parameter_list|(
name|no
parameter_list|,
name|func
parameter_list|,
name|ioset
parameter_list|)
define|\
value|(((no)& 0xffff) | (((func)& 0xf)<< 16) | (((ioset)& 0xff)<< 20))
end_define

begin_define
define|#
directive|define
name|PIN_PA0
value|0
end_define

begin_define
define|#
directive|define
name|PIN_PA0__GPIO
value|PINMUX_PIN(PIN_PA0, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA0__SDMMC0_CK
value|PINMUX_PIN(PIN_PA0, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA0__QSPI0_SCK
value|PINMUX_PIN(PIN_PA0, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA0__D0
value|PINMUX_PIN(PIN_PA0, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA1
value|1
end_define

begin_define
define|#
directive|define
name|PIN_PA1__GPIO
value|PINMUX_PIN(PIN_PA1, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA1__SDMMC0_CMD
value|PINMUX_PIN(PIN_PA1, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA1__QSPI0_CS
value|PINMUX_PIN(PIN_PA1, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA1__D1
value|PINMUX_PIN(PIN_PA1, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA2
value|2
end_define

begin_define
define|#
directive|define
name|PIN_PA2__GPIO
value|PINMUX_PIN(PIN_PA2, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA2__SDMMC0_DAT0
value|PINMUX_PIN(PIN_PA2, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA2__QSPI0_IO0
value|PINMUX_PIN(PIN_PA2, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA2__D2
value|PINMUX_PIN(PIN_PA2, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA3
value|3
end_define

begin_define
define|#
directive|define
name|PIN_PA3__GPIO
value|PINMUX_PIN(PIN_PA3, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA3__SDMMC0_DAT1
value|PINMUX_PIN(PIN_PA3, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA3__QSPI0_IO1
value|PINMUX_PIN(PIN_PA3, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA3__D3
value|PINMUX_PIN(PIN_PA3, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA4
value|4
end_define

begin_define
define|#
directive|define
name|PIN_PA4__GPIO
value|PINMUX_PIN(PIN_PA4, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA4__SDMMC0_DAT2
value|PINMUX_PIN(PIN_PA4, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA4__QSPI0_IO2
value|PINMUX_PIN(PIN_PA4, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA4__D4
value|PINMUX_PIN(PIN_PA4, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA5
value|5
end_define

begin_define
define|#
directive|define
name|PIN_PA5__GPIO
value|PINMUX_PIN(PIN_PA5, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA5__SDMMC0_DAT3
value|PINMUX_PIN(PIN_PA5, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA5__QSPI0_IO3
value|PINMUX_PIN(PIN_PA5, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA5__D5
value|PINMUX_PIN(PIN_PA5, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA6
value|6
end_define

begin_define
define|#
directive|define
name|PIN_PA6__GPIO
value|PINMUX_PIN(PIN_PA6, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA6__SDMMC0_DAT4
value|PINMUX_PIN(PIN_PA6, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA6__QSPI1_SCK
value|PINMUX_PIN(PIN_PA6, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA6__TIOA5
value|PINMUX_PIN(PIN_PA6, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA6__FLEXCOM2_IO0
value|PINMUX_PIN(PIN_PA6, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA6__D6
value|PINMUX_PIN(PIN_PA6, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA7
value|7
end_define

begin_define
define|#
directive|define
name|PIN_PA7__GPIO
value|PINMUX_PIN(PIN_PA7, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA7__SDMMC0_DAT5
value|PINMUX_PIN(PIN_PA7, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA7__QSPI1_IO0
value|PINMUX_PIN(PIN_PA7, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA7__TIOB5
value|PINMUX_PIN(PIN_PA7, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA7__FLEXCOM2_IO1
value|PINMUX_PIN(PIN_PA7, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA7__D7
value|PINMUX_PIN(PIN_PA7, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA8
value|8
end_define

begin_define
define|#
directive|define
name|PIN_PA8__GPIO
value|PINMUX_PIN(PIN_PA8, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA8__SDMMC0_DAT6
value|PINMUX_PIN(PIN_PA8, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA8__QSPI1_IO1
value|PINMUX_PIN(PIN_PA8, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA8__TCLK5
value|PINMUX_PIN(PIN_PA8, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA8__FLEXCOM2_IO2
value|PINMUX_PIN(PIN_PA8, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA8__NWE_NANDWE
value|PINMUX_PIN(PIN_PA8, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA9
value|9
end_define

begin_define
define|#
directive|define
name|PIN_PA9__GPIO
value|PINMUX_PIN(PIN_PA9, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA9__SDMMC0_DAT7
value|PINMUX_PIN(PIN_PA9, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA9__QSPI1_IO2
value|PINMUX_PIN(PIN_PA9, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA9__TIOA4
value|PINMUX_PIN(PIN_PA9, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA9__FLEXCOM2_IO3
value|PINMUX_PIN(PIN_PA9, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA9__NCS3
value|PINMUX_PIN(PIN_PA9, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA10
value|10
end_define

begin_define
define|#
directive|define
name|PIN_PA10__GPIO
value|PINMUX_PIN(PIN_PA10, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA10__SDMMC0_RSTN
value|PINMUX_PIN(PIN_PA10, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA10__QSPI1_IO3
value|PINMUX_PIN(PIN_PA10, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA10__TIOB4
value|PINMUX_PIN(PIN_PA10, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA10__FLEXCOM2_IO4
value|PINMUX_PIN(PIN_PA10, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA10__A21_NANDALE
value|PINMUX_PIN(PIN_PA10, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA11
value|11
end_define

begin_define
define|#
directive|define
name|PIN_PA11__GPIO
value|PINMUX_PIN(PIN_PA11, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA11__SDMMC0_VDDSEL
value|PINMUX_PIN(PIN_PA11, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA11__QSPI1_CS
value|PINMUX_PIN(PIN_PA11, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA11__TCLK4
value|PINMUX_PIN(PIN_PA11, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA11__A22_NANDCLE
value|PINMUX_PIN(PIN_PA11, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA12
value|12
end_define

begin_define
define|#
directive|define
name|PIN_PA12__GPIO
value|PINMUX_PIN(PIN_PA12, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA12__SDMMC0_WP
value|PINMUX_PIN(PIN_PA12, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA12__IRQ
value|PINMUX_PIN(PIN_PA12, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA12__NRD_NANDOE
value|PINMUX_PIN(PIN_PA12, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA13
value|13
end_define

begin_define
define|#
directive|define
name|PIN_PA13__GPIO
value|PINMUX_PIN(PIN_PA13, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA13__SDMMC0_CD
value|PINMUX_PIN(PIN_PA13, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA13__FLEXCOM3_IO1
value|PINMUX_PIN(PIN_PA13, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA13__D8
value|PINMUX_PIN(PIN_PA13, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA14
value|14
end_define

begin_define
define|#
directive|define
name|PIN_PA14__GPIO
value|PINMUX_PIN(PIN_PA14, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__SPI0_SPCK
value|PINMUX_PIN(PIN_PA14, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__TK1
value|PINMUX_PIN(PIN_PA14, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__QSPI0_SCK
value|PINMUX_PIN(PIN_PA14, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__I2SC1_MCK
value|PINMUX_PIN(PIN_PA14, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__FLEXCOM3_IO2
value|PINMUX_PIN(PIN_PA14, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA14__D9
value|PINMUX_PIN(PIN_PA14, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA15
value|15
end_define

begin_define
define|#
directive|define
name|PIN_PA15__GPIO
value|PINMUX_PIN(PIN_PA15, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__SPI0_MOSI
value|PINMUX_PIN(PIN_PA15, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__TF1
value|PINMUX_PIN(PIN_PA15, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__QSPI0_CS
value|PINMUX_PIN(PIN_PA15, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__I2SC1_CK
value|PINMUX_PIN(PIN_PA15, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__FLEXCOM3_IO0
value|PINMUX_PIN(PIN_PA15, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA15__D10
value|PINMUX_PIN(PIN_PA15, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA16
value|16
end_define

begin_define
define|#
directive|define
name|PIN_PA16__GPIO
value|PINMUX_PIN(PIN_PA16, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__SPI0_MISO
value|PINMUX_PIN(PIN_PA16, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__TD1
value|PINMUX_PIN(PIN_PA16, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__QSPI0_IO0
value|PINMUX_PIN(PIN_PA16, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__I2SC1_WS
value|PINMUX_PIN(PIN_PA16, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__FLEXCOM3_IO3
value|PINMUX_PIN(PIN_PA16, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA16__D11
value|PINMUX_PIN(PIN_PA16, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA17
value|17
end_define

begin_define
define|#
directive|define
name|PIN_PA17__GPIO
value|PINMUX_PIN(PIN_PA17, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__SPI0_NPCS0
value|PINMUX_PIN(PIN_PA17, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__RD1
value|PINMUX_PIN(PIN_PA17, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__QSPI0_IO1
value|PINMUX_PIN(PIN_PA17, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__I2SC1_DI0
value|PINMUX_PIN(PIN_PA17, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__FLEXCOM3_IO4
value|PINMUX_PIN(PIN_PA17, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA17__D12
value|PINMUX_PIN(PIN_PA17, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA18
value|18
end_define

begin_define
define|#
directive|define
name|PIN_PA18__GPIO
value|PINMUX_PIN(PIN_PA18, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__SPI0_NPCS1
value|PINMUX_PIN(PIN_PA18, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__RK1
value|PINMUX_PIN(PIN_PA18, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__QSPI0_IO2
value|PINMUX_PIN(PIN_PA18, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__I2SC1_DO0
value|PINMUX_PIN(PIN_PA18, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__SDMMC1_DAT0
value|PINMUX_PIN(PIN_PA18, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA18__D13
value|PINMUX_PIN(PIN_PA18, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA19
value|19
end_define

begin_define
define|#
directive|define
name|PIN_PA19__GPIO
value|PINMUX_PIN(PIN_PA19, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__SPI0_NPCS2
value|PINMUX_PIN(PIN_PA19, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__RF1
value|PINMUX_PIN(PIN_PA19, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__QSPI0_IO3
value|PINMUX_PIN(PIN_PA19, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__TIOA0
value|PINMUX_PIN(PIN_PA19, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__SDMMC1_DAT1
value|PINMUX_PIN(PIN_PA19, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA19__D14
value|PINMUX_PIN(PIN_PA19, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA20
value|20
end_define

begin_define
define|#
directive|define
name|PIN_PA20__GPIO
value|PINMUX_PIN(PIN_PA20, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA20__SPI0_NPCS3
value|PINMUX_PIN(PIN_PA20, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA20__TIOB0
value|PINMUX_PIN(PIN_PA20, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA20__SDMMC1_DAT2
value|PINMUX_PIN(PIN_PA20, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA20__D15
value|PINMUX_PIN(PIN_PA20, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA21
value|21
end_define

begin_define
define|#
directive|define
name|PIN_PA21__GPIO
value|PINMUX_PIN(PIN_PA21, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA21__IRQ
value|PINMUX_PIN(PIN_PA21, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA21__PCK2
value|PINMUX_PIN(PIN_PA21, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA21__TCLK0
value|PINMUX_PIN(PIN_PA21, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA21__SDMMC1_DAT3
value|PINMUX_PIN(PIN_PA21, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA21__NANDRDY
value|PINMUX_PIN(PIN_PA21, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA22
value|22
end_define

begin_define
define|#
directive|define
name|PIN_PA22__GPIO
value|PINMUX_PIN(PIN_PA22, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__FLEXCOM1_IO2
value|PINMUX_PIN(PIN_PA22, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__D0
value|PINMUX_PIN(PIN_PA22, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__TCK
value|PINMUX_PIN(PIN_PA22, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__SPI1_SPCK
value|PINMUX_PIN(PIN_PA22, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__SDMMC1_CK
value|PINMUX_PIN(PIN_PA22, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA22__QSPI0_SCK
value|PINMUX_PIN(PIN_PA22, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA23
value|23
end_define

begin_define
define|#
directive|define
name|PIN_PA23__GPIO
value|PINMUX_PIN(PIN_PA23, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA23__FLEXCOM1_IO1
value|PINMUX_PIN(PIN_PA23, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA23__D1
value|PINMUX_PIN(PIN_PA23, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA23__TDI
value|PINMUX_PIN(PIN_PA23, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PA23__SPI1_MOSI
value|PINMUX_PIN(PIN_PA23, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA23__QSPI0_CS
value|PINMUX_PIN(PIN_PA23, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA24
value|24
end_define

begin_define
define|#
directive|define
name|PIN_PA24__GPIO
value|PINMUX_PIN(PIN_PA24, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA24__FLEXCOM1_IO0
value|PINMUX_PIN(PIN_PA24, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA24__D2
value|PINMUX_PIN(PIN_PA24, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA24__TDO
value|PINMUX_PIN(PIN_PA24, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PA24__SPI1_MISO
value|PINMUX_PIN(PIN_PA24, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA24__QSPI0_IO0
value|PINMUX_PIN(PIN_PA24, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA25
value|25
end_define

begin_define
define|#
directive|define
name|PIN_PA25__GPIO
value|PINMUX_PIN(PIN_PA25, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA25__FLEXCOM1_IO3
value|PINMUX_PIN(PIN_PA25, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA25__D3
value|PINMUX_PIN(PIN_PA25, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA25__TMS
value|PINMUX_PIN(PIN_PA25, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PA25__SPI1_NPCS0
value|PINMUX_PIN(PIN_PA25, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA25__QSPI0_IO1
value|PINMUX_PIN(PIN_PA25, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA26
value|26
end_define

begin_define
define|#
directive|define
name|PIN_PA26__GPIO
value|PINMUX_PIN(PIN_PA26, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA26__FLEXCOM1_IO4
value|PINMUX_PIN(PIN_PA26, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA26__D4
value|PINMUX_PIN(PIN_PA26, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA26__NTRST
value|PINMUX_PIN(PIN_PA26, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PA26__SPI1_NPCS1
value|PINMUX_PIN(PIN_PA26, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA26__QSPI0_IO2
value|PINMUX_PIN(PIN_PA26, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA27
value|27
end_define

begin_define
define|#
directive|define
name|PIN_PA27__GPIO
value|PINMUX_PIN(PIN_PA27, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__TIOA1
value|PINMUX_PIN(PIN_PA27, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__D5
value|PINMUX_PIN(PIN_PA27, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__SPI0_NPCS2
value|PINMUX_PIN(PIN_PA27, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__SPI1_NPCS2
value|PINMUX_PIN(PIN_PA27, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__SDMMC1_RSTN
value|PINMUX_PIN(PIN_PA27, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA27__QSPI0_IO3
value|PINMUX_PIN(PIN_PA27, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PA28
value|28
end_define

begin_define
define|#
directive|define
name|PIN_PA28__GPIO
value|PINMUX_PIN(PIN_PA28, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__TIOB1
value|PINMUX_PIN(PIN_PA28, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__D6
value|PINMUX_PIN(PIN_PA28, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__SPI0_NPCS3
value|PINMUX_PIN(PIN_PA28, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__SPI1_NPCS3
value|PINMUX_PIN(PIN_PA28, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__SDMMC1_CMD
value|PINMUX_PIN(PIN_PA28, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA28__CLASSD_L0
value|PINMUX_PIN(PIN_PA28, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA29
value|29
end_define

begin_define
define|#
directive|define
name|PIN_PA29__GPIO
value|PINMUX_PIN(PIN_PA29, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA29__TCLK1
value|PINMUX_PIN(PIN_PA29, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA29__D7
value|PINMUX_PIN(PIN_PA29, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA29__SPI0_NPCS1
value|PINMUX_PIN(PIN_PA29, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA29__SDMMC1_WP
value|PINMUX_PIN(PIN_PA29, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA29__CLASSD_L1
value|PINMUX_PIN(PIN_PA29, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA30
value|30
end_define

begin_define
define|#
directive|define
name|PIN_PA30__GPIO
value|PINMUX_PIN(PIN_PA30, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA30__NWE_NANDWE
value|PINMUX_PIN(PIN_PA30, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA30__SPI0_NPCS0
value|PINMUX_PIN(PIN_PA30, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA30__PWMH0
value|PINMUX_PIN(PIN_PA30, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA30__SDMMC1_CD
value|PINMUX_PIN(PIN_PA30, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA30__CLASSD_L2
value|PINMUX_PIN(PIN_PA30, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA31
value|31
end_define

begin_define
define|#
directive|define
name|PIN_PA31__GPIO
value|PINMUX_PIN(PIN_PA31, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PA31__NCS3
value|PINMUX_PIN(PIN_PA31, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA31__SPI0_MISO
value|PINMUX_PIN(PIN_PA31, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PA31__PWML0
value|PINMUX_PIN(PIN_PA31, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PA31__CLASSD_L3
value|PINMUX_PIN(PIN_PA31, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB0
value|32
end_define

begin_define
define|#
directive|define
name|PIN_PB0__GPIO
value|PINMUX_PIN(PIN_PB0, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB0__A21_NANDALE
value|PINMUX_PIN(PIN_PB0, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB0__SPI0_MOSI
value|PINMUX_PIN(PIN_PB0, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB0__PWMH1
value|PINMUX_PIN(PIN_PB0, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB1
value|33
end_define

begin_define
define|#
directive|define
name|PIN_PB1__GPIO
value|PINMUX_PIN(PIN_PB1, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB1__A22_NANDCLE
value|PINMUX_PIN(PIN_PB1, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB1__SPI0_SPCK
value|PINMUX_PIN(PIN_PB1, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB1__PWML1
value|PINMUX_PIN(PIN_PB1, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB1__CLASSD_R0
value|PINMUX_PIN(PIN_PB1, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB2
value|34
end_define

begin_define
define|#
directive|define
name|PIN_PB2__GPIO
value|PINMUX_PIN(PIN_PB2, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB2__NRD_NANDOE
value|PINMUX_PIN(PIN_PB2, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB2__PWMFI0
value|PINMUX_PIN(PIN_PB2, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB2__CLASSD_R1
value|PINMUX_PIN(PIN_PB2, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB3
value|35
end_define

begin_define
define|#
directive|define
name|PIN_PB3__GPIO
value|PINMUX_PIN(PIN_PB3, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB3__URXD4
value|PINMUX_PIN(PIN_PB3, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB3__D8
value|PINMUX_PIN(PIN_PB3, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB3__IRQ
value|PINMUX_PIN(PIN_PB3, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB3__PWMEXTRG0
value|PINMUX_PIN(PIN_PB3, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB3__CLASSD_R2
value|PINMUX_PIN(PIN_PB3, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB4
value|36
end_define

begin_define
define|#
directive|define
name|PIN_PB4__GPIO
value|PINMUX_PIN(PIN_PB4, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB4__UTXD4
value|PINMUX_PIN(PIN_PB4, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB4__D9
value|PINMUX_PIN(PIN_PB4, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB4__FIQ
value|PINMUX_PIN(PIN_PB4, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PB4__CLASSD_R3
value|PINMUX_PIN(PIN_PB4, 6, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB5
value|37
end_define

begin_define
define|#
directive|define
name|PIN_PB5__GPIO
value|PINMUX_PIN(PIN_PB5, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB5__TCLK2
value|PINMUX_PIN(PIN_PB5, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB5__D10
value|PINMUX_PIN(PIN_PB5, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB5__PWMH2
value|PINMUX_PIN(PIN_PB5, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB5__QSPI1_SCK
value|PINMUX_PIN(PIN_PB5, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB5__GTSUCOMP
value|PINMUX_PIN(PIN_PB5, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB6
value|38
end_define

begin_define
define|#
directive|define
name|PIN_PB6__GPIO
value|PINMUX_PIN(PIN_PB6, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB6__TIOA2
value|PINMUX_PIN(PIN_PB6, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB6__D11
value|PINMUX_PIN(PIN_PB6, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB6__PWML2
value|PINMUX_PIN(PIN_PB6, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB6__QSPI1_CS
value|PINMUX_PIN(PIN_PB6, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB6__GTXER
value|PINMUX_PIN(PIN_PB6, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB7
value|39
end_define

begin_define
define|#
directive|define
name|PIN_PB7__GPIO
value|PINMUX_PIN(PIN_PB7, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB7__TIOB2
value|PINMUX_PIN(PIN_PB7, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB7__D12
value|PINMUX_PIN(PIN_PB7, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB7__PWMH3
value|PINMUX_PIN(PIN_PB7, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB7__QSPI1_IO0
value|PINMUX_PIN(PIN_PB7, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB7__GRXCK
value|PINMUX_PIN(PIN_PB7, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB8
value|40
end_define

begin_define
define|#
directive|define
name|PIN_PB8__GPIO
value|PINMUX_PIN(PIN_PB8, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB8__TCLK3
value|PINMUX_PIN(PIN_PB8, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB8__D13
value|PINMUX_PIN(PIN_PB8, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB8__PWML3
value|PINMUX_PIN(PIN_PB8, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB8__QSPI1_IO1
value|PINMUX_PIN(PIN_PB8, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB8__GCRS
value|PINMUX_PIN(PIN_PB8, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB9
value|41
end_define

begin_define
define|#
directive|define
name|PIN_PB9__GPIO
value|PINMUX_PIN(PIN_PB9, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB9__TIOA3
value|PINMUX_PIN(PIN_PB9, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB9__D14
value|PINMUX_PIN(PIN_PB9, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB9__PWMFI1
value|PINMUX_PIN(PIN_PB9, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB9__QSPI1_IO2
value|PINMUX_PIN(PIN_PB9, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB9__GCOL
value|PINMUX_PIN(PIN_PB9, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB10
value|42
end_define

begin_define
define|#
directive|define
name|PIN_PB10__GPIO
value|PINMUX_PIN(PIN_PB10, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB10__TIOB3
value|PINMUX_PIN(PIN_PB10, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB10__D15
value|PINMUX_PIN(PIN_PB10, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB10__PWMEXTRG1
value|PINMUX_PIN(PIN_PB10, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB10__QSPI1_IO3
value|PINMUX_PIN(PIN_PB10, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB10__GRX2
value|PINMUX_PIN(PIN_PB10, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB11
value|43
end_define

begin_define
define|#
directive|define
name|PIN_PB11__GPIO
value|PINMUX_PIN(PIN_PB11, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB11__LCDDAT0
value|PINMUX_PIN(PIN_PB11, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB11__A0_NBS0
value|PINMUX_PIN(PIN_PB11, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB11__URXD3
value|PINMUX_PIN(PIN_PB11, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB11__PDMIC_DAT
value|PINMUX_PIN(PIN_PB11, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB11__GRX3
value|PINMUX_PIN(PIN_PB11, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB12
value|44
end_define

begin_define
define|#
directive|define
name|PIN_PB12__GPIO
value|PINMUX_PIN(PIN_PB12, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB12__LCDDAT1
value|PINMUX_PIN(PIN_PB12, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB12__A1
value|PINMUX_PIN(PIN_PB12, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB12__UTXD3
value|PINMUX_PIN(PIN_PB12, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB12__PDMIC_CLK
value|PINMUX_PIN(PIN_PB12, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB12__GTX2
value|PINMUX_PIN(PIN_PB12, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB13
value|45
end_define

begin_define
define|#
directive|define
name|PIN_PB13__GPIO
value|PINMUX_PIN(PIN_PB13, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB13__LCDDAT2
value|PINMUX_PIN(PIN_PB13, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB13__A2
value|PINMUX_PIN(PIN_PB13, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB13__PCK1
value|PINMUX_PIN(PIN_PB13, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB13__GTX3
value|PINMUX_PIN(PIN_PB13, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB14
value|46
end_define

begin_define
define|#
directive|define
name|PIN_PB14__GPIO
value|PINMUX_PIN(PIN_PB14, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__LCDDAT3
value|PINMUX_PIN(PIN_PB14, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__A3
value|PINMUX_PIN(PIN_PB14, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__TK1
value|PINMUX_PIN(PIN_PB14, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__I2SC1_MCK
value|PINMUX_PIN(PIN_PB14, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__QSPI1_SCK
value|PINMUX_PIN(PIN_PB14, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB14__GTXCK
value|PINMUX_PIN(PIN_PB14, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB15
value|47
end_define

begin_define
define|#
directive|define
name|PIN_PB15__GPIO
value|PINMUX_PIN(PIN_PB15, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__LCDDAT4
value|PINMUX_PIN(PIN_PB15, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__A4
value|PINMUX_PIN(PIN_PB15, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__TF1
value|PINMUX_PIN(PIN_PB15, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__I2SC1_CK
value|PINMUX_PIN(PIN_PB15, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__QSPI1_CS
value|PINMUX_PIN(PIN_PB15, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB15__GTXEN
value|PINMUX_PIN(PIN_PB15, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB16
value|48
end_define

begin_define
define|#
directive|define
name|PIN_PB16__GPIO
value|PINMUX_PIN(PIN_PB16, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__LCDDAT5
value|PINMUX_PIN(PIN_PB16, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__A5
value|PINMUX_PIN(PIN_PB16, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__TD1
value|PINMUX_PIN(PIN_PB16, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__I2SC1_WS
value|PINMUX_PIN(PIN_PB16, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__QSPI1_IO0
value|PINMUX_PIN(PIN_PB16, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB16__GRXDV
value|PINMUX_PIN(PIN_PB16, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB17
value|49
end_define

begin_define
define|#
directive|define
name|PIN_PB17__GPIO
value|PINMUX_PIN(PIN_PB17, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__LCDDAT6
value|PINMUX_PIN(PIN_PB17, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__A6
value|PINMUX_PIN(PIN_PB17, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__RD1
value|PINMUX_PIN(PIN_PB17, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__I2SC1_DI0
value|PINMUX_PIN(PIN_PB17, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__QSPI1_IO1
value|PINMUX_PIN(PIN_PB17, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB17__GRXER
value|PINMUX_PIN(PIN_PB17, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB18
value|50
end_define

begin_define
define|#
directive|define
name|PIN_PB18__GPIO
value|PINMUX_PIN(PIN_PB18, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__LCDDAT7
value|PINMUX_PIN(PIN_PB18, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__A7
value|PINMUX_PIN(PIN_PB18, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__RK1
value|PINMUX_PIN(PIN_PB18, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__I2SC1_DO0
value|PINMUX_PIN(PIN_PB18, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__QSPI1_IO2
value|PINMUX_PIN(PIN_PB18, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB18__GRX0
value|PINMUX_PIN(PIN_PB18, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB19
value|51
end_define

begin_define
define|#
directive|define
name|PIN_PB19__GPIO
value|PINMUX_PIN(PIN_PB19, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__LCDDAT8
value|PINMUX_PIN(PIN_PB19, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__A8
value|PINMUX_PIN(PIN_PB19, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__RF1
value|PINMUX_PIN(PIN_PB19, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__TIOA3
value|PINMUX_PIN(PIN_PB19, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__QSPI1_IO3
value|PINMUX_PIN(PIN_PB19, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB19__GRX1
value|PINMUX_PIN(PIN_PB19, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB20
value|52
end_define

begin_define
define|#
directive|define
name|PIN_PB20__GPIO
value|PINMUX_PIN(PIN_PB20, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__LCDDAT9
value|PINMUX_PIN(PIN_PB20, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__A9
value|PINMUX_PIN(PIN_PB20, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__TK0
value|PINMUX_PIN(PIN_PB20, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__TIOB3
value|PINMUX_PIN(PIN_PB20, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__PCK1
value|PINMUX_PIN(PIN_PB20, 5, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PB20__GTX0
value|PINMUX_PIN(PIN_PB20, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB21
value|53
end_define

begin_define
define|#
directive|define
name|PIN_PB21__GPIO
value|PINMUX_PIN(PIN_PB21, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__LCDDAT10
value|PINMUX_PIN(PIN_PB21, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__A10
value|PINMUX_PIN(PIN_PB21, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__TF0
value|PINMUX_PIN(PIN_PB21, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__TCLK3
value|PINMUX_PIN(PIN_PB21, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__FLEXCOM3_IO2
value|PINMUX_PIN(PIN_PB21, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB21__GTX1
value|PINMUX_PIN(PIN_PB21, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB22
value|54
end_define

begin_define
define|#
directive|define
name|PIN_PB22__GPIO
value|PINMUX_PIN(PIN_PB22, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__LCDDAT11
value|PINMUX_PIN(PIN_PB22, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__A11
value|PINMUX_PIN(PIN_PB22, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__TDO
value|PINMUX_PIN(PIN_PB22, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__TIOA2
value|PINMUX_PIN(PIN_PB22, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__FLEXCOM3_IO1
value|PINMUX_PIN(PIN_PB22, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB22__GMDC
value|PINMUX_PIN(PIN_PB22, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB23
value|55
end_define

begin_define
define|#
directive|define
name|PIN_PB23__GPIO
value|PINMUX_PIN(PIN_PB23, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__LCDDAT12
value|PINMUX_PIN(PIN_PB23, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__A12
value|PINMUX_PIN(PIN_PB23, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__RD0
value|PINMUX_PIN(PIN_PB23, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__TIOB2
value|PINMUX_PIN(PIN_PB23, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__FLEXCOM3_IO0
value|PINMUX_PIN(PIN_PB23, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB23__GMDIO
value|PINMUX_PIN(PIN_PB23, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB24
value|56
end_define

begin_define
define|#
directive|define
name|PIN_PB24__GPIO
value|PINMUX_PIN(PIN_PB24, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__LCDDAT13
value|PINMUX_PIN(PIN_PB24, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__A13
value|PINMUX_PIN(PIN_PB24, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__RK0
value|PINMUX_PIN(PIN_PB24, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__TCLK2
value|PINMUX_PIN(PIN_PB24, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__FLEXCOM3_IO3
value|PINMUX_PIN(PIN_PB24, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB24__ISC_D10
value|PINMUX_PIN(PIN_PB24, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB25
value|57
end_define

begin_define
define|#
directive|define
name|PIN_PB25__GPIO
value|PINMUX_PIN(PIN_PB25, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB25__LCDDAT14
value|PINMUX_PIN(PIN_PB25, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB25__A14
value|PINMUX_PIN(PIN_PB25, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB25__RF0
value|PINMUX_PIN(PIN_PB25, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB25__FLEXCOM3_IO4
value|PINMUX_PIN(PIN_PB25, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB25__ISC_D11
value|PINMUX_PIN(PIN_PB25, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB26
value|58
end_define

begin_define
define|#
directive|define
name|PIN_PB26__GPIO
value|PINMUX_PIN(PIN_PB26, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB26__LCDDAT15
value|PINMUX_PIN(PIN_PB26, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB26__A15
value|PINMUX_PIN(PIN_PB26, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB26__URXD0
value|PINMUX_PIN(PIN_PB26, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB26__PDMIC_DAT
value|PINMUX_PIN(PIN_PB26, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB26__ISC_D0
value|PINMUX_PIN(PIN_PB26, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB27
value|59
end_define

begin_define
define|#
directive|define
name|PIN_PB27__GPIO
value|PINMUX_PIN(PIN_PB27, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB27__LCDDAT16
value|PINMUX_PIN(PIN_PB27, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB27__A16
value|PINMUX_PIN(PIN_PB27, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB27__UTXD0
value|PINMUX_PIN(PIN_PB27, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB27__PDMIC_CLK
value|PINMUX_PIN(PIN_PB27, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB27__ISC_D1
value|PINMUX_PIN(PIN_PB27, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB28
value|60
end_define

begin_define
define|#
directive|define
name|PIN_PB28__GPIO
value|PINMUX_PIN(PIN_PB28, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB28__LCDDAT17
value|PINMUX_PIN(PIN_PB28, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB28__A17
value|PINMUX_PIN(PIN_PB28, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB28__FLEXCOM0_IO0
value|PINMUX_PIN(PIN_PB28, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB28__TIOA5
value|PINMUX_PIN(PIN_PB28, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB28__ISC_D2
value|PINMUX_PIN(PIN_PB28, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB29
value|61
end_define

begin_define
define|#
directive|define
name|PIN_PB29__GPIO
value|PINMUX_PIN(PIN_PB29, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB29__LCDDAT18
value|PINMUX_PIN(PIN_PB29, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB29__A18
value|PINMUX_PIN(PIN_PB29, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB29__FLEXCOM0_IO1
value|PINMUX_PIN(PIN_PB29, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB29__TIOB5
value|PINMUX_PIN(PIN_PB29, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB29__ISC_D3
value|PINMUX_PIN(PIN_PB29, 7, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB30
value|62
end_define

begin_define
define|#
directive|define
name|PIN_PB30__GPIO
value|PINMUX_PIN(PIN_PB30, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB30__LCDDAT19
value|PINMUX_PIN(PIN_PB30, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB30__A19
value|PINMUX_PIN(PIN_PB30, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB30__FLEXCOM0_IO2
value|PINMUX_PIN(PIN_PB30, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB30__TCLK5
value|PINMUX_PIN(PIN_PB30, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PB30__ISC_D4
value|PINMUX_PIN(PIN_PB30, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PB31
value|63
end_define

begin_define
define|#
directive|define
name|PIN_PB31__GPIO
value|PINMUX_PIN(PIN_PB31, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PB31__LCDDAT20
value|PINMUX_PIN(PIN_PB31, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB31__A20
value|PINMUX_PIN(PIN_PB31, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB31__FLEXCOM0_IO3
value|PINMUX_PIN(PIN_PB31, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB31__TWD0
value|PINMUX_PIN(PIN_PB31, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PB31__ISC_D5
value|PINMUX_PIN(PIN_PB31, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC0
value|64
end_define

begin_define
define|#
directive|define
name|PIN_PC0__GPIO
value|PINMUX_PIN(PIN_PC0, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC0__LCDDAT21
value|PINMUX_PIN(PIN_PC0, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC0__A23
value|PINMUX_PIN(PIN_PC0, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC0__FLEXCOM0_IO4
value|PINMUX_PIN(PIN_PC0, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC0__TWCK0
value|PINMUX_PIN(PIN_PC0, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC0__ISC_D6
value|PINMUX_PIN(PIN_PC0, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC1
value|65
end_define

begin_define
define|#
directive|define
name|PIN_PC1__GPIO
value|PINMUX_PIN(PIN_PC1, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__LCDDAT22
value|PINMUX_PIN(PIN_PC1, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__A24
value|PINMUX_PIN(PIN_PC1, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__CANTX0
value|PINMUX_PIN(PIN_PC1, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__SPI1_SPCK
value|PINMUX_PIN(PIN_PC1, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__I2SC0_CK
value|PINMUX_PIN(PIN_PC1, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC1__ISC_D7
value|PINMUX_PIN(PIN_PC1, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC2
value|66
end_define

begin_define
define|#
directive|define
name|PIN_PC2__GPIO
value|PINMUX_PIN(PIN_PC2, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__LCDDAT23
value|PINMUX_PIN(PIN_PC2, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__A25
value|PINMUX_PIN(PIN_PC2, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__CANRX0
value|PINMUX_PIN(PIN_PC2, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__SPI1_MOSI
value|PINMUX_PIN(PIN_PC2, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__I2SC0_MCK
value|PINMUX_PIN(PIN_PC2, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC2__ISC_D8
value|PINMUX_PIN(PIN_PC2, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC3
value|67
end_define

begin_define
define|#
directive|define
name|PIN_PC3__GPIO
value|PINMUX_PIN(PIN_PC3, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__LCDPWM
value|PINMUX_PIN(PIN_PC3, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__NWAIT
value|PINMUX_PIN(PIN_PC3, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__TIOA1
value|PINMUX_PIN(PIN_PC3, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__SPI1_MISO
value|PINMUX_PIN(PIN_PC3, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__I2SC0_WS
value|PINMUX_PIN(PIN_PC3, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC3__ISC_D9
value|PINMUX_PIN(PIN_PC3, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC4
value|68
end_define

begin_define
define|#
directive|define
name|PIN_PC4__GPIO
value|PINMUX_PIN(PIN_PC4, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__LCDDISP
value|PINMUX_PIN(PIN_PC4, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__NWR1_NBS1
value|PINMUX_PIN(PIN_PC4, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__TIOB1
value|PINMUX_PIN(PIN_PC4, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__SPI1_NPCS0
value|PINMUX_PIN(PIN_PC4, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__I2SC0_DI0
value|PINMUX_PIN(PIN_PC4, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC4__ISC_PCK
value|PINMUX_PIN(PIN_PC4, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC5
value|69
end_define

begin_define
define|#
directive|define
name|PIN_PC5__GPIO
value|PINMUX_PIN(PIN_PC5, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__LCDVSYNC
value|PINMUX_PIN(PIN_PC5, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__NCS0
value|PINMUX_PIN(PIN_PC5, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__TCLK1
value|PINMUX_PIN(PIN_PC5, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__SPI1_NPCS1
value|PINMUX_PIN(PIN_PC5, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__I2SC0_DO0
value|PINMUX_PIN(PIN_PC5, 5, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC5__ISC_VSYNC
value|PINMUX_PIN(PIN_PC5, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC6
value|70
end_define

begin_define
define|#
directive|define
name|PIN_PC6__GPIO
value|PINMUX_PIN(PIN_PC6, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC6__LCDHSYNC
value|PINMUX_PIN(PIN_PC6, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC6__NCS1
value|PINMUX_PIN(PIN_PC6, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC6__TWD1
value|PINMUX_PIN(PIN_PC6, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC6__SPI1_NPCS2
value|PINMUX_PIN(PIN_PC6, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC6__ISC_HSYNC
value|PINMUX_PIN(PIN_PC6, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC7
value|71
end_define

begin_define
define|#
directive|define
name|PIN_PC7__GPIO
value|PINMUX_PIN(PIN_PC7, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__LCDPCK
value|PINMUX_PIN(PIN_PC7, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__NCS2
value|PINMUX_PIN(PIN_PC7, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__TWCK1
value|PINMUX_PIN(PIN_PC7, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__SPI1_NPCS3
value|PINMUX_PIN(PIN_PC7, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__URXD1
value|PINMUX_PIN(PIN_PC7, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC7__ISC_MCK
value|PINMUX_PIN(PIN_PC7, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC8
value|72
end_define

begin_define
define|#
directive|define
name|PIN_PC8__GPIO
value|PINMUX_PIN(PIN_PC8, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__LCDDEN
value|PINMUX_PIN(PIN_PC8, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__NANDRDY
value|PINMUX_PIN(PIN_PC8, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__FIQ
value|PINMUX_PIN(PIN_PC8, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__PCK0
value|PINMUX_PIN(PIN_PC8, 4, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__UTXD1
value|PINMUX_PIN(PIN_PC8, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC8__ISC_FIELD
value|PINMUX_PIN(PIN_PC8, 6, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC9
value|73
end_define

begin_define
define|#
directive|define
name|PIN_PC9__GPIO
value|PINMUX_PIN(PIN_PC9, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC9__FIQ
value|PINMUX_PIN(PIN_PC9, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PC9__GTSUCOMP
value|PINMUX_PIN(PIN_PC9, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC9__ISC_D0
value|PINMUX_PIN(PIN_PC9, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC9__TIOA4
value|PINMUX_PIN(PIN_PC9, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC10
value|74
end_define

begin_define
define|#
directive|define
name|PIN_PC10__GPIO
value|PINMUX_PIN(PIN_PC10, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC10__LCDDAT2
value|PINMUX_PIN(PIN_PC10, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC10__GTXCK
value|PINMUX_PIN(PIN_PC10, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC10__ISC_D1
value|PINMUX_PIN(PIN_PC10, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC10__TIOB4
value|PINMUX_PIN(PIN_PC10, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC10__CANTX0
value|PINMUX_PIN(PIN_PC10, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC11
value|75
end_define

begin_define
define|#
directive|define
name|PIN_PC11__GPIO
value|PINMUX_PIN(PIN_PC11, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__LCDDAT3
value|PINMUX_PIN(PIN_PC11, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__GTXEN
value|PINMUX_PIN(PIN_PC11, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__ISC_D2
value|PINMUX_PIN(PIN_PC11, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__TCLK4
value|PINMUX_PIN(PIN_PC11, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__CANRX0
value|PINMUX_PIN(PIN_PC11, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC11__A0_NBS0
value|PINMUX_PIN(PIN_PC11, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC12
value|76
end_define

begin_define
define|#
directive|define
name|PIN_PC12__GPIO
value|PINMUX_PIN(PIN_PC12, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__LCDDAT4
value|PINMUX_PIN(PIN_PC12, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__GRXDV
value|PINMUX_PIN(PIN_PC12, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__ISC_D3
value|PINMUX_PIN(PIN_PC12, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__URXD3
value|PINMUX_PIN(PIN_PC12, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__TK0
value|PINMUX_PIN(PIN_PC12, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC12__A1
value|PINMUX_PIN(PIN_PC12, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC13
value|77
end_define

begin_define
define|#
directive|define
name|PIN_PC13__GPIO
value|PINMUX_PIN(PIN_PC13, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__LCDDAT5
value|PINMUX_PIN(PIN_PC13, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__GRXER
value|PINMUX_PIN(PIN_PC13, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__ISC_D4
value|PINMUX_PIN(PIN_PC13, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__UTXD3
value|PINMUX_PIN(PIN_PC13, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__TF0
value|PINMUX_PIN(PIN_PC13, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC13__A2
value|PINMUX_PIN(PIN_PC13, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC14
value|78
end_define

begin_define
define|#
directive|define
name|PIN_PC14__GPIO
value|PINMUX_PIN(PIN_PC14, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC14__LCDDAT6
value|PINMUX_PIN(PIN_PC14, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC14__GRX0
value|PINMUX_PIN(PIN_PC14, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC14__ISC_D5
value|PINMUX_PIN(PIN_PC14, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC14__TDO
value|PINMUX_PIN(PIN_PC14, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC14__A3
value|PINMUX_PIN(PIN_PC14, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC15
value|79
end_define

begin_define
define|#
directive|define
name|PIN_PC15__GPIO
value|PINMUX_PIN(PIN_PC15, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC15__LCDDAT7
value|PINMUX_PIN(PIN_PC15, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC15__GRX1
value|PINMUX_PIN(PIN_PC15, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC15__ISC_D6
value|PINMUX_PIN(PIN_PC15, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC15__RD0
value|PINMUX_PIN(PIN_PC15, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC15__A4
value|PINMUX_PIN(PIN_PC15, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC16
value|80
end_define

begin_define
define|#
directive|define
name|PIN_PC16__GPIO
value|PINMUX_PIN(PIN_PC16, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC16__LCDDAT10
value|PINMUX_PIN(PIN_PC16, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC16__GTX0
value|PINMUX_PIN(PIN_PC16, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC16__ISC_D7
value|PINMUX_PIN(PIN_PC16, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC16__RK0
value|PINMUX_PIN(PIN_PC16, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC16__A5
value|PINMUX_PIN(PIN_PC16, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC17
value|81
end_define

begin_define
define|#
directive|define
name|PIN_PC17__GPIO
value|PINMUX_PIN(PIN_PC17, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC17__LCDDAT11
value|PINMUX_PIN(PIN_PC17, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC17__GTX1
value|PINMUX_PIN(PIN_PC17, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC17__ISC_D8
value|PINMUX_PIN(PIN_PC17, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC17__RF0
value|PINMUX_PIN(PIN_PC17, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC17__A6
value|PINMUX_PIN(PIN_PC17, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC18
value|82
end_define

begin_define
define|#
directive|define
name|PIN_PC18__GPIO
value|PINMUX_PIN(PIN_PC18, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC18__LCDDAT12
value|PINMUX_PIN(PIN_PC18, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC18__GMDC
value|PINMUX_PIN(PIN_PC18, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC18__ISC_D9
value|PINMUX_PIN(PIN_PC18, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC18__FLEXCOM3_IO2
value|PINMUX_PIN(PIN_PC18, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC18__A7
value|PINMUX_PIN(PIN_PC18, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC19
value|83
end_define

begin_define
define|#
directive|define
name|PIN_PC19__GPIO
value|PINMUX_PIN(PIN_PC19, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC19__LCDDAT13
value|PINMUX_PIN(PIN_PC19, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC19__GMDIO
value|PINMUX_PIN(PIN_PC19, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC19__ISC_D10
value|PINMUX_PIN(PIN_PC19, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC19__FLEXCOM3_IO1
value|PINMUX_PIN(PIN_PC19, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC19__A8
value|PINMUX_PIN(PIN_PC19, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC20
value|84
end_define

begin_define
define|#
directive|define
name|PIN_PC20__GPIO
value|PINMUX_PIN(PIN_PC20, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC20__LCDDAT14
value|PINMUX_PIN(PIN_PC20, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC20__GRXCK
value|PINMUX_PIN(PIN_PC20, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC20__ISC_D11
value|PINMUX_PIN(PIN_PC20, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC20__FLEXCOM3_IO0
value|PINMUX_PIN(PIN_PC20, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC20__A9
value|PINMUX_PIN(PIN_PC20, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC21
value|85
end_define

begin_define
define|#
directive|define
name|PIN_PC21__GPIO
value|PINMUX_PIN(PIN_PC21, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC21__LCDDAT15
value|PINMUX_PIN(PIN_PC21, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC21__GTXER
value|PINMUX_PIN(PIN_PC21, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC21__ISC_PCK
value|PINMUX_PIN(PIN_PC21, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC21__FLEXCOM3_IO3
value|PINMUX_PIN(PIN_PC21, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC21__A10
value|PINMUX_PIN(PIN_PC21, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC22
value|86
end_define

begin_define
define|#
directive|define
name|PIN_PC22__GPIO
value|PINMUX_PIN(PIN_PC22, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC22__LCDDAT18
value|PINMUX_PIN(PIN_PC22, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC22__GCRS
value|PINMUX_PIN(PIN_PC22, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC22__ISC_VSYNC
value|PINMUX_PIN(PIN_PC22, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC22__FLEXCOM3_IO4
value|PINMUX_PIN(PIN_PC22, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC22__A11
value|PINMUX_PIN(PIN_PC22, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC23
value|87
end_define

begin_define
define|#
directive|define
name|PIN_PC23__GPIO
value|PINMUX_PIN(PIN_PC23, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC23__LCDDAT19
value|PINMUX_PIN(PIN_PC23, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC23__GCOL
value|PINMUX_PIN(PIN_PC23, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC23__ISC_HSYNC
value|PINMUX_PIN(PIN_PC23, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC23__A12
value|PINMUX_PIN(PIN_PC23, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC24
value|88
end_define

begin_define
define|#
directive|define
name|PIN_PC24__GPIO
value|PINMUX_PIN(PIN_PC24, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC24__LCDDAT20
value|PINMUX_PIN(PIN_PC24, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC24__GRX2
value|PINMUX_PIN(PIN_PC24, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC24__ISC_MCK
value|PINMUX_PIN(PIN_PC24, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC24__A13
value|PINMUX_PIN(PIN_PC24, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC25
value|89
end_define

begin_define
define|#
directive|define
name|PIN_PC25__GPIO
value|PINMUX_PIN(PIN_PC25, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC25__LCDDAT21
value|PINMUX_PIN(PIN_PC25, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC25__GRX3
value|PINMUX_PIN(PIN_PC25, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC25__ISC_FIELD
value|PINMUX_PIN(PIN_PC25, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC25__A14
value|PINMUX_PIN(PIN_PC25, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC26
value|90
end_define

begin_define
define|#
directive|define
name|PIN_PC26__GPIO
value|PINMUX_PIN(PIN_PC26, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC26__LCDDAT22
value|PINMUX_PIN(PIN_PC26, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC26__GTX2
value|PINMUX_PIN(PIN_PC26, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC26__CANTX1
value|PINMUX_PIN(PIN_PC26, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC26__A15
value|PINMUX_PIN(PIN_PC26, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC27
value|91
end_define

begin_define
define|#
directive|define
name|PIN_PC27__GPIO
value|PINMUX_PIN(PIN_PC27, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__LCDDAT23
value|PINMUX_PIN(PIN_PC27, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__GTX3
value|PINMUX_PIN(PIN_PC27, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__PCK1
value|PINMUX_PIN(PIN_PC27, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__CANRX1
value|PINMUX_PIN(PIN_PC27, 4, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__TWD0
value|PINMUX_PIN(PIN_PC27, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC27__A16
value|PINMUX_PIN(PIN_PC27, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC28
value|92
end_define

begin_define
define|#
directive|define
name|PIN_PC28__GPIO
value|PINMUX_PIN(PIN_PC28, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC28__LCDPWM
value|PINMUX_PIN(PIN_PC28, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC28__FLEXCOM4_IO0
value|PINMUX_PIN(PIN_PC28, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC28__PCK2
value|PINMUX_PIN(PIN_PC28, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC28__TWCK0
value|PINMUX_PIN(PIN_PC28, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC28__A17
value|PINMUX_PIN(PIN_PC28, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC29
value|93
end_define

begin_define
define|#
directive|define
name|PIN_PC29__GPIO
value|PINMUX_PIN(PIN_PC29, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC29__LCDDISP
value|PINMUX_PIN(PIN_PC29, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC29__FLEXCOM4_IO1
value|PINMUX_PIN(PIN_PC29, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC29__A18
value|PINMUX_PIN(PIN_PC29, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC30
value|94
end_define

begin_define
define|#
directive|define
name|PIN_PC30__GPIO
value|PINMUX_PIN(PIN_PC30, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC30__LCDVSYNC
value|PINMUX_PIN(PIN_PC30, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC30__FLEXCOM4_IO2
value|PINMUX_PIN(PIN_PC30, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC30__A19
value|PINMUX_PIN(PIN_PC30, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC31
value|95
end_define

begin_define
define|#
directive|define
name|PIN_PC31__GPIO
value|PINMUX_PIN(PIN_PC31, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PC31__LCDHSYNC
value|PINMUX_PIN(PIN_PC31, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC31__FLEXCOM4_IO3
value|PINMUX_PIN(PIN_PC31, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PC31__URXD3
value|PINMUX_PIN(PIN_PC31, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PC31__A20
value|PINMUX_PIN(PIN_PC31, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD0
value|96
end_define

begin_define
define|#
directive|define
name|PIN_PD0__GPIO
value|PINMUX_PIN(PIN_PD0, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD0__LCDPCK
value|PINMUX_PIN(PIN_PD0, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD0__FLEXCOM4_IO4
value|PINMUX_PIN(PIN_PD0, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD0__UTXD3
value|PINMUX_PIN(PIN_PD0, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD0__GTSUCOMP
value|PINMUX_PIN(PIN_PD0, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD0__A23
value|PINMUX_PIN(PIN_PD0, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD1
value|97
end_define

begin_define
define|#
directive|define
name|PIN_PD1__GPIO
value|PINMUX_PIN(PIN_PD1, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD1__LCDDEN
value|PINMUX_PIN(PIN_PD1, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD1__GRXCK
value|PINMUX_PIN(PIN_PD1, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD1__A24
value|PINMUX_PIN(PIN_PD1, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD2
value|98
end_define

begin_define
define|#
directive|define
name|PIN_PD2__GPIO
value|PINMUX_PIN(PIN_PD2, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD2__URXD1
value|PINMUX_PIN(PIN_PD2, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD2__GTXER
value|PINMUX_PIN(PIN_PD2, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD2__ISC_MCK
value|PINMUX_PIN(PIN_PD2, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD2__A25
value|PINMUX_PIN(PIN_PD2, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD3
value|99
end_define

begin_define
define|#
directive|define
name|PIN_PD3__GPIO
value|PINMUX_PIN(PIN_PD3, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD3__UTXD1
value|PINMUX_PIN(PIN_PD3, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD3__FIQ
value|PINMUX_PIN(PIN_PD3, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD3__GCRS
value|PINMUX_PIN(PIN_PD3, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD3__ISC_D11
value|PINMUX_PIN(PIN_PD3, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD3__NWAIT
value|PINMUX_PIN(PIN_PD3, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD4
value|100
end_define

begin_define
define|#
directive|define
name|PIN_PD4__GPIO
value|PINMUX_PIN(PIN_PD4, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD4__TWD1
value|PINMUX_PIN(PIN_PD4, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD4__URXD2
value|PINMUX_PIN(PIN_PD4, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD4__GCOL
value|PINMUX_PIN(PIN_PD4, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD4__ISC_D10
value|PINMUX_PIN(PIN_PD4, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD4__NCS0
value|PINMUX_PIN(PIN_PD4, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD5
value|101
end_define

begin_define
define|#
directive|define
name|PIN_PD5__GPIO
value|PINMUX_PIN(PIN_PD5, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD5__TWCK1
value|PINMUX_PIN(PIN_PD5, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD5__UTXD2
value|PINMUX_PIN(PIN_PD5, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD5__GRX2
value|PINMUX_PIN(PIN_PD5, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD5__ISC_D9
value|PINMUX_PIN(PIN_PD5, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD5__NCS1
value|PINMUX_PIN(PIN_PD5, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD6
value|102
end_define

begin_define
define|#
directive|define
name|PIN_PD6__GPIO
value|PINMUX_PIN(PIN_PD6, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD6__TCK
value|PINMUX_PIN(PIN_PD6, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD6__PCK1
value|PINMUX_PIN(PIN_PD6, 2, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD6__GRX3
value|PINMUX_PIN(PIN_PD6, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD6__ISC_D8
value|PINMUX_PIN(PIN_PD6, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD6__NCS2
value|PINMUX_PIN(PIN_PD6, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD7
value|103
end_define

begin_define
define|#
directive|define
name|PIN_PD7__GPIO
value|PINMUX_PIN(PIN_PD7, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD7__TDI
value|PINMUX_PIN(PIN_PD7, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD7__UTMI_RXVAL
value|PINMUX_PIN(PIN_PD7, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD7__GTX2
value|PINMUX_PIN(PIN_PD7, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD7__ISC_D0
value|PINMUX_PIN(PIN_PD7, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD7__NWR1_NBS1
value|PINMUX_PIN(PIN_PD7, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD8
value|104
end_define

begin_define
define|#
directive|define
name|PIN_PD8__GPIO
value|PINMUX_PIN(PIN_PD8, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD8__TDO
value|PINMUX_PIN(PIN_PD8, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD8__UTMI_RXERR
value|PINMUX_PIN(PIN_PD8, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD8__GTX3
value|PINMUX_PIN(PIN_PD8, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD8__ISC_D1
value|PINMUX_PIN(PIN_PD8, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD8__NANDRDY
value|PINMUX_PIN(PIN_PD8, 6, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD9
value|105
end_define

begin_define
define|#
directive|define
name|PIN_PD9__GPIO
value|PINMUX_PIN(PIN_PD9, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD9__TMS
value|PINMUX_PIN(PIN_PD9, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD9__UTMI_RXACT
value|PINMUX_PIN(PIN_PD9, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD9__GTXCK
value|PINMUX_PIN(PIN_PD9, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD9__ISC_D2
value|PINMUX_PIN(PIN_PD9, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD10
value|106
end_define

begin_define
define|#
directive|define
name|PIN_PD10__GPIO
value|PINMUX_PIN(PIN_PD10, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD10__NTRST
value|PINMUX_PIN(PIN_PD10, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD10__UTMI_HDIS
value|PINMUX_PIN(PIN_PD10, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD10__GTXEN
value|PINMUX_PIN(PIN_PD10, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD10__ISC_D3
value|PINMUX_PIN(PIN_PD10, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD11
value|107
end_define

begin_define
define|#
directive|define
name|PIN_PD11__GPIO
value|PINMUX_PIN(PIN_PD11, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__TIOA1
value|PINMUX_PIN(PIN_PD11, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__PCK2
value|PINMUX_PIN(PIN_PD11, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__UTMI_LS0
value|PINMUX_PIN(PIN_PD11, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__GRXDV
value|PINMUX_PIN(PIN_PD11, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__ISC_D4
value|PINMUX_PIN(PIN_PD11, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD11__ISC_MCK
value|PINMUX_PIN(PIN_PD11, 7, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD12
value|108
end_define

begin_define
define|#
directive|define
name|PIN_PD12__GPIO
value|PINMUX_PIN(PIN_PD12, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__TIOB1
value|PINMUX_PIN(PIN_PD12, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__FLEXCOM4_IO0
value|PINMUX_PIN(PIN_PD12, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__UTMI_LS1
value|PINMUX_PIN(PIN_PD12, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__GRXER
value|PINMUX_PIN(PIN_PD12, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__ISC_D5
value|PINMUX_PIN(PIN_PD12, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD12__ISC_D4
value|PINMUX_PIN(PIN_PD12, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD13
value|109
end_define

begin_define
define|#
directive|define
name|PIN_PD13__GPIO
value|PINMUX_PIN(PIN_PD13, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__TCLK1
value|PINMUX_PIN(PIN_PD13, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__FLEXCOM4_IO1
value|PINMUX_PIN(PIN_PD13, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__UTMI_CDRPCSEL0
value|PINMUX_PIN(PIN_PD13, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__GRX0
value|PINMUX_PIN(PIN_PD13, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__ISC_D6
value|PINMUX_PIN(PIN_PD13, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD13__ISC_D5
value|PINMUX_PIN(PIN_PD13, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD14
value|110
end_define

begin_define
define|#
directive|define
name|PIN_PD14__GPIO
value|PINMUX_PIN(PIN_PD14, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__TCK
value|PINMUX_PIN(PIN_PD14, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__FLEXCOM4_IO2
value|PINMUX_PIN(PIN_PD14, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__UTMI_CDRPCSEL1
value|PINMUX_PIN(PIN_PD14, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__GRX1
value|PINMUX_PIN(PIN_PD14, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__ISC_D7
value|PINMUX_PIN(PIN_PD14, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD14__ISC_D6
value|PINMUX_PIN(PIN_PD14, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD15
value|111
end_define

begin_define
define|#
directive|define
name|PIN_PD15__GPIO
value|PINMUX_PIN(PIN_PD15, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__TDI
value|PINMUX_PIN(PIN_PD15, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__FLEXCOM4_IO3
value|PINMUX_PIN(PIN_PD15, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__UTMI_CDRCPDIVEN
value|PINMUX_PIN(PIN_PD15, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__GTX0
value|PINMUX_PIN(PIN_PD15, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__ISC_PCK
value|PINMUX_PIN(PIN_PD15, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD15__ISC_D7
value|PINMUX_PIN(PIN_PD15, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD16
value|112
end_define

begin_define
define|#
directive|define
name|PIN_PD16__GPIO
value|PINMUX_PIN(PIN_PD16, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__TDO
value|PINMUX_PIN(PIN_PD16, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__FLEXCOM4_IO4
value|PINMUX_PIN(PIN_PD16, 2, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__UTMI_CDRBISTEN
value|PINMUX_PIN(PIN_PD16, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__GTX1
value|PINMUX_PIN(PIN_PD16, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__ISC_VSYNC
value|PINMUX_PIN(PIN_PD16, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD16__ISC_D8
value|PINMUX_PIN(PIN_PD16, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD17
value|113
end_define

begin_define
define|#
directive|define
name|PIN_PD17__GPIO
value|PINMUX_PIN(PIN_PD17, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD17__TMS
value|PINMUX_PIN(PIN_PD17, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD17__UTMI_CDRCPSELDIV
value|PINMUX_PIN(PIN_PD17, 3, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD17__GMDC
value|PINMUX_PIN(PIN_PD17, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD17__ISC_HSYNC
value|PINMUX_PIN(PIN_PD17, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD17__ISC_D9
value|PINMUX_PIN(PIN_PD17, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD18
value|114
end_define

begin_define
define|#
directive|define
name|PIN_PD18__GPIO
value|PINMUX_PIN(PIN_PD18, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD18__NTRST
value|PINMUX_PIN(PIN_PD18, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD18__GMDIO
value|PINMUX_PIN(PIN_PD18, 4, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD18__ISC_FIELD
value|PINMUX_PIN(PIN_PD18, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD18__ISC_D10
value|PINMUX_PIN(PIN_PD18, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD19
value|115
end_define

begin_define
define|#
directive|define
name|PIN_PD19__GPIO
value|PINMUX_PIN(PIN_PD19, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD19__PCK0
value|PINMUX_PIN(PIN_PD19, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD19__TWD1
value|PINMUX_PIN(PIN_PD19, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD19__URXD2
value|PINMUX_PIN(PIN_PD19, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD19__I2SC0_CK
value|PINMUX_PIN(PIN_PD19, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD19__ISC_D11
value|PINMUX_PIN(PIN_PD19, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD20
value|116
end_define

begin_define
define|#
directive|define
name|PIN_PD20__GPIO
value|PINMUX_PIN(PIN_PD20, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD20__TIOA2
value|PINMUX_PIN(PIN_PD20, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD20__TWCK1
value|PINMUX_PIN(PIN_PD20, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD20__UTXD2
value|PINMUX_PIN(PIN_PD20, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD20__I2SC0_MCK
value|PINMUX_PIN(PIN_PD20, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD20__ISC_PCK
value|PINMUX_PIN(PIN_PD20, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD21
value|117
end_define

begin_define
define|#
directive|define
name|PIN_PD21__GPIO
value|PINMUX_PIN(PIN_PD21, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD21__TIOB2
value|PINMUX_PIN(PIN_PD21, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD21__TWD0
value|PINMUX_PIN(PIN_PD21, 2, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD21__FLEXCOM4_IO0
value|PINMUX_PIN(PIN_PD21, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD21__I2SC0_WS
value|PINMUX_PIN(PIN_PD21, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD21__ISC_VSYNC
value|PINMUX_PIN(PIN_PD21, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD22
value|118
end_define

begin_define
define|#
directive|define
name|PIN_PD22__GPIO
value|PINMUX_PIN(PIN_PD22, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD22__TCLK2
value|PINMUX_PIN(PIN_PD22, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD22__TWCK0
value|PINMUX_PIN(PIN_PD22, 2, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD22__FLEXCOM4_IO1
value|PINMUX_PIN(PIN_PD22, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD22__I2SC0_DI0
value|PINMUX_PIN(PIN_PD22, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD22__ISC_HSYNC
value|PINMUX_PIN(PIN_PD22, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD23
value|119
end_define

begin_define
define|#
directive|define
name|PIN_PD23__GPIO
value|PINMUX_PIN(PIN_PD23, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD23__URXD2
value|PINMUX_PIN(PIN_PD23, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD23__FLEXCOM4_IO2
value|PINMUX_PIN(PIN_PD23, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD23__I2SC0_DO0
value|PINMUX_PIN(PIN_PD23, 5, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD23__ISC_FIELD
value|PINMUX_PIN(PIN_PD23, 6, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD24
value|120
end_define

begin_define
define|#
directive|define
name|PIN_PD24__GPIO
value|PINMUX_PIN(PIN_PD24, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD24__UTXD2
value|PINMUX_PIN(PIN_PD24, 1, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD24__FLEXCOM4_IO3
value|PINMUX_PIN(PIN_PD24, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD25
value|121
end_define

begin_define
define|#
directive|define
name|PIN_PD25__GPIO
value|PINMUX_PIN(PIN_PD25, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD25__SPI1_SPCK
value|PINMUX_PIN(PIN_PD25, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD25__FLEXCOM4_IO4
value|PINMUX_PIN(PIN_PD25, 3, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD26
value|122
end_define

begin_define
define|#
directive|define
name|PIN_PD26__GPIO
value|PINMUX_PIN(PIN_PD26, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD26__SPI1_MOSI
value|PINMUX_PIN(PIN_PD26, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD26__FLEXCOM2_IO0
value|PINMUX_PIN(PIN_PD26, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD27
value|123
end_define

begin_define
define|#
directive|define
name|PIN_PD27__GPIO
value|PINMUX_PIN(PIN_PD27, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD27__SPI1_MISO
value|PINMUX_PIN(PIN_PD27, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD27__TCK
value|PINMUX_PIN(PIN_PD27, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD27__FLEXCOM2_IO1
value|PINMUX_PIN(PIN_PD27, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD28
value|124
end_define

begin_define
define|#
directive|define
name|PIN_PD28__GPIO
value|PINMUX_PIN(PIN_PD28, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD28__SPI1_NPCS0
value|PINMUX_PIN(PIN_PD28, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD28__TCI
value|PINMUX_PIN(PIN_PD28, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD28__FLEXCOM2_IO2
value|PINMUX_PIN(PIN_PD28, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD29
value|125
end_define

begin_define
define|#
directive|define
name|PIN_PD29__GPIO
value|PINMUX_PIN(PIN_PD29, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD29__SPI1_NPCS1
value|PINMUX_PIN(PIN_PD29, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD29__TDO
value|PINMUX_PIN(PIN_PD29, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD29__FLEXCOM2_IO3
value|PINMUX_PIN(PIN_PD29, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD29__TIOA3
value|PINMUX_PIN(PIN_PD29, 4, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD29__TWD0
value|PINMUX_PIN(PIN_PD29, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD30
value|126
end_define

begin_define
define|#
directive|define
name|PIN_PD30__GPIO
value|PINMUX_PIN(PIN_PD30, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD30__SPI1_NPCS2
value|PINMUX_PIN(PIN_PD30, 1, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD30__TMS
value|PINMUX_PIN(PIN_PD30, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD30__FLEXCOM2_IO4
value|PINMUX_PIN(PIN_PD30, 3, 2)
end_define

begin_define
define|#
directive|define
name|PIN_PD30__TIOB3
value|PINMUX_PIN(PIN_PD30, 4, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD30__TWCK0
value|PINMUX_PIN(PIN_PD30, 5, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD31
value|127
end_define

begin_define
define|#
directive|define
name|PIN_PD31__GPIO
value|PINMUX_PIN(PIN_PD31, 0, 0)
end_define

begin_define
define|#
directive|define
name|PIN_PD31__ADTRG
value|PINMUX_PIN(PIN_PD31, 1, 1)
end_define

begin_define
define|#
directive|define
name|PIN_PD31__NTRST
value|PINMUX_PIN(PIN_PD31, 2, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD31__IRQ
value|PINMUX_PIN(PIN_PD31, 3, 4)
end_define

begin_define
define|#
directive|define
name|PIN_PD31__TCLK3
value|PINMUX_PIN(PIN_PD31, 4, 3)
end_define

begin_define
define|#
directive|define
name|PIN_PD31__PCK0
value|PINMUX_PIN(PIN_PD31, 5, 2)
end_define

end_unit

