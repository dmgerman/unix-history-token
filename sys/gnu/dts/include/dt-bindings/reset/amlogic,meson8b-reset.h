begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, see<http://www.gnu.org/licenses/>.  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * BSD LICENSE  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *   * Neither the name of Intel Corporation nor the names of its  *     contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_AMLOGIC_MESON8B_RESET_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_AMLOGIC_MESON8B_RESET_H
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

begin_define
define|#
directive|define
name|RESET_VLD
value|1
end_define

begin_define
define|#
directive|define
name|RESET_IQIDCT
value|2
end_define

begin_define
define|#
directive|define
name|RESET_MC
value|3
end_define

begin_comment
comment|/*					8	*/
end_comment

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
name|RESET_MCPU
value|7
end_define

begin_define
define|#
directive|define
name|RESET_CCPU
value|8
end_define

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
name|RESET_MDEC
value|13
end_define

begin_define
define|#
directive|define
name|RESET_VLD_PART
value|14
end_define

begin_define
define|#
directive|define
name|RESET_VIFIFO
value|15
end_define

begin_comment
comment|/*					16-31	*/
end_comment

begin_comment
comment|/*	RESET1					*/
end_comment

begin_comment
comment|/*					32	*/
end_comment

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
name|RESET_VDAC_1
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

begin_define
define|#
directive|define
name|RESET_AHB_BRIDGE
value|39
end_define

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
name|RESET_ABUF
value|44
end_define

begin_define
define|#
directive|define
name|RESET_AHB_DATA
value|45
end_define

begin_define
define|#
directive|define
name|RESET_AHB_CNTL
value|46
end_define

begin_define
define|#
directive|define
name|RESET_ROM_BOOT
value|47
end_define

begin_comment
comment|/*					48-63	*/
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
name|RESET_DBLK
value|66
end_define

begin_define
define|#
directive|define
name|RESET_PIC_DC
value|66
end_define

begin_define
define|#
directive|define
name|RESET_PSC
value|66
end_define

begin_define
define|#
directive|define
name|RESET_NAND
value|66
end_define

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

begin_define
define|#
directive|define
name|RESET_HDMI_APB
value|75
end_define

begin_define
define|#
directive|define
name|RESET_AUDIO_APB
value|76
end_define

begin_define
define|#
directive|define
name|RESET_MEDIA_CPU
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
name|RESET_SYS_CPU_0
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
name|RESET_AUDIO_PLL_MODULATOR
value|101
end_define

begin_define
define|#
directive|define
name|RESET_AHB_BRIDGE_CNTL
value|102
end_define

begin_define
define|#
directive|define
name|RESET_SYS_CPU_1
value|103
end_define

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

begin_define
define|#
directive|define
name|RESET_PL310
value|128
end_define

begin_define
define|#
directive|define
name|RESET_A5_APB
value|129
end_define

begin_define
define|#
directive|define
name|RESET_A5_AXI
value|130
end_define

begin_define
define|#
directive|define
name|RESET_A5
value|131
end_define

begin_define
define|#
directive|define
name|RESET_DVIN
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

begin_define
define|#
directive|define
name|RESET_VENCT
value|136
end_define

begin_define
define|#
directive|define
name|RESET_VDAC_4
value|137
end_define

begin_define
define|#
directive|define
name|RESET_RTC
value|138
end_define

begin_define
define|#
directive|define
name|RESET_A5_DEBUG
value|139
end_define

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

begin_comment
comment|/*					142-159	*/
end_comment

begin_comment
comment|/*	RESET5					*/
end_comment

begin_define
define|#
directive|define
name|RESET_DDR_PLL
value|160
end_define

begin_define
define|#
directive|define
name|RESET_MISC_PLL
value|161
end_define

begin_define
define|#
directive|define
name|RESET_SYS_PLL
value|162
end_define

begin_define
define|#
directive|define
name|RESET_HPLL_PLL
value|163
end_define

begin_define
define|#
directive|define
name|RESET_AUDIO_PLL
value|164
end_define

begin_define
define|#
directive|define
name|RESET_VID2_PLL
value|165
end_define

begin_comment
comment|/*					166-191	*/
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
name|RESET_PERIPHS_IR_REMOTE
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
name|RESET_PERIPHS_I2C_MASTER_1
value|197
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_I2C_SLAVE
value|198
end_define

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
name|RESET_PERIPHS_UART_1
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
name|RESET_PERIPHS_SPI_1
value|206
end_define

begin_define
define|#
directive|define
name|RESET_PERIPHS_LED_PWM
value|207
end_define

begin_comment
comment|/*					208-223	*/
end_comment

begin_comment
comment|/*	RESET7					*/
end_comment

begin_comment
comment|/*					224-255	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

