begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, see<http://www.gnu.org/licenses/>.  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * BSD LICENSE  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *   * Neither the name of Intel Corporation nor the names of its  *     contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_AMLOGIC_MESON_GXBB_RESET_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_AMLOGIC_MESON_GXBB_RESET_H
end_define

begin_comment
comment|/*	RESET0					*/
end_comment

begin_define
define|#
directive|define
name|RESET_HIU
value|0
end_define

begin_comment
comment|/*					1	*/
end_comment

begin_define
define|#
directive|define
name|RESET_DOS_RESET
value|2
end_define

begin_define
define|#
directive|define
name|RESET_DDR_TOP
value|3
end_define

begin_define
define|#
directive|define
name|RESET_DCU_RESET
value|4
end_define

begin_define
define|#
directive|define
name|RESET_VIU
value|5
end_define

begin_define
define|#
directive|define
name|RESET_AIU
value|6
end_define

begin_define
define|#
directive|define
name|RESET_VID_PLL_DIV
value|7
end_define

begin_comment
comment|/*					8	*/
end_comment

begin_define
define|#
directive|define
name|RESET_PMUX
value|9
end_define

begin_define
define|#
directive|define
name|RESET_VENC
value|10
end_define

begin_define
define|#
directive|define
name|RESET_ASSIST
value|11
end_define

begin_define
define|#
directive|define
name|RESET_AFIFO2
value|12
end_define

begin_define
define|#
directive|define
name|RESET_VCBUS
value|13
end_define

begin_comment
comment|/*					14	*/
end_comment

begin_comment
comment|/*					15	*/
end_comment

begin_define
define|#
directive|define
name|RESET_GIC
value|16
end_define

begin_define
define|#
directive|define
name|RESET_CAPB3_DECODE
value|17
end_define

begin_define
define|#
directive|define
name|RESET_NAND_CAPB3
value|18
end_define

begin_define
define|#
directive|define
name|RESET_HDMITX_CAPB3
value|19
end_define

begin_define
define|#
directive|define
name|RESET_MALI_CAPB3
value|20
end_define

begin_define
define|#
directive|define
name|RESET_DOS_CAPB3
value|21
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_CAPB3
value|22
end_define

begin_define
define|#
directive|define
name|RESET_CBUS_CAPB3
value|23
end_define

begin_define
define|#
directive|define
name|RESET_AHB_CNTL
value|24
end_define

begin_define
define|#
directive|define
name|RESET_AHB_DATA
value|25
end_define

begin_define
define|#
directive|define
name|RESET_VCBUS_CLK81
value|26
end_define

begin_define
define|#
directive|define
name|RESET_MMC
value|27
end_define

begin_define
define|#
directive|define
name|RESET_MIPI_0
value|28
end_define

begin_define
define|#
directive|define
name|RESET_MIPI_1
value|29
end_define

begin_define
define|#
directive|define
name|RESET_MIPI_2
value|30
end_define

begin_define
define|#
directive|define
name|RESET_MIPI_3
value|31
end_define

begin_comment
comment|/*	RESET1					*/
end_comment

begin_define
define|#
directive|define
name|RESET_CPPM
value|32
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX
value|33
end_define

begin_define
define|#
directive|define
name|RESET_USB_OTG
value|34
end_define

begin_define
define|#
directive|define
name|RESET_DDR
value|35
end_define

begin_define
define|#
directive|define
name|RESET_AO_RESET
value|36
end_define

begin_define
define|#
directive|define
name|RESET_BT656
value|37
end_define

begin_define
define|#
directive|define
name|RESET_AHB_SRAM
value|38
end_define

begin_comment
comment|/*					39	*/
end_comment

begin_define
define|#
directive|define
name|RESET_PARSER
value|40
end_define

begin_define
define|#
directive|define
name|RESET_BLKMV
value|41
end_define

begin_define
define|#
directive|define
name|RESET_ISA
value|42
end_define

begin_define
define|#
directive|define
name|RESET_ETHERNET
value|43
end_define

begin_define
define|#
directive|define
name|RESET_SD_EMMC_A
value|44
end_define

begin_define
define|#
directive|define
name|RESET_SD_EMMC_B
value|45
end_define

begin_define
define|#
directive|define
name|RESET_SD_EMMC_C
value|46
end_define

begin_define
define|#
directive|define
name|RESET_ROM_BOOT
value|47
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_0
value|48
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_1
value|49
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_2
value|50
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_3
value|51
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_CORE_0
value|52
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_CORE_1
value|53
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_CORE_2
value|54
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_CORE_3
value|55
end_define

begin_define
define|#
directive|define
name|RESET_SYS_PLL_DIV
value|56
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_AXI
value|57
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_L2
value|58
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_P
value|59
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_MBIST
value|60
end_define

begin_comment
comment|/*					61	*/
end_comment

begin_comment
comment|/*					62	*/
end_comment

begin_comment
comment|/*					63	*/
end_comment

begin_comment
comment|/*	RESET2					*/
end_comment

begin_define
define|#
directive|define
name|RESET_VD_RMEM
value|64
end_define

begin_define
define|#
directive|define
name|RESET_AUDIN
value|65
end_define

begin_define
define|#
directive|define
name|RESET_HDMI_TX
value|66
end_define

begin_comment
comment|/*					67	*/
end_comment

