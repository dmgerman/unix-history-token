begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#) Copyright (c) 1990 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)find.c	4.25 (Berkeley) %G%"
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
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"find.h"
end_include

begin_decl_stmt
name|FTS
modifier|*
name|tree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to top of FTS hierarchy */
end_comment

begin_decl_stmt
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time find was run */
end_comment

begin_decl_stmt
name|dev_t
name|curdev
init|=
operator|(
name|dev_t
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device number of current tree */
end_comment

begin_decl_stmt
name|int
name|ftsoptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options passed to ftsopen() */
end_comment

begin_decl_stmt
name|int
name|depth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by -depth option */
end_comment

begin_decl_stmt
name|int
name|output_specified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one of -print, -ok or -exec was specified */
end_comment

begin_decl_stmt
name|int
name|xdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by -xdev option */
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
name|PLAN
modifier|*
name|plan
decl_stmt|;
name|char
modifier|*
modifier|*
name|paths
decl_stmt|,
modifier|*
modifier|*
name|find_getpaths
argument_list|()
decl_stmt|;
name|PLAN
modifier|*
name|find_formplan
parameter_list|()
function_decl|;
name|time_t
name|time
parameter_list|()
function_decl|;
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
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
name|ftsoptions
operator|=
name|FTS_MULTIPLE
operator||
name|FTS_NOSTAT
operator||
name|FTS_PHYSICAL
expr_stmt|;
name|paths
operator|=
name|find_getpaths
argument_list|(
operator|&
name|argv
argument_list|)
expr_stmt|;
comment|/* places to start search */
name|plan
operator|=
name|find_formplan
argument_list|(
name|argv
argument_list|)
expr_stmt|;
comment|/* execution plan */
name|find_execute
argument_list|(
name|plan
argument_list|,
name|paths
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * find_formplan --  *	process the command line and create a "plan" corresponding to the  *	command arguments.  */
end_comment

begin_function
name|PLAN
modifier|*
name|find_formplan
parameter_list|(
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|PLAN
modifier|*
name|plan
decl_stmt|,
modifier|*
name|tail
decl_stmt|,
modifier|*
name|new
decl_stmt|;
name|int
name|i
decl_stmt|;
name|PLAN
modifier|*
name|c_print
argument_list|()
decl_stmt|,
modifier|*
name|find_create
argument_list|()
decl_stmt|,
modifier|*
name|find_squish_not
argument_list|()
decl_stmt|,
modifier|*
name|find_squish_or
argument_list|()
decl_stmt|;
name|PLAN
modifier|*
name|find_squish_paren
parameter_list|()
function_decl|;
comment|/* 	 * for each argument in the command line, determine what kind of node 	 * it is, create the appropriate node type and add the new plan node 	 * to the end of the existing plan.  The resulting plan is a linked 	 * list of plan nodes.  For example, the string: 	 * 	 *	% find . -name foo -newer bar -print 	 * 	 * results in the plan: 	 * 	 *	[-name foo]--> [-newer bar]--> [-print] 	 * 	 * in this diagram, `[-name foo]' represents the plan node generated 	 * by c_name() with an argument of foo and `-->' represents the 	 * plan->next pointer. 	 */
for|for
control|(
name|plan
operator|=
name|NULL
init|;
operator|*
name|argv
condition|;
control|)
block|{
name|new
operator|=
name|find_create
argument_list|(
operator|&
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|plan
operator|==
name|NULL
condition|)
name|tail
operator|=
name|plan
operator|=
name|new
expr_stmt|;
else|else
block|{
name|tail
operator|->
name|next
operator|=
name|new
expr_stmt|;
name|tail
operator|=
name|new
expr_stmt|;
block|}
block|}
comment|/* 	 * if the user didn't specify one of -print, -ok or -exec, then -print 	 * is assumed so we add a -print node on the end.  It is possible that 	 * the user might want the -print someplace else on the command line, 	 * but there's no way to know that. 	 */
if|if
condition|(
operator|!
name|output_specified
condition|)
block|{
name|new
operator|=
name|c_print
argument_list|()
expr_stmt|;
if|if
condition|(
name|plan
operator|==
name|NULL
condition|)
name|tail
operator|=
name|plan
operator|=
name|new
expr_stmt|;
else|else
block|{
name|tail
operator|->
name|next
operator|=
name|new
expr_stmt|;
name|tail
operator|=
name|new
expr_stmt|;
block|}
block|}
comment|/* 	 * the command line has been completely processed into a search plan 	 * except for the (, ), !, and -o operators.  Rearrange the plan so 	 * that the portions of the plan which are affected by the operators 	 * are moved into operator nodes themselves.  For example: 	 * 	 *	[!]--> [-name foo]--> [-print] 	 * 	 * becomes 	 * 	 *	[! [-name foo] ]--> [-print] 	 * 	 * and 	 * 	 *	[(]--> [-depth]--> [-name foo]--> [)]--> [-print] 	 * 	 * becomes 	 * 	 *	[expr [-depth]-->[-name foo] ]--> [-print] 	 * 	 * operators are handled in order of precedence. 	 */
name|plan
operator|=
name|find_squish_paren
argument_list|(
name|plan
argument_list|)
expr_stmt|;
comment|/* ()'s */
name|plan
operator|=
name|find_squish_not
argument_list|(
name|plan
argument_list|)
expr_stmt|;
comment|/* !'s */
name|plan
operator|=
name|find_squish_or
argument_list|(
name|plan
argument_list|)
expr_stmt|;
comment|/* -o's */
return|return
operator|(
name|plan
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * find_execute --  *	take a search plan and an array of search paths and executes the plan  *	over all FTSENT's returned for the given search paths.  */
end_comment

begin_macro
name|find_execute
argument_list|(
argument|plan
argument_list|,
argument|paths
argument_list|)
end_macro

begin_decl_stmt
name|PLAN
modifier|*
name|plan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search plan */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|paths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of pathnames to traverse */
end_comment

begin_block
block|{
name|FTSENT
modifier|*
name|entry
decl_stmt|;
comment|/* current fts entry */
name|PLAN
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|tree
operator|=
name|ftsopen
argument_list|(
name|paths
argument_list|,
name|ftsoptions
argument_list|,
name|NULL
argument_list|)
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: ftsopen: %s.\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|entry
operator|=
name|ftsread
argument_list|(
name|tree
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|entry
operator|->
name|info
condition|)
block|{
case|case
name|FTS_DNR
case|:
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: %s: unable to read.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_DNX
case|:
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: %s: unable to search.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_ERR
case|:
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: %s: %s.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_D
case|:
if|if
condition|(
name|depth
condition|)
continue|continue;
break|break;
case|case
name|FTS_DC
case|:
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: directory cycle: %s.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|)
expr_stmt|;
continue|continue;
case|case
name|FTS_DP
case|:
if|if
condition|(
operator|!
name|depth
condition|)
continue|continue;
case|case
name|FTS_NS
case|:
if|if
condition|(
operator|!
operator|(
name|ftsoptions
operator|&
name|FTS_NOSTAT
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: can't stat: %s.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|)
expr_stmt|;
continue|continue;
block|}
break|break;
block|}
comment|/* always keep curdev up to date, -fstype uses it. */
if|if
condition|(
name|xdev
operator|&&
name|curdev
operator|!=
name|entry
operator|->
name|statb
operator|.
name|st_dev
operator|&&
name|ftsset
argument_list|(
name|tree
argument_list|,
name|entry
argument_list|,
name|FTS_SKIP
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"find: %s: %s.\n"
argument_list|,
name|entry
operator|->
name|path
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * call all the functions in the execution plan until one is 		 * false or all have been executed.  This is where we do all 		 * the work specified by the user on the command line. 		 */
for|for
control|(
name|p
operator|=
name|plan
init|;
name|p
operator|&&
call|(
name|p
operator|->
name|eval
call|)
argument_list|(
name|p
argument_list|,
name|entry
argument_list|)
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
empty_stmt|;
name|curdev
operator|=
name|entry
operator|->
name|statb
operator|.
name|st_dev
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|ftsclose
argument_list|(
name|tree
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

