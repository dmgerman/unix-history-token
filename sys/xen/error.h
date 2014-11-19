begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Roger Pau MonnÃ©<royger@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_ERROR_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_ERROR_H__
end_define

begin_comment
comment|/* List of Xen error codes */
end_comment

begin_define
define|#
directive|define
name|XEN_EPERM
value|1
end_define

begin_comment
comment|/* Operation not permitted */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOENT
value|2
end_define

begin_comment
comment|/* No such file or directory */
end_comment

begin_define
define|#
directive|define
name|XEN_ESRCH
value|3
end_define

begin_comment
comment|/* No such process */
end_comment

begin_define
define|#
directive|define
name|XEN_EINTR
value|4
end_define

begin_comment
comment|/* Interrupted system call */
end_comment

begin_define
define|#
directive|define
name|XEN_EIO
value|5
end_define

begin_comment
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|XEN_ENXIO
value|6
end_define

begin_comment
comment|/* No such device or address */
end_comment

begin_define
define|#
directive|define
name|XEN_E2BIG
value|7
end_define

begin_comment
comment|/* Arg list too long */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOEXEC
value|8
end_define

begin_comment
comment|/* Exec format error */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADF
value|9
end_define

begin_comment
comment|/* Bad file number */
end_comment

begin_define
define|#
directive|define
name|XEN_ECHILD
value|10
end_define

begin_comment
comment|/* No child processes */
end_comment

begin_define
define|#
directive|define
name|XEN_EAGAIN
value|11
end_define

begin_comment
comment|/* Try again */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOMEM
value|12
end_define

begin_comment
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|XEN_EACCES
value|13
end_define

begin_comment
comment|/* Permission denied */
end_comment

begin_define
define|#
directive|define
name|XEN_EFAULT
value|14
end_define

begin_comment
comment|/* Bad address */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTBLK
value|15
end_define

begin_comment
comment|/* Block device required */
end_comment

begin_define
define|#
directive|define
name|XEN_EBUSY
value|16
end_define

begin_comment
comment|/* Device or resource busy */
end_comment

begin_define
define|#
directive|define
name|XEN_EEXIST
value|17
end_define

begin_comment
comment|/* File exists */
end_comment

begin_define
define|#
directive|define
name|XEN_EXDEV
value|18
end_define

begin_comment
comment|/* Cross-device link */
end_comment

begin_define
define|#
directive|define
name|XEN_ENODEV
value|19
end_define

begin_comment
comment|/* No such device */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTDIR
value|20
end_define

begin_comment
comment|/* Not a directory */
end_comment

begin_define
define|#
directive|define
name|XEN_EISDIR
value|21
end_define

begin_comment
comment|/* Is a directory */
end_comment

begin_define
define|#
directive|define
name|XEN_EINVAL
value|22
end_define

begin_comment
comment|/* Invalid argument */
end_comment

begin_define
define|#
directive|define
name|XEN_ENFILE
value|23
end_define

begin_comment
comment|/* File table overflow */
end_comment

begin_define
define|#
directive|define
name|XEN_EMFILE
value|24
end_define

begin_comment
comment|/* Too many open files */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTTY
value|25
end_define

begin_comment
comment|/* Not a typewriter */
end_comment

begin_define
define|#
directive|define
name|XEN_ETXTBSY
value|26
end_define

begin_comment
comment|/* Text file busy */
end_comment

begin_define
define|#
directive|define
name|XEN_EFBIG
value|27
end_define

begin_comment
comment|/* File too large */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOSPC
value|28
end_define

begin_comment
comment|/* No space left on device */
end_comment

begin_define
define|#
directive|define
name|XEN_ESPIPE
value|29
end_define

begin_comment
comment|/* Illegal seek */
end_comment

begin_define
define|#
directive|define
name|XEN_EROFS
value|30
end_define

begin_comment
comment|/* Read-only file system */
end_comment

begin_define
define|#
directive|define
name|XEN_EMLINK
value|31
end_define

