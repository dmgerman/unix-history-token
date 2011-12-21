begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Michihiro NAKAJIMA  * Copyright (c) 2003-2006 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TODO: A lot of stuff in here isn't actually used by libarchive and  * can be trimmed out.  Note that this file is used by libarchive and  * libarchive_test but nowhere else.  (But note that it gets compiled  * with many different Windows environments, including MinGW, Visual  * Studio, and Cygwin.  Significant changes should be tested in all three.)  */
end_comment

begin_comment
comment|/*  * TODO: Don't use off_t in here.  Use __int64 instead.  Note that  * Visual Studio and the Windows SDK define off_t as 32 bits; Win32's  * more modern file handling APIs all use __int64 instead of off_t.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBARCHIVE_ARCHIVE_WINDOWS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|LIBARCHIVE_ARCHIVE_WINDOWS_H_INCLUDED
end_define

begin_comment
comment|/* Start of configuration for native Win32  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|set_errno
parameter_list|(
name|val
parameter_list|)
value|((errno)=val)
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|//brings in NULL
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_define
define|#
directive|define
name|NOCRYPT
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|//#define	EFTYPE 7
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDIN_FILENO
argument_list|)
end_if

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDOUT_FILENO
argument_list|)
end_if

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDERR_FILENO
argument_list|)
end_if

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|/* TODO: Fix the code, don't suppress the warnings. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4244
name|)
end_pragma

begin_comment
comment|/* 'conversion' conversion from 'type1' to 'type2', possible loss of data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|8068
end_pragma

begin_comment
comment|/* Constant out of range in comparison. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warn
name|-
name|8072
end_pragma

begin_comment
comment|/* Suspicious pointer arithmetic. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
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
comment|/* Alias the Windows _function to the POSIX equivalent. */
end_comment

begin_define
define|#
directive|define
name|access
value|_access
end_define

begin_define
define|#
directive|define
name|chdir
value|__la_chdir
end_define

begin_define
define|#
directive|define
name|chmod
value|__la_chmod
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|fcntl
value|__la_fcntl
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|fileno
end_ifndef

begin_define
define|#
directive|define
name|fileno
value|_fileno
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fstat
value|__la_fstat
end_define

begin_define
define|#
directive|define
name|ftruncate
value|__la_ftruncate
end_define

begin_define
define|#
directive|define
name|futimes
value|__la_futimes
end_define

begin_define
define|#
directive|define
name|getcwd
value|_getcwd
end_define

begin_define
define|#
directive|define
name|link
value|__la_link
end_define

begin_define
define|#
directive|define
name|lseek
value|__la_lseek
end_define

begin_define
define|#
directive|define
name|lstat
value|__la_stat
end_define

begin_define
define|#
directive|define
name|mbstowcs
value|__la_mbstowcs
end_define

begin_define
define|#
directive|define
name|mkdir
parameter_list|(
name|d
parameter_list|,
name|m
parameter_list|)
value|__la_mkdir(d, m)
end_define

begin_define
define|#
directive|define
name|mktemp
value|_mktemp
end_define

begin_define
define|#
directive|define
name|open
value|__la_open
end_define

begin_define
define|#
directive|define
name|read
value|__la_read
end_define

begin_define
define|#
directive|define
name|rmdir
value|__la_rmdir
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|setmode
value|_setmode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|path
parameter_list|,
name|stref
parameter_list|)
value|__la_stat(path,stref)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tzset
value|_tzset
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|umask
value|_umask
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|unlink
value|__la_unlink
end_define

begin_define
define|#
directive|define
name|utimes
value|__la_utimes
end_define

begin_define
define|#
directive|define
name|waitpid
value|__la_waitpid
end_define

begin_define
define|#
directive|define
name|write
value|__la_write
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|_O_WRONLY
end_define

begin_define
define|#
directive|define
name|O_TRUNC
value|_O_TRUNC
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|_O_CREAT
end_define

begin_define
define|#
directive|define
name|O_EXCL
value|_O_EXCL
end_define

begin_define
define|#
directive|define
name|O_BINARY
value|_O_BINARY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFIFO
end_ifndef

begin_define
define|#
directive|define
name|_S_IFIFO
value|0010000
end_define

begin_comment
comment|/* pipe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFCHR
end_ifndef

begin_define
define|#
directive|define
name|_S_IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFDIR
end_ifndef

begin_define
define|#
directive|define
name|_S_IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFBLK
end_ifndef

begin_define
define|#
directive|define
name|_S_IFBLK
value|0060000
end_define

begin_comment
comment|/* block special */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFLNK
end_ifndef

begin_define
define|#
directive|define
name|_S_IFLNK
value|0120000
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFSOCK
end_ifndef

begin_define
define|#
directive|define
name|_S_IFSOCK
value|0140000
end_define

begin_comment
comment|/* socket */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFREG
end_ifndef

begin_define
define|#
directive|define
name|_S_IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_S_IFMT
end_ifndef

begin_define
define|#
directive|define
name|_S_IFMT
value|0170000
end_define

