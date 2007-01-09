begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* FreeBSD 5.0 and later have ACL support. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>
literal|4
end_if

begin_define
define|#
directive|define
name|HAVE_ACL_CREATE_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FD_NP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_SET_FILE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ACL_USER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_BZLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EFTYPE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_EILSEQ
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LCHOWN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LUTIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MALLOC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKFIFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_RDEV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_ACL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* FreeBSD 4 and earlier lack intmax_t/uintmax_t */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD__
operator|<
literal|5
end_if

begin_define
define|#
directive|define
name|intmax_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|uintmax_t
value|uint64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