begin_comment
comment|/* Too many links */
end_comment

begin_define
define|#
directive|define
name|XEN_EPIPE
value|32
end_define

begin_comment
comment|/* Broken pipe */
end_comment

begin_define
define|#
directive|define
name|XEN_EDOM
value|33
end_define

begin_comment
comment|/* Math argument out of domain of func */
end_comment

begin_define
define|#
directive|define
name|XEN_ERANGE
value|34
end_define

begin_comment
comment|/* Math result not representable */
end_comment

begin_define
define|#
directive|define
name|XEN_EDEADLK
value|35
end_define

begin_comment
comment|/* Resource deadlock would occur */
end_comment

begin_define
define|#
directive|define
name|XEN_ENAMETOOLONG
value|36
end_define

begin_comment
comment|/* File name too long */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOLCK
value|37
end_define

begin_comment
comment|/* No record locks available */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOSYS
value|38
end_define

begin_comment
comment|/* Function not implemented */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTEMPTY
value|39
end_define

begin_comment
comment|/* Directory not empty */
end_comment

begin_define
define|#
directive|define
name|XEN_ELOOP
value|40
end_define

begin_comment
comment|/* Too many symbolic links encountered */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOMSG
value|42
end_define

begin_comment
comment|/* No message of desired type */
end_comment

begin_define
define|#
directive|define
name|XEN_EIDRM
value|43
end_define

begin_comment
comment|/* Identifier removed */
end_comment

begin_define
define|#
directive|define
name|XEN_ECHRNG
value|44
end_define

begin_comment
comment|/* Channel number out of range */
end_comment

begin_define
define|#
directive|define
name|XEN_EL2NSYNC
value|45
end_define

begin_comment
comment|/* Level 2 not synchronized */
end_comment

begin_define
define|#
directive|define
name|XEN_EL3HLT
value|46
end_define

begin_comment
comment|/* Level 3 halted */
end_comment

begin_define
define|#
directive|define
name|XEN_EL3RST
value|47
end_define

begin_comment
comment|/* Level 3 reset */
end_comment

begin_define
define|#
directive|define
name|XEN_ELNRNG
value|48
end_define

begin_comment
comment|/* Link number out of range */
end_comment

begin_define
define|#
directive|define
name|XEN_EUNATCH
value|49
end_define

begin_comment
comment|/* Protocol driver not attached */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOCSI
value|50
end_define

begin_comment
comment|/* No CSI structure available */
end_comment

begin_define
define|#
directive|define
name|XEN_EL2HLT
value|51
end_define

begin_comment
comment|/* Level 2 halted */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADE
value|52
end_define

begin_comment
comment|/* Invalid exchange */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADR
value|53
end_define

begin_comment
comment|/* Invalid request descriptor */
end_comment

begin_define
define|#
directive|define
name|XEN_EXFULL
value|54
end_define

begin_comment
comment|/* Exchange full */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOANO
value|55
end_define

begin_comment
comment|/* No anode */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADRQC
value|56
end_define

begin_comment
comment|/* Invalid request code */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADSLT
value|57
end_define

begin_comment
comment|/* Invalid slot */
end_comment

begin_define
define|#
directive|define
name|XEN_EBFONT
value|59
end_define

begin_comment
comment|/* Bad font file format */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOSTR
value|60
end_define

begin_comment
comment|/* Device not a stream */
end_comment

begin_define
define|#
directive|define
name|XEN_ENODATA
value|61
end_define

begin_comment
comment|/* No data available */
end_comment

begin_define
define|#
directive|define
name|XEN_ETIME
value|62
end_define

begin_comment
comment|/* Timer expired */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOSR
value|63
end_define

begin_comment
comment|/* Out of streams resources */
end_comment

begin_define
define|#
directive|define
name|XEN_ENONET
value|64
end_define

begin_comment
comment|/* Machine is not on the network */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOPKG
value|65
end_define

begin_comment
comment|/* Package not installed */
end_comment

begin_define
define|#
directive|define
name|XEN_EREMOTE
value|66
end_define

