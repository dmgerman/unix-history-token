begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* daemon.c: kernel part of Vinum daemon */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *    * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|REALLYKERNEL
end_define

begin_include
include|#
directive|include
file|"vinumhdr.h"
end_include

begin_include
include|#
directive|include
file|"request.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* declarations */
end_comment

begin_function_decl
name|void
name|recover_io
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|daemonq
modifier|*
name|daemonq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daemon's work queue */
end_comment

begin_decl_stmt
name|struct
name|daemonq
modifier|*
name|dqend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and the end of the queue */
end_comment

begin_decl_stmt
name|int
name|daemon_options
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options */
end_comment

begin_function
name|void
name|vinum_daemon
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|daemonq
modifier|*
name|request
decl_stmt|;
name|int
name|s
decl_stmt|;
name|daemon_save_config
argument_list|()
expr_stmt|;
comment|/* start by saving the configuration */
while|while
condition|(
literal|1
condition|)
block|{
name|tsleep
argument_list|(
operator|&
name|vinum_daemon
argument_list|,
name|PRIBIO
argument_list|,
literal|"vinum"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* wait for something to happen */
while|while
condition|(
name|daemonq
operator|!=
name|NULL
condition|)
block|{
comment|/* we have work to do, */
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
comment|/* don't get interrupted here */
name|request
operator|=
name|daemonq
expr_stmt|;
comment|/* get the request */
name|daemonq
operator|=
name|daemonq
operator|->
name|next
expr_stmt|;
comment|/* and detach it */
if|if
condition|(
name|daemonq
operator|==
name|NULL
condition|)
comment|/* got to the end, */
name|dqend
operator|=
name|NULL
expr_stmt|;
comment|/* no end any more */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|request
operator|->
name|type
condition|)
block|{
comment|/* We had an I/O error on a request.  Go through the 		 * request and try to salvage it */
case|case
name|daemonrq_ioerror
case|:
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
block|{
name|struct
name|request
modifier|*
name|rq
init|=
name|request
operator|->
name|info
operator|.
name|rq
decl_stmt|;
name|printf
argument_list|(
literal|"vinumd: recovering I/O request: %x\n%s dev 0x%x, offset 0x%x, length %ld\n"
argument_list|,
operator|(
name|u_int
operator|)
name|rq
argument_list|,
name|rq
operator|->
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|?
literal|"Read"
else|:
literal|"Write"
argument_list|,
name|rq
operator|->
name|bp
operator|->
name|b_dev
argument_list|,
name|rq
operator|->
name|bp
operator|->
name|b_blkno
argument_list|,
name|rq
operator|->
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
block|}
name|recover_io
argument_list|(
name|request
operator|->
name|info
operator|.
name|rq
argument_list|)
expr_stmt|;
comment|/* the failed request */
break|break;
comment|/* Write the config to disk.  We could end up with 		 * quite a few of these in a row.  Only honour the 		 * last one */
case|case
name|daemonrq_saveconfig
case|:
if|if
condition|(
operator|(
name|daemonq
operator|==
name|NULL
operator|)
comment|/* no more requests */
operator|||
operator|(
name|daemonq
operator|->
name|type
operator|!=
name|daemonrq_saveconfig
operator|)
condition|)
block|{
comment|/* or the next isn't the same */
if|if
condition|(
operator|(
name|daemon_options
operator|&
name|daemon_noupdate
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* we can do it */
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
name|printf
argument_list|(
literal|"vinumd: saving config\n"
argument_list|)
expr_stmt|;
name|daemon_save_config
argument_list|()
expr_stmt|;
comment|/* save it */
block|}
block|}
break|break;
case|case
name|daemonrq_return
case|:
comment|/* been told to stop */
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
name|printf
argument_list|(
literal|"vinumd: stopping\n"
argument_list|)
expr_stmt|;
name|daemon_options
operator||=
name|daemon_stopped
expr_stmt|;
comment|/* note that we've stopped */
name|wakeup
argument_list|(
name|vinum_daemon
argument_list|)
expr_stmt|;
comment|/* in case somebody's waiting for us to stop */
return|return;
break|break;
case|case
name|daemonrq_ping
case|:
comment|/* tell the caller we're here */
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
name|printf
argument_list|(
literal|"vinumd: ping reply\n"
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|&
name|vinum_finddaemon
argument_list|)
expr_stmt|;
comment|/* wake up the caller */
break|break;
case|case
name|daemonrq_init
case|:
comment|/* initialize a plex */
comment|/* XXX */
case|case
name|daemonrq_revive
case|:
comment|/* revive a subdisk */
comment|/* XXX */
default|default:
name|printf
argument_list|(
literal|"Invalid request\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|Free
argument_list|(
name|request
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* Recover a failed I/O operation.   * The correct way to do this is to examine the request and determine  * how to recover each individual failure.  In the case of a write,  * this could be as simple as doing nothing: the defective drives may  * already be down, and there may be nothing else to do.  In case of  * a read, it will be necessary to retry if there are alternative  * copies of the data.  *  * The easy way (here) is just to reissue the request.  This will take  * a little longer, but nothing like as long as the failure will have  * taken.  *  */
end_comment

begin_function
name|void
name|recover_io
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|)
block|{
name|vinumstrategy
argument_list|(
name|rq
operator|->
name|bp
argument_list|)
expr_stmt|;
comment|/* reissue the command */
block|}
end_function

begin_comment
comment|/* Functions called to interface with the daemon */
end_comment

begin_comment
comment|/* queue a request for the daemon */
end_comment

begin_function
name|void
name|queue_daemon_request
parameter_list|(
name|enum
name|daemonrq
name|type
parameter_list|,
name|union
name|daemoninfo
name|info
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|struct
name|daemonq
modifier|*
name|qelt
init|=
operator|(
expr|struct
name|daemonq
operator|*
operator|)
name|Malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|daemonq
argument_list|)
argument_list|)
decl_stmt|;
name|qelt
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
comment|/* end of the chain */
name|qelt
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|qelt
operator|->
name|info
operator|=
name|info
expr_stmt|;
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
if|if
condition|(
name|daemonq
condition|)
block|{
comment|/* something queued already */
name|dqend
operator|->
name|next
operator|=
name|qelt
expr_stmt|;
name|dqend
operator|=
name|qelt
expr_stmt|;
block|}
else|else
block|{
comment|/* queue is empty, */
name|daemonq
operator|=
name|qelt
expr_stmt|;
comment|/* this is the whole queue */
name|dqend
operator|=
name|qelt
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|&
name|vinum_daemon
argument_list|)
expr_stmt|;
comment|/* and give the dæmon a kick */
block|}
end_function

begin_comment
comment|/* see if the daemon is running.  Return 0 (no error)  * if it is, ESRCH otherwise */
end_comment

begin_function
name|int
name|vinum_finddaemon
parameter_list|()
block|{
name|int
name|result
decl_stmt|;
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
literal|2
condition|;
name|i
operator|++
control|)
block|{
comment|/* try twice */
name|queue_daemon_request
argument_list|(
name|daemonrq_ping
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* queue a ping */
do|do
name|result
operator|=
name|tsleep
argument_list|(
operator|&
name|vinum_finddaemon
argument_list|,
name|PUSER
argument_list|,
literal|"recolte"
argument_list|,
literal|20
operator|*
name|hz
argument_list|)
expr_stmt|;
do|while
condition|(
name|result
operator|==
name|ERESTART
condition|)
do|;
comment|/* let it finish */
block|}
if|if
condition|(
name|result
condition|)
comment|/* will be EWOULDBLOCK or EINTR */
return|return
name|ESRCH
return|;
comment|/* no process */
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|vinum_setdaemonopts
parameter_list|(
name|int
name|options
parameter_list|)
block|{
name|daemon_options
operator|=
name|options
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

