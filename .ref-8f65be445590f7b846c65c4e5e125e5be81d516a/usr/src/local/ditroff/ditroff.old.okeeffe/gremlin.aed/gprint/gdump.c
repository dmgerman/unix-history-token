begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gdump.c	1.3	83/06/24 	by David Slattengren  *  *      This file contains a program for printing gprint raster files.  *   Gprint puts out a generic file, and gdump changes the size to fit  *   the proper device that's being used.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"gprint.h"
end_include

begin_define
define|#
directive|define
name|LPR
value|"/usr/ucb/lpr"
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|picture
init|=
literal|"/usr/tmp/rastAXXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file name */
end_comment

begin_decl_stmt
name|int
name|temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file number */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lpargs
index|[
literal|9
index|]
init|=
block|{
literal|"lpr"
block|,
literal|"-Pvarian"
block|,
literal|"-v"
block|,
literal|"-s"
block|,
literal|"-r"
block|,
literal|"-J"
block|,
literal|"gdump"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|outwidth
init|=
name|Vbytperlin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of chars per line to output*/
end_comment

begin_decl_stmt
name|int
name|outlength
init|=
name|Vylen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lines to output */
end_comment

begin_decl_stmt
name|int
name|infile
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file (default = stdin) */
end_comment

begin_decl_stmt
name|int
name|inwidth
init|=
name|Vxlen
operator|/
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file raster line length */
end_comment

begin_decl_stmt
name|int
name|FileFound
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for filename on input */
end_comment

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* intermediary command line argument */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name */
end_comment

begin_decl_stmt
name|char
name|buf
index|[
name|Wbytperlin
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* intermediary raster line buffer */
end_comment

begin_macro
name|cleanup
argument_list|()
end_macro

begin_comment
comment|/* Called if program stopped, or ... */
end_comment

begin_block
block|{
name|unlink
argument_list|(
name|picture
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* read in one line of the raster file */
end_comment

begin_macro
name|readline
argument_list|()
end_macro

begin_comment
comment|/* returns 1 (true) if successful, 0 if not */
end_comment

begin_block
block|{
specifier|register
name|i
operator|=
name|inwidth
expr_stmt|;
specifier|register
name|j
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|(
name|j
operator|=
name|read
argument_list|(
name|infile
argument_list|,
name|buf
argument_list|,
name|inwidth
argument_list|)
operator|)
operator|<
literal|1
condition|)
block|{
if|if
condition|(
name|i
operator|==
name|inwidth
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
block|{
comment|/* fill in incomplete last line */
while|while
condition|(
name|i
operator|!=
name|inwidth
condition|)
name|buf
index|[
name|i
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
name|i
operator|-=
name|j
expr_stmt|;
block|}
do|while
condition|(
name|i
condition|)
do|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

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
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* multipurpose index */
name|lpargs
index|[
literal|7
index|]
operator|=
name|picture
expr_stmt|;
comment|/* set file for lpr to read */
name|lpargs
index|[
literal|8
index|]
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
comment|/* Parse the command line. */
block|{
name|arg
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
name|arg
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
if|if
condition|(
name|FileFound
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"gdump: Only one file may be printed\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|lpargs
index|[
literal|6
index|]
operator|=
name|file
operator|=
name|arg
expr_stmt|;
comment|/* set filename (and to lpr) */
name|FileFound
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
operator|*
operator|++
name|arg
condition|)
block|{
case|case
literal|'W'
case|:
comment|/* Print to wide (versatec) device */
name|outwidth
operator|=
name|Wbytperlin
expr_stmt|;
name|outlength
operator|=
name|Wylen
expr_stmt|;
name|lpargs
index|[
literal|1
index|]
operator|=
literal|"-Pversatec"
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
comment|/* Print to narrow (varian) device */
name|outwidth
operator|=
name|Vbytperlin
expr_stmt|;
name|outlength
operator|=
name|Vylen
expr_stmt|;
name|lpargs
index|[
literal|1
index|]
operator|=
literal|"-Pvarian"
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"unknown switch %c\n"
argument_list|,
operator|*
name|arg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|FileFound
condition|)
block|{
comment|/* open input file, if one exists */
name|fclose
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
name|infile
operator|=
name|open
argument_list|(
name|file
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|infile
operator|==
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't open %s"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* clear out line buffer */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Wbytperlin
condition|;
name|buf
index|[
name|i
operator|++
index|]
operator|=
literal|0
control|)
empty_stmt|;
name|mktemp
argument_list|(
name|picture
argument_list|)
expr_stmt|;
comment|/* make up file name */
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
comment|/* prepare to be killed */
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
name|SIG_IGN
condition|)
comment|/*    or interrupted */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|temp
operator|=
name|creat
argument_list|(
name|picture
argument_list|,
literal|0666
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"gdump: can't create %s\n"
argument_list|,
name|picture
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
comment|/*  * transfer the raster file from input to output,  * fixing line lengths, if necessary,  * and truncating to one page length  */
while|while
condition|(
name|readline
argument_list|()
operator|&&
name|outlength
operator|--
condition|)
block|{
if|if
condition|(
name|write
argument_list|(
name|temp
argument_list|,
name|buf
argument_list|,
name|outwidth
argument_list|)
operator|!=
name|outwidth
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"gdump - error writing %s\n"
argument_list|,
name|picture
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
block|}
comment|/* eat the rest of input */
while|while
condition|(
name|read
argument_list|(
name|infile
argument_list|,
name|buf
argument_list|,
name|inwidth
argument_list|)
operator|>
literal|0
condition|)
comment|/* if there is any */
empty_stmt|;
name|close
argument_list|(
name|infile
argument_list|)
expr_stmt|;
comment|/* clear out line buffer */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Wbytperlin
condition|;
name|buf
index|[
name|i
operator|++
index|]
operator|=
literal|0
control|)
empty_stmt|;
while|while
condition|(
name|outlength
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* and fill out the picture */
if|if
condition|(
name|write
argument_list|(
name|temp
argument_list|,
name|buf
argument_list|,
name|outwidth
argument_list|)
operator|!=
name|outwidth
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"gdump - error writing %s\n"
argument_list|,
name|picture
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
block|}
name|execv
argument_list|(
name|LPR
argument_list|,
name|lpargs
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"gdump: can't exec %s\n"
argument_list|,
name|LPR
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

