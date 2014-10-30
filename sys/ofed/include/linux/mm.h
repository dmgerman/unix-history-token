begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MM_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MM_H_
end_define

begin_include
include|#
directive|include
file|<linux/spinlock.h>
end_include

begin_include
include|#
directive|include
file|<linux/gfp.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|x
parameter_list|)
value|ALIGN(x, PAGE_SIZE)
end_define

begin_struct
struct|struct
name|vm_area_struct
block|{
name|vm_offset_t
name|vm_start
decl_stmt|;
name|vm_offset_t
name|vm_end
decl_stmt|;
name|vm_offset_t
name|vm_pgoff
decl_stmt|;
name|vm_paddr_t
name|vm_pfn
decl_stmt|;
comment|/* PFN For mmap. */
name|vm_memattr_t
name|vm_page_prot
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Compute log2 of the power of two rounded up count of pages  * needed for size bytes.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|get_order
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|int
name|order
decl_stmt|;
name|size
operator|=
operator|(
name|size
operator|-
literal|1
operator|)
operator|>>
name|PAGE_SHIFT
expr_stmt|;
name|order
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|size
condition|)
block|{
name|order
operator|++
expr_stmt|;
name|size
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|order
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|lowmem_page_address
parameter_list|(
name|struct
name|page
modifier|*
name|page
parameter_list|)
block|{
return|return
name|page_address
argument_list|(
name|page
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This only works via mmap ops.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|io_remap_pfn_range
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
name|vma
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|unsigned
name|long
name|pfn
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|vm_memattr_t
name|prot
parameter_list|)
block|{
name|vma
operator|->
name|vm_page_prot
operator|=
name|prot
expr_stmt|;
name|vma
operator|->
name|vm_pfn
operator|=
name|pfn
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MM_H_ */
end_comment

end_unit

