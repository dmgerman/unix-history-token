begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ibcs2_errno.h  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_ERRNO_H
end_define

begin_define
define|#
directive|define
name|_SCO_NET
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_EPERM
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_ESRCH
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_EINTR
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_EIO
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_ENXIO
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_E2BIG
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOEXEC
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_EBADF
value|9
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHILD
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_EAGAIN
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOMEM
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_EACCES
value|13
end_define

begin_define
define|#
directive|define
name|IBCS2_EFAULT
value|14
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTBLK
value|15
end_define

begin_define
define|#
directive|define
name|IBCS2_EBUSY
value|16
end_define

begin_define
define|#
directive|define
name|IBCS2_EEXIST
value|17
end_define

begin_define
define|#
directive|define
name|IBCS2_EXDEV
value|18
end_define

begin_define
define|#
directive|define
name|IBCS2_ENODEV
value|19
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|IBCS2_EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|IBCS2_EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|IBCS2_ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|IBCS2_EMFILE
value|24
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTTY
value|25
end_define

begin_define
define|#
directive|define
name|IBCS2_ETXTBSY
value|26
end_define

begin_define
define|#
directive|define
name|IBCS2_EFBIG
value|27
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|IBCS2_ESPIPE
value|29
end_define

begin_define
define|#
directive|define
name|IBCS2_EROFS
value|30
end_define

begin_define
define|#
directive|define
name|IBCS2_EMLINK
value|31
end_define

begin_define
define|#
directive|define
name|IBCS2_EPIPE
value|32
end_define

begin_define
define|#
directive|define
name|IBCS2_EDOM
value|33
end_define

begin_define
define|#
directive|define
name|IBCS2_ERANGE
value|34
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOMSG
value|35
end_define

begin_define
define|#
directive|define
name|IBCS2_EIDRM
value|36
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHRNG
value|37
end_define

begin_define
define|#
directive|define
name|IBCS2_EL2NSYNC
value|38
end_define

begin_define
define|#
directive|define
name|IBCS2_EL3HLT
value|39
end_define

begin_define
define|#
directive|define
name|IBCS2_EL3RST
value|40
end_define

begin_define
define|#
directive|define
name|IBCS2_ELNRNG
value|41
end_define

begin_define
define|#
directive|define
name|IBCS2_EUNATCH
value|42
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOCSI
value|43
end_define

begin_define
define|#
directive|define
name|IBCS2_EL2HLT
value|44
end_define

begin_define
define|#
directive|define
name|IBCS2_EDEADLK
value|45
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOLCK
value|46
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOSTR
value|60
end_define

begin_define
define|#
directive|define
name|IBCS2_ENODATA
value|61
end_define

begin_define
define|#
directive|define
name|IBCS2_ETIME
value|62
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOSR
value|63
end_define

begin_define
define|#
directive|define
name|IBCS2_ENONET
value|64
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOPKG
value|65
end_define

begin_define
define|#
directive|define
name|IBCS2_EREMOTE
value|66
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOLINK
value|67
end_define

begin_define
define|#
directive|define
name|IBCS2_EADV
value|68
end_define

begin_define
define|#
directive|define
name|IBCS2_ESRMNT
value|69
end_define

begin_define
define|#
directive|define
name|IBCS2_ECOMM
value|70
end_define

begin_define
define|#
directive|define
name|IBCS2_EPROTO
value|71
end_define

begin_define
define|#
directive|define
name|IBCS2_EMULTIHOP
value|74
end_define

begin_define
define|#
directive|define
name|IBCS2_ELBIN
value|75
end_define

begin_define
define|#
directive|define
name|IBCS2_EDOTDOT
value|76
end_define

begin_define
define|#
directive|define
name|IBCS2_EBADMSG
value|77
end_define

begin_define
define|#
directive|define
name|IBCS2_ENAMETOOLONG
value|78
end_define

begin_define
define|#
directive|define
name|IBCS2_EOVERFLOW
value|79
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTUNIQ
value|80
end_define

