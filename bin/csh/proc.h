begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Structure for each process the shell knows about:  *	allocated and filled by pcreate.  *	flushed by pflush; freeing always happens at top level  *	    so the interrupt level has less to worry about.  *	processes are related to "friends" when in a pipeline;  *	    p_friends links makes a circular list of such jobs  */
end_comment

begin_struct
struct|struct
name|process
block|{
name|struct
name|process
modifier|*
name|p_next
decl_stmt|;
comment|/* next in global "proclist" */
name|struct
name|process
modifier|*
name|p_friends
decl_stmt|;
comment|/* next in job list (or self) */
name|struct
name|directory
modifier|*
name|p_cwd
decl_stmt|;
comment|/* cwd of the job (only in head) */
name|short
name|unsigned
name|p_flags
decl_stmt|;
comment|/* various job status flags */
name|char
name|p_reason
decl_stmt|;
comment|/* reason for entering this state */
name|int
name|p_index
decl_stmt|;
comment|/* shorthand job index */
name|int
name|p_pid
decl_stmt|;
name|int
name|p_jobid
decl_stmt|;
comment|/* pid of job leader */
comment|/* if a job is stopped/background p_jobid gives its pgrp */
name|struct
name|timeval
name|p_btime
decl_stmt|;
comment|/* begin time */
name|struct
name|timeval
name|p_etime
decl_stmt|;
comment|/* end time */
name|struct
name|rusage
name|p_rusage
decl_stmt|;
name|Char
modifier|*
name|p_command
decl_stmt|;
comment|/* first PMAXLEN chars of command */
block|}
struct|;
end_struct

begin_comment
comment|/* flag values for p_flags */
end_comment

begin_define
define|#
directive|define
name|PRUNNING
value|(1<<0)
end_define

begin_comment
comment|/* running */
end_comment

begin_define
define|#
directive|define
name|PSTOPPED
value|(1<<1)
end_define

begin_comment
comment|/* stopped */
end_comment

begin_define
define|#
directive|define
name|PNEXITED
value|(1<<2)
end_define

begin_comment
comment|/* normally exited */
end_comment

begin_define
define|#
directive|define
name|PAEXITED
value|(1<<3)
end_define

begin_comment
comment|/* abnormally exited */
end_comment

begin_define
define|#
directive|define
name|PSIGNALED
value|(1<<4)
end_define

begin_comment
comment|/* terminated by a signal != SIGINT */
end_comment

begin_define
define|#
directive|define
name|PALLSTATES
value|(PRUNNING|PSTOPPED|PNEXITED|PAEXITED|PSIGNALED|PINTERRUPTED)
end_define

begin_define
define|#
directive|define
name|PNOTIFY
value|(1<<5)
end_define

begin_comment
comment|/* notify async when done */
end_comment

begin_define
define|#
directive|define
name|PTIME
value|(1<<6)
end_define

begin_comment
comment|/* job times should be printed */
end_comment

begin_define
define|#
directive|define
name|PAWAITED
value|(1<<7)
end_define

begin_comment
comment|/* top level is waiting for it */
end_comment

begin_define
define|#
directive|define
name|PFOREGND
value|(1<<8)
end_define

begin_comment
comment|/* started in shells pgrp */
end_comment

begin_define
define|#
directive|define
name|PDUMPED
value|(1<<9)
end_define

begin_comment
comment|/* process dumped core */
end_comment

begin_define
define|#
directive|define
name|PERR
value|(1<<10)
end_define

begin_comment
comment|/* diagnostic output also piped out */
end_comment

begin_define
define|#
directive|define
name|PPOU
value|(1<<11)
end_define

begin_comment
comment|/* piped output */
end_comment

begin_define
define|#
directive|define
name|PREPORTED
value|(1<<12)
end_define

begin_comment
comment|/* status has been reported */
end_comment

begin_define
define|#
directive|define
name|PINTERRUPTED
value|(1<<13)
end_define

begin_comment
comment|/* job stopped via interrupt signal */
end_comment

begin_define
define|#
directive|define
name|PPTIME
value|(1<<14)
end_define

begin_comment
comment|/* time individual process */
end_comment

begin_define
define|#
directive|define
name|PNEEDNOTE
value|(1<<15)
end_define

begin_comment
comment|/* notify as soon as practical */
end_comment

begin_define
define|#
directive|define
name|PMAXLEN
value|80
end_define

begin_comment
comment|/* defines for arguments to pprint */
end_comment

begin_define
define|#
directive|define
name|NUMBER
value|01
end_define

begin_define
define|#
directive|define
name|NAME
value|02
end_define

begin_define
define|#
directive|define
name|REASON
value|04
end_define

begin_define
define|#
directive|define
name|AMPERSAND
value|010
end_define

begin_define
define|#
directive|define
name|FANCY
value|020
end_define

begin_define
define|#
directive|define
name|SHELLDIR
value|040
end_define

begin_comment
comment|/* print shell's dir if not the same */
end_comment

begin_define
define|#
directive|define
name|JOBDIR
value|0100
end_define

begin_comment
comment|/* print job's dir if not the same */
end_comment

begin_define
define|#
directive|define
name|AREASON
value|0200
end_define

begin_decl_stmt
name|struct
name|process
name|proclist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list head of all processes */
end_comment

begin_decl_stmt
name|bool
name|pnoprocesses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pchild found nothing to wait for */
end_comment

begin_decl_stmt
name|struct
name|process
modifier|*
name|pholdjob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one level stack of current jobs */
end_comment

begin_decl_stmt
name|struct
name|process
modifier|*
name|pcurrjob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current job */
end_comment

begin_decl_stmt
name|struct
name|process
modifier|*
name|pcurrent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current job in table */
end_comment

begin_decl_stmt
name|struct
name|process
modifier|*
name|pprevious
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous job in table */
end_comment

begin_decl_stmt
name|int
name|pmaxindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current maximum job index */
end_comment

end_unit

