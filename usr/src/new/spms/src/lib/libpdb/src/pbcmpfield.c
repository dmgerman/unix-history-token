begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbcmpfield() compares non-key fields and returns an integer greater than,  * equal to, or less than 0, depending on whether field is lexicographically  * greater than, equal to, or less than the non-key field pointed to by bp.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_expr_stmt
name|pbcmpfield
argument_list|(
name|field
argument_list|,
name|bp
argument_list|)
specifier|register
name|char
operator|*
name|field
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* field string */
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
name|field
operator|==
operator|*
name|bp
operator|&&
operator|*
name|field
operator|!=
literal|'\0'
condition|;
name|field
operator|++
operator|,
name|bp
operator|++
control|)
continue|continue;
if|if
condition|(
operator|*
name|field
operator|==
literal|'\0'
operator|&&
operator|(
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
name|field
operator|-
operator|*
name|bp
operator|)
return|;
block|}
end_block

end_unit

