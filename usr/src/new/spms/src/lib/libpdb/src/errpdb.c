begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * errpdb() prints the error message in pdbp->err, or ERRPDB if pdbp is  * null. Clears error message and returns 1.  */
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
name|errpdb
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
comment|/* database stream */
end_comment

begin_block
block|{
specifier|extern
name|char
name|PDBERR
index|[]
decl_stmt|;
comment|/* database error message buffer */
specifier|extern
name|char
modifier|*
name|PGN
decl_stmt|;
comment|/* program name */
if|if
condition|(
name|pdbp
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|PDBERR
operator|!=
literal|'\0'
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|PGN
argument_list|,
name|PDBERR
argument_list|)
expr_stmt|;
operator|*
name|PDBERR
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
operator|*
name|pdbp
operator|->
name|perr
operator|!=
literal|'\0'
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|PGN
argument_list|,
name|pdbp
operator|->
name|perr
argument_list|)
expr_stmt|;
operator|*
name|pdbp
operator|->
name|perr
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

