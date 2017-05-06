begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MTK_SOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MTK_SOC_H_
end_define

begin_enum
enum|enum
name|mtk_soc_id
block|{
name|MTK_SOC_UNKNOWN
block|,
name|MTK_SOC_RT2880
block|,
name|MTK_SOC_RT3050
block|,
name|MTK_SOC_RT3052
block|,
name|MTK_SOC_RT3350
block|,
name|MTK_SOC_RT3352
block|,
name|MTK_SOC_RT3662
block|,
name|MTK_SOC_RT3883
block|,
name|MTK_SOC_RT5350
block|,
name|MTK_SOC_MT7620A
block|,
name|MTK_SOC_MT7620N
block|,
name|MTK_SOC_MT7621
block|,
name|MTK_SOC_MT7628
block|,
name|MTK_SOC_MT7688
block|,
name|MTK_SOC_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|RT2880_CPU_CLKSEL_OFF
value|20
end_define

begin_define
define|#
directive|define
name|RT2880_CPU_CLKSEL_MSK
value|0x3
end_define

begin_define
define|#
directive|define
name|RT305X_CPU_CLKSEL_OFF
value|18
end_define

begin_define
define|#
directive|define
name|RT305X_CPU_CLKSEL_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|RT3352_CPU_CLKSEL_OFF
value|8
end_define

begin_define
define|#
directive|define
name|RT3352_CPU_CLKSEL_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|RT3883_CPU_CLKSEL_OFF
value|8
end_define

begin_define
define|#
directive|define
name|RT3883_CPU_CLKSEL_MSK
value|0x3
end_define

begin_define
define|#
directive|define
name|RT5350_CPU_CLKSEL_OFF1
value|8
end_define

begin_define
define|#
directive|define
name|RT5350_CPU_CLKSEL_OFF2
value|10
end_define

begin_define
define|#
directive|define
name|RT5350_CPU_CLKSEL_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|MT7628_CPU_CLKSEL_OFF
value|6
end_define

begin_define
define|#
directive|define
name|MT7628_CPU_CLKSEL_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|MT7620_CPU_CLK_AUX0
value|(1u<<24)
end_define

begin_define
define|#
directive|define
name|MT7620_CPLL_SW_CFG
value|(1u<<31)
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_MULT_RATIO_OFF
value|16
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_MULT_RATIO_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_MULT_RATIO_BASE
value|24
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_DIV_RATIO_OFF
value|10
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_DIV_RATIO_MSK
value|0x3
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_DIV_RATIO_BASE
value|2
end_define

begin_define
define|#
directive|define
name|MT7620_PLL_DIV_RATIO_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MT7620_XTAL_40
value|40
end_define

begin_define
define|#
directive|define
name|MT7621_USES_MEMDIV
value|(1u<<30)
end_define

begin_define
define|#
directive|define
name|MT7621_MEMDIV_OFF
value|4
end_define

begin_define
define|#
directive|define
name|MT7621_MEMDIV_MSK
value|0x7f
end_define

begin_define
define|#
directive|define
name|MT7621_MEMDIV_BASE
value|1
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_OFF
value|6
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_25MHZ_VAL
value|6
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_20MHZ_VAL
value|3
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_20MHZ
value|20
end_define

begin_define
define|#
directive|define
name|MT7621_CLKSEL_25MHZ
value|25
end_define

begin_define
define|#
directive|define
name|MT7621_CLK_STS_DIV_OFF
value|8
end_define

begin_define
define|#
directive|define
name|MT7621_CLK_STS_MSK
value|0x1f
end_define

begin_define
define|#
directive|define
name|MT7621_CLK_STS_BASE
value|500
end_define

begin_define
define|#
directive|define
name|MTK_MT7621_CLKDIV_REG
value|0x5648
end_define

begin_define
define|#
directive|define
name|MTK_MT7621_CLKDIV_OFF
value|4
end_define

begin_define
define|#
directive|define
name|MTK_MT7621_CLKDIV_MSK
value|0x7f
end_define

begin_define
define|#
directive|define
name|MTK_MHZ
parameter_list|(
name|x
parameter_list|)
value|((x) * 1000 * 1000)
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_233MHZ
value|233333333
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_250MHZ
value|250000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_266MHZ
value|266666666
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_280MHZ
value|280000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_300MHZ
value|300000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_320MHZ
value|320000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_360MHZ
value|360000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_384MHZ
value|384000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_400MHZ
value|400000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_480MHZ
value|480000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_500MHZ
value|500000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_575MHZ
value|575000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_580MHZ
value|580000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_600MHZ
value|600000000
end_define

begin_define
define|#
directive|define
name|MTK_CPU_CLK_880MHZ
value|880000000
end_define

begin_define
define|#
directive|define
name|MTK_UART_CLK_40MHZ
value|40000000
end_define

begin_define
define|#
directive|define
name|MTK_UART_CLK_50MHZ
value|50000000
end_define

begin_define
define|#
directive|define
name|MTK_UARTDIV_2
value|2
end_define

begin_define
define|#
directive|define
name|MTK_UARTDIV_3
value|3
end_define

begin_define
define|#
directive|define
name|MTK_DEFAULT_BASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MTK_RT2880_BASE
value|0x00300000
end_define

begin_define
define|#
directive|define
name|MTK_MT7621_BASE
value|0x1e000000
end_define

begin_define
define|#
directive|define
name|MTK_DEFAULT_SIZE
value|0x6000
end_define

begin_function_decl
specifier|extern
name|void
name|mtk_soc_try_early_detect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|mtk_soc_get_uartclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|mtk_soc_get_cpuclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|mtk_soc_get_timerclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|mtk_soc_get_socid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mtk_soc_reset_device
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mtk_soc_stop_clock
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mtk_soc_start_clock
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mtk_soc_assert_reset
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mtk_soc_deassert_reset
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mtk_soc_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MTK_SOC_H_ */
end_comment

end_unit