begin_comment
comment|/*					68	*/
end_comment

begin_comment
comment|/*					69	*/
end_comment

begin_define
define|#
directive|define
name|RESET_GE2D
value|70
end_define

begin_define
define|#
directive|define
name|RESET_PARSER_REG
value|71
end_define

begin_define
define|#
directive|define
name|RESET_PARSER_FETCH
value|72
end_define

begin_define
define|#
directive|define
name|RESET_PARSER_CTL
value|73
end_define

begin_define
define|#
directive|define
name|RESET_PARSER_TOP
value|74
end_define

begin_comment
comment|/*					75	*/
end_comment

begin_comment
comment|/*					76	*/
end_comment

begin_define
define|#
directive|define
name|RESET_AO_CPU_RESET
value|77
end_define

begin_define
define|#
directive|define
name|RESET_MALI
value|78
end_define

begin_define
define|#
directive|define
name|RESET_HDMI_SYSTEM_RESET
value|79
end_define

begin_comment
comment|/*					80-95	*/
end_comment

begin_comment
comment|/*	RESET3					*/
end_comment

begin_define
define|#
directive|define
name|RESET_RING_OSCILLATOR
value|96
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU
value|97
end_define

begin_define
define|#
directive|define
name|RESET_EFUSE
value|98
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_BVCI
value|99
end_define

begin_define
define|#
directive|define
name|RESET_AIFIFO
value|100
end_define

begin_define
define|#
directive|define
name|RESET_TVFE
value|101
end_define

begin_define
define|#
directive|define
name|RESET_AHB_BRIDGE_CNTL
value|102
end_define

begin_comment
comment|/*					103	*/
end_comment

begin_define
define|#
directive|define
name|RESET_AUDIO_DAC
value|104
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_TOP
value|105
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_DES
value|106
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_S2P_0
value|107
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_S2P_1
value|108
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_RESET_0
value|109
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_RESET_1
value|110
end_define

begin_define
define|#
directive|define
name|RESET_DEMUX_RESET_2
value|111
end_define

begin_comment
comment|/*					112-127	*/
end_comment

begin_comment
comment|/*	RESET4					*/
end_comment

begin_comment
comment|/*					128	*/
end_comment

begin_comment
comment|/*					129	*/
end_comment

begin_comment
comment|/*					130	*/
end_comment

begin_comment
comment|/*					131	*/
end_comment

begin_define
define|#
directive|define
name|RESET_DVIN_RESET
value|132
end_define

begin_define
define|#
directive|define
name|RESET_RDMA
value|133
end_define

begin_define
define|#
directive|define
name|RESET_VENCI
value|134
end_define

begin_define
define|#
directive|define
name|RESET_VENCP
value|135
end_define

begin_comment
comment|/*					136	*/
end_comment

begin_define
define|#
directive|define
name|RESET_VDAC
value|137
end_define

begin_define
define|#
directive|define
name|RESET_RTC
value|138
end_define

begin_comment
comment|/*					139	*/
end_comment

begin_define
define|#
directive|define
name|RESET_VDI6
value|140
end_define

begin_define
define|#
directive|define
name|RESET_VENCL
value|141
end_define

begin_define
define|#
directive|define
name|RESET_I2C_MASTER_2
value|142
end_define

begin_define
define|#
directive|define
name|RESET_I2C_MASTER_1
value|143
end_define

begin_comment
comment|/*					144-159	*/
end_comment

begin_comment
comment|/*	RESET5					*/
end_comment

begin_comment
comment|/*					160-191	*/
end_comment

begin_comment
comment|/*	RESET6					*/
end_comment

begin_define
define|#
directive|define
name|RESET_PERIPHS_GENERAL
value|192
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SPICC
value|193
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SMART_CARD
value|194
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SAR_ADC
value|195
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_I2C_MASTER_0
value|196
end_define

begin_define
define|#
directive|define
name|RESET_SANA
value|197
end_define

begin_comment
comment|/*					198	*/
end_comment

begin_define
define|#
directive|define
name|RESET_PERIPHS_STREAM_INTERFACE
value|199
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SDIO
value|200
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_UART_0
value|201
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_UART_1_2
value|202
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_ASYNC_0
value|203
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_ASYNC_1
value|204
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SPI_0
value|205
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_SDHC
value|206
end_define

begin_define
define|#
directive|define
name|RESET_UART_SLIP
value|207
end_define

begin_comment
comment|/*					208-223	*/
end_comment

begin_comment
comment|/*	RESET7					*/
end_comment

begin_define
define|#
directive|define
name|RESET_USB_DDR_0
value|224
end_define

begin_define
define|#
directive|define
name|RESET_USB_DDR_1
value|225
end_define

begin_define
define|#
directive|define
name|RESET_USB_DDR_2
value|226
end_define

begin_define
define|#
directive|define
name|RESET_USB_DDR_3
value|227
end_define

begin_comment
comment|/*					228	*/
end_comment

begin_define
define|#
directive|define
name|RESET_DEVICE_MMC_ARB
value|229
end_define

begin_comment
comment|/*					230	*/
end_comment

begin_define
define|#
directive|define
name|RESET_VID_LOCK
value|231
end_define

begin_define
define|#
directive|define
name|RESET_A9_DMC_PIPEL
value|232
end_define

begin_comment
comment|/*					233-255	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

