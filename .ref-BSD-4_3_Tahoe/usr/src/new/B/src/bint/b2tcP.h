begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2tcP.h,v 1.4 85/08/22 16:43:20 timo Exp $ */
end_comment

begin_comment
comment|/* polytype representation */
end_comment

begin_typedef
typedef|typedef
name|value
name|typekind
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value
name|polytype
typedef|;
end_typedef

begin_comment
comment|/* accessing, NOT giving new values */
end_comment

begin_function_decl
name|typekind
name|kind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|intlet
name|nsubtypes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|polytype
name|subtype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u, intlet i */
end_comment

begin_function_decl
name|polytype
name|asctype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|polytype
name|keytype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|value
name|ident
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_comment
comment|/* MaKe Types, where subtypes are "eaten" */
end_comment

begin_function_decl
name|polytype
name|mkt_polytype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k; intlet nsub */
end_comment

begin_comment
comment|/* visible only in bunif.c */
end_comment

begin_comment
comment|/* Procedure putsubtype(); */
end_comment

begin_comment
comment|/* polytype sub, *pcomp; intlet isub */
end_comment

begin_comment
comment|/* to be used after mkt_polytype or 				 * mkt_compound */
end_comment

begin_function_decl
name|polytype
name|mkt_number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|polytype
name|mkt_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|polytype
name|mkt_tn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|polytype
name|mkt_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|polytype
name|mkt_list
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype s */
end_comment

begin_function_decl
name|polytype
name|mkt_table
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype k, a */
end_comment

begin_function_decl
name|polytype
name|mkt_lt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype s */
end_comment

begin_function_decl
name|polytype
name|mkt_tlt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype s */
end_comment

begin_comment
comment|/* next to be used with putsubtype() calls */
end_comment

begin_function_decl
name|polytype
name|mkt_compound
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* intlet nsub */
end_comment

begin_function_decl
name|polytype
name|mkt_var
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* value id */
end_comment

begin_function_decl
name|polytype
name|mkt_newvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|polytype
name|p_copy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_comment
comment|/* Procedure p_release(); */
end_comment

begin_comment
comment|/* polytype u */
end_comment

begin_comment
comment|/* predicates */
end_comment

begin_function_decl
name|bool
name|are_same_types
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u, v */
end_comment

begin_function_decl
name|bool
name|have_same_structure
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u, v */
end_comment

begin_function_decl
name|bool
name|t_is_number
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_text
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_tn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_list
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_table
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_lt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_tlt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_compound
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|t_is_var
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|has_number
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|has_text
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_function_decl
name|bool
name|has_lt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* typekind k */
end_comment

begin_comment
comment|/* typetable */
end_comment

begin_comment
comment|/* Procedure repl_type_of(); */
end_comment

begin_comment
comment|/* polytype u, tu */
end_comment

begin_function_decl
name|bool
name|table_has_type_of
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|polytype
name|type_of
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_function_decl
name|polytype
name|bottom_var
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* polytype u */
end_comment

begin_comment
comment|/* Procedure usetypetable(); */
end_comment

begin_comment
comment|/* value t */
end_comment

begin_comment
comment|/* Procedure deltypetable(); */
end_comment

begin_comment
comment|/* init */
end_comment

begin_comment
comment|/* Procedure initpol(); */
end_comment

begin_comment
comment|/* */
end_comment

end_unit

