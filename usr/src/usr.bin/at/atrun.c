begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)atrun.c	5.5 (Berkeley) 11/26/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  *	Synopsis: atrun  *  *  *	Run jobs created by at(1)  *  *  *	Modifications by:	Steve Wall  *				Computer Systems Research Group  *				University of California @ Berkeley  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_include
include|#
directive|include
file|<sys/quota.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_define
define|#
directive|define
name|ATDIR
value|"/usr/spool/at"
end_define

begin_comment
comment|/* spooling area */
end_comment

begin_define
define|#
directive|define
name|TMPDIR
value|"/tmp"
end_define

begin_comment
comment|/* area for temporary files */
end_comment

begin_define
define|#
directive|define
name|MAILER
value|"/bin/mail"
end_define

begin_comment
comment|/* program to use for sending 						   mail */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_comment
comment|/* job exited normally */
end_comment

begin_define
define|#
directive|define
name|ABNORMAL
value|1
end_define

begin_comment
comment|/* job exited abnormally */
end_comment

begin_define
define|#
directive|define
name|PASTDIR
value|"/usr/spool/at/past"
end_define

begin_comment
comment|/* area to run jobs from */
end_comment

begin_define
define|#
directive|define
name|LASTFILE
value|"/usr/spool/at/lasttimedone"
end_define

begin_comment
comment|/* update time file */
end_comment

