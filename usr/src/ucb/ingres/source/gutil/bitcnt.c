begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)bitcnt.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	Count the number of 1's in the integer var. As long **	as left shift is zero fill this routine is machine **	independent. */
end_comment

begin_expr_stmt
name|bitcnt
argument_list|(
name|var
argument_list|)
specifier|register
name|int
name|var
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|ret
decl_stmt|;
for|for
control|(
name|ret
operator|=
literal|0
operator|,
name|i
operator|=
literal|1
init|;
name|i
condition|;
name|i
operator|<<=
literal|1
control|)
if|if
condition|(
name|i
operator|&
name|var
condition|)
name|ret
operator|++
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

end_unit

