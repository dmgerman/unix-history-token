begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"less.h"
end_include

begin_comment
comment|/*  * Display some help.  * Help is in two pages.  */
end_comment

begin_function
specifier|static
name|void
name|help0
parameter_list|()
block|{
name|puts
argument_list|(
literal|"f, SPACE       Forward one screen.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"b              Backward one screen.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"e, j, CR    *  Forward N lines, default 1.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"y, k        *  Backward N lines, default 1.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"d           *  Forward N lines, default 10 or last N to d or u command.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"u           *  Backward N lines, default 10 or last N to d or u command.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"r              Repaint screen.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"g           *  Go to line N, default 1.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"G           *  Like g, but default is last line in file.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"=              Print current file name\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"/pattern    *  Search forward for N-th occurence of pattern.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"?pattern    *  Search backward for N-th occurence of pattern.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"n           *  Repeat previous search (for N-th occurence).\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"q              Exit.\n"
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"More help..."
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|help1
parameter_list|()
block|{
name|char
name|message
index|[
literal|100
index|]
decl_stmt|;
specifier|extern
name|char
name|all_options
index|[]
decl_stmt|;
name|puts
argument_list|(
literal|"R              Repaint screen, discarding buffered input.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"p, %        *  Position to N percent into the file.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"m<letter>      Mark the current position with<letter>.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"'<letter>      Return to a previously marked position.\n"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|message
argument_list|,
literal|"-X             Toggle a flag (X may be one of \"%s\").\n"
argument_list|,
name|all_options
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"E [file]       Examine a new file.\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"N              Examine the next file (from the command line).\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"P              Examine the previous file (from the command line).\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"V              Print version number.\n"
argument_list|)
expr_stmt|;
if|#
directive|if
name|SHELL_ESCAPE
name|puts
argument_list|(
literal|"!command       Passes the command to a shell to be executed.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|EDITOR
name|sprintf
argument_list|(
name|message
argument_list|,
literal|"v              Edit the current file with $EDITOR (default %s).\n"
argument_list|,
name|EDIT_PGM
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|message
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|error
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|public
name|void
name|help
parameter_list|()
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|puts
argument_list|(
literal|"Commands marked with * may be preceeded by a number, N.\n\n"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|0
case|:
name|help0
argument_list|()
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|help1
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

end_unit

