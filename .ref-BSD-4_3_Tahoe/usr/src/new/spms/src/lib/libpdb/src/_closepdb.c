begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * _closepdb() closes a database without updating. Returns 0 normally, 1  * if database error.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pdb.h"
end_include

begin_macro
name|_closepdb
argument_list|(
argument|pdbp
argument_list|)
end_macro

begin_decl_stmt
name|PDB
modifier|*
name|pdbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* database description pointer	*/
end_comment

begin_block
block|{
name|int
name|errpdb
parameter_list|()
function_decl|;
comment|/* print database error message */
name|int
name|errstat
init|=
literal|0
decl_stmt|;
comment|/* database error status */
name|fclose
argument_list|(
name|pdbp
operator|->
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
name|_PACCESS
operator|)
operator|==
operator|(
name|_PREAD
operator||
name|_PWRITE
operator|)
condition|)
block|{
name|fclose
argument_list|(
name|pdbp
operator|->
name|tfp
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|pdbp
operator|->
name|tpath
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
operator|(
name|_PWRITE
operator||
name|_PAPPEND
operator|)
operator|)
operator|!=
literal|0
condition|)
name|unlink
argument_list|(
name|pdbp
operator|->
name|tpath
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pdbp
operator|->
name|flag
operator|&
name|_PERR
operator|)
operator|!=
literal|0
condition|)
block|{
name|errpdb
argument_list|(
name|pdbp
argument_list|)
expr_stmt|;
name|errstat
operator|=
literal|1
expr_stmt|;
block|}
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pdbp
argument_list|)
expr_stmt|;
return|return
operator|(
name|errstat
operator|)
return|;
block|}
end_block

end_unit

