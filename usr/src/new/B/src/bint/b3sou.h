begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3sou.h,v 1.4 85/08/22 16:44:42 timo Exp $ */
end_comment

begin_comment
comment|/* bsou.h: sources */
end_comment

begin_function_decl
name|bool
name|is_unit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enquire if a keyword is a unit */
end_comment

begin_function_decl
name|value
name|permkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get key of b_perm table */
end_comment

begin_function_decl
name|bool
name|p_exists
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enquire if a unit is filed */
end_comment

begin_function_decl
name|value
name|get_pname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get (perm) name of a unit or target */
end_comment

begin_function_decl
name|value
name|tarvalue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* value of target */
end_comment

begin_comment
comment|/* Procedure def_unit(); */
end_comment

begin_comment
comment|/* enter a keyword into the list of units */
end_comment

begin_comment
comment|/* Procedure rem_unit() */
end_comment

begin_comment
comment|/* remove a unit from the internal adm. */
end_comment

begin_comment
comment|/* Procedure p_name_type(); */
end_comment

begin_comment
comment|/* get name and type of a unit or target */
end_comment

begin_comment
comment|/* Procedure special(); */
end_comment

begin_comment
comment|/* execute a special command */
end_comment

begin_comment
comment|/* Procedure vs_ifile(); */
end_comment

begin_comment
comment|/* restore the input file */
end_comment

begin_comment
comment|/* Procedure getprmnv(); */
end_comment

begin_comment
comment|/* create the permanent environment */
end_comment

begin_comment
comment|/* Procedure putprmnv(); */
end_comment

begin_comment
comment|/* output the permanent environment */
end_comment

begin_comment
comment|/* Procedure initsou(); */
end_comment

begin_comment
comment|/* init sources */
end_comment

begin_comment
comment|/* Procedure lst_uhds(); */
end_comment

begin_comment
comment|/* listing of unit headings */
end_comment

end_unit

