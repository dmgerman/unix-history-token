begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2par.h,v 1.4 85/08/22 16:42:58 timo Exp $ */
end_comment

begin_comment
comment|/* General definitions for the parser */
end_comment

begin_comment
comment|/* contexts: */
end_comment

begin_define
define|#
directive|define
name|In_share
value|'s'
end_define

begin_define
define|#
directive|define
name|In_ranger
value|'q'
end_define

begin_define
define|#
directive|define
name|In_ref
value|'r'
end_define

begin_comment
comment|/* Expressions: */
end_comment

begin_function_decl
name|parsetree
name|expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|parsetree
name|singexpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tag_operator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_b_tag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure selection(); */
end_comment

begin_comment
comment|/* Targets: */
end_comment

begin_function_decl
name|parsetree
name|targ
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure tar_trimmed_text(); */
end_comment

begin_comment
comment|/* Tests: */
end_comment

begin_function_decl
name|parsetree
name|test
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|parsetree
name|unp_test
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|dya_proposition
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Commands: */
end_comment

begin_function_decl
name|parsetree
name|cmd_suite
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure suite_command(); */
end_comment

begin_function_decl
name|bool
name|simple_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|control_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|term_com
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_comment
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|tail_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* B units */
end_comment

begin_function_decl
name|parsetree
name|unit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|unit_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|parsetree
name|collateral
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|parsetree
name|compound
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|parsetree
name|idf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|literal
name|idf_cntxt
decl_stmt|;
end_decl_stmt

end_unit

