begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)syncmush.c	4.2	(Melbourne)	82/05/30	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mush.h>
end_include

begin_include
include|#
directive|include
file|<sys/mu_msg.h>
end_include

begin_include
include|#
directive|include
file|<sys/quota.h>
end_include

begin_include
include|#
directive|include
file|<mushmuck.h>
end_include

begin_comment
comment|/* send a dummy to mush and wait for a reply-- to synchronize */
end_comment

begin_macro
name|syncmush
argument_list|()
end_macro

begin_block
block|{
name|mmsgbuf
name|mb
decl_stmt|;
name|mb
operator|.
name|msg_pid
operator|=
name|MUSHPID
expr_stmt|;
name|mb
operator|.
name|msg_data
operator|.
name|d_req
operator|=
name|MM_SYNC
expr_stmt|;
name|mb
operator|.
name|msg_data
operator|.
name|d_uid
operator|=
literal|0
expr_stmt|;
name|mb
operator|.
name|msg_rply
operator|=
literal|1
expr_stmt|;
name|sendw
argument_list|(
operator|&
name|mb
argument_list|,
operator|&
name|mb
argument_list|,
name|MSG_W_POST
operator||
name|MSG_W_RCV
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

