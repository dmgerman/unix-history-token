begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mpool.h	8.1 (Berkeley) 6/2/93  */
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

begin_comment
comment|/*  * The memory pool scheme is a simple one.  Each in memory page is referenced  * by a bucket which is threaded in three ways.  All active pages are threaded  * on a hash chain (hashed by the page number) and an lru chain.  Inactive  * pages are threaded on a free chain.  Each reference to a memory pool is  * handed an MPOOL which is the opaque cookie passed to all of the memory  * routines.  */
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
comment|/* The BKT structures are the elements of the lists. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BKT
block|{
name|struct
name|BKT
modifier|*
name|hnext
decl_stmt|;
comment|/* next hash bucket */
name|struct
name|BKT
modifier|*
name|hprev
decl_stmt|;
comment|/* previous hash bucket */
name|struct
name|BKT
modifier|*
name|cnext
decl_stmt|;
comment|/* next free/lru bucket */
name|struct
name|BKT
modifier|*
name|cprev
decl_stmt|;
comment|/* previous free/lru bucket */
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
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* flags */
block|}
name|BKT
typedef|;
end_typedef

begin_comment
comment|/* The BKTHDR structures are the heads of the lists. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BKTHDR
block|{
name|struct
name|BKT
modifier|*
name|hnext
decl_stmt|;
comment|/* next hash bucket */
name|struct
name|BKT
modifier|*
name|hprev
decl_stmt|;
comment|/* previous hash bucket */
name|struct
name|BKT
modifier|*
name|cnext
decl_stmt|;
comment|/* next free/lru bucket */
name|struct
name|BKT
modifier|*
name|cprev
decl_stmt|;
comment|/* previous free/lru bucket */
block|}
name|BKTHDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|MPOOL
block|{
name|BKTHDR
name|free
decl_stmt|;
comment|/* The free list. */
name|BKTHDR
name|lru
decl_stmt|;
comment|/* The LRU list. */
name|BKTHDR
name|hashtable
index|[
name|HASHSIZE
index|]
decl_stmt|;
comment|/* Hashed list by page number. */
name|pgno_t
name|curcache
decl_stmt|;
comment|/* Current number of cached pages. */
name|pgno_t
name|maxcache
decl_stmt|;
comment|/* Max number of cached pages. */
name|pgno_t
name|npages
decl_stmt|;
comment|/* Number of pages in the file. */
name|u_long
name|pagesize
decl_stmt|;
comment|/* File page size. */
name|int
name|fd
decl_stmt|;
comment|/* File descriptor. */
comment|/* Page in conversion routine. */
name|void
argument_list|(
argument|*pgin
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|pgno_t
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Page out conversion routine. */
name|void
argument_list|(
argument|*pgout
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|pgno_t
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|pgcookie
decl_stmt|;
comment|/* Cookie for page in/out routines. */
ifdef|#
directive|ifdef
name|STATISTICS
name|unsigned
name|long
name|cachehit
decl_stmt|;
name|unsigned
name|long
name|cachemiss
decl_stmt|;
name|unsigned
name|long
name|pagealloc
decl_stmt|;
name|unsigned
name|long
name|pageflush
decl_stmt|;
name|unsigned
name|long
name|pageget
decl_stmt|;
name|unsigned
name|long
name|pagenew
decl_stmt|;
name|unsigned
name|long
name|pageput
decl_stmt|;
name|unsigned
name|long
name|pageread
decl_stmt|;
name|unsigned
name|long
name|pagewrite
decl_stmt|;
endif|#
directive|endif
block|}
name|MPOOL
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__MPOOLINTERFACE_PRIVATE
end_ifdef

begin_comment
comment|/* Macros to insert/delete into/from hash chain. */
end_comment

begin_define
define|#
directive|define
name|rmhash
parameter_list|(
name|bp
parameter_list|)
value|{ \         (bp)->hprev->hnext = (bp)->hnext; \         (bp)->hnext->hprev = (bp)->hprev; \ }
end_define

begin_define
define|#
directive|define
name|inshash
parameter_list|(
name|bp
parameter_list|,
name|pg
parameter_list|)
value|{ \ 	hp =&mp->hashtable[HASHKEY(pg)]; \         (bp)->hnext = hp->hnext; \         (bp)->hprev = (struct BKT *)hp; \         hp->hnext->hprev = (bp); \         hp->hnext = (bp); \ }
end_define

begin_comment
comment|/* Macros to insert/delete into/from lru and free chains. */
end_comment

begin_define
define|#
directive|define
name|rmchain
parameter_list|(
name|bp
parameter_list|)
value|{ \         (bp)->cprev->cnext = (bp)->cnext; \         (bp)->cnext->cprev = (bp)->cprev; \ }
end_define

begin_define
define|#
directive|define
name|inschain
parameter_list|(
name|bp
parameter_list|,
name|dp
parameter_list|)
value|{ \         (bp)->cnext = (dp)->cnext; \         (bp)->cprev = (struct BKT *)(dp); \         (dp)->cnext->cprev = (bp); \         (dp)->cnext = (bp); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
name|MPOOL
modifier|*
name|mpool_open
name|__P
argument_list|(
operator|(
name|DBT
operator|*
operator|,
name|int
operator|,
name|pgno_t
operator|,
name|pgno_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mpool_filter
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|pgno_t
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|pgno_t
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|mpool_new
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|,
name|pgno_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|mpool_get
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|,
name|pgno_t
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mpool_put
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mpool_sync
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mpool_close
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|STATISTICS
end_ifdef

begin_decl_stmt
name|void
name|mpool_stat
name|__P
argument_list|(
operator|(
name|MPOOL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

