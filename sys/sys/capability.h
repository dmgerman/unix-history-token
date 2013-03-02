begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2010 Robert N. M. Watson  * Copyright (c) 2012 FreeBSD Foundation  * All rights reserved.  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.  *  * Portions of this software were developed by Pawel Jakub Dawidek under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for FreeBSD capabilities facility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CAPABILITY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CAPABILITY_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_comment
comment|/*  * Possible rights on capabilities.  *  * Notes:  * Some system calls don't require a capability in order to perform an  * operation on an fd.  These include: close, dup, dup2.  *  * sendfile is authorized using CAP_READ on the file and CAP_WRITE on the  * socket.  *  * mmap() and aio*() system calls will need special attention as they may  * involve reads or writes depending a great deal on context.  */
end_comment

begin_define
define|#
directive|define
name|CAP_NONE
value|0x0000000000000000ULL
end_define

begin_comment
comment|/*  * General file I/O.  */
end_comment

begin_comment
comment|/* Allows for openat(O_RDONLY), read(2), readv(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_READ
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* Allows for openat(O_WRONLY | O_APPEND), write(2), writev(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_WRITE
value|0x0000000000000002ULL
end_define

begin_comment
comment|/* Allows for lseek(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_SEEK
value|0x0000000000000080ULL
end_define

begin_comment
comment|/* Allows for pread(2), preadv(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_PREAD
value|(CAP_SEEK | CAP_READ)
end_define

begin_comment
comment|/* Allows for openat(O_WRONLY) (without O_APPEND), pwrite(2), pwritev(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_PWRITE
value|(CAP_SEEK | CAP_WRITE)
end_define

begin_comment
comment|/* Allows for mmap(PROT_NONE). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP
value|0x0000000000000004ULL
end_define

begin_comment
comment|/* Allows for mmap(PROT_READ). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_R
value|(CAP_MMAP | CAP_SEEK | CAP_READ)
end_define

begin_comment
comment|/* Allows for mmap(PROT_WRITE). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_W
value|(CAP_MMAP | CAP_SEEK | CAP_WRITE)
end_define

begin_comment
comment|/* Allows for mmap(PROT_EXEC). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_X
value|(CAP_MMAP | CAP_SEEK | 0x0000000000000008ULL)
end_define

begin_comment
comment|/* Allows for mmap(PROT_READ | PROT_WRITE). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_RW
value|(CAP_MMAP_R | CAP_MMAP_W)
end_define

begin_comment
comment|/* Allows for mmap(PROT_READ | PROT_EXEC). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_RX
value|(CAP_MMAP_R | CAP_MMAP_X)
end_define

begin_comment
comment|/* Allows for mmap(PROT_WRITE | PROT_EXEC). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_WX
value|(CAP_MMAP_W | CAP_MMAP_X)
end_define

begin_comment
comment|/* Allows for mmap(PROT_READ | PROT_WRITE | PROT_EXEC). */
end_comment

begin_define
define|#
directive|define
name|CAP_MMAP_RWX
value|(CAP_MMAP_R | CAP_MMAP_W | CAP_MMAP_X)
end_define

begin_comment
comment|/* Allows for openat(O_CREAT). */
end_comment

begin_define
define|#
directive|define
name|CAP_CREATE
value|0x0000000000080000ULL
end_define

begin_comment
comment|/* Allows for openat(O_EXEC) and fexecve(2) in turn. */
end_comment

begin_define
define|#
directive|define
name|CAP_FEXECVE
value|0x0000000000000010ULL
end_define

begin_comment
comment|/* Allows for openat(O_SYNC), openat(O_FSYNC), fsync(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_FSYNC
value|0x0000000000000020ULL
end_define

begin_comment
comment|/* Allows for openat(O_TRUNC), ftruncate(2). */
end_comment

begin_define
define|#
directive|define
name|CAP_FTRUNCATE
value|0x0000000000000040ULL
end_define

begin_comment
comment|/* VFS methods. */
end_comment

begin_define
define|#
directive|define
name|CAP_FCHDIR
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|CAP_FCHFLAGS
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|CAP_FCHMOD
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|CAP_FCHMODAT
value|CAP_FCHMOD
end_define

begin_define
define|#
directive|define
name|CAP_FCHOWN
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|CAP_FCHOWNAT
value|CAP_FCHOWN
end_define

begin_define
define|#
directive|define
name|CAP_FCNTL
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FLOCK
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FPATHCONF
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FSCK
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FSTAT
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FSTATAT
value|CAP_FSTAT
end_define

begin_define
define|#
directive|define
name|CAP_FSTATFS
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FUTIMES
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|CAP_FUTIMESAT
value|CAP_FUTIMES
end_define

