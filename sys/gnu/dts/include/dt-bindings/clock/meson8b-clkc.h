begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * Meson8b clock tree IDs  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MESON8B_CLKC_H
end_ifndef

begin_define
define|#
directive|define
name|__MESON8B_CLKC_H
end_define

begin_define
define|#
directive|define
name|CLKID_UNUSED
value|0
end_define

begin_define
define|#
directive|define
name|CLKID_XTAL
value|1
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_FIXED
value|2
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_VID
value|3
end_define

begin_define
define|#
directive|define
name|CLKID_PLL_SYS
value|4
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV2
value|5
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV3
value|6
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV4
value|7
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV5
value|8
end_define

begin_define
define|#
directive|define
name|CLKID_FCLK_DIV7
value|9
end_define

begin_define
define|#
directive|define
name|CLKID_CLK81
value|10
end_define

begin_define
define|#
directive|define
name|CLKID_MALI
value|11
end_define

begin_define
define|#
directive|define
name|CLKID_CPUCLK
value|12
end_define

begin_define
define|#
directive|define
name|CLKID_ZERO
value|13
end_define

begin_define
define|#
directive|define
name|CLKID_MPEG_SEL
value|14
end_define

begin_define
define|#
directive|define
name|CLKID_MPEG_DIV
value|15
end_define

begin_define
define|#
directive|define
name|CLKID_DDR
value|16
end_define

begin_define
define|#
directive|define
name|CLKID_DOS
value|17
end_define

begin_define
define|#
directive|define
name|CLKID_ISA
value|18
end_define

begin_define
define|#
directive|define
name|CLKID_PL301
value|19
end_define

begin_define
define|#
directive|define
name|CLKID_PERIPHS
value|20
end_define

begin_define
define|#
directive|define
name|CLKID_SPICC
value|21
end_define

begin_define
define|#
directive|define
name|CLKID_I2C
value|22
end_define

begin_define
define|#
directive|define
name|CLKID_SAR_ADC
value|23
end_define

begin_define
define|#
directive|define
name|CLKID_SMART_CARD
value|24
end_define

begin_define
define|#
directive|define
name|CLKID_RNG0
value|25
end_define

begin_define
define|#
directive|define
name|CLKID_UART0
value|26
end_define

begin_define
define|#
directive|define
name|CLKID_SDHC
value|27
end_define

begin_define
define|#
directive|define
name|CLKID_STREAM
value|28
end_define

begin_define
define|#
directive|define
name|CLKID_ASYNC_FIFO
value|29
end_define

begin_define
define|#
directive|define
name|CLKID_SDIO
value|30
end_define

begin_define
define|#
directive|define
name|CLKID_ABUF
value|31
end_define

begin_define
define|#
directive|define
name|CLKID_HIU_IFACE
value|32
end_define

begin_define
define|#
directive|define
name|CLKID_ASSIST_MISC
value|33
end_define

begin_define
define|#
directive|define
name|CLKID_SPI
value|34
end_define

begin_define
define|#
directive|define
name|CLKID_I2S_SPDIF
value|35
end_define

begin_define
define|#
directive|define
name|CLKID_ETH
value|36
end_define

begin_define
define|#
directive|define
name|CLKID_DEMUX
value|37
end_define

begin_define
define|#
directive|define
name|CLKID_AIU_GLUE
value|38
end_define

begin_define
define|#
directive|define
name|CLKID_IEC958
value|39
end_define

begin_define
define|#
directive|define
name|CLKID_I2S_OUT
value|40
end_define

begin_define
define|#
directive|define
name|CLKID_AMCLK
value|41
end_define

begin_define
define|#
directive|define
name|CLKID_AIFIFO2
value|42
end_define

begin_define
define|#
directive|define
name|CLKID_MIXER
value|43
end_define

begin_define
define|#
directive|define
name|CLKID_MIXER_IFACE
value|44
end_define

begin_define
define|#
directive|define
name|CLKID_ADC
value|45
end_define

begin_define
define|#
directive|define
name|CLKID_BLKMV
value|46
end_define

