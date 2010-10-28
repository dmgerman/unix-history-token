begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|_I386_ERRNO_H
end_define

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
comment|/* No child processes */
end_comment

begin_define
define|#
directive|define
name|EAGAIN
value|11
end_define

begin_comment
comment|/* Try again */
end_comment

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_comment
comment|/* Out of memory */
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
comment|/* Device or resource busy */
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

begin_define
define|#
directive|define
name|EDOM
value|33
end_define

begin_comment
comment|/* Math argument out of domain of func */
end_comment

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_comment
comment|/* Math result not representable */
end_comment

begin_define
define|#
directive|define
name|EDEADLK
value|35
end_define

begin_comment
comment|/* Resource deadlock would occur */
end_comment

begin_define
define|#
directive|define
name|ENAMETOOLONG
value|36
end_define

begin_comment
comment|/* File name too long */
end_comment

begin_define
define|#
directive|define
name|ENOLCK
value|37
end_define

begin_comment
comment|/* No record locks available */
end_comment

begin_define
define|#
directive|define
name|ENOSYS
value|38
end_define

begin_comment
comment|/* Function not implemented */
end_comment

begin_define
define|#
directive|define
name|ENOTEMPTY
value|39
end_define

begin_comment
comment|/* Directory not empty */
end_comment

begin_define
define|#
directive|define
name|ELOOP
value|40
end_define

begin_comment
comment|/* Too many symbolic links encountered */
end_comment

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
name|ENOMSG
value|42
end_define

begin_comment
comment|/* No message of desired type */
end_comment

begin_define
define|#
directive|define
name|EIDRM
value|43
end_define

begin_comment
comment|/* Identifier removed */
end_comment

begin_define
define|#
directive|define
name|ECHRNG
value|44
end_define

begin_comment
comment|/* Channel number out of range */
end_comment

begin_define
define|#
directive|define
name|EL2NSYNC
value|45
end_define

begin_comment
comment|/* Level 2 not synchronized */
end_comment

begin_define
define|#
directive|define
name|EL3HLT
value|46
end_define

begin_comment
comment|/* Level 3 halted */
end_comment

begin_define
define|#
directive|define
name|EL3RST
value|47
end_define

begin_comment
comment|/* Level 3 reset */
end_comment

begin_define
define|#
directive|define
name|ELNRNG
value|48
end_define

begin_comment
comment|/* Link number out of range */
end_comment

begin_define
define|#
directive|define
name|EUNATCH
value|49
end_define

begin_comment
comment|/* Protocol driver not attached */
end_comment

begin_define
define|#
directive|define
name|ENOCSI
value|50
end_define

begin_comment
comment|/* No CSI structure available */
end_comment

begin_define
define|#
directive|define
name|EL2HLT
value|51
end_define

begin_comment
comment|/* Level 2 halted */
end_comment

begin_define
define|#
directive|define
name|EBADE
value|52
end_define

begin_comment
comment|/* Invalid exchange */
end_comment

begin_define
define|#
directive|define
name|EBADR
value|53
end_define

begin_comment
comment|/* Invalid request descriptor */
end_comment

begin_define
define|#
directive|define
name|EXFULL
value|54
end_define

begin_comment
comment|/* Exchange full */
end_comment

begin_define
define|#
directive|define
name|ENOANO
value|55
end_define

begin_comment
comment|/* No anode */
end_comment

begin_define
define|#
directive|define
name|EBADRQC
value|56
end_define

begin_comment
comment|/* Invalid request code */
end_comment

begin_define
define|#
directive|define
name|EBADSLT
value|57
end_define

begin_comment
comment|/* Invalid slot */
end_comment

begin_define
define|#
directive|define
name|EDEADLOCK
value|EDEADLK
end_define

begin_define
define|#
directive|define
name|EBFONT
value|59
end_define

begin_comment
comment|/* Bad font file format */
end_comment

begin_define
define|#
directive|define
name|ENOSTR
value|60
end_define

begin_comment
comment|/* Device not a stream */
end_comment

begin_define
define|#
directive|define
name|ENODATA
value|61
end_define

begin_comment
comment|/* No data available */
end_comment

begin_define
define|#
directive|define
name|ETIME
value|62
end_define

begin_comment
comment|/* Timer expired */
end_comment

begin_define
define|#
directive|define
name|ENOSR
value|63
end_define

begin_comment
comment|/* Out of streams resources */
end_comment

