begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)memory.h	5.1 (Berkeley) 85/08/05  */
end_comment

begin_comment
comment|/*  * Definitions of the Sys5 compat memory manipulation routines  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|memccpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|memcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

end_unit

