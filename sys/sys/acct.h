begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)acct.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ACCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ACCT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|float
value|uint32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AC_COMM_LEN
value|16
end_define

begin_comment
comment|/*  * Accounting structure version 3 (current).  * The first byte is always zero.  * Time units are microseconds.  */
end_comment

begin_struct
struct|struct
name|acctv3
block|{
name|uint8_t
name|ac_zero
decl_stmt|;
comment|/* zero identifies new version */
name|uint8_t
name|ac_version
decl_stmt|;
comment|/* record version number */
name|uint16_t
name|ac_len
decl_stmt|;
comment|/* record length */
name|char
name|ac_comm
index|[
name|AC_COMM_LEN
index|]
decl_stmt|;
comment|/* command name */
name|float
name|ac_utime
decl_stmt|;
comment|/* user time */
name|float
name|ac_stime
decl_stmt|;
comment|/* system time */
name|float
name|ac_etime
decl_stmt|;
comment|/* elapsed time */
name|time_t
name|ac_btime
decl_stmt|;
comment|/* starting time */
name|uid_t
name|ac_uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|ac_gid
decl_stmt|;
comment|/* group id */
name|float
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|float
name|ac_io
decl_stmt|;
comment|/* count of IO blocks */
name|__dev_t
name|ac_tty
decl_stmt|;
comment|/* controlling tty */
name|uint32_t
name|ac_pad0
decl_stmt|;
name|uint16_t
name|ac_len2
decl_stmt|;
comment|/* record length */
union|union
block|{
name|uint32_t
name|ac_align
decl_stmt|;
comment|/* force v1 compatible alignment */
define|#
directive|define
name|AFORK
value|0x01
comment|/* forked but not exec'ed */
comment|/* ASU is no longer supported */
define|#
directive|define
name|ASU
value|0x02
comment|/* used super-user permissions */
define|#
directive|define
name|ACOMPAT
value|0x04
comment|/* used compatibility mode */
define|#
directive|define
name|ACORE
value|0x08
comment|/* dumped core */
define|#
directive|define
name|AXSIG
value|0x10
comment|/* killed by a signal */
define|#
directive|define
name|ANVER
value|0x20
comment|/* new record version */
name|uint8_t
name|ac_flag
decl_stmt|;
comment|/* accounting flags */
block|}
name|ac_trailer
union|;
define|#
directive|define
name|ac_flagx
value|ac_trailer.ac_flag
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acctv2
block|{
name|uint8_t
name|ac_zero
decl_stmt|;
comment|/* zero identifies new version */
name|uint8_t
name|ac_version
decl_stmt|;
comment|/* record version number */
name|uint16_t
name|ac_len
decl_stmt|;
comment|/* record length */
name|char
name|ac_comm
index|[
name|AC_COMM_LEN
index|]
decl_stmt|;
comment|/* command name */
name|float
name|ac_utime
decl_stmt|;
comment|/* user time */
name|float
name|ac_stime
decl_stmt|;
comment|/* system time */
name|float
name|ac_etime
decl_stmt|;
comment|/* elapsed time */
name|time_t
name|ac_btime
decl_stmt|;
comment|/* starting time */
name|uid_t
name|ac_uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|ac_gid
decl_stmt|;
comment|/* group id */
name|float
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|float
name|ac_io
decl_stmt|;
comment|/* count of IO blocks */
name|uint32_t
name|ac_tty
decl_stmt|;
comment|/* controlling tty */
name|uint16_t
name|ac_len2
decl_stmt|;
comment|/* record length */
union|union
block|{
name|uint32_t
name|ac_align
decl_stmt|;
comment|/* force v1 compatible alignment */
name|uint8_t
name|ac_flag
decl_stmt|;
comment|/* accounting flags */
block|}
name|ac_trailer
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Legacy accounting structure (rev. 1.5-1.18).  * The first byte is always non-zero.  * Some fields use a comp_t type which is a 3 bits base 8  * exponent, 13 bit fraction ``floating point'' number.  * Units are 1/AHZV1 seconds.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|comp_t
typedef|;
end_typedef

begin_struct
struct|struct
name|acctv1
block|{
name|char
name|ac_comm
index|[
name|AC_COMM_LEN
index|]
decl_stmt|;
comment|/* command name */
name|comp_t
name|ac_utime
decl_stmt|;
comment|/* user time */
name|comp_t
name|ac_stime
decl_stmt|;
comment|/* system time */
name|comp_t
name|ac_etime
decl_stmt|;
comment|/* elapsed time */
name|time_t
name|ac_btime
decl_stmt|;
comment|/* starting time */
name|uid_t
name|ac_uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|ac_gid
decl_stmt|;
comment|/* group id */
name|uint16_t
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|comp_t
name|ac_io
decl_stmt|;
comment|/* count of IO blocks */
name|uint32_t
name|ac_tty
decl_stmt|;
comment|/* controlling tty */
name|uint8_t
name|ac_flag
decl_stmt|;
comment|/* accounting flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 1/AHZV1 is the granularity of the data encoded in the comp_t fields.  * This is not necessarily equal to hz.  */
end_comment

begin_define
define|#
directive|define
name|AHZV1
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|acct_process
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|float
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ACCT_H_ */
end_comment

end_unit

