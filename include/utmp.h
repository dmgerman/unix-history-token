begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)utmp.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTMP_H_
end_define

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/var/run/utmp"
end_define

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/var/log/wtmp"
end_define

begin_define
define|#
directive|define
name|_PATH_LASTLOG
value|"/var/log/lastlog"
end_define

begin_define
define|#
directive|define
name|UT_NAMESIZE
value|16
end_define

begin_comment
comment|/* see MAXLOGNAME in<sys/param.h> */
end_comment

begin_define
define|#
directive|define
name|UT_LINESIZE
value|8
end_define

begin_define
define|#
directive|define
name|UT_HOSTSIZE
value|16
end_define

begin_struct
struct|struct
name|lastlog
block|{
name|time_t
name|ll_time
decl_stmt|;
name|char
name|ll_line
index|[
name|UT_LINESIZE
index|]
decl_stmt|;
name|char
name|ll_host
index|[
name|UT_HOSTSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|utmp
block|{
name|char
name|ut_line
index|[
name|UT_LINESIZE
index|]
decl_stmt|;
name|char
name|ut_name
index|[
name|UT_NAMESIZE
index|]
decl_stmt|;
name|char
name|ut_host
index|[
name|UT_HOSTSIZE
index|]
decl_stmt|;
name|time_t
name|ut_time
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UTMP_H_ */
end_comment

end_unit

