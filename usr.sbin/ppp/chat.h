begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CHAT_EXPECT
value|0
end_define

begin_define
define|#
directive|define
name|CHAT_SEND
value|1
end_define

begin_define
define|#
directive|define
name|CHAT_DONE
value|2
end_define

begin_define
define|#
directive|define
name|CHAT_FAILED
value|3
end_define

begin_define
define|#
directive|define
name|MAXABORTS
value|50
end_define

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|chat
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
name|struct
name|physical
modifier|*
name|physical
decl_stmt|;
name|int
name|state
decl_stmt|;
comment|/* Our CHAT_* status */
name|char
name|script
index|[
name|LINE_LEN
index|]
decl_stmt|;
comment|/* Our arg buffer */
name|char
modifier|*
name|argv
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* Our arguments (pointing to script) */
name|int
name|argc
decl_stmt|;
comment|/* Number of argv's */
name|int
name|arg
decl_stmt|;
comment|/* Our current arg number */
name|char
name|exp
index|[
name|LINE_LEN
index|]
decl_stmt|;
comment|/* Our translated current argument */
name|char
modifier|*
name|argptr
decl_stmt|;
comment|/* Our current arg pointer */
name|int
name|arglen
decl_stmt|;
comment|/* The length of argptr */
name|char
modifier|*
name|nargptr
decl_stmt|;
comment|/* Our next for expect-send-expect */
name|char
name|buf
index|[
name|LINE_LEN
operator|*
literal|2
index|]
decl_stmt|;
comment|/* Our input */
name|char
modifier|*
name|bufstart
decl_stmt|;
comment|/* start of relevent data */
name|char
modifier|*
name|bufend
decl_stmt|;
comment|/* end of relevent data */
name|int
name|TimeoutSec
decl_stmt|;
comment|/* Expect timeout value */
name|int
name|TimedOut
decl_stmt|;
comment|/* We timed out */
specifier|const
name|char
modifier|*
name|phone
decl_stmt|;
comment|/* Our phone number */
struct|struct
block|{
struct|struct
block|{
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Abort the dial if we get one */
name|int
name|len
decl_stmt|;
block|}
name|string
index|[
name|MAXABORTS
index|]
struct|;
name|int
name|num
decl_stmt|;
comment|/* How many AbortStrings */
block|}
name|abort
struct|;
name|struct
name|pppTimer
name|pause
decl_stmt|;
comment|/* Inactivity timer */
name|struct
name|pppTimer
name|timeout
decl_stmt|;
comment|/* TimeoutSec timer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2chat
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == CHAT_DESCRIPTOR ? (struct chat *)(d) : NULL)
end_define

begin_define
define|#
directive|define
name|VECSIZE
parameter_list|(
name|v
parameter_list|)
value|(sizeof(v) / sizeof(v[0]))
end_define

begin_function_decl
specifier|extern
name|void
name|chat_Init
parameter_list|(
name|struct
name|chat
modifier|*
parameter_list|,
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chat_Setup
parameter_list|(
name|struct
name|chat
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|chat_Finish
parameter_list|(
name|struct
name|chat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|chat_Destroy
parameter_list|(
name|struct
name|chat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

