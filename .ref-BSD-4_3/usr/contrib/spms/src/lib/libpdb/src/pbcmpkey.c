begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbcmpkey() compares keys and returns an integer greater than, equal to,  * or less than 0, depending on whether key is lexicographically greater  * than, equal to, or less than the key field pointed to by bp.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_expr_stmt
name|pbcmpkey
argument_list|(
name|key
argument_list|,
name|bp
argument_list|)
specifier|register
name|char
operator|*
name|key
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* key string */
end_comment

begin_decl_stmt
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer pointer */
end_comment

begin_block
block|{
for|for
control|(
init|;
operator|*
name|key
operator|==
operator|*
name|bp
operator|&&
operator|*
name|key
operator|!=
literal|'\0'
condition|;
name|key
operator|++
operator|,
name|bp
operator|++
control|)
continue|continue;
if|if
condition|(
operator|*
name|key
operator|==
literal|'\0'
operator|&&
operator|(
operator|*
name|bp
operator|==
name|_PBKS
operator|||
operator|*
name|bp
operator|==
name|_PBFS
operator|||
operator|*
name|bp
operator|==
literal|'\0'
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
operator|*
name|key
operator|-
operator|*
name|bp
operator|)
return|;
block|}
end_block

end_unit

