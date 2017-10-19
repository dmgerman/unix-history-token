begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * Copyright (c) 2015-2016 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * from: FreeBSD: //depot/projects/arm/src/sys/arm/ti/ti_machdep.c  */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

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
file|<sys/devmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/aw_mp.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/aw_wdog.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/aw_machdep.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a10_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a13_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a20_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a31_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a31s_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|a83t_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_attach_t
name|h3_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_devmap_init_t
name|allwinner_devmap_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_cpu_reset_t
name|allwinner_cpu_reset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|soc_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|soc_family
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|a10_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A10
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN4I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a13_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A13
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN5I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a20_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A20
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN7I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a31_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A31
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN6I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a31s_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A31S
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN6I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a33_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A33
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN8I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a83t_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_A83T
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN8I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|h3_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|soc_type
operator|=
name|ALLWINNERSOC_H3
expr_stmt|;
name|soc_family
operator|=
name|ALLWINNERSOC_SUN8I
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Set up static device mappings.  *  * This covers all the on-chip device with 1MB section mappings, which is good  * for performance (uses fewer TLB entries for device access).  *  * XXX It also covers a block of SRAM and some GPU (mali400) stuff that maybe  * shouldn't be device-mapped.  The original code mapped a 4MB block, but  * perhaps a 1MB block would be more appropriate.  */
end_comment

begin_function
specifier|static
name|int
name|allwinner_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|devmap_add_entry
argument_list|(
literal|0x01C00000
argument_list|,
literal|0x00400000
argument_list|)
expr_stmt|;
comment|/* 4MB */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|allwinner_cpu_reset
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|aw_wdog_watchdog_reset
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"Reset failed!\n"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|/*  * To use early printf on Allwinner SoC, add to kernel config  * options SOCDEV_PA=0x01C00000  * options SOCDEV_VA=0x10000000  * options EARLY_PRINTF  * And remove the if 0 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|EARLY_PRINTF
end_ifdef

begin_endif
unit|static void allwinner_early_putc(int c) { 	volatile uint32_t * UART_STAT_REG = (uint32_t *)0x1002807C; 	volatile uint32_t * UART_TX_REG   = (uint32_t *)0x10028000; 	const uint32_t      UART_TXRDY    = (1<< 2);  	while ((*UART_STAT_REG& UART_TXRDY) == 0) 		continue; 	*UART_TX_REG = c; } early_putc_t *early_putc = allwinner_early_putc;
endif|#
directive|endif
end_endif

begin_comment
comment|/* EARLY_PRINTF */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A10
argument_list|)
end_if

begin_endif
unit|static platform_method_t a10_methods[] = { 	PLATFORMMETHOD(platform_attach,         a10_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),  	PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a10, "a10", 0, "allwinner,sun4i-a10", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A13
argument_list|)
end_if

begin_endif
unit|static platform_method_t a13_methods[] = { 	PLATFORMMETHOD(platform_attach,         a13_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),  	PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a13, "a13", 0, "allwinner,sun5i-a13", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A20
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t a20_methods[] = { 	PLATFORMMETHOD(platform_attach,         a20_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a20, "a20", 0, "allwinner,sun7i-a20", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A31
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t a31_methods[] = { 	PLATFORMMETHOD(platform_attach,         a31_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a31, "a31", 0, "allwinner,sun6i-a31", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A31S
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t a31s_methods[] = { 	PLATFORMMETHOD(platform_attach,         a31s_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a31s, "a31s", 0, "allwinner,sun6i-a31s", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A33
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t a33_methods[] = { 	PLATFORMMETHOD(platform_attach,         a33_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a33, "a33", 0, "allwinner,sun8i-a33", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_A83T
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t a83t_methods[] = { 	PLATFORMMETHOD(platform_attach,         a83t_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	a83t_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(a83t, "a83t", 0, "allwinner,sun8i-a83t", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_H2PLUS
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t h2_plus_methods[] = { 	PLATFORMMETHOD(platform_attach,         h3_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(h2_plus, "h2_plus", 0, "allwinner,sun8i-h2-plus", 200);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_ALLWINNER_H3
argument_list|)
end_if

begin_ifdef
unit|static platform_method_t h3_methods[] = { 	PLATFORMMETHOD(platform_attach,         h3_attach), 	PLATFORMMETHOD(platform_devmap_init,    allwinner_devmap_init), 	PLATFORMMETHOD(platform_cpu_reset,	allwinner_cpu_reset),
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_endif
unit|PLATFORMMETHOD(platform_mp_start_ap,	aw_mp_start_ap), 	PLATFORMMETHOD(platform_mp_setmaxid,	aw_mp_setmaxid),
endif|#
directive|endif
end_endif

begin_endif
unit|PLATFORMMETHOD_END, }; FDT_PLATFORM_DEF(h3, "h3", 0, "allwinner,sun8i-h3", 200);
endif|#
directive|endif
end_endif

unit|u_int allwinner_soc_type(void) { 	return (soc_type); }  u_int allwinner_soc_family(void) { 	return (soc_family); }
end_unit

