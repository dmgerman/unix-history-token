begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)dinode.h	7.10 (Berkeley) 5/8/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_DINODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_DINODE_H_
value|1
end_define

begin_comment
comment|/*  * A dinode contains all the meta-data associated with a UFS file.  * This structure defines the on-disk format of a dinode.  */
end_comment

begin_define
define|#
directive|define
name|NDADDR
value|12
end_define

begin_comment
comment|/* direct addresses in inode */
end_comment

begin_define
define|#
directive|define
name|NIADDR
value|3
end_define

begin_comment
comment|/* indirect addresses in inode */
end_comment

begin_define
define|#
directive|define
name|MAXFASTLINK
value|(((NDADDR+NIADDR) * sizeof(daddr_t)) - 1)
end_define

begin_struct
struct|struct
name|dinode
block|{
name|u_short
name|di_mode
decl_stmt|;
comment|/*  0: mode and type of file */
name|short
name|di_nlink
decl_stmt|;
comment|/*  2: number of links to file */
name|uid_t
name|di_uid
decl_stmt|;
comment|/*  4: owner's user id */
name|gid_t
name|di_gid
decl_stmt|;
comment|/*  6: owner's group id */
union|union
block|{
comment|/*		u_quad_t v;*/
name|u_long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|di_qsize
union|;
comment|/*  8: number of bytes in file */
name|time_t
name|di_atime
decl_stmt|;
comment|/* 16: time last accessed */
name|long
name|di_atspare
decl_stmt|;
name|time_t
name|di_mtime
decl_stmt|;
comment|/* 24: time last modified */
name|long
name|di_mtspare
decl_stmt|;
name|time_t
name|di_ctime
decl_stmt|;
comment|/* 32: last time inode changed */
name|long
name|di_ctspare
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|daddr_t
name|di_udb
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/* 40: disk block addresses */
name|daddr_t
name|di_uib
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/* 88: indirect blocks */
block|}
name|di_addr
struct|;
name|char
name|di_usymlink
index|[
name|MAXFASTLINK
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|di_un
union|;
name|long
name|di_flags
decl_stmt|;
comment|/* 100: status, currently unused */
name|long
name|di_blocks
decl_stmt|;
comment|/* 104: blocks actually held */
name|long
name|di_gen
decl_stmt|;
comment|/* 108: generation number */
define|#
directive|define
name|DI_SPARE_SZ
value|4
comment|/* 112: spare for 4 longs */
name|u_long
name|di_spare
index|[
name|DI_SPARE_SZ
index|]
decl_stmt|;
comment|/* reserved (unused) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|di_db
value|di_un.di_addr.di_udb
end_define

begin_define
define|#
directive|define
name|di_ib
value|di_un.di_addr.di_uib
end_define

begin_define
define|#
directive|define
name|di_symlink
value|di_un.di_usymlink
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/* ugh! -- must be fixed */
end_comment

begin_define
define|#
directive|define
name|di_size
value|di_qsize.val[0]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|di_size
value|di_qsize.val[1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|di_rdev
value|di_db[0]
end_define

begin_comment
comment|/* file modes */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|0170000
end_define

begin_comment
comment|/* mask of file type */
end_comment

begin_define
define|#
directive|define
name|IFIFO
value|0010000
end_define

begin_comment
comment|/* named pipe (fifo) */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|0020000
end_define

begin_comment
comment|/* character special device */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|0060000
end_define

begin_comment
comment|/* block special device */
end_comment

begin_define
define|#
directive|define
name|IFREG
value|0100000
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|IFLNK
value|0120000
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|IFSOCK
value|0140000
end_define

begin_comment
comment|/* UNIX domain socket */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|04000
end_define

begin_comment
comment|/* set user identifier when exec'ing */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|02000
end_define

begin_comment
comment|/* set group identifier when exec'ing */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|01000
end_define

begin_comment
comment|/* save execution information on exit */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0200
end_define

begin_comment
comment|/* write permission */
end_comment

begin_define
define|#
directive|define
name|IEXEC
value|0100
end_define

begin_comment
comment|/* execute permission */
end_comment

begin_define
define|#
directive|define
name|DFASTLINK
parameter_list|(
name|di
parameter_list|)
define|\
value|((((di).di_mode& IFMT) == IFLNK)&& \ 	 ((di).di_size<= MAXFASTLINK)&& \ 	 ((di).di_size == (di).di_spare[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UFS_DINODE_H_ */
end_comment

end_unit

