begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Semihalf, Rafal Jaworowski  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
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
file|<machine/spr.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/mpc85xx/ocpbus.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/mpc85xx/mpc85xx.h>
end_include

begin_comment
comment|/*  * MPC85xx system specific routines  */
end_comment

begin_function
name|uint32_t
name|ccsr_read4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|ptr
init|=
operator|(
name|void
operator|*
operator|)
name|addr
decl_stmt|;
return|return
operator|(
operator|*
name|ptr
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ccsr_write4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|ptr
init|=
operator|(
name|void
operator|*
operator|)
name|addr
decl_stmt|;
operator|*
name|ptr
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|ver
init|=
name|SVR_VER
argument_list|(
name|mfspr
argument_list|(
name|SPR_SVR
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|ver
operator|==
name|SVR_MPC8572E
operator|||
name|ver
operator|==
name|SVR_MPC8572
condition|)
comment|/* Systems with dedicated reset register */
name|ccsr_write4
argument_list|(
name|OCP85XX_RSTCR
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* Clear DBCR0, disables debug interrupts and events. */
name|mtspr
argument_list|(
name|SPR_DBCR0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
asm|__asm __volatile("isync");
comment|/* Enable Debug Interrupts in MSR. */
name|mtmsr
argument_list|(
name|mfmsr
argument_list|()
operator||
name|PSL_DE
argument_list|)
expr_stmt|;
comment|/* Enable debug interrupts and issue reset. */
name|mtspr
argument_list|(
name|SPR_DBCR0
argument_list|,
name|mfspr
argument_list|(
name|SPR_DBCR0
argument_list|)
operator||
name|DBCR0_IDM
operator||
name|DBCR0_RST_SYSTEM
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Reset failed...\n"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

end_unit

