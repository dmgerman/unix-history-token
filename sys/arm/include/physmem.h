begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PHYSMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PHYSMEM_H_
end_define

begin_comment
comment|/*  * The physical address at which the kernel was loaded.  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|arm_physmem_kernaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routines to help configure physical ram.  *  * Multiple regions of contiguous physical ram can be added (in any order).  *  * Multiple regions of physical ram that should be excluded from crash dumps, or  * memory allocation, or both, can be added (in any order).  *  * After all early kernel init is done and it's time to configure all  * remainining non-excluded physical ram for use by other parts of the kernel,  * arm_physmem_init_kernel_globals() processes the hardware regions and  * exclusion regions to generate the global dump_avail and phys_avail arrays  * that communicate physical ram configuration to other parts of the kernel.  */
end_comment

begin_define
define|#
directive|define
name|EXFLAG_NODUMP
value|0x01
end_define

begin_define
define|#
directive|define
name|EXFLAG_NOALLOC
value|0x02
end_define

begin_function_decl
name|void
name|arm_physmem_hardware_region
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_physmem_exclude_region
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|sz
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_physmem_init_kernel_globals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_physmem_print_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convenience routines for FDT.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<machine/ofw_machdep.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
name|arm_physmem_hardware_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
name|mrptr
parameter_list|,
name|int
name|mrcount
parameter_list|)
block|{
while|while
condition|(
name|mrcount
operator|--
condition|)
block|{
name|arm_physmem_hardware_region
argument_list|(
name|mrptr
operator|->
name|mr_start
argument_list|,
name|mrptr
operator|->
name|mr_size
argument_list|)
expr_stmt|;
operator|++
name|mrptr
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|arm_physmem_exclude_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
name|mrptr
parameter_list|,
name|int
name|mrcount
parameter_list|,
name|uint32_t
name|exflags
parameter_list|)
block|{
while|while
condition|(
name|mrcount
operator|--
condition|)
block|{
name|arm_physmem_exclude_region
argument_list|(
name|mrptr
operator|->
name|mr_start
argument_list|,
name|mrptr
operator|->
name|mr_size
argument_list|,
name|exflags
argument_list|)
expr_stmt|;
operator|++
name|mrptr
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FDT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