begin_define
define|#
directive|define
name|ENONET
value|64
end_define

begin_comment
comment|/* Machine is not on the network */
end_comment

begin_define
define|#
directive|define
name|ENOPKG
value|65
end_define

begin_comment
comment|/* Package not installed */
end_comment

begin_define
define|#
directive|define
name|EREMOTE
value|66
end_define

begin_comment
comment|/* Object is remote */
end_comment

begin_define
define|#
directive|define
name|ENOLINK
value|67
end_define

begin_comment
comment|/* Link has been severed */
end_comment

begin_define
define|#
directive|define
name|EADV
value|68
end_define

begin_comment
comment|/* Advertise error */
end_comment

begin_define
define|#
directive|define
name|ESRMNT
value|69
end_define

begin_comment
comment|/* Srmount error */
end_comment

begin_define
define|#
directive|define
name|ECOMM
value|70
end_define

begin_comment
comment|/* Communication error on send */
end_comment

begin_define
define|#
directive|define
name|EPROTO
value|71
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_define
define|#
directive|define
name|EMULTIHOP
value|72
end_define

begin_comment
comment|/* Multihop attempted */
end_comment

begin_define
define|#
directive|define
name|EDOTDOT
value|73
end_define

begin_comment
comment|/* RFS specific error */
end_comment

begin_define
define|#
directive|define
name|EBADMSG
value|74
end_define

begin_comment
comment|/* Not a data message */
end_comment

begin_define
define|#
directive|define
name|EOVERFLOW
value|75
end_define

begin_comment
comment|/* Value too large for defined data type */
end_comment

begin_define
define|#
directive|define
name|ENOTUNIQ
value|76
end_define

begin_comment
comment|/* Name not unique on network */
end_comment

begin_define
define|#
directive|define
name|EBADFD
value|77
end_define

begin_comment
comment|/* File descriptor in bad state */
end_comment

begin_define
define|#
directive|define
name|EREMCHG
value|78
end_define

begin_comment
comment|/* Remote address changed */
end_comment

begin_define
define|#
directive|define
name|ELIBACC
value|79
end_define

begin_comment
comment|/* Can not access a needed shared library */
end_comment

begin_define
define|#
directive|define
name|ELIBBAD
value|80
end_define

begin_comment
comment|/* Accessing a corrupted shared library */
end_comment

begin_define
define|#
directive|define
name|ELIBSCN
value|81
end_define

begin_comment
comment|/* .lib section in a.out corrupted */
end_comment

begin_define
define|#
directive|define
name|ELIBMAX
value|82
end_define

begin_comment
comment|/* Attempting to link in too many shared libraries */
end_comment

begin_define
define|#
directive|define
name|ELIBEXEC
value|83
end_define

begin_comment
comment|/* Cannot exec a shared library directly */
end_comment

begin_define
define|#
directive|define
name|EILSEQ
value|84
end_define

begin_comment
comment|/* Illegal byte sequence */
end_comment

begin_define
define|#
directive|define
name|ERESTART
value|85
end_define

begin_comment
comment|/* Interrupted system call should be restarted */
end_comment

begin_define
define|#
directive|define
name|ESTRPIPE
value|86
end_define

begin_comment
comment|/* Streams pipe error */
end_comment

begin_define
define|#
directive|define
name|EUSERS
value|87
end_define

begin_comment
comment|/* Too many users */
end_comment

begin_define
define|#
directive|define
name|ENOTSOCK
value|88
end_define

begin_comment
comment|/* Socket operation on non-socket */
end_comment

begin_define
define|#
directive|define
name|EDESTADDRREQ
value|89
end_define

begin_comment
comment|/* Destination address required */
end_comment

begin_define
define|#
directive|define
name|EMSGSIZE
value|90
end_define

begin_comment
comment|/* Message too long */
end_comment

begin_define
define|#
directive|define
name|EPROTOTYPE
value|91
end_define

begin_comment
comment|/* Protocol wrong type for socket */
end_comment

begin_define
define|#
directive|define
name|ENOPROTOOPT
value|92
end_define

begin_comment
comment|/* Protocol not available */
end_comment

begin_define
define|#
directive|define
name|EPROTONOSUPPORT
value|93
end_define

begin_comment
comment|/* Protocol not supported */
end_comment

begin_define
define|#
directive|define
name|ESOCKTNOSUPPORT
value|94
end_define

