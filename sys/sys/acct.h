begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)acct.h	8.4 (Berkeley) 1/9/95  * $Id: acct.h,v 1.8 1997/02/22 09:44:48 peter Exp $  */
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

begin_comment
comment|/*  * Accounting structures; these use a comp_t type which is a 3 bits base 8  * exponent, 13 bit fraction ``floating point'' number.  Units are 1/AHZ  * seconds.  */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|comp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AC_COMM_LEN
value|16
end_define

begin_struct
struct|struct
name|acct
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
name|u_int16_t
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|comp_t
name|ac_io
decl_stmt|;
comment|/* count of IO blocks */
name|dev_t
name|ac_tty
decl_stmt|;
comment|/* controlling tty */
define|#
directive|define
name|AFORK
value|0x01
comment|/* forked but not exec'ed */
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
name|u_int8_t
name|ac_flag
decl_stmt|;
comment|/* accounting flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 1/AHZ is the granularity of the data encoded in the comp_t fields.  * This is not necessarily equal to hz.  */
end_comment

begin_define
define|#
directive|define
name|AHZ
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|acct_process
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

