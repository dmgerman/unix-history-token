begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bthidcontrol.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: bthidcontrol.h,v 1.1 2004/02/12 23:25:51 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BTHIDCONTROL_H__
end_ifndef

begin_define
define|#
directive|define
name|__BTHIDCONTROL_H__
end_define

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_comment
comment|/* everything was OK */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_comment
comment|/* could not execute command */
end_comment

begin_define
define|#
directive|define
name|FAILED
value|2
end_define

begin_comment
comment|/* error was reported */
end_comment

begin_define
define|#
directive|define
name|USAGE
value|3
end_define

begin_comment
comment|/* invalid parameters */
end_comment

begin_struct
struct|struct
name|bthid_command
block|{
name|char
specifier|const
modifier|*
name|command
decl_stmt|;
name|char
specifier|const
modifier|*
name|description
decl_stmt|;
name|int
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|bdaddr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bthid_command
name|hid_commands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bthid_command
name|sdp_commands
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BTHIDCONTROL_H__ */
end_comment

end_unit

