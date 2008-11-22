begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Gordon W. Ross  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: clock_subr.h,v 1.7 2000/10/03 13:41:07 tsutsui Exp $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CLOCK_H_
end_define

begin_comment
comment|/*  * Structure to hold the values typically reported by time-of-day clocks.  * This can be passed to the generic conversion functions to be converted  * to a struct timespec.  */
end_comment

begin_struct
struct|struct
name|clocktime
block|{
name|int
name|year
decl_stmt|;
comment|/* year - 1900 */
name|int
name|mon
decl_stmt|;
comment|/* month (1 - 12) */
name|int
name|day
decl_stmt|;
comment|/* day (1 - 31) */
name|int
name|hour
decl_stmt|;
comment|/* hour (0 - 23) */
name|int
name|min
decl_stmt|;
comment|/* minute (0 - 59) */
name|int
name|sec
decl_stmt|;
comment|/* second (0 - 59) */
name|int
name|dow
decl_stmt|;
comment|/* day of week (0 - 6; 0 = Sunday) */
name|long
name|nsec
decl_stmt|;
comment|/* nano seconds */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|clock_ct_to_ts
parameter_list|(
name|struct
name|clocktime
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clock_ts_to_ct
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|clocktime
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clock_register
parameter_list|(
name|device_t
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * BCD to decimal and decimal to BCD.  */
end_comment

begin_define
define|#
directive|define
name|FROMBCD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4) * 10 + ((x)& 0xf))
end_define

begin_define
define|#
directive|define
name|TOBCD
parameter_list|(
name|x
parameter_list|)
value|(((x) / 10 * 16) + ((x) % 10))
end_define

begin_comment
comment|/* Some handy constants. */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|(24 * 60 * 60)
end_define

begin_define
define|#
directive|define
name|SECYR
value|(SECDAY * 365)
end_define

begin_comment
comment|/* Traditional POSIX base year */
end_comment

begin_define
define|#
directive|define
name|POSIX_BASE_YEAR
value|1970
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CLOCK_H_ */
end_comment

end_unit

