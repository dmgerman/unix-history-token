begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Intel Corporation. All rights reserved  * Copyright (C) 2016 Altera Corporation. All rights reserved  *  * This program is free software; you can redistribute it and/or modify  * it under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License along with  * this program.  If not, see<http://www.gnu.org/licenses/>.  *  * derived from Steffen Trumtrar's "altr,rst-mgr-a10.h"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_S10_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_S10_H
end_define

begin_comment
comment|/* MPUMODRST */
end_comment

begin_define
define|#
directive|define
name|CPU0_RESET
value|0
end_define

begin_define
define|#
directive|define
name|CPU1_RESET
value|1
end_define

begin_define
define|#
directive|define
name|CPU2_RESET
value|2
end_define

begin_define
define|#
directive|define
name|CPU3_RESET
value|3
end_define

begin_comment
comment|/* PER0MODRST */
end_comment

begin_define
define|#
directive|define
name|EMAC0_RESET
value|32
end_define

begin_define
define|#
directive|define
name|EMAC1_RESET
value|33
end_define

begin_define
define|#
directive|define
name|EMAC2_RESET
value|34
end_define

begin_define
define|#
directive|define
name|USB0_RESET
value|35
end_define

begin_define
define|#
directive|define
name|USB1_RESET
value|36
end_define

begin_define
define|#
directive|define
name|NAND_RESET
value|37
end_define

begin_comment
comment|/* 38 is empty */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RESET
value|39
end_define

begin_define
define|#
directive|define
name|EMAC0_OCP_RESET
value|40
end_define

begin_define
define|#
directive|define
name|EMAC1_OCP_RESET
value|41
end_define

begin_define
define|#
directive|define
name|EMAC2_OCP_RESET
value|42
end_define

begin_define
define|#
directive|define
name|USB0_OCP_RESET
value|43
end_define

begin_define
define|#
directive|define
name|USB1_OCP_RESET
value|44
end_define

begin_define
define|#
directive|define
name|NAND_OCP_RESET
value|45
end_define

begin_comment
comment|/* 46 is empty */
end_comment

begin_define
define|#
directive|define
name|SDMMC_OCP_RESET
value|47
end_define

begin_define
define|#
directive|define
name|DMA_RESET
value|48
end_define

begin_define
define|#
directive|define
name|SPIM0_RESET
value|49
end_define

begin_define
define|#
directive|define
name|SPIM1_RESET
value|50
end_define

begin_define
define|#
directive|define
name|SPIS0_RESET
value|51
end_define

begin_define
define|#
directive|define
name|SPIS1_RESET
value|52
end_define

begin_define
define|#
directive|define
name|DMA_OCP_RESET
value|53
end_define

begin_define
define|#
directive|define
name|EMAC_PTP_RESET
value|54
end_define

begin_comment
comment|/* 55 is empty*/
end_comment

begin_define
define|#
directive|define
name|DMAIF0_RESET
value|56
end_define

begin_define
define|#
directive|define
name|DMAIF1_RESET
value|57
end_define

begin_define
define|#
directive|define
name|DMAIF2_RESET
value|58
end_define

begin_define
define|#
directive|define
name|DMAIF3_RESET
value|59
end_define

begin_define
define|#
directive|define
name|DMAIF4_RESET
value|60
end_define

begin_define
define|#
directive|define
name|DMAIF5_RESET
value|61
end_define

begin_define
define|#
directive|define
name|DMAIF6_RESET
value|62
end_define

begin_define
define|#
directive|define
name|DMAIF7_RESET
value|63
end_define

begin_comment
comment|/* PER1MODRST */
end_comment

begin_define
define|#
directive|define
name|WATCHDOG0_RESET
value|64
end_define

begin_define
define|#
directive|define
name|WATCHDOG1_RESET
value|65
end_define

begin_define
define|#
directive|define
name|WATCHDOG2_RESET
value|66
end_define

begin_define
define|#
directive|define
name|WATCHDOG3_RESET
value|67
end_define

begin_define
define|#
directive|define
name|L4SYSTIMER0_RESET
value|68
end_define

begin_define
define|#
directive|define
name|L4SYSTIMER1_RESET
value|69
end_define

begin_define
define|#
directive|define
name|SPTIMER0_RESET
value|70
end_define

begin_define
define|#
directive|define
name|SPTIMER1_RESET
value|71
end_define

begin_define
define|#
directive|define
name|I2C0_RESET
value|72
end_define

begin_define
define|#
directive|define
name|I2C1_RESET
value|73
end_define

begin_define
define|#
directive|define
name|I2C2_RESET
value|74
end_define

begin_define
define|#
directive|define
name|I2C3_RESET
value|75
end_define

begin_define
define|#
directive|define
name|I2C4_RESET
value|76
end_define

begin_comment
comment|/* 77-79 is empty */
end_comment

begin_define
define|#
directive|define
name|UART0_RESET
value|80
end_define

begin_define
define|#
directive|define
name|UART1_RESET
value|81
end_define

begin_comment
comment|/* 82-87 is empty */
end_comment

begin_define
define|#
directive|define
name|GPIO0_RESET
value|88
end_define

begin_define
define|#
directive|define
name|GPIO1_RESET
value|89
end_define

begin_comment
comment|/* BRGMODRST */
end_comment

begin_define
define|#
directive|define
name|SOC2FPGA_RESET
value|96
end_define

begin_define
define|#
directive|define
name|LWHPS2FPGA_RESET
value|97
end_define

begin_define
define|#
directive|define
name|FPGA2SOC_RESET
value|98
end_define

begin_define
define|#
directive|define
name|F2SSDRAM0_RESET
value|99
end_define

begin_define
define|#
directive|define
name|F2SSDRAM1_RESET
value|100
end_define

begin_define
define|#
directive|define
name|F2SSDRAM2_RESET
value|101
end_define

begin_define
define|#
directive|define
name|DDRSCH_RESET
value|102
end_define

begin_comment
comment|/* COLDMODRST */
end_comment

begin_define
define|#
directive|define
name|CPUPO0_RESET
value|160
end_define

begin_define
define|#
directive|define
name|CPUPO1_RESET
value|161
end_define

begin_define
define|#
directive|define
name|CPUPO2_RESET
value|162
end_define

begin_define
define|#
directive|define
name|CPUPO3_RESET
value|163
end_define

begin_comment
comment|/* 164-167 is empty */
end_comment

begin_define
define|#
directive|define
name|L2_RESET
value|168
end_define

begin_comment
comment|/* DBGMODRST */
end_comment

begin_define
define|#
directive|define
name|DBG_RESET
value|224
end_define

begin_define
define|#
directive|define
name|CSDAP_RESET
value|225
end_define

begin_comment
comment|/* TAPMODRST */
end_comment

begin_define
define|#
directive|define
name|TAP_RESET
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

