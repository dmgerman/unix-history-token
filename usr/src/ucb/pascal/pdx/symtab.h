begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)symtab.h 1.2 1/18/82"; */
end_comment

begin_comment
comment|/*  * Public definitions for symbol table.  */
end_comment

begin_decl_stmt
name|SYMTAB
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_function_decl
name|SYMTAB
modifier|*
name|st_creat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* create a symbol table */
end_comment

begin_expr_stmt
name|st_destroy
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* destroy a symbol table, i.e. free storage */
end_comment

begin_function_decl
name|SYM
modifier|*
name|st_insert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* insert a symbol */
end_comment

begin_function_decl
name|SYM
modifier|*
name|st_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* lookup a symbol */
end_comment

begin_expr_stmt
name|dumpvars
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* dump the symbols of a function */
end_comment

begin_expr_stmt
name|print_alias
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* print out currently active aliases */
end_comment

begin_expr_stmt
name|enter_alias
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* create a new name for a command */
end_comment

begin_function_decl
name|SYM
modifier|*
name|findtype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* search symbol table for a type name */
end_comment

end_unit