begin_comment
comment|/* Object is remote */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOLINK
value|67
end_define

begin_comment
comment|/* Link has been severed */
end_comment

begin_define
define|#
directive|define
name|XEN_EADV
value|68
end_define

begin_comment
comment|/* Advertise error */
end_comment

begin_define
define|#
directive|define
name|XEN_ESRMNT
value|69
end_define

begin_comment
comment|/* Srmount error */
end_comment

begin_define
define|#
directive|define
name|XEN_ECOMM
value|70
end_define

begin_comment
comment|/* Communication error on send */
end_comment

begin_define
define|#
directive|define
name|XEN_EPROTO
value|71
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_define
define|#
directive|define
name|XEN_EMULTIHOP
value|72
end_define

begin_comment
comment|/* Multihop attempted */
end_comment

begin_define
define|#
directive|define
name|XEN_EDOTDOT
value|73
end_define

begin_comment
comment|/* RFS specific error */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADMSG
value|74
end_define

begin_comment
comment|/* Not a data message */
end_comment

begin_define
define|#
directive|define
name|XEN_EOVERFLOW
value|75
end_define

begin_comment
comment|/* Value too large for defined data type */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTUNIQ
value|76
end_define

begin_comment
comment|/* Name not unique on network */
end_comment

begin_define
define|#
directive|define
name|XEN_EBADFD
value|77
end_define

begin_comment
comment|/* File descriptor in bad state */
end_comment

begin_define
define|#
directive|define
name|XEN_EREMCHG
value|78
end_define

begin_comment
comment|/* Remote address changed */
end_comment

begin_define
define|#
directive|define
name|XEN_ELIBACC
value|79
end_define

begin_comment
comment|/* Can not access a needed shared library */
end_comment

begin_define
define|#
directive|define
name|XEN_ELIBBAD
value|80
end_define

begin_comment
comment|/* Accessing a corrupted shared library */
end_comment

begin_define
define|#
directive|define
name|XEN_ELIBSCN
value|81
end_define

begin_comment
comment|/* .lib section in a.out corrupted */
end_comment

begin_define
define|#
directive|define
name|XEN_ELIBMAX
value|82
end_define

begin_comment
comment|/* Attempting to link in too many shared libraries */
end_comment

begin_define
define|#
directive|define
name|XEN_ELIBEXEC
value|83
end_define

begin_comment
comment|/* Cannot exec a shared library directly */
end_comment

begin_define
define|#
directive|define
name|XEN_EILSEQ
value|84
end_define

begin_comment
comment|/* Illegal byte sequence */
end_comment

begin_define
define|#
directive|define
name|XEN_ERESTART
value|85
end_define

begin_comment
comment|/* Interrupted system call should be restarted */
end_comment

begin_define
define|#
directive|define
name|XEN_ESTRPIPE
value|86
end_define

begin_comment
comment|/* Streams pipe error */
end_comment

begin_define
define|#
directive|define
name|XEN_EUSERS
value|87
end_define

begin_comment
comment|/* Too many users */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTSOCK
value|88
end_define

begin_comment
comment|/* Socket operation on non-socket */
end_comment

begin_define
define|#
directive|define
name|XEN_EDESTADDRREQ
value|89
end_define

begin_comment
comment|/* Destination address required */
end_comment

begin_define
define|#
directive|define
name|XEN_EMSGSIZE
value|90
end_define

begin_comment
comment|/* Message too long */
end_comment

begin_define
define|#
directive|define
name|XEN_EPROTOTYPE
value|91
end_define

begin_comment
comment|/* Protocol wrong type for socket */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOPROTOOPT
value|92
end_define

begin_comment
comment|/* Protocol not available */
end_comment

begin_define
define|#
directive|define
name|XEN_EPROTONOSUPPORT
value|93
end_define

begin_comment
comment|/* Protocol not supported */
end_comment

begin_define
define|#
directive|define
name|XEN_ESOCKTNOSUPPORT
value|94
end_define

