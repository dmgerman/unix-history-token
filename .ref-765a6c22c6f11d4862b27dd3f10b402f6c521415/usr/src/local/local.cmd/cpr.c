begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)cpr.c	1.8		%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  CPR -- print on concept 108 ** **	This filter arranges to output onto a printer connected **	to a Concept 108 terminal.  It probably works on other **	models in the Concept 100 series also. ** **	Usage: **		cpr [-f] [file ...] ** **	Flags: **		-f	form feed following to print. */
end_comment

begin_define
define|#
directive|define
name|LINELEN
value|132
end_define

begin_comment
comment|/* carriage width */
end_comment

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_decl_stmt
name|struct
name|sgttyb
name|tbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SysLinePid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of sysline process */
end_comment

begin_decl_stmt
name|bool
name|FormFeedFollowing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print form feed following print */
end_comment

begin_decl_stmt
name|bool
name|EchoDuringPrint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* echo on terminal while printing */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
extern|extern cleanterm(
block|)
function|;
end_function

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* arrange to stop the sysline program during printing */
end_comment

begin_expr_stmt
name|p
operator|=
name|getenv
argument_list|(
literal|"SYSLINE"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
name|SysLinePid
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* process arguments */
end_comment

begin_while
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
block|{
name|p
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'-'
condition|)
break|break;
switch|switch
condition|(
operator|*
operator|++
name|p
condition|)
block|{
case|case
literal|'f'
case|:
name|FormFeedFollowing
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
name|EchoDuringPrint
operator|=
name|TRUE
expr_stmt|;
break|break;
block|}
block|}
end_while

begin_comment
comment|/* be nice on interrupts, etc. */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cleanterm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set the terminal to output to printer */
end_comment

begin_expr_stmt
name|setupterm
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* print the appropriate files */
end_comment

begin_if
if|if
condition|(
name|argc
operator|<
literal|1
condition|)
name|copyfile
argument_list|()
expr_stmt|;
else|else
block|{
while|while
condition|(
name|argc
operator|--
operator|>
literal|0
condition|)
block|{
name|p
operator|=
operator|*
name|argv
operator|++
expr_stmt|;
if|if
condition|(
name|freopen
argument_list|(
name|p
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
operator|==
name|NULL
condition|)
name|perror
argument_list|(
name|p
argument_list|)
expr_stmt|;
else|else
name|copyfile
argument_list|()
expr_stmt|;
block|}
block|}
end_if

begin_comment
comment|/* reset terminal to a nice state */
end_comment

begin_expr_stmt
name|cleanterm
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  copyfile
operator|(
operator|)
block|{
block|{
name|p
operator|=
name|index
argument_list|(
name|buf
argument_list|,
literal|'\n'
argument_list|)
block|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
continue|continue;
operator|*
name|p
operator|=
literal|'\r'
block|;
name|printf
argument_list|(
literal|"\033 5%s\033|"
argument_list|,
name|buf
argument_list|)
block|;
if|if
condition|(
name|getack
argument_list|()
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Lost printer\n"
argument_list|)
expr_stmt|;
name|cleanterm
argument_list|()
expr_stmt|;
block|}
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|} }
name|setupterm
argument_list|()
end_macro

begin_block
block|{
name|int
name|oldflags
decl_stmt|;
if|if
condition|(
name|gtty
argument_list|(
literal|1
argument_list|,
operator|&
name|tbuf
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"cpr: stdout"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|oldflags
operator|=
name|tbuf
operator|.
name|sg_flags
expr_stmt|;
name|tbuf
operator|.
name|sg_flags
operator|&=
operator|~
name|ECHO
expr_stmt|;
name|tbuf
operator|.
name|sg_flags
operator||=
name|CBREAK
operator||
name|XTABS
expr_stmt|;
name|stty
argument_list|(
literal|1
argument_list|,
operator|&
name|tbuf
argument_list|)
expr_stmt|;
name|tbuf
operator|.
name|sg_flags
operator|=
name|oldflags
expr_stmt|;
block|}
end_block

begin_macro
name|cleanterm
argument_list|()
end_macro

begin_block
block|{
comment|/* output trailing formfeed */
if|if
condition|(
name|FormFeedFollowing
condition|)
name|fputs
argument_list|(
literal|"\r\f"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
comment|/* disconnect printer */
name|resetmodes
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|getack
argument_list|()
end_macro

begin_block
block|{
name|char
name|buf
index|[
literal|1
index|]
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
literal|2
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|)
operator|<=
literal|0
operator|||
name|buf
index|[
literal|0
index|]
operator|!=
literal|'\006'
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|resetmodes
argument_list|()
end_macro

begin_block
block|{
name|stty
argument_list|(
literal|1
argument_list|,
operator|&
name|tbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|SysLinePid
operator|>
literal|0
condition|)
name|kill
argument_list|(
name|SysLinePid
argument_list|,
name|SIGCONT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

