begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Functions which manipulate the command buffer.  * Used only by command() and related functions.  */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|erase_char
decl_stmt|,
name|kill_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sc_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|cmdbuf
index|[
literal|120
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for holding a multi-char command */
end_comment

begin_decl_stmt
specifier|static
name|int
name|cmd_col
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current column of the multi-char command */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer into cmdbuf */
end_comment

begin_comment
comment|/*  * Reset command buffer (to empty).  */
end_comment

begin_function
name|public
name|void
name|cmd_reset
parameter_list|()
block|{
name|cp
operator|=
name|cmdbuf
expr_stmt|;
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
name|cmd_col
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * How many characters are in the command buffer?  */
end_comment

begin_function
name|public
name|int
name|len_cmdbuf
parameter_list|()
block|{
return|return
operator|(
name|cp
operator|-
name|cmdbuf
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Backspace in the command buffer.  */
end_comment

begin_function
name|public
name|int
name|cmd_erase
parameter_list|()
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|cp
operator|==
name|cmdbuf
condition|)
comment|/* 		 * Backspace past beginning of the string: 		 * this usually means abort the command. 		 */
return|return
operator|(
literal|1
operator|)
return|;
operator|--
name|cp
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
name|ESC
condition|)
name|s
operator|=
literal|"ESC"
expr_stmt|;
else|else
name|s
operator|=
name|prchar
argument_list|(
operator|*
name|cp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|++
operator|!=
literal|'\0'
condition|)
block|{
name|backspace
argument_list|()
expr_stmt|;
name|cmd_col
operator|--
expr_stmt|;
block|}
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process a single character of a multi-character command, such as  * a number, or the pattern of a search command.  */
end_comment

begin_function
name|public
name|int
name|cmd_char
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|c
operator|==
name|erase_char
condition|)
block|{
if|if
condition|(
name|cmd_erase
argument_list|()
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|kill_char
condition|)
block|{
comment|/* {{ Could do this faster, but who cares? }} */
while|while
condition|(
name|cmd_erase
argument_list|()
operator|==
literal|0
condition|)
empty_stmt|;
block|}
elseif|else
if|if
condition|(
name|cp
operator|>=
operator|&
name|cmdbuf
index|[
sizeof|sizeof
argument_list|(
name|cmdbuf
argument_list|)
operator|-
literal|1
index|]
condition|)
block|{
comment|/* 		 * No room in the command buffer. 		 */
name|bell
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cmd_col
operator|>=
name|sc_width
operator|-
literal|4
condition|)
block|{
comment|/* 		 * No room on the screen. 		 * {{ Could get fancy here; maybe shift the displayed 		 *    line and make room for more chars, like ksh. }} 		 */
name|bell
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * Append the character to the string. 		 */
operator|*
name|cp
operator|++
operator|=
name|c
expr_stmt|;
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
name|s
operator|=
literal|"ESC"
expr_stmt|;
else|else
name|s
operator|=
name|prchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|cmd_col
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return the number currently in the command buffer.  */
end_comment

begin_function
name|public
name|int
name|cmd_int
parameter_list|()
block|{
return|return
operator|(
name|atoi
argument_list|(
name|cmdbuf
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Display a string, usually as a prompt for input into the command buffer.  */
end_comment

begin_function
name|public
name|void
name|cmd_putstr
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|putstr
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|cmd_col
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Return a pointer to the command buffer.  */
end_comment

begin_function
name|public
name|char
modifier|*
name|get_cmdbuf
parameter_list|()
block|{
return|return
operator|(
name|cmdbuf
operator|)
return|;
block|}
end_function

end_unit

