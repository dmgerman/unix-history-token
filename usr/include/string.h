begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)string.h	5.1 (Berkeley) 85/08/05  */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * these next few are obsolete trash  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpyn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcatn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strcmpn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * and the rest are Sys5 functions supported just so  * Sys5 progs will compile easily.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strpbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strspn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strcspn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strtok
parameter_list|()
function_decl|;
end_function_decl

end_unit

