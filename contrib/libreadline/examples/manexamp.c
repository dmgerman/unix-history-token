begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* manexamp.c -- The examples which appear in the documentation are here. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<readline/readline.h>
end_include

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_expr_stmt
operator|*
name|How
name|to
name|Emulate
name|gets
argument_list|()
operator|*
operator|/
comment|/*                                                                  */
comment|/* **************************************************************** */
comment|/* A static variable for holding the line. */
specifier|static
name|char
operator|*
name|line_read
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
end_comment

begin_function
name|char
modifier|*
name|rl_gets
parameter_list|()
block|{
comment|/* If the buffer has already been allocated, return the memory      to the free pool. */
if|if
condition|(
name|line_read
condition|)
block|{
name|free
argument_list|(
name|line_read
argument_list|)
expr_stmt|;
name|line_read
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
comment|/* Get a line from the user. */
name|line_read
operator|=
name|readline
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* If the line has any text in it, save it on the history. */
if|if
condition|(
name|line_read
operator|&&
operator|*
name|line_read
condition|)
name|add_history
argument_list|(
name|line_read
argument_list|)
expr_stmt|;
return|return
operator|(
name|line_read
operator|)
return|;
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*        Writing a Function to be Called by Readline.              */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Invert the case of the COUNT following characters. */
end_comment

begin_macro
name|invert_case_line
argument_list|(
argument|count
argument_list|,
argument|key
argument_list|)
end_macro

begin_decl_stmt
name|int
name|count
decl_stmt|,
name|key
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
name|start
operator|=
name|rl_point
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|0
condition|)
block|{
name|direction
operator|=
operator|-
literal|1
expr_stmt|;
name|count
operator|=
operator|-
name|count
expr_stmt|;
block|}
else|else
name|direction
operator|=
literal|1
expr_stmt|;
comment|/* Find the end of the range to modify. */
name|end
operator|=
name|start
operator|+
operator|(
name|count
operator|*
name|direction
operator|)
expr_stmt|;
comment|/* Force it to be within range. */
if|if
condition|(
name|end
operator|>
name|rl_end
condition|)
name|end
operator|=
name|rl_end
expr_stmt|;
elseif|else
if|if
condition|(
name|end
operator|<
literal|0
condition|)
name|end
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|start
operator|>
name|end
condition|)
block|{
name|int
name|temp
init|=
name|start
decl_stmt|;
name|start
operator|=
name|end
expr_stmt|;
name|end
operator|=
name|temp
expr_stmt|;
block|}
if|if
condition|(
name|start
operator|==
name|end
condition|)
return|return;
comment|/* Tell readline that we are modifying the line, so save the undo      information. */
name|rl_modifying
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|start
operator|!=
name|end
condition|;
name|start
operator|+=
name|direction
control|)
block|{
if|if
condition|(
name|uppercase_p
argument_list|(
name|rl_line_buffer
index|[
name|start
index|]
argument_list|)
condition|)
name|rl_line_buffer
index|[
name|start
index|]
operator|=
name|to_lower
argument_list|(
name|rl_line_buffer
index|[
name|start
index|]
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|lowercase_p
argument_list|(
name|rl_line_buffer
index|[
name|start
index|]
argument_list|)
condition|)
name|rl_line_buffer
index|[
name|start
index|]
operator|=
name|to_upper
argument_list|(
name|rl_line_buffer
index|[
name|start
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* Move point to on top of the last character changed. */
name|rl_point
operator|=
name|end
operator|-
name|direction
expr_stmt|;
block|}
end_block

end_unit

