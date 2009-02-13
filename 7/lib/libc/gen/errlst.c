begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)errlst.c	8.2 (Berkeley) 11/16/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|sys_errlist
index|[]
init|=
block|{
literal|"Undefined error: 0"
block|,
comment|/*  0 - ENOERROR */
literal|"Operation not permitted"
block|,
comment|/*  1 - EPERM */
literal|"No such file or directory"
block|,
comment|/*  2 - ENOENT */
literal|"No such process"
block|,
comment|/*  3 - ESRCH */
literal|"Interrupted system call"
block|,
comment|/*  4 - EINTR */
literal|"Input/output error"
block|,
comment|/*  5 - EIO */
literal|"Device not configured"
block|,
comment|/*  6 - ENXIO */
literal|"Argument list too long"
block|,
comment|/*  7 - E2BIG */
literal|"Exec format error"
block|,
comment|/*  8 - ENOEXEC */
literal|"Bad file descriptor"
block|,
comment|/*  9 - EBADF */
literal|"No child processes"
block|,
comment|/* 10 - ECHILD */
literal|"Resource deadlock avoided"
block|,
comment|/* 11 - EDEADLK */
literal|"Cannot allocate memory"
block|,
comment|/* 12 - ENOMEM */
literal|"Permission denied"
block|,
comment|/* 13 - EACCES */
literal|"Bad address"
block|,
comment|/* 14 - EFAULT */
literal|"Block device required"
block|,
comment|/* 15 - ENOTBLK */
literal|"Device busy"
block|,
comment|/* 16 - EBUSY */
literal|"File exists"
block|,
comment|/* 17 - EEXIST */
literal|"Cross-device link"
block|,
comment|/* 18 - EXDEV */
literal|"Operation not supported by device"
block|,
comment|/* 19 - ENODEV */
literal|"Not a directory"
block|,
comment|/* 20 - ENOTDIR */
literal|"Is a directory"
block|,
comment|/* 21 - EISDIR */
literal|"Invalid argument"
block|,
comment|/* 22 - EINVAL */
literal|"Too many open files in system"
block|,
comment|/* 23 - ENFILE */
literal|"Too many open files"
block|,
comment|/* 24 - EMFILE */
literal|"Inappropriate ioctl for device"
block|,
comment|/* 25 - ENOTTY */
literal|"Text file busy"
block|,
comment|/* 26 - ETXTBSY */
literal|"File too large"
block|,
comment|/* 27 - EFBIG */
literal|"No space left on device"
block|,
comment|/* 28 - ENOSPC */
literal|"Illegal seek"
block|,
comment|/* 29 - ESPIPE */
literal|"Read-only file system"
block|,
comment|/* 30 - EROFS */
literal|"Too many links"
block|,
comment|/* 31 - EMLINK */
literal|"Broken pipe"
block|,
comment|/* 32 - EPIPE */
comment|/* math software */
literal|"Numerical argument out of domain"
block|,
comment|/* 33 - EDOM */
literal|"Result too large"
block|,
comment|/* 34 - ERANGE */
comment|/* non-blocking and interrupt i/o */
literal|"Resource temporarily unavailable"
block|,
comment|/* 35 - EAGAIN */
comment|/* 35 - EWOULDBLOCK */
literal|"Operation now in progress"
block|,
comment|/* 36 - EINPROGRESS */
literal|"Operation already in progress"
block|,
comment|/* 37 - EALREADY */
comment|/* ipc/network software -- argument errors */
literal|"Socket operation on non-socket"
block|,
comment|/* 38 - ENOTSOCK */
literal|"Destination address required"
block|,
comment|/* 39 - EDESTADDRREQ */
literal|"Message too long"
block|,
comment|/* 40 - EMSGSIZE */
literal|"Protocol wrong type for socket"
block|,
comment|/* 41 - EPROTOTYPE */
literal|"Protocol not available"
block|,
comment|/* 42 - ENOPROTOOPT */
literal|"Protocol not supported"
block|,
comment|/* 43 - EPROTONOSUPPORT */
literal|"Socket type not supported"
block|,
comment|/* 44 - ESOCKTNOSUPPORT */
literal|"Operation not supported"
block|,
comment|/* 45 - EOPNOTSUPP */
literal|"Protocol family not supported"
block|,
comment|/* 46 - EPFNOSUPPORT */
comment|/* 47 - EAFNOSUPPORT */
literal|"Address family not supported by protocol family"
block|,
literal|"Address already in use"
block|,
comment|/* 48 - EADDRINUSE */
literal|"Can't assign requested address"
block|,
comment|/* 49 - EADDRNOTAVAIL */
comment|/* ipc/network software -- operational errors */
literal|"Network is down"
block|,
comment|/* 50 - ENETDOWN */
literal|"Network is unreachable"
block|,
comment|/* 51 - ENETUNREACH */
literal|"Network dropped connection on reset"
block|,
comment|/* 52 - ENETRESET */
literal|"Software caused connection abort"
block|,
comment|/* 53 - ECONNABORTED */
literal|"Connection reset by peer"
block|,
comment|/* 54 - ECONNRESET */
literal|"No buffer space available"
block|,
comment|/* 55 - ENOBUFS */
literal|"Socket is already connected"
block|,
comment|/* 56 - EISCONN */
literal|"Socket is not connected"
block|,
comment|/* 57 - ENOTCONN */
literal|"Can't send after socket shutdown"
block|,
comment|/* 58 - ESHUTDOWN */
literal|"Too many references: can't splice"
block|,
comment|/* 59 - ETOOMANYREFS */
literal|"Operation timed out"
block|,
comment|/* 60 - ETIMEDOUT */
literal|"Connection refused"
block|,
comment|/* 61 - ECONNREFUSED */
literal|"Too many levels of symbolic links"
block|,
comment|/* 62 - ELOOP */
literal|"File name too long"
block|,
comment|/* 63 - ENAMETOOLONG */
comment|/* should be rearranged */
literal|"Host is down"
block|,
comment|/* 64 - EHOSTDOWN */
literal|"No route to host"
block|,
comment|/* 65 - EHOSTUNREACH */
literal|"Directory not empty"
block|,
comment|/* 66 - ENOTEMPTY */
comment|/* quotas& mush */
literal|"Too many processes"
block|,
comment|/* 67 - EPROCLIM */
literal|"Too many users"
block|,
comment|/* 68 - EUSERS */
literal|"Disc quota exceeded"
block|,
comment|/* 69 - EDQUOT */
comment|/* Network File System */
literal|"Stale NFS file handle"
block|,
comment|/* 70 - ESTALE */
literal|"Too many levels of remote in path"
block|,
comment|/* 71 - EREMOTE */
literal|"RPC struct is bad"
block|,
comment|/* 72 - EBADRPC */
literal|"RPC version wrong"
block|,
comment|/* 73 - ERPCMISMATCH */
literal|"RPC prog. not avail"
block|,
comment|/* 74 - EPROGUNAVAIL */
literal|"Program version wrong"
block|,
comment|/* 75 - EPROGMISMATCH */
literal|"Bad procedure for program"
block|,
comment|/* 76 - EPROCUNAVAIL */
literal|"No locks available"
block|,
comment|/* 77 - ENOLCK */
literal|"Function not implemented"
block|,
comment|/* 78 - ENOSYS */
literal|"Inappropriate file type or format"
block|,
comment|/* 79 - EFTYPE */
literal|"Authentication error"
block|,
comment|/* 80 - EAUTH */
literal|"Need authenticator"
block|,
comment|/* 81 - ENEEDAUTH */
literal|"Identifier removed"
block|,
comment|/* 82 - EIDRM */
literal|"No message of desired type"
block|,
comment|/* 83 - ENOMSG */
literal|"Value too large to be stored in data type"
block|,
comment|/* 84 - EOVERFLOW */
literal|"Operation canceled"
block|,
comment|/* 85 - ECANCELED */
literal|"Illegal byte sequence"
block|,
comment|/* 86 - EILSEQ */
literal|"Attribute not found"
block|,
comment|/* 87 - ENOATTR */
comment|/* General */
literal|"Programming error"
block|,
comment|/* 88 - EDOOFUS */
literal|"Bad message"
block|,
comment|/* 89 - EBADMSG */
literal|"Multihop attempted"
block|,
comment|/* 90 - EMULTIHOP */
literal|"Link has been severed"
block|,
comment|/* 91 - ENOLINK */
literal|"Protocol error"
block|,
comment|/* 92 - EPROTO */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|sys_nerr
init|=
sizeof|sizeof
argument_list|(
name|sys_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|sys_errlist
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

