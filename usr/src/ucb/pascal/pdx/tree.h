begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)tree.h 1.4 2/13/82"; */
end_comment

begin_comment
comment|/*  * This file contains the declarations of the variables and routines  * within the "tree" subdirectory that are accessible from outside.  */
end_comment

begin_include
include|#
directive|include
file|"tree/opinfo.h"
end_include

begin_comment
comment|/*  * Evaluation stack manipulation macros.  These are publically  * available because "eval" leaves it's result on the stack.  *  * These macros allow one to operate on stacks of arbitrary types  * (including a stack of different typed objects).  *  * Sadly, underflow and overflow are not checked for.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|STACK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WMASK
value|(sizeof(int) - 1)
end_define

begin_define
define|#
directive|define
name|push
parameter_list|(
name|type
parameter_list|,
name|value
parameter_list|)
value|((type *) (sp += sizeof(type)))[-1] = (value)
end_define

begin_define
define|#
directive|define
name|pop
parameter_list|(
name|type
parameter_list|)
value|(*((type *) (sp -= sizeof(type))))
end_define

begin_define
define|#
directive|define
name|alignstack
parameter_list|()
value|sp = (char *) (( ((int) sp) + WMASK)&~WMASK)
end_define

begin_decl_stmt
name|STACK
name|stack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STACK
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|NODE
modifier|*
name|build
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* create a node in the parse tree */
end_comment

begin_expr_stmt
name|prtree
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* print a tree in source form */
end_comment

begin_expr_stmt
name|eval
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* evaluate a tree, leaving value on stack */
end_comment

begin_function_decl
name|long
name|popsmall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* pop a small item from the stack given its type */
end_comment

begin_expr_stmt
name|tfree
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* release storage for a tree */
end_comment

begin_function_decl
name|BOOLEAN
name|tr_equal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* test if two trees are structurally equivalent */
end_comment

begin_function_decl
name|BOOLEAN
name|cond
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* evaluate a node for a conditional */
end_comment

begin_function_decl
name|ADDRESS
name|lval
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the object address of a node */
end_comment

begin_function_decl
name|BOOLEAN
name|isredirected
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TRUE if output is being redirected */
end_comment

end_unit

