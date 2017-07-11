begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Thomas Skibo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent code for Xilinx Zynq-7000 Soc.  *  * Reference: Zynq-7000 All Programmable SoC Technical Reference Manual.  * (v1.4) November 16, 2012.  Xilinx doc UG585.  */
end_comment

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
file|<machine/platform.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/xilinx/zy7_machdep.h>
end_include

begin_include
include|#
directive|include
file|<arm/xilinx/zy7_reg.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_include
include|#
directive|include
file|"platform_pl310_if.h"
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|zynq7_cpu_reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set up static device mappings.  Not strictly necessary -- simplebus will  * dynamically establish mappings as needed -- but doing it this way gets us  * nice efficient 1MB section mappings.  */
end_comment

begin_function
specifier|static
name|int
name|zynq7_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|devmap_add_entry
argument_list|(
name|ZYNQ7_PSIO_HWBASE
argument_list|,
name|ZYNQ7_PSIO_SIZE
argument_list|)
expr_stmt|;
name|devmap_add_entry
argument_list|(
name|ZYNQ7_PSCTL_HWBASE
argument_list|,
name|ZYNQ7_PSCTL_SIZE
argument_list|)
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
name|void
name|zynq7_do_cpu_reset
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
if|if
condition|(
name|zynq7_cpu_reset
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|zynq7_cpu_reset
call|)
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"cpu_reset: no platform cpu_reset.  hanging.\n"
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|platform_method_t
name|zynq7_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_devmap_init
argument_list|,
name|zynq7_devmap_init
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_cpu_reset
argument_list|,
name|zynq7_do_cpu_reset
argument_list|)
block|,
ifdef|#
directive|ifdef
name|SMP
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_setmaxid
argument_list|,
name|zynq7_mp_setmaxid
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_start_ap
argument_list|,
name|zynq7_mp_start_ap
argument_list|)
block|,
endif|#
directive|endif
name|PLATFORMMETHOD
argument_list|(
name|platform_pl310_init
argument_list|,
name|zynq7_pl310_init
argument_list|)
block|,
name|PLATFORMMETHOD_END
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FDT_PLATFORM_DEF
argument_list|(
name|zynq7
argument_list|,
literal|"zynq7"
argument_list|,
literal|0
argument_list|,
literal|"xlnx,zynq-7000"
argument_list|,
literal|200
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

