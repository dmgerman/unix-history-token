begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* these are c routines to handle the pdp dungeon i/o */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*	send arguments to message printing process */
end_comment

begin_macro
name|rspsb3_
argument_list|(
argument|arg1
argument_list|,
argument|arg2
argument_list|,
argument|arg3
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|arg1
decl_stmt|,
modifier|*
name|arg2
decl_stmt|,
modifier|*
name|arg3
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"n%d %d %d\n"
argument_list|,
operator|*
name|arg1
argument_list|,
operator|*
name|arg2
argument_list|,
operator|*
name|arg3
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* print for puzzle room */
end_comment

begin_macro
name|puzout_
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
name|printf
argument_list|(
literal|"       |%c%c %c%c %c%c|\n"
argument_list|,
name|p
index|[
literal|0
index|]
argument_list|,
name|p
index|[
literal|0
index|]
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
name|p
index|[
literal|2
index|]
argument_list|,
name|p
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  WEST |%c%c .. %c%c| EAST\n"
argument_list|,
name|p
index|[
literal|3
index|]
argument_list|,
name|p
index|[
literal|3
index|]
argument_list|,
name|p
index|[
literal|4
index|]
argument_list|,
name|p
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"       |%c%c %c%c %c%c|\n"
argument_list|,
name|p
index|[
literal|5
index|]
argument_list|,
name|p
index|[
literal|5
index|]
argument_list|,
name|p
index|[
literal|6
index|]
argument_list|,
name|p
index|[
literal|6
index|]
argument_list|,
name|p
index|[
literal|7
index|]
argument_list|,
name|p
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* output general string (echo room) */
end_comment

begin_macro
name|outstr_
argument_list|(
argument|ptr
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ptr
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%.*s\n"
argument_list|,
operator|*
name|len
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* print a prompt */
end_comment

begin_macro
name|prompt_
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"> ~"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* terminate the game */
end_comment

begin_macro
name|exit_
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"The game is over\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*	read a character */
end_comment

begin_macro
name|rdchr_
argument_list|(
argument|cptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|int
name|ch
decl_stmt|;
if|if
condition|(
operator|(
name|ch
operator|=
name|getchar
argument_list|()
operator|)
operator|==
name|EOF
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"EOF on input\n"
argument_list|)
expr_stmt|;
name|exit_
argument_list|()
expr_stmt|;
block|}
else|else
operator|*
name|cptr
operator|=
name|ch
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* read a line from std input */
end_comment

begin_macro
name|rdlin_
argument_list|(
argument|sptr
argument_list|,
argument|cntptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|cntptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|int
name|chr
decl_stmt|;
operator|*
name|cntptr
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|chr
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
name|EOF
condition|)
block|{
if|if
condition|(
operator|(
name|chr
operator|>=
literal|97
operator|)
operator|&&
operator|(
name|chr
operator|<=
literal|122
operator|)
condition|)
comment|/* convert to uc */
name|chr
operator|-=
literal|32
expr_stmt|;
if|if
condition|(
name|chr
operator|==
literal|10
condition|)
block|{
comment|/* quit if newline */
operator|*
name|sptr
operator|++
operator|=
literal|'\0'
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|chr
operator|==
literal|32
operator|)
operator|&&
operator|(
operator|*
name|cntptr
operator|==
literal|0
operator|)
condition|)
comment|/* rm lead blank */
continue|continue;
if|if
condition|(
operator|*
name|cntptr
operator|>=
literal|78
condition|)
continue|continue;
operator|*
name|sptr
operator|++
operator|=
name|chr
expr_stmt|;
operator|(
operator|*
name|cntptr
operator|)
operator|++
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"EOF on input\n"
argument_list|)
expr_stmt|;
name|exit_
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*	print cure time */
end_comment

begin_macro
name|cured_
argument_list|(
argument|time
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|time
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|" You will be cured in %d moves\n"
argument_list|,
operator|*
name|time
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* print the score */
end_comment

begin_macro
name|pscore_
argument_list|(
argument|score
argument_list|,
argument|max
argument_list|,
argument|moves
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|score
decl_stmt|,
modifier|*
name|max
decl_stmt|,
modifier|*
name|moves
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|" Your current score is %d out of %d points in %d moves.\n"
argument_list|,
operator|*
name|score
argument_list|,
operator|*
name|max
argument_list|,
operator|*
name|moves
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* BUG-- REPORT FATAL SYSTEM ERROR  C C CALLED BY-- C C	CALL BUG(NO,PAR) C C      note: return if DBGFLG set is not implemented C*/
end_comment

begin_macro
name|bug_
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Program error %d ; Parameter %d\n"
argument_list|,
operator|*
name|a
argument_list|,
operator|*
name|b
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* send restore message  */
end_comment

begin_macro
name|restor_
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|" Restore by starting with 'dungeon r'\n"
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* password output */
end_comment

begin_macro
name|voice_
argument_list|(
argument|sp1
argument_list|,
argument|sp2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|sp1
decl_stmt|,
modifier|*
name|sp2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|" A Hollow voice replies: %6.6s %6.6s\n"
argument_list|,
name|sp1
argument_list|,
name|sp2
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* print version */
end_comment

begin_macro
name|prvers_
argument_list|(
argument|v1
argument_list|,
argument|v2
argument_list|,
argument|v3
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|v1
decl_stmt|,
modifier|*
name|v2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|v3
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|" V%1d.%2d%c\n"
argument_list|,
operator|*
name|v1
argument_list|,
operator|*
name|v2
argument_list|,
operator|*
name|v3
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/* dummy stub for game debugger */
end_comment

begin_macro
name|nogdt_
argument_list|()
end_macro

begin_block
block|{
comment|/* debugger deleted to save room */
name|printf
argument_list|(
literal|" Sorry, no debugger available in this version.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

