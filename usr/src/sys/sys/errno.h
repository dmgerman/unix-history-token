begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)errno.h	7.10 (Berkeley) 6/28/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global error number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EPERM
value|1
end_define

begin_comment
comment|/* Operation not permitted */
end_comment

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_comment
comment|/* No such file or directory */
end_comment

begin_define
define|#
directive|define
name|ESRCH
value|3
end_define

begin_comment
comment|/* No such process */
end_comment

begin_define
define|#
directive|define
name|EINTR
value|4
end_define

begin_comment
comment|/* Interrupted system call */
end_comment

begin_define
define|#
directive|define
name|EIO
value|5
end_define

begin_comment
comment|/* Input/output error */
end_comment

begin_define
define|#
directive|define
name|ENXIO
value|6
end_define

begin_comment
comment|/* Device not configured */
end_comment

begin_define
define|#
directive|define
name|E2BIG
value|7
end_define

begin_comment
comment|/* Argument list too long */
end_comment

begin_define
define|#
directive|define
name|ENOEXEC
value|8
end_define

begin_comment
comment|/* Exec format error */
end_comment

begin_define
define|#
directive|define
name|EBADF
value|9
end_define

begin_comment
comment|/* Bad file descriptor */
end_comment

begin_define
define|#
directive|define
name|ECHILD
value|10
end_define

begin_comment
comment|/* No child processes */
end_comment

begin_define
define|#
directive|define
name|EDEADLK
value|11
end_define

begin_comment
comment|/* Resource deadlock avoided */
end_comment

begin_comment
comment|/* 11 was EAGAIN */
end_comment

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_comment
comment|/* Cannot allocate memory */
end_comment

begin_define
define|#
directive|define
name|EACCES
value|13
end_define

begin_comment
comment|/* Permission denied */
end_comment

begin_define
define|#
directive|define
name|EFAULT
value|14
end_define

begin_comment
comment|/* Bad address */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ENOTBLK
value|15
end_define

begin_comment
comment|/* Block device required */
end_comment

begin_define
define|#
directive|define
name|EBUSY
value|16
end_define

begin_comment
comment|/* Device busy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EEXIST
value|17
end_define

begin_comment
comment|/* File exists */
end_comment

begin_define
define|#
directive|define
name|EXDEV
value|18
end_define

begin_comment
comment|/* Cross-device link */
end_comment

begin_define
define|#
directive|define
name|ENODEV
value|19
end_define

begin_comment
comment|/* Operation not supported by device */
end_comment

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_comment
comment|/* Not a directory */
end_comment

begin_define
define|#
directive|define
name|EISDIR
value|21
end_define

begin_comment
comment|/* Is a directory */
end_comment

begin_define
define|#
directive|define
name|EINVAL
value|22
end_define

begin_comment
comment|/* Invalid argument */
end_comment

begin_define
define|#
directive|define
name|ENFILE
value|23
end_define

begin_comment
comment|/* Too many open files in system */
end_comment

begin_define
define|#
directive|define
name|EMFILE
value|24
end_define

begin_comment
comment|/* Too many open files */
end_comment

begin_define
define|#
directive|define
name|ENOTTY
value|25
end_define

begin_comment
comment|/* Inappropriate ioctl for device */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ETXTBSY
value|26
end_define

begin_comment
comment|/* Text file busy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EFBIG
value|27
end_define

begin_comment
comment|/* File too large */
end_comment

begin_define
define|#
directive|define
name|ENOSPC
value|28
end_define

begin_comment
comment|/* No space left on device */
end_comment

begin_define
define|#
directive|define
name|ESPIPE
value|29
end_define

begin_comment
comment|/* Illegal seek */
end_comment

begin_define
define|#
directive|define
name|EROFS
value|30
end_define

begin_comment
comment|/* Read-only file system */
end_comment

begin_define
define|#
directive|define
name|EMLINK
value|31
end_define

begin_comment
comment|/* Too many links */
end_comment

begin_define
define|#
directive|define
name|EPIPE
value|32
end_define

begin_comment
comment|/* Broken pipe */
end_comment

begin_comment
comment|/* math software */
end_comment

begin_define
define|#
directive|define
name|EDOM
value|33
end_define

begin_comment
comment|/* Numerical argument out of domain */
end_comment

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_comment
comment|/* Numerical result out of range */
end_comment

begin_comment
comment|/* non-blocking and interrupt i/o */
end_comment

begin_define
define|#
directive|define
name|EAGAIN
value|35
end_define

begin_comment
comment|/* Resource temporarily unavailable */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|EAGAIN
end_define

begin_comment
comment|/* Operation would block */
end_comment

begin_define
define|#
directive|define
name|EINPROGRESS
value|36
end_define

begin_comment
comment|/* Operation now in progress */
end_comment

begin_define
define|#
directive|define
name|EALREADY
value|37
end_define

begin_comment
comment|/* Operation already in progress */
end_comment

begin_comment
comment|/* ipc/network software -- argument errors */
end_comment

begin_define
define|#
directive|define
name|ENOTSOCK
value|38
end_define

begin_comment
comment|/* Socket operation on non-socket */
end_comment

begin_define
define|#
directive|define
name|EDESTADDRREQ
value|39
end_define

begin_comment
comment|/* Destination address required */
end_comment

begin_define
define|#
directive|define
name|EMSGSIZE
value|40
end_define

begin_comment
comment|/* Message too long */
end_comment

begin_define
define|#
directive|define
name|EPROTOTYPE
value|41
end_define

begin_comment
comment|/* Protocol wrong type for socket */
end_comment

