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
name|time_t
name|dbg_timenow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|timenow
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|time_t
name|parse8601
parameter_list|(
specifier|const
name|char
modifier|*
name|_srcstr
parameter_list|,
name|time_t
modifier|*
name|_next_time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|parseDWM
parameter_list|(
name|char
modifier|*
name|_srcstr
parameter_list|,
name|time_t
modifier|*
name|_next_time
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

