begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3int.h,v 1.4 85/08/22 16:44:13 timo Exp $ */
end_comment

begin_comment
comment|/* Interpreter */
end_comment

begin_function_decl
name|value
name|evalthread
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure execthread(); */
end_comment

begin_function_decl
name|value
name|pop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure push(); */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|tracing
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Thread
parameter_list|(
name|t
parameter_list|)
value|*Branch(t, Nbranches(t))
end_define

begin_comment
comment|/* Next instruction */
end_comment

begin_define
define|#
directive|define
name|Thread2
parameter_list|(
name|t
parameter_list|)
value|*Branch(t, Nbranches(t)+1)
end_define

begin_comment
comment|/* Alternate next instr. or flag */
end_comment

begin_define
define|#
directive|define
name|Stop
value|((parsetree)zero)
end_define

begin_comment
comment|/* Legal stop */
end_comment

begin_define
define|#
directive|define
name|Halt
value|NilTree
end_define

begin_comment
comment|/* Illegal stop (loose end of code) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|call_level
decl_stmt|;
end_decl_stmt

end_unit

