begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

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
file|<machine/frame.h>
end_include

begin_comment
comment|/* For trapframe_t, used in<machine/machdep.h> */
end_comment

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_define
define|#
directive|define
name|DEVMAP_BOOTSTRAP_MAP_START
value|0xF0000000
end_define

begin_decl_stmt
specifier|extern
name|int
name|unmapped_buf_allowed
decl_stmt|;
end_decl_stmt

begin_function
name|vm_offset_t
name|initarm_lastaddr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|DEVMAP_BOOTSTRAP_MAP_START
operator|-
name|ARM_NOCACHE_KVA_SIZE
operator|)
return|;
block|}
end_function

begin_function
name|void
name|initarm_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|initarm_late_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* XXX: PR arm/180080 */
name|unmapped_buf_allowed
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|FDT_DEVMAP_MAX
value|(1 + 2 + 1 + 1)
end_define

begin_comment
comment|/* FIXME */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pmap_devmap
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
block|,
literal|0
block|,
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Construct pmap_devmap[] with DT-derived config data.  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_va
operator|=
literal|0xf2C00000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_pa
operator|=
literal|0x12C00000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_size
operator|=
literal|0x100000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_prot
operator|=
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_cache
operator|=
name|PTE_NOCACHE
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|pmap_devmap_bootstrap_table
operator|=
operator|&
name|fdt_devmap
index|[
literal|0
index|]
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|arm32_dma_range
modifier|*
name|bus_dma_get_range
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bus_dma_get_range_nb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

