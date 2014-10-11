begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Anish Gupta (akgupt3@gmail.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|"npt.h"
end_include

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_vmm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw_vmm
argument_list|,
name|OID_AUTO
argument_list|,
name|npt
argument_list|,
name|CTLFLAG_RW
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|npt_flags
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_npt
argument_list|,
name|OID_AUTO
argument_list|,
name|pmap_flags
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|npt_flags
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NPT_IPIMASK
value|0xFF
end_define

begin_comment
comment|/*  * AMD nested page table init.  */
end_comment

begin_function
name|int
name|svm_npt_init
parameter_list|(
name|int
name|ipinum
parameter_list|)
block|{
name|int
name|enable_superpage
init|=
literal|1
decl_stmt|;
name|npt_flags
operator|=
name|ipinum
operator|&
name|NPT_IPIMASK
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.vmm.npt.enable_superpage"
argument_list|,
operator|&
name|enable_superpage
argument_list|)
expr_stmt|;
if|if
condition|(
name|enable_superpage
condition|)
name|npt_flags
operator||=
name|PMAP_PDE_SUPERPAGE
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
name|npt_pinit
parameter_list|(
name|pmap_t
name|pmap
parameter_list|)
block|{
return|return
operator|(
name|pmap_pinit_type
argument_list|(
name|pmap
argument_list|,
name|PT_RVI
argument_list|,
name|npt_flags
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|vmspace
modifier|*
name|svm_npt_alloc
parameter_list|(
name|vm_offset_t
name|min
parameter_list|,
name|vm_offset_t
name|max
parameter_list|)
block|{
return|return
operator|(
name|vmspace_alloc
argument_list|(
name|min
argument_list|,
name|max
argument_list|,
name|npt_pinit
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|svm_npt_free
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
block|{
name|vmspace_free
argument_list|(
name|vmspace
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

