begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  * Copyright (c) 2005, 2009 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)malloc.h	8.5 (Berkeley) 5/3/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MALLOC_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_define
define|#
directive|define
name|MINALLOCSIZE
value|UMA_SMALLEST_UNIT
end_define

begin_comment
comment|/*  * flags to malloc.  */
end_comment

begin_define
define|#
directive|define
name|M_NOWAIT
value|0x0001
end_define

begin_comment
comment|/* do not block */
end_comment

begin_define
define|#
directive|define
name|M_WAITOK
value|0x0002
end_define

begin_comment
comment|/* ok to block */
end_comment

begin_define
define|#
directive|define
name|M_ZERO
value|0x0100
end_define

begin_comment
comment|/* bzero the allocation */
end_comment

begin_define
define|#
directive|define
name|M_NOVM
value|0x0200
end_define

begin_comment
comment|/* don't ask VM for pages */
end_comment

begin_define
define|#
directive|define
name|M_USE_RESERVE
value|0x0400
end_define

begin_comment
comment|/* can alloc out of reserve memory */
end_comment

begin_define
define|#
directive|define
name|M_NODUMP
value|0x0800
end_define

begin_comment
comment|/* don't dump pages in this allocation */
end_comment

begin_define
define|#
directive|define
name|M_FIRSTFIT
value|0x1000
end_define

begin_comment
comment|/* Only for vmem, fast fit. */
end_comment

begin_define
define|#
directive|define
name|M_BESTFIT
value|0x2000
end_define

begin_comment
comment|/* Only for vmem, low fragmentation. */
end_comment

begin_define
define|#
directive|define
name|M_MAGIC
value|877983977
end_define

begin_comment
comment|/* time when first defined :-) */
end_comment

begin_comment
comment|/*  * Two malloc type structures are present: malloc_type, which is used by a  * type owner to declare the type, and malloc_type_internal, which holds  * malloc-owned statistics and other ABI-sensitive fields, such as the set of  * malloc statistics indexed by the compile-time MAXCPU constant.  * Applications should avoid introducing dependence on the allocator private  * data layout and size.  *  * The malloc_type ks_next field is protected by malloc_mtx.  Other fields in  * malloc_type are static after initialization so unsynchronized.  *  * Statistics in malloc_type_stats are written only when holding a critical  * section and running on the CPU associated with the index into the stat  * array, but read lock-free resulting in possible (minor) races, which the  * monitoring app should take into account.  */
end_comment

