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
argument|@(#)bequal.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  BLOCK EQUALITY TEST ** **	blocks `a' and `b', both of length `l', are tested **		for absolute equality. **	Returns one for equal, zero otherwise. */
end_comment

begin_function
name|bool
name|bequal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|l
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

