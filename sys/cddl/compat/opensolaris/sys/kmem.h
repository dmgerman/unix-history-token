begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_KMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_KMEM_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmem.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SOLARIS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|POINTER_IS_VALID
parameter_list|(
name|p
parameter_list|)
value|(!((uintptr_t)(p)& 0x3))
end_define

begin_define
define|#
directive|define
name|POINTER_INVALIDATE
parameter_list|(
name|pp
parameter_list|)
value|(*(pp) = (void *)((uintptr_t)(*(pp)) | 0x1))
end_define

begin_define
define|#
directive|define
name|KM_SLEEP
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|KM_PUSHPAGE
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|KM_NOSLEEP
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|KM_NODEBUG
value|M_NODUMP
end_define

begin_define
define|#
directive|define
name|KM_NORMALPRI
value|0
end_define

begin_define
define|#
directive|define
name|KMC_NODEBUG
value|UMA_ZONE_NODUMP
end_define

begin_define
define|#
directive|define
name|KMC_NOTOUCH
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|kmem_cache
block|{
name|char
name|kc_name
index|[
literal|32
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KMEM_DEBUG
argument_list|)
name|uma_zone_t
name|kc_zone
decl_stmt|;
else|#
directive|else
name|size_t
name|kc_size
decl_stmt|;
endif|#
directive|endif
name|int
function_decl|(
modifier|*
name|kc_constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|kc_destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|kc_private
decl_stmt|;
block|}
name|kmem_cache_t
typedef|;
end_typedef

begin_function_decl
name|void
modifier|*
name|zfs_kmem_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
name|kmflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zfs_kmem_free
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|kmem_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|kmem_cache_t
modifier|*
name|kmem_cache_create
argument_list|(
name|char
operator|*
name|name
argument_list|,
name|size_t
name|bufsize
argument_list|,
name|size_t
name|align
argument_list|,
name|int
argument_list|(
operator|*
name|constructor
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|,
name|int
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
name|destructor
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|)
argument_list|,
name|void
argument_list|(
argument|*reclaim
argument_list|)
operator|(
name|void
operator|*
operator|)
name|__unused
argument_list|,
name|void
operator|*
name|private
argument_list|,
name|vmem_t
operator|*
name|vmp
argument_list|,
name|int
name|cflags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|kmem_cache_destroy
parameter_list|(
name|kmem_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|kmem_cache_alloc
parameter_list|(
name|kmem_cache_t
modifier|*
name|cache
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kmem_cache_free
parameter_list|(
name|kmem_cache_t
modifier|*
name|cache
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kmem_cache_reap_now
parameter_list|(
name|kmem_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kmem_reap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmem_debugging
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|n
parameter_list|,
name|size_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|freemem
value|vm_cnt.v_free_count
end_define

begin_define
define|#
directive|define
name|minfree
value|vm_cnt.v_free_min
end_define

begin_define
define|#
directive|define
name|heap_arena
value|kmem_arena
end_define

begin_define
define|#
directive|define
name|kmem_alloc
parameter_list|(
name|size
parameter_list|,
name|kmflags
parameter_list|)
value|zfs_kmem_alloc((size), (kmflags))
end_define

begin_define
define|#
directive|define
name|kmem_zalloc
parameter_list|(
name|size
parameter_list|,
name|kmflags
parameter_list|)
value|zfs_kmem_alloc((size), (kmflags) | M_ZERO)
end_define

begin_define
define|#
directive|define
name|kmem_free
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|zfs_kmem_free((buf), (size))
end_define

begin_define
define|#
directive|define
name|kmem_cache_set_move
parameter_list|(
name|cache
parameter_list|,
name|movefunc
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_KMEM_H_ */
end_comment

end_unit

