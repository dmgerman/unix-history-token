begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mtree.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|KEYDEFAULT
define|\
value|(F_GID | F_MODE | F_NLINK | F_SIZE | F_SLINK | F_TIME | F_UID | F_FLAGS)
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
name|sha1digest
decl_stmt|;
comment|/* SHA-1 digest */
name|char
modifier|*
name|rmd160digest
decl_stmt|;
comment|/* RIPEMD160 digest */
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
name|u_long
name|st_flags
decl_stmt|;
comment|/* flags */
name|nlink_t
name|st_nlink
decl_stmt|;
comment|/* link count */
define|#
directive|define
name|F_CKSUM
value|0x0001
comment|/* check sum */
define|#
directive|define
name|F_DONE
value|0x0002
comment|/* directory done */
define|#
directive|define
name|F_GID
value|0x0004
comment|/* gid */
define|#
directive|define
name|F_GNAME
value|0x0008
comment|/* group name */
define|#
directive|define
name|F_IGN
value|0x0010
comment|/* ignore */
define|#
directive|define
name|F_MAGIC
value|0x0020
comment|/* name has magic chars */
define|#
directive|define
name|F_MODE
value|0x0040
comment|/* mode */
define|#
directive|define
name|F_NLINK
value|0x0080
comment|/* number of links */
define|#
directive|define
name|F_SIZE
value|0x0100
comment|/* size */
define|#
directive|define
name|F_SLINK
value|0x0200
comment|/* link count */
define|#
directive|define
name|F_TIME
value|0x0400
comment|/* modification time */
define|#
directive|define
name|F_TYPE
value|0x0800
comment|/* file type */
define|#
directive|define
name|F_UID
value|0x1000
comment|/* uid */
define|#
directive|define
name|F_UNAME
value|0x2000
comment|/* user name */
define|#
directive|define
name|F_VISIT
value|0x4000
comment|/* file visited */
define|#
directive|define
name|F_MD5
value|0x8000
comment|/* MD5 digest */
define|#
directive|define
name|F_NOCHANGE
value|0x10000
comment|/* If owner/mode "wrong", do */
comment|/* not change */
define|#
directive|define
name|F_SHA1
value|0x20000
comment|/* SHA-1 digest */
define|#
directive|define
name|F_RMD160
value|0x40000
comment|/* RIPEMD160 digest */
define|#
directive|define
name|F_FLAGS
value|0x80000
comment|/* file flags */
name|u_int
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
name|u_char
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

end_unit