begin_comment
comment|/* Socket type not supported */
end_comment

begin_define
define|#
directive|define
name|XEN_EOPNOTSUPP
value|95
end_define

begin_comment
comment|/* Operation not supported on transport endpoint */
end_comment

begin_define
define|#
directive|define
name|XEN_EPFNOSUPPORT
value|96
end_define

begin_comment
comment|/* Protocol family not supported */
end_comment

begin_define
define|#
directive|define
name|XEN_EAFNOSUPPORT
value|97
end_define

begin_comment
comment|/* Address family not supported by protocol */
end_comment

begin_define
define|#
directive|define
name|XEN_EADDRINUSE
value|98
end_define

begin_comment
comment|/* Address already in use */
end_comment

begin_define
define|#
directive|define
name|XEN_EADDRNOTAVAIL
value|99
end_define

begin_comment
comment|/* Cannot assign requested address */
end_comment

begin_define
define|#
directive|define
name|XEN_ENETDOWN
value|100
end_define

begin_comment
comment|/* Network is down */
end_comment

begin_define
define|#
directive|define
name|XEN_ENETUNREACH
value|101
end_define

begin_comment
comment|/* Network is unreachable */
end_comment

begin_define
define|#
directive|define
name|XEN_ENETRESET
value|102
end_define

begin_comment
comment|/* Network dropped connection because of reset */
end_comment

begin_define
define|#
directive|define
name|XEN_ECONNABORTED
value|103
end_define

begin_comment
comment|/* Software caused connection abort */
end_comment

begin_define
define|#
directive|define
name|XEN_ECONNRESET
value|104
end_define

begin_comment
comment|/* Connection reset by peer */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOBUFS
value|105
end_define

begin_comment
comment|/* No buffer space available */
end_comment

begin_define
define|#
directive|define
name|XEN_EISCONN
value|106
end_define

begin_comment
comment|/* Transport endpoint is already connected */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTCONN
value|107
end_define

begin_comment
comment|/* Transport endpoint is not connected */
end_comment

begin_define
define|#
directive|define
name|XEN_ESHUTDOWN
value|108
end_define

begin_comment
comment|/* Cannot send after transport endpoint shutdown */
end_comment

begin_define
define|#
directive|define
name|XEN_ETOOMANYREFS
value|109
end_define

begin_comment
comment|/* Too many references: cannot splice */
end_comment

begin_define
define|#
directive|define
name|XEN_ETIMEDOUT
value|110
end_define

begin_comment
comment|/* Connection timed out */
end_comment

begin_define
define|#
directive|define
name|XEN_ECONNREFUSED
value|111
end_define

begin_comment
comment|/* Connection refused */
end_comment

begin_define
define|#
directive|define
name|XEN_EHOSTDOWN
value|112
end_define

begin_comment
comment|/* Host is down */
end_comment

begin_define
define|#
directive|define
name|XEN_EHOSTUNREACH
value|113
end_define

begin_comment
comment|/* No route to host */
end_comment

begin_define
define|#
directive|define
name|XEN_EALREADY
value|114
end_define

begin_comment
comment|/* Operation already in progress */
end_comment

begin_define
define|#
directive|define
name|XEN_EINPROGRESS
value|115
end_define

begin_comment
comment|/* Operation now in progress */
end_comment

begin_define
define|#
directive|define
name|XEN_ESTALE
value|116
end_define

begin_comment
comment|/* Stale NFS file handle */
end_comment

begin_define
define|#
directive|define
name|XEN_EUCLEAN
value|117
end_define

begin_comment
comment|/* Structure needs cleaning */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOTNAM
value|118
end_define

begin_comment
comment|/* Not a XENIX named type file */
end_comment

begin_define
define|#
directive|define
name|XEN_ENAVAIL
value|119
end_define

begin_comment
comment|/* No XENIX semaphores available */
end_comment

begin_define
define|#
directive|define
name|XEN_EISNAM
value|120
end_define

begin_comment
comment|/* Is a named type file */
end_comment

