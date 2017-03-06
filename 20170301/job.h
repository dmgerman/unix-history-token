begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: job.h,v 1.42 2013/07/05 22:14:56 sjg Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)job.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)job.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*-  * job.h --  *	Definitions pertaining to the running of jobs in parallel mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_JOB_H_
end_ifndef

begin_define
define|#
directive|define
name|_JOB_H_
end_define

begin_define
define|#
directive|define
name|TMPPAT
value|"makeXXXXXX"
end_define

begin_comment
comment|/* relative to tmpdir */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SELECT
end_ifdef

begin_comment
comment|/*  * Emulate poll() in terms of select().  This is not a complete  * emulation but it is sufficient for make's purposes.  */
end_comment

begin_define
define|#
directive|define
name|poll
value|emul_poll
end_define

begin_define
define|#
directive|define
name|pollfd
value|emul_pollfd
end_define

begin_struct
struct|struct
name|emul_pollfd
block|{
name|int
name|fd
decl_stmt|;
name|short
name|events
decl_stmt|;
name|short
name|revents
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|POLLOUT
value|0x0004
end_define

begin_function_decl
name|int
name|emul_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fd
parameter_list|,
name|int
name|nfd
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The POLL_MSEC constant determines the maximum number of milliseconds spent  * in poll before coming out to see if a child has finished.   */
end_comment

begin_define
define|#
directive|define
name|POLL_MSEC
value|5000
end_define

begin_escape
end_escape

begin_comment
comment|/*-  * Job Table definitions.  *  * Each job has several things associated with it:  *	1) The process id of the child shell  *	2) The graph node describing the target being made by this job  *	3) A LstNode for the first command to be saved after the job  *	   completes. This is NULL if there was no "..." in the job's  *	   commands.  *	4) An FILE* for writing out the commands. This is only  *	   used before the job is actually started.  *	5) The output is being caught via a pipe and  *	   the descriptors of our pipe, an array in which output is line  *	   buffered and the current position in that buffer are all  *	   maintained for each job.  *	6) A word of flags which determine how the module handles errors,  *	   echoing, etc. for the job  *  * When a job is finished, the Make_Update function is called on each of the  * parents of the node which was just remade. This takes care of the upward  * traversal of the dependency graph.  */
end_comment

begin_struct_decl
struct_decl|struct
name|pollfd
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_META
end_ifdef

begin_include
include|#
directive|include
file|"meta.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JOB_BUFSIZE
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
name|Job
block|{
name|int
name|pid
decl_stmt|;
comment|/* The child's process ID */
name|GNode
modifier|*
name|node
decl_stmt|;
comment|/* The target the child is making */
name|LstNode
name|tailCmds
decl_stmt|;
comment|/* The node of the first command to be 			     * saved when the job has been run */
name|FILE
modifier|*
name|cmdFILE
decl_stmt|;
comment|/* When creating the shell script, this is 			     * where the commands go */
name|int
name|exit_status
decl_stmt|;
comment|/* from wait4() in signal handler */
name|char
name|job_state
decl_stmt|;
comment|/* status of the job entry */
define|#
directive|define
name|JOB_ST_FREE
value|0
comment|/* Job is available */
define|#
directive|define
name|JOB_ST_SETUP
value|1
comment|/* Job is allocated but otherwise invalid */
define|#
directive|define
name|JOB_ST_RUNNING
value|3
comment|/* Job is running, pid valid */
define|#
directive|define
name|JOB_ST_FINISHED
value|4
comment|/* Job is done (ie after SIGCHILD) */
name|char
name|job_suspended
decl_stmt|;
name|short
name|flags
decl_stmt|;
comment|/* Flags to control treatment of job */
define|#
directive|define
name|JOB_IGNERR
value|0x001
comment|/* Ignore non-zero exits */
define|#
directive|define
name|JOB_SILENT
value|0x002
comment|/* no output */
define|#
directive|define
name|JOB_SPECIAL
value|0x004
comment|/* Target is a special one. i.e. run it locally 				 * if we can't export it and maxLocal is 0 */
define|#
directive|define
name|JOB_IGNDOTS
value|0x008
comment|/* Ignore "..." lines when processing 				 * commands */
define|#
directive|define
name|JOB_TRACED
value|0x400
comment|/* we've sent 'set -x' */
name|int
name|jobPipe
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pipe for readind output from job */
name|struct
name|pollfd
modifier|*
name|inPollfd
decl_stmt|;
comment|/* pollfd associated with inPipe */
name|char
name|outBuf
index|[
name|JOB_BUFSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Buffer for storing the output of the 				 * job, line by line */
name|int
name|curPos
decl_stmt|;
comment|/* Current position in op_outBuf */
ifdef|#
directive|ifdef
name|USE_META
name|struct
name|BuildMon
name|bm
decl_stmt|;
endif|#
directive|endif
block|}
name|Job
typedef|;
end_typedef

begin_define
define|#
directive|define
name|inPipe
value|jobPipe[0]
end_define

begin_define
define|#
directive|define
name|outPipe
value|jobPipe[1]
end_define

begin_escape
end_escape

begin_comment
comment|/*-  * Shell Specifications:  * Each shell type has associated with it the following information:  *	1) The string which must match the last character of the shell name  *	   for the shell to be considered of this type. The longest match  *	   wins.  *	2) A command to issue to turn off echoing of command lines  *	3) A command to issue to turn echoing back on again  *	4) What the shell prints, and its length, when given the echo-off  *	   command. This line will not be printed when received from the shell  *	5) A boolean to tell if the shell has the ability to control  *	   error checking for individual commands.  *	6) The string to turn this checking on.  *	7) The string to turn it off.  *	8) The command-flag to give to cause the shell to start echoing  *	   commands right away.  *	9) The command-flag to cause the shell to Lib_Exit when an error is  *	   detected in one of the commands.  *  * Some special stuff goes on if a shell doesn't have error control. In such  * a case, errCheck becomes a printf template for echoing the command,  * should echoing be on and ignErr becomes another printf template for  * executing the command while ignoring the return status. Finally errOut  * is a printf template for running the command and causing the shell to   * exit on error. If any of these strings are empty when hasErrCtl is FALSE,   * the command will be executed anyway as is and if it causes an error, so be   * it. Any templates setup to echo the command will escape any '$ ` \ "'i  * characters in the command string to avoid common problems with   * echo "%s\n" as a template.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Shell
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the name of the shell. For Bourne and C 				 * shells, this is used only to find the 				 * shell description when used as the single 				 * source of a .SHELL target. For user-defined 				 * shells, this is the full path of the shell. 				 */
name|Boolean
name|hasEchoCtl
decl_stmt|;
comment|/* True if both echoOff and echoOn defined */
specifier|const
name|char
modifier|*
name|echoOff
decl_stmt|;
comment|/* command to turn off echo */
specifier|const
name|char
modifier|*
name|echoOn
decl_stmt|;
comment|/* command to turn it back on again */
specifier|const
name|char
modifier|*
name|noPrint
decl_stmt|;
comment|/* command to skip when printing output from 				 * shell. This is usually the command which 				 * was executed to turn off echoing */
name|int
name|noPLen
decl_stmt|;
comment|/* length of noPrint command */
name|Boolean
name|hasErrCtl
decl_stmt|;
comment|/* set if can control error checking for 				 * individual commands */
specifier|const
name|char
modifier|*
name|errCheck
decl_stmt|;
comment|/* string to turn error checking on */
specifier|const
name|char
modifier|*
name|ignErr
decl_stmt|;
comment|/* string to turn off error checking */
specifier|const
name|char
modifier|*
name|errOut
decl_stmt|;
comment|/* string to use for testing exit code */
specifier|const
name|char
modifier|*
name|newline
decl_stmt|;
comment|/* string literal that results in a newline 				 * character when it appears outside of any 				 * 'quote' or "quote" characters */
name|char
name|commentChar
decl_stmt|;
comment|/* character used by shell for comment lines */
comment|/*      * command-line flags      */
specifier|const
name|char
modifier|*
name|echo
decl_stmt|;
comment|/* echo commands */
specifier|const
name|char
modifier|*
name|exit
decl_stmt|;
comment|/* exit on error */
block|}
name|Shell
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|shellPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|shellName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shellErrFlag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jobTokensRunning
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tokens currently "out" */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxJobs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max jobs we can run */
end_comment

begin_function_decl
name|void
name|Shell_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|Shell_GetNewline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Touch
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_CheckCommands
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
name|abortProc
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CATCH_BLOCK
value|1
end_define

begin_function_decl
name|void
name|Job_CatchChildren
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_CatchOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Make
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_Full
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_Empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ReturnStatus
name|Job_ParseShell
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Job_Finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_AbortAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|JobFlagForMigration
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_TokenReturn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_TokenWithdraw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_ServerStart
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_SetPrefix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_RunTarget
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _JOB_H_ */
end_comment

end_unit

