begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pblenkey() returns length of key field pointed to by buffer pointer bp.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_expr_stmt
name|pblenkey
argument_list|(
name|bp
argument_list|)
specifier|register
name|char
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* buffer pointer */
end_comment

begin_block
block|{
specifier|register
name|int
name|n
decl_stmt|;
comment|/* length counter */
for|for
control|(
name|n
operator|=
literal|0
init|;
operator|*
name|bp
operator|!=
name|_PBKS
operator|&&
operator|*
name|bp
operator|!=
name|_PBFS
operator|&&
operator|*
name|bp
operator|!=
literal|'\0'
condition|;
name|bp
operator|++
operator|,
name|n
operator|++
control|)
continue|continue;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

