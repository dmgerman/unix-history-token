begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2sou.h,v 1.1 84/06/28 00:48:51 timo Exp $ */
end_comment

begin_comment
comment|/* bsou.h: sources */
end_comment

begin_decl_stmt
specifier|extern
name|value
name|aster
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|unit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get a new unit */
end_comment

begin_function_decl
name|bool
name|is_unit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*enquire if a keyword is a unit */
end_comment

begin_comment
comment|/* Procedure def_unit(); */
end_comment

begin_comment
comment|/*enter a keyword into the list of units*/
end_comment

begin_function_decl
name|value
name|unit_info
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*retrieve the details of a unit*/
end_comment

begin_comment
comment|/* Procedure special(); */
end_comment

begin_comment
comment|/*execute a special command*/
end_comment

begin_comment
comment|/* Procedure vs_ifile(); */
end_comment

begin_comment
comment|/*restore the input file*/
end_comment

begin_function_decl
name|bool
name|is_tloaded
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*ensure a permanent target is loaded*/
end_comment

begin_comment
comment|/* Procedure getval(); */
end_comment

begin_comment
comment|/*get a value from a file*/
end_comment

begin_comment
comment|/* Procedure getprmnv(); */
end_comment

begin_comment
comment|/*create the permanent environment*/
end_comment

begin_comment
comment|/* Procedure putprmnv(); */
end_comment

begin_comment
comment|/*output the permanent environment*/
end_comment

begin_comment
comment|/* Procedure initsou(); */
end_comment

end_unit

