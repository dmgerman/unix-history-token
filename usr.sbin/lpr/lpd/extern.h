begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      From: @(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|scnkey
index|[]
index|[
name|HEIGHT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in lpdchar.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in lpd.c */
end_comment

begin_struct_decl
struct_decl|struct
name|printer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|void
name|printjob
parameter_list|(
name|struct
name|printer
modifier|*
name|_pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startprinting
parameter_list|(
specifier|const
name|char
modifier|*
name|_printer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|recvjob
parameter_list|(
specifier|const
name|char
modifier|*
name|_printer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msearch
parameter_list|(
name|char
modifier|*
name|_str
parameter_list|,
name|struct
name|termios
modifier|*
name|_ip
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

