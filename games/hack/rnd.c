begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rnd.c - version 1.0.2 */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|RND
parameter_list|(
name|x
parameter_list|)
value|(random() % x)
end_define

begin_expr_stmt
name|rn1
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
specifier|register
name|x
operator|,
name|y
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|RND
argument_list|(
name|x
argument_list|)
operator|+
name|y
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|rn2
argument_list|(
name|x
argument_list|)
specifier|register
name|x
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|RND
argument_list|(
name|x
argument_list|)
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|rnd
argument_list|(
name|x
argument_list|)
specifier|register
name|x
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|RND
argument_list|(
name|x
argument_list|)
operator|+
literal|1
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|d
argument_list|(
name|n
argument_list|,
name|x
argument_list|)
specifier|register
name|n
operator|,
name|x
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|tmp
operator|=
name|n
expr_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
name|tmp
operator|+=
name|RND
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|tmp
operator|)
return|;
block|}
end_block

end_unit