begin_comment
comment|/* Socket type not supported */
end_comment

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|95
end_define

begin_comment
comment|/* Operation not supported on transport endpoint */
end_comment

begin_define
define|#
directive|define
name|EPFNOSUPPORT
value|96
end_define

begin_comment
comment|/* Protocol family not supported */
end_comment

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|97
end_define

begin_comment
comment|/* Address family not supported by protocol */
end_comment

begin_define
define|#
directive|define
name|EADDRINUSE
value|98
end_define

begin_comment
comment|/* Address already in use */
end_comment

begin_define
define|#
directive|define
name|EADDRNOTAVAIL
value|99
end_define

begin_comment
comment|/* Cannot assign requested address */
end_comment

begin_define
define|#
directive|define
name|ENETDOWN
value|100
end_define

begin_comment
comment|/* Network is down */
end_comment

begin_define
define|#
directive|define
name|ENETUNREACH
value|101
end_define

begin_comment
comment|/* Network is unreachable */
end_comment

begin_define
define|#
directive|define
name|ENETRESET
value|102
end_define

begin_comment
comment|/* Network dropped connection because of reset */
end_comment

begin_define
define|#
directive|define
name|ECONNABORTED
value|103
end_define

begin_comment
comment|/* Software caused connection abort */
end_comment

begin_define
define|#
directive|define
name|ECONNRESET
value|104
end_define

begin_comment
comment|/* Connection reset by peer */
end_comment

begin_define
define|#
directive|define
name|ENOBUFS
value|105
end_define

begin_comment
comment|/* No buffer space available */
end_comment

begin_define
define|#
directive|define
name|EISCONN
value|106
end_define

begin_comment
comment|/* Transport endpoint is already connected */
end_comment

begin_define
define|#
directive|define
name|ENOTCONN
value|107
end_define

begin_comment
comment|/* Transport endpoint is not connected */
end_comment

begin_define
define|#
directive|define
name|ESHUTDOWN
value|108
end_define

begin_comment
comment|/* Cannot send after transport endpoint shutdown */
end_comment

begin_define
define|#
directive|define
name|ETOOMANYREFS
value|109
end_define

begin_comment
comment|/* Too many references: cannot splice */
end_comment

begin_define
define|#
directive|define
name|ETIMEDOUT
value|110
end_define

begin_comment
comment|/* Connection timed out */
end_comment

begin_define
define|#
directive|define
name|ECONNREFUSED
value|111
end_define

begin_comment
comment|/* Connection refused */
end_comment

begin_define
define|#
directive|define
name|EHOSTDOWN
value|112
end_define

begin_comment
comment|/* Host is down */
end_comment

begin_define
define|#
directive|define
name|EHOSTUNREACH
value|113
end_define

begin_comment
comment|/* No route to host */
end_comment

begin_define
define|#
directive|define
name|EALREADY
value|114
end_define

begin_comment
comment|/* Operation already in progress */
end_comment

begin_define
define|#
directive|define
name|EINPROGRESS
value|115
end_define

begin_comment
comment|/* Operation now in progress */
end_comment

begin_define
define|#
directive|define
name|ESTALE
value|116
end_define

begin_comment
comment|/* Stale NFS file handle */
end_comment

begin_define
define|#
directive|define
name|EUCLEAN
value|117
end_define

begin_comment
comment|/* Structure needs cleaning */
end_comment

begin_define
define|#
directive|define
name|ENOTNAM
value|118
end_define

begin_comment
comment|/* Not a XENIX named type file */
end_comment

begin_define
define|#
directive|define
name|ENAVAIL
value|119
end_define

begin_comment
comment|/* No XENIX semaphores available */
end_comment

begin_define
define|#
directive|define
name|EISNAM
value|120
end_define

begin_comment
comment|/* Is a named type file */
end_comment

begin_define
define|#
directive|define
name|EREMOTEIO
value|121
end_define

begin_comment
comment|/* Remote I/O error */
end_comment

begin_define
define|#
directive|define
name|EDQUOT
value|122
end_define

begin_comment
comment|/* Quota exceeded */
end_comment

begin_define
define|#
directive|define
name|ENOMEDIUM
value|123
end_define

begin_comment
comment|/* No medium found */
end_comment

begin_define
define|#
directive|define
name|EMEDIUMTYPE
value|124
end_define

begin_comment
comment|/* Wrong medium type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

