begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dirent.h	8.1 (Berkeley) 6/2/93  * $Id$  */
end_comment

begin_comment
comment|/*  * The dirent structure defines the format of directory entries returned by   * the getdirentries(2) system call.  *  * A directory entry has a struct dirent at the front of it, containing its  * inode number, the length of the entry, and the length of the name  * contained in the entry.  These are followed by the name padded to a 4  * byte boundary with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  */
end_comment

begin_struct
struct|struct
name|dirent
block|{
name|unsigned
name|long
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|unsigned
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|unsigned
name|char
name|d_type
decl_stmt|;
comment|/* file type, see below */
name|unsigned
name|char
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
name|char
name|d_name
index|[
literal|255
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
else|#
directive|else
define|#
directive|define
name|MAXNAMLEN
value|255
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
endif|#
directive|endif
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

end_unit

