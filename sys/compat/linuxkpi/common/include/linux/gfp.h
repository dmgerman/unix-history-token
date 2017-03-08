begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_GFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_GFP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<linux/page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_define
define|#
directive|define
name|__GFP_NOWARN
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_HIGHMEM
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_ZERO
value|M_ZERO
end_define

begin_define
define|#
directive|define
name|__GFP_NORETRY
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_RECLAIM
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_RECLAIMABLE
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_IO
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_NO_KSWAPD
value|0
end_define

begin_define
define|#
directive|define
name|__GFP_WAIT
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|__GFP_DMA32
value|(1U<< 24)
end_define

begin_comment
comment|/* LinuxKPI only */
end_comment

begin_define
define|#
directive|define
name|GFP_NOWAIT
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|GFP_ATOMIC
value|(M_NOWAIT | M_USE_RESERVE)
end_define

begin_define
define|#
directive|define
name|GFP_KERNEL
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|GFP_USER
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|GFP_HIGHUSER
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|GFP_HIGHUSER_MOVABLE
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|GFP_IOFS
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|GFP_NOIO
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|GFP_DMA32
value|__GFP_DMA32
end_define

begin_define
define|#
directive|define
name|GFP_TEMPORARY
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|GFP_NATIVE_MASK
value|(M_NOWAIT | M_WAITOK | M_USE_RESERVE | M_ZERO)
end_define

begin_comment
comment|/*  * Resolve a page into a virtual address:  *  * NOTE: This function only works for pages allocated by the kernel.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|linux_page_address
parameter_list|(
name|struct
name|page
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|page_address
parameter_list|(
name|page
parameter_list|)
value|linux_page_address(page)
end_define

begin_comment
comment|/*  * Page management for unmapped pages:  */
end_comment

begin_function_decl
specifier|extern
name|vm_page_t
name|linux_alloc_pages
parameter_list|(
name|gfp_t
name|flags
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_free_pages
parameter_list|(
name|vm_page_t
name|page
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|struct
name|page
modifier|*
name|alloc_page
parameter_list|(
name|gfp_t
name|flags
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_pages
argument_list|(
name|flags
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|page
modifier|*
name|alloc_pages
parameter_list|(
name|gfp_t
name|flags
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_pages
argument_list|(
name|flags
argument_list|,
name|order
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|page
modifier|*
name|alloc_pages_node
parameter_list|(
name|int
name|node_id
parameter_list|,
name|gfp_t
name|flags
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_pages
argument_list|(
name|flags
argument_list|,
name|order
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__free_pages
parameter_list|(
name|struct
name|page
modifier|*
name|page
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
block|{
name|linux_free_pages
argument_list|(
name|page
argument_list|,
name|order
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__free_page
parameter_list|(
name|struct
name|page
modifier|*
name|page
parameter_list|)
block|{
name|linux_free_pages
argument_list|(
name|page
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Page management for mapped pages:  */
end_comment

begin_function_decl
specifier|extern
name|vm_offset_t
name|linux_alloc_kmem
parameter_list|(
name|gfp_t
name|flags
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|linux_free_kmem
parameter_list|(
name|vm_offset_t
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|vm_offset_t
name|get_zeroed_page
parameter_list|(
name|gfp_t
name|flags
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_kmem
argument_list|(
name|flags
operator||
name|__GFP_ZERO
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|vm_offset_t
name|__get_free_page
parameter_list|(
name|gfp_t
name|flags
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_kmem
argument_list|(
name|flags
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|vm_offset_t
name|__get_free_pages
parameter_list|(
name|gfp_t
name|flags
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
block|{
return|return
operator|(
name|linux_alloc_kmem
argument_list|(
name|flags
argument_list|,
name|order
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|free_pages
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|unsigned
name|int
name|order
parameter_list|)
block|{
if|if
condition|(
name|addr
operator|==
literal|0
condition|)
return|return;
name|linux_free_kmem
argument_list|(
name|addr
argument_list|,
name|order
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|free_page
parameter_list|(
name|uintptr_t
name|addr
parameter_list|)
block|{
if|if
condition|(
name|addr
operator|==
literal|0
condition|)
return|return;
name|linux_free_kmem
argument_list|(
name|addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|gfpflags_allow_blocking
parameter_list|(
specifier|const
name|gfp_t
name|gfp_flags
parameter_list|)
block|{
return|return
operator|(
operator|(
name|gfp_flags
operator|&
operator|(
name|M_WAITOK
operator||
name|M_NOWAIT
operator|)
operator|)
operator|==
name|M_WAITOK
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|SetPageReserved
parameter_list|(
name|page
parameter_list|)
value|do { } while (0)
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|ClearPageReserved
parameter_list|(
name|page
parameter_list|)
value|do { } while (0)
end_define

begin_comment
comment|/* NOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_GFP_H_ */
end_comment

end_unit

