begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fts.h	8.3 (Berkeley) 8/14/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FTS_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|_ftsent
modifier|*
name|fts_cur
decl_stmt|;
comment|/* current node */
name|struct
name|_ftsent
modifier|*
name|fts_child
decl_stmt|;
comment|/* linked list of children */
name|struct
name|_ftsent
modifier|*
modifier|*
name|fts_array
decl_stmt|;
comment|/* sort array */
name|dev_t
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
name|int
name|fts_pathlen
decl_stmt|;
comment|/* sizeof(path) */
name|int
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
name|_ftsent
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|_ftsent
modifier|*
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|FTS_COMFOLLOW
value|0x001
comment|/* follow command line symlinks */
define|#
directive|define
name|FTS_LOGICAL
value|0x002
comment|/* logical walk */
define|#
directive|define
name|FTS_NOCHDIR
value|0x004
comment|/* don't change directories */
define|#
directive|define
name|FTS_NOSTAT
value|0x008
comment|/* don't get stat info */
define|#
directive|define
name|FTS_PHYSICAL
value|0x010
comment|/* physical walk */
define|#
directive|define
name|FTS_SEEDOT
value|0x020
comment|/* return dot and dot-dot */
define|#
directive|define
name|FTS_XDEV
value|0x040
comment|/* don't cross devices */
define|#
directive|define
name|FTS_WHITEOUT
value|0x080
comment|/* return whiteout information */
define|#
directive|define
name|FTS_OPTIONMASK
value|0x0ff
comment|/* valid user option mask */
define|#
directive|define
name|FTS_NAMEONLY
value|0x100
comment|/* (private) child names only */
define|#
directive|define
name|FTS_STOP
value|0x200
comment|/* (private) unrecoverable error */
name|int
name|fts_options
decl_stmt|;
comment|/* fts_open options, global flags */
block|}
name|FTS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ftsent
block|{
name|struct
name|_ftsent
modifier|*
name|fts_cycle
decl_stmt|;
comment|/* cycle node */
name|struct
name|_ftsent
modifier|*
name|fts_parent
decl_stmt|;
comment|/* parent directory */
name|struct
name|_ftsent
modifier|*
name|fts_link
decl_stmt|;
comment|/* next file in directory */
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
name|u_short
name|fts_pathlen
decl_stmt|;
comment|/* strlen(fts_path) */
name|u_short
name|fts_namelen
decl_stmt|;
comment|/* strlen(fts_name) */
name|ino_t
name|fts_ino
decl_stmt|;
comment|/* inode */
name|dev_t
name|fts_dev
decl_stmt|;
comment|/* device */
name|nlink_t
name|fts_nlink
decl_stmt|;
comment|/* link count */
define|#
directive|define
name|FTS_ROOTPARENTLEVEL
value|-1
define|#
directive|define
name|FTS_ROOTLEVEL
value|0
name|short
name|fts_level
decl_stmt|;
comment|/* depth (-1 to N) */
define|#
directive|define
name|FTS_D
value|1
comment|/* preorder directory */
define|#
directive|define
name|FTS_DC
value|2
comment|/* directory that causes cycles */
define|#
directive|define
name|FTS_DEFAULT
value|3
comment|/* none of the above */
define|#
directive|define
name|FTS_DNR
value|4
comment|/* unreadable directory */
define|#
directive|define
name|FTS_DOT
value|5
comment|/* dot or dot-dot */
define|#
directive|define
name|FTS_DP
value|6
comment|/* postorder directory */
define|#
directive|define
name|FTS_ERR
value|7
comment|/* error; errno is set */
define|#
directive|define
name|FTS_F
value|8
comment|/* regular file */
define|#
directive|define
name|FTS_INIT
value|9
comment|/* initialized only */
define|#
directive|define
name|FTS_NS
value|10
comment|/* stat(2) failed */
define|#
directive|define
name|FTS_NSOK
value|11
comment|/* no stat(2) requested */
define|#
directive|define
name|FTS_SL
value|12
comment|/* symbolic link */
define|#
directive|define
name|FTS_SLNONE
value|13
comment|/* symbolic link without target */
define|#
directive|define
name|FTS_W
value|14
comment|/* whiteout object */
name|u_short
name|fts_info
decl_stmt|;
comment|/* user flags for FTSENT structure */
define|#
directive|define
name|FTS_DONTCHDIR
value|0x01
comment|/* don't chdir .. to the parent */
define|#
directive|define
name|FTS_SYMFOLLOW
value|0x02
comment|/* followed a symlink to get here */
define|#
directive|define
name|FTS_ISW
value|0x04
comment|/* this is a whiteout object */
name|u_short
name|fts_flags
decl_stmt|;
comment|/* private flags for FTSENT structure */
define|#
directive|define
name|FTS_AGAIN
value|1
comment|/* read node again */
define|#
directive|define
name|FTS_FOLLOW
value|2
comment|/* follow symbolic link */
define|#
directive|define
name|FTS_NOINSTR
value|3
comment|/* no instructions */
define|#
directive|define
name|FTS_SKIP
value|4
comment|/* discard node */
name|u_short
name|fts_instr
decl_stmt|;
comment|/* fts_set() instructions */
name|struct
name|stat
modifier|*
name|fts_statp
decl_stmt|;
comment|/* stat(2) information */
name|char
name|fts_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* file name */
block|}
name|FTSENT
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|FTSENT
modifier|*
name|fts_children
parameter_list|(
name|FTS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fts_close
parameter_list|(
name|FTS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FTS
modifier|*
name|fts_open
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
name|FTSENT
modifier|*
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FTSENT
modifier|*
name|fts_read
parameter_list|(
name|FTS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fts_set
parameter_list|(
name|FTS
modifier|*
parameter_list|,
name|FTSENT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FTS_H_ */
end_comment

end_unit

