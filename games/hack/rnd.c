begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rnd.c - version 1.0.2 */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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

begin_macro
name|rn1
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

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

begin_macro
name|rn2
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

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

begin_macro
name|rnd
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

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

begin_macro
name|d
argument_list|(
argument|n
argument_list|,
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|tmp
init|=
name|n
decl_stmt|;
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

