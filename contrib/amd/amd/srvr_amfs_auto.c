begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: srvr_amfs_auto.c,v 1.2 1999/01/10 21:53:53 ezk Exp $  *  */
end_comment

begin_comment
comment|/*  * Automount FS server ("localhost") modeling  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amd.h>
end_include

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
name|qelem
name|amfs_auto_srvr_list
init|=
block|{
operator|&
name|amfs_auto_srvr_list
block|,
operator|&
name|amfs_auto_srvr_list
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statics */
end_comment

begin_decl_stmt
specifier|static
name|fserver
modifier|*
name|localhost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Find an nfs server for the local host  */
end_comment

begin_function
name|fserver
modifier|*
name|find_amfs_auto_srvr
parameter_list|(
name|mntfs
modifier|*
name|mf
parameter_list|)
block|{
name|fserver
modifier|*
name|fs
init|=
name|localhost
decl_stmt|;
if|if
condition|(
operator|!
name|fs
condition|)
block|{
name|fs
operator|=
name|ALLOC
argument_list|(
expr|struct
name|fserver
argument_list|)
expr_stmt|;
name|fs
operator|->
name|fs_refc
operator|=
literal|0
expr_stmt|;
name|fs
operator|->
name|fs_host
operator|=
name|strdup
argument_list|(
literal|"localhost"
argument_list|)
expr_stmt|;
name|fs
operator|->
name|fs_ip
operator|=
literal|0
expr_stmt|;
name|fs
operator|->
name|fs_cid
operator|=
literal|0
expr_stmt|;
name|fs
operator|->
name|fs_pinger
operator|=
literal|0
expr_stmt|;
name|fs
operator|->
name|fs_flags
operator|=
name|FSF_VALID
expr_stmt|;
name|fs
operator|->
name|fs_type
operator|=
literal|"local"
expr_stmt|;
name|fs
operator|->
name|fs_private
operator|=
literal|0
expr_stmt|;
name|fs
operator|->
name|fs_prfree
operator|=
literal|0
expr_stmt|;
name|ins_que
argument_list|(
operator|&
name|fs
operator|->
name|fs_q
argument_list|,
operator|&
name|amfs_auto_srvr_list
argument_list|)
expr_stmt|;
name|srvrlog
argument_list|(
name|fs
argument_list|,
literal|"starts up"
argument_list|)
expr_stmt|;
name|localhost
operator|=
name|fs
expr_stmt|;
block|}
name|fs
operator|->
name|fs_refc
operator|++
expr_stmt|;
return|return
name|fs
return|;
block|}
end_function

begin_comment
comment|/*****************************************************************************  *** GENERIC ROUTINES FOLLOW  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Wakeup anything waiting for this server  */
end_comment

begin_function
name|void
name|wakeup_srvr
parameter_list|(
name|fserver
modifier|*
name|fs
parameter_list|)
block|{
name|fs
operator|->
name|fs_flags
operator|&=
operator|~
name|FSF_WANT
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|voidp
operator|)
name|fs
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Called when final ttl of server has expired  */
end_comment

begin_function
specifier|static
name|void
name|timeout_srvr
parameter_list|(
name|voidp
name|v
parameter_list|)
block|{
name|fserver
modifier|*
name|fs
init|=
name|v
decl_stmt|;
comment|/*    * If the reference count is still zero then    * we are free to remove this node    */
if|if
condition|(
name|fs
operator|->
name|fs_refc
operator|==
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|dlog
argument_list|(
literal|"Deleting file server %s"
argument_list|,
name|fs
operator|->
name|fs_host
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|fs
operator|->
name|fs_flags
operator|&
name|FSF_WANT
condition|)
name|wakeup_srvr
argument_list|(
name|fs
argument_list|)
expr_stmt|;
comment|/*      * Remove from queue.      */
name|rem_que
argument_list|(
operator|&
name|fs
operator|->
name|fs_q
argument_list|)
expr_stmt|;
comment|/*      * (Possibly) call the private free routine.      */
if|if
condition|(
name|fs
operator|->
name|fs_private
operator|&&
name|fs
operator|->
name|fs_prfree
condition|)
call|(
modifier|*
name|fs
operator|->
name|fs_prfree
call|)
argument_list|(
name|fs
operator|->
name|fs_private
argument_list|)
expr_stmt|;
comment|/*      * Free the net address      */
if|if
condition|(
name|fs
operator|->
name|fs_ip
condition|)
name|XFREE
argument_list|(
name|fs
operator|->
name|fs_ip
argument_list|)
expr_stmt|;
comment|/*      * Free the host name.      */
name|XFREE
argument_list|(
name|fs
operator|->
name|fs_host
argument_list|)
expr_stmt|;
comment|/*      * Discard the fserver object.      */
name|XFREE
argument_list|(
name|fs
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Free a file server  */
end_comment

begin_function
name|void
name|free_srvr
parameter_list|(
name|fserver
modifier|*
name|fs
parameter_list|)
block|{
if|if
condition|(
operator|--
name|fs
operator|->
name|fs_refc
operator|==
literal|0
condition|)
block|{
comment|/*      * The reference count is now zero,      * so arrange for this node to be      * removed in AM_TTL seconds if no      * other mntfs is referencing it.      */
name|int
name|ttl
init|=
operator|(
name|fs
operator|->
name|fs_flags
operator|&
operator|(
name|FSF_DOWN
operator||
name|FSF_ERROR
operator|)
operator|)
condition|?
literal|19
else|:
name|AM_TTL
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|dlog
argument_list|(
literal|"Last hard reference to file server %s - will timeout in %ds"
argument_list|,
name|fs
operator|->
name|fs_host
argument_list|,
name|ttl
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|fs
operator|->
name|fs_cid
condition|)
block|{
name|untimeout
argument_list|(
name|fs
operator|->
name|fs_cid
argument_list|)
expr_stmt|;
comment|/*        * Turn off pinging - XXX        */
name|fs
operator|->
name|fs_flags
operator|&=
operator|~
name|FSF_PINGING
expr_stmt|;
block|}
comment|/*      * Keep structure lying around for a while      */
name|fs
operator|->
name|fs_cid
operator|=
name|timeout
argument_list|(
name|ttl
argument_list|,
name|timeout_srvr
argument_list|,
operator|(
name|voidp
operator|)
name|fs
argument_list|)
expr_stmt|;
comment|/*      * Mark the fileserver down and invalid again      */
name|fs
operator|->
name|fs_flags
operator|&=
operator|~
name|FSF_VALID
expr_stmt|;
name|fs
operator|->
name|fs_flags
operator||=
name|FSF_DOWN
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Make a duplicate fserver reference  */
end_comment

begin_function
name|fserver
modifier|*
name|dup_srvr
parameter_list|(
name|fserver
modifier|*
name|fs
parameter_list|)
block|{
name|fs
operator|->
name|fs_refc
operator|++
expr_stmt|;
return|return
name|fs
return|;
block|}
end_function

begin_comment
comment|/*  * Log state change  */
end_comment

begin_function
name|void
name|srvrlog
parameter_list|(
name|fserver
modifier|*
name|fs
parameter_list|,
name|char
modifier|*
name|state
parameter_list|)
block|{
name|plog
argument_list|(
name|XLOG_INFO
argument_list|,
literal|"file server %s type %s %s"
argument_list|,
name|fs
operator|->
name|fs_host
argument_list|,
name|fs
operator|->
name|fs_type
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

