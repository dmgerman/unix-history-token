begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)clrmem.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  CLRMEM -- clear a block of memory ** **	A block of memory is set to zero.  If we use assembly **	language, this can be potentially very fast. ** **	Parameters: **		p -- a pointer to the area to be cleared. **		l -- the length of the area in bytes. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Trace Flags: **		none */
end_comment

begin_expr_stmt
name|clrmem
argument_list|(
name|p
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|p
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
name|p
operator|++
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