begin_define
define|#
directive|define
name|IBCS2_EBADFD
value|81
end_define

begin_define
define|#
directive|define
name|IBCS2_EREMCHG
value|82
end_define

begin_define
define|#
directive|define
name|IBCS2_EILSEQ
value|88
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOSYS
value|89
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SCO_NET
argument_list|)
end_if

begin_comment
comment|/* not strict iBCS2 */
end_comment

begin_define
define|#
directive|define
name|IBCS2_EWOULDBLOCK
value|90
end_define

begin_define
define|#
directive|define
name|IBCS2_EINPROGRESS
value|91
end_define

begin_define
define|#
directive|define
name|IBCS2_EALREADY
value|92
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTSOCK
value|93
end_define

begin_define
define|#
directive|define
name|IBCS2_EDESTADDRREQ
value|94
end_define

begin_define
define|#
directive|define
name|IBCS2_EMSGSIZE
value|95
end_define

begin_define
define|#
directive|define
name|IBCS2_EPROTOTYPE
value|96
end_define

begin_define
define|#
directive|define
name|IBCS2_EPROTONOSUPPORT
value|97
end_define

begin_define
define|#
directive|define
name|IBCS2_ESOCKTNOSUPPORT
value|98
end_define

begin_define
define|#
directive|define
name|IBCS2_EOPNOTSUPP
value|99
end_define

begin_define
define|#
directive|define
name|IBCS2_EPFNOSUPPORT
value|100
end_define

begin_define
define|#
directive|define
name|IBCS2_EAFNOSUPPORT
value|101
end_define

begin_define
define|#
directive|define
name|IBCS2_EADDRINUSE
value|102
end_define

begin_define
define|#
directive|define
name|IBCS2_EADDRNOTAVAIL
value|103
end_define

begin_define
define|#
directive|define
name|IBCS2_ENETDOWN
value|104
end_define

begin_define
define|#
directive|define
name|IBCS2_ENETUNREACH
value|105
end_define

begin_define
define|#
directive|define
name|IBCS2_ENETRESET
value|106
end_define

begin_define
define|#
directive|define
name|IBCS2_ECONNABORTED
value|107
end_define

begin_define
define|#
directive|define
name|IBCS2_ECONNRESET
value|108
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOBUFS
value|IBCS2_ENOSR
end_define

begin_define
define|#
directive|define
name|IBCS2_EISCONN
value|110
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTCONN
value|111
end_define

begin_define
define|#
directive|define
name|IBCS2_ESHUTDOWN
value|112
end_define

begin_define
define|#
directive|define
name|IBCS2_ETOOMANYREFS
value|113
end_define

begin_define
define|#
directive|define
name|IBCS2_ETIMEDOUT
value|114
end_define

begin_define
define|#
directive|define
name|IBCS2_ECONNREFUSED
value|115
end_define

begin_define
define|#
directive|define
name|IBCS2_EHOSTDOWN
value|116
end_define

begin_define
define|#
directive|define
name|IBCS2_EHOSTUNREACH
value|117
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOPROTOOPT
value|118
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTEMPTY
value|145
end_define

begin_define
define|#
directive|define
name|IBCS2_ELOOP
value|150
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IBCS2_ELOOP
value|90
end_define

begin_define
define|#
directive|define
name|IBCS2_EWOULDBLOCK
value|90
end_define

begin_define
define|#
directive|define
name|IBCS2_ERESTART
value|91
end_define

begin_define
define|#
directive|define
name|IBCS2_ESTRPIPE
value|92
end_define

begin_define
define|#
directive|define
name|IBCS2_ENOTEMPTY
value|93
end_define

begin_define
define|#
directive|define
name|IBCS2_EUSERS
value|94
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IBCS2_ESTALE
value|151
end_define

begin_define
define|#
directive|define
name|IBCS2_EIORESID
value|500
end_define

begin_decl_stmt
specifier|extern
name|int
name|bsd2ibcs_errno
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_ERRNO_H */
end_comment

end_unit