begin_decl_stmt
name|char
name|nowtime
index|[
literal|11
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time it is right now (yy.ddd.hhmm) */
end_comment

begin_decl_stmt
name|char
name|errfile
index|[
literal|25
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file where we redirect errors to */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/* for loop index */
name|int
name|numjobs
decl_stmt|;
comment|/* number of jobs to be run */
name|int
name|should_be_run
parameter_list|()
function_decl|;
comment|/* should a job be run? */
name|struct
name|direct
modifier|*
modifier|*
name|jobqueue
decl_stmt|;
comment|/* queue of jobs to be run */
comment|/* 	 * Move to the spooling area. 	 */
name|chdir
argument_list|(
name|ATDIR
argument_list|)
expr_stmt|;
comment|/* 	 * Create a filename that represents the time it is now. This is used 	 * to determine if the execution time for a job has arrived. 	 */
name|makenowtime
argument_list|(
name|nowtime
argument_list|)
expr_stmt|;
comment|/* 	 * Create a queue of the jobs that should be run. 	 */
if|if
condition|(
operator|(
name|numjobs
operator|=
name|scandir
argument_list|(
literal|"."
argument_list|,
operator|&
name|jobqueue
argument_list|,
name|should_be_run
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
name|ATDIR
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * If there are jobs to be run, run them. 	 */
if|if
condition|(
name|numjobs
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|numjobs
condition|;
operator|++
name|i
control|)
block|{
name|run
argument_list|(
name|jobqueue
index|[
name|i
index|]
operator|->
name|d_name
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Record the last update time. 	 */
name|updatetime
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Create a string with the syntax yy.ddd.hhmm that represents the  * time it is right now. This string is used to determine whether a  * job should be run.  */
end_comment

begin_macro
name|makenowtime
argument_list|(
argument|nowtime
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|nowtime
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|tm
modifier|*
name|now
decl_stmt|;
comment|/* broken down representation of the 					   time it is right now */
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* number of seconds since 1/1/70 */
name|struct
name|timezone
name|zone
decl_stmt|;
comment|/* time zone we're in (NOT USED) */
comment|/* 	 * Get the time of day. 	 */
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|time
argument_list|,
operator|&
name|zone
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"gettimeofday"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Get a broken down representation of the time it is right now. 	 */
name|now
operator|=
name|localtime
argument_list|(
operator|&
name|time
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
comment|/* 	 * Create a string to be used in determining whether or not a job 	 * should be run. The syntax is yy.ddd.hhmm . 	 */
name|sprintf
argument_list|(
name|nowtime
argument_list|,
literal|"%d.%03d.%02d%02d"
argument_list|,
name|now
operator|->
name|tm_year
argument_list|,
name|now
operator|->
name|tm_yday
argument_list|,
name|now
operator|->
name|tm_hour
argument_list|,
name|now
operator|->
name|tm_min
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/*  * Run a job.  */
end_comment

begin_macro
name|run
argument_list|(
argument|spoolfile
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|spoolfile
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
comment|/* scratch variable */
name|int
name|pid
decl_stmt|;
comment|/* process id of forked shell */
name|int
name|exitstatus
decl_stmt|;
comment|/* exit status of the job */
name|int
name|notifybymail
decl_stmt|;
comment|/* should we notify the owner of the 					   job after the job is run? */
name|char
name|shell
index|[
literal|4
index|]
decl_stmt|;
comment|/* shell to run the job under */
name|char
modifier|*
name|getname
parameter_list|()
function_decl|;
comment|/* get a uname from using a uid */
name|char
name|mailvar
index|[
literal|4
index|]
decl_stmt|;
comment|/* send mail variable ("yes" or "no") */
name|char
name|runfile
index|[
literal|100
index|]
decl_stmt|;
comment|/* file sent to forked shell for exec- 					   ution */
name|char
name|owner
index|[
literal|128
index|]
decl_stmt|;
comment|/* owner of job we're going to run */
name|char
name|jobname
index|[
literal|128
index|]
decl_stmt|;
comment|/* name of job we're going to run */
name|char
name|whichshell
index|[
literal|100
index|]
decl_stmt|;
comment|/* which shell should we fork off? */
name|struct
name|passwd
modifier|*
name|pwdbuf
decl_stmt|;
comment|/* password info of the owner of job */
name|struct
name|stat
name|errbuf
decl_stmt|;
comment|/* stats on error file */
name|struct
name|stat
name|jobbuf
decl_stmt|;
comment|/* stats on job file */
name|FILE
modifier|*
name|infile
decl_stmt|;
comment|/* I/O stream to spoolfile */
comment|/* 	 * First we fork a child so that the main can run other jobs. 	 */
if|if
condition|(
name|pid
operator|=
name|fork
argument_list|()
condition|)
return|return;
comment|/* 	 * Open the spoolfile. 	 */
if|if
condition|(
operator|(
name|infile
operator|=
name|fopen
argument_list|(
name|spoolfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|spoolfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Grab the 4-line header out of the spoolfile. 	 */
if|if
condition|(
operator|(
name|fscanf
argument_list|(
name|infile
argument_list|,
literal|"# owner: %127s%*[^\n]\n"
argument_list|,
name|owner
argument_list|)
operator|!=
literal|1
operator|)
operator|||
operator|(
name|fscanf
argument_list|(
name|infile
argument_list|,
literal|"# jobname: %127s%*[^\n]\n"
argument_list|,
name|jobname
argument_list|)
operator|!=
literal|1
operator|)
operator|||
operator|(
name|fscanf
argument_list|(
name|infile
argument_list|,
literal|"# shell: %3s%*[^\n]\n"
argument_list|,
name|shell
argument_list|)
operator|!=
literal|1
operator|)
operator|||
operator|(
name|fscanf
argument_list|(
name|infile
argument_list|,
literal|"# notify by mail: %3s%*[^\n]\n"
argument_list|,
name|mailvar
argument_list|)
operator|!=
literal|1
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: bad spool header\n"
argument_list|,
name|spoolfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Check to see if we should send mail to the owner. 	 */
name|notifybymail
operator|=
operator|(
name|strcmp
argument_list|(
name|mailvar
argument_list|,
literal|"yes"
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
name|fclose
argument_list|(
name|infile
argument_list|)
expr_stmt|;
comment|/* 	 * Change the ownership of the spoolfile from "daemon" to the owner 	 * of the job. 	 */
name|pwdbuf
operator|=
name|getpwnam
argument_list|(
name|owner
argument_list|)
expr_stmt|;
if|if
condition|(
name|pwdbuf
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: could not find owner in passwd file\n"
argument_list|,
name|spoolfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|chown
argument_list|(
name|spoolfile
argument_list|,
name|pwdbuf
operator|->
name|pw_uid
argument_list|,
name|pwdbuf
operator|->
name|pw_gid
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
name|spoolfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Move the spoolfile to the directory where jobs are run from and 	 * then move into that directory. 	 */
name|sprintf
argument_list|(
name|runfile
argument_list|,
literal|"%s/%s"
argument_list|,
name|PASTDIR
argument_list|,
name|spoolfile
argument_list|)
expr_stmt|;
name|rename
argument_list|(
name|spoolfile
argument_list|,
name|runfile
argument_list|)
expr_stmt|;
name|chdir
argument_list|(
name|PASTDIR
argument_list|)
expr_stmt|;
comment|/* 	 * Create a temporary file where we will redirect errors to. 	 * Just to make sure we've got a unique file, we'll run an "access" 	 * check on the file. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|1000
condition|;
name|i
operator|+=
literal|2
control|)
block|{
name|sprintf
argument_list|(
name|errfile
argument_list|,
literal|"%s/at.err%d"
argument_list|,
name|TMPDIR
argument_list|,
operator|(
name|getpid
argument_list|()
operator|+
name|i
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|access
argument_list|(
name|errfile
argument_list|,
name|F_OK
argument_list|)
condition|)
break|break;
if|if
condition|(
name|i
operator|==
literal|1000
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"couldn't create errorfile.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Get the stats of the job being run. 	 */
if|if
condition|(
name|stat
argument_list|(
name|runfile
argument_list|,
operator|&
name|jobbuf
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
name|runfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Fork another child that will run the job. 	 */
if|if
condition|(
name|pid
operator|=
name|fork
argument_list|()
condition|)
block|{
comment|/* 		 * If the child fails, save the job so that it gets 		 * rerun the next time "atrun" is executed and then exit. 		 */
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
block|{
name|chdir
argument_list|(
name|ATDIR
argument_list|)
expr_stmt|;
name|rename
argument_list|(
name|runfile
argument_list|,
name|spoolfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * Wait for the child to terminate. 		 */
name|wait
argument_list|(
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|/* 		 * Get the stats of the error file and determine the exit 		 * status of the child. We assume that if there is anything 		 * in the error file then the job ran into some errors. 		 */
if|if
condition|(
name|stat
argument_list|(
name|errfile
argument_list|,
operator|&
name|errbuf
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|perror
argument_list|(
name|errfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|exitstatus
operator|=
operator|(
operator|(
name|errbuf
operator|.
name|st_size
operator|==
literal|0
operator|)
condition|?
name|NORMAL
else|:
name|ABNORMAL
operator|)
expr_stmt|;
comment|/* If errors occurred, then we send mail to the owner 		 * telling him/her that we ran into trouble.   		 * 		 * (NOTE: this could easily be modified so that if any  		 * errors occurred while running a job, mail is sent regard- 		 * less of whether the -m flag was set or not. 		 * 		 * i.e. rather than: 		 * 		 *	"if (notifybymail)" use 		 * use: 		 * 		 *	"if ((exitstatus == ABNORMAL) || (notifybymail))" 		 * 		 * It's up to you if you want to implement this. 		 * 		 */
if|if
condition|(
name|exitstatus
operator|==
name|ABNORMAL
operator|||
name|notifybymail
condition|)
name|sendmailto
argument_list|(
name|getname
argument_list|(
name|jobbuf
operator|.
name|st_uid
argument_list|)
argument_list|,
name|jobname
argument_list|,
name|exitstatus
argument_list|)
expr_stmt|;
comment|/* 		 * Remove the errorfile and the jobfile. 		 */
if|if
condition|(
name|unlink
argument_list|(
name|errfile
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
name|errfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlink
argument_list|(
name|runfile
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
name|runfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * HERE'S WHERE WE SET UP AND FORK THE SHELL. 	 */
comment|/* 	 * Run the job as the owner of the jobfile 	 */
ifdef|#
directive|ifdef
name|notdef
comment|/* This is no longer needed with the new, stripped-down quota system */
name|quota
argument_list|(
name|Q_SETUID
argument_list|,
name|jobbuf
operator|.
name|st_uid
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setgid
argument_list|(
name|jobbuf
operator|.
name|st_gid
argument_list|)
expr_stmt|;
name|initgroups
argument_list|(
name|getname
argument_list|(
name|jobbuf
operator|.
name|st_uid
argument_list|)
argument_list|,
name|jobbuf
operator|.
name|st_gid
argument_list|)
expr_stmt|;
name|setuid
argument_list|(
name|jobbuf
operator|.
name|st_uid
argument_list|)
expr_stmt|;
comment|/* 	 * Close all open files so that we can reopen a temporary file 	 * for stdout and sterr. 	 */
for|for
control|(
name|i
operator|=
name|getdtablesize
argument_list|()
init|;
operator|--
name|i
operator|>=
literal|0
condition|;
control|)
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|/* 	 * Reposition stdin, stdout, and stderr. 	 * 	 *	stdin  = /dev/null 	 *	stout  = /dev/null 	 *	stderr = /tmp/at.err{pid} 	 *	 	 */
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|open
argument_list|(
name|errfile
argument_list|,
name|O_CREAT
operator||
name|O_WRONLY
argument_list|,
literal|00644
argument_list|)
expr_stmt|;
comment|/* 	 * Now we fork the shell. 	 * 	 * See if the shell is in /bin 	 */
name|sprintf
argument_list|(
name|whichshell
argument_list|,
literal|"/bin/%s"
argument_list|,
name|shell
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|whichshell
argument_list|,
name|shell
argument_list|,
name|runfile
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * If not in /bin, look for the shell in /usr/bin. 	 */
name|sprintf
argument_list|(
name|whichshell
argument_list|,
literal|"/usr/bin/%s"
argument_list|,
name|shell
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|whichshell
argument_list|,
name|shell
argument_list|,
name|runfile
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * If not in /bin, look for the shell in /usr/new. 	 */
name|sprintf
argument_list|(
name|whichshell
argument_list|,
literal|"/usr/new/%s"
argument_list|,
name|shell
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|whichshell
argument_list|,
name|shell
argument_list|,
name|runfile
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * If we don't succeed by now, we're really having troubles, 	 * so we'll send the owner some mail. 	 */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Can't execl shell\n"
argument_list|,
name|shell
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
comment|/*  * Send mail to the owner of the job.   */
end_comment

begin_macro
name|sendmailto
argument_list|(
argument|user
argument_list|,
argument|jobname
argument_list|,
argument|exitstatus
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|jobname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exitstatus
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|ch
decl_stmt|;
comment|/* scratch variable */
name|char
name|mailtouser
index|[
literal|100
index|]
decl_stmt|;
comment|/* the process we use to send mail */
name|FILE
modifier|*
name|mailptr
decl_stmt|;
comment|/* I/O stream to the mail process */
name|FILE
modifier|*
name|errptr
decl_stmt|;
comment|/* I/O stream to file containing error 					   messages */
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
comment|/* initiate I/O to a process */
comment|/* 	 * Create the full name for the mail process. 	 */
name|sprintf
argument_list|(
name|mailtouser
argument_list|,
literal|"%s %s"
argument_list|,
name|MAILER
argument_list|,
name|user
argument_list|)
expr_stmt|;
comment|/* 	 * Open a stream to the mail process. 	 */
if|if
condition|(
operator|(
name|mailptr
operator|=
name|popen
argument_list|(
name|mailtouser
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|MAILER
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Send the letter. If the job exited normally, just send a 	 * quick letter notifying the owner that everthing went ok. 	 */
if|if
condition|(
name|exitstatus
operator|==
name|NORMAL
condition|)
block|{
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"Your job \"%s\" was run without "
argument_list|,
name|jobname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"any errors.\n"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * If the job exited abnormally, send a letter notifying the user 	 * that the job didn't run proberly. Also, send a copy of the errors  	 * that occurred to the user. 	 */
else|else
block|{
if|if
condition|(
name|exitstatus
operator|==
name|ABNORMAL
condition|)
block|{
comment|/* 			 * Write the intro to the letter. 			 */
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"\n\nThe job you submitted to at, "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"\"%s\", "
argument_list|,
name|jobname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"exited abnormally.\nA list of the "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|" errors that occurred follows:\n\n\n"
argument_list|)
expr_stmt|;
comment|/* 			 * Open the file containing a log of the errors that 			 * occurred. 			 */
if|if
condition|(
operator|(
name|errptr
operator|=
name|fopen
argument_list|(
name|errfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|errfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 			 * Send the copy of the errors to the owner. 			 */
name|fputc
argument_list|(
literal|'\t'
argument_list|,
name|mailptr
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|fgetc
argument_list|(
name|errptr
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
name|fputc
argument_list|(
name|ch
argument_list|,
name|mailptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch
operator|==
operator|(
name|int
operator|)
literal|'\n'
condition|)
name|fputc
argument_list|(
literal|'\t'
argument_list|,
name|mailptr
argument_list|)
expr_stmt|;
block|}
name|fclose
argument_list|(
name|errptr
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * Sign the letter. 	 */
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"\n\n-----------------\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mailptr
argument_list|,
literal|"The Atrun Program\n"
argument_list|)
expr_stmt|;
comment|/* 	 * Close the stream to the mail process. 	 */
name|pclose
argument_list|(
name|mailptr
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/*  * Do we want to include a file in the job queue? (used by "scandir")   * We are looking for files whose "value" (its name) is less than or   * equal to the time it is right now (represented by "nowtime").  * We'll only consider files with three dots in their name since these  * are the only files that represent jobs to be run.  */
end_comment

begin_macro
name|should_be_run
argument_list|(
argument|direntry
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|direct
modifier|*
name|direntry
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|numdot
init|=
literal|0
decl_stmt|;
comment|/* number of dots found in a filename */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* pointer for scanning a filename */
name|filename
operator|=
name|direntry
operator|->
name|d_name
expr_stmt|;
comment|/* 	 * Count the number of dots found in the directory entry. 	 */
while|while
condition|(
operator|*
name|filename
condition|)
name|numdot
operator|+=
operator|(
operator|*
operator|(
name|filename
operator|++
operator|)
operator|==
literal|'.'
operator|)
expr_stmt|;
comment|/* 	 * If the directory entry doesn't represent a job, just return a 0. 	 */
if|if
condition|(
name|numdot
operator|!=
literal|3
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * If a directory entry represents a job, determine if it's time to 	 * run it. 	 */
return|return
operator|(
name|strncmp
argument_list|(
name|direntry
operator|->
name|d_name
argument_list|,
name|nowtime
argument_list|,
literal|11
argument_list|)
operator|<=
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Record the last time that "atrun" was run.  */
end_comment

begin_macro
name|updatetime
argument_list|()
end_macro

begin_block
block|{
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* number of seconds since 1/1/70 */
name|struct
name|timezone
name|zone
decl_stmt|;
comment|/* time zone we're in (NOT USED) */
name|FILE
modifier|*
name|lastimefile
decl_stmt|;
comment|/* file where recored is kept */
comment|/* 	 * Get the time of day. 	 */
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|time
argument_list|,
operator|&
name|zone
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"gettimeofday"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Open the record file. 	 */
if|if
condition|(
operator|(
name|lastimefile
operator|=
name|fopen
argument_list|(
name|LASTFILE
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't update lastfile: "
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|LASTFILE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Record the last update time (in seconds since 1/1/70). 	 */
name|fprintf
argument_list|(
name|lastimefile
argument_list|,
literal|"%d\n"
argument_list|,
operator|(
name|u_long
operator|)
name|time
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
comment|/* 	 * Close the record file. 	 */
name|fclose
argument_list|(
name|lastimefile
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Get the full login name of a person using his/her user id.  */
end_comment

begin_function
name|char
modifier|*
name|getname
parameter_list|(
name|uid
parameter_list|)
name|int
name|uid
decl_stmt|;
block|{
name|struct
name|passwd
modifier|*
name|pwdinfo
decl_stmt|;
comment|/* password info structure */
if|if
condition|(
operator|(
name|pwdinfo
operator|=
name|getpwuid
argument_list|(
name|uid
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|perror
argument_list|(
name|uid
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|pwdinfo
operator|->
name|pw_name
operator|)
return|;
block|}
end_function

end_unit

