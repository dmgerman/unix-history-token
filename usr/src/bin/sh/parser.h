begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)parser.h	8.1 (Berkeley) %G%  */
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

