begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ------+---------+---------+---------+---------+---------+---------+---------*  * Copyright (c) 2003  - Garance Alistair Drosehn<gad@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation  * are those of the authors and should not be interpreted as representing  * official policies, either expressed or implied, of the FreeBSD Project.  *  * ------+---------+---------+---------+---------+---------+---------+---------*  * $FreeBSD$  * ------+---------+---------+---------+---------+---------+---------+---------*  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_define
define|#
directive|define
name|PTM_PARSE_ISO8601
value|0x0001
end_define

begin_comment
comment|/* Parse ISO-standard format */
end_comment

begin_define
define|#
directive|define
name|PTM_PARSE_DWM
value|0x0002
end_define

begin_comment
comment|/* Parse Day-Week-Month format */
end_comment

begin_define
define|#
directive|define
name|PTM_PARSE_MATCHDOM
value|0x0004
end_define

begin_comment
comment|/* If the user specifies a day-of-month, 					 * then the result should be a month 					 * which actually has that day.  Eg: 					 * the user requests "day 31" when 					 * the present month is February. */
end_comment

begin_struct_decl
struct_decl|struct
name|ptime_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* Some global variables from newsyslog.c which might be of interest */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dbg_at_times
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cmdline debugging option */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|noaction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command-line option */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command-line option */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ptime_data
modifier|*
name|dbg_timenow
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|ptime_data
modifier|*
name|ptime_init
parameter_list|(
specifier|const
name|struct
name|ptime_data
modifier|*
name|_optsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptime_adjust4dst
parameter_list|(
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|,
specifier|const
name|struct
name|ptime_data
modifier|*
name|_dstsrc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptime_free
parameter_list|(
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptime_relparse
parameter_list|(
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|,
name|int
name|_parseopts
parameter_list|,
name|time_t
name|_basetime
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ptimeget_ctime
parameter_list|(
specifier|const
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ptimeget_ctime_rfc5424
parameter_list|(
specifier|const
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|,
name|char
modifier|*
name|timebuf
parameter_list|,
name|size_t
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ptimeget_diff
parameter_list|(
specifier|const
name|struct
name|ptime_data
modifier|*
name|_minuend
parameter_list|,
specifier|const
name|struct
name|ptime_data
modifier|*
name|_subtrahend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|ptimeget_secs
parameter_list|(
specifier|const
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptimeset_nxtime
parameter_list|(
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptimeset_time
parameter_list|(
name|struct
name|ptime_data
modifier|*
name|_ptime
parameter_list|,
name|time_t
name|_secs
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

