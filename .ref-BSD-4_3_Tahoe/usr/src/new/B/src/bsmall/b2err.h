begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2err.h,v 1.1 84/06/28 00:48:45 timo Exp $ */
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
name|literal
name|errutype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|main_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|skipping
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|tracing
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Procedure bye(); */
end_comment

end_unit

