begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TICKUNIT
value|100000
end_define

begin_comment
comment|/* usec's per Unit */
end_comment

begin_define
define|#
directive|define
name|SECTICKS
value|(1000000/TICKUNIT)
end_define

begin_comment
comment|/* Units per second */
end_comment

begin_struct
struct|struct
name|pppTimer
block|{
name|int
name|state
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|u_long
name|rest
decl_stmt|;
comment|/* Ticks to expire */
name|u_long
name|load
decl_stmt|;
comment|/* Initial load value */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* Function called when timer is expired */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* Argument passed to timeout function */
name|struct
name|pppTimer
modifier|*
name|next
decl_stmt|;
comment|/* Link to next timer */
name|struct
name|pppTimer
modifier|*
name|enext
decl_stmt|;
comment|/* Link to next expired timer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIMER_STOPPED
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_EXPIRED
value|2
end_define

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|timer_Start
parameter_list|(
name|struct
name|pppTimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_Stop
parameter_list|(
name|struct
name|pppTimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_InitService
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_TermService
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_Show
parameter_list|(
name|int
name|LogLevel
parameter_list|,
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

