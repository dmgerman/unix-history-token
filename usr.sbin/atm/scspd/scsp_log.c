begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP logging routines  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<libatm.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"scsp_msg.h"
end_include

begin_include
include|#
directive|include
file|"scsp_if.h"
end_include

begin_include
include|#
directive|include
file|"scsp_var.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|scsp_trace_file
init|=
operator|(
name|FILE
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Write a message to SCSP's log  *  * Arguments:  *	level	pointer to an SCSP cache key structure  *	fmt	printf-style format string  *	...	parameters for printf-style use according to fmt  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
if|#
directive|if
name|__STDC__
name|scsp_log
parameter_list|(
specifier|const
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|scsp_log
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|level
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * In debug mode, just write to stdout 	 */
if|if
condition|(
name|scsp_debug_mode
condition|)
block|{
name|vprintf
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Write to syslog if it's active or if no log file is set up 	 */
if|if
condition|(
name|scsp_log_syslog
operator|||
operator|!
name|scsp_log_file
condition|)
block|{
name|vsyslog
argument_list|(
name|level
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Write to the log file if there's one set up 	 */
if|if
condition|(
name|scsp_log_file
condition|)
block|{
name|vfprintf
argument_list|(
name|scsp_log_file
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|scsp_log_file
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Open SCSP's trace file  *  * Arguments:  *	none  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|scsp_open_trace
parameter_list|()
block|{
name|char
name|fname
index|[
literal|64
index|]
decl_stmt|;
comment|/* 	 * Build a file name 	 */
name|UM_ZERO
argument_list|(
name|fname
argument_list|,
sizeof|sizeof
argument_list|(
name|fname
argument_list|)
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|fname
argument_list|,
literal|"/tmp/scspd.%d.trace"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* 	 * Open the trace file.  If the open fails, log an error, but 	 * keep going.  The trace routine will notice that the file 	 * isn't open and won't try to write to it. 	 */
name|scsp_trace_file
operator|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|scsp_trace_file
operator|==
operator|(
name|FILE
operator|*
operator|)
literal|0
condition|)
block|{
name|scsp_log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't open trace file"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Write a message to SCSP's trace file  *  * Arguments:  *	fmt	printf-style format string  *	...	parameters for printf-style use according to fmt  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
if|#
directive|if
name|__STDC__
name|scsp_trace
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|scsp_trace
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Write the message to the trace file, if it's open 	 */
if|if
condition|(
name|scsp_trace_file
condition|)
block|{
name|vfprintf
argument_list|(
name|scsp_trace_file
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Write an SCSP message to SCSP's trace file  *  * Arguments:  *	dcsp	pointer to DCS block for the message  *	msg	pointer to the message  *	dir	a direction indicator--0 for sending, 1 for receiving  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|scsp_trace_msg
parameter_list|(
name|dcsp
parameter_list|,
name|msg
parameter_list|,
name|dir
parameter_list|)
name|Scsp_dcs
modifier|*
name|dcsp
decl_stmt|;
name|Scsp_msg
modifier|*
name|msg
decl_stmt|;
name|int
name|dir
decl_stmt|;
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* 	 * Copy the remote IP address into a struct in_addr 	 */
name|UM_COPY
argument_list|(
name|dcsp
operator|->
name|sd_dcsid
operator|.
name|id
argument_list|,
operator|&
name|addr
operator|.
name|s_addr
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|in_addr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Write the message to the trace file, if it's open 	 */
if|if
condition|(
name|scsp_trace_file
condition|)
block|{
name|scsp_trace
argument_list|(
literal|"SCSP message at 0x%x %s %s\n"
argument_list|,
operator|(
name|u_long
operator|)
name|msg
argument_list|,
operator|(
name|dir
condition|?
literal|"received from"
else|:
literal|"sent to"
operator|)
argument_list|,
name|format_ip_addr
argument_list|(
operator|&
name|addr
argument_list|)
argument_list|)
expr_stmt|;
name|print_scsp_msg
argument_list|(
name|scsp_trace_file
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Log a memory error and exit  *  * Arguments:  *	cp	message to log  *  * Returns:  *	exits, does not return  *  */
end_comment

begin_function
name|void
name|scsp_mem_err
parameter_list|(
name|cp
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|;
block|{
name|scsp_log
argument_list|(
name|LOG_CRIT
argument_list|,
literal|"out of memory: %s"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

