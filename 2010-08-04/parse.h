begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: parse.h,v 1.7 2009/12/30 22:37:40 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)parse.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * el.parse.h: Parser functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_parse
end_ifndef

begin_define
define|#
directive|define
name|_h_el_parse
end_define

begin_function_decl
name|protected
name|int
name|parse_line
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|parse__escape
parameter_list|(
specifier|const
name|Char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|Char
modifier|*
name|parse__string
parameter_list|(
name|Char
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|parse_cmd
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|Char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_parse */
end_comment

end_unit

