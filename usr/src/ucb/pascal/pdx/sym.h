begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)sym.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * This header file declares the variables and routines that  * are defined within the "sym" subdirectory and that can be  * accessed from outside.  */
end_comment

begin_decl_stmt
name|SYM
modifier|*
name|program
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * attributes  */
end_comment

begin_function_decl
name|char
modifier|*
name|name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* symbol string name */
end_comment

begin_function_decl
name|char
modifier|*
name|classname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* class name of a symbol */
end_comment

begin_function_decl
name|int
name|toknum
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* token number of reserved word */
end_comment

begin_function_decl
name|int
name|tokval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* associated token value */
end_comment

begin_function_decl
name|int
name|size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* size in bytes of a type */
end_comment

begin_function_decl
name|SYM
modifier|*
name|rtype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* the reduced type, i.e. no type names */
end_comment

begin_function_decl
name|SYM
modifier|*
name|container
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* symbol (block) that contains given symbol */
end_comment

begin_function_decl
name|ADDRESS
name|codeloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address of the beginning of a function */
end_comment

begin_comment
comment|/*  * predicates  */
end_comment

begin_function_decl
name|BOOLEAN
name|isblock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol is a block name */
end_comment

begin_function_decl
name|BOOLEAN
name|isbuiltin
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol is a builtin type */
end_comment

begin_function_decl
name|BOOLEAN
name|isparam
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol is a parameter */
end_comment

begin_function_decl
name|BOOLEAN
name|isvarparam
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol is a var parameter */
end_comment

begin_function_decl
name|BOOLEAN
name|isvariable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol is a variable */
end_comment

begin_function_decl
name|BOOLEAN
name|isambiguous
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol name is not unique */
end_comment

begin_function_decl
name|BOOLEAN
name|compatible
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test to see if two types are compatible */
end_comment

begin_function_decl
name|BOOLEAN
name|should_print
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if a symbol should be printed */
end_comment

begin_function_decl
name|SYM
modifier|*
name|readsym
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read in a symbol from object file */
end_comment

begin_function_decl
name|SYM
modifier|*
name|which
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find the appropriate symbol of given name */
end_comment

begin_function_decl
name|SYM
modifier|*
name|findsym
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find a symbol for a given block */
end_comment

begin_function_decl
name|SYM
modifier|*
name|findclass
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find symbol with given class */
end_comment

begin_function_decl
name|NODE
modifier|*
name|dot
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* construct a tree for the dot operator */
end_comment

begin_function_decl
name|NODE
modifier|*
name|subscript
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* construct a tree for subscripting */
end_comment

begin_function_decl
name|SYM
modifier|*
name|treetype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the type of a tree, checking also */
end_comment

begin_function_decl
name|long
name|evalindex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* evaluate a subscript index */
end_comment

begin_function_decl
name|int
name|unmkstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* free a constant string type */
end_comment

begin_function_decl
name|int
name|chkboolean
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* check if a tree is boolean-valued */
end_comment

begin_function_decl
name|int
name|printdecl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out a symbol's declaration */
end_comment

begin_function_decl
name|int
name|printparams
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print out values of a fn's parameters */
end_comment

begin_function_decl
name|int
name|printentry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* note entrance of a block */
end_comment

begin_function_decl
name|int
name|printexit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* note exiting from a block */
end_comment

begin_function_decl
name|int
name|printcall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* note call of a function */
end_comment

begin_function_decl
name|int
name|printval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print an eval result */
end_comment

begin_function_decl
name|int
name|printv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print the name and value of a variable */
end_comment

begin_function_decl
name|int
name|printwhich
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print the full "path" of an identifier */
end_comment

begin_function_decl
name|int
name|maketypes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize basic types */
end_comment

begin_function_decl
name|int
name|make_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* create a keyword in a given symbol table */
end_comment

end_unit

