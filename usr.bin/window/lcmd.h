begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lcmd.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|LCMD_NARG
value|20
end_define

begin_comment
comment|/* maximum number of arguments */
end_comment

begin_struct
struct|struct
name|lcmd_tab
block|{
name|char
modifier|*
name|lc_name
decl_stmt|;
name|int
name|lc_minlen
decl_stmt|;
name|int
function_decl|(
modifier|*
name|lc_func
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|lcmd_arg
modifier|*
name|lc_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lcmd_arg
block|{
name|char
modifier|*
name|arg_name
decl_stmt|;
name|int
name|arg_minlen
decl_stmt|;
name|int
name|arg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* arg_flags bits */
end_comment

begin_define
define|#
directive|define
name|ARG_TYPE
value|0x0f
end_define

begin_comment
comment|/* type of arg */
end_comment

begin_define
define|#
directive|define
name|ARG_ANY
value|0x00
end_define

begin_comment
comment|/* any type */
end_comment

begin_define
define|#
directive|define
name|ARG_NUM
value|0x01
end_define

begin_comment
comment|/* must be a number */
end_comment

begin_define
define|#
directive|define
name|ARG_STR
value|0x02
end_define

begin_comment
comment|/* must be a string */
end_comment

begin_define
define|#
directive|define
name|ARG_LIST
value|0x10
end_define

begin_comment
comment|/* this arg can be a list */
end_comment

begin_function_decl
name|struct
name|lcmd_tab
modifier|*
name|lcmd_lookup
parameter_list|()
function_decl|;
end_function_decl

end_unit

