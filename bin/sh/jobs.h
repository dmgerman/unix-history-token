begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)jobs.h	5.1 (Berkeley) 3/7/91  *	jobs.h,v 1.4 1993/08/01 18:58:26 mycroft Exp  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|setjobctl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showjobs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|job
modifier|*
name|makejob
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|forkshell
parameter_list|(
name|struct
name|job
modifier|*
parameter_list|,
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|waitforjob
parameter_list|(
name|struct
name|job
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|setjobctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|showjobs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|job
modifier|*
name|makejob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|forkshell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|waitforjob
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

