begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * put a string on output stream.  */
end_comment

begin_expr_stmt
name|putstr
argument_list|(
name|f
argument_list|,
name|s
argument_list|,
name|l
argument_list|)
specifier|register
name|FILE
operator|*
name|f
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|l
operator|--
condition|)
name|putc
argument_list|(
operator|*
name|s
operator|++
argument_list|,
name|f
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

