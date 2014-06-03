begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ben Gray.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * Power, Reset and Clock Managment Module  *  * This is a very simple driver wrapper around the PRCM set of registers in  * the OMAP3 chip. It allows you to turn on and off things like the functional  * and interface clocks to the various on-chip modules.  *  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_cpuid.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_prcm.h>
end_include

begin_comment
comment|/**  *	ti_*_clk_devmap - Array of clock devices, should be defined one per SoC   *  *	This array is typically defined in one of the targeted *_prcm_clk.c  *	files and is specific to the given SoC platform.  Each entry in the array  *	corresponds to an individual clock device.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ti_clock_dev
name|ti_omap4_clk_devmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ti_clock_dev
name|ti_am335x_clk_devmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  *	ti_prcm_clk_dev - returns a pointer to the clock device with given id  *	@clk: the ID of the clock device to get  *  *	Simply iterates through the clk_devmap global array and returns a pointer  *	to the clock device if found.   *  *	LOCKING:  *	None  *  *	RETURNS:  *	The pointer to the clock device on success, on failure NULL is returned.  */
end_comment

begin_function
specifier|static
name|struct
name|ti_clock_dev
modifier|*
name|ti_prcm_clk_dev
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
block|{
name|struct
name|ti_clock_dev
modifier|*
name|clk_dev
decl_stmt|;
comment|/* Find the clock within the devmap - it's a bit inefficent having a for  	 * loop for this, but this function should only called when a driver is  	 * being activated so IMHO not a big issue. 	 */
name|clk_dev
operator|=
name|NULL
expr_stmt|;
switch|switch
condition|(
name|ti_chip
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|SOC_OMAP4
case|case
name|CHIP_OMAP_4
case|:
name|clk_dev
operator|=
operator|&
operator|(
name|ti_omap4_clk_devmap
index|[
literal|0
index|]
operator|)
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SOC_TI_AM335X
case|case
name|CHIP_AM335X
case|:
name|clk_dev
operator|=
operator|&
operator|(
name|ti_am335x_clk_devmap
index|[
literal|0
index|]
operator|)
expr_stmt|;
break|break;
endif|#
directive|endif
block|}
if|if
condition|(
name|clk_dev
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"No clock devmap found"
argument_list|)
expr_stmt|;
while|while
condition|(
name|clk_dev
operator|->
name|id
operator|!=
name|INVALID_CLK_IDENT
condition|)
block|{
if|if
condition|(
name|clk_dev
operator|->
name|id
operator|==
name|clk
condition|)
block|{
return|return
operator|(
name|clk_dev
operator|)
return|;
block|}
name|clk_dev
operator|++
expr_stmt|;
block|}
comment|/* Sanity check we managed to find the clock */
name|printf
argument_list|(
literal|"ti_prcm: Failed to find clock device (%d)\n"
argument_list|,
name|clk
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  *	ti_prcm_clk_valid - enables a clock for a particular module  *	@clk: identifier for the module to enable, see ti_prcm.h for a list  *	      of possible modules.  *	         Example: OMAP3_MODULE_MMC1_ICLK or OMAP3_MODULE_GPTIMER10_FCLK.  *	  *	This function can enable either a functional or interface clock.  *  *	The real work done to enable the clock is really done in the callback  *	function associated with the clock, this function is simply a wrapper  *	around that.  *  *	LOCKING:  *	Internally locks the driver context.  *  *	RETURNS:  *	Returns 0 on success or positive error code on failure.  */
end_comment

begin_function
name|int
name|ti_prcm_clk_valid
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ti_prcm_clk_dev
argument_list|(
name|clk
argument_list|)
operator|==
name|NULL
condition|)
name|ret
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  *	ti_prcm_clk_enable - enables a clock for a particular module  *	@clk: identifier for the module to enable, see ti_prcm.h for a list  *	      of possible modules.  *	         Example: OMAP3_MODULE_MMC1_ICLK or OMAP3_MODULE_GPTIMER10_FCLK.  *	  *	This function can enable either a functional or interface clock.  *  *	The real work done to enable the clock is really done in the callback  *	function associated with the clock, this function is simply a wrapper  *	around that.  *  *	LOCKING:  *	Internally locks the driver context.  *  *	RETURNS:  *	Returns 0 on success or positive error code on failure.  */
end_comment

begin_function
name|int
name|ti_prcm_clk_enable
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
block|{
name|struct
name|ti_clock_dev
modifier|*
name|clk_dev
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* Find the clock within the devmap - it's a bit inefficent having a for  	 * loop for this, but this function should only called when a driver is  	 * being activated so IMHO not a big issue. 	 */
name|clk_dev
operator|=
name|ti_prcm_clk_dev
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Sanity check we managed to find the clock */
if|if
condition|(
name|clk_dev
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Activate the clock */
if|if
condition|(
name|clk_dev
operator|->
name|clk_activate
condition|)
name|ret
operator|=
name|clk_dev
operator|->
name|clk_activate
argument_list|(
name|clk_dev
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  *	ti_prcm_clk_disable - disables a clock for a particular module  *	@clk: identifier for the module to enable, see ti_prcm.h for a list  *	      of possible modules.  *	         Example: OMAP3_MODULE_MMC1_ICLK or OMAP3_MODULE_GPTIMER10_FCLK.  *	  *	This function can enable either a functional or interface clock.  *  *	The real work done to enable the clock is really done in the callback  *	function associated with the clock, this function is simply a wrapper  *	around that.  *  *	LOCKING:  *	Internally locks the driver context.  *  *	RETURNS:  *	Returns 0 on success or positive error code on failure.  */
end_comment

begin_function
name|int
name|ti_prcm_clk_disable
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|)
block|{
name|struct
name|ti_clock_dev
modifier|*
name|clk_dev
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* Find the clock within the devmap - it's a bit inefficent having a for  	 * loop for this, but this function should only called when a driver is  	 * being activated so IMHO not a big issue. 	 */
name|clk_dev
operator|=
name|ti_prcm_clk_dev
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Sanity check we managed to find the clock */
if|if
condition|(
name|clk_dev
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Activate the clock */
if|if
condition|(
name|clk_dev
operator|->
name|clk_deactivate
condition|)
name|ret
operator|=
name|clk_dev
operator|->
name|clk_deactivate
argument_list|(
name|clk_dev
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  *	ti_prcm_clk_set_source - sets the source   *	@clk: identifier for the module to enable, see ti_prcm.h for a list  *	      of possible modules.  *	         Example: OMAP3_MODULE_MMC1_ICLK or OMAP3_MODULE_GPTIMER10_FCLK.  *	  *	This function can enable either a functional or interface clock.  *  *	The real work done to enable the clock is really done in the callback  *	function associated with the clock, this function is simply a wrapper  *	around that.  *  *	LOCKING:  *	Internally locks the driver context.  *  *	RETURNS:  *	Returns 0 on success or positive error code on failure.  */
end_comment

begin_function
name|int
name|ti_prcm_clk_set_source
parameter_list|(
name|clk_ident_t
name|clk
parameter_list|,
name|clk_src_t
name|clksrc
parameter_list|)
block|{
name|struct
name|ti_clock_dev
modifier|*
name|clk_dev
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* Find the clock within the devmap - it's a bit inefficent having a for  	 * loop for this, but this function should only called when a driver is  	 * being activated so IMHO not a big issue. 	 */
name|clk_dev
operator|=
name|ti_prcm_clk_dev
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Sanity check we managed to find the clock */
if|if
condition|(
name|clk_dev
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Activate the clock */
if|if
condition|(
name|clk_dev
operator|->
name|clk_set_source
condition|)
name|ret
operator|=
name|clk_dev
operator|->
name|clk_set_source
argument_list|(
name|clk_dev
argument_list|,
name|clksrc
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  *	ti_prcm_clk_get_source_freq - gets the source clock frequency  *	@clk: identifier for the module to enable, see ti_prcm.h for a list  *	      of possible modules.  *	@freq: pointer to an integer that upon return will contain the src freq  *	  *	This function returns the frequency of the source clock.  *  *	The real work done to enable the clock is really done in the callback  *	function associated with the clock, this function is simply a wrapper  *	around that.  *  *	LOCKING:  *	Internally locks the driver context.  *  *	RETURNS:  *	Returns 0 on success or positive error code on failure.  */
end_comment

begin_function
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
block|{
name|struct
name|ti_clock_dev
modifier|*
name|clk_dev
decl_stmt|;
name|int
name|ret
decl_stmt|;
comment|/* Find the clock within the devmap - it's a bit inefficent having a for  	 * loop for this, but this function should only called when a driver is  	 * being activated so IMHO not a big issue. 	 */
name|clk_dev
operator|=
name|ti_prcm_clk_dev
argument_list|(
name|clk
argument_list|)
expr_stmt|;
comment|/* Sanity check we managed to find the clock */
if|if
condition|(
name|clk_dev
operator|==
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Get the source frequency of the clock */
if|if
condition|(
name|clk_dev
operator|->
name|clk_get_source_freq
condition|)
name|ret
operator|=
name|clk_dev
operator|->
name|clk_get_source_freq
argument_list|(
name|clk_dev
argument_list|,
name|freq
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

