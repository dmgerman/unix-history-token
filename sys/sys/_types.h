begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/_types.h>
end_include

begin_comment
comment|/*  * Standard type definitions.  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__blksize_t
typedef|;
end_typedef

begin_comment
comment|/* file block size */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|__blkcnt_t
typedef|;
end_typedef

begin_comment
comment|/* file block count */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|__clockid_t
typedef|;
end_typedef

begin_comment
comment|/* clock_gettime()... */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__fflags_t
typedef|;
end_typedef

begin_comment
comment|/* file flags */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|__fsblkcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__fsfilcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__id_t
typedef|;
end_typedef

begin_comment
comment|/* can hold a gid_t, pid_t, or uid_t */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__ino_t
typedef|;
end_typedef

begin_comment
comment|/* inode number */
end_comment

begin_typedef
typedef|typedef
name|long
name|__key_t
typedef|;
end_typedef

begin_comment
comment|/* IPC key (for Sys V IPC) */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|__lwpid_t
typedef|;
end_typedef

begin_comment
comment|/* Thread ID (a.k.a. LWP) */
end_comment

begin_typedef
typedef|typedef
name|__uint16_t
name|__mode_t
typedef|;
end_typedef

begin_comment
comment|/* permissions */
end_comment

begin_typedef
typedef|typedef
name|int
name|__nl_item
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|__nlink_t
typedef|;
end_typedef

begin_comment
comment|/* link count */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|__off_t
typedef|;
end_typedef

begin_comment
comment|/* file offset */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|__pid_t
typedef|;
end_typedef

begin_comment
comment|/* process [group] */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|__rlim_t
typedef|;
end_typedef

begin_comment
comment|/* resource limit - intentionally */
end_comment

begin_comment
comment|/* signed, because of legacy code */
end_comment

begin_comment
comment|/* that uses -1 for RLIM_INFINITY */
end_comment

begin_typedef
typedef|typedef
name|__uint8_t
name|__sa_family_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__socklen_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|__suseconds_t
typedef|;
end_typedef

begin_comment
comment|/* microseconds (signed) */
end_comment

begin_typedef
typedef|typedef
name|struct
name|__timer
modifier|*
name|__timer_t
typedef|;
end_typedef

begin_comment
comment|/* timer_gettime()... */
end_comment

begin_typedef
typedef|typedef
name|struct
name|__mq
modifier|*
name|__mqd_t
typedef|;
end_typedef

begin_comment
comment|/* mq_open()... */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__useconds_t
typedef|;
end_typedef

begin_comment
comment|/* microseconds (unsigned) */
end_comment

begin_comment
comment|/*  * Unusual type definitions.  */
end_comment

begin_comment
comment|/*  * rune_t is declared to be an ``int'' instead of the more natural  * ``unsigned long'' or ``long''.  Two things are happening here.  It is not  * unsigned so that EOF (-1) can be naturally assigned to it and used.  Also,  * it looks like 10646 will be a 31 bit standard.  This means that if your  * ints cannot hold 32 bits, you will be in trouble.  The reason an int was  * chosen over a long is that the is*() and to*() routines take ints (says  * ANSI C), but they use __ct_rune_t instead of int.  *  * NOTE: rune_t is not covered by ANSI nor other standards, and should not  * be instantiated outside of lib/libc/locale.  Use wchar_t.  wchar_t and  * rune_t must be the same type.  Also, wint_t must be no narrower than  * wchar_t, and should be able to hold all members of the largest  * character set plus one extra value (WEOF), and must be at least 16 bits.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|__ct_rune_t
typedef|;
end_typedef

begin_comment
comment|/* arg type for ctype funcs */
end_comment

begin_typedef
typedef|typedef
name|__ct_rune_t
name|__rune_t
typedef|;
end_typedef

begin_comment
comment|/* rune_t (see above) */
end_comment

begin_typedef
typedef|typedef
name|__ct_rune_t
name|__wchar_t
typedef|;
end_typedef

begin_comment
comment|/* wchar_t (see above) */
end_comment

begin_typedef
typedef|typedef
name|__ct_rune_t
name|__wint_t
typedef|;
end_typedef

begin_comment
comment|/* wint_t (see above) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__dev_t
typedef|;
end_typedef

begin_comment
comment|/* device number */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__fixpt_t
typedef|;
end_typedef

begin_comment
comment|/* fixed point number */
end_comment

begin_comment
comment|/*  * mbstate_t is an opaque object to keep conversion state during multibyte  * stream conversions.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|__mbstate8
index|[
literal|128
index|]
decl_stmt|;
name|__int64_t
name|_mbstateL
decl_stmt|;
comment|/* for alignment */
block|}
name|__mbstate_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__TYPES_H_ */
end_comment

end_unit

