begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Server Cache Synchronization Protocol (SCSP) Support  * ----------------------------------------------------  *  * SCSP-ATMARP server interface: logging routines  *  */
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
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_msg.h"
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_if.h"
end_include

begin_include
include|#
directive|include
file|"../scspd/scsp_var.h"
end_include

begin_include
include|#
directive|include
file|"atmarp_var.h"
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
comment|/*  * Write a message to atmarpd's log  *  * Arguments:  *	level	the level (error, info, etc.) of the message  *	fmt	printf-style format string  *	...	parameters for printf-style use according to fmt  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
if|#
directive|if
name|__STDC__
name|atmarp_log
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
function|atmarp_log
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
name|atmarp_debug_mode
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
comment|/* 	 * Check whether we have a log file set up 	 */
if|if
condition|(
operator|!
name|atmarp_log_file
condition|)
block|{
comment|/* 		 * Write to syslog 		 */
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
else|else
block|{
comment|/* 		 * Write to the log file 		 */
name|vfprintf
argument_list|(
name|atmarp_log_file
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|atmarp_log_file
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
comment|/*  * Log a memory error and exit  *  * Arguments:  *	cp	message to log  *  * Returns:  *	exits, does not return  *  */
end_comment

begin_function
name|void
name|atmarp_mem_err
parameter_list|(
name|cp
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|;
block|{
name|atmarp_log
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