begin_define
define|#
directive|define
name|ENOPROTOOPT
value|42
end_define

begin_comment
comment|/* Protocol not available */
end_comment

begin_define
define|#
directive|define
name|EPROTONOSUPPORT
value|43
end_define

begin_comment
comment|/* Protocol not supported */
end_comment

begin_define
define|#
directive|define
name|ESOCKTNOSUPPORT
value|44
end_define

begin_comment
comment|/* Socket type not supported */
end_comment

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|45
end_define

begin_comment
comment|/* Operation not supported on socket */
end_comment

begin_define
define|#
directive|define
name|EPFNOSUPPORT
value|46
end_define

begin_comment
comment|/* Protocol family not supported */
end_comment

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|47
end_define

begin_comment
comment|/* Address family not supported by protocol family */
end_comment

begin_define
define|#
directive|define
name|EADDRINUSE
value|48
end_define

begin_comment
comment|/* Address already in use */
end_comment

begin_define
define|#
directive|define
name|EADDRNOTAVAIL
value|49
end_define

begin_comment
comment|/* Can't assign requested address */
end_comment

begin_comment
comment|/* ipc/network software -- operational errors */
end_comment

begin_define
define|#
directive|define
name|ENETDOWN
value|50
end_define

begin_comment
comment|/* Network is down */
end_comment

begin_define
define|#
directive|define
name|ENETUNREACH
value|51
end_define

begin_comment
comment|/* Network is unreachable */
end_comment

begin_define
define|#
directive|define
name|ENETRESET
value|52
end_define

begin_comment
comment|/* Network dropped connection on reset */
end_comment

begin_define
define|#
directive|define
name|ECONNABORTED
value|53
end_define

begin_comment
comment|/* Software caused connection abort */
end_comment

begin_define
define|#
directive|define
name|ECONNRESET
value|54
end_define

begin_comment
comment|/* Connection reset by peer */
end_comment

begin_define
define|#
directive|define
name|ENOBUFS
value|55
end_define

begin_comment
comment|/* No buffer space available */
end_comment

begin_define
define|#
directive|define
name|EISCONN
value|56
end_define

begin_comment
comment|/* Socket is already connected */
end_comment

begin_define
define|#
directive|define
name|ENOTCONN
value|57
end_define

begin_comment
comment|/* Socket is not connected */
end_comment

begin_define
define|#
directive|define
name|ESHUTDOWN
value|58
end_define

begin_comment
comment|/* Can't send after socket shutdown */
end_comment

begin_define
define|#
directive|define
name|ETOOMANYREFS
value|59
end_define

begin_comment
comment|/* Too many references: can't splice */
end_comment

begin_define
define|#
directive|define
name|ETIMEDOUT
value|60
end_define

begin_comment
comment|/* Connection timed out */
end_comment

begin_define
define|#
directive|define
name|ECONNREFUSED
value|61
end_define

begin_comment
comment|/* Connection refused */
end_comment

begin_define
define|#
directive|define
name|ELOOP
value|62
end_define

begin_comment
comment|/* Too many levels of symbolic links */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|ENAMETOOLONG
value|63
end_define

begin_comment
comment|/* File name too long */
end_comment

begin_comment
comment|/* should be rearranged */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|EHOSTDOWN
value|64
end_define

begin_comment
comment|/* Host is down */
end_comment

begin_define
define|#
directive|define
name|EHOSTUNREACH
value|65
end_define

begin_comment
comment|/* No route to host */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|ENOTEMPTY
value|66
end_define

begin_comment
comment|/* Directory not empty */
end_comment

begin_comment
comment|/* quotas& mush */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|EPROCLIM
value|67
end_define

begin_comment
comment|/* Too many processes */
end_comment

begin_define
define|#
directive|define
name|EUSERS
value|68
end_define

begin_comment
comment|/* Too many users */
end_comment

begin_define
define|#
directive|define
name|EDQUOT
value|69
end_define

begin_comment
comment|/* Disc quota exceeded */
end_comment

begin_comment
comment|/* Network File System */
end_comment

begin_define
define|#
directive|define
name|ESTALE
value|70
end_define

begin_comment
comment|/* Stale NFS file handle */
end_comment

begin_define
define|#
directive|define
name|EREMOTE
value|71
end_define

begin_comment
comment|/* Too many levels of remote in path */
end_comment

begin_define
define|#
directive|define
name|EBADRPC
value|72
end_define

begin_comment
comment|/* RPC struct is bad */
end_comment

begin_define
define|#
directive|define
name|ERPCMISMATCH
value|73
end_define

begin_comment
comment|/* RPC version wrong */
end_comment

begin_define
define|#
directive|define
name|EPROGUNAVAIL
value|74
end_define

begin_comment
comment|/* RPC prog. not avail */
end_comment

begin_define
define|#
directive|define
name|EPROGMISMATCH
value|75
end_define

begin_comment
comment|/* Program version wrong */
end_comment

begin_define
define|#
directive|define
name|EPROCUNAVAIL
value|76
end_define

begin_comment
comment|/* Bad procedure for program */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|ENOLCK
value|77
end_define

begin_comment
comment|/* No locks available */
end_comment

begin_define
define|#
directive|define
name|ENOSYS
value|78
end_define

begin_comment
comment|/* Function not implemented */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* pseudo-errors returned inside kernel to modify return to process */
end_comment

begin_define
define|#
directive|define
name|ERESTART
value|-1
end_define

begin_comment
comment|/* restart syscall */
end_comment

begin_define
define|#
directive|define
name|EJUSTRETURN
value|-2
end_define

begin_comment
comment|/* don't modify regs, just return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