begin_struct
struct|struct
name|malloc_type_stats
block|{
name|uint64_t
name|mts_memalloced
decl_stmt|;
comment|/* Bytes allocated on CPU. */
name|uint64_t
name|mts_memfreed
decl_stmt|;
comment|/* Bytes freed on CPU. */
name|uint64_t
name|mts_numallocs
decl_stmt|;
comment|/* Number of allocates on CPU. */
name|uint64_t
name|mts_numfrees
decl_stmt|;
comment|/* number of frees on CPU. */
name|uint64_t
name|mts_size
decl_stmt|;
comment|/* Bitmask of sizes allocated on CPU. */
name|uint64_t
name|_mts_reserved1
decl_stmt|;
comment|/* Reserved field. */
name|uint64_t
name|_mts_reserved2
decl_stmt|;
comment|/* Reserved field. */
name|uint64_t
name|_mts_reserved3
decl_stmt|;
comment|/* Reserved field. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Index definitions for the mti_probes[] array.  */
end_comment

begin_define
define|#
directive|define
name|DTMALLOC_PROBE_MALLOC
value|0
end_define

begin_define
define|#
directive|define
name|DTMALLOC_PROBE_FREE
value|1
end_define

begin_define
define|#
directive|define
name|DTMALLOC_PROBE_MAX
value|2
end_define

begin_struct
struct|struct
name|malloc_type_internal
block|{
name|uint32_t
name|mti_probes
index|[
name|DTMALLOC_PROBE_MAX
index|]
decl_stmt|;
comment|/* DTrace probe ID array. */
name|u_char
name|mti_zone
decl_stmt|;
name|struct
name|malloc_type_stats
name|mti_stats
index|[
name|MAXCPU
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Public data structure describing a malloc type.  Private data is hung off  * of ks_handle to avoid encoding internal malloc(9) data structures in  * modules, which will statically allocate struct malloc_type.  */
end_comment

begin_struct
struct|struct
name|malloc_type
block|{
name|struct
name|malloc_type
modifier|*
name|ks_next
decl_stmt|;
comment|/* Next in global chain. */
name|u_long
name|ks_magic
decl_stmt|;
comment|/* Detect programmer error. */
specifier|const
name|char
modifier|*
name|ks_shortdesc
decl_stmt|;
comment|/* Printable type name. */
name|void
modifier|*
name|ks_handle
decl_stmt|;
comment|/* Priv. data, was lo_class. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Statistics structure headers for user space.  The kern.malloc sysctl  * exposes a structure stream consisting of a stream header, then a series of  * malloc type headers and statistics structures (quantity maxcpus).  For  * convenience, the kernel will provide the current value of maxcpus at the  * head of the stream.  */
end_comment

begin_define
define|#
directive|define
name|MALLOC_TYPE_STREAM_VERSION
value|0x00000001
end_define

begin_struct
struct|struct
name|malloc_type_stream_header
block|{
name|uint32_t
name|mtsh_version
decl_stmt|;
comment|/* Stream format version. */
name|uint32_t
name|mtsh_maxcpus
decl_stmt|;
comment|/* Value of MAXCPU for stream. */
name|uint32_t
name|mtsh_count
decl_stmt|;
comment|/* Number of records. */
name|uint32_t
name|_mtsh_pad
decl_stmt|;
comment|/* Pad/reserved field. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MALLOC_MAX_NAME
value|32
end_define

begin_struct
struct|struct
name|malloc_type_header
block|{
name|char
name|mth_name
index|[
name|MALLOC_MAX_NAME
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MALLOC_DEFINE
parameter_list|(
name|type
parameter_list|,
name|shortdesc
parameter_list|,
name|longdesc
parameter_list|)
define|\
value|struct malloc_type type[1] = {					\ 		{ NULL, M_MAGIC, shortdesc, NULL }			\ 	};								\ 	SYSINIT(type##_init, SI_SUB_KMEM, SI_ORDER_THIRD, malloc_init,	\ 	    type);							\ 	SYSUNINIT(type##_uninit, SI_SUB_KMEM, SI_ORDER_ANY,		\ 	    malloc_uninit, type)
end_define

begin_define
define|#
directive|define
name|MALLOC_DECLARE
parameter_list|(
name|type
parameter_list|)
define|\
value|extern struct malloc_type type[1]
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CACHE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_DEVBUF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TEMP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IP6OPT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* for INET6 */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IP6NDP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* for INET6 */
end_comment

begin_comment
comment|/*  * Deprecated macro versions of not-quite-malloc() and free().  */
end_comment

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|space
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|((space) = (cast)malloc((u_long)(size), (type), (flags)))
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|)
value|free((addr), (type))
end_define

begin_comment
comment|/*  * XXX this should be declared in<sys/uio.h>, but that tends to fail  * because<sys/uio.h> is included in a header before the source file  * has a chance to include<sys/malloc.h> to get MALLOC_DECLARE() defined.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IOV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|malloc_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function type used when iterating over the list of malloc types.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|malloc_type_list_func_t
parameter_list|(
name|struct
name|malloc_type
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|contigfree
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
modifier|*
name|contigmalloc
argument_list|(
name|unsigned
name|long
name|size
argument_list|,
expr|struct
name|malloc_type
operator|*
name|type
argument_list|,
name|int
name|flags
argument_list|,
name|vm_paddr_t
name|low
argument_list|,
name|vm_paddr_t
name|high
argument_list|,
name|unsigned
name|long
name|alignment
argument_list|,
name|vm_paddr_t
name|boundary
argument_list|)
name|__malloc_like
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
modifier|*
name|malloc
argument_list|(
name|unsigned
name|long
name|size
argument_list|,
expr|struct
name|malloc_type
operator|*
name|type
argument_list|,
name|int
name|flags
argument_list|)
name|__malloc_like
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|malloc_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malloc_last_fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_type_allocated
parameter_list|(
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_type_freed
parameter_list|(
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_type_list
parameter_list|(
name|malloc_type_list_func_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_uninit
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|reallocf
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|malloc_type
modifier|*
name|malloc_desc2type
parameter_list|(
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_MALLOC_H_ */
end_comment

end_unit

