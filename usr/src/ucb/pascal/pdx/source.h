begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)source.h 1.2 1/18/82"; */
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

begin_expr_stmt
name|skimsource
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get seek pointers to source lines */
end_comment

begin_expr_stmt
name|chkline
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* checks to see that a line number is valid */
end_comment

begin_expr_stmt
name|printlines
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* print out from first line to second */
end_comment

end_unit

