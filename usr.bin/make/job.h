begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)job.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * job.h --  *	Definitions pertaining to the running of jobs in parallel mode.  *	Exported from job.c for the use of remote-execution modules.  */
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
value|"/tmp/makeXXXXXXXXXX"
end_define

begin_comment
comment|/*  * The SEL_ constants determine the maximum amount of time spent in select  * before coming out to see if a child has finished. SEL_SEC is the number of  * seconds and SEL_USEC is the number of micro-seconds  */
end_comment

begin_define
define|#
directive|define
name|SEL_SEC
value|0
end_define

begin_define
define|#
directive|define
name|SEL_USEC
value|100000
end_define

begin_escape
end_escape

begin_comment
comment|/*-  * Job Table definitions.  *  * Each job has several things associated with it:  *	1) The process id of the child shell  *	2) The graph node describing the target being made by this job  *	3) A LstNode for the first command to be saved after the job  *	   completes. This is NULL if there was no "..." in the job's  *	   commands.  *	4) An FILE* for writing out the commands. This is only  *	   used before the job is actually started.  *	5) A union of things used for handling the shell's output. Different  *	   parts of the union are used based on the value of the usePipes  *	   flag. If it is true, the output is being caught via a pipe and  *	   the descriptors of our pipe, an array in which output is line  *	   buffered and the current position in that buffer are all  *	   maintained for each job. If, on the other hand, usePipes is false,  *	   the output is routed to a temporary file and all that is kept  *	   is the name of the file and the descriptor open to the file.  *	6) An identifier provided by and for the exclusive use of the  *	   Rmt module.  *	7) A word of flags which determine how the module handles errors,  *	   echoing, etc. for the job  *  * The job "table" is kept as a linked Lst in 'jobs', with the number of  * active jobs maintained in the 'nJobs' variable. At no time will this  * exceed the value of 'maxJobs', initialized by the Job_Init function.  *  * When a job is finished, the Make_Update function is called on each of the  * parents of the node which was just remade. This takes care of the upward  * traversal of the dependency graph.  */
end_comment

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
name|char
name|tfile
index|[
sizeof|sizeof
argument_list|(
name|TMPPAT
argument_list|)
index|]
decl_stmt|;
comment|/* Temporary file to use for job */
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
name|rmtID
decl_stmt|;
comment|/* ID returned from Rmt module */
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
name|JOB_REMOTE
value|0x010
comment|/* Job is running remotely */
define|#
directive|define
name|JOB_FIRST
value|0x020
comment|/* Job is first job for the node */
define|#
directive|define
name|JOB_REMIGRATE
value|0x040
comment|/* Job needs to be remigrated */
define|#
directive|define
name|JOB_RESTART
value|0x080
comment|/* Job needs to be completely restarted */
define|#
directive|define
name|JOB_RESUME
value|0x100
comment|/* Job needs to be resumed b/c it stopped, 				 * for some reason */
define|#
directive|define
name|JOB_CONTINUING
value|0x200
comment|/* We are in the process of resuming this job. 				 * Used to avoid infinite recursion between 				 * JobFinish and JobRestart */
union|union
block|{
struct|struct
block|{
name|int
name|op_inPipe
decl_stmt|;
comment|/* Input side of pipe associated 					 * with job's output channel */
name|int
name|op_outPipe
decl_stmt|;
comment|/* Output side of pipe associated with 					 * job's output channel */
name|char
name|op_outBuf
index|[
name|JOB_BUFSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Buffer for storing the output of the 					 * job, line by line */
name|int
name|op_curPos
decl_stmt|;
comment|/* Current position in op_outBuf */
block|}
name|o_pipe
struct|;
comment|/* data used when catching the output via 				     * a pipe */
struct|struct
block|{
name|char
name|of_outFile
index|[
sizeof|sizeof
argument_list|(
name|TMPPAT
argument_list|)
index|]
decl_stmt|;
comment|/* Name of file to which shell output 					 * was rerouted */
name|int
name|of_outFd
decl_stmt|;
comment|/* Stream open to the output 					 * file. Used to funnel all 					 * from a single job to one file 					 * while still allowing 					 * multiple shell invocations */
block|}
name|o_file
struct|;
comment|/* Data used when catching the output in 				     * a temporary file */
block|}
name|output
union|;
comment|/* Data for tracking a shell's output */
block|}
name|Job
typedef|;
end_typedef

