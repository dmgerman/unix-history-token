begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_ERRNO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_ERRNO_H_
end_define

begin_define
define|#
directive|define
name|SVR4_EPERM
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_ESRCH
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_EINTR
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_EIO
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_ENXIO
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_E2BIG
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_ENOEXEC
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_EBADF
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_ECHILD
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_EAGAIN
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_ENOMEM
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_EACCES
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_EFAULT
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTBLK
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_EBUSY
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_EEXIST
value|17
end_define

begin_define
define|#
directive|define
name|SVR4_EXDEV
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_ENODEV
value|19
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|SVR4_EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|SVR4_EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|SVR4_ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|SVR4_EMFILE
value|24
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTTY
value|25
end_define

begin_define
define|#
directive|define
name|SVR4_ETXTBSY
value|26
end_define

begin_define
define|#
directive|define
name|SVR4_EFBIG
value|27
end_define

begin_define
define|#
directive|define
name|SVR4_ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|SVR4_ESPIPE
value|29
end_define

begin_define
define|#
directive|define
name|SVR4_EROFS
value|30
end_define

begin_define
define|#
directive|define
name|SVR4_EMLINK
value|31
end_define

begin_define
define|#
directive|define
name|SVR4_EPIPE
value|32
end_define

begin_define
define|#
directive|define
name|SVR4_EDOM
value|33
end_define

begin_define
define|#
directive|define
name|SVR4_ERANGE
value|34
end_define

begin_define
define|#
directive|define
name|SVR4_ENOMSG
value|35
end_define

begin_define
define|#
directive|define
name|SVR4_EIDRM
value|36
end_define

begin_define
define|#
directive|define
name|SVR4_ECHRNG
value|37
end_define

begin_define
define|#
directive|define
name|SVR4_EL2NSYNC
value|38
end_define

begin_define
define|#
directive|define
name|SVR4_EL3HLT
value|39
end_define

begin_define
define|#
directive|define
name|SVR4_EL3RST
value|40
end_define

begin_define
define|#
directive|define
name|SVR4_ELNRNG
value|41
end_define

begin_define
define|#
directive|define
name|SVR4_EUNATCH
value|42
end_define

begin_define
define|#
directive|define
name|SVR4_ENOCSI
value|43
end_define

begin_define
define|#
directive|define
name|SVR4_EL2HLT
value|44
end_define

begin_define
define|#
directive|define
name|SVR4_EDEADLK
value|45
end_define

begin_define
define|#
directive|define
name|SVR4_ENOLCK
value|46
end_define

begin_define
define|#
directive|define
name|SVR4_EBADE
value|50
end_define

begin_define
define|#
directive|define
name|SVR4_EBADR
value|51
end_define

begin_define
define|#
directive|define
name|SVR4_EXFULL
value|52
end_define

begin_define
define|#
directive|define
name|SVR4_ENOANO
value|53
end_define

begin_define
define|#
directive|define
name|SVR4_EBADRQC
value|54
end_define

begin_define
define|#
directive|define
name|SVR4_EBADSLT
value|55
end_define

begin_define
define|#
directive|define
name|SVR4_EDEADLOCK
value|56
end_define

begin_define
define|#
directive|define
name|SVR4_EBFONT
value|57
end_define

begin_define
define|#
directive|define
name|SVR4_ENOSTR
value|60
end_define

begin_define
define|#
directive|define
name|SVR4_ENODATA
value|61
end_define

begin_define
define|#
directive|define
name|SVR4_ETIME
value|62
end_define

begin_define
define|#
directive|define
name|SVR4_ENOSR
value|63
end_define

begin_define
define|#
directive|define
name|SVR4_ENONET
value|64
end_define

begin_define
define|#
directive|define
name|SVR4_ENOPKG
value|65
end_define

begin_define
define|#
directive|define
name|SVR4_EREMOTE
value|66
end_define

begin_define
define|#
directive|define
name|SVR4_ENOLINK
value|67
end_define

begin_define
define|#
directive|define
name|SVR4_EADV
value|68
end_define

begin_define
define|#
directive|define
name|SVR4_ESRMNT
value|69
end_define

begin_define
define|#
directive|define
name|SVR4_ECOMM
value|70
end_define

begin_define
define|#
directive|define
name|SVR4_EPROTO
value|71
end_define

begin_define
define|#
directive|define
name|SVR4_EMULTIHOP
value|74
end_define

begin_define
define|#
directive|define
name|SVR4_EBADMSG
value|77
end_define

begin_define
define|#
directive|define
name|SVR4_ENAMETOOLONG
value|78
end_define

begin_define
define|#
directive|define
name|SVR4_EOVERFLOW
value|79
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTUNIQ
value|80
end_define

begin_define
define|#
directive|define
name|SVR4_EBADFD
value|81
end_define

begin_define
define|#
directive|define
name|SVR4_EREMCHG
value|82
end_define

begin_define
define|#
directive|define
name|SVR4_ELIBACC
value|83
end_define

