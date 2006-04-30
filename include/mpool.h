begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mpool.h	8.2 (Berkeley) 7/14/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPOOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPOOL_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * The memory pool scheme is a simple one.  Each in-memory page is referenced  * by a bucket which is threaded in up to two of three ways.  All active pages  * are threaded on a hash chain (hashed by page number) and an lru chain.  * Inactive pages are threaded on a free chain.  Each reference to a memory  * pool is handed an opaque MPOOL cookie which stores all of this information.  */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|128
end_define

begin_define
define|#
directive|define
name|HASHKEY
parameter_list|(
name|pgno
parameter_list|)
value|((pgno - 1) % HASHSIZE)
end_define

begin_comment
comment|/* The BKT structures are the elements of the queues. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_bkt
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_bkt
argument_list|)
name|hq
expr_stmt|;
comment|/* hash queue */
name|TAILQ_ENTRY
argument_list|(
argument|_bkt
argument_list|)
name|q
expr_stmt|;
comment|/* lru queue */
name|void
modifier|*
name|page
decl_stmt|;
comment|/* page */
name|pgno_t
name|pgno
decl_stmt|;
comment|/* page number */
define|#
directive|define
name|MPOOL_DIRTY
value|0x01
comment|/* page needs to be written */
define|#
directive|define
name|MPOOL_PINNED
value|0x02
comment|/* page is pinned into memory */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* flags */
block|}
name|BKT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|MPOOL
block|{
name|TAILQ_HEAD
argument_list|(
argument|_lqh
argument_list|,
argument|_bkt
argument_list|)
name|lqh
expr_stmt|;
comment|/* lru queue head */
comment|/* hash queue array */
name|TAILQ_HEAD
argument_list|(
argument|_hqh
argument_list|,
argument|_bkt
argument_list|)
name|hqh
index|[
name|HASHSIZE
index|]
expr_stmt|;
name|pgno_t
name|curcache
decl_stmt|;
comment|/* current number of cached pages */
name|pgno_t
name|maxcache
decl_stmt|;
comment|/* max number of cached pages */
name|pgno_t
name|npages
decl_stmt|;
comment|/* number of pages in the file */
name|u_long
name|pagesize
decl_stmt|;
comment|/* file page size */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
comment|/* page in conversion routine */
name|void
function_decl|(
modifier|*
name|pgin
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|pgno_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* page out conversion routine */
name|void
function_decl|(
modifier|*
name|pgout
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|pgno_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|pgcookie
decl_stmt|;
comment|/* cookie for page in/out routines */
ifdef|#
directive|ifdef
name|STATISTICS
name|u_long
name|cachehit
decl_stmt|;
name|u_long
name|cachemiss
decl_stmt|;
name|u_long
name|pagealloc
decl_stmt|;
name|u_long
name|pageflush
decl_stmt|;
name|u_long
name|pageget
decl_stmt|;
name|u_long
name|pagenew
decl_stmt|;
name|u_long
name|pageput
decl_stmt|;
name|u_long
name|pageread
decl_stmt|;
name|u_long
name|pagewrite
decl_stmt|;
endif|#
directive|endif
block|}
name|MPOOL
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
name|MPOOL
modifier|*
name|mpool_open
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|pgno_t
parameter_list|,
name|pgno_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpool_filter
parameter_list|(
name|MPOOL
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|pgno_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|pgno_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mpool_new
parameter_list|(
name|MPOOL
modifier|*
parameter_list|,
name|pgno_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mpool_get
parameter_list|(
name|MPOOL
modifier|*
parameter_list|,
name|pgno_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpool_put
parameter_list|(
name|MPOOL
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpool_sync
parameter_list|(
name|MPOOL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpool_close
parameter_list|(
name|MPOOL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|STATISTICS
end_ifdef

begin_function_decl
name|void
name|mpool_stat
parameter_list|(
name|MPOOL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

