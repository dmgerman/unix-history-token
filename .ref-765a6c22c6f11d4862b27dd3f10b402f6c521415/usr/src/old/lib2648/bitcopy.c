begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	bitcopy.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * Copy from msrc to mdest.  * This is done as it is because it would be much slower to do it  * a bit at a time.  */
end_comment

begin_include
include|#
directive|include
file|"bit.h"
end_include

begin_macro
name|bitcopy
argument_list|(
argument|mdest
argument_list|,
argument|msrc
argument_list|,
argument|rows
argument_list|,
argument|cols
argument_list|)
end_macro

begin_decl_stmt
name|bitmat
name|mdest
decl_stmt|,
name|msrc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rows
decl_stmt|,
name|cols
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|size
init|=
operator|(
operator|(
name|cols
operator|+
literal|7
operator|)
operator|>>
literal|3
operator|)
operator|*
name|rows
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
for|for
control|(
name|p
operator|=
operator|&
name|mdest
index|[
name|size
index|]
operator|,
name|q
operator|=
operator|&
name|msrc
index|[
name|size
index|]
init|;
name|p
operator|>=
name|mdest
condition|;
control|)
operator|*
operator|--
name|p
operator|=
operator|*
operator|--
name|q
expr_stmt|;
block|}
end_block

end_unit

