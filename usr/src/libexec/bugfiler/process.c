begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)process.c	5.2 (Berkeley) 87/01/28"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<bug.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
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

begin_decl_stmt
specifier|extern
name|HEADER
name|mailhead
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail headers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|dir
index|[]
decl_stmt|,
comment|/* directory */
name|folder
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sub-directory */
end_comment

begin_decl_stmt
name|char
name|pfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* permanent file name */
end_comment

begin_comment
comment|/*  * process --  *	process a bug report  */
end_comment

begin_macro
name|process
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|rval
decl_stmt|;
comment|/* read return value */
name|struct
name|timeval
name|tp
decl_stmt|;
comment|/* time of day */
name|struct
name|timezone
name|tzp
decl_stmt|;
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
comment|/* copy report to permanent file */
name|sprintf
argument_list|(
name|pfile
argument_list|,
literal|"%s/%s/%d"
argument_list|,
name|dir
argument_list|,
name|folder
argument_list|,
name|getnext
argument_list|()
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t%s\n"
argument_list|,
name|pfile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|freopen
argument_list|(
name|pfile
argument_list|,
literal|"w"
argument_list|,
name|stdout
argument_list|)
operator|)
condition|)
name|error
argument_list|(
literal|"unable to create permanent bug file %s."
argument_list|,
name|pfile
argument_list|)
expr_stmt|;
name|rewind
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|rval
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
name|rval
condition|)
name|write
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|,
name|bfr
argument_list|,
name|rval
argument_list|)
expr_stmt|;
name|REL_LOCK
expr_stmt|;
comment|/* append information to the summary file */
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s/%s"
argument_list|,
name|dir
argument_list|,
name|SUMMARY_FILE
argument_list|)
expr_stmt|;
name|GET_LOCK
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|freopen
argument_list|(
name|bfr
argument_list|,
literal|"a"
argument_list|,
name|stdout
argument_list|)
operator|)
condition|)
name|error
argument_list|(
literal|"unable to append to summary file %s."
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
else|else
block|{
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
name|printf
argument_list|(
literal|"\n%s\t\t%s\t%s\t%s\tOwner: Bugs Bunny\n\tComment: Received\n"
argument_list|,
name|pfile
argument_list|,
name|ctime
argument_list|(
operator|&
name|tp
operator|.
name|tv_sec
argument_list|)
argument_list|,
name|mailhead
index|[
name|INDX_TAG
index|]
operator|.
name|line
argument_list|,
name|mailhead
index|[
name|SUBJ_TAG
index|]
operator|.
name|found
condition|?
name|mailhead
index|[
name|SUBJ_TAG
index|]
operator|.
name|line
else|:
literal|"Subject:\n"
argument_list|)
expr_stmt|;
block|}
name|REL_LOCK
expr_stmt|;
name|fclose
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * getnext --  *	get next file name (number)  */
end_comment

begin_expr_stmt
specifier|static
name|getnext
argument_list|()
block|{
specifier|register
expr|struct
name|direct
operator|*
name|d
block|;
comment|/* directory structure */
specifier|register
name|DIR
operator|*
name|dirp
block|;
comment|/* directory pointer */
specifier|register
name|int
name|n
block|;
comment|/* number values */
name|GET_LOCK
block|;
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s/%s"
argument_list|,
name|dir
argument_list|,
name|folder
argument_list|)
block|;
if|if
condition|(
operator|!
operator|(
name|dirp
operator|=
name|opendir
argument_list|(
name|bfr
argument_list|)
operator|)
condition|)
block|{
name|REL_LOCK
expr_stmt|;
name|error
argument_list|(
literal|"unable to read folder directory %s."
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|n
operator|=
literal|0
init|;
name|d
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
condition|;
control|)
name|n
operator|=
name|MAX
argument_list|(
name|n
argument_list|,
name|atoi
argument_list|(
name|d
operator|->
name|d_name
argument_list|)
argument_list|)
expr_stmt|;
end_for

begin_expr_stmt
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
operator|++
name|n
operator|)
return|;
end_return

unit|}
end_unit

