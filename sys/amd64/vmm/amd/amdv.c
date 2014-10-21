begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|"io/iommu.h"
end_include

begin_function
specifier|static
name|int
name|amd_iommu_init
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_init: not implemented\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_cleanup
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_cleanup: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_enable: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_disable: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
modifier|*
name|amd_iommu_create_domain
parameter_list|(
name|vm_paddr_t
name|maxaddr
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_create_domain: not implemented\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_destroy_domain
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_destroy_domain: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|uint64_t
name|amd_iommu_create_mapping
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|,
name|vm_paddr_t
name|gpa
parameter_list|,
name|vm_paddr_t
name|hpa
parameter_list|,
name|uint64_t
name|len
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_create_mapping: not implemented\n"
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
name|uint64_t
name|amd_iommu_remove_mapping
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|,
name|vm_paddr_t
name|gpa
parameter_list|,
name|uint64_t
name|len
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_remove_mapping: not implemented\n"
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
name|amd_iommu_add_device
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|,
name|uint16_t
name|rid
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_add_device: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_remove_device
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|,
name|uint16_t
name|rid
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_remove_device: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|amd_iommu_invalidate_tlb
parameter_list|(
name|void
modifier|*
name|domain
parameter_list|)
block|{
name|printf
argument_list|(
literal|"amd_iommu_invalidate_tlb: not implemented\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|iommu_ops
name|iommu_ops_amd
init|=
block|{
name|amd_iommu_init
block|,
name|amd_iommu_cleanup
block|,
name|amd_iommu_enable
block|,
name|amd_iommu_disable
block|,
name|amd_iommu_create_domain
block|,
name|amd_iommu_destroy_domain
block|,
name|amd_iommu_create_mapping
block|,
name|amd_iommu_remove_mapping
block|,
name|amd_iommu_add_device
block|,
name|amd_iommu_remove_device
block|,
name|amd_iommu_invalidate_tlb
block|, }
decl_stmt|;
end_decl_stmt

end_unit