begin_comment
comment|/* file type mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFIFO
end_ifndef

begin_define
define|#
directive|define
name|S_IFIFO
value|_S_IFIFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#define	S_IFCHR  _S_IFCHR
end_comment

begin_comment
comment|//#define	S_IFDIR  _S_IFDIR
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFBLK
end_ifndef

begin_define
define|#
directive|define
name|S_IFBLK
value|_S_IFBLK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFLNK
end_ifndef

begin_define
define|#
directive|define
name|S_IFLNK
value|_S_IFLNK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFSOCK
end_ifndef

begin_define
define|#
directive|define
name|S_IFSOCK
value|_S_IFSOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#define	S_IFREG  _S_IFREG
end_comment

begin_comment
comment|//#define	S_IFMT   _S_IFMT
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
end_define

begin_comment
comment|/* fifo or socket */
end_comment

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
end_define

begin_comment
comment|/* char special */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_comment
comment|/* regular file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFLNK)
end_define

begin_comment
comment|/* Symbolic link */
end_comment

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
end_define

begin_comment
comment|/* Socket */
end_comment

begin_define
define|#
directive|define
name|_S_ISUID
value|0004000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|_S_ISGID
value|0002000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|_S_ISVTX
value|0001000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|S_ISUID
value|_S_ISUID
end_define

begin_define
define|#
directive|define
name|S_ISGID
value|_S_ISGID
end_define

begin_define
define|#
directive|define
name|S_ISVTX
value|_S_ISVTX
end_define

begin_define
define|#
directive|define
name|_S_IRWXU
value|(_S_IREAD | _S_IWRITE | _S_IEXEC)
end_define

begin_define
define|#
directive|define
name|_S_IXUSR
value|_S_IEXEC
end_define

begin_comment
comment|/* read permission, user */
end_comment

begin_define
define|#
directive|define
name|_S_IWUSR
value|_S_IWRITE
end_define

begin_comment
comment|/* write permission, user */
end_comment

begin_define
define|#
directive|define
name|_S_IRUSR
value|_S_IREAD
end_define

begin_comment
comment|/* execute/search permission, user */
end_comment

begin_define
define|#
directive|define
name|_S_IRWXG
value|(_S_IRWXU>> 3)
end_define

begin_define
define|#
directive|define
name|_S_IXGRP
value|(_S_IXUSR>> 3)
end_define

begin_comment
comment|/* read permission, group */
end_comment

begin_define
define|#
directive|define
name|_S_IWGRP
value|(_S_IWUSR>> 3)
end_define

begin_comment
comment|/* write permission, group */
end_comment

begin_define
define|#
directive|define
name|_S_IRGRP
value|(_S_IRUSR>> 3)
end_define

begin_comment
comment|/* execute/search permission, group */
end_comment

begin_define
define|#
directive|define
name|_S_IRWXO
value|(_S_IRWXG>> 3)
end_define

begin_define
define|#
directive|define
name|_S_IXOTH
value|(_S_IXGRP>> 3)
end_define

begin_comment
comment|/* read permission, other */
end_comment

begin_define
define|#
directive|define
name|_S_IWOTH
value|(_S_IWGRP>> 3)
end_define

begin_comment
comment|/* write permission, other */
end_comment

begin_define
define|#
directive|define
name|_S_IROTH
value|(_S_IRGRP>> 3)
end_define

begin_comment
comment|/* execute/search permission, other */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXU
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXU
value|_S_IRWXU
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|_S_IXUSR
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|_S_IWUSR
end_define

begin_define
define|#
directive|define
name|S_IRUSR
value|_S_IRUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_IRWXG
value|_S_IRWXG
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|_S_IXGRP
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|_S_IWGRP
end_define

begin_define
define|#
directive|define
name|S_IRGRP
value|_S_IRGRP
end_define

begin_define
define|#
directive|define
name|S_IRWXO
value|_S_IRWXO
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|_S_IXOTH
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|_S_IWOTH
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|_S_IROTH
end_define

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* Duplicate file descriptor.  */
end_comment

begin_define
define|#
directive|define
name|F_GETFD
value|1
end_define

begin_comment
comment|/* Get file descriptor flags.  */
end_comment

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_comment
comment|/* Set file descriptor flags.  */
end_comment

begin_define
define|#
directive|define
name|F_GETFL
value|3
end_define

begin_comment
comment|/* Get file status flags.  */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|4
end_define

begin_comment
comment|/* Set file status flags.  */
end_comment

begin_define
define|#
directive|define
name|F_GETOWN
value|5
end_define

begin_comment
comment|/* Get owner (receiver of SIGIO).  */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN
value|6
end_define

begin_comment
comment|/* Set owner (receiver of SIGIO).  */
end_comment

begin_define
define|#
directive|define
name|F_GETLK
value|7
end_define

begin_comment
comment|/* Get record locking info.  */
end_comment

begin_define
define|#
directive|define
name|F_SETLK
value|8
end_define

begin_comment
comment|/* Set record locking info (non-blocking).  */
end_comment

begin_define
define|#
directive|define
name|F_SETLKW
value|9
end_define

