begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mtree.h,v 1.21 2003/08/07 11:25:36 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mtree.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MTREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MTREE_H_
end_define

begin_define
define|#
directive|define
name|KEYDEFAULT
value|(F_GID | F_MODE | F_NLINK | F_SIZE | F_SLINK | \ 			F_TIME | F_TYPE | F_UID | F_FLAGS)
end_define

begin_define
define|#
directive|define
name|MISMATCHEXIT
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_node
block|{
name|struct
name|_node
modifier|*
name|parent
decl_stmt|,
modifier|*
name|child
decl_stmt|;
comment|/* up, down */
name|struct
name|_node
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* left, right */
name|off_t
name|st_size
decl_stmt|;
comment|/* size */
name|struct
name|timespec
name|st_mtimespec
decl_stmt|;
comment|/* last modification time */
name|char
modifier|*
name|slink
decl_stmt|;
comment|/* symbolic link reference */
name|uid_t
name|st_uid
decl_stmt|;
comment|/* uid */
name|gid_t
name|st_gid
decl_stmt|;
comment|/* gid */
define|#
directive|define
name|MBITS
value|(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
name|mode_t
name|st_mode
decl_stmt|;
comment|/* mode */
name|dev_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|u_long
name|st_flags
decl_stmt|;
comment|/* flags */
name|nlink_t
name|st_nlink
decl_stmt|;
comment|/* link count */
name|u_long
name|cksum
decl_stmt|;
comment|/* check sum */
name|char
modifier|*
name|md5digest
decl_stmt|;
comment|/* MD5 digest */
name|char
modifier|*
name|rmd160digest
decl_stmt|;
comment|/* RMD-160 digest */
name|char
modifier|*
name|sha1digest
decl_stmt|;
comment|/* SHA1 digest */
name|char
modifier|*
name|tags
decl_stmt|;
comment|/* tags, comma delimited */
name|size_t
name|lineno
decl_stmt|;
comment|/* line # entry came from */
define|#
directive|define
name|F_CKSUM
value|0x00000001
comment|/* cksum(1) check sum */
define|#
directive|define
name|F_DEV
value|0x00000002
comment|/* device type */
define|#
directive|define
name|F_DONE
value|0x00000004
comment|/* directory done */
define|#
directive|define
name|F_FLAGS
value|0x00000008
comment|/* file flags */
define|#
directive|define
name|F_GID
value|0x00000010
comment|/* gid */
define|#
directive|define
name|F_GNAME
value|0x00000020
comment|/* group name */
define|#
directive|define
name|F_IGN
value|0x00000040
comment|/* ignore */
define|#
directive|define
name|F_MAGIC
value|0x00000080
comment|/* name has magic chars */
define|#
directive|define
name|F_MD5
value|0x00000100
comment|/* MD5 digest */
define|#
directive|define
name|F_MODE
value|0x00000200
comment|/* mode */
define|#
directive|define
name|F_NLINK
value|0x00000400
comment|/* number of links */
define|#
directive|define
name|F_OPT
value|0x00000800
comment|/* existence optional */
define|#
directive|define
name|F_RMD160
value|0x00001000
comment|/* RMD-160 digest */
define|#
directive|define
name|F_SHA1
value|0x00002000
comment|/* SHA1 digest */
define|#
directive|define
name|F_SIZE
value|0x00004000
comment|/* size */
define|#
directive|define
name|F_SLINK
value|0x00008000
comment|/* symbolic link */
define|#
directive|define
name|F_TAGS
value|0x00010000
comment|/* tags */
define|#
directive|define
name|F_TIME
value|0x00020000
comment|/* modification time */
define|#
directive|define
name|F_TYPE
value|0x00040000
comment|/* file type */
define|#
directive|define
name|F_UID
value|0x00080000
comment|/* uid */
define|#
directive|define
name|F_UNAME
value|0x00100000
comment|/* user name */
define|#
directive|define
name|F_VISIT
value|0x00200000
comment|/* file visited */
name|int
name|flags
decl_stmt|;
comment|/* items set */
define|#
directive|define
name|F_BLOCK
value|0x001
comment|/* block special */
define|#
directive|define
name|F_CHAR
value|0x002
comment|/* char special */
define|#
directive|define
name|F_DIR
value|0x004
comment|/* directory */
define|#
directive|define
name|F_FIFO
value|0x008
comment|/* fifo */
define|#
directive|define
name|F_FILE
value|0x010
comment|/* regular file */
define|#
directive|define
name|F_LINK
value|0x020
comment|/* symbolic link */
define|#
directive|define
name|F_SOCK
value|0x040
comment|/* socket */
name|int
name|type
decl_stmt|;
comment|/* file type */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* file name (must be last) */
block|}
name|NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
modifier|*
name|list
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|slist_t
typedef|;
end_typedef

begin_comment
comment|/*  * prototypes for functions published to other programs which want to use  * the specfile parser but don't want to pull in all of "extern.h"  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|inotype
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|nodetoino
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup_getid
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NODE
modifier|*
name|spec
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vispath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RP
parameter_list|(
name|p
parameter_list|)
define|\
value|((p)->fts_path[0] == '.'&& (p)->fts_path[1] == '/' ? \ 	    (p)->fts_path + 2 : (p)->fts_path)
end_define

begin_define
define|#
directive|define
name|UF_MASK
value|((UF_NODUMP | UF_IMMUTABLE |   \                   UF_APPEND | UF_OPAQUE)       \& UF_SETTABLE)
end_define

begin_comment
comment|/* user settable flags */
end_comment

begin_define
define|#
directive|define
name|SF_MASK
value|((SF_ARCHIVED | SF_IMMUTABLE | \                   SF_APPEND)& SF_SETTABLE)
end_define

begin_comment
comment|/* root settable flags */
end_comment

begin_define
define|#
directive|define
name|CH_MASK
value|(UF_MASK | SF_MASK)
end_define

begin_comment
comment|/* all settable flags */
end_comment

begin_define
define|#
directive|define
name|SP_FLGS
value|(SF_IMMUTABLE | SF_APPEND)
end_define

begin_comment
comment|/* special flags */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MTREE_H_ */
end_comment

end_unit

