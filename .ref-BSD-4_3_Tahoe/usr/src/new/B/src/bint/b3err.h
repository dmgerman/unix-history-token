begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3err.h,v 1.4 85/08/22 16:43:46 timo Exp $ */
end_comment

begin_comment
comment|/* berr.h: B error message handling */
end_comment

begin_decl_stmt
specifier|extern
name|intlet
name|errlino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|value
name|erruname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|parsetree
name|curline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|value
name|curlino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|context
name|how_context
decl_stmt|,
name|act_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|still_ok
decl_stmt|,
name|interrupted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|tracing
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Procedure
name|bye
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure syserr(); */
end_comment

begin_comment
comment|/* Procedure memexh(); */
end_comment

begin_comment
comment|/* Procedure error(); */
end_comment

begin_comment
comment|/* Procedure parerr(); */
end_comment

begin_comment
comment|/* Procedure pprerr(); */
end_comment

begin_comment
comment|/* Procedure checkerr(); */
end_comment

begin_comment
comment|/* Procedure debug(); */
end_comment

begin_comment
comment|/* Procedure trace(); */
end_comment

begin_comment
comment|/* Procedure int_signal(); */
end_comment

end_unit

