begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)errno.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Error codes  */
end_comment

begin_define
define|#
directive|define
name|EPERM
value|1
end_define

begin_comment
comment|/* Not owner */
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
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|ENXIO
value|6
end_define

begin_comment
comment|/* No such device or address */
end_comment

begin_define
define|#
directive|define
name|E2BIG
value|7
end_define

begin_comment
comment|/* Arg list too long */
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
comment|/* Bad file number */
end_comment

begin_define
define|#
directive|define
name|ECHILD
value|10
end_define

begin_comment
comment|/* No children */
end_comment

begin_define
define|#
directive|define
name|EAGAIN
value|11
end_define

begin_comment
comment|/* No more processes */
end_comment

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_comment
comment|/* Not enough core */
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
comment|/* Mount device busy */
end_comment

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
comment|/* No such device */
end_comment

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_comment
comment|/* Not a directory*/
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
comment|/* File table overflow */
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
comment|/* Not a typewriter */
end_comment

begin_define
define|#
directive|define
name|ETXTBSY
value|26
end_define

begin_comment
comment|/* Text file busy */
end_comment

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
comment|/* Argument too large */
end_comment

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_comment
comment|/* Result too large */
end_comment

begin_comment
comment|/* non-blocking and interrupt i/o */
end_comment

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|35
end_define

begin_comment
comment|/* Operation would block */
end_comment

begin_define
define|#
directive|define
name|EDEADLK
value|EWOULDBLOCK
end_define

begin_comment
comment|/* ditto */
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
comment|/* ipc/network software */
end_comment

begin_comment
comment|/* argument errors */
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
comment|/* operational errors */
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

begin_comment
comment|/* */
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

end_unit