begin_define
define|#
directive|define
name|CAP_LINKAT
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|CAP_MKDIRAT
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|CAP_MKFIFOAT
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|CAP_MKNODAT
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_RENAMEAT
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_SYMLINKAT
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNLINKAT
value|0x0000000000100000ULL
end_define

begin_comment
comment|/* Lookups - used to constrain *at() calls. */
end_comment

begin_define
define|#
directive|define
name|CAP_LOOKUP
value|0x0000000001000000ULL
end_define

begin_comment
comment|/* Extended attributes. */
end_comment

begin_define
define|#
directive|define
name|CAP_EXTATTR_DELETE
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_EXTATTR_GET
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_EXTATTR_LIST
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_EXTATTR_SET
value|0x0000000010000000ULL
end_define

begin_comment
comment|/* Access Control Lists. */
end_comment

begin_define
define|#
directive|define
name|CAP_ACL_CHECK
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_ACL_DELETE
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_ACL_GET
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_ACL_SET
value|0x0000000100000000ULL
end_define

begin_comment
comment|/* Socket operations. */
end_comment

begin_define
define|#
directive|define
name|CAP_ACCEPT
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_BIND
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_CONNECT
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_GETPEERNAME
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_GETSOCKNAME
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_GETSOCKOPT
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_LISTEN
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_PEELOFF
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_RECV
value|CAP_READ
end_define

begin_define
define|#
directive|define
name|CAP_SEND
value|CAP_WRITE
end_define

begin_define
define|#
directive|define
name|CAP_SETSOCKOPT
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_SHUTDOWN
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_SOCK_CLIENT
define|\
value|(CAP_CONNECT | CAP_GETPEERNAME | CAP_GETSOCKNAME | CAP_GETSOCKOPT | \ 	 CAP_PEELOFF | CAP_RECV | CAP_SEND | CAP_SETSOCKOPT | CAP_SHUTDOWN)
end_define

begin_define
define|#
directive|define
name|CAP_SOCK_SERVER
define|\
value|(CAP_ACCEPT | CAP_BIND | CAP_GETPEERNAME | CAP_GETSOCKNAME | \ 	 CAP_GETSOCKOPT | CAP_LISTEN | CAP_PEELOFF | CAP_RECV | CAP_SEND | \ 	 CAP_SETSOCKOPT | CAP_SHUTDOWN)
end_define

begin_comment
comment|/* Mandatory Access Control. */
end_comment

begin_define
define|#
directive|define
name|CAP_MAC_GET
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_MAC_SET
value|0x0000100000000000ULL
end_define

begin_comment
comment|/* Methods on semaphores. */
end_comment

begin_define
define|#
directive|define
name|CAP_SEM_GETVALUE
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_SEM_POST
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_SEM_WAIT
value|0x0000800000000000ULL
end_define

begin_comment
comment|/* kqueue events. */
end_comment

begin_define
define|#
directive|define
name|CAP_POLL_EVENT
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_POST_EVENT
value|0x0002000000000000ULL
end_define

begin_comment
comment|/* Strange and powerful rights that should not be given lightly. */
end_comment

begin_define
define|#
directive|define
name|CAP_IOCTL
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_TTYHOOK
value|0x0008000000000000ULL
end_define

begin_comment
comment|/* Process management via process descriptors. */
end_comment

begin_define
define|#
directive|define
name|CAP_PDGETPID
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_PDWAIT
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_PDKILL
value|0x0040000000000000ULL
end_define

begin_comment
comment|/* The mask of all valid method rights. */
end_comment

begin_define
define|#
directive|define
name|CAP_MASK_VALID
value|0x03ffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|CAP_ALL
value|CAP_MASK_VALID
end_define

begin_comment
comment|/* Available bits. */
end_comment

begin_define
define|#
directive|define
name|CAP_UNUSED5
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNUSED4
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNUSED3
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNUSED2
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNUSED1
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|CAP_UNUSED0
value|0x8000000000000000ULL
end_define

begin_comment
comment|/*  * The following defines are provided for backward API compatibility and  * should not be used in new code.  */
end_comment

begin_define
define|#
directive|define
name|CAP_MAPEXEC
value|CAP_MMAP_X
end_define

begin_define
define|#
directive|define
name|CAP_DELETE
value|CAP_UNLINKAT
end_define

begin_define
define|#
directive|define
name|CAP_MKDIR
value|CAP_MKDIRAT
end_define

begin_define
define|#
directive|define
name|CAP_RMDIR
value|CAP_UNLINKAT
end_define

begin_define
define|#
directive|define
name|CAP_MKFIFO
value|CAP_MKFIFOAT
end_define

begin_define
define|#
directive|define
name|CAP_MKNOD
value|CAP_MKNODAT
end_define

begin_define
define|#
directive|define
name|CAP_SOCK_ALL
value|(CAP_SOCK_CLIENT | CAP_SOCK_SERVER)
end_define

begin_comment
comment|/*  * Allowed fcntl(2) commands.  */
end_comment

