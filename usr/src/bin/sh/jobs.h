begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)jobs.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Mode argument to forkshell.  Don't change FORK_FG or FORK_BG. */
end_comment

begin_define
define|#
directive|define
name|FORK_FG
value|0
end_define

begin_define
define|#
directive|define
name|FORK_BG
value|1
end_define

begin_define
define|#
directive|define
name|FORK_NOJOB
value|2
end_define

begin_comment
comment|/*  * A job structure contains information about a job.  A job is either a  * single process or a set of processes contained in a pipeline.  In the  * latter case, pidlist will be non-NULL, and will point to a -1 terminated  * array of pids.  */
end_comment

begin_struct
struct|struct
name|procstat
block|{
name|short
name|pid
decl_stmt|;
comment|/* process id */
name|short
name|status
decl_stmt|;
comment|/* status flags (defined above) */
name|char
modifier|*
name|cmd
decl_stmt|;
comment|/* text of command being run */
block|}
struct|;
end_struct

begin_comment
comment|/* states */
end_comment

begin_define
define|#
directive|define
name|JOBSTOPPED
value|1
end_define

begin_comment
comment|/* all procs are stopped */
end_comment

begin_define
define|#
directive|define
name|JOBDONE
value|2
end_define

begin_comment
comment|/* all procs are completed */
end_comment

begin_struct
struct|struct
name|job
block|{
name|struct
name|procstat
name|ps0
decl_stmt|;
comment|/* status of process */
name|struct
name|procstat
modifier|*
name|ps
decl_stmt|;
comment|/* status or processes when more than one */
name|short
name|nprocs
decl_stmt|;
comment|/* number of processes */
name|short
name|pgrp
decl_stmt|;
comment|/* process group of this job */
name|char
name|state
decl_stmt|;
comment|/* true if job is finished */
name|char
name|used
decl_stmt|;
comment|/* true if this entry is in used */
name|char
name|changed
decl_stmt|;
comment|/* true if status has changed */
if|#
directive|if
name|JOBS
name|char
name|jobctl
decl_stmt|;
comment|/* job running under job control */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|short
name|backgndpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of last background process */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|job_warning
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user was warned about stopped jobs */
end_comment

begin_decl_stmt
name|void
name|setjobctl
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fgcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bgcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|jobscmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|showjobs
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waitcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|jobidcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|job
modifier|*
name|makejob
name|__P
argument_list|(
operator|(
expr|union
name|node
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|forkshell
name|__P
argument_list|(
operator|(
expr|struct
name|job
operator|*
operator|,
expr|union
name|node
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waitforjob
name|__P
argument_list|(
operator|(
expr|struct
name|job
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stoppedjobs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|commandtext
name|__P
argument_list|(
operator|(
expr|union
name|node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|JOBS
end_if

begin_define
define|#
directive|define
name|setjobctl
parameter_list|(
name|on
parameter_list|)
end_define

begin_comment
comment|/* do nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

