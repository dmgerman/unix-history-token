begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ibcs2_errno.c  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_errno.h>
end_include

begin_decl_stmt
name|int
name|bsd_to_ibcs2_errno
index|[
name|ELAST
operator|+
literal|1
index|]
init|=
block|{
literal|0
block|,
comment|/* 0 */
name|IBCS2_EPERM
block|,
comment|/* 1 */
name|IBCS2_ENOENT
block|,
comment|/* 2 */
name|IBCS2_ESRCH
block|,
comment|/* 3 */
name|IBCS2_EINTR
block|,
comment|/* 4 */
name|IBCS2_EIO
block|,
comment|/* 5 */
name|IBCS2_ENXIO
block|,
comment|/* 6 */
name|IBCS2_E2BIG
block|,
comment|/* 7 */
name|IBCS2_ENOEXEC
block|,
comment|/* 8 */
name|IBCS2_EBADF
block|,
comment|/* 9 */
name|IBCS2_ECHILD
block|,
comment|/* 10 */
name|IBCS2_EDEADLK
block|,
comment|/* 11 */
name|IBCS2_ENOMEM
block|,
comment|/* 12 */
name|IBCS2_EACCES
block|,
comment|/* 13 */
name|IBCS2_EFAULT
block|,
comment|/* 14 */
name|IBCS2_ENOTBLK
block|,
comment|/* 15 */
name|IBCS2_EBUSY
block|,
comment|/* 16 */
name|IBCS2_EEXIST
block|,
comment|/* 17 */
name|IBCS2_EXDEV
block|,
comment|/* 18 */
name|IBCS2_ENODEV
block|,
comment|/* 19 */
name|IBCS2_ENOTDIR
block|,
comment|/* 20 */
name|IBCS2_EISDIR
block|,
comment|/* 21 */
name|IBCS2_EINVAL
block|,
comment|/* 22 */
name|IBCS2_ENFILE
block|,
comment|/* 23 */
name|IBCS2_EMFILE
block|,
comment|/* 24 */
name|IBCS2_ENOTTY
block|,
comment|/* 25 */
name|IBCS2_ETXTBSY
block|,
comment|/* 26 */
name|IBCS2_EFBIG
block|,
comment|/* 27 */
name|IBCS2_ENOSPC
block|,
comment|/* 28 */
name|IBCS2_ESPIPE
block|,
comment|/* 29 */
name|IBCS2_EROFS
block|,
comment|/* 30 */
name|IBCS2_EMLINK
block|,
comment|/* 31 */
name|IBCS2_EPIPE
block|,
comment|/* 32 */
name|IBCS2_EDOM
block|,
comment|/* 33 */
name|IBCS2_ERANGE
block|,
comment|/* 34 */
name|IBCS2_EAGAIN
block|,
comment|/* 35 */
name|IBCS2_EINPROGRESS
block|,
comment|/* 36 */
name|IBCS2_EALREADY
block|,
comment|/* 37 */
name|IBCS2_ENOTSOCK
block|,
comment|/* 38 */
name|IBCS2_EDESTADDRREQ
block|,
comment|/* 39 */
name|IBCS2_EMSGSIZE
block|,
comment|/* 40 */
name|IBCS2_EPROTOTYPE
block|,
comment|/* 41 */
name|IBCS2_ENOPROTOOPT
block|,
comment|/* 42 */
name|IBCS2_EPROTONOSUPPORT
block|,
comment|/* 43 */
name|IBCS2_ESOCKTNOSUPPORT
block|,
comment|/* 44 */
name|IBCS2_EOPNOTSUPP
block|,
comment|/* 45 */
name|IBCS2_EPFNOSUPPORT
block|,
comment|/* 46 */
name|IBCS2_EAFNOSUPPORT
block|,
comment|/* 47 */
name|IBCS2_EADDRINUSE
block|,
comment|/* 48 */
name|IBCS2_EADDRNOTAVAIL
block|,
comment|/* 49 */
name|IBCS2_ENETDOWN
block|,
comment|/* 50 */
name|IBCS2_ENETUNREACH
block|,
comment|/* 51 */
name|IBCS2_ENETRESET
block|,
comment|/* 52 */
name|IBCS2_ECONNABORTED
block|,
comment|/* 53 */
name|IBCS2_ECONNRESET
block|,
comment|/* 54 */
name|IBCS2_ENOBUFS
block|,
comment|/* 55 */
name|IBCS2_EISCONN
block|,
comment|/* 56 */
name|IBCS2_ENOTCONN
block|,
comment|/* 57 */
name|IBCS2_ESHUTDOWN
block|,
comment|/* 58 */
name|IBCS2_ETOOMANYREFS
block|,
comment|/* 59 */
name|IBCS2_ETIMEDOUT
block|,
comment|/* 60 */
name|IBCS2_ECONNREFUSED
block|,
comment|/* 61 */
name|IBCS2_ELOOP
block|,
comment|/* 62 */
name|IBCS2_ENAMETOOLONG
block|,
comment|/* 63 */
name|IBCS2_EHOSTDOWN
block|,
comment|/* 64 */
name|IBCS2_EHOSTUNREACH
block|,
comment|/* 65 */
name|IBCS2_ENOTEMPTY
block|,
comment|/* 66 */
literal|0
block|,
comment|/* 67 */
literal|0
block|,
comment|/* 68 */
literal|0
block|,
comment|/* 69 */
name|IBCS2_ESTALE
block|,
comment|/* 70 */
name|IBCS2_EREMOTE
block|,
comment|/* 71 */
literal|0
block|,
comment|/* 72 */
literal|0
block|,
comment|/* 73 */
literal|0
block|,
comment|/* 74 */
literal|0
block|,
comment|/* 75 */
literal|0
block|,
comment|/* 76 */
name|IBCS2_ENOLCK
block|,
comment|/* 77 */
name|IBCS2_ENOSYS
block|,
comment|/* 78 */
literal|0
block|,
comment|/* 79 */
literal|0
block|,
comment|/* 80 */
literal|0
block|,
comment|/* 81 */
name|IBCS2_EIDRM
block|,
comment|/* 82 */
name|IBCS2_ENOMSG
block|,
comment|/* 83 */
name|IBCS2_EOVERFLOW
block|,
comment|/* 84 */
literal|0
block|,
comment|/* 85 */
name|IBCS2_EILSEQ
block|,
comment|/* 86 */
block|}
decl_stmt|;
end_decl_stmt

end_unit

