begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|"../decomp/globs.h"
end_include

begin_include
include|#
directive|include
file|"../ctlmod/pipes.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)startovqp.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	startovqp is called at the beginning of **	the execution of ovqp. */
end_comment

begin_macro
name|startovqp
argument_list|()
end_macro

begin_block
block|{
extern|extern	flptexcep(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|Equel
condition|)
name|startequel
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|De
operator|.
name|ov_tupsfound
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* counts the number of tuples which sat the qual */
end_comment

begin_expr_stmt
name|De
operator|.
name|ov_retrieve
operator|=
name|De
operator|.
name|ov_bopen
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* catch floating point signals */
end_comment

begin_expr_stmt
name|signal
argument_list|(
literal|8
argument_list|,
operator|(
name|int
operator|)
name|flptexcep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* **	Give a user error for a floating point exceptions */
end_comment

begin_expr_stmt
unit|flptexcep
operator|(
operator|)
block|{
name|ov_err
argument_list|(
name|FLOATEXCEP
argument_list|)
block|; }
end_expr_stmt

end_unit

