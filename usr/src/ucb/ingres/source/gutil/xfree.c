begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)xfree.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  XFREE -- free memory only if dynamically allocated. ** **	This acts just like "free", except that it does nothing **	if the area handed to it hasn't been dynamically allocated. ** **	Parameters: **		p -- a pointer to the area to free. ** **	Returns: **		none. ** **	Side Effects: **		Free memory queue is changed. ** **	WARNING: **		This routine depends on the implementation of malloc **		in C; it may have to be changed on other systems. */
end_comment

begin_macro
name|xfree
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|char
name|end
index|[]
decl_stmt|;
if|if
condition|(
name|p
operator|>=
name|end
operator|&&
name|p
operator|<
operator|(
name|char
operator|*
operator|)
operator|&
name|p
condition|)
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

