begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)cmd2.c	3.31 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|help_shortcmd
index|[]
init|=
block|{
literal|"#       Select window # and return to conversation mode."
block|,
literal|"%#      Select window # but stay in command mode."
block|,
literal|"escape  Return to conversation mode without changing window."
block|,
literal|"^^      Return to conversation mode and change to previous window."
block|,
literal|"c#      Close window #."
block|,
literal|"w       Open a new window."
block|,
literal|"m#      Move window #."
block|,
literal|"M#      Move window # to its previous position."
block|,
literal|"s#      Change the size of window #."
block|,
literal|"S#      Change window # to its previous size."
block|,
literal|"^Y,^E   Scroll up, down one line."
block|,
literal|"^U,^D   Scroll up, down half a window."
block|,
literal|"^B,^F   Scroll up, down a full window."
block|,
literal|"h,j,k,l Move cursor left, down, up, right."
block|,
literal|"^S,^Q   Stop, start output in current window."
block|,
literal|"^L      Redraw screen."
block|,
literal|"^Z      Suspend."
block|,
literal|"q       Quit."
block|,
literal|":       Enter a long command."
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|help_longcmd
index|[]
init|=
block|{
literal|":%#                   Select window #."
block|,
literal|":close # . . .        Close windows."
block|,
literal|":close all            Close all windows."
block|,
literal|":cursor modes         Set the cursor modes."
block|,
literal|":echo # string . . .  Print ``string . . .'' in window #."
block|,
literal|":escape C             Set escape character to C."
block|,
literal|":foreground # [off]   Make # a foreground window."
block|,
literal|":label # string       Set label of window # to ``string''."
block|,
literal|":list                 Give a list of all windows."
block|,
literal|":nline lines          Set the default number of lines"
block|,
literal|"                      in window text buffers."
block|,
literal|":shell string . . .   Set default shell program to ``string . . .''"
block|,
literal|":source filename      Execute commands in ``filename.''"
block|,
literal|":terse [off]          Turn on (or off) terse mode."
block|,
literal|":unset variable       Deallocate ``variable''."
block|,
literal|":variable             List all variables."
block|,
literal|":window row col nrow ncol [nline label pty frame shell]"
block|,
literal|"                      Open a window at ``row'', ``col''"
block|,
literal|"                      of size ``nrow'', ``ncol'',"
block|,
literal|"                      with ``nline'', and ``label''."
block|,
literal|":write # string . . . Write ``string . . .'' to window #."
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|c_help
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|ww
modifier|*
name|w
decl_stmt|;
if|if
condition|(
operator|(
name|w
operator|=
name|openiwin
argument_list|(
name|wwnrow
operator|-
literal|3
argument_list|,
literal|"Help"
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"Can't open help window: %s."
argument_list|,
name|wwerror
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|wwprintf
argument_list|(
name|w
argument_list|,
literal|"The escape character is %c.\n"
argument_list|,
name|escapec
argument_list|)
expr_stmt|;
name|wwprintf
argument_list|(
name|w
argument_list|,
literal|"(Below, # is one of the digits from 1 to 9.)\n\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|help_print
argument_list|(
name|w
argument_list|,
literal|"Short commands"
argument_list|,
name|help_shortcmd
argument_list|)
operator|>=
literal|0
condition|)
operator|(
name|void
operator|)
name|help_print
argument_list|(
name|w
argument_list|,
literal|"Long commands"
argument_list|,
name|help_longcmd
argument_list|)
expr_stmt|;
name|closeiwin
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|help_print
argument_list|(
name|w
argument_list|,
name|name
argument_list|,
name|list
argument_list|)
specifier|register
expr|struct
name|ww
operator|*
name|w
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
modifier|*
name|list
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|wwprintf
argument_list|(
name|w
argument_list|,
literal|"%s:\n\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|list
condition|)
switch|switch
condition|(
name|more
argument_list|(
name|w
argument_list|,
literal|0
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
name|wwputs
argument_list|(
operator|*
name|list
operator|++
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|wwputc
argument_list|(
literal|'\n'
argument_list|,
name|w
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|wwprintf
argument_list|(
name|w
argument_list|,
literal|"%s: (continued)\n\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
return|return
operator|-
literal|1
return|;
block|}
return|return
name|more
argument_list|(
name|w
argument_list|,
literal|1
argument_list|)
operator|==
literal|2
condition|?
operator|-
literal|1
else|:
literal|0
return|;
block|}
end_block

begin_macro
name|c_quit
argument_list|()
end_macro

begin_block
block|{
name|char
name|oldterse
init|=
name|terse
decl_stmt|;
name|setterse
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|wwputs
argument_list|(
literal|"Really quit [yn]? "
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|wwcurtowin
argument_list|(
name|cmdwin
argument_list|)
expr_stmt|;
while|while
condition|(
name|wwpeekc
argument_list|()
operator|<
literal|0
condition|)
name|wwiomux
argument_list|()
expr_stmt|;
if|if
condition|(
name|wwgetc
argument_list|()
operator|==
literal|'y'
condition|)
block|{
name|wwputs
argument_list|(
literal|"Yes"
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|quit
operator|++
expr_stmt|;
block|}
else|else
name|wwputc
argument_list|(
literal|'\n'
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
name|setterse
argument_list|(
operator|!
name|quit
operator|&&
name|oldterse
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

