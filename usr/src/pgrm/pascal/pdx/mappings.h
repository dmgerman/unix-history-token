begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mappings.h	5.2 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Mappings definitions.  *  * The mappings module is the interface between the object code and  * source file representations of the program.  *  * This module is strongly tied to the object module, and needs the  * most of the data defined in "object.h".  */
end_comment

begin_function_decl
name|ADDRESS
name|objaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the object address corresponding to a line */
end_comment

begin_function_decl
name|char
modifier|*
name|srcfilename
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the nearest source file<= a given address */
end_comment

begin_function_decl
name|LINENO
name|srcline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the nearest source line<= a given address */
end_comment

begin_function_decl
name|LINENO
name|linelookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look for a line number with exactly given address */
end_comment

begin_function_decl
name|int
name|newfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* record the appearance of a new function */
end_comment

begin_function_decl
name|SYM
modifier|*
name|whatblock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find the function associated with an address */
end_comment

begin_function_decl
name|int
name|clrfunctab
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* re-initialize function table */
end_comment

end_unit

