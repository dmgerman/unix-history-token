begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ben Gray.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Texas Instruments - OMAP3xxx series processors  *  * Reference:  *  OMAP35x Applications Processor  *   Technical Reference Manual  *  (omap35xx_techref.pdf)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_PRCM_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_PRCM_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* System clocks, typically you can only call ti_prcm_clk_get_source_freq() 	 * on these clocks as they are enabled by default. 	 */
name|SYS_CLK
init|=
literal|1
block|,
comment|/* The MPU (ARM) core clock */
name|MPU_CLK
init|=
literal|20
block|,
comment|/* MMC modules */
name|MMC0_CLK
init|=
literal|100
block|,
name|MMC1_CLK
block|,
name|MMC2_CLK
block|,
name|MMC3_CLK
block|,
name|MMC4_CLK
block|,
name|MMC5_CLK
block|,
comment|/* I2C modules */
name|I2C0_CLK
init|=
literal|200
block|,
name|I2C1_CLK
block|,
name|I2C2_CLK
block|,
name|I2C3_CLK
block|,
name|I2C4_CLK
block|,
comment|/* USB module(s) */
name|USBTLL_CLK
init|=
literal|300
block|,
name|USBHSHOST_CLK
block|,
name|USBFSHOST_CLK
block|,
name|USBP1_PHY_CLK
block|,
name|USBP2_PHY_CLK
block|,
name|USBP1_UTMI_CLK
block|,
name|USBP2_UTMI_CLK
block|,
name|USBP1_HSIC_CLK
block|,
name|USBP2_HSIC_CLK
block|,
comment|/* UART modules */
name|UART0_CLK
init|=
literal|400
block|,
name|UART1_CLK
block|,
name|UART2_CLK
block|,
name|UART3_CLK
block|,
name|UART4_CLK
block|,
name|UART5_CLK
block|,
name|UART6_CLK
block|,
name|UART7_CLK
block|,
name|UART8_CLK
block|,
comment|/* General purpose timer modules */
name|GPTIMER1_CLK
init|=
literal|500
block|,
name|GPTIMER2_CLK
block|,
name|GPTIMER3_CLK
block|,
name|GPTIMER4_CLK
block|,
name|GPTIMER5_CLK
block|,
name|GPTIMER6_CLK
block|,
name|GPTIMER7_CLK
block|,
name|GPTIMER8_CLK
block|,
name|GPTIMER9_CLK
block|,
name|GPTIMER10_CLK
block|,
name|GPTIMER11_CLK
block|,
name|GPTIMER12_CLK
block|,
comment|/* McBSP module(s) */
name|MCBSP1_CLK
init|=
literal|600
block|,
name|MCBSP2_CLK
block|,
name|MCBSP3_CLK
block|,
name|MCBSP4_CLK
block|,
name|MCBSP5_CLK
block|,
comment|/* General purpose I/O modules */
name|GPIO0_CLK
init|=
literal|700
block|,
name|GPIO1_CLK
block|,
name|GPIO2_CLK
block|,
name|GPIO3_CLK
block|,
name|GPIO4_CLK
block|,
name|GPIO5_CLK
block|,
name|GPIO6_CLK
block|,
comment|/* sDMA module */
name|SDMA_CLK
init|=
literal|800
block|,
comment|/* DMTimer modules */
name|DMTIMER0_CLK
init|=
literal|900
block|,
name|DMTIMER1_CLK
block|,
name|DMTIMER2_CLK
block|,
name|DMTIMER3_CLK
block|,
name|DMTIMER4_CLK
block|,
name|DMTIMER5_CLK
block|,
name|DMTIMER6_CLK
block|,
name|DMTIMER7_CLK
block|,
comment|/* CPSW modules */
name|CPSW_CLK
init|=
literal|1000
block|,
comment|/* Mentor USB modules */
name|MUSB0_CLK
init|=
literal|1100
block|,
comment|/* EDMA module */
name|EDMA_TPCC_CLK
init|=
literal|1200
block|,
name|EDMA_TPTC0_CLK
block|,
name|EDMA_TPTC1_CLK
block|,
name|EDMA_TPTC2_CLK
block|,
comment|/* LCD controller module */
name|LCDC_CLK
init|=
literal|1300
block|,
comment|/* PWM modules */
name|PWMSS0_CLK
init|=
literal|1400
block|,
name|PWMSS1_CLK
block|,
name|PWMSS2_CLK
block|,
comment|/* Mailbox modules */
name|MAILBOX0_CLK
init|=
literal|1500
block|,
comment|/* Spinlock modules */
name|SPINLOCK0_CLK
init|=
literal|1600
block|,
name|PRUSS_CLK
init|=
literal|1700
block|,
name|TSC_ADC_CLK
init|=
literal|1800
block|,
name|INVALID_CLK_IDENT
block|}
name|clk_ident_t
typedef|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SYSCLK_CLK
block|,
comment|/* System clock */
name|EXT_CLK
block|,
name|F32KHZ_CLK
block|,
comment|/* 32KHz clock */
name|F48MHZ_CLK
block|,
comment|/* 48MHz clock */
name|F64MHZ_CLK
block|,
comment|/* 64MHz clock */
name|F96MHZ_CLK
block|,
comment|/* 96MHz clock */
block|}
name|clk_src_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ti_clock_dev
block|{
comment|/* The profile of the timer */
name|clk_ident_t
name|id
decl_stmt|;
comment|/* A bunch of callbacks associated with the clock device */
name|int
function_decl|(
modifier|*
name|clk_activate
function_decl|)
parameter_list|(
name|struct
name|ti_clock_dev
modifier|*
name|clkdev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|clk_deactivate
function_decl|)
parameter_list|(
name|struct
name|ti_clock_dev
modifier|*
name|clkdev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|clk_set_source
function_decl|)
parameter_list|(
name|struct
name|ti_clock_dev
modifier|*
name|clkdev
parameter_list|,
name|clk_src_t
name|clksrc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|clk_accessible
function_decl|)
parameter_list|(
name|struct
name|ti_clock_dev
modifier|*
name|clkdev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|clk_get_source_freq
function_decl|)
parameter_list|(
name|struct
name|ti_clock_dev
modifier|*
name|clkdev
parameter_list|,
name|unsigned
name|int
modifier|*
name|freq
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ti_prcm_clk_valid
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_enable
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_disable
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_accessible
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_disable_autoidle
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_set_source
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|,
name|clk_src_t
name|clksrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_prcm_clk_get_source_freq
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|,
name|unsigned
name|int
modifier|*
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ti_prcm_reset
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
comment|/* _TI_PRCM_H_ */
end_comment

end_unit

