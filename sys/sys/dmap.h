begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dmap.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DMAP_H_
end_define

begin_comment
comment|/*  * Definitions for the mapping of vitual swap space to the physical swap  * area - the disk map.  */
end_comment

begin_define
define|#
directive|define
name|NDMAP
value|38
end_define

begin_comment
comment|/* size of the swap area map */
end_comment

begin_struct
struct|struct
name|dmap
block|{
name|swblk_t
name|dm_size
decl_stmt|;
comment|/* current size used by process */
name|swblk_t
name|dm_alloc
decl_stmt|;
comment|/* amount of physical swap space allocated */
name|swblk_t
name|dm_map
index|[
name|NDMAP
index|]
decl_stmt|;
comment|/* first disk block number in each chunk */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|dmap
name|zdmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dmmin
decl_stmt|,
name|dmmax
decl_stmt|,
name|dmtext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following structure is that ``returned'' from a call to vstodb(). */
end_comment

begin_struct
struct|struct
name|dblock
block|{
name|swblk_t
name|db_base
decl_stmt|;
comment|/* base of physical contig drum block */
name|swblk_t
name|db_size
decl_stmt|;
comment|/* size of block */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DMAP_H_ */
end_comment

end_unit

