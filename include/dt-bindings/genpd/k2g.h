begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * TI K2G SoC Device definitions  *  * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_GENPD_K2G_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_GENPD_K2G_H
end_define

begin_comment
comment|/* Documented in http://processors.wiki.ti.com/index.php/TISCI */
end_comment

begin_define
define|#
directive|define
name|K2G_DEV_PMMC0
value|0x0000
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MLB0
value|0x0001
end_define

begin_define
define|#
directive|define
name|K2G_DEV_DSS0
value|0x0002
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MCBSP0
value|0x0003
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MCASP0
value|0x0004
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MCASP1
value|0x0005
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MCASP2
value|0x0006
end_define

begin_define
define|#
directive|define
name|K2G_DEV_DCAN0
value|0x0008
end_define

begin_define
define|#
directive|define
name|K2G_DEV_DCAN1
value|0x0009
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EMIF0
value|0x000a
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MMCHS0
value|0x000b
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MMCHS1
value|0x000c
end_define

begin_define
define|#
directive|define
name|K2G_DEV_GPMC0
value|0x000d
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ELM0
value|0x000e
end_define

begin_define
define|#
directive|define
name|K2G_DEV_SPI0
value|0x0010
end_define

begin_define
define|#
directive|define
name|K2G_DEV_SPI1
value|0x0011
end_define

begin_define
define|#
directive|define
name|K2G_DEV_SPI2
value|0x0012
end_define

begin_define
define|#
directive|define
name|K2G_DEV_SPI3
value|0x0013
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ICSS0
value|0x0014
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ICSS1
value|0x0015
end_define

begin_define
define|#
directive|define
name|K2G_DEV_USB0
value|0x0016
end_define

begin_define
define|#
directive|define
name|K2G_DEV_USB1
value|0x0017
end_define

begin_define
define|#
directive|define
name|K2G_DEV_NSS0
value|0x0018
end_define

begin_define
define|#
directive|define
name|K2G_DEV_PCIE0
value|0x0019
end_define

begin_define
define|#
directive|define
name|K2G_DEV_GPIO0
value|0x001b
end_define

begin_define
define|#
directive|define
name|K2G_DEV_GPIO1
value|0x001c
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_0
value|0x001d
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_1
value|0x001e
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_2
value|0x001f
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_3
value|0x0020
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_4
value|0x0021
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_5
value|0x0022
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TIMER64_6
value|0x0023
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MSGMGR0
value|0x0025
end_define

begin_define
define|#
directive|define
name|K2G_DEV_BOOTCFG0
value|0x0026
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ARM_BOOTROM0
value|0x0027
end_define

begin_define
define|#
directive|define
name|K2G_DEV_DSP_BOOTROM0
value|0x0029
end_define

begin_define
define|#
directive|define
name|K2G_DEV_DEBUGSS0
value|0x002b
end_define

begin_define
define|#
directive|define
name|K2G_DEV_UART0
value|0x002c
end_define

begin_define
define|#
directive|define
name|K2G_DEV_UART1
value|0x002d
end_define

begin_define
define|#
directive|define
name|K2G_DEV_UART2
value|0x002e
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM0
value|0x002f
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM1
value|0x0030
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM2
value|0x0031
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM3
value|0x0032
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM4
value|0x0033
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EHRPWM5
value|0x0034
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EQEP0
value|0x0035
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EQEP1
value|0x0036
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EQEP2
value|0x0037
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ECAP0
value|0x0038
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ECAP1
value|0x0039
end_define

begin_define
define|#
directive|define
name|K2G_DEV_I2C0
value|0x003a
end_define

begin_define
define|#
directive|define
name|K2G_DEV_I2C1
value|0x003b
end_define

begin_define
define|#
directive|define
name|K2G_DEV_I2C2
value|0x003c
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EDMA0
value|0x003f
end_define

begin_define
define|#
directive|define
name|K2G_DEV_SEMAPHORE0
value|0x0040
end_define

begin_define
define|#
directive|define
name|K2G_DEV_INTC0
value|0x0041
end_define

begin_define
define|#
directive|define
name|K2G_DEV_GIC0
value|0x0042
end_define

begin_define
define|#
directive|define
name|K2G_DEV_QSPI0
value|0x0043
end_define

begin_define
define|#
directive|define
name|K2G_DEV_ARM_64B_COUNTER0
value|0x0044
end_define

begin_define
define|#
directive|define
name|K2G_DEV_TETRIS0
value|0x0045
end_define

begin_define
define|#
directive|define
name|K2G_DEV_CGEM0
value|0x0046
end_define

begin_define
define|#
directive|define
name|K2G_DEV_MSMC0
value|0x0047
end_define

begin_define
define|#
directive|define
name|K2G_DEV_CBASS0
value|0x0049
end_define

begin_define
define|#
directive|define
name|K2G_DEV_BOARD0
value|0x004c
end_define

begin_define
define|#
directive|define
name|K2G_DEV_EDMA1
value|0x004f
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

