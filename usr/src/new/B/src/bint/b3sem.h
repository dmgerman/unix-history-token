begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3sem.h,v 1.4 85/08/22 16:44:32 timo Exp $ */
end_comment

begin_comment
comment|/* bsem.h: semantics */
end_comment

begin_typedef
typedef|typedef
name|bool
name|outcome
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Und
value|((bool) '?')
end_define

begin_comment
comment|/* absence of REPORTed outcome */
end_comment

begin_comment
comment|/* Locations */
end_comment

begin_function_decl
name|loc
name|local_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|global_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|content
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure check_location(); */
end_comment

begin_function_decl
name|loc
name|trim_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|tbsel_loc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure put(); */
end_comment

begin_comment
comment|/* Procedure putcheck(); */
end_comment

begin_comment
comment|/* Procedure l_delete(); */
end_comment

begin_comment
comment|/* Procedure l_insert(); */
end_comment

begin_comment
comment|/* Procedure l_remove(); */
end_comment

begin_comment
comment|/* Procedure choose(); */
end_comment

begin_comment
comment|/* Procedure draw(); */
end_comment

begin_comment
comment|/* Procedure bind(); */
end_comment

begin_comment
comment|/* Functions and Predicates */
end_comment

begin_function_decl
name|bool
name|is_zerfun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_monfun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_dyafun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_zerprd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_monprd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_dyaprd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure initfpr(); */
end_comment

begin_comment
comment|/* Elaboration: */
end_comment

begin_function_decl
name|value
name|pre_fun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|outcome
name|pre_prop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* B units */
end_comment

begin_decl_stmt
specifier|extern
name|value
name|resval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|terminated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Procedure udfpr(); */
end_comment

begin_function_decl
name|bool
name|ref_com
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure ref_et(); */
end_comment

end_unit

