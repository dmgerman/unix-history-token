begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fts.h	8.3 (Berkeley) 8/14/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FTS_COPMAT11_H_
end_ifndef

begin_define
define|#
directive|define
name|_FTS_COPMAT11_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|_ftsent11
modifier|*
name|fts_cur
decl_stmt|;
comment|/* current node */
name|struct
name|_ftsent11
modifier|*
name|fts_child
decl_stmt|;
comment|/* linked list of children */
name|struct
name|_ftsent11
modifier|*
modifier|*
name|fts_array
decl_stmt|;
comment|/* sort array */
name|uint32_t
name|fts_dev
decl_stmt|;
comment|/* starting device # */
name|char
modifier|*
name|fts_path
decl_stmt|;
comment|/* path for this descent */
name|int
name|fts_rfd
decl_stmt|;
comment|/* fd for root */
name|__size_t
name|fts_pathlen
decl_stmt|;
comment|/* sizeof(path) */
name|__size_t
name|fts_nitems
decl_stmt|;
comment|/* elements in the sort array */
name|int
function_decl|(
modifier|*
name|fts_compar
function_decl|)
comment|/* compare function */
parameter_list|(
specifier|const
name|struct
name|_ftsent11
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|struct
name|_ftsent11
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
name|int
name|fts_options
decl_stmt|;
comment|/* fts_open options, global flags */
name|void
modifier|*
name|fts_clientptr
decl_stmt|;
comment|/* thunk for sort function */
block|}
name|FTS11
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ftsent11
block|{
name|struct
name|_ftsent11
modifier|*
name|fts_cycle
decl_stmt|;
comment|/* cycle node */
name|struct
name|_ftsent11
modifier|*
name|fts_parent
decl_stmt|;
comment|/* parent directory */
name|struct
name|_ftsent11
modifier|*
name|fts_link
decl_stmt|;
comment|/* next file in directory */
name|long
name|long
name|fts_number
decl_stmt|;
comment|/* local numeric value */
name|void
modifier|*
name|fts_pointer
decl_stmt|;
comment|/* local address value */
name|char
modifier|*
name|fts_accpath
decl_stmt|;
comment|/* access path */
name|char
modifier|*
name|fts_path
decl_stmt|;
comment|/* root path */
name|int
name|fts_errno
decl_stmt|;
comment|/* errno for this node */
name|int
name|fts_symfd
decl_stmt|;
comment|/* fd for symlink */
name|__size_t
name|fts_pathlen
decl_stmt|;
comment|/* strlen(fts_path) */
name|__size_t
name|fts_namelen
decl_stmt|;
comment|/* strlen(fts_name) */
name|uint32_t
name|fts_ino
decl_stmt|;
comment|/* inode */
name|uint32_t
name|fts_dev
decl_stmt|;
comment|/* device */
name|uint16_t
name|fts_nlink
decl_stmt|;
comment|/* link count */
name|long
name|fts_level
decl_stmt|;
comment|/* depth (-1 to N) */
name|int
name|fts_info
decl_stmt|;
comment|/* user status for FTSENT structure */
name|unsigned
name|fts_flags
decl_stmt|;
comment|/* private flags for FTSENT structure */
name|int
name|fts_instr
decl_stmt|;
comment|/* fts_set() instructions */
name|struct
name|freebsd11_stat
modifier|*
name|fts_statp
decl_stmt|;
comment|/* stat(2) information */
name|char
modifier|*
name|fts_name
decl_stmt|;
comment|/* file name */
name|FTS11
modifier|*
name|fts_fts
decl_stmt|;
comment|/* back pointer to main FTS */
block|}
name|FTSENT11
typedef|;
end_typedef

begin_function_decl
name|FTSENT11
modifier|*
name|freebsd11_fts_children
parameter_list|(
name|FTS11
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_fts_close
parameter_list|(
name|FTS11
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|freebsd11_fts_get_clientptr
parameter_list|(
name|FTS11
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|freebsd11_fts_get_clientptr
parameter_list|(
name|fts
parameter_list|)
value|((fts)->fts_clientptr)
end_define

begin_function_decl
name|FTS11
modifier|*
name|freebsd11_fts_get_stream
parameter_list|(
name|FTSENT11
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|freebsd11_fts_get_stream
parameter_list|(
name|ftsent
parameter_list|)
value|((ftsent)->fts_fts)
end_define

begin_function_decl
name|FTS11
modifier|*
name|freebsd11_fts_open
parameter_list|(
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|FTSENT11
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|FTSENT11
modifier|*
specifier|const
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FTSENT11
modifier|*
name|freebsd11_fts_read
parameter_list|(
name|FTS11
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_fts_set
parameter_list|(
name|FTS11
modifier|*
parameter_list|,
name|FTSENT11
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freebsd11_fts_set_clientptr
parameter_list|(
name|FTS11
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FTS_COMPAT11_H_ */
end_comment

end_unit

