begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)sequal.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  SEQUAL -- string equality test ** **	null-terminated strings `a' and `b' are tested for **		absolute equality. **	returns one if equal, zero otherwise. */
end_comment

begin_function
name|bool
name|sequal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
specifier|register
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
while|while
condition|(
operator|*
name|a
operator|||
operator|*
name|b
condition|)
if|if
condition|(
operator|*
name|a
operator|++
operator|!=
operator|*
name|b
operator|++
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_block

end_unit

