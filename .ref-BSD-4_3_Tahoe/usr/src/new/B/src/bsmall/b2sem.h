begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2sem.h,v 1.1 84/06/28 00:48:50 timo Exp $ */
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
name|Succ
value|Yes
end_define

begin_define
define|#
directive|define
name|Fail
value|No
end_define

begin_define
define|#
directive|define
name|Und
value|((bool) '?')
end_define

begin_comment
comment|/* absence of REPORTed outcome */
end_comment

begin_define
define|#
directive|define
name|Ifxeq
parameter_list|(
name|v
parameter_list|)
value|(xeq ? (v) : Dumval)
end_define

begin_decl_stmt
specifier|extern
name|bool
name|xeq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|envtab
name|prmnvtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|envchain
name|prmnvchain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|env
name|prmnv
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|value
name|montor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|dyator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|formula
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|outcome
name|proposition
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure initfprs(); */
end_comment

begin_comment
comment|/* Expressions: */
end_comment

begin_function_decl
name|value
name|expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|obasexpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|constant
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|conversion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure trimbc(); */
end_comment

begin_comment
comment|/* Procedure inittors(); */
end_comment

begin_comment
comment|/* Targets: */
end_comment

begin_function_decl
name|loc
name|targ
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|bastarg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Tests: */
end_comment

begin_function_decl
name|outcome
name|test
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|relop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|outcome
name|comparison
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Commands: */
end_comment

begin_comment
comment|/* Procedure command(); */
end_comment

begin_comment
comment|/* Procedure comm_suite(); */
end_comment

begin_comment
comment|/* Procedure initcom(); */
end_comment

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
name|outcome
name|resout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|terminated
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|unit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure getunit(); */
end_comment

begin_comment
comment|/* Procedure ytu_heading(); */
end_comment

begin_function_decl
name|bool
name|udc
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|value
name|eva_formal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|loc
name|loc_formal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure inithow(); */
end_comment

end_unit

