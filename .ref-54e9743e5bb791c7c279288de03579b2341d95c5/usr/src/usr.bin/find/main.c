begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1990, 1993, 1994\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

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
literal|"@(#)main.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"find.h"
end_include

begin_decl_stmt
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time find was run */
end_comment

begin_decl_stmt
name|int
name|dotfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* starting directory */
end_comment

begin_decl_stmt
name|int
name|ftsoptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options for the ftsopen(3) call */
end_comment

begin_decl_stmt
name|int
name|isdeprecated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using deprecated syntax */
end_comment

begin_decl_stmt
name|int
name|isdepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do directories on post-order visit */
end_comment

begin_decl_stmt
name|int
name|isoutput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user specified output operator */
end_comment

begin_decl_stmt
name|int
name|isxargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't permit xargs delimiting chars */
end_comment

begin_decl_stmt
specifier|static
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
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
name|char
modifier|*
modifier|*
name|p
decl_stmt|,
modifier|*
modifier|*
name|start
decl_stmt|;
name|int
name|Hflag
decl_stmt|,
name|Lflag
decl_stmt|,
name|Pflag
decl_stmt|,
name|ch
decl_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
comment|/* initialize the time-of-day */
name|p
operator|=
name|start
operator|=
name|argv
expr_stmt|;
name|Hflag
operator|=
name|Lflag
operator|=
name|Pflag
operator|=
literal|0
expr_stmt|;
name|ftsoptions
operator|=
name|FTS_NOSTAT
operator||
name|FTS_PHYSICAL
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"HLPXdf:x"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'H'
case|:
name|Hflag
operator|=
literal|1
expr_stmt|;
name|Lflag
operator|=
name|Pflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'L'
case|:
name|Lflag
operator|=
literal|1
expr_stmt|;
name|Hflag
operator|=
name|Pflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|Pflag
operator|=
literal|1
expr_stmt|;
name|Hflag
operator|=
name|Lflag
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'X'
case|:
name|isxargs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|isdepth
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
operator|*
name|p
operator|++
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|ftsoptions
operator||=
name|FTS_XDEV
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
break|break;
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
name|Hflag
condition|)
name|ftsoptions
operator||=
name|FTS_COMFOLLOW
expr_stmt|;
if|if
condition|(
name|Lflag
condition|)
block|{
name|ftsoptions
operator|&=
operator|~
name|FTS_PHYSICAL
expr_stmt|;
name|ftsoptions
operator||=
name|FTS_LOGICAL
expr_stmt|;
block|}
comment|/* Find first option to delimit the file list. */
for|for
control|(
init|;
operator|*
name|argv
operator|!=
name|NULL
condition|;
operator|*
name|p
operator|++
operator|=
operator|*
name|argv
operator|++
control|)
if|if
condition|(
name|option
argument_list|(
operator|*
name|argv
argument_list|)
condition|)
break|break;
if|if
condition|(
name|p
operator|==
name|start
condition|)
name|usage
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|(
name|dotfd
operator|=
name|open
argument_list|(
literal|"."
argument_list|,
name|O_RDONLY
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"."
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|find_execute
argument_list|(
name|find_formplan
argument_list|(
name|argv
argument_list|)
argument_list|,
name|start
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|usage
parameter_list|()
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: find [-H | -L | -P] [-Xdx] [-f file] [file ...] [expression]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

