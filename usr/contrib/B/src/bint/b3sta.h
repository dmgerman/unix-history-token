begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3sta.h,v 1.4 85/08/22 16:48:00 timo Exp $ */
end_comment

begin_undef
undef|#
directive|undef
name|Procedure
end_undef

begin_define
define|#
directive|define
name|Procedure
value|int
end_define

begin_function_decl
name|Procedure
name|v_formal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Procedure
name|l_formal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|parsetree
name|pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'Program counter', current parsetree node */
end_comment

begin_decl_stmt
specifier|extern
name|parsetree
name|next
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next parsetree node (changed by jumps) */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|report
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'Condition code register', outcome of last test */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|noloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set while evaluating (as opposed to locating) 			formal parameters of HOW'TOs */
end_comment

end_unit

