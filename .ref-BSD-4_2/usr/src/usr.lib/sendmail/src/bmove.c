begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|bmove
operator|.
name|c
literal|4.1
literal|7
operator|/
literal|25
operator|/
literal|83
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* **  BMOVE -- block move. ** **	Parameters: **		s -- source of bytes. **		d -- destination of bytes. **		l -- length of block to move. ** **	Returns: **		none. ** **	Side Effects: **		copies 's' to 'd' for 'l' bytes. ** **	Notes: **		This can be easily written in assembly language on **		machines like VAXes if performance is needed. */
end_comment

begin_comment
comment|/*VARARGS0*/
end_comment

begin_expr_stmt
name|bmove
argument_list|(
name|s
argument_list|,
name|d
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|s
operator|,
operator|*
name|d
expr_stmt|;
end_expr_stmt

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
operator|>
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_block

end_unit