begin_define
define|#
directive|define
name|XEN_EREMOTEIO
value|121
end_define

begin_comment
comment|/* Remote I/O error */
end_comment

begin_define
define|#
directive|define
name|XEN_EDQUOT
value|122
end_define

begin_comment
comment|/* Quota exceeded */
end_comment

begin_define
define|#
directive|define
name|XEN_ENOMEDIUM
value|123
end_define

begin_comment
comment|/* No medium found */
end_comment

begin_define
define|#
directive|define
name|XEN_EMEDIUMTYPE
value|124
end_define

begin_comment
comment|/* Wrong medium type */
end_comment

begin_comment
comment|/* Translation table */
end_comment

begin_decl_stmt
specifier|static
name|int
name|xen_errors
index|[]
init|=
block|{
index|[
name|XEN_EPERM
index|]
operator|=
name|EPERM
block|,
index|[
name|XEN_ENOENT
index|]
operator|=
name|ENOENT
block|,
index|[
name|XEN_ESRCH
index|]
operator|=
name|ESRCH
block|,
index|[
name|XEN_EINTR
index|]
operator|=
name|EINTR
block|,
index|[
name|XEN_EIO
index|]
operator|=
name|EIO
block|,
index|[
name|XEN_ENXIO
index|]
operator|=
name|ENXIO
block|,
index|[
name|XEN_E2BIG
index|]
operator|=
name|E2BIG
block|,
index|[
name|XEN_ENOEXEC
index|]
operator|=
name|ENOEXEC
block|,
index|[
name|XEN_EBADF
index|]
operator|=
name|EBADF
block|,
index|[
name|XEN_ECHILD
index|]
operator|=
name|ECHILD
block|,
index|[
name|XEN_EAGAIN
index|]
operator|=
name|EAGAIN
block|,
index|[
name|XEN_ENOMEM
index|]
operator|=
name|ENOMEM
block|,
index|[
name|XEN_EACCES
index|]
operator|=
name|EACCES
block|,
index|[
name|XEN_EFAULT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ENOTBLK
index|]
operator|=
name|ENOTBLK
block|,
index|[
name|XEN_EBUSY
index|]
operator|=
name|EBUSY
block|,
index|[
name|XEN_EEXIST
index|]
operator|=
name|EEXIST
block|,
index|[
name|XEN_EXDEV
index|]
operator|=
name|EXDEV
block|,
index|[
name|XEN_ENODEV
index|]
operator|=
name|ENODEV
block|,
index|[
name|XEN_ENOTDIR
index|]
operator|=
name|ENOTDIR
block|,
index|[
name|XEN_EISDIR
index|]
operator|=
name|EISDIR
block|,
index|[
name|XEN_EINVAL
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_ENFILE
index|]
operator|=
name|ENFILE
block|,
index|[
name|XEN_EMFILE
index|]
operator|=
name|EMFILE
block|,
index|[
name|XEN_ENOTTY
index|]
operator|=
name|ENOTTY
block|,
index|[
name|XEN_ETXTBSY
index|]
operator|=
name|ETXTBSY
block|,
index|[
name|XEN_EFBIG
index|]
operator|=
name|EFBIG
block|,
index|[
name|XEN_ENOSPC
index|]
operator|=
name|ENOSPC
block|,
index|[
name|XEN_ESPIPE
index|]
operator|=
name|ESPIPE
block|,
index|[
name|XEN_EROFS
index|]
operator|=
name|EROFS
block|,
index|[
name|XEN_EMLINK
index|]
operator|=
name|EMLINK
block|,
index|[
name|XEN_EPIPE
index|]
operator|=
name|EPIPE
block|,
index|[
name|XEN_EDOM
index|]
operator|=
name|EDOM
block|,
index|[
name|XEN_ERANGE
index|]
operator|=
name|ERANGE
block|,
index|[
name|XEN_EDEADLK
index|]
operator|=
name|EDEADLK
block|,
index|[
name|XEN_ENAMETOOLONG
index|]
operator|=
name|ENAMETOOLONG
block|,
index|[
name|XEN_ENOLCK
index|]
operator|=
name|ENOLCK
block|,
index|[
name|XEN_ENOSYS
index|]
operator|=
name|ENOSYS
block|,
index|[
name|XEN_ENOTEMPTY
index|]
operator|=
name|ENOTEMPTY
block|,
index|[
name|XEN_ELOOP
index|]
operator|=
name|ELOOP
block|,
index|[
name|XEN_ENOMSG
index|]
operator|=
name|ENOMSG
block|,
index|[
name|XEN_EIDRM
index|]
operator|=
name|EIDRM
block|,
index|[
name|XEN_ECHRNG
index|]
operator|=
name|ERANGE
block|,
index|[
name|XEN_EL2NSYNC
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EL3HLT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EL3RST
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ELNRNG
index|]
operator|=
name|ERANGE
block|,
index|[
name|XEN_EUNATCH
index|]
operator|=
name|ENODEV
block|,
index|[
name|XEN_ENOCSI
index|]
operator|=
name|ENODEV
block|,
index|[
name|XEN_EL2HLT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EBADE
index|]
operator|=
name|ERANGE
block|,
index|[
name|XEN_EBADR
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_EXFULL
index|]
operator|=
name|ENOBUFS
block|,
index|[
name|XEN_ENOANO
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_EBADRQC
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_EBADSLT
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_EBFONT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ENOSTR
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_ENODATA
index|]
operator|=
name|ENOENT
block|,
index|[
name|XEN_ETIME
index|]
operator|=
name|ETIMEDOUT
block|,
index|[
name|XEN_ENOSR
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ENONET
index|]
operator|=
name|ENETDOWN
block|,
index|[
name|XEN_ENOPKG
index|]
operator|=
name|EINVAL
block|,
index|[
name|XEN_EREMOTE
index|]
operator|=
name|EREMOTE
block|,
index|[
name|XEN_ENOLINK
index|]
operator|=
name|ENOLINK
block|,
index|[
name|XEN_EADV
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ESRMNT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ECOMM
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EPROTO
index|]
operator|=
name|EPROTO
block|,
index|[
name|XEN_EMULTIHOP
index|]
operator|=
name|EMULTIHOP
block|,
index|[
name|XEN_EDOTDOT
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EBADMSG
index|]
operator|=
name|EBADMSG
block|,
index|[
name|XEN_EOVERFLOW
index|]
operator|=
name|EOVERFLOW
block|,
index|[
name|XEN_ENOTUNIQ
index|]
operator|=
name|EADDRINUSE
block|,
index|[
name|XEN_EBADFD
index|]
operator|=
name|EBADF
block|,
index|[
name|XEN_EREMCHG
index|]
operator|=
name|EHOSTDOWN
block|,
index|[
name|XEN_ELIBACC
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ELIBBAD
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ELIBSCN
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ELIBMAX
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ELIBEXEC
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EILSEQ
index|]
operator|=
name|EILSEQ
block|,
index|[
name|XEN_ERESTART
index|]
operator|=
name|EAGAIN
block|,
index|[
name|XEN_ESTRPIPE
index|]
operator|=
name|EPIPE
block|,
index|[
name|XEN_EUSERS
index|]
operator|=
name|EUSERS
block|,
index|[
name|XEN_ENOTSOCK
index|]
operator|=
name|ENOTSOCK
block|,
index|[
name|XEN_EDESTADDRREQ
index|]
operator|=
name|EDESTADDRREQ
block|,
index|[
name|XEN_EMSGSIZE
index|]
operator|=
name|EMSGSIZE
block|,
index|[
name|XEN_EPROTOTYPE
index|]
operator|=
name|EPROTOTYPE
block|,
index|[
name|XEN_ENOPROTOOPT
index|]
operator|=
name|ENOPROTOOPT
block|,
index|[
name|XEN_EPROTONOSUPPORT
index|]
operator|=
name|EPROTONOSUPPORT
block|,
index|[
name|XEN_ESOCKTNOSUPPORT
index|]
operator|=
name|ESOCKTNOSUPPORT
block|,
index|[
name|XEN_EOPNOTSUPP
index|]
operator|=
name|EOPNOTSUPP
block|,
index|[
name|XEN_EPFNOSUPPORT
index|]
operator|=
name|EPFNOSUPPORT
block|,
index|[
name|XEN_EAFNOSUPPORT
index|]
operator|=
name|EAFNOSUPPORT
block|,
index|[
name|XEN_EADDRINUSE
index|]
operator|=
name|EADDRINUSE
block|,
index|[
name|XEN_EADDRNOTAVAIL
index|]
operator|=
name|EADDRNOTAVAIL
block|,
index|[
name|XEN_ENETDOWN
index|]
operator|=
name|ENETDOWN
block|,
index|[
name|XEN_ENETUNREACH
index|]
operator|=
name|ENETUNREACH
block|,
index|[
name|XEN_ENETRESET
index|]
operator|=
name|ENETRESET
block|,
index|[
name|XEN_ECONNABORTED
index|]
operator|=
name|ECONNABORTED
block|,
index|[
name|XEN_ECONNRESET
index|]
operator|=
name|ECONNRESET
block|,
index|[
name|XEN_ENOBUFS
index|]
operator|=
name|ENOBUFS
block|,
index|[
name|XEN_EISCONN
index|]
operator|=
name|EISCONN
block|,
index|[
name|XEN_ENOTCONN
index|]
operator|=
name|ENOTCONN
block|,
index|[
name|XEN_ESHUTDOWN
index|]
operator|=
name|ESHUTDOWN
block|,
index|[
name|XEN_ETOOMANYREFS
index|]
operator|=
name|ETOOMANYREFS
block|,
index|[
name|XEN_ETIMEDOUT
index|]
operator|=
name|ETIMEDOUT
block|,
index|[
name|XEN_ECONNREFUSED
index|]
operator|=
name|ECONNREFUSED
block|,
index|[
name|XEN_EHOSTDOWN
index|]
operator|=
name|EHOSTDOWN
block|,
index|[
name|XEN_EHOSTUNREACH
index|]
operator|=
name|EHOSTUNREACH
block|,
index|[
name|XEN_EALREADY
index|]
operator|=
name|EALREADY
block|,
index|[
name|XEN_EINPROGRESS
index|]
operator|=
name|EINPROGRESS
block|,
index|[
name|XEN_ESTALE
index|]
operator|=
name|ESTALE
block|,
index|[
name|XEN_EUCLEAN
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ENOTNAM
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_ENAVAIL
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EISNAM
index|]
operator|=
name|EFAULT
block|,
index|[
name|XEN_EREMOTEIO
index|]
operator|=
name|EIO
block|,
index|[
name|XEN_EDQUOT
index|]
operator|=
name|EDQUOT
block|,
index|[
name|XEN_ENOMEDIUM
index|]
operator|=
name|ENOENT
block|,
index|[
name|XEN_EMEDIUMTYPE
index|]
operator|=
name|ENOENT
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|xen_translate_error
parameter_list|(
name|int
name|error
parameter_list|)
block|{
name|int
name|bsd_error
decl_stmt|;
name|KASSERT
argument_list|(
operator|(
name|error
operator|<
literal|0
operator|)
argument_list|,
operator|(
literal|"Value is not a valid Xen error code"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
name|error
operator|>=
name|nitems
argument_list|(
name|xen_errors
argument_list|)
condition|)
block|{
comment|/* 		 * We received an error value that cannot be translated, 		 * return EINVAL. 		 */
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|bsd_error
operator|=
name|xen_errors
index|[
operator|-
name|error
index|]
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
name|bsd_error
operator|!=
literal|0
operator|)
argument_list|,
operator|(
literal|"Unknown Xen error code"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|bsd_error
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__XEN_ERROR_H__ */
end_comment

end_unit

