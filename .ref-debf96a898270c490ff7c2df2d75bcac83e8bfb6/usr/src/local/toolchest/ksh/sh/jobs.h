begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)jobs.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	rewritten by David Korn  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JOBS
end_ifdef

begin_if
if|#
directive|if
name|BSD
operator|||
name|RT
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|CBUNIX
end_ifndef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_define
define|#
directive|define
name|_IOCTL_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CBUNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOCTL_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RT */
end_comment

begin_if
if|#
directive|if
name|u370
operator|||
name|uts
end_if

begin_define
define|#
directive|define
name|MAXJ
value|75
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXJ
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u370 */
end_comment

begin_comment
comment|/* JBYTES is the number of char's needed for MAXJ bits */
end_comment

begin_define
define|#
directive|define
name|JBYTES
value|(1+((MAXJ-1)/(8)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JOBS */
end_comment

begin_struct
struct|struct
name|process
block|{
ifdef|#
directive|ifdef
name|JOBS
name|struct
name|process
modifier|*
name|p_next
decl_stmt|;
comment|/* next process structure */
endif|#
directive|endif
comment|/* JOBS */
name|int
name|p_pid
decl_stmt|;
ifdef|#
directive|ifdef
name|JOBS
name|int
name|p_pgrp
decl_stmt|;
comment|/* process group */
name|unsigned
name|char
name|p_job
decl_stmt|;
comment|/* job number of process */
name|unsigned
name|char
name|p_flag
decl_stmt|;
comment|/* flags - see below */
name|unsigned
name|short
name|p_sig
decl_stmt|;
comment|/* signal number */
name|long
name|p_name
decl_stmt|;
comment|/* offset into history file for command */
if|#
directive|if
name|BSD
operator|||
name|RT
name|struct
name|sgttyb
name|p_stty
decl_stmt|;
comment|/* terminal state for job */
else|#
directive|else
ifdef|#
directive|ifdef
name|CBUNIX
name|struct
name|ttiocb
name|p_stty
decl_stmt|;
name|struct
name|termcb
name|p_sterm
decl_stmt|;
else|#
directive|else
name|struct
name|termio
name|p_stty
decl_stmt|;
comment|/* terminal state for job */
endif|#
directive|endif
comment|/* CBUNIX */
endif|#
directive|endif
comment|/* BSD */
endif|#
directive|endif
comment|/* JOBS */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|JOBS
end_ifdef

begin_comment
comment|/* Process states */
end_comment

begin_define
define|#
directive|define
name|P_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|P_STOPPED
value|2
end_define

begin_define
define|#
directive|define
name|P_NOTIFY
value|4
end_define

begin_define
define|#
directive|define
name|P_WAITED
value|8
end_define

begin_define
define|#
directive|define
name|P_STTY
value|16
end_define

begin_define
define|#
directive|define
name|P_PIPEJOB
value|32
end_define

begin_define
define|#
directive|define
name|P_COREDUMP
value|64
end_define

begin_struct
struct|struct
name|jobs
block|{
name|int
name|cur_pgrp
decl_stmt|;
name|int
name|mypid
decl_stmt|;
name|short
name|cur_job
decl_stmt|;
name|short
name|j_flag
decl_stmt|;
name|int
name|p_numpost
decl_stmt|;
comment|/* number of posted jobs */
name|int
name|p_numrun
decl_stmt|;
comment|/* number of running jobs */
name|struct
name|process
modifier|*
name|p_pwlist
decl_stmt|;
comment|/* head of process list */
name|unsigned
name|char
name|p_freejobs
index|[
name|JBYTES
index|]
decl_stmt|;
comment|/* free jobs numbers */
ifdef|#
directive|ifdef
name|SXT
name|int
name|pipe
index|[
literal|2
index|]
decl_stmt|;
comment|/* pipe used for synchronization */
name|int
name|maxjob
decl_stmt|;
comment|/* maximum number of channels */
endif|#
directive|endif
comment|/* SXT */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|jobs
name|jobstat
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|J_PIPE
value|1
end_define

begin_comment
comment|/* set when setting up a pipeline */
end_comment

begin_decl_stmt
specifier|extern
name|MSG
name|kill_usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|bkill
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_Done
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_Running
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_amp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_coredump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_cpid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_job
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_kill
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_no_jctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_newtty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_no_proc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_no_job
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_no_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_not_tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_oldtty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_perm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_running
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_space
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|j_terminate
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JOBS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sysmsg
index|[]
decl_stmt|;
end_decl_stmt

end_unit

