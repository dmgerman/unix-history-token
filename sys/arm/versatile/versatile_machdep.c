begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|"platform_if.h"
end_include

begin_comment
comment|/* Start of address space used for bootstrap map */
end_comment

begin_define
define|#
directive|define
name|DEVMAP_BOOTSTRAP_MAP_START
value|0xE0000000
end_define

begin_function
specifier|static
name|vm_offset_t
name|versatile_lastaddr
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
return|return
operator|(
name|DEVMAP_BOOTSTRAP_MAP_START
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|FDT_DEVMAP_MAX
value|(2)
end_define

begin_comment
comment|/* FIXME */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|devmap_entry
name|fdt_devmap
index|[
name|FDT_DEVMAP_MAX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Construct devmap table with DT-derived config data.  */
end_comment

begin_function
specifier|static
name|int
name|versatile_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_va
operator|=
literal|0xf0100000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_pa
operator|=
literal|0x10100000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_size
operator|=
literal|0x01000000
expr_stmt|;
comment|/* 1 MB */
name|devmap_register_table
argument_list|(
operator|&
name|fdt_devmap
index|[
literal|0
index|]
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
name|versatile_cpu_reset
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|printf
argument_list|(
literal|"cpu_reset\n"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|platform_method_t
name|versatile_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_lastaddr
argument_list|,
name|versatile_lastaddr
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_devmap_init
argument_list|,
name|versatile_devmap_init
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_cpu_reset
argument_list|,
name|versatile_cpu_reset
argument_list|)
block|,
name|PLATFORMMETHOD_END
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FDT_PLATFORM_DEF
argument_list|(
name|versatile
argument_list|,
literal|"versatile"
argument_list|,
literal|0
argument_list|,
literal|"arm,versatile-pb"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

