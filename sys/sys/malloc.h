begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)malloc.h	8.5 (Berkeley) 5/3/95  * $FreeBSD$  */
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
file|<vm/uma.h>
end_include

begin_define
define|#
directive|define
name|splmem
value|splhigh
end_define

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
name|M_WAITOK
value|0x0000
end_define

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
name|M_USE_RESERVE
value|0x0002
end_define

begin_comment
comment|/* can alloc out of reserve memory */
end_comment

begin_define
define|#
directive|define
name|M_ZERO
value|0x0004
end_define

begin_comment
comment|/* bzero the allocation */
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

begin_struct
struct|struct
name|malloc_type
block|{
name|struct
name|malloc_type
modifier|*
name|ks_next
decl_stmt|;
comment|/* next in list */
name|long
name|ks_memuse
decl_stmt|;
comment|/* total memory held in bytes */
name|long
name|ks_limit
decl_stmt|;
comment|/* most that are allowed to exist */
name|long
name|ks_size
decl_stmt|;
comment|/* sizes of this thing that are allocated */
name|long
name|ks_inuse
decl_stmt|;
comment|/* # of packets of this type currently in use */
name|uint64_t
name|ks_calls
decl_stmt|;
comment|/* total packets of this type ever allocated */
name|long
name|ks_maxused
decl_stmt|;
comment|/* maximum number ever used */
name|u_long
name|ks_magic
decl_stmt|;
comment|/* if it's not magic, don't touch it */
specifier|const
name|char
modifier|*
name|ks_shortdesc
decl_stmt|;
comment|/* short description */
name|u_short
name|ks_limblocks
decl_stmt|;
comment|/* number of times blocked for hitting limit */
name|u_short
name|ks_mapblocks
decl_stmt|;
comment|/* number of times blocked for kernel map */
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
value|struct malloc_type type[1] = { \ 		{ NULL, 0, 0, 0, 0, 0, 0, M_MAGIC, shortdesc, 0, 0 } \ 	}; \ 	SYSINIT(type##_init, SI_SUB_KMEM, SI_ORDER_SECOND, malloc_init, type); \ 	SYSUNINIT(type##_uninit, SI_SUB_KMEM, SI_ORDER_ANY, malloc_uninit, type)
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
value|(space) = (cast)malloc((u_long)(size), (type), (flags))
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

begin_comment
comment|/* XXX struct malloc_type is unused for contig*(). */
end_comment

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

begin_function_decl
name|void
modifier|*
name|contigmalloc
parameter_list|(
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
parameter_list|,
name|unsigned
name|long
name|low
parameter_list|,
name|unsigned
name|long
name|high
parameter_list|,
name|unsigned
name|long
name|alignment
parameter_list|,
name|unsigned
name|long
name|boundary
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
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
name|malloc_init
parameter_list|(
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

