begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)2006 YAMAMOTO Takashi,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* From	$NetBSD: vmem.h,v 1.20 2013/01/29 21:26:24 para Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VMEM_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|vmem
name|vmem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uintptr_t
name|vmem_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|vmem_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VMEM_ADDR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|VMEM_ADDR_MAX
value|(~(vmem_addr_t)0)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
name|vmem_import_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vmem_size_t
parameter_list|,
name|int
parameter_list|,
name|vmem_addr_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|vmem_release_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vmem_addr_t
parameter_list|,
name|vmem_size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|vmem_reclaim_t
function_decl|)
parameter_list|(
name|vmem_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Create a vmem:  *	name		- Name of the region  *	base		- Initial span start (optional)  *	size		- Initial span size  *	quantum		- Natural unit of allocation (ie PAGE_SIZE, 1, etc)  *	qcache_max	- Maximum size to quantum cache.  This creates a UMA  *			  cache for each multiple of quantum up to qcache_max.  *	flags		- M_* flags  */
end_comment

begin_function_decl
name|vmem_t
modifier|*
name|vmem_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|vmem_addr_t
name|base
parameter_list|,
name|vmem_size_t
name|size
parameter_list|,
name|vmem_size_t
name|quantum
parameter_list|,
name|vmem_size_t
name|qcache_max
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vmem_t
modifier|*
name|vmem_init
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|vmem_addr_t
name|base
parameter_list|,
name|vmem_size_t
name|size
parameter_list|,
name|vmem_size_t
name|quantum
parameter_list|,
name|vmem_size_t
name|qcache_max
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmem_destroy
parameter_list|(
name|vmem_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set callbacks for bringing in dynamic regions:  *	importfn	- Backing store import routine.  *	releasefn	- Backing store release routine.  *	arg		- Backing store argument  *	import_quantum	- Size to import from backing store  */
end_comment

begin_function_decl
name|void
name|vmem_set_import
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_import_t
modifier|*
name|importfn
parameter_list|,
name|vmem_release_t
modifier|*
name|releasefn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|vmem_size_t
name|import_quantum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set a callback for reclaiming memory when space is exhausted:  */
end_comment

begin_function_decl
name|void
name|vmem_set_reclaim
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_reclaim_t
modifier|*
name|reclaimfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate and free linear regions from a vmem.  Must specify  * BESTFIT or FIRSTFIT.  Free is non-blocking.  These routines  * respect the quantum caches.  */
end_comment

begin_function_decl
name|int
name|vmem_alloc
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|,
name|vmem_addr_t
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmem_free
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_addr_t
name|addr
parameter_list|,
name|vmem_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Constrained allocate and free routines.  These bypass the quantum cache.  *	size		- Size in units of 1, not quantum.  *	align		- Required alignment of the start of region  *	phase		- Offset from alignment  *	nocross		- Illegal boundary  *	minaddr		- Minimum allowed address for last byte  *	maxaddr		- Maximum allowed address for first byte  *	flags		- M_* flags  *	addrp		- result  */
end_comment

begin_function_decl
name|int
name|vmem_xalloc
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_size_t
name|size
parameter_list|,
name|vmem_size_t
name|align
parameter_list|,
name|vmem_size_t
name|phase
parameter_list|,
name|vmem_size_t
name|nocross
parameter_list|,
name|vmem_addr_t
name|minaddr
parameter_list|,
name|vmem_addr_t
name|maxaddr
parameter_list|,
name|int
name|flags
parameter_list|,
name|vmem_addr_t
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmem_xfree
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_addr_t
name|addr
parameter_list|,
name|vmem_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a static region to a vmem after create.  This won't be freed  * until the vmem is destroyed.  */
end_comment

begin_function_decl
name|int
name|vmem_add
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_addr_t
name|addr
parameter_list|,
name|vmem_size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given roundup size to the vmem's native quantum size.  */
end_comment

begin_function_decl
name|vmem_size_t
name|vmem_roundup_size
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|vmem_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Report vmem utilization according to the requested type.  */
end_comment

begin_function_decl
name|vmem_size_t
name|vmem_size
parameter_list|(
name|vmem_t
modifier|*
name|vm
parameter_list|,
name|int
name|typemask
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|vmem_whatis
argument_list|(
name|vmem_addr_t
name|addr
argument_list|,
name|int
argument_list|(
argument|*fn
argument_list|)
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vmem_print
argument_list|(
name|vmem_addr_t
name|addr
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|(
argument|*fn
argument_list|)
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vmem_printall
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|(
argument|*fn
argument_list|)
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
name|__printflike
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|vmem_startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vmem_size typemask */
end_comment

begin_define
define|#
directive|define
name|VMEM_ALLOC
value|0x01
end_define

begin_define
define|#
directive|define
name|VMEM_FREE
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_VMEM_H_ */
end_comment

end_unit

