begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cmd1.c */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This file contains some of the EX commands - mostly ones that deal with  * files, options, etc. -- anything except text.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ctype.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REGEX
end_ifdef

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"regexp.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGEX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TAGSTACK
end_ifndef

begin_comment
comment|/* These describe the current state of the tag related commands		  */
end_comment

begin_define
define|#
directive|define
name|MAXTAGS
value|15
end_define

begin_struct
struct|struct
name|Tag_item
block|{
name|MARK
name|tag_mark
decl_stmt|;
name|char
modifier|*
name|tag_file
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|Tag_item
name|tag_stack
index|[
name|MAXTAGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|curr_tag
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NO_TAGSTACK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/* print the selected lines with info on the blocks */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_debug
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|;
name|MARK
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
name|REG
name|char
modifier|*
name|scan
decl_stmt|;
name|REG
name|long
name|l
decl_stmt|;
name|REG
name|int
name|i
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* scan lnum[] to determine which block its in */
name|l
operator|=
name|markline
argument_list|(
name|frommark
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|l
operator|>
name|lnum
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{ 	}
do|do
block|{
comment|/* fetch text of the block containing that line */
name|scan
operator|=
name|blkget
argument_list|(
name|i
argument_list|)
operator|->
name|c
expr_stmt|;
comment|/* calculate its length */
if|if
condition|(
name|scan
index|[
name|BLKSIZE
operator|-
literal|1
index|]
condition|)
block|{
name|len
operator|=
name|BLKSIZE
expr_stmt|;
block|}
else|else
block|{
name|len
operator|=
name|strlen
argument_list|(
name|scan
argument_list|)
expr_stmt|;
block|}
comment|/* print block stats */
name|msg
argument_list|(
literal|"##### hdr[%d]=%d, lnum[%d-1]=%ld, lnum[%d]=%ld (%ld lines)"
argument_list|,
name|i
argument_list|,
name|hdr
operator|.
name|n
index|[
name|i
index|]
argument_list|,
name|i
argument_list|,
name|lnum
index|[
name|i
operator|-
literal|1
index|]
argument_list|,
name|i
argument_list|,
name|lnum
index|[
name|i
index|]
argument_list|,
name|lnum
index|[
name|i
index|]
operator|-
name|lnum
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|msg
argument_list|(
literal|"##### len=%d, buf=0x%lx, %sdirty"
argument_list|,
name|len
argument_list|,
name|scan
argument_list|,
operator|(
operator|(
name|int
operator|*
operator|)
name|scan
operator|)
index|[
name|MAXBLKS
operator|+
literal|1
index|]
condition|?
literal|""
else|:
literal|"not "
argument_list|)
expr_stmt|;
if|if
condition|(
name|bang
condition|)
block|{
while|while
condition|(
operator|--
name|len
operator|>=
literal|0
condition|)
block|{
name|addch
argument_list|(
operator|*
name|scan
argument_list|)
expr_stmt|;
name|scan
operator|++
expr_stmt|;
block|}
block|}
name|exrefresh
argument_list|()
expr_stmt|;
comment|/* next block */
name|i
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|i
operator|<
name|MAXBLKS
operator|&&
name|lnum
index|[
name|i
index|]
operator|&&
name|lnum
index|[
name|i
operator|-
literal|1
index|]
operator|<
name|markline
argument_list|(
name|tomark
argument_list|)
condition|)
do|;
block|}
end_function

begin_comment
comment|/* This function checks a lot of conditions to make sure they aren't screwy */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_validate
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|;
name|MARK
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
name|char
modifier|*
name|scan
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|nlcnt
decl_stmt|;
comment|/* used to count newlines */
name|int
name|len
decl_stmt|;
comment|/* counts non-NUL characters */
comment|/* check lnum[0] */
if|if
condition|(
name|lnum
index|[
literal|0
index|]
operator|!=
literal|0L
condition|)
block|{
name|msg
argument_list|(
literal|"lnum[0] = %ld"
argument_list|,
name|lnum
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* check each block */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|lnum
index|[
name|i
index|]
operator|<=
name|nlines
condition|;
name|i
operator|++
control|)
block|{
name|scan
operator|=
name|blkget
argument_list|(
name|i
argument_list|)
operator|->
name|c
expr_stmt|;
if|if
condition|(
name|scan
index|[
name|BLKSIZE
operator|-
literal|1
index|]
condition|)
block|{
name|msg
argument_list|(
literal|"block %d has no NUL at the end"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|nlcnt
operator|=
name|len
operator|=
literal|0
init|;
operator|*
name|scan
condition|;
name|scan
operator|++
operator|,
name|len
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|scan
operator|==
literal|'\n'
condition|)
block|{
name|nlcnt
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
name|scan
index|[
operator|-
literal|1
index|]
operator|!=
literal|'\n'
condition|)
block|{
name|msg
argument_list|(
literal|"block %d doesn't end with '\\n' (length %d)"
argument_list|,
name|i
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bang
operator|||
name|nlcnt
operator|!=
name|lnum
index|[
name|i
index|]
operator|-
name|lnum
index|[
name|i
operator|-
literal|1
index|]
condition|)
block|{
name|msg
argument_list|(
literal|"block %d (line %ld?) has %d lines, but should have %ld"
argument_list|,
name|i
argument_list|,
name|lnum
index|[
name|i
operator|-
literal|1
index|]
operator|+
literal|1L
argument_list|,
name|nlcnt
argument_list|,
name|lnum
index|[
name|i
index|]
operator|-
name|lnum
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|exrefresh
argument_list|()
expr_stmt|;
block|}
comment|/* check lnum again */
if|if
condition|(
name|lnum
index|[
name|i
index|]
operator|!=
name|INFINITY
condition|)
block|{
name|msg
argument_list|(
literal|"hdr.n[%d] = %d, but lnum[%d] = %ld"
argument_list|,
name|i
argument_list|,
name|hdr
operator|.
name|n
index|[
name|i
index|]
argument_list|,
name|i
argument_list|,
name|lnum
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|msg
argument_list|(
literal|"# = \"%s\", %% = \"%s\""
argument_list|,
name|prevorig
argument_list|,
name|origname
argument_list|)
expr_stmt|;
name|msg
argument_list|(
literal|"V_from=%ld.%d, cursor=%ld.%d"
argument_list|,
name|markline
argument_list|(
name|V_from
argument_list|)
argument_list|,
name|markidx
argument_list|(
name|V_from
argument_list|)
argument_list|,
name|markline
argument_list|(
name|cursor
argument_list|)
argument_list|,
name|markidx
argument_list|(
name|cursor
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_mark
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|;
name|MARK
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
comment|/* validate the name of the mark */
if|if
condition|(
operator|*
name|extra
operator|==
literal|'"'
condition|)
block|{
name|extra
operator|++
expr_stmt|;
block|}
comment|/* valid mark names are lowercase ascii characters */
if|if
condition|(
operator|!
name|isascii
argument_list|(
operator|*
name|extra
argument_list|)
operator|||
operator|!
name|islower
argument_list|(
operator|*
name|extra
argument_list|)
operator|||
name|extra
index|[
literal|1
index|]
condition|)
block|{
name|msg
argument_list|(
literal|"Invalid mark name"
argument_list|)
expr_stmt|;
return|return;
block|}
name|mark
index|[
operator|*
name|extra
operator|-
literal|'a'
index|]
operator|=
name|tomark
expr_stmt|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_write
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|;
name|MARK
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
name|int
name|fd
decl_stmt|;
name|int
name|append
decl_stmt|;
comment|/* boolean: write in "append" mode? */
name|REG
name|long
name|l
decl_stmt|;
name|REG
name|char
modifier|*
name|scan
decl_stmt|;
name|REG
name|int
name|i
decl_stmt|;
comment|/* if writing to a filter, then let filter() handle it */
if|if
condition|(
operator|*
name|extra
operator|==
literal|'!'
condition|)
block|{
name|filter
argument_list|(
name|frommark
argument_list|,
name|tomark
argument_list|,
name|extra
operator|+
literal|1
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* if all lines are to be written, use tmpsave() */
if|if
condition|(
name|frommark
operator|==
name|MARK_FIRST
operator|&&
name|tomark
operator|==
name|MARK_LAST
operator|&&
name|cmd
operator|==
name|CMD_WRITE
condition|)
block|{
name|tmpsave
argument_list|(
name|extra
argument_list|,
name|bang
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* see if we're going to do this in append mode or not */
name|append
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|extra
index|[
literal|0
index|]
operator|==
literal|'>'
operator|&&
name|extra
index|[
literal|1
index|]
operator|==
literal|'>'
condition|)
block|{
name|extra
operator|+=
literal|2
expr_stmt|;
name|append
operator|=
name|TRUE
expr_stmt|;
block|}
comment|/* either the file must not exist, or we must have a ! or be appending */
if|if
condition|(
operator|*
name|extra
operator|&&
name|access
argument_list|(
name|extra
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
operator|&&
operator|!
name|bang
operator|&&
operator|!
name|append
condition|)
block|{
name|msg
argument_list|(
literal|"File already exists - Use :w! to overwrite"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* else do it line-by-line, like cmd_print() */
if|if
condition|(
name|append
condition|)
block|{
ifdef|#
directive|ifdef
name|O_APPEND
name|fd
operator|=
name|open
argument_list|(
name|extra
argument_list|,
name|O_WRONLY
operator||
name|O_APPEND
argument_list|)
expr_stmt|;
else|#
directive|else
name|fd
operator|=
name|open
argument_list|(
name|extra
argument_list|,
name|O_WRONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
block|{
name|lseek
argument_list|(
name|fd
argument_list|,
literal|0L
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
else|else
block|{
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* so we know the file isn't open yet */
block|}
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|fd
operator|=
name|creat
argument_list|(
name|extra
argument_list|,
name|FILEPERMS
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|msg
argument_list|(
literal|"Can't write to \"%s\""
argument_list|,
name|extra
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
for|for
control|(
name|l
operator|=
name|markline
argument_list|(
name|frommark
argument_list|)
init|;
name|l
operator|<=
name|markline
argument_list|(
name|tomark
argument_list|)
condition|;
name|l
operator|++
control|)
block|{
comment|/* get the next line */
name|scan
operator|=
name|fetchline
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|i
operator|=
name|strlen
argument_list|(
name|scan
argument_list|)
expr_stmt|;
name|scan
index|[
name|i
operator|++
index|]
operator|=
literal|'\n'
expr_stmt|;
comment|/* print the line */
if|if
condition|(
name|twrite
argument_list|(
name|fd
argument_list|,
name|scan
argument_list|,
name|i
argument_list|)
operator|<
name|i
condition|)
block|{
name|msg
argument_list|(
literal|"Write failed"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|rptlines
operator|=
name|markline
argument_list|(
name|tomark
argument_list|)
operator|-
name|markline
argument_list|(
name|frommark
argument_list|)
operator|+
literal|1
expr_stmt|;
name|rptlabel
operator|=
literal|"written"
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_shell
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|,
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BSD
specifier|static
name|char
modifier|*
name|prevextra
init|=
name|NULL
decl_stmt|;
else|#
directive|else
specifier|static
name|char
name|prevextra
index|[
literal|80
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* special case: ":sh" means ":!sh" */
if|if
condition|(
name|cmd
operator|==
name|CMD_SHELL
condition|)
block|{
name|extra
operator|=
name|o_shell
expr_stmt|;
name|frommark
operator|=
name|tomark
operator|=
literal|0L
expr_stmt|;
block|}
comment|/* if extra is "!", substitute previous command */
if|if
condition|(
operator|*
name|extra
operator|==
literal|'!'
condition|)
block|{
ifdef|#
directive|ifdef
name|BSD
if|if
condition|(
name|prevextra
operator|==
name|NULL
condition|)
else|#
directive|else
if|if
condition|(
operator|*
name|prevextra
operator|==
literal|'\0'
condition|)
endif|#
directive|endif
block|{
name|msg
argument_list|(
literal|"No previous shell command to substitute for '!'"
argument_list|)
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|BSD
elseif|else
if|if
condition|(
operator|(
name|prevextra
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|prevextra
argument_list|,
name|strlen
argument_list|(
name|prevextra
argument_list|)
operator|+
name|strlen
argument_list|(
name|extra
argument_list|)
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|strcat
argument_list|(
name|prevextra
argument_list|,
name|extra
operator|+
literal|1
argument_list|)
expr_stmt|;
name|extra
operator|=
name|prevextra
expr_stmt|;
block|}
else|#
directive|else
name|extra
operator|=
name|prevextra
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|cmd
operator|==
name|CMD_BANG
operator|&&
ifdef|#
directive|ifdef
name|BSD
operator|(
name|prevextra
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|prevextra
argument_list|,
name|strlen
argument_list|(
name|extra
argument_list|)
operator|+
literal|1
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
else|#
directive|else
name|strlen
argument_list|(
name|extra
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|prevextra
argument_list|)
operator|-
literal|1
block|)
endif|#
directive|endif
block|{
name|strcpy
argument_list|(
name|prevextra
argument_list|,
name|extra
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* warn the user if the file hasn't been saved yet */
end_comment

begin_if
if|if
condition|(
operator|*
name|o_warn
operator|&&
name|tstflag
argument_list|(
name|file
argument_list|,
name|MODIFIED
argument_list|)
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|MODE_VI
condition|)
block|{
name|mode
operator|=
name|MODE_COLON
expr_stmt|;
block|}
name|msg
argument_list|(
literal|"Warning: \"%s\" has been modified but not yet saved"
argument_list|,
name|origname
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* if no lines were specified, just run the command */
end_comment

begin_expr_stmt
name|suspend_curses
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|frommark
operator|==
literal|0L
condition|)
block|{
name|system
argument_list|(
name|extra
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* pipe lines from the file through the command */
block|{
name|filter
argument_list|(
name|frommark
argument_list|,
name|tomark
argument_list|,
name|extra
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* resume curses quietly for MODE_EX, but noisily otherwise */
end_comment

begin_expr_stmt
name|resume_curses
argument_list|(
name|mode
operator|==
name|MODE_EX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*ARGSUSED*/
end_comment

begin_macro
unit|void
name|cmd_global
argument_list|(
argument|frommark
argument_list|,
argument|tomark
argument_list|,
argument|cmd
argument_list|,
argument|bang
argument_list|,
argument|extra
argument_list|)
end_macro

begin_decl_stmt
name|MARK
name|frommark
decl_stmt|,
name|tomark
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMD
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bang
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|extra
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rest of the command line */
end_comment

begin_block
block|{
name|char
modifier|*
name|cmdptr
decl_stmt|;
comment|/* the command from the command line */
name|char
name|cmdln
index|[
literal|100
index|]
decl_stmt|;
comment|/* copy of the command from the command line */
name|char
modifier|*
name|line
decl_stmt|;
comment|/* a line from the file */
name|long
name|l
decl_stmt|;
comment|/* used as a counter to move through lines */
name|long
name|lqty
decl_stmt|;
comment|/* quantity of lines to be scanned */
name|long
name|nchanged
decl_stmt|;
comment|/* number of lines changed */
ifdef|#
directive|ifdef
name|REGEX
name|regex_t
modifier|*
name|re
decl_stmt|,
modifier|*
name|optpat
argument_list|()
decl_stmt|;
else|#
directive|else
name|regexp
modifier|*
name|re
decl_stmt|;
comment|/* the compiled search expression */
endif|#
directive|endif
comment|/* can't nest global commands */
if|if
condition|(
name|doingglobal
condition|)
block|{
name|msg
argument_list|(
literal|"Can't nest global commands."
argument_list|)
expr_stmt|;
name|rptlines
operator|=
operator|-
literal|1L
expr_stmt|;
return|return;
block|}
comment|/* ":g! ..." is the same as ":v ..." */
if|if
condition|(
name|bang
condition|)
block|{
name|cmd
operator|=
name|CMD_VGLOBAL
expr_stmt|;
block|}
comment|/* make sure we got a search pattern */
if|if
condition|(
operator|*
name|extra
operator|==
literal|' '
operator|||
operator|*
name|extra
operator|==
literal|'\n'
condition|)
block|{
name|msg
argument_list|(
literal|"Usage: %c /regular expression/ command"
argument_list|,
name|cmd
operator|==
name|CMD_GLOBAL
condition|?
literal|'g'
else|:
literal|'v'
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* parse& compile the search pattern */
name|cmdptr
operator|=
name|parseptrn
argument_list|(
name|extra
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|REGEX
name|re
operator|=
name|optpat
argument_list|(
name|extra
operator|+
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
name|extra
index|[
literal|1
index|]
condition|)
block|{
name|msg
argument_list|(
literal|"Can't use empty regular expression with '%c' command"
argument_list|,
name|cmd
operator|==
name|CMD_GLOBAL
condition|?
literal|'g'
else|:
literal|'v'
argument_list|)
expr_stmt|;
return|return;
block|}
name|re
operator|=
name|regcomp
argument_list|(
name|extra
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|re
condition|)
block|{
comment|/* regcomp found& described an error */
return|return;
block|}
comment|/* for each line in the range */
name|doingglobal
operator|=
name|TRUE
expr_stmt|;
name|ChangeText
block|{
comment|/* NOTE: we have to go through the lines in a forward order, 		 * otherwise "g/re/p" would look funny.  *BUT* for "g/re/d" 		 * to work, simply adding 1 to the line# on each loop won't 		 * work.  The solution: count lines relative to the end of 		 * the file.  Think about it. 		 */
for|for
control|(
name|l
operator|=
name|nlines
operator|-
name|markline
argument_list|(
name|frommark
argument_list|)
operator|,
name|lqty
operator|=
name|markline
argument_list|(
name|tomark
argument_list|)
operator|-
name|markline
argument_list|(
name|frommark
argument_list|)
operator|+
literal|1L
operator|,
name|nchanged
operator|=
literal|0L
init|;
name|lqty
operator|>
literal|0
operator|&&
name|nlines
operator|-
name|l
operator|>=
literal|0
operator|&&
name|nchanged
operator|>=
literal|0L
condition|;
name|l
operator|--
operator|,
name|lqty
operator|--
control|)
block|{
comment|/* fetch the line */
name|line
operator|=
name|fetchline
argument_list|(
name|nlines
operator|-
name|l
argument_list|)
expr_stmt|;
comment|/* if it contains the search pattern... */
ifdef|#
directive|ifdef
name|REGEX
if|if
condition|(
operator|(
operator|!
name|regexec
argument_list|(
name|re
argument_list|,
name|line
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|(
name|cmd
operator|==
name|CMD_GLOBAL
operator|)
condition|)
else|#
directive|else
if|if
condition|(
operator|(
operator|!
name|regexec
argument_list|(
name|re
argument_list|,
name|line
argument_list|,
literal|1
argument_list|)
operator|)
operator|==
operator|(
name|cmd
operator|!=
name|CMD_GLOBAL
operator|)
condition|)
endif|#
directive|endif
block|{
comment|/* move the cursor to that line */
name|cursor
operator|=
name|MARK_AT_LINE
argument_list|(
name|nlines
operator|-
name|l
argument_list|)
expr_stmt|;
comment|/* do the ex command (without mucking up 				 * the original copy of the command line) 				 */
name|strcpy
argument_list|(
name|cmdln
argument_list|,
name|cmdptr
argument_list|)
expr_stmt|;
name|rptlines
operator|=
literal|0L
expr_stmt|;
name|doexcmd
argument_list|(
name|cmdln
argument_list|)
expr_stmt|;
name|nchanged
operator|+=
name|rptlines
expr_stmt|;
block|}
block|}
block|}
name|doingglobal
operator|=
name|FALSE
expr_stmt|;
ifndef|#
directive|ifndef
name|REGEX
comment|/* free the regexp */
name|_free_
argument_list|(
name|re
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Reporting...*/
name|rptlines
operator|=
name|nchanged
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|cmd_file
parameter_list|(
name|frommark
parameter_list|,
name|tomark
parameter_list|,
name|cmd
parameter_list|,
name|bang
parameter_list|,
name|extra
parameter_list|)
name|MARK
name|frommark
decl_stmt|,
name|tomark
decl_stmt|;
name|CMD
name|cmd
decl_stmt|;
name|int
name|bang
decl_stmt|;
name|char
modifier|*
name|extra
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|CRUNCH
comment|/* if we're given a new filename, use it as this file's name */
if|if
condition|(
name|extra
operator|&&
operator|*
name|extra
condition|)
block|{
name|strcpy
argument_list|(
name|origname
argument_list|,
name|extra
argument_list|)
expr_stmt|;
name|storename
argument_list|(
name|origname
argument_list|)
expr_stmt|;
name|setflag
argument_list|(
name|file
argument_list|,
name|NOTEDITED
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|cmd
operator|==
name|CMD_FILE
condition|)
block|{
ifndef|#
directive|ifndef
name|CRUNCH
name|msg
argument_list|(
literal|"\"%s\" %s%s%s line %ld of %ld [%ld%%]"
argument_list|,
else|#
directive|else
argument|msg(
literal|"\"%s\" %s%s line %ld of %ld [%ld%%]"
argument|,
endif|#
directive|endif
argument|*origname ? origname :
literal|"[NO FILE]"
argument|, 			tstflag(file, MODIFIED) ?
literal|"[MODIFIED]"
argument|:
literal|""
argument|,
ifndef|#
directive|ifndef
name|CRUNCH
argument|tstflag(file, NOTEDITED) ?
literal|"[NOT EDITED]"
argument|:
literal|""
argument|,
endif|#
directive|endif
argument|tstflag(file, READONLY) ?
literal|"[READONLY]"
argument|:
literal|""
argument|, 			markline(frommark), 			nlines, 			markline(frommark) *
literal|100
argument|/ nlines); 	}
ifndef|#
directive|ifndef
name|CRUNCH
argument|else if (markline(frommark) != markline(tomark)) 	{ 		msg(
literal|"range \"%ld,%ld\" contains %ld lines"
argument|, 			markline(frommark), 			markline(tomark), 			markline(tomark) - markline(frommark) +
literal|1L
argument|); 	}
endif|#
directive|endif
argument|else 	{ 		msg(
literal|"%ld"
argument|, markline(frommark)); 	} }
comment|/*ARGSUSED*/
argument|void cmd_edit(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	long	line =
literal|1L
argument|;
comment|/* might be set to prevline */
ifndef|#
directive|ifndef
name|CRUNCH
argument|char	*init = (char *)
literal|0
argument|;
endif|#
directive|endif
comment|/* if ":vi", then switch to visual mode, and if no file is named 	 * then don't switch files. 	 */
argument|if (cmd == CMD_VISUAL) 	{ 		mode = MODE_VI; 		msg(
literal|""
argument|); 		if (!*extra) 		{ 			return; 		} 	}
comment|/* Editing previous file?  Then start at previous line */
argument|if (!strcmp(extra, prevorig)) 	{ 		line = prevline; 	}
ifndef|#
directive|ifndef
name|CRUNCH
comment|/* if we were given an explicit starting line, then start there */
argument|if (*extra ==
literal|'+'
argument|) 	{ 		for (init = ++extra; !isspace(*extra); extra++) 		{ 		} 		while (isspace(*extra)) 		{ 			*extra++ =
literal|'\0'
argument|; 		} 		if (!*init) 		{ 			init =
literal|"$"
argument|; 		} 		if (!extra) 		{ 			extra = origname; 		} 	}
endif|#
directive|endif
comment|/* not CRUNCH */
comment|/* switch files */
argument|if (tmpabort(bang)) 	{ 		tmpstart(extra); 		if (line<= nlines&& line>=
literal|1L
argument|) 		{ 			cursor = MARK_AT_LINE(line); 		}
ifndef|#
directive|ifndef
name|CRUNCH
argument|if (init) 		{ 			doexcmd(init); 		}
endif|#
directive|endif
argument|} 	else 	{ 		msg(
literal|"Use edit! to abort changes, or w to save changes"
argument|);
comment|/* so we can say ":e!#" next time... */
argument|strcpy(prevorig, extra); 		prevline =
literal|1L
argument|; 	} }
comment|/* This code is also used for rewind -- GB */
comment|/*ARGSUSED*/
argument|void cmd_next(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	int	i
argument_list|,
argument|j; 	char	*scan;
comment|/* if extra stuff given, use ":args" to define a new args list */
argument|if (cmd == CMD_NEXT&& extra&& *extra) 	{ 		cmd_args(frommark, tomark, cmd, bang, extra); 	}
comment|/* move to the next arg */
argument|if (cmd == CMD_NEXT) 	{ 		i = argno +
literal|1
argument|; 	} 	else if (cmd == CMD_PREVIOUS) 	{ 		i = argno -
literal|1
argument|; 	} 	else
comment|/* cmd == CMD_REWIND */
argument|{ 		i =
literal|0
argument|; 	}	 	if (i<
literal|0
argument||| i>= nargs) 	{ 		msg(
literal|"No %sfiles to edit"
argument|, cmd == CMD_REWIND ?
literal|""
argument|:
literal|"more "
argument|); 		return; 	}
comment|/* find& isolate the name of the file to edit */
argument|for (j = i, scan = args; j>
literal|0
argument|; j--) 	{ 		while(*scan++) 		{ 		} 	}
comment|/* switch to the next file */
argument|if (tmpabort(bang)) 	{ 		tmpstart(scan); 		argno = i; 	} 	else 	{ 		msg(
literal|"Use :%s! to abort changes, or w to save changes"
argument|, 			cmd == CMD_NEXT ?
literal|"next"
argument|: 			cmd == CMD_PREVIOUS ?
literal|"previous"
argument|:
literal|"rewind"
argument|); 	} }
comment|/* also called for :wq -- always writes back in this case */
comment|/* also called for :q -- never writes back in that case */
comment|/*ARGSUSED*/
argument|void cmd_xit(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	static long	whenwarned;
comment|/* when the user was last warned of extra files */
argument|int		oldflag;
comment|/* Unless the command is ":q", save the file if it has been modified */
argument|if (cmd != CMD_QUIT&& (cmd == CMD_WQUIT || tstflag(file, MODIFIED))&& !tmpsave((char *)
literal|0
argument|, FALSE)&& !bang) 	{ 		msg(
literal|"Could not save file -- use quit! to abort changes, or w filename"
argument|); 		return; 	}
comment|/* If there are more files to edit, then warn user */
argument|if (argno>=
literal|0
argument|&& argno +
literal|1
argument|< nargs
comment|/* more args */
argument|&& whenwarned != changes
comment|/* user not already warned */
argument|&& (!bang || cmd != CMD_QUIT))
comment|/* command not ":q!" */
argument|{ 		msg(
literal|"More files to edit -- Use \":n\" to go to next file"
argument|); 		whenwarned = changes; 		return; 	}
comment|/* Discard the temp file.  Note that we should already have saved the 	 * the file, unless the command is ":q", so the only way that tmpabort 	 * could fail would be if you did a ":q" on a modified file. 	 */
argument|oldflag = *o_autowrite; 	*o_autowrite = FALSE; 	if (tmpabort(bang)) 	{ 		mode = MODE_QUIT; 	} 	else 	{ 		msg(
literal|"Use q! to abort changes, or wq to save changes"
argument|); 	} 	*o_autowrite = oldflag; }
comment|/*ARGSUSED*/
argument|void cmd_args(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	char	*scan; 	int	col; 	int	arg; 	int	scrolled = FALSE; 	int	width;
comment|/* if no extra names given, or just current name, then report the args 	 * we have now. 	 */
argument|if (!extra || !*extra) 	{
comment|/* empty args list? */
argument|if (nargs ==
literal|1
argument|&& !*args) 		{ 			return; 		}
comment|/* list the arguments */
argument|for (scan = args, col = arg =
literal|0
argument|; 		     arg< nargs; 		     scan += width +
literal|1
argument|, col += width, arg++) 		{ 			width = strlen(scan); 			if (col + width>= COLS -
literal|4
argument|) 			{ 				addch(
literal|'\n'
argument|); 				col =
literal|0
argument|; 				scrolled = TRUE; 			} 			else if (col>
literal|0
argument|) 			{ 				addch(
literal|' '
argument|); 				col++; 			} 			if (arg == argno) 			{ 				addch(
literal|'['
argument|); 				addstr(scan); 				addch(
literal|']'
argument|); 				col +=
literal|2
argument|; 			} 			else 			{ 				addstr(scan); 			} 		}
comment|/* write a trailing newline */
argument|if ((mode == MODE_EX || mode == MODE_COLON || scrolled)&& col) 		{ 			addch(
literal|'\n'
argument|); 		} 		exrefresh();	 	} 	else
comment|/* new args list given */
argument|{ 		for (scan = args, nargs =
literal|1
argument|; *extra; ) 		{ 			if (isspace(*extra)) 			{ 				*scan++ =
literal|'\0'
argument|; 				while (isspace(*extra)) 				{ 					extra++; 				} 				if (*extra) 				{ 					nargs++; 				} 			} 			else 			{ 				*scan++ = *extra++; 			} 		} 		*scan =
literal|'\0'
argument|;
comment|/* reset argno to before the first, so :next will go to first */
argument|argno = -
literal|1
argument|;  		if (nargs !=
literal|1
argument|) 		{                         msg(
literal|"%d files to edit"
argument|, nargs); 		} 	} }
comment|/*ARGSUSED*/
argument|void cmd_cd(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; {
ifndef|#
directive|ifndef
name|CRUNCH
comment|/* if current file is modified, and no '!' was given, then error */
argument|if (tstflag(file, MODIFIED)&& !bang) 	{ 		msg(
literal|"File modified; use \"cd! %s\" to switch anyway"
argument|, extra); 	}
endif|#
directive|endif
comment|/* default directory name is $HOME */
argument|if (!*extra) 	{ 		extra = gethome((char *)
literal|0
argument|); 		if (!extra) 		{ 			msg(
literal|"environment variable $HOME not set"
argument|); 			return; 		} 	}
comment|/* go to the directory */
argument|if (chdir(extra)<
literal|0
argument|) 	{ 		perror(extra); 	} }
comment|/*ARGSUSED*/
argument|void cmd_map(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	char	*mapto; 	char	*build
argument_list|,
argument|*scan;
ifndef|#
directive|ifndef
name|NO_FKEY
argument|static char *fnames[NFKEYS] = 	{
literal|"#10"
argument_list|,
literal|"#1"
argument_list|,
literal|"#2"
argument_list|,
literal|"#3"
argument_list|,
literal|"#4"
argument_list|,
literal|"#5"
argument_list|,
literal|"#6"
argument_list|,
literal|"#7"
argument_list|,
literal|"#8"
argument_list|,
literal|"#9"
argument_list|,
ifndef|#
directive|ifndef
name|NO_SHIFT_FKEY
literal|"#10s"
argument_list|,
literal|"#1s"
argument_list|,
literal|"#2s"
argument_list|,
literal|"#3s"
argument_list|,
literal|"#4s"
argument_list|,
literal|"#5s"
argument_list|,
literal|"#6s"
argument_list|,
literal|"#7s"
argument_list|,
literal|"#8s"
argument_list|,
literal|"#9s"
argument_list|,
ifndef|#
directive|ifndef
name|NO_CTRL_FKEY
literal|"#10c"
argument_list|,
literal|"#1c"
argument_list|,
literal|"#2c"
argument_list|,
literal|"#3c"
argument_list|,
literal|"#4c"
argument_list|,
literal|"#5c"
argument_list|,
literal|"#6c"
argument_list|,
literal|"#7c"
argument_list|,
literal|"#8c"
argument_list|,
literal|"#9c"
argument_list|,
ifndef|#
directive|ifndef
name|NO_ALT_FKEY
literal|"#10a"
argument_list|,
literal|"#1a"
argument_list|,
literal|"#2a"
argument_list|,
literal|"#3a"
argument_list|,
literal|"#4a"
argument_list|,
literal|"#5a"
argument_list|,
literal|"#6a"
argument_list|,
literal|"#7a"
argument_list|,
literal|"#8a"
argument_list|,
literal|"#9a"
argument_list|,
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|}; 	int	key;
endif|#
directive|endif
comment|/* "map" with no extra will dump the map table contents */
argument|if (!*extra) 	{
ifndef|#
directive|ifndef
name|NO_ABBR
argument|if (cmd == CMD_ABBR) 		{ 			dumpkey(bang ? WHEN_EX|WHEN_VIINP|WHEN_VIREP : WHEN_VIINP|WHEN_VIREP, TRUE); 		} 		else
endif|#
directive|endif
argument|{ 			dumpkey(bang ? WHEN_VIINP|WHEN_VIREP : WHEN_VICMD, FALSE); 		} 	} 	else 	{
comment|/* "extra" is key to map, followed by what it maps to */
comment|/* handle quoting inside the "raw" string */
argument|for (build = mapto = extra; 		     *mapto&& (*mapto !=
literal|' '
argument|&& *mapto !=
literal|'\t'
argument|); 		     *build++ = *mapto++) 		{ 			if (*mapto == ctrl(
literal|'V'
argument|)&& mapto[
literal|1
argument|]) 			{ 				mapto++; 			} 		}
comment|/* skip whitespace, and mark the end of the "raw" string */
argument|while ((*mapto ==
literal|' '
argument||| *mapto ==
literal|'\t'
argument|)) 		{ 			*mapto++ =
literal|'\0'
argument|; 		} 		*build =
literal|'\0'
argument|;
comment|/* strip ^Vs from the "cooked" string */
argument|for (scan = build = mapto; *scan; *build++ = *scan++) 		{ 			if (*scan == ctrl(
literal|'V'
argument|)&& scan[
literal|1
argument|]) 			{ 				scan++; 			} 		} 		*build =
literal|'\0'
argument|;
ifndef|#
directive|ifndef
name|NO_FKEY
comment|/* if the mapped string is '#' and a number, then assume 		 * the user wanted that function key 		 */
argument|if (extra[
literal|0
argument|] ==
literal|'#'
argument|&& isdigit(extra[
literal|1
argument|])) 		{ 			key = atoi(extra +
literal|1
argument|) %
literal|10
argument|;
ifndef|#
directive|ifndef
name|NO_SHIFT_FKEY
argument|build = extra + strlen(extra) -
literal|1
argument|; 			if (*build ==
literal|'s'
argument|) 				key +=
literal|10
argument|;
ifndef|#
directive|ifndef
name|NO_CTRL_FKEY
argument|else if (*build ==
literal|'c'
argument|) 				key +=
literal|20
argument|;
ifndef|#
directive|ifndef
name|NO_ALT_FKEY
argument|else if (*build ==
literal|'a'
argument|) 				key +=
literal|30
argument|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|if (FKEY[key]) 				mapkey(FKEY[key], mapto, bang ? WHEN_VIINP|WHEN_VIREP : WHEN_VICMD, fnames[key]); 			else 				msg(
literal|"This terminal has no %s key"
argument|, fnames[key]); 		} 		else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_ABBR
argument|if (cmd == CMD_ABBR || cmd == CMD_UNABBR) 		{ 			mapkey(extra, mapto, bang ? WHEN_EX|WHEN_VIINP|WHEN_VIREP : WHEN_VIINP|WHEN_VIREP,
literal|"abbr"
argument|); 		} 		else
endif|#
directive|endif
argument|{ 			mapkey(extra, mapto, bang ? WHEN_VIINP|WHEN_VIREP : WHEN_VICMD, (char *)
literal|0
argument|); 		} 	} }
comment|/*ARGSUSED*/
argument|void cmd_set(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	if (!*extra) 	{ 		dumpopts(FALSE);
comment|/* "FALSE" means "don't dump all" - only set */
argument|} 	else if (!strcmp(extra,
literal|"all"
argument|)) 	{ 		dumpopts(TRUE);
comment|/* "TRUE" means "dump all" - even unset vars */
argument|} 	else 	{ 		setopts(extra);
comment|/* That option may have affected the appearence of text */
argument|changes++; 	} }
comment|/*ARGSUSED*/
argument|void cmd_tag(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	int	fd;
comment|/* file descriptor used to read the file */
argument|char	*scan;
comment|/* used to scan through the tmpblk.c */
ifdef|#
directive|ifdef
name|INTERNAL_TAGS
argument|char	*cmp;
comment|/* char of tag name we're comparing, or NULL */
argument|char	*end;
comment|/* marks the end of chars in tmpblk.c */
argument|char	file[
literal|128
argument|];
comment|/* name of file containing tag */
argument|int	found;
comment|/* whether the tag has been found */
argument|int	file_exists;
comment|/* whether any tag file exists */
argument|char	*s
argument_list|,
argument|*t;
else|#
directive|else
ifndef|#
directive|ifndef
name|NO_TAGSTACK
argument|char	*s;
endif|#
directive|endif
argument|int	i;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_MAGIC
argument|char	wasmagic;
comment|/* preserves the original state of o_magic */
endif|#
directive|endif
argument|static char prevtag[
literal|30
argument|];
comment|/* if no tag is given, use the previous tag */
argument|if (!extra || !*extra) 	{ 		if (!*prevtag) 		{ 			msg(
literal|"No previous tag"
argument|); 			return; 		} 		extra = prevtag; 	} 	else 	{ 		strncpy(prevtag, extra, sizeof prevtag); 		prevtag[sizeof prevtag -
literal|1
argument|] =
literal|'\0'
argument|; 	}
ifndef|#
directive|ifndef
name|INTERNAL_TAGS
comment|/* use "ref" to look up the tag info for this tag */
argument|sprintf(tmpblk.c,
literal|"ref -t %s%s %s"
argument|, (*origname ?
literal|"-f"
argument|:
literal|""
argument|),origname, prevtag); 	fd = rpipe(tmpblk.c,
literal|0
argument|); 	if (fd<
literal|0
argument|) 	{ 		msg(
literal|"Can't run \"%s\""
argument|, tmpblk.c); 		return; 	}
comment|/* try to read the tag info */
argument|for (scan = tmpblk.c; 	     (i = tread(fd, scan, scan - tmpblk.c + BLKSIZE))>
literal|0
argument|; 	     scan += i) 	{ 	} 	*scan =
literal|'\0'
argument|;
comment|/* close the pipe.  abort if error */
argument|if (rpclose(fd) !=
literal|0
argument|) 	{ 		msg(
literal|"Trouble running \"ref\" -- Can't do tag lookup"
argument|); 		return; 	} 	else if (scan< tmpblk.c +
literal|3
argument|) 	{ 		msg(
literal|"tag \"%s\" not found"
argument|, extra); 		return; 	}
else|#
directive|else
comment|/* use internal code to look up the tag */
argument|found =
literal|0
argument|; 	file_exists =
literal|0
argument|; 	s = o_tags; 	while (!found&& *s !=
literal|0
argument|) { 		while (isspace(*s)) s++; 		for(t = file; s&& *s&& !isspace(*s); s++) 			*t++ = *s; 		*t =
literal|'\0'
argument|;
comment|/* open the next tags file */
argument|fd = open(file, O_RDONLY); 		if (fd<
literal|0
argument|) 			continue; 		else 			file_exists =
literal|1
argument|;
comment|/* Hmmm... this would have been a lot easier with<stdio.h> */
comment|/* find the line with our tag in it */
argument|for(scan = end = tmpblk.c, cmp = extra; ; scan++) 		{
comment|/* read a block, if necessary */
argument|if (scan>= end) 			{ 				end = tmpblk.c + tread(fd, tmpblk.c, BLKSIZE); 				scan = tmpblk.c; 				if (scan>= end) 				{ 					close(fd); 					break; 				} 			}
comment|/* if we're comparing, compare... */
argument|if (cmp) 			{
comment|/* matched??? wow! */
argument|if (!*cmp&& *scan ==
literal|'\t'
argument|) 				{ 					if ((s = strrchr(file,
literal|'/'
argument|)) !=
literal|0
argument||| 					    (s = strrchr(file,
literal|'\\'
argument|)) !=
literal|0
argument|) 						++s; 					else 						s = file; 					*s =
literal|'\0'
argument|; 					found =
literal|1
argument|; 					break; 				} 				if (*cmp++ != *scan) 				{
comment|/* failed! skip to newline */
argument|cmp = (char *)
literal|0
argument|; 				} 			}
comment|/* if we're skipping to newline, do it fast! */
argument|if (!cmp) 			{ 				while (scan< end&& *scan !=
literal|'\n'
argument|) 				{ 					scan++; 				} 				if (scan< end) 				{ 					cmp = extra; 				} 			} 		} 	}  	if (!file_exists) { 		msg(
literal|"No tags file"
argument|); 		return; 	}  	if (!found) { 		msg(
literal|"tag \"%s\" not found"
argument|, extra); 		return; 	}
comment|/* found it! get the rest of the line into memory */
argument|for (cmp = tmpblk.c, scan++; scan< end&& *scan !=
literal|'\n'
argument|; ) 	{ 		*cmp++ = *scan++; 	} 	if (scan == end) 	{ 		tread(fd, cmp, BLKSIZE - (int)(cmp - tmpblk.c)); 	} 	else 		*cmp = *scan;
comment|/* we can close the tags file now */
argument|close(fd);
endif|#
directive|endif
comment|/* INTERNAL_TAGS */
comment|/* extract the filename from the line, and edit the file */
argument|for (scan = tmpblk.c; *scan !=
literal|'\t'
argument|; scan++) 	{ 	} 	*scan++ =
literal|'\0'
argument|; 	if (strcmp(origname, tmpblk.c) !=
literal|0
argument|) 	{ 		if (!tmpabort(bang)) 		{ 			msg(
literal|"Use :tag! to abort changes, or :w to save changes"
argument|); 			return; 		} 		tmpstart(tmpblk.c);
ifdef|#
directive|ifdef
name|NO_TAGSTACK
argument|}
else|#
directive|else
comment|/* tagstack enabled */
argument|s = prevorig; 	} 	else 		s = origname;  	if (frommark != MARK_UNSET&& *s&& *o_tagstack) 	{ 		curr_tag++; 		if (curr_tag>= MAXTAGS) 		{
comment|/* discard the oldest tag position */
argument|free(tag_stack[
literal|0
argument|].tag_file); 			for (curr_tag =
literal|0
argument|; curr_tag< MAXTAGS -
literal|1
argument|; curr_tag++) 			{ 				tag_stack[curr_tag] = tag_stack[curr_tag +
literal|1
argument|]; 			}
comment|/* at this point, curr_tag = MAXTAGS-1 */
argument|} 		tag_stack[curr_tag].tag_file = (char *) malloc(strlen(s) +
literal|1
argument|); 		strcpy(tag_stack[curr_tag].tag_file, s); 		tag_stack[curr_tag].tag_mark = frommark; 	}
endif|#
directive|endif
comment|/* move to the desired line (or to line 1 if that fails) */
ifndef|#
directive|ifndef
name|NO_MAGIC
argument|wasmagic = *o_magic; 	*o_magic = FALSE;
endif|#
directive|endif
argument|cursor = MARK_FIRST; 	linespec(scan,&cursor); 	if (cursor == MARK_UNSET) 	{ 		cursor = MARK_FIRST; 		msg(
literal|"Tag's address is out of date"
argument|); 	}
ifndef|#
directive|ifndef
name|NO_MAGIC
argument|*o_magic = wasmagic;
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|NO_TAGSTACK
comment|/*ARGSUSED*/
argument|void cmd_pop(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	char	buf[
literal|8
argument|];  	if (!*o_tagstack) 	{ 		msg(
literal|"Tagstack not enabled"
argument|); 		return; 	}  	if (curr_tag<
literal|0
argument|) 		msg(
literal|"Tagstack empty"
argument|); 	else 	{ 		if (strcmp(origname, tag_stack[curr_tag].tag_file) !=
literal|0
argument|) 		{ 			if (!tmpabort(bang)) 			{ 				msg(
literal|"Use :pop! to abort changes, or :w to save changes"
argument|); 				return; 			} 			tmpstart(tag_stack[curr_tag].tag_file); 		} 		cursor = tag_stack[curr_tag].tag_mark; 		if (cursor< MARK_FIRST || cursor> MARK_LAST + BLKSIZE) 		{ 			cursor = MARK_FIRST; 		} 		free(tag_stack[curr_tag--].tag_file); 	} }
endif|#
directive|endif
comment|/* describe this version of the program */
comment|/*ARGSUSED*/
argument|void cmd_version(frommark, tomark, cmd, bang, extra) 	MARK	frommark; 	MARK	tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	msg(
literal|"%s"
argument|, VERSION);
ifdef|#
directive|ifdef
name|CREDIT
argument|msg(
literal|"%s"
argument|, CREDIT);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CREDIT2
argument|msg(
literal|"%s"
argument|, CREDIT2);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COMPILED_BY
argument|msg(
literal|"Compiled by %s"
argument|, COMPILED_BY);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COPYING
argument|msg(
literal|"%s"
argument|, COPYING);
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|NO_MKEXRC
comment|/* make a .exrc file which describes the current configuration */
comment|/*ARGSUSED*/
argument|void cmd_mkexrc(frommark, tomark, cmd, bang, extra) 	MARK	frommark; 	MARK	tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	int	fd;
comment|/* the default name for the .exrc file EXRC */
argument|if (!*extra) 	{ 		extra = EXRC; 	}
comment|/* create the .exrc file */
argument|fd = creat(extra, FILEPERMS); 	if (fd<
literal|0
argument|) 	{ 		msg(
literal|"Couldn't create a new \"%s\" file"
argument|, extra); 		return; 	}
comment|/* save stuff */
argument|saveopts(fd); 	savemaps(fd, FALSE);
ifndef|#
directive|ifndef
name|NO_ABBR
argument|savemaps(fd, TRUE);
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_DIGRAPH
argument|savedigs(fd);
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_COLOR
argument|savecolor(fd);
endif|#
directive|endif
comment|/* close the file */
argument|close(fd); 	msg(
literal|"Configuration saved"
argument|); }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_DIGRAPH
comment|/*ARGSUSED*/
argument|void cmd_digraph(frommark, tomark, cmd, bang, extra) 	MARK	frommark; 	MARK	tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	do_digraph(bang, extra); }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_ERRLIST
argument|static char	errfile[
literal|256
argument|];
comment|/* the name of a file containing an error */
argument|static long	errline;
comment|/* the line number for an error */
argument|static int	errfd = -
literal|2
argument|;
comment|/* fd of the errlist file */
comment|/* This static function tries to parse an error message.  *  * For most compilers, the first word is taken to be the name of the erroneous  * file, and the first number after that is taken to be the line number where  * the error was detected.  The description of the error follows, possibly  * preceded by an "error ... :" or "warning ... :" label which is skipped.  *  * For Coherent, error messages look like "line#: filename: message".  *  * For non-error lines, or unparsable error lines, this function returns NULL.  * Normally, though, it alters errfile and errline, and returns a pointer to  * the description.  */
argument|static char *parse_errmsg(text) 	REG char	*text; { 	REG char	*cpy; 	long		atol();
if|#
directive|if
name|COHERENT
operator|||
name|TOS
comment|/* any Mark Williams compiler */
comment|/* Get the line number.  If no line number, then ignore this line. */
argument|errline = atol(text); 	if (errline ==
literal|0L
argument|) 		return (char *)
literal|0
argument|;
comment|/* Skip to the start of the filename */
argument|while (*text&& *text++ !=
literal|':'
argument|) 	{ 	} 	if (!*text++) 		return (char *)
literal|0
argument|;
comment|/* copy the filename to errfile */
argument|for (cpy = errfile; *text&& (*cpy++ = *text++) !=
literal|':'
argument|; ) 	{ 	} 	if (!*text++) 		return (char *)
literal|0
argument|; 	cpy[-
literal|1
argument|] =
literal|'\0'
argument|;  	return text;
else|#
directive|else
comment|/* not a Mark Williams compiler */
argument|char		*errmsg;
comment|/* the error message is the whole line, by default */
argument|errmsg = text;
comment|/* skip leading garbage */
argument|while (*text&& !isalnum(*text)) 	{ 		text++; 	}
comment|/* copy over the filename */
argument|cpy = errfile; 	while(isalnum(*text) || *text ==
literal|'.'
argument|) 	{ 		*cpy++ = *text++; 	} 	*cpy =
literal|'\0'
argument|;
comment|/* ignore the name "Error" and filenames that contain a '/' */
argument|if (*text ==
literal|'/'
argument||| !*errfile || !strcmp(errfile +
literal|1
argument|,
literal|"rror"
argument|) || access(errfile,
literal|0
argument|)<
literal|0
argument|) 	{ 		return (char *)
literal|0
argument|; 	}
comment|/* skip garbage between filename and line number */
argument|while (*text&& !isdigit(*text)) 	{ 		text++; 	}
comment|/* if the number is part of a larger word, then ignore this line */
argument|if (*text&& (isalpha(text[-
literal|1
argument|]) || text[-
literal|1
argument|] ==
literal|'_'
argument|)) 	{ 		return (char *)
literal|0
argument|; 	}
comment|/* get the error line */
argument|errline =
literal|0L
argument|; 	while (isdigit(*text)) 	{ 		errline *=
literal|10
argument|; 		errline += (*text -
literal|'0'
argument|); 		text++; 	}
comment|/* any line which lacks a filename or line number should be ignored */
argument|if (!errfile[
literal|0
argument|] || !errline) 	{ 		return (char *)
literal|0
argument|; 	}
comment|/* locate the beginning of the error description */
argument|while (*text&& !isspace(*text)) 	{ 		text++; 	} 	while (*text) 	{
ifndef|#
directive|ifndef
name|CRUNCH
comment|/* skip "error #:" and "warning #:" clauses */
argument|if (!strncmp(text +
literal|1
argument|,
literal|"rror "
argument|,
literal|5
argument|) 		 || !strncmp(text +
literal|1
argument|,
literal|"arning "
argument|,
literal|7
argument|) 		 || !strncmp(text +
literal|1
argument|,
literal|"atal error"
argument|,
literal|10
argument|)) 		{ 			do 			{ 				text++; 			} while (*text&& *text !=
literal|':'
argument|); 			continue; 		}
endif|#
directive|endif
comment|/* anything other than whitespace or a colon is important */
argument|if (!isspace(*text)&& *text !=
literal|':'
argument|) 		{ 			errmsg = text; 			break; 		}
comment|/* else keep looking... */
argument|text++; 	}  	return errmsg;
endif|#
directive|endif
comment|/* not COHERENT */
argument|}
comment|/*ARGSUSED*/
argument|void cmd_errlist(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	static long	endline;
comment|/* original number of lines in this file */
argument|static long	offset;
comment|/* offset of the next line in the errlist file */
argument|int		i; 	char		*errmsg;
comment|/* if a new errlist file is named, open it */
argument|if (extra&& extra[
literal|0
argument|]) 	{
comment|/* close the old one */
argument|if (errfd>=
literal|0
argument|) 		{ 			close(errfd); 		}
comment|/* open the new one */
argument|errfd = open(extra, O_RDONLY); 		offset =
literal|0L
argument|; 		endline = nlines; 	} 	else if (errfd<
literal|0
argument|) 	{
comment|/* open the default file */
argument|errfd = open(ERRLIST, O_RDONLY); 		offset =
literal|0L
argument|; 		endline = nlines; 	}
comment|/* do we have an errlist file now? */
argument|if (errfd<
literal|0
argument|) 	{ 		msg(
literal|"There is no errlist file"
argument|); 		beep(); 		return; 	}
comment|/* find the next error message in the file */
argument|do 	{
comment|/* read the next line from the errlist */
argument|lseek(errfd, offset,
literal|0
argument|); 		if (tread(errfd, tmpblk.c, (unsigned)BLKSIZE)<=
literal|0
argument|) 		{ 			msg(
literal|"No more errors"
argument|); 			beep(); 			close(errfd); 			errfd = -
literal|2
argument|; 			return; 		} 		for (i =
literal|0
argument|; tmpblk.c[i] !=
literal|'\n'
argument|; i++) 		{ 		} 		tmpblk.c[i++] =
literal|0
argument|;
comment|/* look for an error message in the line */
argument|errmsg = parse_errmsg(tmpblk.c); 		if (!errmsg) 		{ 			offset += i; 		}  	} while (!errmsg);
comment|/* switch to the file containing the error, if this isn't it */
argument|if (strcmp(origname, errfile)) 	{ 		if (!tmpabort(bang)) 		{ 			msg(
literal|"Use :er! to abort changes, or :w to save changes"
argument|); 			beep(); 			return; 		} 		tmpstart(errfile); 		endline = nlines; 	} 	else if (endline ==
literal|0L
argument|) 	{ 		endline = nlines; 	}
comment|/* go to the line where the error was detected */
argument|cursor = MARK_AT_LINE(errline + (nlines - endline)); 	if (cursor> MARK_LAST) 	{ 		cursor = MARK_LAST; 	} 	if (mode == MODE_VI) 	{ 		redraw(cursor, FALSE); 	}
comment|/* display the error message */
ifdef|#
directive|ifdef
name|CRUNCH
argument|msg(
literal|"%.70s"
argument|, errmsg);
else|#
directive|else
argument|if (nlines> endline) 	{ 		msg(
literal|"line %ld(+%ld): %.60s"
argument|, errline, nlines - endline, errmsg); 	} 	else if (nlines< endline) 	{ 		msg(
literal|"line %ld(-%ld): %.60s"
argument|, errline, endline - nlines, errmsg); 	} 	else 	{ 		msg(
literal|"line %ld: %.65s"
argument|, errline, errmsg); 	}
endif|#
directive|endif
comment|/* remember where the NEXT error line will start */
argument|offset += i; }
comment|/*ARGSUSED*/
argument|void cmd_make(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	BLK	buf;
comment|/* if the file hasn't been saved, then complain unless ! */
argument|if (tstflag(file, MODIFIED)&& !bang) 	{ 		msg(
literal|"\"%s\" not saved yet"
argument|, origname); 		return; 	}
comment|/* build the command */
argument|sprintf(buf.c,
literal|"%s %s %s%s"
argument|, (cmd == CMD_CC ? o_cc : o_make), extra, REDIRECT, ERRLIST); 	qaddstr(buf.c); 	addch(
literal|'\n'
argument|);
comment|/* close the old errlist file, if any */
argument|if (errfd>=
literal|0
argument|) 	{ 		close(errfd); 		errfd = -
literal|3
argument|; 	}
if|#
directive|if
name|MINT
comment|/* I guess MiNT can't depend on the shell for redirection? */
argument|close(creat(ERRLIST,
literal|0666
argument|)); 	if ((fd = open(ERRLIST, O_RDWR)) == -
literal|1
argument|) 	{ 		unlink(ERRLIST); 		return; 	} 	suspend_curses(); 	old2 = dup(
literal|2
argument|); 	dup2(fd,
literal|2
argument|); 	system(buf.c); 	dup2(old2,
literal|2
argument|); 	close(old2); 	close(fd);
else|#
directive|else
comment|/* run the command, with curses temporarily disabled */
argument|suspend_curses(); 	system(buf.c);
endif|#
directive|endif
argument|resume_curses(mode == MODE_EX); 	if (mode == MODE_COLON)
comment|/* ':' hit instead of CR, so let him escape... -nox */
argument|return;
comment|/* run the "errlist" command */
argument|cmd_errlist(MARK_UNSET, MARK_UNSET, cmd, bang, ERRLIST);
comment|/* avoid spurious `Hit<RETURN>' after 1st error message  -nox */
comment|/* (which happened when cmd_errlist didn't have to change files...)  */
argument|if (mode == MODE_VI) 		refresh(); }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_COLOR
comment|/* figure out the number of text colors we use with this configuration */
ifndef|#
directive|ifndef
name|NO_POPUP
ifndef|#
directive|ifndef
name|NO_VISIBLE
define|#
directive|define
name|NCOLORS
value|7
else|#
directive|else
define|#
directive|define
name|NCOLORS
value|6
endif|#
directive|endif
else|#
directive|else
ifndef|#
directive|ifndef
name|NO_VISIBLE
define|#
directive|define
name|NCOLORS
value|6
else|#
directive|else
define|#
directive|define
name|NCOLORS
value|5
endif|#
directive|endif
endif|#
directive|endif
comment|/* the attribute bytes used in each of "when"s */
argument|static char bytes[NCOLORS];  static struct { 	char	*word;
comment|/* a legal word */
argument|int	type;
comment|/* what type of word this is */
argument|int	val;
comment|/* some other value */
argument|} 	words[] = { 	{
literal|"normal"
argument_list|,
literal|1
argument_list|,
argument|A_NORMAL}
argument_list|,
comment|/* all "when" names must come */
argument|{
literal|"standout"
argument_list|,
literal|1
argument_list|,
argument|A_STANDOUT}
argument_list|,
comment|/* at the top of the list.    */
argument|{
literal|"bold"
argument_list|,
literal|1
argument_list|,
argument|A_BOLD}
argument_list|,
comment|/* The first 3 must be normal,*/
argument|{
literal|"underlined"
argument_list|,
literal|1
argument_list|,
argument|A_UNDERLINE}
argument_list|,
comment|/* standout, and bold; the    */
argument|{
literal|"italics"
argument_list|,
literal|1
argument_list|,
argument|A_ALTCHARSET}
argument_list|,
comment|/* remaining names follow.    */
ifndef|#
directive|ifndef
name|NO_POPUP
argument|{
literal|"popup"
argument_list|,
literal|1
argument_list|,
argument|A_POPUP}
argument_list|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_VISIBLE
argument|{
literal|"visible"
argument_list|,
literal|1
argument_list|,
argument|A_VISIBLE}
argument_list|,
endif|#
directive|endif
argument|{
literal|"black"
argument_list|,
literal|3
argument_list|,
literal|0x00
argument|}
argument_list|,
comment|/* The color names start right*/
argument|{
literal|"blue"
argument_list|,
literal|3
argument_list|,
literal|0x01
argument|}
argument_list|,
comment|/* after the "when" names.    */
argument|{
literal|"green"
argument_list|,
literal|3
argument_list|,
literal|0x02
argument|}
argument_list|,
argument|{
literal|"cyan"
argument_list|,
literal|3
argument_list|,
literal|0x03
argument|}
argument_list|,
argument|{
literal|"red"
argument_list|,
literal|3
argument_list|,
literal|0x04
argument|}
argument_list|,
argument|{
literal|"magenta"
argument_list|,
literal|3
argument_list|,
literal|0x05
argument|}
argument_list|,
argument|{
literal|"brown"
argument_list|,
literal|3
argument_list|,
literal|0x06
argument|}
argument_list|,
argument|{
literal|"white"
argument_list|,
literal|3
argument_list|,
literal|0x07
argument|}
argument_list|,
argument|{
literal|"yellow"
argument_list|,
literal|3
argument_list|,
literal|0x0E
argument|}
argument_list|,
comment|/* bright brown */
argument|{
literal|"gray"
argument_list|,
literal|3
argument_list|,
literal|0x08
argument|}
argument_list|,
comment|/* bright black?  of course! */
argument|{
literal|"grey"
argument_list|,
literal|3
argument_list|,
literal|0x08
argument|}
argument_list|,
argument|{
literal|"bright"
argument_list|,
literal|2
argument_list|,
literal|0x08
argument|}
argument_list|,
argument|{
literal|"light"
argument_list|,
literal|2
argument_list|,
literal|0x08
argument|}
argument_list|,
argument|{
literal|"blinking"
argument_list|,
literal|2
argument_list|,
literal|0x80
argument|}
argument_list|,
argument|{
literal|"on"
argument_list|,
literal|0
argument_list|,
literal|0
argument|}
argument_list|,
argument|{
literal|"n"
argument_list|,
literal|1
argument_list|,
argument|A_NORMAL}
argument_list|,
argument|{
literal|"s"
argument_list|,
literal|1
argument_list|,
argument|A_STANDOUT}
argument_list|,
argument|{
literal|"b"
argument_list|,
literal|1
argument_list|,
argument|A_BOLD}
argument_list|,
argument|{
literal|"u"
argument_list|,
literal|1
argument_list|,
argument|A_UNDERLINE}
argument_list|,
argument|{
literal|"i"
argument_list|,
literal|1
argument_list|,
argument|A_ALTCHARSET}
argument_list|,
ifndef|#
directive|ifndef
name|NO_POPUP
argument|{
literal|"p"
argument_list|,
literal|1
argument_list|,
argument|A_POPUP}
argument_list|,
argument|{
literal|"menu"
argument_list|,
literal|1
argument_list|,
argument|A_POPUP}
argument_list|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_VISIBLE
argument|{
literal|"v"
argument_list|,
literal|1
argument_list|,
argument|A_VISIBLE}
argument_list|,
endif|#
directive|endif
argument|{(char *)
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument|} };
comment|/*ARGSUSED*/
argument|void cmd_color(frommark, tomark, cmd, bang, extra) 	MARK	frommark
argument_list|,
argument|tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	int	attrbyte; 	int	cmode; 	int	nowbg;
comment|/* BOOLEAN: is the next color background? */
argument|REG char *scan; 	REG	i;
ifndef|#
directive|ifndef
name|CRUNCH
comment|/* if no args are given, then report the current colors */
argument|if (!*extra) 	{
comment|/* if no colors are set, then say so */
argument|if (!bytes[
literal|0
argument|]) 		{ 			msg(
literal|"no colors have been set"
argument|); 			return; 		}
comment|/* report all five color combinations */
argument|for (i =
literal|0
argument|; i< NCOLORS; i++) 		{ 			qaddstr(
literal|"color "
argument|); 			qaddstr(words[i].word); 			qaddch(
literal|' '
argument|); 			if (bytes[i]&
literal|0x80
argument|) 				qaddstr(
literal|"blinking "
argument|); 			switch (bytes[i]&
literal|0xf
argument|) 			{ 			  case
literal|0x08
argument|:	qaddstr(
literal|"gray"
argument|);	break; 			  case
literal|0x0e
argument|:	qaddstr(
literal|"yellow"
argument|);	break; 			  case
literal|0x0f
argument|:	qaddstr(
literal|"bright white"
argument|);break; 			  default: 				if (bytes[i]&
literal|0x08
argument|) 					qaddstr(
literal|"light "
argument|); 				qaddstr(words[(bytes[i]&
literal|0x07
argument|) + NCOLORS].word); 			} 			qaddstr(
literal|" on "
argument|); 			qaddstr(words[((bytes[i]>>
literal|4
argument|)&
literal|0x07
argument|) + NCOLORS].word); 			addch(
literal|'\n'
argument|); 			exrefresh(); 		} 		return; 	}
endif|#
directive|endif
comment|/* The default background color is the same as "normal" chars. 	 * There is no default foreground color. 	 */
argument|cmode = A_NORMAL; 	attrbyte = bytes[
literal|0
argument|]&
literal|0x70
argument|; 	nowbg = FALSE;
comment|/* parse each word in the "extra" text */
argument|for (scan = extra; *extra; extra = scan) 	{
comment|/* locate the end of the word */
argument|while (*scan&& *scan !=
literal|' '
argument|) 		{ 			scan++; 		}
comment|/* skip whitespace at the end of the word */
argument|while(*scan ==
literal|' '
argument|) 		{ 			*scan++ =
literal|'\0'
argument|; 		}
comment|/* lookup the word */
argument|for (i =
literal|0
argument|; words[i].word&& strcmp(words[i].word, extra); i++) 		{ 		}
comment|/* if not a word, then complain */
argument|if (!words[i].word) 		{ 			msg(
literal|"Invalid color name: %s"
argument|, extra); 			return; 		}
comment|/* process the word */
argument|switch (words[i].type) 		{ 		  case
literal|1
argument|: 			cmode = words[i].val; 			break;  		  case
literal|2
argument|: 			attrbyte |= words[i].val; 			break;  		  case
literal|3
argument|: 			if (nowbg) 				attrbyte = ((attrbyte& ~
literal|0x70
argument|) | ((words[i].val&
literal|0x07
argument|)<<
literal|4
argument|)); 			else 				attrbyte |= words[i].val; 			nowbg = TRUE; 			break; 		} 	}
comment|/* if nowbg isn't set now, then we were never given a foreground color */
argument|if (!nowbg) 	{ 		msg(
literal|"usage: color [when] [\"bright\"] [\"blinking\"] foreground [background]"
argument|); 		return; 	}
comment|/* the first ":color" command MUST define the "normal" colors */
argument|if (!bytes[
literal|0
argument|]) 		cmode = A_NORMAL;
comment|/* we should now have a cmode and an attribute byte... */
comment|/* set the color */
argument|setcolor(cmode, attrbyte);
comment|/* remember what we just did */
argument|bytes[cmode] = attrbyte;
comment|/* if the other colors haven't been set yet, then set them to defaults */
argument|if (!bytes[
literal|1
argument|]) 	{
comment|/* standout is the opposite of normal */
argument|bytes[
literal|1
argument|] = ((attrbyte<<
literal|4
argument|)&
literal|0x70
argument|| (attrbyte>>
literal|4
argument|)&
literal|0x07
argument|); 		setcolor(A_STANDOUT, bytes[
literal|1
argument|]);
comment|/* if "normal" isn't bright, then bold defaults to normal+bright 		 * else bold defaults to bright white. 		 */
argument|bytes[
literal|2
argument|] = attrbyte | ((attrbyte&
literal|0x08
argument|) ?
literal|0x0f
argument|:
literal|0x08
argument|); 		setcolor(A_BOLD, bytes[
literal|2
argument|]);
comment|/* all others default to the "standout" colors, without blinking */
argument|for (i =
literal|3
argument|; i< NCOLORS; i++) 		{ 			bytes[i] = (bytes[
literal|1
argument|]&
literal|0x7f
argument|); 			setcolor(words[i].val, bytes[i]); 		} 	}
comment|/* force a redraw, so we see the new colors */
argument|redraw(MARK_UNSET, FALSE); }    void savecolor(fd) 	int	fd;
comment|/* file descriptor to write colors to */
argument|{ 	int	i; 	char	buf[
literal|80
argument|];
comment|/* if no colors are set, then return */
argument|if (!bytes[
literal|0
argument|]) 	{ 		return; 	}
comment|/* save all five color combinations */
argument|for (i =
literal|0
argument|; i< NCOLORS; i++) 	{ 		strcpy(buf,
literal|"color "
argument|); 		strcat(buf, words[i].word); 		strcat(buf,
literal|" "
argument|); 		if (bytes[i]&
literal|0x80
argument|) 			strcat(buf,
literal|"blinking "
argument|); 		switch (bytes[i]&
literal|0xf
argument|) 		{ 		  case
literal|0x08
argument|:	strcat(buf,
literal|"gray"
argument|);	break; 		  case
literal|0x0e
argument|:	strcat(buf,
literal|"yellow"
argument|);	break; 		  case
literal|0x0f
argument|:	strcat(buf,
literal|"bright white"
argument|);break; 		  default: 			if (bytes[i]&
literal|0x08
argument|) 				strcat(buf,
literal|"light "
argument|); 			strcat(buf, words[(bytes[i]&
literal|0x07
argument|) + NCOLORS].word); 		} 		strcat(buf,
literal|" on "
argument|); 		strcat(buf, words[((bytes[i]>>
literal|4
argument|)&
literal|0x07
argument|) + NCOLORS].word); 		strcat(buf,
literal|"\n"
argument|); 		twrite(fd, buf, (unsigned)strlen(buf)); 	} }
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGTSTP
comment|/* temporarily suspend elvis */
comment|/*ARGSUSED*/
argument|void cmd_suspend(frommark, tomark, cmd, bang, extra) 	MARK	frommark; 	MARK	tomark; 	CMD	cmd; 	int	bang; 	char	*extra; { 	SIGTYPE	(*func)();
comment|/* stores the previous setting of SIGTSTP */
if|#
directive|if
name|ANY_UNIX
comment|/* the Bourne shell can't handle ^Z */
argument|if (!strcmp(o_shell,
literal|"/bin/sh"
argument|)) 	{ 		msg(
literal|"The /bin/sh shell doesn't support ^Z"
argument|); 		return; 	}
endif|#
directive|endif
argument|move(LINES -
literal|1
argument|,
literal|0
argument|); 	if (tstflag(file, MODIFIED)) 	{ 		addstr(
literal|"Warning: \""
argument|); 		addstr(origname); 		addstr(
literal|"\" modified but not yet saved"
argument|); 		clrtoeol(); 	} 	refresh(); 	suspend_curses(); 	func = signal(SIGTSTP, SIG_DFL); 	kill (
literal|0
argument|, SIGTSTP);
comment|/* the process stops and resumes here */
argument|signal(SIGTSTP, func); 	resume_curses(TRUE); 	if (mode == MODE_VI || mode == MODE_COLON) 		redraw(MARK_UNSET, FALSE); 	else 		refresh (); }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

