begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Olivier Houchard.  All rights reserved.  * Copyright (c) 2010 Greg Ansley.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91var.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91rm92reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_aicreg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pmcreg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_streg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pmcvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91soc.h>
end_include

begin_comment
comment|/*  * Standard priority levels for the system.  0 is lowest and 7 is highest.  * These values are the ones Atmel uses for its Linux port, which differ  * a little form the ones that are in the standard distribution.  Also,  * the ones marked with 'TWEEK' are different based on experience.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|at91_irq_prio
index|[
literal|32
index|]
init|=
block|{
literal|7
block|,
comment|/* Advanced Interrupt Controller (FIQ) */
literal|7
block|,
comment|/* System Peripherals */
literal|1
block|,
comment|/* Parallel IO Controller A */
literal|1
block|,
comment|/* Parallel IO Controller B */
literal|1
block|,
comment|/* Parallel IO Controller C */
literal|1
block|,
comment|/* Parallel IO Controller D */
literal|5
block|,
comment|/* USART 0 */
literal|5
block|,
comment|/* USART 1 */
literal|5
block|,
comment|/* USART 2 */
literal|5
block|,
comment|/* USART 3 */
literal|0
block|,
comment|/* Multimedia Card Interface */
literal|2
block|,
comment|/* USB Device Port */
literal|4
block|,
comment|/* Two-Wire Interface */
comment|/* TWEEK */
literal|5
block|,
comment|/* Serial Peripheral Interface */
literal|4
block|,
comment|/* Serial Synchronous Controller 0 */
literal|6
block|,
comment|/* Serial Synchronous Controller 1 */
comment|/* TWEEK */
literal|4
block|,
comment|/* Serial Synchronous Controller 2 */
literal|0
block|,
comment|/* Timer Counter 0 */
literal|6
block|,
comment|/* Timer Counter 1 */
comment|/* TWEEK */
literal|0
block|,
comment|/* Timer Counter 2 */
literal|0
block|,
comment|/* Timer Counter 3 */
literal|0
block|,
comment|/* Timer Counter 4 */
literal|0
block|,
comment|/* Timer Counter 5 */
literal|2
block|,
comment|/* USB Host port */
literal|3
block|,
comment|/* Ethernet MAC */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ0) */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ1) */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ2) */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ3) */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ4) */
literal|0
block|,
comment|/* Advanced Interrupt Controller (IRQ5) */
literal|0
comment|/* Advanced Interrupt Controller (IRQ6) */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|at91_pio_base
index|[]
init|=
block|{
name|AT91RM92_PIOA_BASE
block|,
name|AT91RM92_PIOB_BASE
block|,
name|AT91RM92_PIOC_BASE
block|,
name|AT91RM92_PIOD_BASE
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEVICE
parameter_list|(
name|_name
parameter_list|,
name|_id
parameter_list|,
name|_unit
parameter_list|)
define|\
value|{					\ 		_name, _unit,			\ 		AT91RM92_ ## _id ##_BASE,	\ 		AT91RM92_ ## _id ## _SIZE,	\ 		AT91RM92_IRQ_ ## _id		\ 	}
end_define

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|cpu_devs
name|at91_devs
index|[]
init|=
block|{
name|DEVICE
argument_list|(
literal|"at91_aic"
argument_list|,
name|AIC
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_pmc"
argument_list|,
name|PMC
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_st"
argument_list|,
name|ST
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_pio"
argument_list|,
name|PIOA
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_pio"
argument_list|,
name|PIOB
argument_list|,
literal|1
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_pio"
argument_list|,
name|PIOC
argument_list|,
literal|2
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_pio"
argument_list|,
name|PIOD
argument_list|,
literal|3
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_rtc"
argument_list|,
name|RTC
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_mci"
argument_list|,
name|MCI
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_twi"
argument_list|,
name|TWI
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_udp"
argument_list|,
name|UDP
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"ate"
argument_list|,
name|EMAC
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_ssc"
argument_list|,
name|SSC0
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_ssc"
argument_list|,
name|SSC1
argument_list|,
literal|1
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_ssc"
argument_list|,
name|SSC2
argument_list|,
literal|2
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"spi"
argument_list|,
name|SPI
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"uart"
argument_list|,
name|DBGU
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"uart"
argument_list|,
name|USART0
argument_list|,
literal|1
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"uart"
argument_list|,
name|USART1
argument_list|,
literal|2
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"uart"
argument_list|,
name|USART2
argument_list|,
literal|3
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"uart"
argument_list|,
name|USART3
argument_list|,
literal|4
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_mc"
argument_list|,
name|MC
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_tc"
argument_list|,
name|TC0
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_tc"
argument_list|,
name|TC1
argument_list|,
literal|1
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"ohci"
argument_list|,
name|OHCI
argument_list|,
literal|0
argument_list|)
block|,
name|DEVICE
argument_list|(
literal|"at91_cfata"
argument_list|,
name|CF
argument_list|,
literal|0
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|uint32_t
name|at91_pll_outb
parameter_list|(
name|int
name|freq
parameter_list|)
block|{
if|if
condition|(
name|freq
operator|>
literal|155000000
condition|)
return|return
operator|(
literal|0x0000
operator|)
return|;
else|else
return|return
operator|(
literal|0x8000
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* -- XXX are these needed? */
end_comment

begin_comment
comment|/* Disable all interrupts for RTC (0xe24 == RTC_IDR) */
end_comment

begin_comment
unit|bus_space_write_4(sc->sc_st, sc->sc_sys_sh, 0xe24, 0xffffffff);
comment|/* Disable all interrupts for the SDRAM controller */
end_comment

begin_endif
unit|bus_space_write_4(sc->sc_st, sc->sc_sys_sh, 0xfa8, 0xffffffff);
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|at91_clock_init
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|at91_pmc_clock
modifier|*
name|clk
decl_stmt|;
comment|/* Update USB device port clock info */
name|clk
operator|=
name|at91_pmc_clock_ref
argument_list|(
literal|"udpck"
argument_list|)
expr_stmt|;
name|clk
operator|->
name|pmc_mask
operator|=
name|PMC_SCER_UDP
expr_stmt|;
name|at91_pmc_clock_deref
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Update USB host port clock info */
name|clk
operator|=
name|at91_pmc_clock_ref
argument_list|(
literal|"uhpck"
argument_list|)
expr_stmt|;
name|clk
operator|->
name|pmc_mask
operator|=
name|PMC_SCER_UHP
expr_stmt|;
name|at91_pmc_clock_deref
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Each SOC has different PLL contraints */
name|clk
operator|=
name|at91_pmc_clock_ref
argument_list|(
literal|"plla"
argument_list|)
expr_stmt|;
name|clk
operator|->
name|pll_min_in
operator|=
name|RM9200_PLL_A_MIN_IN_FREQ
expr_stmt|;
comment|/*   1 MHz */
name|clk
operator|->
name|pll_max_in
operator|=
name|RM9200_PLL_A_MAX_IN_FREQ
expr_stmt|;
comment|/*  32 MHz */
name|clk
operator|->
name|pll_min_out
operator|=
name|RM9200_PLL_A_MIN_OUT_FREQ
expr_stmt|;
comment|/*  80 MHz */
name|clk
operator|->
name|pll_max_out
operator|=
name|RM9200_PLL_A_MAX_OUT_FREQ
expr_stmt|;
comment|/* 180 MHz */
name|clk
operator|->
name|pll_mul_shift
operator|=
name|RM9200_PLL_A_MUL_SHIFT
expr_stmt|;
name|clk
operator|->
name|pll_mul_mask
operator|=
name|RM9200_PLL_A_MUL_MASK
expr_stmt|;
name|clk
operator|->
name|pll_div_shift
operator|=
name|RM9200_PLL_A_DIV_SHIFT
expr_stmt|;
name|clk
operator|->
name|pll_div_mask
operator|=
name|RM9200_PLL_A_DIV_MASK
expr_stmt|;
name|clk
operator|->
name|set_outb
operator|=
name|at91_pll_outb
expr_stmt|;
name|at91_pmc_clock_deref
argument_list|(
name|clk
argument_list|)
expr_stmt|;
name|clk
operator|=
name|at91_pmc_clock_ref
argument_list|(
literal|"pllb"
argument_list|)
expr_stmt|;
name|clk
operator|->
name|pll_min_in
operator|=
name|RM9200_PLL_B_MIN_IN_FREQ
expr_stmt|;
comment|/* 100 KHz */
name|clk
operator|->
name|pll_max_in
operator|=
name|RM9200_PLL_B_MAX_IN_FREQ
expr_stmt|;
comment|/*  32 MHz */
name|clk
operator|->
name|pll_min_out
operator|=
name|RM9200_PLL_B_MIN_OUT_FREQ
expr_stmt|;
comment|/*  30 MHz */
name|clk
operator|->
name|pll_max_out
operator|=
name|RM9200_PLL_B_MAX_OUT_FREQ
expr_stmt|;
comment|/* 240 MHz */
name|clk
operator|->
name|pll_mul_shift
operator|=
name|RM9200_PLL_B_MUL_SHIFT
expr_stmt|;
name|clk
operator|->
name|pll_mul_mask
operator|=
name|RM9200_PLL_B_MUL_MASK
expr_stmt|;
name|clk
operator|->
name|pll_div_shift
operator|=
name|RM9200_PLL_B_DIV_SHIFT
expr_stmt|;
name|clk
operator|->
name|pll_div_mask
operator|=
name|RM9200_PLL_B_DIV_MASK
expr_stmt|;
name|clk
operator|->
name|set_outb
operator|=
name|at91_pll_outb
expr_stmt|;
name|at91_pmc_clock_deref
argument_list|(
name|clk
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|at91_soc_data
name|soc_data
init|=
block|{
operator|.
name|soc_delay
operator|=
name|at91_st_delay
block|,
operator|.
name|soc_reset
operator|=
name|at91_st_cpu_reset
block|,
operator|.
name|soc_clock_init
operator|=
name|at91_clock_init
block|,
operator|.
name|soc_irq_prio
operator|=
name|at91_irq_prio
block|,
operator|.
name|soc_children
operator|=
name|at91_devs
block|,
operator|.
name|soc_pio_base
operator|=
name|at91_pio_base
block|,
operator|.
name|soc_pio_count
operator|=
name|nitems
argument_list|(
name|at91_pio_base
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|AT91_SOC
argument_list|(
name|AT91_T_RM9200
argument_list|,
operator|&
name|soc_data
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

