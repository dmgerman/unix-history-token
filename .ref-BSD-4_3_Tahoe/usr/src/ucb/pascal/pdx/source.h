begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)source.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * Definitions for interfacing with source management routines.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cursource
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current source file name */
end_comment

begin_decl_stmt
name|LINENO
name|lastlinenum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last source line number */
end_comment

begin_function_decl
name|int
name|skimsource
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get seek pointers to source lines */
end_comment

begin_function_decl
name|int
name|chkline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* checks to see that a line number is valid */
end_comment

begin_function_decl
name|int
name|printlines
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out from first line to second */
end_comment

end_unit

