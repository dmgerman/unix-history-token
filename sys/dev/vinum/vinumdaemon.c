begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* daemon.c: kernel part of Vinum daemon */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumdaemon.c,v 1.8 2000/01/03 05:22:03 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/vinum/vinumhdr.h>
end_include

begin_include
include|#
directive|include
file|<dev/vinum/request.h>
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
name|int
name|daemon_options
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* options */
end_comment

begin_decl_stmt
name|int
name|daemonpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PID of daemon */
end_comment

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

begin_comment
comment|/*  * We normally call Malloc to get a queue element.  In interrupt  * context, we can't guarantee that we'll get one, since we're not  * allowed to wait.  If malloc fails, use one of these elements.  */
end_comment

begin_define
define|#
directive|define
name|INTQSIZE
value|4
end_define

begin_decl_stmt
name|struct
name|daemonq
name|intq
index|[
name|INTQSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue elements for interrupt context */
end_comment

begin_decl_stmt
name|struct
name|daemonq
modifier|*
name|intqp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and pointer in it */
end_comment

begin_function
name|void
name|vinum_daemon
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|struct
name|daemonq
modifier|*
name|request
decl_stmt|;
name|curproc
operator|->
name|p_flag
operator||=
name|P_INMEM
operator||
name|P_SYSTEM
expr_stmt|;
comment|/* we're a system process */
name|daemon_save_config
argument_list|()
expr_stmt|;
comment|/* start by saving the configuration */
name|daemonpid
operator|=
name|curproc
operator|->
name|p_pid
expr_stmt|;
comment|/* mark our territory */
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
comment|/* 	 * It's conceivable that, as the result of an 	 * I/O error, we'll be out of action long 	 * enough that another daemon gets started. 	 * That's OK, just give up gracefully. 	 */
if|if
condition|(
name|curproc
operator|->
name|p_pid
operator|!=
name|daemonpid
condition|)
block|{
comment|/* we've been ousted in our sleep */
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"vinum: abdicating\n"
argument_list|)
expr_stmt|;
return|return;
block|}
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
comment|/* 		 * We had an I/O error on a request.  Go through the 		 * request and try to salvage it 		 */
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
name|log
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"vinum: recovering I/O request: %p\n%s dev %d.%d, offset 0x%x, length %ld\n"
argument_list|,
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
name|major
argument_list|(
name|rq
operator|->
name|bp
operator|->
name|b_dev
argument_list|)
argument_list|,
name|minor
argument_list|(
name|rq
operator|->
name|bp
operator|->
name|b_dev
argument_list|)
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
comment|/* 		 * Write the config to disk.  We could end up with 		 * quite a few of these in a row.  Only honour the 		 * last one 		 */
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
operator|(
name|daemon_options
operator|&
name|daemon_noupdate
operator|)
operator|==
literal|0
operator|)
comment|/* we're allowed to do it */
operator|&&
operator|(
operator|(
name|vinum_conf
operator|.
name|flags
operator|&
name|VF_READING_CONFIG
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* and we're not building the config now */
comment|/* 			   * We obviously don't want to save a 			   * partial configuration.  Less obviously, 			   * we don't need to do anything if we're 			   * asked to write the config when we're 			   * building it up, because we save it at 			   * the end. 			 */
if|if
condition|(
name|daemon_options
operator|&
name|daemon_verbose
condition|)
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"vinum: saving config\n"
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
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"vinum: stopping\n"
argument_list|)
expr_stmt|;
name|daemon_options
operator||=
name|daemon_stopped
expr_stmt|;
comment|/* note that we've stopped */
name|Free
argument_list|(
name|request
argument_list|)
expr_stmt|;
while|while
condition|(
name|daemonq
operator|!=
name|NULL
condition|)
block|{
comment|/* backed up requests, */
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
name|Free
argument_list|(
name|request
argument_list|)
expr_stmt|;
comment|/* then free it */
block|}
name|wakeup
argument_list|(
operator|&
name|vinumclose
argument_list|)
expr_stmt|;
comment|/* and wake any waiting vinum(8)s */
return|return;
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
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"vinum: ping reply\n"
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
name|daemonrq_closedrive
case|:
comment|/* close a drive */
name|close_drive
argument_list|(
name|request
operator|->
name|info
operator|.
name|drive
argument_list|)
expr_stmt|;
comment|/* do it */
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
comment|/* FALLTHROUGH */
default|default:
name|log
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"Invalid request\n"
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|request
operator|->
name|privateinuse
condition|)
comment|/* one of ours, */
name|request
operator|->
name|privateinuse
operator|=
literal|0
expr_stmt|;
comment|/* no longer in use */
else|else
name|Free
argument_list|(
name|request
argument_list|)
expr_stmt|;
comment|/* return it */
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * Recover a failed I/O operation.  *  * The correct way to do this is to examine the request and determine  * how to recover each individual failure.  In the case of a write,  * this could be as simple as doing nothing: the defective drives may  * already be down, and there may be nothing else to do.  In case of  * a read, it will be necessary to retry if there are alternative  * copies of the data.  *  * The easy way (here) is just to reissue the request.  This will take  * a little longer, but nothing like as long as the failure will have  * taken.  *  */
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
comment|/*      * This should read:      *      *     vinumstrategy(rq->bp);      *      * Negotiate with phk to get it fixed.      */
name|BUF_STRATEGY
argument_list|(
name|rq
operator|->
name|bp
argument_list|,
literal|0
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
if|if
condition|(
name|qelt
operator|==
name|NULL
condition|)
block|{
comment|/* malloc failed, we're prepared for that */
comment|/* 	 * Take one of our spares.  Give up if it's still in use; the only 	 * message we're likely to get here is a 'drive failed' message, 	 * and that'll come by again if we miss it. 	 */
if|if
condition|(
name|intqp
operator|->
name|privateinuse
condition|)
comment|/* still in use? */
return|return;
comment|/* yes, give up */
name|qelt
operator|=
name|intqp
operator|++
expr_stmt|;
if|if
condition|(
name|intqp
operator|==
operator|&
name|intq
index|[
name|INTQSIZE
index|]
condition|)
comment|/* got to the end, */
name|intqp
operator|=
name|intq
expr_stmt|;
comment|/* wrap around */
name|qelt
operator|->
name|privateinuse
operator|=
literal|1
expr_stmt|;
comment|/* it's ours, and it's in use */
block|}
else|else
name|qelt
operator|->
name|privateinuse
operator|=
literal|0
expr_stmt|;
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
comment|/*  * see if the daemon is running.  Return 0 (no error)  * if it is, ESRCH otherwise  */
end_comment

begin_function
name|int
name|vinum_finddaemon
parameter_list|()
block|{
name|int
name|result
decl_stmt|;
if|if
condition|(
name|daemonpid
operator|!=
literal|0
condition|)
block|{
comment|/* we think we have a daemon, */
name|queue_daemon_request
argument_list|(
name|daemonrq_ping
argument_list|,
operator|(
expr|union
name|daemoninfo
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* queue a ping */
name|result
operator|=
name|tsleep
argument_list|(
operator|&
name|vinum_finddaemon
argument_list|,
name|PUSER
argument_list|,
literal|"reap"
argument_list|,
literal|2
operator|*
name|hz
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
comment|/* yup, the daemon's up and running */
return|return
literal|0
return|;
block|}
comment|/* no daemon, or we couldn't talk to it: start it */
name|vinum_daemon
argument_list|()
expr_stmt|;
comment|/* start the daemon */
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

