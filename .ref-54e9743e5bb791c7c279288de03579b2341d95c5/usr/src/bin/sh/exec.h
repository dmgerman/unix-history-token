begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* values of cmdtype */
end_comment

begin_define
define|#
directive|define
name|CMDUNKNOWN
value|-1
end_define

begin_comment
comment|/* no entry in table for command */
end_comment

begin_define
define|#
directive|define
name|CMDNORMAL
value|0
end_define

begin_comment
comment|/* command is an executable program */
end_comment

begin_define
define|#
directive|define
name|CMDBUILTIN
value|1
end_define

begin_comment
comment|/* command is a shell builtin */
end_comment

begin_define
define|#
directive|define
name|CMDFUNCTION
value|2
end_define

begin_comment
comment|/* command is a shell function */
end_comment

begin_struct
struct|struct
name|cmdentry
block|{
name|int
name|cmdtype
decl_stmt|;
union|union
name|param
block|{
name|int
name|index
decl_stmt|;
name|union
name|node
modifier|*
name|func
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pathopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by padvance */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|shellexec
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|padvance
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|find_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|cmdentry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_builtin
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hashcd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|changepath
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defun
parameter_list|(
name|char
modifier|*
parameter_list|,
name|union
name|node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetfunc
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|shellexec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|padvance
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|find_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_builtin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hashcd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|changepath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetfunc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

