begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent support for SVR4 /proc (process file system) for GDB.    Copyright 1999, 2000 Free Software Foundation, Inc.    Written by Michael Snyder at Cygnus Solutions.    Based on work by Fred Fish, Stu Grossman, Geoff Noer, and others.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation,  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * Pretty-print the prstatus flags.  *   * Arguments: unsigned long flags, int verbose  *  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NEW_PROC_API
argument_list|)
end_if

begin_define
define|#
directive|define
name|_STRUCTURED_PROC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_comment
comment|/*  Much of the information used in the /proc interface, particularly for     printing status information, is kept as tables of structures of the     following form.  These tables can be used to map numeric values to     their symbolic names and to a string that describes their specific use. */
end_comment

begin_struct
struct|struct
name|trans
block|{
name|int
name|value
decl_stmt|;
comment|/* The numeric value */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The equivalent symbolic value */
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* Short description of value */
block|}
struct|;
end_struct

begin_comment
comment|/* Translate bits in the pr_flags member of the prstatus structure,    into the names and desc information. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|trans
name|pr_flag_table
index|[]
init|=
block|{
if|#
directive|if
name|defined
argument_list|(
name|PR_STOPPED
argument_list|)
comment|/* Sol2.5: lwp is stopped    * Sol2.6: lwp is stopped    * Sol2.7: lwp is stopped    * IRIX6:  process is stopped    * OSF:    task/thread is stopped    * UW:     LWP is stopped    */
block|{
name|PR_STOPPED
block|,
literal|"PR_STOPPED"
block|,
literal|"Process (LWP) is stopped"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_ISTOP
argument_list|)
comment|/* Sol2.5: lwp is stopped on an event of interest    * Sol2.6: lwp is stopped on an event of interest    * Sol2.7: lwp is stopped on an event of interest    * IRIX6:  process is stopped on event of interest    * OSF:    task/thread stopped on event of interest    * UW:     LWP stopped on an event of interest    */
block|{
name|PR_ISTOP
block|,
literal|"PR_ISTOP"
block|,
literal|"Stopped on an event of interest"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_DSTOP
argument_list|)
comment|/* Sol2.5: lwp has a stop directive in effect    * Sol2.6: lwp has a stop directive in effect    * Sol2.7: lwp has a stop directive in effect    * IRIX6:  process has stop directive in effect    * OSF:    task/thread has stop directive in effect    * UW:     A stop directive is in effect    */
block|{
name|PR_DSTOP
block|,
literal|"PR_DSTOP"
block|,
literal|"A stop directive is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_STEP
argument_list|)
comment|/* Sol2.5: lwp has a single-step directive in effect    * Sol2.6: lwp has a single-step directive in effect    * Sol2.7: lwp has a single-step directive in effect    * IRIX6:  process has single step pending    */
block|{
name|PR_STEP
block|,
literal|"PR_STEP"
block|,
literal|"A single step directive is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_ASLEEP
argument_list|)
comment|/* Sol2.5: lwp is sleeping in a system call    * Sol2.6: lwp is sleeping in a system call    * Sol2.7: lwp is sleeping in a system call    * IRIX6:  process is in an interruptible sleep    * OSF:    task/thread is asleep within a system call    * UW:     LWP is sleep()ing in a system call    */
block|{
name|PR_ASLEEP
block|,
literal|"PR_ASLEEP"
block|,
literal|"Sleeping in an (interruptible) system call"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_PCINVAL
argument_list|)
comment|/* Sol2.5: contents of pr_instr undefined    * Sol2.6: contents of pr_instr undefined    * Sol2.7: contents of pr_instr undefined    * IRIX6:  current pc is invalid    * OSF:    program counter contains invalid address    * UW:     %pc refers to an invalid virtual address    */
block|{
name|PR_PCINVAL
block|,
literal|"PR_PCINVAL"
block|,
literal|"PC (pr_instr) is invalid"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_ASLWP
argument_list|)
comment|/* Sol2.5: this lwp is the aslwp    * Sol2.6: this lwp is the aslwp    * Sol2.7: this lwp is the aslwp    */
block|{
name|PR_ASLWP
block|,
literal|"PR_ASLWP"
block|,
literal|"This is the asynchronous signal LWP"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_AGENT
argument_list|)
comment|/* Sol2.6: this lwp is the /proc agent lwp    * Sol2.7: this lwp is the /proc agent lwp    */
block|{
name|PR_AGENT
block|,
literal|"PR_AGENT"
block|,
literal|"This is the /proc agent LWP"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_ISSYS
argument_list|)
comment|/* Sol2.5: system process    * Sol2.6: this is a system process    * Sol2.7: this is a system process    * IRIX6:  process is a system process    * OSF:    task/thread is a system task/thread    * UW:     System process    */
block|{
name|PR_ISSYS
block|,
literal|"PR_ISSYS"
block|,
literal|"Is a system process/thread"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_VFORKP
argument_list|)
comment|/* Sol2.6: process is the parent of a vfork()d child    * Sol2.7: process is the parent of a vfork()d child    */
block|{
name|PR_VFORKP
block|,
literal|"PR_VFORKP"
block|,
literal|"Process is the parent of a vforked child"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_ORPHAN
comment|/* Sol2.6: process's process group is orphaned    * Sol2.7: process's process group is orphaned    */
block|{
name|PR_ORPHAN
block|,
literal|"PR_ORPHAN"
block|,
literal|"Process's process group is orphaned"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_FORK
argument_list|)
comment|/* Sol2.5: inherit-on-fork is in effect    * Sol2.6: inherit-on-fork is in effect    * Sol2.7: inherit-on-fork is in effect    * IRIX6:  process has inherit-on-fork flag set    * OSF:    task/thread has inherit-on-fork flag set    * UW:     inherit-on-fork is in effect    */
block|{
name|PR_FORK
block|,
literal|"PR_FORK"
block|,
literal|"Inherit-on-fork is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_RLC
argument_list|)
comment|/* Sol2.5: run-on-last-close is in effect    * Sol2.6: run-on-last-close is in effect    * Sol2.7: run-on-last-close is in effect    * IRIX6:  process has run-on-last-close flag set    * OSF:    task/thread has run-on-last-close flag set    * UW:     Run-on-last-close is in effect    */
block|{
name|PR_RLC
block|,
literal|"PR_RLC"
block|,
literal|"Run-on-last-close is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_KLC
argument_list|)
comment|/* Sol2.5: kill-on-last-close is in effect    * Sol2.6: kill-on-last-close is in effect    * Sol2.7: kill-on-last-close is in effect    * IRIX6:  process has kill-on-last-close flag set    * OSF:    kill-on-last-close, superceeds RLC    * UW:     kill-on-last-close is in effect    */
block|{
name|PR_KLC
block|,
literal|"PR_KLC"
block|,
literal|"Kill-on-last-close is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_ASYNC
argument_list|)
comment|/* Sol2.5: asynchronous-stop is in effect    * Sol2.6: asynchronous-stop is in effect    * Sol2.7: asynchronous-stop is in effect    * OSF:    asynchronous stop mode is in effect    * UW:     asynchronous stop mode is in effect    */
block|{
name|PR_ASYNC
block|,
literal|"PR_ASYNC"
block|,
literal|"Asynchronous stop is in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_MSACCT
argument_list|)
comment|/* Sol2.5: micro-state usage accounting is in effect    * Sol2.6: micro-state usage accounting is in effect    * Sol2.7: micro-state usage accounting is in effect    */
block|{
name|PR_MSACCT
block|,
literal|"PR_MSACCT"
block|,
literal|"Microstate accounting enabled"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_BPTADJ
argument_list|)
comment|/* Sol2.5: breakpoint trap pc adjustment is in effect    * Sol2.6: breakpoint trap pc adjustment is in effect    * Sol2.7: breakpoint trap pc adjustment is in effect    */
block|{
name|PR_BPTADJ
block|,
literal|"PR_BPTADJ"
block|,
literal|"Breakpoint PC adjustment in effect"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_PTRACE
argument_list|)
comment|/* Note: different meanings on Solaris and Irix 6    * Sol2.5: obsolete, never set in SunOS5.0    * Sol2.6: ptrace-compatibility mode is in effect    * Sol2.7: ptrace-compatibility mode is in effect    * IRIX6:  process is traced with ptrace() too    * OSF:    task/thread is being traced by ptrace    * UW:     Process is being controlled by ptrace(2)    */
block|{
name|PR_PTRACE
block|,
literal|"PR_PTRACE"
block|,
literal|"Process is being controlled by ptrace"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PR_PCOMPAT
argument_list|)
comment|/* Note: PCOMPAT on Sol2.5 means same thing as PTRACE on Sol2.6    * Sol2.5 (only): ptrace-compatibility mode is in effect    */
block|{
name|PR_PCOMPAT
block|,
literal|"PR_PCOMPAT"
block|,
literal|"Ptrace compatibility mode in effect"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_MSFORK
comment|/* Sol2.6: micro-state accounting inherited on fork    * Sol2.7: micro-state accounting inherited on fork    */
block|{
name|PR_MSFORK
block|,
literal|"PR_PCOMPAT"
block|,
literal|"Micro-state accounting inherited on fork"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_ISKTHREAD
comment|/* Irix6: process is a kernel thread */
block|{
name|PR_ISKTHREAD
block|,
literal|"PR_KTHREAD"
block|,
literal|"Process is a kernel thread"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_ABORT
comment|/* OSF (only): abort the current stop condition */
block|{
name|PR_ABORT
block|,
literal|"PR_ABORT"
block|,
literal|"Abort the current stop condition"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_TRACING
comment|/* OSF: task is traced */
block|{
name|PR_TRACING
block|,
literal|"PR_TRACING"
block|,
literal|"Task is traced"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_STOPFORK
comment|/* OSF: stop child on fork */
block|{
name|PR_STOPFORK
block|,
literal|"PR_STOPFORK"
block|,
literal|"Stop child on fork"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_STOPEXEC
comment|/* OSF: stop on exec */
block|{
name|PR_STOPEXEC
block|,
literal|"PR_STOPEXEC"
block|,
literal|"Stop on exec"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_STOPTERM
comment|/* OSF: stop on task exit */
block|{
name|PR_STOPTERM
block|,
literal|"PR_STOPTERM"
block|,
literal|"Stop on task exit"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_STOPTCR
comment|/* OSF: stop on thread creation */
block|{
name|PR_STOPTCR
block|,
literal|"PR_STOPTCR"
block|,
literal|"Stop on thread creation"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_STOPTTERM
comment|/* OSF: stop on thread exit */
block|{
name|PR_STOPTTERM
block|,
literal|"PR_STOPTTERM"
block|,
literal|"Stop on thread exit"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PR_USCHED
comment|/* OSF: user level scheduling is in effect */
block|{
name|PR_USCHED
block|,
literal|"PR_USCHED"
block|,
literal|"User level scheduling is in effect"
block|}
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|proc_prettyfprint_flags
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|,
name|int
name|verbose
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|pr_flag_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|pr_flag_table
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|flags
operator|&
name|pr_flag_table
index|[
name|i
index|]
operator|.
name|value
condition|)
block|{
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"%s "
argument_list|,
name|pr_flag_table
index|[
name|i
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"%s\n"
argument_list|,
name|pr_flag_table
index|[
name|i
index|]
operator|.
name|desc
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|verbose
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|proc_prettyprint_flags
parameter_list|(
name|unsigned
name|long
name|flags
parameter_list|,
name|int
name|verbose
parameter_list|)
block|{
name|proc_prettyfprint_flags
argument_list|(
name|stdout
argument_list|,
name|flags
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

