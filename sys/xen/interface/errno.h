begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ERRNO_H__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_define
define|#
directive|define
name|XEN_ERRNO
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|XEN_##name = value,
end_define

begin_enum
enum|enum
name|xen_errno
block|{
else|#
directive|else
comment|/* !__ASSEMBLY__ */
define|#
directive|define
name|XEN_ERRNO
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|.equ XEN_##name, value
endif|#
directive|endif
comment|/* __ASSEMBLY__ */
comment|/* ` enum neg_errnoval {  [ -Efoo for each Efoo in the list below ]  } */
comment|/* ` enum errnoval { */
endif|#
directive|endif
comment|/* __XEN_PUBLIC_ERRNO_H__ */
ifdef|#
directive|ifdef
name|XEN_ERRNO
comment|/*  * Values originating from x86 Linux. Please consider using respective  * values when adding new definitions here.  *  * The set of identifiers to be added here shouldn't extend beyond what  * POSIX mandates (see e.g.  * http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/errno.h.html)  * with the exception that we support some optional (XSR) values  * specified there (but no new ones should be added).  */
name|XEN_ERRNO
argument_list|(
argument|EPERM
argument_list|,
literal|1
argument_list|)
comment|/* Operation not permitted */
name|XEN_ERRNO
argument_list|(
argument|ENOENT
argument_list|,
literal|2
argument_list|)
comment|/* No such file or directory */
name|XEN_ERRNO
argument_list|(
argument|ESRCH
argument_list|,
literal|3
argument_list|)
comment|/* No such process */
ifdef|#
directive|ifdef
name|__XEN__
comment|/* Internal only, should never be exposed to the guest. */
name|XEN_ERRNO
argument_list|(
argument|EINTR
argument_list|,
literal|4
argument_list|)
comment|/* Interrupted system call */
endif|#
directive|endif
name|XEN_ERRNO
argument_list|(
argument|EIO
argument_list|,
literal|5
argument_list|)
comment|/* I/O error */
name|XEN_ERRNO
argument_list|(
argument|ENXIO
argument_list|,
literal|6
argument_list|)
comment|/* No such device or address */
name|XEN_ERRNO
argument_list|(
argument|E2BIG
argument_list|,
literal|7
argument_list|)
comment|/* Arg list too long */
name|XEN_ERRNO
argument_list|(
argument|ENOEXEC
argument_list|,
literal|8
argument_list|)
comment|/* Exec format error */
name|XEN_ERRNO
argument_list|(
argument|EBADF
argument_list|,
literal|9
argument_list|)
comment|/* Bad file number */
name|XEN_ERRNO
argument_list|(
argument|ECHILD
argument_list|,
literal|10
argument_list|)
comment|/* No child processes */
name|XEN_ERRNO
argument_list|(
argument|EAGAIN
argument_list|,
literal|11
argument_list|)
comment|/* Try again */
name|XEN_ERRNO
argument_list|(
argument|ENOMEM
argument_list|,
literal|12
argument_list|)
comment|/* Out of memory */
name|XEN_ERRNO
argument_list|(
argument|EACCES
argument_list|,
literal|13
argument_list|)
comment|/* Permission denied */
name|XEN_ERRNO
argument_list|(
argument|EFAULT
argument_list|,
literal|14
argument_list|)
comment|/* Bad address */
name|XEN_ERRNO
argument_list|(
argument|EBUSY
argument_list|,
literal|16
argument_list|)
comment|/* Device or resource busy */
name|XEN_ERRNO
argument_list|(
argument|EEXIST
argument_list|,
literal|17
argument_list|)
comment|/* File exists */
name|XEN_ERRNO
argument_list|(
argument|EXDEV
argument_list|,
literal|18
argument_list|)
comment|/* Cross-device link */
name|XEN_ERRNO
argument_list|(
argument|ENODEV
argument_list|,
literal|19
argument_list|)
comment|/* No such device */
name|XEN_ERRNO
argument_list|(
argument|EINVAL
argument_list|,
literal|22
argument_list|)
comment|/* Invalid argument */
name|XEN_ERRNO
argument_list|(
argument|ENFILE
argument_list|,
literal|23
argument_list|)
comment|/* File table overflow */
name|XEN_ERRNO
argument_list|(
argument|EMFILE
argument_list|,
literal|24
argument_list|)
comment|/* Too many open files */
name|XEN_ERRNO
argument_list|(
argument|ENOSPC
argument_list|,
literal|28
argument_list|)
comment|/* No space left on device */
name|XEN_ERRNO
argument_list|(
argument|EMLINK
argument_list|,
literal|31
argument_list|)
comment|/* Too many links */
name|XEN_ERRNO
argument_list|(
argument|EDOM
argument_list|,
literal|33
argument_list|)
comment|/* Math argument out of domain of func */
name|XEN_ERRNO
argument_list|(
argument|ERANGE
argument_list|,
literal|34
argument_list|)
comment|/* Math result not representable */
name|XEN_ERRNO
argument_list|(
argument|EDEADLK
argument_list|,
literal|35
argument_list|)
comment|/* Resource deadlock would occur */
name|XEN_ERRNO
argument_list|(
argument|ENAMETOOLONG
argument_list|,
literal|36
argument_list|)
comment|/* File name too long */
name|XEN_ERRNO
argument_list|(
argument|ENOLCK
argument_list|,
literal|37
argument_list|)
comment|/* No record locks available */
name|XEN_ERRNO
argument_list|(
argument|ENOSYS
argument_list|,
literal|38
argument_list|)
comment|/* Function not implemented */
name|XEN_ERRNO
argument_list|(
argument|ENODATA
argument_list|,
literal|61
argument_list|)
comment|/* No data available */
name|XEN_ERRNO
argument_list|(
argument|ETIME
argument_list|,
literal|62
argument_list|)
comment|/* Timer expired */
name|XEN_ERRNO
argument_list|(
argument|EBADMSG
argument_list|,
literal|74
argument_list|)
comment|/* Not a data message */
name|XEN_ERRNO
argument_list|(
argument|EOVERFLOW
argument_list|,
literal|75
argument_list|)
comment|/* Value too large for defined data type */
name|XEN_ERRNO
argument_list|(
argument|EILSEQ
argument_list|,
literal|84
argument_list|)
comment|/* Illegal byte sequence */
ifdef|#
directive|ifdef
name|__XEN__
comment|/* Internal only, should never be exposed to the guest. */
name|XEN_ERRNO
argument_list|(
argument|ERESTART
argument_list|,
literal|85
argument_list|)
comment|/* Interrupted system call should be restarted */
endif|#
directive|endif
name|XEN_ERRNO
argument_list|(
argument|ENOTSOCK
argument_list|,
literal|88
argument_list|)
comment|/* Socket operation on non-socket */
name|XEN_ERRNO
argument_list|(
argument|EOPNOTSUPP
argument_list|,
literal|95
argument_list|)
comment|/* Operation not supported on transport endpoint */
name|XEN_ERRNO
argument_list|(
argument|EADDRINUSE
argument_list|,
literal|98
argument_list|)
comment|/* Address already in use */
name|XEN_ERRNO
argument_list|(
argument|EADDRNOTAVAIL
argument_list|,
literal|99
argument_list|)
comment|/* Cannot assign requested address */
name|XEN_ERRNO
argument_list|(
argument|ENOBUFS
argument_list|,
literal|105
argument_list|)
comment|/* No buffer space available */
name|XEN_ERRNO
argument_list|(
argument|EISCONN
argument_list|,
literal|106
argument_list|)
comment|/* Transport endpoint is already connected */
name|XEN_ERRNO
argument_list|(
argument|ENOTCONN
argument_list|,
literal|107
argument_list|)
comment|/* Transport endpoint is not connected */
name|XEN_ERRNO
argument_list|(
argument|ETIMEDOUT
argument_list|,
literal|110
argument_list|)
comment|/* Connection timed out */
undef|#
directive|undef
name|XEN_ERRNO
endif|#
directive|endif
comment|/* XEN_ERRNO */
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ERRNO_H__
define|#
directive|define
name|__XEN_PUBLIC_ERRNO_H__
comment|/* ` } */
ifndef|#
directive|ifndef
name|__ASSEMBLY__
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XEN_EWOULDBLOCK
value|XEN_EAGAIN
end_define

begin_comment
comment|/* Operation would block */
end_comment

begin_define
define|#
directive|define
name|XEN_EDEADLOCK
value|XEN_EDEADLK
end_define

begin_comment
comment|/* Resource deadlock would occur */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __XEN_PUBLIC_ERRNO_H__ */
end_comment

end_unit

