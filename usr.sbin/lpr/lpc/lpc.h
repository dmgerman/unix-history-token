begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lpc.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Line Printer Control (lpc) program.  */
end_comment

begin_struct_decl
struct_decl|struct
name|printer
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|LPC_PRIVCMD
value|0x0001
end_define

begin_comment
comment|/* a privileged command */
end_comment

begin_define
define|#
directive|define
name|LPC_MSGOPT
value|0x0002
end_define

begin_comment
comment|/* command recognizes -msg option */
end_comment

begin_struct
struct|struct
name|cmd
block|{
specifier|const
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* command name */
specifier|const
name|char
modifier|*
name|c_help
decl_stmt|;
comment|/* help message */
specifier|const
name|int
name|c_opts
decl_stmt|;
comment|/* flags (eg: privileged command) */
comment|/* routine to do all the work for plain cmds, or 		 * initialization work for generic-printer cmds: */
name|void
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
comment|/* routine to do the work for generic-printer cmds: */
name|void
function_decl|(
modifier|*
name|c_generic
function_decl|)
parameter_list|(
name|struct
name|printer
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

