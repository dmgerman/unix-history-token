begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)errlst.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sys_errlist
index|[]
init|=
block|{
literal|"Error 0"
block|,
literal|"Not owner"
block|,
comment|/* 1 - EPERM */
literal|"No such file or directory"
block|,
comment|/* 2 - ENOENT */
literal|"No such process"
block|,
comment|/* 3 - ESRCH */
literal|"Interrupted system call"
block|,
comment|/* 4 - EINTR */
literal|"I/O error"
block|,
comment|/* 5 - EIO */
literal|"No such device or address"
block|,
comment|/* 6 - ENXIO */
literal|"Arg list too long"
block|,
comment|/* 7 - E2BIG */
literal|"Exec format error"
block|,
comment|/* 8 - ENOEXEC */
literal|"Bad file number"
block|,
comment|/* 9 - EBADF */
literal|"No children"
block|,
comment|/* 10 - ECHILD */
literal|"No more processes"
block|,
comment|/* 11 - EAGAIN */
literal|"Not enough memory"
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
literal|"No such device"
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
literal|"File table overflow"
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
literal|"Argument too large"
block|,
comment|/* 33 - EDOM */
literal|"Result too large"
block|,
comment|/* 34 - ERANGE */
comment|/* non-blocking and interrupt i/o */
literal|"Operation would block"
block|,
comment|/* 35 - EWOULDBLOCK */
literal|"Operation now in progress"
block|,
comment|/* 36 - EINPROGRESS */
literal|"Operation already in progress"
block|,
comment|/* 37 - EALREADY */
comment|/* ipc/network software */
comment|/* argument errors */
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
literal|"Option not supported by protocol"
block|,
comment|/* 42 - ENOPROTOOPT */
literal|"Protocol not supported"
block|,
comment|/* 43 - EPROTONOSUPPORT */
literal|"Socket type not supported"
block|,
comment|/* 44 - ESOCKTNOSUPPORT */
literal|"Operation not supported on socket"
block|,
comment|/* 45 - EOPNOTSUPP */
literal|"Protocol family not supported"
block|,
comment|/* 46 - EPFNOSUPPORT */
literal|"Address family not supported by protocol family"
block|,
comment|/* 47 - EAFNOSUPPORT */
literal|"Address already in use"
block|,
comment|/* 48 - EADDRINUSE */
literal|"Can't assign requested address"
block|,
comment|/* 49 - EADDRNOTAVAIL */
comment|/* operational errors */
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
literal|"Error 59"
block|,
comment|/* 59 - unused */
literal|"Connection timed out"
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
literal|"Host is down"
block|,
comment|/* 64 - EHOSTDOWN */
literal|"Host is unreachable"
block|,
comment|/* 65 - EHOSTUNREACH */
literal|"Directory not empty"
block|,
comment|/* 66 - ENOTEMPTY */
literal|"Too many processes"
block|,
comment|/* 67 - EPROCLIM */
literal|"Too many users"
block|,
comment|/* 68 - EUSERS */
literal|"Disc quota exceeded"
block|,
comment|/* 69 - EDQUOT */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sys_nerr
init|=
block|{
sizeof|sizeof
name|sys_errlist
operator|/
sizeof|sizeof
name|sys_errlist
index|[
literal|0
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

end_unit

