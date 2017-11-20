begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2008 Apple Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.   *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_ERRNO_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_ERRNO_H_
end_define

begin_comment
comment|/*  * For the purposes of portable encoding, we convert between local error  * numbers and Solaris error numbers (as well as some extensions for error  * numbers that don't exist in Solaris).  Although the first 35 or so  * constants are the same across all OS's, we don't handle that in any  * special way.  *  * When adding constants here, also add them to bsm_errno.c.  */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ESUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EPERM
value|1
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESRCH
value|3
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EINTR
value|4
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EIO
value|5
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENXIO
value|6
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_E2BIG
value|7
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOEXEC
value|8
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADF
value|9
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECHILD
value|10
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EAGAIN
value|11
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOMEM
value|12
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EACCES
value|13
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EFAULT
value|14
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTBLK
value|15
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EBUSY
value|16
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EEXIST
value|17
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EXDEV
value|18
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENODEV
value|19
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EMFILE
value|24
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTTY
value|25
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ETXTBSY
value|26
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EFBIG
value|27
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESPIPE
value|29
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EROFS
value|30
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EMLINK
value|31
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EPIPE
value|32
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EDOM
value|33
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ERANGE
value|34
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOMSG
value|35
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EIDRM
value|36
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECHRNG
value|37
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EL2NSYNC
value|38
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EL3HLT
value|39
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EL3RST
value|40
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELNRNG
value|41
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EUNATCH
value|42
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOCSI
value|43
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EL2HLT
value|44
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDEADLK
value|45
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOLCK
value|46
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECANCELED
value|47
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTSUP
value|48
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EDQUOT
value|49
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADE
value|50
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADR
value|51
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EXFULL
value|52
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOANO
value|53
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADRQC
value|54
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADSLT
value|55
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDEADLOCK
value|56
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBFONT
value|57
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EOWNERDEAD
value|58
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTRECOVERABLE
value|59
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOSTR
value|60
end_define

begin_comment
comment|/* Solaris/Darwin/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENODATA
value|61
end_define

begin_comment
comment|/* Solaris/Darwin/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ETIME
value|62
end_define

begin_comment
comment|/* Solaris/Darwin/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOSR
value|63
end_define

begin_comment
comment|/* Solaris/Darwin/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENONET
value|64
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOPKG
value|65
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EREMOTE
value|66
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOLINK
value|67
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EADV
value|68
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ESRMNT
value|69
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ECOMM
value|70
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROTO
value|71
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ELOCKUNMAPPED
value|72
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTACTIVE
value|73
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EMULTIHOP
value|74
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADMSG
value|77
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENAMETOOLONG
value|78
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EOVERFLOW
value|79
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTUNIQ
value|80
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADFD
value|81
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EREMCHG
value|82
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELIBACC
value|83
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELIBBAD
value|84
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELIBSCN
value|85
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELIBMAX
value|86
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ELIBEXEC
value|87
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EILSEQ
value|88
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOSYS
value|89
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ELOOP
value|90
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ERESTART
value|91
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESTRPIPE
value|92
end_define

begin_comment
comment|/* Solaris/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTEMPTY
value|93
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EUSERS
value|94
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTSOCK
value|95
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EDESTADDRREQ
value|96
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EMSGSIZE
value|97
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROTOTYPE
value|98
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOPROTOOPT
value|99
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROTONOSUPPORT
value|120
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESOCKTNOSUPPORT
value|121
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EOPNOTSUPP
value|122
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EPFNOSUPPORT
value|123
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EAFNOSUPPORT
value|124
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EADDRINUSE
value|125
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EADDRNOTAVAIL
value|126
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENETDOWN
value|127
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENETUNREACH
value|128
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENETRESET
value|129
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECONNABORTED
value|130
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECONNRESET
value|131
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOBUFS
value|132
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EISCONN
value|133
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTCONN
value|134
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESHUTDOWN
value|143
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ETOOMANYREFS
value|144
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ETIMEDOUT
value|145
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ECONNREFUSED
value|146
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EHOSTDOWN
value|147
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EHOSTUNREACH
value|148
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EALREADY
value|149
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_EINPROGRESS
value|150
end_define

begin_define
define|#
directive|define
name|BSM_ERRNO_ESTALE
value|151
end_define

begin_comment
comment|/*  * OpenBSM constants for error numbers not defined in Solaris.  In the event  * that these errors are added to Solaris, we will deprecate the OpenBSM  * numbers in the same way we do for audit event constants.  *  * ELAST doesn't get a constant in the BSM space.  */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROCLIM
value|190
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADRPC
value|191
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ERPCMISMATCH
value|192
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROGUNAVAIL
value|193
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROGMISMATCH
value|194
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPROCUNAVAIL
value|195
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EFTYPE
value|196
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EAUTH
value|197
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENEEDAUTH
value|198
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOATTR
value|199
end_define

begin_comment
comment|/* FreeBSD/Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDOOFUS
value|200
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EJUSTRETURN
value|201
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOIOCTL
value|202
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDIRIOCTL
value|203
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPWROFF
value|204
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDEVERR
value|205
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADEXEC
value|206
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADARCH
value|207
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ESHLIBVERS
value|208
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EBADMACHO
value|209
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EPOLICY
value|210
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EDOTDOT
value|211
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EUCLEAN
value|212
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTNAM
value|213
end_define

begin_comment
comment|/* Linux(Xenix?)-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENAVAIL
value|214
end_define

begin_comment
comment|/* Linux(Xenix?)-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EISNAM
value|215
end_define

begin_comment
comment|/* Linux(Xenix?)-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EREMOTEIO
value|216
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOMEDIUM
value|217
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EMEDIUMTYPE
value|218
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOKEY
value|219
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EKEYEXPIRED
value|220
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EKEYREVOKED
value|221
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_EKEYREJECTED
value|222
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ENOTCAPABLE
value|223
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_ECAPMODE
value|224
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_comment
comment|/*  * In the event that OpenBSM doesn't have a file representation of a local  * error number, use this.  */
end_comment

begin_define
define|#
directive|define
name|BSM_ERRNO_UNKNOWN
value|250
end_define

begin_comment
comment|/* OpenBSM-specific. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_ERRNO_H_ */
end_comment

end_unit

