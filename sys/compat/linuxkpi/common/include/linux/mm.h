begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2017 Mellanox Technologies, Ltd.  * Copyright (c) 2015 FranÃ§ois Tigeot  * Copyright (c) 2015 Matthew Dillon<dillon@backplane.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<linux/mm_types.h>
end_include

begin_include
include|#
directive|include
file|<linux/pfn.h>
end_include

begin_include
include|#
directive|include
file|<linux/list.h>
end_include

begin_include
include|#
directive|include
file|<asm/pgtable.h>
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

begin_comment
comment|/*  * Make sure our LinuxKPI defined virtual memory flags don't conflict  * with the ones defined by FreeBSD:  */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|VM_PROT_ALL
operator|&
operator|-
operator|(
literal|1
operator|<<
literal|8
operator|)
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VM_READ
value|VM_PROT_READ
end_define

begin_define
define|#
directive|define
name|VM_WRITE
value|VM_PROT_WRITE
end_define

begin_define
define|#
directive|define
name|VM_EXEC
value|VM_PROT_EXECUTE
end_define

begin_define
define|#
directive|define
name|VM_PFNINTERNAL
value|(1<< 8)
end_define

begin_comment
comment|/* FreeBSD private flag to vm_insert_pfn() */
end_comment

begin_define
define|#
directive|define
name|VM_MIXEDMAP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|VM_NORESERVE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|VM_PFNMAP
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|VM_IO
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|VM_MAYWRITE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|VM_DONTCOPY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|VM_DONTEXPAND
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|VM_DONTDUMP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VMA_MAX_PREFAULT_RECORD
value|1
end_define