begin_define
define|#
directive|define
name|CLKID_AIU
value|47
end_define

begin_define
define|#
directive|define
name|CLKID_UART1
value|48
end_define

begin_define
define|#
directive|define
name|CLKID_G2D
value|49
end_define

begin_define
define|#
directive|define
name|CLKID_USB0
value|50
end_define

begin_define
define|#
directive|define
name|CLKID_USB1
value|51
end_define

begin_define
define|#
directive|define
name|CLKID_RESET
value|52
end_define

begin_define
define|#
directive|define
name|CLKID_NAND
value|53
end_define

begin_define
define|#
directive|define
name|CLKID_DOS_PARSER
value|54
end_define

begin_define
define|#
directive|define
name|CLKID_USB
value|55
end_define

begin_define
define|#
directive|define
name|CLKID_VDIN1
value|56
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_ARB0
value|57
end_define

begin_define
define|#
directive|define
name|CLKID_EFUSE
value|58
end_define

begin_define
define|#
directive|define
name|CLKID_BOOT_ROM
value|59
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_DATA_BUS
value|60
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_CTRL_BUS
value|61
end_define

begin_define
define|#
directive|define
name|CLKID_HDMI_INTR_SYNC
value|62
end_define

begin_define
define|#
directive|define
name|CLKID_HDMI_PCLK
value|63
end_define

begin_define
define|#
directive|define
name|CLKID_USB1_DDR_BRIDGE
value|64
end_define

begin_define
define|#
directive|define
name|CLKID_USB0_DDR_BRIDGE
value|65
end_define

begin_define
define|#
directive|define
name|CLKID_MMC_PCLK
value|66
end_define

begin_define
define|#
directive|define
name|CLKID_DVIN
value|67
end_define

begin_define
define|#
directive|define
name|CLKID_UART2
value|68
end_define

begin_define
define|#
directive|define
name|CLKID_SANA
value|69
end_define

begin_define
define|#
directive|define
name|CLKID_VPU_INTR
value|70
end_define

begin_define
define|#
directive|define
name|CLKID_SEC_AHB_AHB3_BRIDGE
value|71
end_define

begin_define
define|#
directive|define
name|CLKID_CLK81_A9
value|72
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCI0
value|73
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCI1
value|74
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCP0
value|75
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCP1
value|76
end_define

begin_define
define|#
directive|define
name|CLKID_GCLK_VENCI_INT
value|77
end_define

begin_define
define|#
directive|define
name|CLKID_GCLK_VENCP_INT
value|78
end_define

begin_define
define|#
directive|define
name|CLKID_DAC_CLK
value|79
end_define

begin_define
define|#
directive|define
name|CLKID_AOCLK_GATE
value|80
end_define

begin_define
define|#
directive|define
name|CLKID_IEC958_GATE
value|81
end_define

begin_define
define|#
directive|define
name|CLKID_ENC480P
value|82
end_define

begin_define
define|#
directive|define
name|CLKID_RNG1
value|83
end_define

begin_define
define|#
directive|define
name|CLKID_GCLK_VENCL_INT
value|84
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCLMCC
value|85
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_VENCL
value|86
end_define

begin_define
define|#
directive|define
name|CLKID_VCLK2_OTHER
value|87
end_define

begin_define
define|#
directive|define
name|CLKID_EDP
value|88
end_define

begin_define
define|#
directive|define
name|CLKID_AO_MEDIA_CPU
value|89
end_define

begin_define
define|#
directive|define
name|CLKID_AO_AHB_SRAM
value|90
end_define

begin_define
define|#
directive|define
name|CLKID_AO_AHB_BUS
value|91
end_define

begin_define
define|#
directive|define
name|CLKID_AO_IFACE
value|92
end_define

begin_define
define|#
directive|define
name|CLKID_MPLL0
value|93
end_define

begin_define
define|#
directive|define
name|CLKID_MPLL1
value|94
end_define

begin_define
define|#
directive|define
name|CLKID_MPLL2
value|95
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MESON8B_CLKC_H */
end_comment

end_unit

