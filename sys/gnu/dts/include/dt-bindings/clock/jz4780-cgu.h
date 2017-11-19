begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides clock numbers for the ingenic,jz4780-cgu DT binding.  *  * They are roughly ordered as:  *   - external clocks  *   - PLLs  *   - muxes/dividers in the order they appear in the jz4780 programmers manual  *   - gates in order of their bit in the CLKGR* registers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_JZ4780_CGU_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_JZ4780_CGU_H__
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_EXCLK
value|0
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_RTCLK
value|1
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_APLL
value|2
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MPLL
value|3
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_EPLL
value|4
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_VPLL
value|5
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_OTGPHY
value|6
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SCLKA
value|7
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_CPUMUX
value|8
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_CPU
value|9
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_L2CACHE
value|10
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AHB0
value|11
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AHB2PMUX
value|12
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AHB2
value|13
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_PCLK
value|14
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_DDR
value|15
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_VPU
value|16
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_I2SPLL
value|17
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_I2S
value|18
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_LCD0PIXCLK
value|19
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_LCD1PIXCLK
value|20
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MSCMUX
value|21
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MSC0
value|22
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MSC1
value|23
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MSC2
value|24
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UHC
value|25
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SSIPLL
value|26
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SSI
value|27
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_CIMMCLK
value|28
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_PCMPLL
value|29
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_PCM
value|30
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_GPU
value|31
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_HDMI
value|32
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_BCH
value|33
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_NEMC
value|34
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_OTG0
value|35
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SSI0
value|36
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SMB0
value|37
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SMB1
value|38
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SCC
value|39
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AIC
value|40
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_TSSI0
value|41
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_OWI
value|42
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_KBC
value|43
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SADC
value|44
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UART0
value|45
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UART1
value|46
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UART2
value|47
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UART3
value|48
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SSI1
value|49
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SSI2
value|50
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_PDMA
value|51
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_GPS
value|52
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_MAC
value|53
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SMB2
value|54
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_CIM
value|55
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_LCD
value|56
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_TVE
value|57
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_IPU
value|58
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_DDR0
value|59
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_DDR1
value|60
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SMB3
value|61
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_TSSI1
value|62
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_COMPRESS
value|63
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AIC1
value|64
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_GPVLC
value|65
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_OTG1
value|66
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_UART4
value|67
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_AHBMON
value|68
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_SMB4
value|69
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_DES
value|70
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_X2D
value|71
end_define

begin_define
define|#
directive|define
name|JZ4780_CLK_CORE1
value|72
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_JZ4780_CGU_H__ */
end_comment

end_unit

