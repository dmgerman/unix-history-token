begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_comment
comment|/* Handles necessary screen-manipultations. */
end_comment

begin_decl_stmt
name|class
name|Screen_Handler
block|{
name|private
label|:
specifier|static
name|char
name|term_entry
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Holds termcap entry for current terminal. */
specifier|static
name|char
name|temp_buf
index|[
literal|100
index|]
decl_stmt|;
comment|/* Holds inverse screen attributes. */
specifier|static
name|int
name|width
decl_stmt|;
comment|/* Current screen width, needed to format output. */
specifier|static
name|char
modifier|*
name|current_ptr
decl_stmt|;
comment|/* Pointer to current position in temp_buf. */
specifier|static
name|char
modifier|*
name|inverse_start
decl_stmt|;
comment|/* Control sequence beginning inverse mode. */
specifier|static
name|char
modifier|*
name|inverse_end
decl_stmt|;
comment|/* Control sequence ending inverse mode. */
specifier|static
name|void
name|center
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* Prints out leading spaces to center BUF. */
specifier|static
name|int
name|fputchar
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
comment|/* Prints a character to standard output. */
name|public
label|:
name|Screen_Handler
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Initialize the screen width. */
specifier|static
name|int
name|screen_width
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return current screen width. */
specifier|static
name|void
name|print_inverse_centered
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* Centers, inverts, and prints BUF. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* See comments in .cc file for inline functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_expr_stmt
specifier|inline
name|int
name|Screen_Handler
operator|::
name|screen_width
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|width
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Screen_Handler
operator|::
name|fputchar
argument_list|(
argument|int i
argument_list|)
block|{
name|putchar
argument_list|(
name|i
argument_list|)
block|; }
specifier|inline
name|void
name|Screen_Handler
operator|::
name|center
argument_list|(
argument|char *buf
argument_list|)
block|{
name|int
name|offset
block|;
name|int
name|len
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
block|;
name|offset
operator|=
name|width
operator|-
name|len
operator|>>
literal|1
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|offset
condition|;
name|i
operator|++
control|)
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Screen_Handler
operator|::
name|print_inverse_centered
argument_list|(
argument|char *buf
argument_list|)
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
block|;
name|center
argument_list|(
name|buf
argument_list|)
block|;
name|tputs
argument_list|(
name|inverse_start
argument_list|,
literal|1
argument_list|,
name|fputchar
argument_list|)
block|;
name|printf
argument_list|(
literal|"%s\n\n"
argument_list|,
name|buf
argument_list|)
block|;
name|tputs
argument_list|(
name|inverse_end
argument_list|,
literal|1
argument_list|,
name|fputchar
argument_list|)
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __OPTIMIZE__
end_comment

end_unit

