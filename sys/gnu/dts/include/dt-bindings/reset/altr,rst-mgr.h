begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, Steffen Trumtrar<s.trumtrar@pengutronix.de>  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_H
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
name|WDS_RESET
value|2
end_define

begin_define
define|#
directive|define
name|SCUPER_RESET
value|3
end_define

begin_define
define|#
directive|define
name|L2_RESET
value|4
end_define

begin_comment
comment|/* PERMODRST */
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
name|USB0_RESET
value|34
end_define

begin_define
define|#
directive|define
name|USB1_RESET
value|35
end_define

begin_define
define|#
directive|define
name|NAND_RESET
value|36
end_define

begin_define
define|#
directive|define
name|QSPI_RESET
value|37
end_define

begin_define
define|#
directive|define
name|L4WD0_RESET
value|38
end_define

begin_define
define|#
directive|define
name|L4WD1_RESET
value|39
end_define

begin_define
define|#
directive|define
name|OSC1TIMER0_RESET
value|40
end_define

begin_define
define|#
directive|define
name|OSC1TIMER1_RESET
value|41
end_define

begin_define
define|#
directive|define
name|SPTIMER0_RESET
value|42
end_define

begin_define
define|#
directive|define
name|SPTIMER1_RESET
value|43
end_define

begin_define
define|#
directive|define
name|I2C0_RESET
value|44
end_define

begin_define
define|#
directive|define
name|I2C1_RESET
value|45
end_define

begin_define
define|#
directive|define
name|I2C2_RESET
value|46
end_define

begin_define
define|#
directive|define
name|I2C3_RESET
value|47
end_define

begin_define
define|#
directive|define
name|UART0_RESET
value|48
end_define

begin_define
define|#
directive|define
name|UART1_RESET
value|49
end_define

begin_define
define|#
directive|define
name|SPIM0_RESET
value|50
end_define

begin_define
define|#
directive|define
name|SPIM1_RESET
value|51
end_define

begin_define
define|#
directive|define
name|SPIS0_RESET
value|52
end_define

begin_define
define|#
directive|define
name|SPIS1_RESET
value|53
end_define

begin_define
define|#
directive|define
name|SDMMC_RESET
value|54
end_define

begin_define
define|#
directive|define
name|CAN0_RESET
value|55
end_define

begin_define
define|#
directive|define
name|CAN1_RESET
value|56
end_define

begin_define
define|#
directive|define
name|GPIO0_RESET
value|57
end_define

begin_define
define|#
directive|define
name|GPIO1_RESET
value|58
end_define

begin_define
define|#
directive|define
name|GPIO2_RESET
value|59
end_define

begin_define
define|#
directive|define
name|DMA_RESET
value|60
end_define

begin_define
define|#
directive|define
name|SDR_RESET
value|61
end_define

begin_comment
comment|/* PER2MODRST */
end_comment

begin_define
define|#
directive|define
name|DMAIF0_RESET
value|64
end_define

begin_define
define|#
directive|define
name|DMAIF1_RESET
value|65
end_define

begin_define
define|#
directive|define
name|DMAIF2_RESET
value|66
end_define

begin_define
define|#
directive|define
name|DMAIF3_RESET
value|67
end_define

begin_define
define|#
directive|define
name|DMAIF4_RESET
value|68
end_define

begin_define
define|#
directive|define
name|DMAIF5_RESET
value|69
end_define

begin_define
define|#
directive|define
name|DMAIF6_RESET
value|70
end_define

begin_define
define|#
directive|define
name|DMAIF7_RESET
value|71
end_define

begin_comment
comment|/* BRGMODRST */
end_comment

begin_define
define|#
directive|define
name|HPS2FPGA_RESET
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
name|FPGA2HPS_RESET
value|98
end_define

begin_comment
comment|/* MISCMODRST*/
end_comment

begin_define
define|#
directive|define
name|ROM_RESET
value|128
end_define

begin_define
define|#
directive|define
name|OCRAM_RESET
value|129
end_define

begin_define
define|#
directive|define
name|SYSMGR_RESET
value|130
end_define

begin_define
define|#
directive|define
name|SYSMGRCOLD_RESET
value|131
end_define

begin_define
define|#
directive|define
name|FPGAMGR_RESET
value|132
end_define

begin_define
define|#
directive|define
name|ACPIDMAP_RESET
value|133
end_define

begin_define
define|#
directive|define
name|S2F_RESET
value|134
end_define

begin_define
define|#
directive|define
name|S2FCOLD_RESET
value|135
end_define

begin_define
define|#
directive|define
name|NRSTPIN_RESET
value|136
end_define

begin_define
define|#
directive|define
name|TIMESTAMPCOLD_RESET
value|137
end_define

begin_define
define|#
directive|define
name|CLKMGRCOLD_RESET
value|138
end_define

begin_define
define|#
directive|define
name|SCANMGR_RESET
value|139
end_define

begin_define
define|#
directive|define
name|FRZCTRLCOLD_RESET
value|140
end_define

begin_define
define|#
directive|define
name|SYSDBG_RESET
value|141
end_define

begin_define
define|#
directive|define
name|DBG_RESET
value|142
end_define

begin_define
define|#
directive|define
name|TAPCOLD_RESET
value|143
end_define

begin_define
define|#
directive|define
name|SDRCOLD_RESET
value|144
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

