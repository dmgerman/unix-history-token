begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dirent.h	8.3 (Berkeley) 8/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DIRENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DIRENT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_INO_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ino_t
name|ino_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INO_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The dirent structure defines the format of directory entries returned by  * the getdirentries(2) system call.  *  * A directory entry has a struct dirent at the front of it, containing its  * inode number, the length of the entry, and the length of the name  * contained in the entry.  These are followed by the name padded to an 8  * byte boundary with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  *  * Explicit padding between the last member of the header (d_namelen) and  * d_name avoids ABI padding at the end of dirent on LP64 architectures.  * There is code depending on d_name being last.  */
end_comment

begin_struct
struct|struct
name|dirent
block|{
name|ino_t
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|off_t
name|d_off
decl_stmt|;
comment|/* directory offset of entry */
name|__uint16_t
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|__uint8_t
name|d_type
decl_stmt|;
comment|/* file type, see below */
name|__uint8_t
name|d_pad0
decl_stmt|;
name|__uint16_t
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|__uint16_t
name|d_pad1
decl_stmt|;
if|#
directive|if
name|__BSD_VISIBLE
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
else|#
directive|else
name|char
name|d_name
index|[
literal|255
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WANT_FREEBSD11_DIRENT
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_struct
struct|struct
name|freebsd11_dirent
block|{
name|__uint32_t
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|__uint16_t
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|__uint8_t
name|d_type
decl_stmt|;
comment|/* file type, see below */
name|__uint8_t
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
literal|255
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WANT_FREEBSD11_DIRENT || _KERNEL */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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
comment|/*  * The _GENERIC_DIRSIZ macro gives the minimum record length which will hold  * the directory entry.  This returns the amount of space in struct direct  * without the d_name field, plus enough space for the name with a terminating  * null byte (dp->d_namlen+1), rounded up to a 8 byte boundary.  *  * XXX although this macro is in the implementation namespace, it requires  * a manifest constant that is not.  */
end_comment

begin_define
define|#
directive|define
name|_GENERIC_DIRLEN
parameter_list|(
name|namlen
parameter_list|)
define|\
value|((__offsetof(struct dirent, d_name) + (namlen) + 1 + 7)& ~7)
end_define

begin_define
define|#
directive|define
name|_GENERIC_DIRSIZ
parameter_list|(
name|dp
parameter_list|)
value|_GENERIC_DIRLEN((dp)->d_namlen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|GENERIC_DIRSIZ
parameter_list|(
name|dp
parameter_list|)
value|_GENERIC_DIRSIZ(dp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DIRENT_H_ */
end_comment

end_unit