begin_define
define|#
directive|define
name|SVR4_ELIBBAD
value|84
end_define

begin_define
define|#
directive|define
name|SVR4_ELIBSCN
value|85
end_define

begin_define
define|#
directive|define
name|SVR4_ELIBMAX
value|86
end_define

begin_define
define|#
directive|define
name|SVR4_ELIBEXEC
value|87
end_define

begin_define
define|#
directive|define
name|SVR4_EILSEQ
value|88
end_define

begin_define
define|#
directive|define
name|SVR4_ENOSYS
value|89
end_define

begin_define
define|#
directive|define
name|SVR4_ELOOP
value|90
end_define

begin_define
define|#
directive|define
name|SVR4_ERESTART
value|91
end_define

begin_define
define|#
directive|define
name|SVR4_ESTRPIPE
value|92
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTEMPTY
value|93
end_define

begin_define
define|#
directive|define
name|SVR4_EUSERS
value|94
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTSOCK
value|95
end_define

begin_define
define|#
directive|define
name|SVR4_EDESTADDRREQ
value|96
end_define

begin_define
define|#
directive|define
name|SVR4_EMSGSIZE
value|97
end_define

begin_define
define|#
directive|define
name|SVR4_EPROTOTYPE
value|98
end_define

begin_define
define|#
directive|define
name|SVR4_ENOPROTOOPT
value|99
end_define

begin_define
define|#
directive|define
name|SVR4_EPROTONOSUPPORT
value|120
end_define

begin_define
define|#
directive|define
name|SVR4_ESOCKTNOSUPPORT
value|121
end_define

begin_define
define|#
directive|define
name|SVR4_EOPNOTSUPP
value|122
end_define

begin_define
define|#
directive|define
name|SVR4_EPFNOSUPPORT
value|123
end_define

begin_define
define|#
directive|define
name|SVR4_EAFNOSUPPORT
value|124
end_define

begin_define
define|#
directive|define
name|SVR4_EADDRINUSE
value|125
end_define

begin_define
define|#
directive|define
name|SVR4_EADDRNOTAVAIL
value|126
end_define

begin_define
define|#
directive|define
name|SVR4_ENETDOWN
value|127
end_define

begin_define
define|#
directive|define
name|SVR4_ENETUNREACH
value|128
end_define

begin_define
define|#
directive|define
name|SVR4_ENETRESET
value|129
end_define

begin_define
define|#
directive|define
name|SVR4_ECONNABORTED
value|130
end_define

begin_define
define|#
directive|define
name|SVR4_ECONNRESET
value|131
end_define

begin_define
define|#
directive|define
name|SVR4_ENOBUFS
value|132
end_define

begin_define
define|#
directive|define
name|SVR4_EISCONN
value|133
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTCONN
value|134
end_define

begin_define
define|#
directive|define
name|SVR4_EUCLEAN
value|135
end_define

begin_define
define|#
directive|define
name|SVR4_ENOTNAM
value|137
end_define

begin_define
define|#
directive|define
name|SVR4_ENAVAIL
value|138
end_define

begin_define
define|#
directive|define
name|SVR4_EISNAM
value|139
end_define

begin_define
define|#
directive|define
name|SVR4_EREMOTEIO
value|140
end_define

begin_define
define|#
directive|define
name|SVR4_EINIT
value|141
end_define

begin_define
define|#
directive|define
name|SVR4_EREMDEV
value|142
end_define

begin_define
define|#
directive|define
name|SVR4_ESHUTDOWN
value|143
end_define

begin_define
define|#
directive|define
name|SVR4_ETOOMANYREFS
value|144
end_define

begin_define
define|#
directive|define
name|SVR4_ETIMEDOUT
value|145
end_define

begin_define
define|#
directive|define
name|SVR4_ECONNREFUSED
value|146
end_define

begin_define
define|#
directive|define
name|SVR4_EHOSTDOWN
value|147
end_define

begin_define
define|#
directive|define
name|SVR4_EHOSTUNREACH
value|148
end_define

begin_define
define|#
directive|define
name|SVR4_EWOULDBLOCK
value|SVR4_EAGAIN
end_define

begin_define
define|#
directive|define
name|SVR4_EALREADY
value|149
end_define

begin_define
define|#
directive|define
name|SVR4_EINPROGRESS
value|150
end_define

begin_define
define|#
directive|define
name|SVR4_ESTALE
value|151
end_define

begin_define
define|#
directive|define
name|SVR4_EIORESID
value|500
end_define

begin_comment
comment|/*  * These ones are not translated...  */
end_comment

begin_define
define|#
directive|define
name|SVR4_EPROCLIM
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EDQUOT
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EBADRPC
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_ERPCMISMATCH
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EPROGUNAVAIL
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EPROGMISMATCH
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EPROCUNAVAIL
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EFTYPE
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_EAUTH
value|SVR4_ENOSYS
end_define

begin_define
define|#
directive|define
name|SVR4_ENEEDAUTH
value|SVR4_ENOSYS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_ERRNO_H_ */
end_comment

end_unit