begin_define
define|#
directive|define
name|outPipe
value|output.o_pipe.op_outPipe
end_define

begin_define
define|#
directive|define
name|inPipe
value|output.o_pipe.op_inPipe
end_define

begin_define
define|#
directive|define
name|outBuf
value|output.o_pipe.op_outBuf
end_define

begin_define
define|#
directive|define
name|curPos
value|output.o_pipe.op_curPos
end_define

begin_define
define|#
directive|define
name|outFile
value|output.o_file.of_outFile
end_define

begin_define
define|#
directive|define
name|outFd
value|output.o_file.of_outFd
end_define

begin_escape
end_escape

begin_comment
comment|/*-  * Shell Specifications:  * Each shell type has associated with it the following information:  *	1) The string which must match the last character of the shell name  *	   for the shell to be considered of this type. The longest match  *	   wins.  *	2) A command to issue to turn off echoing of command lines  *	3) A command to issue to turn echoing back on again  *	4) What the shell prints, and its length, when given the echo-off  *	   command. This line will not be printed when received from the shell  *	5) A boolean to tell if the shell has the ability to control  *	   error checking for individual commands.  *	6) The string to turn this checking on.  *	7) The string to turn it off.  *	8) The command-flag to give to cause the shell to start echoing  *	   commands right away.  *	9) The command-flag to cause the shell to Lib_Exit when an error is  *	   detected in one of the commands.  *  * Some special stuff goes on if a shell doesn't have error control. In such  * a case, errCheck becomes a printf template for echoing the command,  * should echoing be on and ignErr becomes another printf template for  * executing the command while ignoring the return status. If either of these  * strings is empty when hasErrCtl is FALSE, the command will be executed  * anyway as is and if it causes an error, so be it.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Shell
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the name of the shell. For Bourne and C 				 * shells, this is used only to find the 				 * shell description when used as the single 				 * source of a .SHELL target. For user-defined 				 * shells, this is the full path of the shell. 				 */
name|Boolean
name|hasEchoCtl
decl_stmt|;
comment|/* True if both echoOff and echoOn defined */
name|char
modifier|*
name|echoOff
decl_stmt|;
comment|/* command to turn off echo */
name|char
modifier|*
name|echoOn
decl_stmt|;
comment|/* command to turn it back on again */
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
name|char
modifier|*
name|errCheck
decl_stmt|;
comment|/* string to turn error checking on */
name|char
modifier|*
name|ignErr
decl_stmt|;
comment|/* string to turn off error checking */
comment|/*      * command-line flags      */
name|char
modifier|*
name|echo
decl_stmt|;
comment|/* echo commands */
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
name|char
modifier|*
name|targFmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Format string for banner that separates 				 * output from multiple jobs. Contains a 				 * single %s where the name of the node being 				 * made should be put. */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|lastNode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last node for which a banner was printed. 				 * If Rmt module finds it necessary to print 				 * a banner, it should set this to the node 				 * for which the banner was printed */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nJobs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of jobs running (local and remote) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nLocal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of jobs running locally */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|jobs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of active job descriptors */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|stoppedJobs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of jobs that are stopped or didn't 				 * quite get started */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|jobFull
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero if no more jobs should/will start*/
end_comment

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
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_CatchChildren
parameter_list|(
name|Boolean
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
name|int
parameter_list|,
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _JOB_H_ */
end_comment

end_unit

