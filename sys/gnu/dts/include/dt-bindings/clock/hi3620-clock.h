begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012-2013 Hisilicon Limited.  * Copyright (c) 2012-2013 Linaro Limited.  *  * Author: Haojian Zhuang<haojian.zhuang@linaro.org>  *	   Xin Li<li.xin@linaro.org>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write to the Free Software Foundation, Inc.,  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HI3620_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HI3620_CLOCK_H
end_define

begin_define
define|#
directive|define
name|HI3620_NONE_CLOCK
value|0
end_define

begin_comment
comment|/* fixed rate& fixed factor clocks */
end_comment

begin_define
define|#
directive|define
name|HI3620_OSC32K
value|1
end_define

begin_define
define|#
directive|define
name|HI3620_OSC26M
value|2
end_define

begin_define
define|#
directive|define
name|HI3620_PCLK
value|3
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_ARM0
value|4
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_ARM1
value|5
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_PERI
value|6
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_USB
value|7
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_HDMI
value|8
end_define

begin_define
define|#
directive|define
name|HI3620_PLL_GPU
value|9
end_define

begin_define
define|#
directive|define
name|HI3620_RCLK_TCXO
value|10
end_define

begin_define
define|#
directive|define
name|HI3620_RCLK_CFGAXI
value|11
end_define

begin_define
define|#
directive|define
name|HI3620_RCLK_PICO
value|12
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|HI3620_TIMER0_MUX
value|32
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER1_MUX
value|33
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER2_MUX
value|34
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER3_MUX
value|35
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER4_MUX
value|36
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER5_MUX
value|37
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER6_MUX
value|38
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER7_MUX
value|39
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER8_MUX
value|40
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER9_MUX
value|41
end_define

begin_define
define|#
directive|define
name|HI3620_UART0_MUX
value|42
end_define

begin_define
define|#
directive|define
name|HI3620_UART1_MUX
value|43
end_define

begin_define
define|#
directive|define
name|HI3620_UART2_MUX
value|44
end_define

begin_define
define|#
directive|define
name|HI3620_UART3_MUX
value|45
end_define

begin_define
define|#
directive|define
name|HI3620_UART4_MUX
value|46
end_define

begin_define
define|#
directive|define
name|HI3620_SPI0_MUX
value|47
end_define

begin_define
define|#
directive|define
name|HI3620_SPI1_MUX
value|48
end_define

begin_define
define|#
directive|define
name|HI3620_SPI2_MUX
value|49
end_define

begin_define
define|#
directive|define
name|HI3620_SAXI_MUX
value|50
end_define

begin_define
define|#
directive|define
name|HI3620_PWM0_MUX
value|51
end_define

begin_define
define|#
directive|define
name|HI3620_PWM1_MUX
value|52
end_define

begin_define
define|#
directive|define
name|HI3620_SD_MUX
value|53
end_define

begin_define
define|#
directive|define
name|HI3620_MMC1_MUX
value|54
end_define

begin_define
define|#
directive|define
name|HI3620_MMC1_MUX2
value|55
end_define

begin_define
define|#
directive|define
name|HI3620_G2D_MUX
value|56
end_define

begin_define
define|#
directive|define
name|HI3620_VENC_MUX
value|57
end_define

begin_define
define|#
directive|define
name|HI3620_VDEC_MUX
value|58
end_define

begin_define
define|#
directive|define
name|HI3620_VPP_MUX
value|59
end_define

begin_define
define|#
directive|define
name|HI3620_EDC0_MUX
value|60
end_define

begin_define
define|#
directive|define
name|HI3620_LDI0_MUX
value|61
end_define

begin_define
define|#
directive|define
name|HI3620_EDC1_MUX
value|62
end_define

begin_define
define|#
directive|define
name|HI3620_LDI1_MUX
value|63
end_define

begin_define
define|#
directive|define
name|HI3620_RCLK_HSIC
value|64
end_define

begin_define
define|#
directive|define
name|HI3620_MMC2_MUX
value|65
end_define

begin_define
define|#
directive|define
name|HI3620_MMC3_MUX
value|66
end_define

begin_comment
comment|/* divider clocks */
end_comment

begin_define
define|#
directive|define
name|HI3620_SHAREAXI_DIV
value|128
end_define

begin_define
define|#
directive|define
name|HI3620_CFGAXI_DIV
value|129
end_define

begin_define
define|#
directive|define
name|HI3620_SD_DIV
value|130
end_define