begin_define
define|#
directive|define
name|FOLL_WRITE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FOLL_FORCE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_OOM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_SIGBUS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_MAJOR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_WRITE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_HWPOISON
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_HWPOISON_LARGE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_SIGSEGV
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_NOPAGE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_LOCKED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_RETRY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|VM_FAULT_FALLBACK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_WRITE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_MKWRITE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_ALLOW_RETRY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_RETRY_NOWAIT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_KILLABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_TRIED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_USER
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_REMOTE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|FAULT_FLAG_INSTRUCTION
value|(1<< 8)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pte_fn_t
function_decl|)
parameter_list|(
name|linux_pte_t
modifier|*
parameter_list|,
name|pgtable_t
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

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
name|pgprot_t
name|vm_page_prot
decl_stmt|;
name|unsigned
name|long
name|vm_flags
decl_stmt|;
name|struct
name|mm_struct
modifier|*
name|vm_mm
decl_stmt|;
name|void
modifier|*
name|vm_private_data
decl_stmt|;
specifier|const
name|struct
name|vm_operations_struct
modifier|*
name|vm_ops
decl_stmt|;
name|struct
name|linux_file
modifier|*
name|vm_file
decl_stmt|;
comment|/* internal operation */
name|vm_paddr_t
name|vm_pfn
decl_stmt|;
comment|/* PFN for memory map */
name|vm_size_t
name|vm_len
decl_stmt|;
comment|/* length for memory map */
name|vm_pindex_t
name|vm_pfn_first
decl_stmt|;
name|int
name|vm_pfn_count
decl_stmt|;
name|int
modifier|*
name|vm_pfn_pcount
decl_stmt|;
name|vm_object_t
name|vm_obj
decl_stmt|;
name|vm_map_t
name|vm_cached_map
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|vm_area_struct
argument_list|)
name|vm_entry
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_fault
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|pgoff_t
name|pgoff
decl_stmt|;
name|void
modifier|*
name|virtual_address
decl_stmt|;
comment|/* user-space address */
name|struct
name|page
modifier|*
name|page
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_operations_struct
block|{
name|void
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fault
function_decl|)
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
parameter_list|,
name|struct
name|vm_fault
modifier|*
parameter_list|)
function_decl|;
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
operator|(
name|page_address
argument_list|(
name|page
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This only works via memory map operations.  */
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
name|vma
operator|->
name|vm_len
operator|=
name|size
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
specifier|inline
name|int
name|apply_to_page_range
parameter_list|(
name|struct
name|mm_struct
modifier|*
name|mm
parameter_list|,
name|unsigned
name|long
name|address
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|pte_fn_t
name|fn
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
return|return
operator|(
operator|-
name|ENOTSUP
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|zap_vma_ptes
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
name|vma
parameter_list|,
name|unsigned
name|long
name|address
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
block|{
return|return
operator|(
operator|-
name|ENOTSUP
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|remap_pfn_range
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
name|pgprot_t
name|prot
parameter_list|)
block|{
return|return
operator|(
operator|-
name|ENOTSUP
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|vma_pages
parameter_list|(
name|struct
name|vm_area_struct
modifier|*
name|vma
parameter_list|)
block|{
return|return
operator|(
operator|(
name|vma
operator|->
name|vm_end
operator|-
name|vma
operator|->
name|vm_start
operator|)
operator|>>
name|PAGE_SHIFT
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|offset_in_page
parameter_list|(
name|off
parameter_list|)
value|((off)& (PAGE_SIZE - 1))
end_define

begin_function
specifier|static
specifier|inline
name|void
name|set_page_dirty
parameter_list|(
name|struct
name|vm_page
modifier|*
name|page
parameter_list|)
block|{
name|vm_page_dirty
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|set_page_dirty_lock
parameter_list|(
name|struct
name|vm_page
modifier|*
name|page
parameter_list|)
block|{
name|vm_page_lock
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_dirty
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_unlock
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mark_page_accessed
parameter_list|(
name|struct
name|vm_page
modifier|*
name|page
parameter_list|)
block|{
name|vm_page_reference
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|get_page
parameter_list|(
name|struct
name|vm_page
modifier|*
name|page
parameter_list|)
block|{
name|vm_page_lock
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_hold
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_wire
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_unlock
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|long
name|get_user_pages
parameter_list|(
name|unsigned
name|long
name|start
parameter_list|,
name|unsigned
name|long
name|nr_pages
parameter_list|,
name|int
name|gup_flags
parameter_list|,
name|struct
name|page
modifier|*
modifier|*
parameter_list|,
name|struct
name|vm_area_struct
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__get_user_pages_fast
parameter_list|(
name|unsigned
name|long
name|start
parameter_list|,
name|int
name|nr_pages
parameter_list|,
name|int
name|write
parameter_list|,
name|struct
name|page
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|get_user_pages_remote
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|,
name|struct
name|mm_struct
modifier|*
parameter_list|,
name|unsigned
name|long
name|start
parameter_list|,
name|unsigned
name|long
name|nr_pages
parameter_list|,
name|int
name|gup_flags
parameter_list|,
name|struct
name|page
modifier|*
modifier|*
parameter_list|,
name|struct
name|vm_area_struct
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|put_page
parameter_list|(
name|struct
name|vm_page
modifier|*
name|page
parameter_list|)
block|{
name|vm_page_lock
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_unwire
argument_list|(
name|page
argument_list|,
name|PQ_ACTIVE
argument_list|)
expr_stmt|;
name|vm_page_unhold
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vm_page_unlock
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|copy_highpage
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|)
value|pmap_copy_page(from, to)
end_define

begin_function
specifier|static
specifier|inline
name|pgprot_t
name|vm_get_page_prot
parameter_list|(
name|unsigned
name|long
name|vm_flags
parameter_list|)
block|{
return|return
operator|(
name|vm_flags
operator|&
name|VM_PROT_ALL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|vm_page_t
name|vmalloc_to_page
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|vm_paddr_t
name|paddr
decl_stmt|;
name|paddr
operator|=
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|addr
argument_list|)
expr_stmt|;
return|return
operator|(
name|PHYS_TO_VM_PAGE
argument_list|(
name|paddr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|is_vmalloc_addr
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MM_H_ */
end_comment

end_unit