begin_define
define|#
directive|define
name|CAP_FCNTL_GETFL
value|(1<< F_GETFL)
end_define

begin_define
define|#
directive|define
name|CAP_FCNTL_SETFL
value|(1<< F_SETFL)
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__XSI_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|CAP_FCNTL_GETOWN
value|(1<< F_GETOWN)
end_define

begin_define
define|#
directive|define
name|CAP_FCNTL_SETOWN
value|(1<< F_SETOWN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__XSI_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|CAP_FCNTL_ALL
value|(CAP_FCNTL_GETFL | CAP_FCNTL_SETFL | \ 				 CAP_FCNTL_GETOWN | CAP_FCNTL_SETOWN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAP_FCNTL_ALL
value|(CAP_FCNTL_GETFL | CAP_FCNTL_SETFL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CAP_IOCTLS_ALL
value|SSIZE_MAX
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_define
define|#
directive|define
name|IN_CAPABILITY_MODE
parameter_list|(
name|td
parameter_list|)
value|((td->td_ucred->cr_flags& CRED_FLAG_CAPMODE) != 0)
end_define

begin_struct_decl
struct_decl|struct
name|filedesc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Test whether a capability grants the requested rights.  */
end_comment

begin_function_decl
name|int
name|cap_check
parameter_list|(
name|cap_rights_t
name|have
parameter_list|,
name|cap_rights_t
name|need
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert capability rights into VM access flags.  */
end_comment

begin_function_decl
name|u_char
name|cap_rights_to_vmprot
parameter_list|(
name|cap_rights_t
name|have
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * For the purposes of procstat(1) and similar tools, allow kern_descrip.c to  * extract the rights from a capability.  */
end_comment

begin_function_decl
name|cap_rights_t
name|cap_rights
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_ioctl_check
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|,
name|u_long
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_fcntl_check
parameter_list|(
name|struct
name|filedesc
modifier|*
name|fdp
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function_decl
name|__BEGIN_DECLS
include|#
directive|include
file|<stdbool.h>
comment|/*  * cap_enter(): Cause the process to enter capability mode, which will  * prevent it from directly accessing global namespaces.  System calls will  * be limited to process-local, process-inherited, or file descriptor  * operations.  If already in capability mode, a no-op.  *  * Currently, process-inherited operations are not properly handled -- in  * particular, we're interested in things like waitpid(2), kill(2), etc,  * being properly constrained.  One possible solution is to introduce process  * descriptors.  */
name|int
name|cap_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Are we sandboxed (in capability mode)?  * This is a libc wrapper around the cap_getmode(2) system call.  */
end_comment

begin_function_decl
name|bool
name|cap_sandboxed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cap_getmode(): Are we in capability mode?  */
end_comment

begin_function_decl
name|int
name|cap_getmode
parameter_list|(
name|u_int
modifier|*
name|modep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Limits capability rights for the given descriptor (CAP_*).  */
end_comment

begin_function_decl
name|int
name|cap_rights_limit
parameter_list|(
name|int
name|fd
parameter_list|,
name|cap_rights_t
name|rights
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns bitmask of capability rights for the given descriptor.  */
end_comment

begin_function_decl
name|int
name|cap_rights_get
parameter_list|(
name|int
name|fd
parameter_list|,
name|cap_rights_t
modifier|*
name|rightsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Limits allowed ioctls for the given descriptor.  */
end_comment

begin_function_decl
name|int
name|cap_ioctls_limit
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|unsigned
name|long
modifier|*
name|cmds
parameter_list|,
name|size_t
name|ncmds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns array of allowed ioctls for the given descriptor.  * If all ioctls are allowed, the cmds array is not populated and  * the function returns CAP_IOCTLS_ALL.  */
end_comment

begin_function_decl
name|ssize_t
name|cap_ioctls_get
parameter_list|(
name|int
name|fd
parameter_list|,
name|unsigned
name|long
modifier|*
name|cmds
parameter_list|,
name|size_t
name|maxcmds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Limits allowed fcntls for the given descriptor (CAP_FCNTL_*).  */
end_comment

begin_function_decl
name|int
name|cap_fcntls_limit
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint32_t
name|fcntlrights
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns bitmask of allowed fcntls for the given descriptor.  */
end_comment

begin_function_decl
name|int
name|cap_fcntls_get
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint32_t
modifier|*
name|fcntlrightsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For backward compatibility. */
end_comment

begin_function_decl
name|int
name|cap_new
parameter_list|(
name|int
name|fd
parameter_list|,
name|cap_rights_t
name|rights
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cap_getrights
parameter_list|(
name|fd
parameter_list|,
name|rightsp
parameter_list|)
value|cap_rights_get((fd), (rightsp))
end_define

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CAPABILITY_H_ */
end_comment

end_unit

