begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dir.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_DIR_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_DIR_H_
end_define

begin_comment
comment|/*  * Theoretically, directories can be more than 2Gb in length, however, in  * practice this seems unlikely. So, we define the type doff_t as a 32-bit  * quantity to keep down the cost of doing lookup on a 32-bit machine.  */
end_comment

begin_define
define|#
directive|define
name|doff_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|MAXDIRSIZE
value|(0x7fffffff)
end_define

begin_comment
comment|/*  * A directory consists of some number of blocks of DIRBLKSIZ  * bytes, where DIRBLKSIZ is chosen such that it can be transferred  * to disk in a single atomic operation (e.g. 512 bytes on most machines).  *  * Each DIRBLKSIZ byte block contains some number of directory entry  * structures, which are of variable length.  Each directory entry has  * a struct direct at the front of it, containing its inode number,  * the length of the entry, and the length of the name contained in  * the entry.  These are followed by the name padded to a 4 byte boundary  * with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  *  * The macro DIRSIZ(fmt, dp) gives the amount of space required to represent  * a directory entry.  Free space in a directory is represented by  * entries which have dp->d_reclen> DIRSIZ(fmt, dp).  All DIRBLKSIZ bytes  * in a directory block are claimed by the directory entries.  This  * usually results in the last entry in a directory having a large  * dp->d_reclen.  When entries are deleted from a directory, the  * space is returned to the previous entry in the same directory  * block by increasing its dp->d_reclen.  If the first entry of  * a directory block is free, then its dp->d_ino is set to 0.  * Entries other than the first in a directory do not normally have  * dp->d_ino set to 0.  */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|DEV_BSIZE
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|direct
block|{
name|u_int32_t
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|u_int16_t
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_int8_t
name|d_type
decl_stmt|;
comment|/* file type, see below */
name|u_int8_t
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name with length<= MAXNAMLEN */
block|}
struct|;
end_struct

begin_comment
comment|/*  * File types  */
end_comment

begin_define
define|#
directive|define
name|DT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|DT_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|DT_CHR
value|2
end_define

begin_define
define|#
directive|define
name|DT_DIR
value|4
end_define

begin_define
define|#
directive|define
name|DT_BLK
value|6
end_define

begin_define
define|#
directive|define
name|DT_REG
value|8
end_define

begin_define
define|#
directive|define
name|DT_LNK
value|10
end_define

begin_define
define|#
directive|define
name|DT_SOCK
value|12
end_define

begin_define
define|#
directive|define
name|DT_WHT
value|14
end_define

begin_comment
comment|/*  * Convert between stat structure types and directory types.  */
end_comment

begin_define
define|#
directive|define
name|IFTODT
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& 0170000)>> 12)
end_define

begin_define
define|#
directive|define
name|DTTOIF
parameter_list|(
name|dirtype
parameter_list|)
value|((dirtype)<< 12)
end_define

begin_comment
comment|/*  * The DIRSIZ macro gives the minimum record length which will hold  * the directory entry.  This requires the amount of space in struct direct  * without the d_name field, plus enough space for the name with a terminating  * null byte (dp->d_namlen+1), rounded up to a 4 byte boundary.  *  *   */
end_comment

begin_define
define|#
directive|define
name|DIRECTSIZ
parameter_list|(
name|namlen
parameter_list|)
define|\
value|(((int)&((struct direct *)0)->d_name +				\ 	  ((namlen)+1)*sizeof(((struct direct *)0)->d_name[0]) + 3)& ~3)
end_define

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|oldfmt
parameter_list|,
name|dp
parameter_list|)
define|\
value|((oldfmt) ? DIRECTSIZ((dp)->d_type) : DIRECTSIZ((dp)->d_namlen))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|oldfmt
parameter_list|,
name|dp
parameter_list|)
define|\
value|DIRECTSIZ((dp)->d_namlen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OLDDIRFMT
value|1
end_define

begin_define
define|#
directive|define
name|NEWDIRFMT
value|0
end_define

begin_comment
comment|/*  * Template for manipulating directories.  Should use struct direct's,  * but the name field is MAXNAMLEN - 1, and this just won't do.  */
end_comment

begin_struct
struct|struct
name|dirtemplate
block|{
name|u_int32_t
name|dot_ino
decl_stmt|;
name|int16_t
name|dot_reclen
decl_stmt|;
name|u_int8_t
name|dot_type
decl_stmt|;
name|u_int8_t
name|dot_namlen
decl_stmt|;
name|char
name|dot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* must be multiple of 4 */
name|u_int32_t
name|dotdot_ino
decl_stmt|;
name|int16_t
name|dotdot_reclen
decl_stmt|;
name|u_int8_t
name|dotdot_type
decl_stmt|;
name|u_int8_t
name|dotdot_namlen
decl_stmt|;
name|char
name|dotdot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* ditto */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the old format of directories, sanz type element.  */
end_comment

begin_struct
struct|struct
name|odirtemplate
block|{
name|u_int32_t
name|dot_ino
decl_stmt|;
name|int16_t
name|dot_reclen
decl_stmt|;
name|u_int16_t
name|dot_namlen
decl_stmt|;
name|char
name|dot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* must be multiple of 4 */
name|u_int32_t
name|dotdot_ino
decl_stmt|;
name|int16_t
name|dotdot_reclen
decl_stmt|;
name|u_int16_t
name|dotdot_namlen
decl_stmt|;
name|char
name|dotdot_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* ditto */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DIR_H_ */
end_comment

end_unit

