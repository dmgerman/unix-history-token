begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#) Copyright (c) 1983, 1986 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)bugfiler.c	5.6 (Berkeley) 86/11/25"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Bug report processing program, designed to be invoked  * through aliases(5).  */
end_comment

begin_include
include|#
directive|include
file|<bug.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt arguments */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock file descriptor */
end_comment

begin_decl_stmt
name|short
name|do_redist
init|=
name|YES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* redistribut BR */
end_comment

begin_decl_stmt
name|char
name|bfr
index|[
name|MAXBSIZE
index|]
decl_stmt|,
comment|/* general I/O buffer */
name|tmpname
index|[
sizeof|sizeof
argument_list|(
name|TMP_BUG
argument_list|)
operator|+
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temp bug file */
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
name|struct
name|passwd
modifier|*
name|pwd
decl_stmt|;
comment|/* bugs password entry */
specifier|register
name|int
name|ch
decl_stmt|;
comment|/* getopts char */
specifier|register
name|short
name|do_ack
init|=
name|YES
decl_stmt|;
comment|/* acknowledge bug report */
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
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
literal|"ar"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
operator|(
name|char
operator|)
name|ch
condition|)
block|{
case|case
literal|'a'
case|:
name|do_ack
operator|=
name|NO
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|do_redist
operator|=
name|NO
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|error
argument_list|(
literal|"usage: bugfiler [-ar] [maildir]"
argument_list|,
name|CHN
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
operator|(
name|pwd
operator|=
name|getpwnam
argument_list|(
name|BUGS_ID
argument_list|)
operator|)
condition|)
name|error
argument_list|(
literal|"bugs person %s is unknown"
argument_list|,
name|BUGS_ID
argument_list|)
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
operator|*
name|argv
condition|)
block|{
comment|/* change to argument directory */
if|if
condition|(
name|chdir
argument_list|(
operator|*
name|argv
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't move to %s."
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
comment|/* change to bugs home directory */
elseif|else
if|if
condition|(
name|chdir
argument_list|(
name|pwd
operator|->
name|pw_dir
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't move to %s."
argument_list|,
name|pwd
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
if|if
condition|(
name|setreuid
argument_list|(
literal|0
argument_list|,
name|pwd
operator|->
name|pw_uid
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't set id to %s."
argument_list|,
name|BUGS_ID
argument_list|)
expr_stmt|;
name|umask
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* everything is 664 */
name|seterr
argument_list|()
expr_stmt|;
name|logit
argument_list|()
expr_stmt|;
name|make_copy
argument_list|()
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|LOCK_FILE
argument_list|,
name|R_OK
argument_list|)
operator|||
operator|(
name|lfd
operator|=
name|open
argument_list|(
name|LOCK_FILE
argument_list|,
name|O_RDONLY
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|"can't read lock file %s."
argument_list|,
name|LOCK_FILE
argument_list|)
expr_stmt|;
name|gethead
argument_list|()
expr_stmt|;
name|process
argument_list|()
expr_stmt|;
if|if
condition|(
name|setuid
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't set id to root."
argument_list|,
name|CHN
argument_list|)
expr_stmt|;
if|if
condition|(
name|do_ack
condition|)
name|reply
argument_list|()
expr_stmt|;
if|if
condition|(
name|do_redist
condition|)
name|redist
argument_list|()
expr_stmt|;
name|unlink
argument_list|(
name|tmpname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * make_copy --  *	make a copy of the bug report  */
end_comment

begin_expr_stmt
specifier|static
name|make_copy
argument_list|()
block|{
specifier|register
name|int
name|cnt
block|,
comment|/* read return value */
name|tfd
block|;
comment|/* temp file descriptor */
name|char
operator|*
name|mktemp
argument_list|()
block|,
operator|*
name|strcpy
argument_list|()
block|;
comment|/* use O_EXCL, since may not be able to get a lock file */
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
literal|20
condition|;
operator|++
name|cnt
control|)
if|if
condition|(
operator|(
name|tfd
operator|=
name|open
argument_list|(
name|mktemp
argument_list|(
name|strcpy
argument_list|(
name|tmpname
argument_list|,
name|TMP_BUG
argument_list|)
argument_list|)
argument_list|,
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_EXCL
argument_list|,
literal|0664
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
while|while
condition|(
operator|(
name|cnt
operator|=
name|read
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|,
name|bfr
argument_list|,
sizeof|sizeof
argument_list|(
name|bfr
argument_list|)
argument_list|)
operator|)
operator|!=
name|ERR
operator|&&
name|cnt
condition|)
name|write
argument_list|(
name|tfd
argument_list|,
name|bfr
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|tfd
argument_list|)
expr_stmt|;
return|return;
block|}
name|error
argument_list|(
literal|"unable to make copy using %s.\n"
argument_list|,
name|tmpname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  * logit --  *	log this run of the bugfiler  */
end_comment

begin_macro
unit|static
name|logit
argument_list|()
end_macro

begin_block
block|{
name|struct
name|timeval
name|tp
decl_stmt|;
name|struct
name|timezone
name|tzp
decl_stmt|;
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tp
argument_list|,
operator|&
name|tzp
argument_list|)
condition|)
name|error
argument_list|(
literal|"unable to get time of day."
argument_list|,
name|CHN
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n>>> BUGFILER<<<\n\t%s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|tp
operator|.
name|tv_sec
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

