begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_AUTH
value|0x01
end_define

begin_define
define|#
directive|define
name|LOCAL_NO_AUTH
value|0x02
end_define

begin_define
define|#
directive|define
name|LOCAL_DENY
value|0x03
end_define

begin_define
define|#
directive|define
name|LOCAL_CX
value|0x04
end_define

begin_comment
comment|/* OR'd value - require a context */
end_comment

begin_define
define|#
directive|define
name|LOCAL_CX_OPT
value|0x08
end_define

begin_comment
comment|/* OR'd value - optional context */
end_comment

begin_struct_decl
struct_decl|struct
name|server
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|datalink
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|prompt
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
name|int
name|fd_in
decl_stmt|,
name|fd_out
decl_stmt|;
name|struct
name|datalink
modifier|*
name|TermMode
decl_stmt|;
comment|/* The modem we're talking directly to */
name|FILE
modifier|*
name|Term
decl_stmt|;
comment|/* sits on top of fd_out */
name|u_char
name|auth
decl_stmt|;
comment|/* Local Authorized status */
name|struct
name|server
modifier|*
name|owner
decl_stmt|;
comment|/* who created me */
name|struct
name|bundle
modifier|*
name|bundle
decl_stmt|;
comment|/* who I'm controlling */
name|unsigned
name|nonewline
range|:
literal|1
decl_stmt|;
comment|/* need a newline before our prompt ? */
name|unsigned
name|needprompt
range|:
literal|1
decl_stmt|;
comment|/* Show a prompt at the next UpdateSet() */
name|unsigned
name|active
range|:
literal|1
decl_stmt|;
comment|/* Is the prompt active (^Z) */
name|unsigned
name|readtilde
range|:
literal|1
decl_stmt|;
comment|/* We've read a ``~'' from fd_in */
struct|struct
block|{
specifier|const
name|char
modifier|*
name|type
decl_stmt|;
comment|/* Type of connection */
name|char
name|from
index|[
literal|40
index|]
decl_stmt|;
comment|/* Source of connection */
block|}
name|src
struct|;
name|struct
name|prompt
modifier|*
name|next
decl_stmt|;
comment|/* Maintained in log.c */
name|u_long
name|logmask
decl_stmt|;
comment|/* Maintained in log.c */
name|struct
name|termios
name|oldtio
decl_stmt|;
comment|/* Original tty mode */
name|struct
name|termios
name|comtio
decl_stmt|;
comment|/* Command level tty mode */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2prompt
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == PROMPT_DESCRIPTOR ? (struct prompt *)(d) : NULL)
end_define

begin_define
define|#
directive|define
name|PROMPT_STD
value|(-1)
end_define

begin_function_decl
specifier|extern
name|struct
name|prompt
modifier|*
name|prompt_Create
parameter_list|(
name|struct
name|server
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_Destroy
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_Required
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|prompt_Printf
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|prompt_Printf
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|prompt_vPrintf
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|prompt_vPrintf
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PROMPT_DONT_WANT_INT
value|1
end_define

begin_define
define|#
directive|define
name|PROMPT_WANT_INT
value|0
end_define

begin_function_decl
specifier|extern
name|void
name|prompt_TtyInit
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_TtyCommandMode
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_TtyTermMode
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_TtyOldMode
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|prompt_pgrp
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PasswdCommand
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_Suspend
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|prompt_Continue
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|prompt_IsTermMode
parameter_list|(
name|p
parameter_list|,
name|dl
parameter_list|)
value|((p)->TermMode == (dl) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|prompt_IsController
parameter_list|(
name|p
parameter_list|)
value|(!(p) || (p)->owner ? 0 : 1)
end_define

begin_define
define|#
directive|define
name|prompt_Required
parameter_list|(
name|p
parameter_list|)
value|((p)->needprompt = 1)
end_define

end_unit

