begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * hthash() returns a hash value for string, s.  */
end_comment

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_expr_stmt
name|hthash
argument_list|(
name|s
argument_list|,
name|hash
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* string */
end_comment

begin_decl_stmt
name|HASH
modifier|*
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table */
end_comment

begin_block
block|{
specifier|register
name|int
name|hashval
decl_stmt|;
comment|/* hash value for string */
for|for
control|(
name|hashval
operator|=
literal|0
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
name|hashval
operator|+=
operator|*
name|s
expr_stmt|;
return|return
operator|(
name|hashval
operator|%
name|hash
operator|->
name|hashsiz
operator|)
return|;
block|}
end_block

end_unit