begin_define
define|#
directive|define
name|HI3620_MMC1_DIV
value|131
end_define

begin_define
define|#
directive|define
name|HI3620_HSIC_DIV
value|132
end_define

begin_define
define|#
directive|define
name|HI3620_MMC2_DIV
value|133
end_define

begin_define
define|#
directive|define
name|HI3620_MMC3_DIV
value|134
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|HI3620_TIMERCLK01
value|160
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER_RCLK01
value|161
end_define

begin_define
define|#
directive|define
name|HI3620_TIMERCLK23
value|162
end_define

begin_define
define|#
directive|define
name|HI3620_TIMER_RCLK23
value|163
end_define

begin_define
define|#
directive|define
name|HI3620_TIMERCLK45
value|164
end_define

begin_define
define|#
directive|define
name|HI3620_TIMERCLK67
value|165
end_define

begin_define
define|#
directive|define
name|HI3620_TIMERCLK89
value|166
end_define

begin_define
define|#
directive|define
name|HI3620_RTCCLK
value|167
end_define

begin_define
define|#
directive|define
name|HI3620_KPC_CLK
value|168
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK0
value|169
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK1
value|170
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK2
value|171
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK3
value|172
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK4
value|173
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK5
value|174
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK6
value|175
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK7
value|176
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK8
value|177
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK9
value|178
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK10
value|179
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK11
value|180
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK12
value|181
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK13
value|182
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK14
value|183
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK15
value|184
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK16
value|185
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK17
value|186
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK18
value|187
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK19
value|188
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK20
value|189
end_define

begin_define
define|#
directive|define
name|HI3620_GPIOCLK21
value|190
end_define

begin_define
define|#
directive|define
name|HI3620_DPHY0_CLK
value|191
end_define

begin_define
define|#
directive|define
name|HI3620_DPHY1_CLK
value|192
end_define

begin_define
define|#
directive|define
name|HI3620_DPHY2_CLK
value|193
end_define

begin_define
define|#
directive|define
name|HI3620_USBPHY_CLK
value|194
end_define

begin_define
define|#
directive|define
name|HI3620_ACP_CLK
value|195
end_define

begin_define
define|#
directive|define
name|HI3620_PWMCLK0
value|196
end_define

begin_define
define|#
directive|define
name|HI3620_PWMCLK1
value|197
end_define

begin_define
define|#
directive|define
name|HI3620_UARTCLK0
value|198
end_define

begin_define
define|#
directive|define
name|HI3620_UARTCLK1
value|199
end_define

begin_define
define|#
directive|define
name|HI3620_UARTCLK2
value|200
end_define

begin_define
define|#
directive|define
name|HI3620_UARTCLK3
value|201
end_define

begin_define
define|#
directive|define
name|HI3620_UARTCLK4
value|202
end_define

begin_define
define|#
directive|define
name|HI3620_SPICLK0
value|203
end_define

begin_define
define|#
directive|define
name|HI3620_SPICLK1
value|204
end_define

begin_define
define|#
directive|define
name|HI3620_SPICLK2
value|205
end_define

begin_define
define|#
directive|define
name|HI3620_I2CCLK0
value|206
end_define

begin_define
define|#
directive|define
name|HI3620_I2CCLK1
value|207
end_define

begin_define
define|#
directive|define
name|HI3620_I2CCLK2
value|208
end_define

begin_define
define|#
directive|define
name|HI3620_I2CCLK3
value|209
end_define

begin_define
define|#
directive|define
name|HI3620_SCI_CLK
value|210
end_define

begin_define
define|#
directive|define
name|HI3620_DDRC_PER_CLK
value|211
end_define

begin_define
define|#
directive|define
name|HI3620_DMAC_CLK
value|212
end_define

begin_define
define|#
directive|define
name|HI3620_USB2DVC_CLK
value|213
end_define

begin_define
define|#
directive|define
name|HI3620_SD_CLK
value|214
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CLK1
value|215
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CLK2
value|216
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CLK3
value|217
end_define

begin_define
define|#
directive|define
name|HI3620_MCU_CLK
value|218
end_define

begin_define
define|#
directive|define
name|HI3620_SD_CIUCLK
value|0
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CIUCLK1
value|1
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CIUCLK2
value|2
end_define

begin_define
define|#
directive|define
name|HI3620_MMC_CIUCLK3
value|3
end_define

begin_define
define|#
directive|define
name|HI3620_NR_CLKS
value|219
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HI3620_CLOCK_H */
end_comment

end_unit

