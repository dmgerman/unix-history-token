begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)parser.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_comment
comment|/* control characters in argument strings */
end_comment

begin_define
define|#
directive|define
name|CTLESC
value|'\201'
end_define

begin_define
define|#
directive|define
name|CTLVAR
value|'\202'
end_define

begin_define
define|#
directive|define
name|CTLENDVAR
value|'\203'
end_define

begin_define
define|#
directive|define
name|CTLBACKQ
value|'\204'
end_define

begin_define
define|#
directive|define
name|CTLQUOTE
value|01
end_define

begin_comment
comment|/* ored with CTLBACKQ code if in quotes */
end_comment

begin_comment
comment|/*	CTLBACKQ | CTLQUOTE == '\205' */
end_comment

begin_define
define|#
directive|define
name|CTLARI
value|'\206'
end_define

begin_define
define|#
directive|define
name|CTLENDARI
value|'\207'
end_define

begin_comment
comment|/* variable substitution byte (follows CTLVAR) */
end_comment

begin_define
define|#
directive|define
name|VSTYPE
value|07
end_define

begin_comment
comment|/* type of variable substitution */
end_comment

begin_define
define|#
directive|define
name|VSNUL
value|040
end_define

begin_comment
comment|/* colon--treat the empty string as unset */
end_comment

begin_define
define|#
directive|define
name|VSQUOTE
value|0100
end_define

begin_comment
comment|/* inside double quotes--suppress splitting */
end_comment

begin_comment
comment|/* values of VSTYPE field */
end_comment

begin_define
define|#
directive|define
name|VSNORMAL
value|1
end_define

begin_comment
comment|/* normal variable:  $var or ${var} */
end_comment

begin_define
define|#
directive|define
name|VSMINUS
value|2
end_define

begin_comment
comment|/* ${var-text} */
end_comment

begin_define
define|#
directive|define
name|VSPLUS
value|3
end_define

begin_comment
comment|/* ${var+text} */
end_comment

begin_define
define|#
directive|define
name|VSQUESTION
value|4
end_define

begin_comment
comment|/* ${var?message} */
end_comment

begin_define
define|#
directive|define
name|VSASSIGN
value|5
end_define

begin_comment
comment|/* ${var=text} */
end_comment

begin_comment
comment|/*  * NEOF is returned by parsecmd when it encounters an end of file.  It  * must be distinct from NULL, so we use the address of a variable that  * happens to be handy.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tokpushback
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NEOF
value|((union node *)&tokpushback)
end_define

begin_decl_stmt
specifier|extern
name|int
name|whichprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 == PS1, 2 == PS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|union
name|node
modifier|*
name|parsecmd
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|goodname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getprompt
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|union
name|node
modifier|*
name|parsecmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|goodname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getprompt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

