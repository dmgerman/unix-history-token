begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Olson.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * @(#)lrucache.h	5.1 (Berkeley) 1/23/91  */
end_comment

begin_comment
comment|/*  *  LRU list entries.  The head of the list is the most-recently requested  *  block; the tail is the least-recently requested one.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|LRU_ENT
block|{
name|char
modifier|*
name|l_buffer
decl_stmt|;
comment|/* buffer we return to user */
name|int
name|l_pgno
decl_stmt|;
comment|/* logical page number */
name|int
name|l_flags
decl_stmt|;
comment|/* FREE and DIRTY bits */
name|struct
name|LRU_ENT
modifier|*
name|l_prev
decl_stmt|;
comment|/* predecessor in LRU list */
name|struct
name|LRU_ENT
modifier|*
name|l_next
decl_stmt|;
comment|/* successor in LRU list */
block|}
name|LRU_ENT
typedef|;
end_typedef

begin_comment
comment|/*  *  Cache entries.  We use a hash table to avoid a linear walk of the LRU  *  list when we need to look up blocks by number.  The hash table is  *  chained.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CACHE_ENT
block|{
name|int
name|c_pgno
decl_stmt|;
name|LRU_ENT
modifier|*
name|c_lruent
decl_stmt|;
name|struct
name|CACHE_ENT
modifier|*
name|c_chain
decl_stmt|;
block|}
name|CACHE_ENT
typedef|;
end_typedef

begin_comment
comment|/*  *  The LRU cache structure.  The cache size (lru_csize) is the largest size  *  the user wants us to grow to; current size (lru_cursz) is always less than  *  or equal to lru_csize.  Note that we will grow the cache (lru_csize) if  *  it's the only way that we can satisfy a user's block request.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|LRUCACHE
block|{
name|int
name|lru_fd
decl_stmt|;
name|int
name|lru_csize
decl_stmt|;
name|int
name|lru_psize
decl_stmt|;
name|int
name|lru_cursz
decl_stmt|;
name|char
modifier|*
name|lru_opaque
decl_stmt|;
comment|/* passed to inproc, outproc */
name|int
function_decl|(
modifier|*
name|lru_inproc
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|lru_outproc
function_decl|)
parameter_list|()
function_decl|;
name|LRU_ENT
modifier|*
name|lru_head
decl_stmt|;
name|LRU_ENT
modifier|*
name|lru_tail
decl_stmt|;
name|CACHE_ENT
modifier|*
modifier|*
name|lru_cache
decl_stmt|;
block|}
name|LRUCACHE
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef NULL */
end_comment

begin_comment
comment|/* this is the opaque type we return for LRU caches */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|LRU
typedef|;
end_typedef

begin_comment
comment|/* bits for l_flags in LRU_ENT structure */
end_comment

begin_define
define|#
directive|define
name|F_DIRTY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|F_FREE
value|(1<< 1)
end_define

begin_comment
comment|/* lru module routines */
end_comment

begin_function_decl
specifier|extern
name|CACHE_ENT
modifier|*
name|lruhashget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CACHE_ENT
modifier|*
name|lruhashput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lruhashdel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lruhead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lrugrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LRU
name|lruinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lruwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lrusync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lruget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lrugetnew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lrugetpg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lrurelease
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lrufree
parameter_list|()
function_decl|;
end_function_decl

end_unit

