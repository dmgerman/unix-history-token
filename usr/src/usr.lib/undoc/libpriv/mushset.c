begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)mushset.c	4.2	(Melbourne)	82/05/30	*/
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

begin_macro
name|mushset
argument_list|(
argument|uid
argument_list|,
argument|req
argument_list|,
argument|dat
argument_list|)
end_macro

begin_decl_stmt
name|short
name|dat
decl_stmt|;
end_decl_stmt

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
name|MM_ALTER
expr_stmt|;
name|mb
operator|.
name|msg_data
operator|.
name|d_info
operator|=
name|req
expr_stmt|;
name|mb
operator|.
name|msg_data
operator|.
name|d_uid
operator|=
name|uid
expr_stmt|;
name|mb
operator|.
name|msg_data
operator|.
name|d_sdat
operator|=
name|dat
expr_stmt|;
name|mb
operator|.
name|msg_rply
operator|=
literal|0
expr_stmt|;
name|send
argument_list|(
operator|&
name|mb
argument_list|,
name|MSG_W_POST
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