begin_comment
comment|/* Set record locking info (blocking).  */
end_comment

begin_comment
comment|/* XXX missing */
end_comment

begin_define
define|#
directive|define
name|F_GETLK64
value|7
end_define

begin_comment
comment|/* Get record locking info.  */
end_comment

begin_define
define|#
directive|define
name|F_SETLK64
value|8
end_define

begin_comment
comment|/* Set record locking info (non-blocking).  */
end_comment

begin_define
define|#
directive|define
name|F_SETLKW64
value|9
end_define

begin_comment
comment|/* Set record locking info (blocking).  */
end_comment

begin_comment
comment|/* File descriptor flags used with F_GETFD and F_SETFD.  */
end_comment

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_comment
comment|/* Close on exec.  */
end_comment

begin_comment
comment|//NOT SURE IF O_NONBLOCK is OK here but at least the 0x0004 flag is not used by anything else...
end_comment

begin_define
define|#
directive|define
name|O_NONBLOCK
value|0x0004
end_define

begin_comment
comment|/* Non-blocking I/O.  */
end_comment

begin_comment
comment|//#define	O_NDELAY   O_NONBLOCK
end_comment

begin_comment
comment|/* Symbolic constants for the access() function */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|F_OK
argument_list|)
end_if

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_comment
comment|/*  Test for read permission    */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_comment
comment|/*  Test for write permission   */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_comment
comment|/*  Test for execute permission */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/*  Test for existence of file  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LARGEFILE_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|__USE_LARGEFILE
value|1
end_define

begin_comment
comment|/* declare fseeko and ftello */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|_FILE_OFFSET_BITS
operator|&&
name|_FILE_OFFSET_BITS
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|__USE_FILE_OFFSET64
value|1
end_define

begin_comment
comment|/* replace 32-bit functions by 64-bit ones */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__USE_LARGEFILE
operator|&&
name|__USE_FILE_OFFSET64
end_if

begin_comment
comment|/* replace stat and seek by their large-file equivalents */
end_comment

begin_undef
undef|#
directive|undef
name|stat
end_undef

begin_define
define|#
directive|define
name|stat
value|_stati64
end_define

begin_undef
undef|#
directive|undef
name|lseek
end_undef

begin_define
define|#
directive|define
name|lseek
value|_lseeki64
end_define

begin_define
define|#
directive|define
name|lseek64
value|_lseeki64
end_define

begin_define
define|#
directive|define
name|tell
value|_telli64
end_define

begin_define
define|#
directive|define
name|tell64
value|_telli64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__MINGW32__
end_ifdef

begin_define
define|#
directive|define
name|fseek
value|fseeko64
end_define

begin_define
define|#
directive|define
name|fseeko
value|fseeko64
end_define

begin_define
define|#
directive|define
name|ftell
value|ftello64
end_define

begin_define
define|#
directive|define
name|ftello
value|ftello64
end_define

begin_define
define|#
directive|define
name|ftell64
value|ftello64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LARGE_FILES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WINSOCK_TIMEVAL
end_ifdef

begin_comment
comment|/* Winsock timeval has long size tv_sec. */
end_comment

begin_define
define|#
directive|define
name|__timeval
value|timeval
end_define

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|_timeval64i32
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__timeval
value|_timeval64i32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of Win32 definitions. */
end_comment

begin_comment
comment|/* Tell libarchive code that we have simulations for these. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FTRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FUTIMES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTIMES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LINK
end_ifndef

begin_define
define|#
directive|define
name|HAVE_LINK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Replacement POSIX function */
end_comment

begin_function_decl
specifier|extern
name|int
name|__la_chdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_chmod
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_fcntl
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|cmd
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_fstat
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|stat
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_futimes
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|struct
name|__timeval
modifier|*
name|times
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_link
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
specifier|const
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|__int64
name|__la_lseek
parameter_list|(
name|int
name|fd
parameter_list|,
name|__int64
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__la_mbstowcs
parameter_list|(
name|wchar_t
modifier|*
name|wcstr
parameter_list|,
specifier|const
name|char
modifier|*
name|mbstr
parameter_list|,
name|size_t
name|nwchars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_mkdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|flags
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|__la_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_rmdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_unlink
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__la_utimes
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|struct
name|__timeval
modifier|*
name|times
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|__la_waitpid
parameter_list|(
name|pid_t
name|wpid
parameter_list|,
name|int
modifier|*
name|status
parameter_list|,
name|int
name|option
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|__la_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_stat64i32
parameter_list|(
name|path
parameter_list|,
name|st
parameter_list|)
value|__la_stat(path, st)
end_define

begin_define
define|#
directive|define
name|_stat64
parameter_list|(
name|path
parameter_list|,
name|st
parameter_list|)
value|__la_stat(path, st)
end_define

begin_comment
comment|/* for status returned by la_waitpid */
end_comment

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|sts
parameter_list|)
value|((sts& 0x100) == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|sts
parameter_list|)
value|(sts& 0x0FF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBARCHIVE_ARCHIVE_WINDOWS_H_INCLUDED */
end_comment

end_unit

